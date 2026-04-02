#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

const int MOD{100};

int main() {
  std::ifstream file{"data.txt"};
  std::string move{};

  // if we can't open the data for reading
  if (!file) {
    std::cerr << ("data.txt could not be opened for reading");
  }

  int dial{50};
  int answer{};

  while (std::getline(file, move)) {

    char direction{move[0]};
    int rotation{std::stoi(move.substr(1, move.length()))};

    if (direction == 'L') // turn left
    {
      dial = (dial - rotation + MOD) % MOD;
      //   put in if condition for if dial == 0 and how many times it passed 0
    } else if (direction == 'R') // turn right
    {
      dial = (dial + rotation) % MOD;
      //   put in if condition for if dial == 0 and how many times it passed 0
    }
  }

  std::cout << answer << "\n";
  return 0;
}