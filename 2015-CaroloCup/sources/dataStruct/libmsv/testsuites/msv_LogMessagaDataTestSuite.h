/*
 * This software is open source. Please see COPYING and AUTHORS for further information.
 *
 * This file is auto-generated. DO NOT CHANGE AS YOUR CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef MSV_LOGMESSAGADATA_TESTSUITE_H
#define MSV_LOGMESSAGADATA_TESTSUITE_H

#include "cxxtest/TestSuite.h"

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"
#include "core/StringToolbox.h"

#include "GeneratedHeaders_msv.h"


class msv_LogMessagaData_TestSuite : public CxxTest::TestSuite {

	public:
		void testCreateObject() {
			using namespace msv;
	
			LogMessagaData obj1;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), ""));
	
			obj1.setComponent("Hello World!");
			obj1.setLoglevel("Hello World!");
			obj1.setMsg("Hello World!");
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), "Hello World!"));
		}
	
		void testCreateAndCopyObject() {
			using namespace msv;
	
			LogMessagaData obj1;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), ""));
	
			LogMessagaData obj2(obj1);
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), obj2.getComponent()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), obj2.getLoglevel()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), obj2.getMsg()));
	
			obj1.setComponent("Hello World!");
			obj1.setLoglevel("Hello World!");
			obj1.setMsg("Hello World!");
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), "Hello World!"));
	
			LogMessagaData obj3(obj1);
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), obj3.getComponent()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), obj3.getLoglevel()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), obj3.getMsg()));
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj3.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj3.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj3.getMsg(), "Hello World!"));
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.toString(), obj3.toString()));
		}
	
		void testCreateAndAssignObject() {
			using namespace msv;
	
			LogMessagaData obj1;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), ""));
	
			LogMessagaData obj2;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getComponent(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getLoglevel(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getMsg(), ""));
	
			obj1.setComponent("Hello World!");
			obj1.setLoglevel("Hello World!");
			obj1.setMsg("Hello World!");
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), "Hello World!"));
	
			obj2 = obj1;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), obj2.getComponent()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), obj2.getLoglevel()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), obj2.getMsg()));
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getMsg(), "Hello World!"));
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.toString(), obj2.toString()));
		}
	
		void testCreateAndSerializeObject() {
			using namespace msv;
	
			LogMessagaData obj1;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), ""));
	
			LogMessagaData obj2;
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getComponent(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getLoglevel(), ""));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getMsg(), ""));
	
			obj1.setComponent("Hello World!");
			obj1.setLoglevel("Hello World!");
			obj1.setMsg("Hello World!");
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), "Hello World!"));
	
			stringstream sstr;
			sstr << obj1;
			sstr >> obj2;
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getComponent(), obj2.getComponent()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getLoglevel(), obj2.getLoglevel()));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.getMsg(), obj2.getMsg()));
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getComponent(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getLoglevel(), "Hello World!"));
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj2.getMsg(), "Hello World!"));
	
			TS_ASSERT(core::StringToolbox::equalsIgnoreCase(obj1.toString(), obj2.toString()));
		}

};

#endif /*MSV_LOGMESSAGADATA_TESTSUITE_H*/
