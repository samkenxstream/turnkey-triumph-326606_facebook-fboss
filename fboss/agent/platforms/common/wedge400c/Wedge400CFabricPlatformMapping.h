/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include "fboss/agent/platforms/common/PlatformMapping.h"

namespace facebook {
namespace fboss {

class Wedge400CFabricPlatformMapping : public PlatformMapping {
 public:
  Wedge400CFabricPlatformMapping();
  explicit Wedge400CFabricPlatformMapping(
      const std::string& platformMappingStr);

 private:
  // Forbidden copy constructor and assignment operator
  Wedge400CFabricPlatformMapping(Wedge400CFabricPlatformMapping const&) =
      delete;
  Wedge400CFabricPlatformMapping& operator=(
      Wedge400CFabricPlatformMapping const&) = delete;
};
} // namespace fboss
} // namespace facebook
