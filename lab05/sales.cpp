// load in packages
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

// create class to manage input data.
struct MonthlySales {
    string month;
    double sales;
};

int main() {
    // create two different sales instances one for sorted input and one for unsorted. 
    vector<MonthlySales> salesData;
    vector<MonthlySales> orderedData;
    // create the string array which maps the names for the input data. This assumes the first input of "input.txt" will be Jan and the last Dec.
    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // grab the filename from the user. Otherwise you could specify fileName = "./input.txt"
    string fileName;
    cout << "Enter the name of the file containing sales data: ";
    cin >> fileName;

    // use ifstream to recieve the input from cin and parse it as a directory object/folder/file.
    ifstream file(fileName);
    // check if the file is a valid name.
    if (!file.is_open()) {
        // if it isn't valid notify user and end program with an error value of 1.
        cout << "Error opening the file. Make sure the file exists." << endl;
        return 1;
    }

    // create sum variable to add all months together.
    double totalSales = 0.0;
    // print beginning report here outside of for loop to avoid overprinting.
    cout << "Monthly sales report for 2022:" << endl;
    cout << "Month Sales" << endl;
    // Read monthly sales data from the file
    for (int i = 0; i < 12; ++i) {
        // create an instance of input class to manage data input.
        MonthlySales data;
        // assign each month's name using the month array
        data.month = months[i];
        // check if valid input like before
        if (!(file >> data.sales)) {
            // if it isn't end program.
            cout << "Error reading sales data from the file." << endl;
            return 1;
        }
        // add month data to both of our data vectors.
        salesData.push_back(data);
        orderedData.push_back(data);
        // increment the total sales sum.
        totalSales += data.sales;
        // print the month and its value here instead of in a new loop later on since the report starts with this information.
        cout << data.month << " $" << fixed << setprecision(2) << data.sales << endl;
    }

    // Sort sales data from highest to lowest using our ordered vector.
    sort(orderedData.begin(), orderedData.end(), [](const MonthlySales &a, const MonthlySales &b) {
        return a.sales > b.sales;
    });

    // Output the rest of the monthly sales report
    cout << "Sales summary:" << endl;
    // since orderedData is sorted we can just grab the last and first values from that vector to print out the min and max
    cout << "Minimum sales: $" << orderedData.back().sales << " (" << orderedData.back().month << ")" << endl;
    cout << "Maximum sales: $" << orderedData[0].sales << " (" << orderedData[0].month << ")" << endl;
    // we just divide our sum by 12 to get the average. 
    cout << "Average sales: $" << fixed << setprecision(2) << totalSales / 12 << endl;
    // create moving average report.
    cout << "Six-Month Moving Average Report:" << endl;
    // loop through the first 7? months. I only did it this way because the example did. I would have stopped at june personally.
    for (int i = 0; i < 7; i++) {
        // create a sum variable for each 6 month section. also reset sum after each iteration.
        double movingAverage = 0;
        // loop through the remaining 5 months to find each of their values as well.
        for (int j = 0; j < 6; j++) {
            // we use "i + j" here to only get the next 6 months from the current i. add value to sum variable.
            // we don't just use 1 vector for the data as it is easier to do this operation on the unsorted list.
            // If the report when this and then the other 2 outputs then just one vector would be needed and you sort after this section to save memory.
            movingAverage += salesData[i + j].sales;
        }
        // print each moving average sum divided by 6 to get the actual average. restart loop until all 6 month pairs have been done.
        cout << months[i] << " - " << months[i + 5] << " $" << fixed << setprecision(2) << movingAverage / 6 << endl;
    }
    // print last bit of sales report.
    cout << "Sales Report (Highest to Lowest):" << endl;
    cout << "Month Sales" << endl;
    // simply loop through the ordered vector and print out all of its values.
    for (const MonthlySales &data : orderedData) {
        cout << data.month << " $" << fixed << setprecision(2) << data.sales << endl;
    }
    // end program after report is done.
    return 0;
}
