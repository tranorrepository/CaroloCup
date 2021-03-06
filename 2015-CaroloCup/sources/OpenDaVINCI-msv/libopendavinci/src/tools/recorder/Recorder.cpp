/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <iostream>

#include "core/data/Container.h"
#include "core/io/StreamFactory.h"
#include "core/io/URL.h"

#include "tools/recorder/Recorder.h"

namespace tools {

    namespace recorder {

        using namespace std;
        using namespace core::base;
        using namespace core::data;
        using namespace core::io;

        Recorder::Recorder(const string &url, const uint32_t &memorySegmentSize, const uint32_t &numberOfSegments) :
            m_fifo(),
            m_sharedDataListener(NULL),
            m_out(NULL),
            m_outSharedMemoryFile(NULL) {

            // Get output file.
            URL _url(url);
            m_out = &(StreamFactory::getInstance().getOutputStream(_url));

            // Add a specific listener for SharedData type.
            URL urlSharedMemoryFile("file://" + _url.getResource() + ".mem");
            m_outSharedMemoryFile = &(StreamFactory::getInstance().getOutputStream(urlSharedMemoryFile));

            // Create data store for shared memory.
            m_sharedDataListener = new SharedDataListener(*m_outSharedMemoryFile, memorySegmentSize, numberOfSegments);
        }

        Recorder::~Recorder() {
            // Record remaining entries.
            cout << "Clearing queue... ";
                recordQueueEntries();
                if (m_out != NULL) {
                    m_out->flush();
                }
            cout << "done." << endl;

            OPENDAVINCI_CORE_DELETE_POINTER(m_sharedDataListener);
        }

        FIFOQueue& Recorder::getFIFO() {
            return m_fifo;
        }

        SharedDataListener& Recorder::getDataStoreForSharedData() {
            return *m_sharedDataListener;
        }

        void Recorder::store(core::data::Container c) {
            // Check if the container to be stored is a "regular" data type.
            if ( (c.getDataType() != Container::UNDEFINEDDATA) &&
                    (c.getDataType() != Container::RECORDER_COMMAND)  &&
                    (c.getDataType() != Container::SHARED_DATA)  &&
                    (c.getDataType() != Container::SHARED_IMAGE) ) {
                getFIFO().enter(c);
                recordQueueEntries();
            }

            // ... or a container that describes a shared memory segment.
            if ( (c.getDataType() == Container::SHARED_DATA)  ||
                 (c.getDataType() == Container::SHARED_IMAGE) ) {
                getDataStoreForSharedData().add(c);
            }
        }

        void Recorder::recordQueueEntries() {
            if (!m_fifo.isEmpty()) {
                uint32_t numberOfEntries = m_fifo.getSize();
                for (uint32_t i = 0; i < numberOfEntries; i++) {
                    Container c = m_fifo.leave();
                    // Filter undefined data as well as recorder commands.
                    if ( (c.getDataType() != Container::UNDEFINEDDATA) &&
                            (c.getDataType() != Container::RECORDER_COMMAND)  &&
                            (c.getDataType() != Container::SHARED_DATA)  &&
                            (c.getDataType() != Container::SHARED_IMAGE) ) {
                        if (m_out != NULL) {
                            (*m_out) << c;
                        }
                    }
                }

                if (m_out != NULL) {
                    m_out->flush();
                }
            }
        }

    } // recorder
} // tools
