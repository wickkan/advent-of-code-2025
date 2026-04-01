#include <iostream>
#include <string>
#include <string_view>
#include <fstream>

int main()
{
    std::ifstream inf{"data.txt"};

    // if we can't open the data for reading
    if (!inf)
    {
        std::cerr << ("data.txt could not be opened for reading");
    }

    /*
    - start at 50
    - when left: dial - number, if negative number then (100 - abs(subtraction))
    - left e.g., 50 - 50 = 0, 50 - 51 = -1 so (100 - 1) = 99, 50 - 62 so (100 - 12) = 82
    - when right: dial + number, if greater than or equal to 100 then (sum - 100)
    - right e.g. 50 + 49 = 99, 50 + 50 == (100 - 100), 50 + 62 (112 - 100) = 12, 99 + 2 (101 - 100)
    24 / 12 =
    */

    int dial{50};
    int answer{};

    // read input
    std::string strInput{};
    std::size_t startIndex{1};

    while (inf >> strInput)
    {
        std::string currDial{strInput};
        int newDial{};

        if (currDial[0] == 'L') // turn left
        {
            std::cout << std::stoi(currDial.substr(startIndex)) << "\n";
            newDial = dial - std::stoi(currDial.substr(startIndex));
            if (newDial < 0)
            {
                newDial = 100 + newDial;
                dial = newDial;
            }
            else
            {
                dial = newDial;
            }
        }
        else // turn right
        {
            newDial = dial + std::stoi(currDial.substr(startIndex));
            if (newDial >= 100)
            {
                newDial = newDial - 100;
                dial = newDial;
            }
            else
            {
                dial = newDial;
            }
        }

        std::cout << currDial << "\n";
        if (dial == 0)
        {
            answer++;
        }
    }

    std::cout << dial << "\n";
    return 0;
}