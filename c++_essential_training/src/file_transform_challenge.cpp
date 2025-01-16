// std headers
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/// @brief A single inventory item read from a filename items.txt
class InventoryItem
{
 public:
  InventoryItem(int sku, std::string name, std::string description)
      : sku_(sku), name_(name), description_(description)
  {
  }

  auto get_sku() const -> int { return sku_; }
  auto get_name() const -> std::string { return name_; }
  auto get_description() const -> std::string { return description_; }

 private:
  int sku_;  // for the purpose of this it will be an int, likely though it will
             // be something more like a uuid.
  std::string name_;
  std::string description_;
};

/// @brief The entire inventory for any number of items.txt files.
class Inventory
{
 public:
  auto total_items() const -> int { return inventory_.size(); }
  auto print_items() const -> void
  {
    for (const auto& item : inventory_)
    {
      std::cout << std::format("sku: {}, name: {}, description: {}\n",
                               item.get_sku(), item.get_name(),
                               item.get_description());
    }
  }

  auto load_items(std::filesystem::path path) -> void
  {
    int items_added = 0;
    const char delim = '\t';
    const char comment = '#';
    char buffer[256];

    std::filesystem::path currentDir = std::filesystem::current_path();
    // If my file exists exactly or as a relative path. Otherwise exit early.
    if (std::filesystem::exists(path))
    {
      std::cout << std::format("[DEBUG] opening file: {}\n", path.c_str());
    }
    else if (std::filesystem::exists(currentDir / path))
    {
      path = currentDir / path;
      std::cout << std::format("[DEBUG] found relitive path file: {}\n",
                               path.c_str());
    }
    else
    {
      std::cout << std::format(
          "[ERROR] exiting. neither filepath {} or {} exist.\n", path.c_str(),
          (currentDir / path).c_str());
      return;
    }

    // read the inventory items from the file.
    std::ifstream infile(path.c_str());
    while (infile.good())
    {
      infile.getline(buffer, sizeof(buffer));
      std::stringstream ss(buffer);

      // check for empty lines - NOTE: since it  was  all white space I could
      // have used strsplit. Good to remember
      if (ss.str().find_first_not_of(' ') != std::string::npos)
      {
        // get the sku
        std::string sku;
        std::getline(ss, sku, delim);
        std::cout << std::format("[DEBUG] found sku: {}\n", sku);

        // get the name
        std::string name;
        std::getline(ss, name, delim);
        std::cout << std::format("[DEBUG] found name: {}\n", name);

        // get the description
        std::string description;
        std::getline(ss, description, delim);
        std::cout << std::format("[DEBUG] found description: {}\n",
                                 description);

        auto item = InventoryItem(std::stoi(sku.c_str()), name, description);
        inventory_.push_back(item);
        ++items_added;
      }
    }

    std::cout << std::format("Inventory: Added {} items.\n", items_added);
  }

 private:
  std::vector<InventoryItem> inventory_;
};

auto main(int argc, char* argv[]) -> int
{
  // Create an inventory
  Inventory inventory;

  // Load items
  auto path = std::filesystem::path("./inventory/item.txt");
  inventory.load_items(path);

  // Print all items
  std::cout << std::format("I have {} items in my inventory.\n",
                           inventory.total_items());

  inventory.print_items();
  return 0;
}