#include <boost/ut.hpp>
#include <pqrs/osx/machine.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "find_serial_number"_test = [] {
    auto actual = pqrs::osx::machine::find_serial_number();
    expect(std::nullopt != actual);
  };

  return 0;
}
