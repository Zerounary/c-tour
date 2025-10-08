#include <iostream>
#include "mathlib/math.hpp"
#include <fmt/core.h>

int main() {
    int a = 5;
    int b = 3;
    int result = mathlib::add(a, b);

    fmt::print("Hello from fmt!\n");
    fmt::print("The sum of {} and {} is {}.\n", a, b, result);
    
    return 0;
}