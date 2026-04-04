#include <fstream>
#include <iostream>
#include <string>

const int MOD = 100;

int main() {
  std::ifstream file("data.txt");
  std::string cmd;

  int position = 50;
  int answer = 0;

  while (std::getline(file, cmd)) {
    char direction = cmd[0];
    int rotations = std::stoi(cmd.substr(1));

    if (direction == 'L') {
      int remainder = rotations % MOD;
      answer += (rotations / MOD) + (position == 0 ? (remainder > 0) : (remainder >= position));
      position = (position - remainder + MOD) % MOD;
    } else if (direction == 'R') {
      int remainder = rotations % MOD;
      answer += (rotations / MOD) + (position == 0 ? (remainder > 0) : (remainder >= MOD - position));
      position = (position + remainder) % MOD;
    }
  }

  std::cout << answer << "\n";
  return 0;
}