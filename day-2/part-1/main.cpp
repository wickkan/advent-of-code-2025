#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isInvalid(long long n) {
  std::string s = std::to_string(n);
  int len = s.length();
}

int main() {
  std::ifstream file{"data.txt"};
  std::string content;
  std::getline(file, content);

  std::vector<std::string> products;
  std::stringstream ss(content);
  std::string product;

  // adding all of the ranges to the products list
  while (std::getline(ss, product, ',')) {
    products.push_back(product);
  }

  std::vector<std::pair<long long, long long>> ranges;

  for (const auto &p : products) {
    std::stringstream ss2(p);
    std::string token;
    std::vector<long long> parts;

    while (std::getline(ss2, token, '-')) {
      parts.push_back(std::stoll(token));
    }

    ranges.push_back({parts[0], parts[1]});
  }

  long long answer{};
  for (const auto &r : ranges) {
    for (long long i = r.first; i <= r.second; i++) {
      std::string s = std::to_string(i);
      if (s.length() % 2 == 0) {
        int length{static_cast<int>(s.length())};
        int left{0};
        int right{length / 2};
        while (right < length && s[left] == s[right]) {
          left++;
          right++;
        }
        if (right == length) {
          answer += i;
        }
      }
    }
  }

  std::cout << answer << "\n";

  return 0;
}
