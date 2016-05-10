//
//  main.cpp
//  Scratch
//
//  Created by Paul Hoehne on 5/27/14.
//  Copyright (c) 2014 Paul Hoehne. All rights reserved.
//

#include <iostream>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP


int main(int argc, const char * argv[])
{
  START_EASYLOGGINGPP(argc, argv);

  el::Configurations defaultConf;
  defaultConf.setToDefault();
  // Values are always std::string
  defaultConf.setGlobally(el::ConfigurationType::Format, "%datetime %level %fbase:%line %msg");
  // default logger uses default configurations
  el::Loggers::reconfigureLogger("default", defaultConf);

  LOG(INFO) << "In tests main";

  //CppUnit::TestResult controller;

  //CppUnit::TestResultCollector collector;
  //controller.addListener(&collector);

  //CppUnit::BriefTestProgressListener progress;
  //controller.addListener(&progress);

  CppUnit::TextUi::TestRunner runner;
  runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
  bool wasSuccessful = runner.run( "", false );
  return wasSuccessful;
}
