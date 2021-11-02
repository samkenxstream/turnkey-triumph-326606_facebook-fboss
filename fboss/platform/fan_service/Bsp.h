// Copyright 2021- Facebook. All rights reserved.

// BSP Base Class, a part of Fan Service
//
// Role : Take care of all the I/O and other board specific details
//        such as, emergency_shutdown, sysfs read, thrift read, util read
//        A base class where it can be extended by platform specific class or
//        overridden by mock Bsp (Mokujin)

// Don't parse multiple times
#pragma once

// Standard CPP include file
#include <fstream>
#include <sstream>

// Header file of the other classes used by this class
#include "SensorData.h"
#include "ServiceConfig.h"

// Auto-generated Thrift inteface headerfile (by Buck)
#include "fboss/platform/sensor_service/if/gen-cpp2/SensorService.h"

// Facebook Service Router Headerfiles
// - used when sending Thrift request to sensor_service
#include "servicerouter/client/cpp2/ClientParams.h"
#include "servicerouter/client/cpp2/ServiceRouter.h"
// Coroutine BlockWait headerfile
#include <folly/experimental/coro/BlockingWait.h>

class Bsp {
 public:
  // Constructur / Destructors
  Bsp();
  virtual ~Bsp();
  // getSensorData: Get sensor data from either cache or direct access
  virtual void getSensorData(
      std::shared_ptr<ServiceConfig> pServiceConfig,
      std::shared_ptr<SensorData> pSensorData);
  // emergencyShutdown: function to shutdown the platform upon overheat
  virtual int emergencyShutdown(
      std::shared_ptr<ServiceConfig> pServiceConfig,
      bool enable);
  // setFanPwm... : Fan pwm set function. Used by Control Logic Class
  virtual bool setFanPwmSysfs(std::string path, int pwm);
  virtual bool
  setFanPwmShell(std::string command, std::string fanName, int pwm);
  // replaceAllString : String replace helper function
  std::string
  replaceAllString(std::string original, std::string src, std::string tgt);
  // Other public functions that cannot be overridden
  virtual uint64_t getCurrentTime();
  virtual bool checkIfInitialSensorDataRead();
  bool getEmergencyState();
  float readSysfs(std::string path);

 protected:
  // This attribute is accessed by internal function and Mock class (Mokujin)
  bool emergencyShutdownState;

 private:
  // Private Attributes
  int sensordThriftPort_;
  bool initialSensorDataRead_;

  // Private Methods
  void setEmergencyState(bool state);
  // Various handlers to fetch sensor data from Thrift / Utility / Rest / Sysfs
  void getSensorDataThrift(
      std::shared_ptr<ServiceConfig> pServiceConfig,
      std::shared_ptr<SensorData> pSensorData);
  void getSensorDataThriftWithSensorList(
      std::shared_ptr<ServiceConfig> pServiceConfig,
      std::shared_ptr<SensorData> pSensorData,
      std::vector<std::string> sensorList);
  void getSensorDataUtil(
      std::shared_ptr<ServiceConfig> pServiceConfig,
      std::shared_ptr<SensorData> pSensorData);
  float getSensorDataSysfs(std::string path);
  void getSensorDataRest(
      std::shared_ptr<ServiceConfig> pServiceConfig,
      std::shared_ptr<SensorData> pSensorData);
};