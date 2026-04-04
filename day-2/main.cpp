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

  std::vector<std::pair<int, int>> ranges;

  for (const auto &p : products) {
    std::stringstream ss2(p);
    std::string token;
    std::vector<int> parts;

    while (std::getline(ss2, token, '-')) {
      parts.push_back(std::stoi(token));
    }

    ranges.push_back({parts[0], parts[1]});
  }

  for (const auto &r : ranges) {
    std::cout << r.first << '-' << r.second << "\n";
  }

  return 0;
}
