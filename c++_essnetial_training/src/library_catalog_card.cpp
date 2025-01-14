// std headers
#include <iostream>
#include <string>
#include <format>
#include <utility>

// third party headers

// project headers


class LibraryCatalogCard{
public:
    LibraryCatalogCard(std::string title, std::string author, std::string publisher, 
		       std::string subject, std::string isbn, std::pair<int,int> dewey_decimal, 
		       int publication_year, int aquisition_year, int total_owned, int total_in_stock)
	    : title_(title), author_(author), publisher_(publisher), subject_(subject), isbn_(isbn), 
	      world_cat_(world_cat), dewey_decimal_(dewey_decimal), publication_year_(publication_year), 
	      total_owned_(total_owned), total_in_stock_(total_in_stock)

private:
    std::string title_;
    std::string author_;
    std::string publisher_;
    std::string subject_;
    std::string isbn_;
    std::string world_cat_;
    std::pair<int, int> dewey_decimal_;
    int pulication_year_;
    int aquisition_year_;
    int total_owned_;
    int total_in_stock_;
};

auto main(int argc, char** argv) -> int {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
