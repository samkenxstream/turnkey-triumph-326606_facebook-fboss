// Copyright 2004-present Facebook. All Rights Reserved.

#include "fboss/agent/hw/switch_asics/BeasAsic.h"
#include "fboss/agent/FbossError.h"

namespace facebook::fboss {
bool BeasAsic::isSupported(Feature feature) const {
  switch (feature) {
    case HwAsic::Feature::REMOVE_PORTS_FOR_COLDBOOT:
      return true;
    default:
      return false;
  }
  return false;
}

std::set<cfg::StreamType> BeasAsic::getQueueStreamTypes(bool /* cpu */) const {
  throw FbossError("Beas doesn't support queue feature");
}
int BeasAsic::getDefaultNumPortQueues(
    cfg::StreamType /* streamType */,
    bool /* cpu */) const {
  throw FbossError("Beas doesn't support queue feature");
}
uint64_t BeasAsic::getDefaultReservedBytes(
    cfg::StreamType /* streamType */,
    bool /* cpu */) const {
  throw FbossError("Beas doesn't support queue feature");
}
cfg::MMUScalingFactor BeasAsic::getDefaultScalingFactor(
    cfg::StreamType /* streamType */,
    bool /* cpu */) const {
  throw FbossError("Beas doesn't support queue feature");
}

uint32_t BeasAsic::getMaxMirrors() const {
  throw FbossError("Beas doesn't support mirror feature");
}
uint16_t BeasAsic::getMirrorTruncateSize() const {
  throw FbossError("Beas doesn't support mirror feature");
}

uint32_t BeasAsic::getMaxLabelStackDepth() const {
  throw FbossError("Beas doesn't support label feature");
};
uint64_t BeasAsic::getMMUSizeBytes() const {
  throw FbossError("Beas doesn't support MMU feature");
};
int BeasAsic::getMaxNumLogicalPorts() const {
  throw FbossError("Beas doesn't support logical ports feature");
}
uint32_t BeasAsic::getMaxWideEcmpSize() const {
  throw FbossError("Beas doesn't support ecmp feature");
}
uint32_t BeasAsic::getMaxLagMemberSize() const {
  throw FbossError("Beas doesn't support lag feature");
}
uint32_t BeasAsic::getPacketBufferUnitSize() const {
  throw FbossError("Beas doesn't support MMU feature");
}
uint32_t BeasAsic::getPacketBufferDescriptorSize() const {
  throw FbossError("Beas doesn't support MMU feature");
}
uint32_t BeasAsic::getMaxVariableWidthEcmpSize() const {
  return 512;
}
uint32_t BeasAsic::getMaxEcmpSize() const {
  return 4096;
}

uint32_t BeasAsic::getNumCores() const {
  throw FbossError("Num cores API not supported by BeasAsic");
}

bool BeasAsic::scalingFactorBasedDynamicThresholdSupported() const {
  throw FbossError("Beas doesn't support MMU feature");
}
int BeasAsic::getBufferDynThreshFromScalingFactor(
    cfg::MMUScalingFactor /* scalingFactor */) const {
  throw FbossError("Beas doesn't support MMU feature");
}
uint32_t BeasAsic::getStaticQueueLimitBytes() const {
  throw FbossError("Beas doesn't support MMU feature");
}
}; // namespace facebook::fboss