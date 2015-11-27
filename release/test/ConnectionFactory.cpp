//
//  ConnectionFactory.cpp
//  Scratch
//
//  Created by Adam Fowler on 27 Nov 2015.
//  Copyright (c) 2015 Adam Fowler. All rights reserved.
//

#include "MLCPlusPlus.hpp"

Connection& ConnectionFactory::getConnection() {
  Connection* conn();
  conn->configure("192.168.123.4","8002","admin","admin");
  return conn;
}
