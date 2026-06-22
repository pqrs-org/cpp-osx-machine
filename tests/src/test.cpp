#include <boost/ut.hpp>
#include <pqrs/osx/machine.hpp>
#include <sstream>

int main() {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "serial_number"_test = [] {
    pqrs::osx::machine::serial_number value("C02TEST00000");

    std::stringstream stream;
    stream << value;

    expect("C02TEST00000" == stream.str());
    expect(value == pqrs::osx::machine::serial_number("C02TEST00000"));
    expect(value != pqrs::osx::machine::serial_number("C02TEST00001"));
  };

  "find_serial_number"_test = [] {
    auto actual = pqrs::osx::machine::find_serial_number();
    expect(std::nullopt != actual);
  };

  return 0;
}
