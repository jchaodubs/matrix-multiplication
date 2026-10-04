#include <iostream>
#include <vector>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void getDimensions(int &aRows, int &aCols, int &bRows, int &bCols);
void createMatrix(const int &rows, const int &cols, vector<vector<double>> &matrix);
void calculateMatrixProduct(vector<vector<double>> &aMatrix, vector<vector<double>> &bMatrix,   vector<vector<double>> &matrixProduct
);
double dotProduct(vector<double> &aVector, vector<double> &bVector);

int main() {
//   int aRows{};
//   int aCols{};
//   int bRows{};
//   int bCols{};
  int aRows = 2;
  int aCols = 3;
  int bRows = 3;
  int bCols = 2;
  //getDimensions(aRows, aCols, bRows, bCols);
  cout << "Enter Matrix A's values now, pls use numbers, I too lazy to check" << endl;
  vector<vector<double>> aMatrix;
  createMatrix(aRows, aCols, aMatrix);
    cout << "Enter Matrix B's values now, pls use numbers, I too lazy to check" << endl;
  vector<vector<double>> bMatrix;
  createMatrix(bRows, bCols, bMatrix);

  cout << "Deleting System32...." << endl;
  sleep(5);

  vector<vector<double>> matrixProduct;
  calculateMatrixProduct(aMatrix, bMatrix, matrixProduct);

}

double dotProduct(vector<double> &aVector, vector<double> &bVector){
    return 1.0;
}

void getDimensions(int &aRows, int &aCols, int &bRows, int &bCols) {
  while (true) {
    cout << "Enter Matrix A's dimensions(ints only)" << endl;
    cout << "rows: ";
    cin >> aRows;
    if (aRows <= 0) {
      cout << "Number must be more than 0" << endl;
      continue;
    }
    cout << "cols: ";
    cin >> aCols;
    if (aCols <= 0) {
      cout << "Number must be more than 0" << endl;
      continue;
    }
    cout << "Enter Matrix B's dimensions(ints only)" << endl;

    cout << "rows: ";
    cin >> bRows;
    if (bRows <= 0) {
      cout << "Number must be more than 0" << endl;
      continue;
    } else if (aCols != bRows) {
      cout << "Number of cols in Matrix A must match number of rows in Matrix B"
           << endl;
      continue;
    }
    cout << "cols: ";
    cin >> bCols;
    if (bCols <= 0) {
      cout << "Number must be more than 0" << endl;
      continue;
    }
    break;
  }
  return;
}

void createMatrix(const int &rows, const int &cols, vector<vector<double>> &matrix){
    for(int i = 0; i < rows; i++){
        vector<double> row;
        cout << "For row " << i << ":" << endl;
        for(int j = 0; j < cols; j++){
            double temp{};
            cout << "Enter value for indice " << j << ": ";
            cin >> temp;
            row.push_back(temp);
        }
        matrix.push_back(row);
    }
}

void calculateMatrixProduct(vector<vector<double>> &aMatrix, vector<vector<double>> &bMatrix,   vector<vector<double>> &matrixProduct){
    const int aMatrixRows = aMatrix.size();
    const int bMatrixCols = bMatrix[0].size();
    for(int aRow = 0; aRow < aMatrixRows - 1; aRow++){
        for(int bCol = 0; bCol < bMatrixCols - 1; bCol++){
            matrixProduct[aRow][bCol] = dotProduct(aMatrix[aRow], bMatrix[bCol]);
        }
    }
}
