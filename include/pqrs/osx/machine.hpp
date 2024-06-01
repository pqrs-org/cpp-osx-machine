#pragma once

// pqrs::osx::machine v1.0

// (C) Copyright Takayama Fumihiko 2024.
// Distributed under the Boost Software License, Version 1.0.
// (See https://www.boost.org/LICENSE_1_0.txt)

// `pqrs::osx::machine` can be used safely in a multi-threaded environment.

#include "machine/serial_number.hpp"
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <optional>
#include <pqrs/cf/string.hpp>

namespace pqrs {
namespace osx {
namespace machine {

inline std::optional<serial_number> find_serial_number(void) {
  std::optional<serial_number> result;

  if (auto platform_expert = IOServiceGetMatchingService(kIOMainPortDefault,
                                                         IOServiceMatching("IOPlatformExpertDevice"))) {
    auto sn = IORegistryEntryCreateCFProperty(platform_expert,
                                              CFSTR(kIOPlatformSerialNumberKey),
                                              kCFAllocatorDefault,
                                              0);
    if (sn) {
      if (auto s = pqrs::cf::make_string(sn)) {
        result = serial_number(*s);
      }

      CFRelease(sn);
    }

    IOObjectRelease(platform_expert);
  }

  return result;
}

} // namespace machine
} // namespace osx
} // namespace pqrs
