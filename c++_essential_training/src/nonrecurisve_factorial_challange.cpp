// std headers
#include <cassert>
#include <format>
#include <iostream>

// third party headers

// project headers

/// @brief recursive_factorial is used mainly to validate my non recursive
/// factorial
/// @param n an unsigned long
/// @return n! an unsigned long
auto recursive_factorial(unsigned long n) -> unsigned long
{
  if (n < 2)
    return 1;
  else
    return n * recursive_factorial(n - 1);
}

/// @brief nonrecursive_factorial is solving the n! without using a lot of
/// memory on the stack
/// @param n an unsigned long
/// @return n! an unsigned long
auto nonrecursive_factorial(unsigned long n) -> unsigned long
{
  auto result = n;
  while (n > 1)
  {
    result *= n;
    --n;
  }
  return result;
}

auto main(int argc, char* argv[]) -> int
{
  // non-recursive factorial challange
  // Just looping through some smaller values

  // NOTE around 15! we start seeing overloading.  If I made them
  // unsigned long long we could likely  get to ... 20!
  for (auto n = 0; n < 100; ++n)
  {
    auto non_recursive_result = nonrecursive_factorial(n);
    auto recursive_result = recursive_factorial(n);

    std::cout << std::format(
        "iteration {}:\n\tnon recursive: {} \n\t    recursive: {}\n", n,
        non_recursive_result, recursive_result);
    // assert(recursive_result == non_recursive_result);
  }
  return 0;
}