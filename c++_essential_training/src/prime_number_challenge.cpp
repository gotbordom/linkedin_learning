// std headers
#include <format>
#include <iostream>
#include <vector>

// third party headers

// project headers

// Challange: calculate the first 25 prime numbers
// Function: is_number_prime(int) -> bool
// Function: calculate_prime_numbers(int n) -> std::vector<int>

/**
 * @brief is_number_prime is a helper function to isolate responasibilites to a
 * single function. It determines if a number given to it is prime.
 * A prime number is one that is:
 *   - Natural number ( positive )
 *   - Greater than 1
 *   - Cannot be a product of 2 natural numbers, i.e can only be divisible by
 *   itself and 1.
 *
 * @param number
 * @return int
 */
auto is_number_prime(int number) -> int { return number; }

// I believe prime numbers are possible to generate by a series ? I don't recall
// the series off hand so I will just solve a simple implementation at the
// moment since this is a coding challenge not a math challange
auto main(int argc, char* argv[]) -> int
{
  // Pick the number of prime values to generate
  auto n = 25;
  auto count = 0;
  auto num_to_check = 2;  // 0 and 1 cannot be prime

  auto primes = std::vector<int>();
  while (count != 25)
  {
    if (is_number_prime(num_to_check))
    {
      primes.push_back(num_to_check);
      count++;
    }

    num_to_check++;
  }

  // confirm that the array was created correctly
  for (auto prime : primes) std::cout << std::format("{}, ", prime);
  std::cout << std::endl;

  return 0;
}