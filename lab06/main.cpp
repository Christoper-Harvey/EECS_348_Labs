#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 100;

// function to read matrix data from file. takes in const matrix, size, and filename
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int &size, const string &filename) {
    // open file. I have this hardcoded as "matrix_input.txt" for convience. Could easily switch that to cin to take in file name.
    ifstream file(filename);
    if (file.is_open()) {
        // get the first line from the matrix input file. This should be the size of the matrix. Store that value in size.
        file >> size;

        // loop through the size of "size" twice to assign every matrix location in the NxN.
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                // check if the file has enough input for size N
                if (file.eof()) {
                    cerr << "Data error in the file." << endl;
                    break;
                }
                // assign matrix index to current value from file in loop.
                file >> matrix[i][j];
            }
        }
        // close file as good practice.
        file.close();
    } else {
        // manage error.
        cerr << "Unable to open the file. Please verify input data." << endl;
    }
}
// function to loop through contents of the matrix and return them.
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // set spacing for print to 3 to keep it even across rows.
            cout << setw(3) << matrix[i][j] << " ";
        }
        // add new line after each row.
        cout << endl;
    }
}
// function to loop through both matrices and add them together by index. This updates a new matrix called result.
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// function to loop through both matrices and multiply them together by index. This updates a new matrix called result.
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
// function to loop through both matrices and subtract them by index. This updates a new matrix called result.
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
// main function
int main() {
    // declare size, and blank nested arrays to store data in.
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Read first matrix from file.
    readMatrixFromFile(matrixA, size, "matrix_input.txt");

    // Create new matrix by adding 1 to each value in original.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrixB[i][j] = matrixA[i][j] + 1;
        }
    }

    // start terminal outputs.
    cout << "Chris Harvey" << endl;
    cout << "Lab #6: Matrix manipulation" << endl;

    // print first matrix
    cout << "Matrix A:" << endl;
    printMatrix(matrixA, size);

    // print second matrix
    cout << "Matrix B:" << endl;
    printMatrix(matrixB, size);

    // add matrices and display the result
    addMatrices(matrixA, matrixB, result, size);
    cout << "Matrix Sum (A + B):" << endl;
    printMatrix(result, size);

    // multiply matrices and display the result
    multiplyMatrices(matrixA, matrixB, result, size);
    cout << "Matrix Product (A * B):" << endl;
    printMatrix(result, size);

    // subtract matrices and display the result
    subtractMatrices(matrixA, matrixB, result, size);
    cout << "Matrix Difference (A - B):" << endl;
    printMatrix(result, size);

    return 0;
}