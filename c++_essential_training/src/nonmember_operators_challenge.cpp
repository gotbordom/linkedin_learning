// std headers
#include <format>
#include <iostream>
#include <string>

// some globals
const std::string nanstr{"[NAN]"};

class Rational
{
 public:
  Rational(int numberator = 0, int denominator = 1)
      : numerator_(numberator), denominator_(denominator)
  {
  }

  // a copy const but no move const...
  Rational(const Rational& rhs)
      : numerator_(rhs.numerator_), denominator_(rhs.denominator_)
  {
  }

  ~Rational() {}

  auto get_numerator() const -> int { return numerator_; }
  auto get_denominator() const -> int { return denominator_; }
  auto reduce() const -> Rational;
  auto str() const -> std::string;
  auto raw_str() const -> std::string;
  auto operator=(const Rational&) -> Rational&;
  // NOTE: To make this correclty compile we are taking these
  // out of the class and instead defining non-member operators down below.
  //   auto operator+(const Rational&) const -> Rational;
  //   auto operator-(const Rational&) const -> Rational;
  //   auto operator*(const Rational&) const -> Rational;
  //   auto operator/(const Rational&) const -> Rational;

 private:
  int numerator_{0};
  int denominator_{1};
};

auto Rational::reduce() const -> Rational
{
  // example shows this to be denominator_ <=3. I  would
  // argue that it should be <=1 because a denominator of 2 or three could
  // still be reduced.
  if (numerator_ == 0 || denominator_ <= 3) return *this;
  for (auto div = denominator_ - 1; div; --div)
  {
    if (numerator_ % div == 0 && denominator_ % div == 0)
    {
      return Rational(numerator_ / div, denominator_ / div);
    }
  }

  // it is already as reduced as possible.
  return *this;
}

auto Rational::str() const -> std::string
{
  // boundary conditions
  if (denominator_ == 0) return nanstr;
  if (denominator_ == 1 || numerator_ == 0) return std::to_string(numerator_);

  // we need to know if we have
  auto abs_numerator = std::abs(numerator_);
  if (abs_numerator > denominator_)
  {
    auto whole = numerator_ / denominator_;
    auto remainder = abs_numerator % denominator_;
    if (remainder)
    {
      return std::to_string(whole) + " " +
             Rational(remainder, denominator_).str();
    }
    else
      return std::to_string(whole);
  }
  else
  {
    return reduce().raw_str();
  }
}

auto Rational::raw_str() const -> std::string
{
  return std::to_string(numerator_) + "/" + std::to_string(denominator_);
}

auto Rational::operator=(const Rational& rhs) -> Rational&
{
  if (this != &rhs)
  {
    numerator_ = rhs.numerator_;
    denominator_ = rhs.denominator_;
  }
  return *this;
}

// NOTE: I  am leaving these here as a reminder of how the class implementations
// were made but replacing them with non-member implementations so that the code
// correctly compiles.

// auto Rational::operator+(const Rational& rhs) const ->
// Rational
// {
//   auto n = numerator_ * rhs.denominator_ + denominator_ * rhs.numerator_;
//   auto d = denominator_ * rhs.denominator_;
//   return Rational(n, d);
// }
// auto Rational::operator-(const Rational& rhs) const -> Rational
// {
//   auto n = numerator_ * rhs.denominator_ - denominator_ * rhs.numerator_;
//   auto d = denominator_ * rhs.denominator_;
//   return Rational(n, d);
// }
// auto Rational::operator*(const Rational& rhs) const -> Rational
// {
//   return Rational(numerator_ * rhs.numerator_, denominator_ *
//   rhs.denominator_);
// }
// auto Rational::operator/(const Rational& rhs) const -> Rational
// {
//   return Rational(numerator_ * rhs.denominator_, denominator_ *
//   rhs.numerator_);
// }

auto operator+(const Rational& lhs, const Rational& rhs) -> Rational
{
  auto n = lhs.get_numerator() * rhs.get_denominator() +
           lhs.get_denominator() * rhs.get_numerator();
  auto d = lhs.get_denominator() * rhs.get_denominator();
  return Rational(n, d);
}
auto operator-(const Rational& lhs, const Rational& rhs) -> Rational
{
  auto n = lhs.get_numerator() * rhs.get_denominator() -
           lhs.get_denominator() * rhs.get_numerator();
  auto d = lhs.get_denominator() * rhs.get_denominator();
  return Rational(n, d);
}
auto operator*(const Rational& lhs, const Rational& rhs) -> Rational
{
  return Rational(lhs.get_numerator() * rhs.get_numerator(),
                  lhs.get_denominator() * rhs.get_denominator());
}
auto operator/(const Rational& lhs, const Rational& rhs) -> Rational
{
  return Rational(lhs.get_numerator() * rhs.get_denominator(),
                  lhs.get_denominator() * rhs.get_numerator());
}

auto main(int argc, char* argv[]) -> int
{
  Rational a{4, 3};  //  1 1/3

  std::cout << std::format("a + 20 = {}\n", (a + 20).str());  //  21 1/3
  std::cout << std::format("a - 20 = {}\n", (a - 20).str());  // -18 2/3
  std::cout << std::format("a * 20 = {}\n", (a * 20).str());  //  26 2/3
  std::cout << std::format("a / 20 = {}\n", (a / 20).str());  //     1/15

  std::cout << "\n";

  // CHALLENGE: With only the class definitions there were not compiling.
  // This challenge is to adjust the code above to allow this to compile.
  std::cout << std::format("20 + a = {}\n", (20 + a).str());  //  21 1/3
  std::cout << std::format("20 - a = {}\n", (20 - a).str());  //  18 2/3
  std::cout << std::format("20 * a = {}\n", (20 * a).str());  //  26 2/3
  std::cout << std::format("20 / a = {}\n", (20 / a).str());  //  15

  return 0;
}