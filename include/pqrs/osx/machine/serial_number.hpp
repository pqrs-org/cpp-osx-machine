#pragma once

// (C) Copyright Takayama Fumihiko 2024.
// Distributed under the Boost Software License, Version 1.0.
// (See https://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <sstream>
#include <type_safe/strong_typedef.hpp>

namespace pqrs {
namespace osx {
namespace machine {
struct serial_number : type_safe::strong_typedef<serial_number, std::string>,
                       type_safe::strong_typedef_op::equality_comparison<serial_number> {
  using strong_typedef::strong_typedef;
};

inline std::ostream& operator<<(std::ostream& os, const serial_number& value) {
  return os << type_safe::get(value);
}
} // namespace machine
} // namespace osx
} // namespace pqrs
