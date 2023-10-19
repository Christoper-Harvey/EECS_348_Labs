// load in packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// #include <algorithm>
// #include <numeric>
// #include <iomanip> 
using namespace std;

// https://stackoverflow.com/questions/56554212/how-do-i-read-a-text-file-into-a-2d-vector

int main() {
    // create two different sales instances one for sorted input and one for unsorted. 
    vector<vector<int>> data;

    // // grab the filename from the user. Otherwise you could specify fileName = "./input.txt"
    string fileName;
    // cout << "Enter the name of the file containing matrix data: ";
    // cin >> fileName;

    // use ifstream to recieve the input from cin and parse it as a directory object/folder/file.
    fileName = "matrix_input.txt";
    fstream file(fileName);

    // check if the file is a valid name.
    if (!file.is_open()) {
        // if it isn't valid notify user and end program with an error value of 1.
        cout << "Error opening the file. Make sure the file exists." << endl;
        return 1;
    }
    
    int num;

    getline(file, num);

    int N = num;

    cout << N;

    // for (int i = 0; i < N; i++) {

    //     for (int j = 0; j < N; j++) {

    //         vector<int> row;
        
    //         // assign each month's name using the month array
    //         getline(file, row);

    //         data[i].push_back(row);
    //     }
    // }

    // end program after report is done.
    return 0;
}