// std headers
#include <iostream>
#include <string>
#include <format>
#include <utility>

// third party headers

// project headers



// NOTES: I thought about making it a class with getters/ setters, etc. But this is a tutorial and 
// I don't see a reason to overcomplicate a solution.
struct LibraryCatalogCard{
    LibraryCatalogCard(std::string title, std::string author, std::string publisher, 
        std::string subject, std::string isbn, std::string world_cat, std::pair<int,int> dewey_decimal, 
        int publication_year, int aquisition_year, int total_owned, int total_in_stock)
	    : title_(title), author_(author), publisher_(publisher), subject_(subject), isbn_(isbn), 
	      world_cat_(world_cat), dewey_decimal_(dewey_decimal), publication_year_(publication_year), 
	      total_owned_(total_owned), total_in_stock_(total_in_stock) 
        {}

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

auto main(int argc, char** argv) -> int {

    // Just creating the struct example
    auto lib_card = LibraryCatalogCard(
        "My New Title", "Some Author", "By a publishing company", 
        "Horror", "1234567890", "world_cat_value?", 
        std::pair{100,10}, 1999, 2000, 10, 1);

    // printing out some of the data
    std::cout << std::format("Hello my new library card.\n\tTitle: {} \n\tAuthor: {} \n\tSubject: {}", 
        lib_card.title_, lib_card.author_, lib_card.subject_) << std::endl;

    return 0;
}
