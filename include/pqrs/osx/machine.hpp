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
#include <pqrs/osx/iokit_object_ptr.hpp>

namespace pqrs::osx::machine {

[[nodiscard]] inline std::optional<serial_number> find_serial_number() {
  if (auto platform_expert = pqrs::osx::adopt_iokit_object_ptr(IOServiceGetMatchingService(kIOMainPortDefault,
                                                                                           IOServiceMatching("IOPlatformExpertDevice")))) {
    auto sn = pqrs::cf::adopt_cf_ptr(IORegistryEntryCreateCFProperty(*platform_expert,
                                                                     CFSTR(kIOPlatformSerialNumberKey),
                                                                     kCFAllocatorDefault,
                                                                     0));
    if (sn) {
      if (auto s = pqrs::cf::make_string(*sn)) {
        return serial_number(*s);
      }
    }
  }

  return std::nullopt;
}

} // namespace pqrs::osx::machine
