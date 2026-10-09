#include <iostream>
#include <unistd.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void getDimensions(int &aRows, int &aCols, int &bRows, int &bCols);
void createMatrix(const int &rows, const int &cols,
                  vector<vector<double>> &matrix);
void createEmptyMatrix(const int &rows, const int &cols,
                       vector<vector<double>> &matrix);
void calculateMatrixProduct(vector<vector<double>> &aMatrix,
                            vector<vector<double>> &bMatrix,
                            vector<vector<double>> &matrixProduct);
double dotProduct(const vector<double> &aVector, const int &bCol,
                  const vector<vector<double>> &bMatrix);
void printMatrix(vector<vector<double>> &matrixProduct);

int main() {
  int aRows{};
  int aCols{};
  int bRows{};
  int bCols{};
  getDimensions(aRows, aCols, bRows, bCols);
  cout << "Enter Matrix A's values now, pls use numbers, I too lazy to check"
       << endl;
  vector<vector<double>> aMatrix;
  createMatrix(aRows, aCols, aMatrix);
  cout << "Enter Matrix B's values now, pls use numbers, I too lazy to check"
       << endl;
  vector<vector<double>> bMatrix;
  createMatrix(bRows, bCols, bMatrix);

  cout << "Deleting System32...." << endl;
  sleep(2);

  vector<vector<double>> matrixProduct;
  createEmptyMatrix(aRows, bCols, matrixProduct);
  calculateMatrixProduct(aMatrix, bMatrix, matrixProduct);
  printMatrix(matrixProduct);
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

void createMatrix(const int &rows, const int &cols,
                  vector<vector<double>> &matrix) {
  for (int i = 0; i < rows; i++) {
    vector<double> row;
    cout << "For row " << i << ":" << endl;
    for (int j = 0; j < cols; j++) {
      double temp{};
      cout << "Enter value for indice " << j << ": ";
      cin >> temp;
      row.push_back(temp);
    }
    matrix.push_back(row);
  }
}

void createEmptyMatrix(const int &rows, const int &cols,
                       vector<vector<double>> &matrix) {
  for (int i = 0; i < rows; i++) {
    vector<double> row(cols, 0);
    matrix.push_back(row);
  }
}

void calculateMatrixProduct(vector<vector<double>> &aMatrix,
                            vector<vector<double>> &bMatrix,
                            vector<vector<double>> &matrixProduct) {
  const int aMatrixRows = aMatrix.size();
  const int bMatrixCols = bMatrix[0].size();
  for (int aRow = 0; aRow < aMatrixRows; aRow++) {
    for (int bCol = 0; bCol < bMatrixCols; bCol++) {
      matrixProduct[aRow][bCol] = dotProduct(aMatrix[aRow], bCol, bMatrix);
    }
  }
}

double dotProduct(const vector<double> &aVector, const int &bCol,
                  const vector<vector<double>> &bMatrix) {
  double product{};
  const int &vectorSize = aVector.size();
  for (int i = 0; i < vectorSize; i++) {
    product += aVector[i] * bMatrix[i][bCol];
  }
  return product;
}

void printMatrix(vector<vector<double>> &matrixProduct) {
  for (const vector<double> &vector : matrixProduct) {
    for (const auto &val : vector) {
      cout << val << " ";
    }
    cout << endl;
  }
}
