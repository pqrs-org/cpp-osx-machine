#include <iostream>
#include <pqrs/osx/machine.hpp>

int main() {
  if (auto serial_number = pqrs::osx::machine::find_serial_number()) {
    std::cout << "serial_number: " << *serial_number << std::endl;
  }

  return 0;
}
