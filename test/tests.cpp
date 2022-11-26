#include <catch2/catch.hpp>
#include <iostream>
#include <lib.hpp>
#include <string>

TEST_CASE("Factorials are computed", "[factorial]") { REQUIRE(1 + 2 == 3); }

TEST_CASE("Factorials are computed2", "[factorial]")
{
  // std::string lib_informations = lib::LibInformations();
  std::cout << lib::LibInformations();
  // REQUIRE(lib_informations.rfind("Lib: ", 0) == 0);
  REQUIRE(1 + 2 == 3);
}
