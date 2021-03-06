/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_WRAPPER_IMAGEFACTORY_H_
#define HESPERIA_CORE_WRAPPER_IMAGEFACTORY_H_

#include <iostream>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "core/wrapper/Disposable.h"
#include "core/wrapper/Image.h"
#include "core/wrapper/Mutex.h"

namespace core {
    namespace wrapper {

        using namespace std;

        /**
         * Abstract factory for handling matrices using a
         * native library (i.e. OpenCV).
         *
         * It can be used as follows:
         *
         * @code
         * fstream fin("image.png", ios::binary|ios::in);
         * Image *i = ImageFactory::getInstance().getImage(fin);
         * fin.close();
         *
         * ...
         *
         * if (i != NULL) {
         *     delete i;
         * }
         *
         * @endcode
         */
        class OPENDAVINCI_API ImageFactory : public Disposable {
            private:
                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 */
                ImageFactory(const ImageFactory &);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 */
                ImageFactory& operator=(const ImageFactory &);

            protected:
                ImageFactory();

            public:
                virtual ~ImageFactory();

                /**
                 * Singleton getter.
                 *
                 * @return Instance of the concrete factory.
                 */
                static ImageFactory& getInstance();

                /**
                 * This method returns an image read from the given istream.
                 *
                 * @param in The stream to be used to create the image.
                 * @return time based on the type of instance this factory is.
                 */
                virtual Image* getImage(istream &in) = 0;

                /**
                 * This method returns an empty image.
                 *
                 * @param width Width of the image.
                 * @param height Height of the image.
                 * @param format Image's format.
                 * @return Wrapped image or NULL.
                 */
                virtual Image* getImage(const uint32_t &width, const uint32_t &height, const enum Image::FORMAT &format) = 0;

                /**
                 * This method returns an image for an already existing
                 * memory based image without copying it.
                 *
                 * @param width Width of the image.
                 * @param height Height of the image.
                 * @param format Image's format.
                 * @param ptr Pointer to the raw data area.
                 * @return Wrapped image or NULL.
                 */
                virtual Image* getImage(const uint32_t &width, const uint32_t &height, const enum Image::FORMAT &format, char *ptr) = 0;

            private:
                static Mutex *m_singletonMutex;
                static ImageFactory *m_singleton;
        };

    }
} // core::wrapper

#endif /*HESPERIA_CORE_WRAPPER_IMAGEFACTORY_H_*/
