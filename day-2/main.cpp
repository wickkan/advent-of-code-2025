#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/*

- receive input
e.g. x-y is the range starting at x and ending at y
separated by a comma

*/

int main() {
  std::ifstream file{"example.txt"};
  std::string content;
  std::getline(file, content);

  std::vector<std::string> products;
  std::stringstream ss(content);
  std::string product;

  // adding all of the ranges to the products list
  while (std::getline(ss, product, ',')) {
    products.push_back(product);
  }

  for (std::size_t i = 0; i < products.size(); i++) {
    for (std::size_t j = 0; j < products[i].size(); j++) {
      std::cout << products[i][j] << "\n";
    }
  }

  return 0;
}
