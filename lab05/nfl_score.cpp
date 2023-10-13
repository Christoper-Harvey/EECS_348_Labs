// TD + 2pt - 8
// TD + FG  - 7
// TD       - 6
// FG       - 3
// Safety   - 2

// load modules
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // make a boolean to control while loop.
    bool breakout = true;
    // print instructions only once outside of while loop.
    cout << "Enter 0 or 1 to STOP" << endl;
    // create loop to run the program until it ends.
    while (breakout) {
        // prompt user and takes in user input.
        cout << "Enter the NFL score: ";
        int input;
        // check if input is valid integer.
        if (cin >> input) {
            // if input is less than 2, stop loop and end program.
            if (input < 2) {
                breakout = false;
            } else {
                // super naive approach:
                // for each possible value of each value that fits in the input, loop through and check each possible combinations.
                for (int TD = 0; TD * 6 <= input; TD++) {
                    for (int FG = 0; FG * 3 <= input; FG++) {
                        for (int safety = 0; safety * 2 <= input; safety++) {
                            for (int TD2 = 0; TD2 * 8 <= input; TD2++) {
                                for (int TDFG = 0; TDFG * 7 <= input; TDFG++) {
                                    // sum values together to get total output.
                                    int score = (TD * 6) + (FG * 3) + (safety * 2) + (TD2 * 8) + (TDFG * 7);
                                    // if sum is equal to the user input, print values.
                                    if (score == input) {
                                        cout << TD2 << "TD + 2pt, " << TDFG << " TD + FG, " << TD << " TD, " << FG << " 3pt FG, " << safety << " Safety" << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else {
            // if input isn't valid, delete cin and restart loop.
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return 0;
}