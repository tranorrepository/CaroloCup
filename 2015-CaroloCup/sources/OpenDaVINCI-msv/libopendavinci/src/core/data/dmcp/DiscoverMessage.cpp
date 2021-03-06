/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"

#include "core/data/dmcp/DiscoverMessage.h"

namespace core {
    namespace data {
        namespace dmcp {

            using namespace core::base;

            DiscoverMessage::DiscoverMessage() :
                m_type(UNDEFINED),
                m_serverInformation()
            {}

            DiscoverMessage::DiscoverMessage(TYPE type) :
                m_type(type),
                m_serverInformation()
            {}

            DiscoverMessage::DiscoverMessage(TYPE type, const core::dmcp::ServerInformation& serverInformation) :
                m_type(type),
                m_serverInformation(serverInformation)
            {}

            DiscoverMessage::~DiscoverMessage() {}

            ostream&  DiscoverMessage::operator<<(ostream &out) const {
                SerializationFactory sf;
                Serializer &s = sf.getSerializer(out);

                uint32_t type = m_type;
                s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('t', 'y', 'p', 'e') >::RESULT, type);
                s.write(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('i', 'f', 'n', 'o') >::RESULT, m_serverInformation);

                return out;
            }

            istream& DiscoverMessage::operator>>(istream &in) {
                SerializationFactory sf;
                Deserializer &d = sf.getDeserializer(in);

                uint32_t type = 0;
                d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('t', 'y', 'p', 'e') >::RESULT, type);
                m_type = static_cast<DiscoverMessage::TYPE>(type);
                d.read(CRC32 < OPENDAVINCI_CORE_STRINGLITERAL4('i', 'f', 'n', 'o') >::RESULT, m_serverInformation);

                return in;
            }

            const string DiscoverMessage::toString() const {
                switch (m_type) {
                case UNDEFINED:
                    return "DiscoverMessage::UNDEFINED";
                case DISCOVER:
                    return "DiscoverMessage::DISCOVER";
                case RESPONSE:
                    return "DiscoverMessage::RESPONSE";
                }
                return "";
            }

            DiscoverMessage::TYPE DiscoverMessage::getType() const {
                return m_type;
            }

            const core::dmcp::ServerInformation DiscoverMessage::getServerInformation() const
            {
                return m_serverInformation;
            }
        }
    }
}
