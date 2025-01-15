// std headers
#include <cassert>
#include <format>
#include <iostream>
#include <vector>

// third party headers

// project headers

// Challange: calculate the first 25 prime numbers
// Function: is_number_prime(int) -> bool

/// @brief  is_number_prime is a helper function It determines if a number given
///         to it is prime. A prime number is one that is:
///           - Natural number ( positive )
///           - Greater than 1
///           - Cannot be a product of 2 natural numbers, i.e can only be
///           divisible by itself and 1.
/// @param number an int to test for prime-ness
/// @return
auto is_number_prime(int number) -> bool
{
  // If we are 1 or less we are not prime
  if (number <= 1) return false;

  auto denominator = 2;
  while (denominator < number)
  {
    if ((number % denominator) == 0)
    {
      return false;
    }
    denominator++;
  }

  return true;
}

// I believe prime numbers are possible to generate by a series ? I don't recall
// the series off hand so I will just solve a simple implementation at the
// moment since this is a coding challenge not a math challange
auto main(int argc, char* argv[]) -> int
{
  // Pick the number of prime values to generate
  auto wanted_primes = 25;
  auto primes_found = 0;
  auto num_to_check = 0;  // 0 and 1 cannot be prime

  auto primes = std::vector<int>();
  while (primes_found < wanted_primes)
  {
    if (is_number_prime(num_to_check))
    {
      std::cout << std::format("found: {}", num_to_check) << std::endl;
      primes.push_back(num_to_check);
      primes_found++;
    }

    num_to_check++;
  }

  // confirm that the array was created correctly
  for (auto prime : primes) std::cout << std::format("{} ", prime);
  std::cout << std::endl;

  // TODO:  Move this into tests
  auto expected_vector =
      std::vector<int>{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                       43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  assert(primes.size() == wanted_primes);
  assert(primes == expected_vector);
  return 0;
}