// std headers
#include <cassert>
#include <format>
#include <iostream>

// third party headers

// project headers

/// @brief nonrecursive_factorial is solving the n! without using a lot of
/// memory on the stack
/// @param n an unsigned long
/// @return n! an unsigned long

template <typename T>
auto nonrecursive_factorial(T n) -> T
{
  auto result = n;
  while (n > 1)
  {
    result *= --n;
  }
  return result;
}

auto main(int argc, char* argv[]) -> int
{
  // non-recursive factorial challange
  // Just looping through some smaller values

  auto int_result = nonrecursive_factorial<int>(5);
  auto long_int_result = nonrecursive_factorial<long int>(10);
  auto long_long_int_result = nonrecursive_factorial<long long int>(20);

  std::cout << std::format(
      "int  5! = {}\nlong int 10! = {}\nlong long int 20! = {}\n", int_result,
      long_int_result, long_long_int_result);

  return 0;
}