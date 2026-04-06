#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream file{"example.txt"};
  std::string move{};

  long long answer{};

  while (getline(file, move)) {
    int leftIndex{};
    int left{};
    for (int i = 0; i < move.size(); i++) {
      int digit{move[i] - '0'};
      if (left < digit) {
        left = digit;
        leftIndex = i;
      }
    }

    int right{};
    for (int i = leftIndex)
  }

  return 0;
}