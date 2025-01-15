// std headers
#include <format>
#include <iostream>
#include <string>
#include <utility>

// third party headers

// project headers

// There is no need to protect anything on this "public library card".
struct LibraryCatalogCard
{
  // Could add equality operators, etc.

  std::string title_;
  std::string author_;
  std::string publisher_;
  std::string subject_;
  std::string isbn_;
  std::string world_cat_;
  std::pair<int, int> dewey_decimal_;
  int publication_year_;
  int aquisition_year_;
  int total_owned_;
  int total_in_stock_;
};

auto main(int argc, char** argv) -> int
{
  // Just creating the struct example
  auto lib_card = LibraryCatalogCard{"My New Title",
                                     "Some Author",
                                     "By a publishing company",
                                     "Horror",
                                     "1234567890",
                                     "world_cat_value?",
                                     std::pair{100, 10},
                                     1999,
                                     2000,
                                     10,
                                     1};

  // printing out some of the data
  std::cout << std::format(
                   "Hello my new library card.\n\tTitle: {} \n\tAuthor: {} "
                   "\n\tSubject: {}",
                   lib_card.title_, lib_card.author_, lib_card.subject_)
            << std::endl;

  return 0;
}
