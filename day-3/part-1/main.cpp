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
    if (leftIndex + 1 == move.size()) { // it is at last index
      for (int i = 0; i < leftIndex; i++) {
        int digit{move[i] - '0'};
        if (right < digit) {
          right = digit;
        }
      }
    } else {
    }
  }

  return 0;
}