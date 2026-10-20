/*******************************
*ФИО:Шамин Александр Сергеевич *
*Группа: ПИ-261                *
*Вариант: 35                   *
********************************/

#include <iostream>
using namespace std;

int main() {
  const int maxSize = 20;
  const int maxValue = 1000;

  int matrix[maxSize][maxSize];
  int characteristics[maxSize] = {};
  int rows, columns;

  cin >> rows >> columns;

  if (!cin || rows < 1 || rows > maxSize ||
      columns < 1 || columns > maxSize) {
    cout << "INVALID\n";
    return 1;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cin >> matrix[i][j];

      if (!cin || matrix[i][j] < -maxValue ||
          matrix[i][j] > maxValue) {
        cout << "INVALID\n";
        return 1;
      }

      if (matrix[i][j] > 0 && matrix[i][j] % 2 != 0) {
        characteristics[i]++;
      }
    }
  }

  cout << "Исходная матрица:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "Характеристики строк:\n";
  for (int i = 0; i < rows; i++) {
    cout << characteristics[i] << "\n";
  }

  for (int i = 0; i < rows - 1; i++) {
    for (int j = 0; j < rows - 1 - i; j++) {
      if (characteristics[j] < characteristics[j + 1]) {
        int temp = characteristics[j];
        characteristics[j] = characteristics[j + 1];
        characteristics[j + 1] = temp;

        for (int k = 0; k < columns; k++) {
          temp = matrix[j][k];
          matrix[j][k] = matrix[j + 1][k];
          matrix[j + 1][k] = temp;
        }
      }
    }
  }

  cout << "Полученная матрица:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
