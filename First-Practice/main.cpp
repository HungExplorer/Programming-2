#include <iostream>
#include <fstream>
#include <iomanip> // Design the output display, just using setw() for aligning text

using namespace std;

const int MAX_N = 1000;  // Set the maximum complex numbers input, which is 1000 values

int readFile(const char* filename, double matrix[3][MAX_N]) {
    ifstream file(filename); //Read the file 

    int n;
    file >> n; // Read the first line, which is the number of complex numbers
    if (n < 5) {
        cout << "The File must contain at least 5 complex numbers" << endl;
        return 0;
    }

    /*Read the values using maxtrix, the first row is the real part, 
    the second one is the imaginary part, the third row is the magnitude */
    
    for (int i = 0; i < n; i++) {
        file >> matrix[0][i] >> matrix[1][i]; //Read each line containing real part and imaginary one respectively
        matrix[2][i] = matrix[0][i] * matrix[0][i] + matrix[1][i] * matrix[1][i]; //Calculation for magnitude
    }
    
     /* Example for the Format of Matrix 
        Real:       3   1   0   2
        Imaginary:  4   1   5   2
        Magnitude²: 25  2   25  8
        */

    file.close();
    return n;
}

// Using Selection Sort by mag value 
void sortDescending(double matrix[3][MAX_N], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i; //the position containing max values
        for (int j = i + 1; j < n; j++) {
            if (matrix[2][j] > matrix[2][max_idx]) {
                max_idx = j;
            }
        }
        for (int row = 0; row < 3; row++) { //Swapping all 3 rows because of 3 values real, imag and mag^2
            double temp = matrix[row][i];
            matrix[row][i] = matrix[row][max_idx];
            matrix[row][max_idx] = temp;
        }
    }
}

// Function prints out all the results
// I make this unique part to show all the results after calculating and sorting
void Matrix(double matrix[3][MAX_N], int n) {
    cout << "\nAfter sorting:\n";
    cout << setw(11) << "Real" << setw(14) << "Imaginary" << setw(15) << "Magnitude^2" << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << setw(10) << matrix[0][i] << setw(10) << matrix[1][i] << setw(15) << matrix[2][i] << endl;
    }
}

// Function prints out the 5 numbers with the largest magnitude
void Top5(double matrix[3][MAX_N]) {
    cout << "\n5 numbers with the largest magnitude:\n";
    for (int i = 0; i < 5; i++) {
        cout << matrix[0][i] << " + " << matrix[1][i] << "i" <<endl;
    }
}

int main() {
    double matrix[3][MAX_N];  // Matrix 3 x n to store the complex numbers

    int n = readFile("In.txt", matrix);
    if (n == 0) {
        return 0; // End the program if n < 5
    }
    
    sortDescending(matrix, n);
    Matrix(matrix, n);
    Top5(matrix);

    return 0;
}
