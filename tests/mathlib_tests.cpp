#include <catch2/catch_test_macros.hpp>
#include "mathlib/math.hpp"

TEST_CASE("Addition is computed", "[mathlib]") {
    REQUIRE(mathlib::add(1, 1) == 2);
    REQUIRE(mathlib::add(5, 3) == 8);
    REQUIRE(mathlib::add(-1, 1) == 0);
    REQUIRE(mathlib::add(-5, -5) == -10);
}