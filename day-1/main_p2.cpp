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
    int remainder = rotations % MOD;

    if (direction == 'L') {
      int distToZero = (position == 0) ? MOD : position;
      answer += (rotations / MOD) + (remainder > 0 && remainder >= distToZero ? 1 : 0);
      position = (position - remainder + MOD) % MOD;
    } else {
      int distToZero = (position == 0) ? MOD : (MOD - position);
      answer += (rotations / MOD) + (remainder > 0 && remainder >= distToZero ? 1 : 0);
      position = (position + remainder) % MOD;
    }
  }

  std::cout << answer << "\n";
  return 0;
}