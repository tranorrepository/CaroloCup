/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef OPENDAVINCI_CORE_BASE_CONDITION_H_
#define OPENDAVINCI_CORE_BASE_CONDITION_H_

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include "core/SharedPointer.h"
#include "core/base/Mutex.h"
#include "core/wrapper/Condition.h"

namespace core {
    namespace base {

        /**
         * This class implements a condition for waiting on signals:
         *
         * Thread 1:
         * [...]
         * @code
         * Condition c;
         * Lock l(c);
         * if (sleep) {
         *    c.waitOnSignal(); // Now, the execution of the current thread is suspended.
         * }
         * @endcode
         *
         * Thread 2:
         * [...]
         * @code
         * Condition &c = thread1.getCondition();
         * Lock l(c);
         * sleep = false
         * c.wakeOne(); // Wake up sleeping thread 1.
         *
         * // or:
         * Lock l(c);
         * sleep = false
         * c.wakeAll(); // Wake up all threads sleeping on this condition.
         * @endcode
         *
         * It is important that a condition is locked before waitOnSignal,
         * wakeOne or wakeAll are called. Otherwise you will get an assertion
         * error. The lock is released before the condition is put asleep or
         * woken up and locked again before the mehtod returns. This way, sleep
         * can be modified thread-safe by different threads.
         */
        class OPENDAVINCI_API Condition : public Mutex {
            private:
                friend class Lock;

                /**
                 * "Forbidden" copy constructor. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the copy constructor.
                 */
                Condition(const Condition&);

                /**
                 * "Forbidden" assignment operator. Goal: The compiler should warn
                 * already at compile time for unwanted bugs caused by any misuse
                 * of the assignment operator.
                 */
                Condition& operator=(const Condition &);

            public:
                Condition();

                virtual ~Condition();

                /**
                 * This method suspends the execution of the
                 * current thread.
                 */
                void waitOnSignal();

                /**
                 * This methods suspends the execution of the current
                 * thread with a timeout
                 *
                 * @return TRUE if condition awakes, FALSE if timeout occurs
                 */
                bool waitOnSignalWithTimeout(const unsigned long& ms);

                /**
                 * This method awakes only one sleeping thread.
                 */
                void wakeOne();

                /**
                 * This method awakes all threads sleeping on
                 * this condition.
                 */
                void wakeAll();

            protected:
                /**
                 * This method locks the condition's mutex.
                 */
                virtual void lock();

                /**
                 * This method tries to lock the condition's mutex.
                 *
                 * @return true, if the mutex could be locked.
                 */
                virtual bool tryLock();

                /**
                 * This method unlocks the condition's mutex.
                 */
                virtual void unlock();

            private:
                SharedPointer<wrapper::Condition> m_condition;
        };

    }
} // core::base

#endif /*OPENDAVINCI_CORE_BASE_CONDITION_H_*/
