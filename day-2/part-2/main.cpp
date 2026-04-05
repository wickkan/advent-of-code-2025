#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// parsing the ranges
std::vector<std::pair<long long, long long>> parseRanges(const std::string &content) {
  std::vector<std::pair<long long, long long>> ranges;
  std::stringstream ss(content);
  std::string token;

  while (std::getline(ss, token, ',')) {
    std::stringstream ss2(token);
    std::string part;
    std::vector<long long> parts;

    while (std::getline(ss2, part, '-')) {
      parts.push_back(std::stoll(part));
    }

    ranges.push_back({parts[0], parts[1]});
  }

  return ranges;
}

// determining if an ID is invalid
bool isInvalid(long long n) {

  std::string s = std::to_string(n);
  long long len = static_cast<int>(s.length());

  for (long long k = 1; k <= len / 2; k++) {
    if (len % k == 0) {
      std::string substring{s.substr(0, k)};
      std::string repeated{""};
      long long repetitions{len / k};

      for (int i = 0; i < repetitions; i++) {
        repeated += substring;
      }

      if (repeated == s) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  std::ifstream file{"data.txt"};
  std::string content;
  std::getline(file, content);

  auto ranges = parseRanges(content);

  long long answer{};
  for (const auto &r : ranges) {
    for (long long i = r.first; i <= r.second; i++) {
      if (isInvalid(i)) {
        answer += i;
      }
    }
  }

  std::cout << answer << "\n";

  return 0;
}
