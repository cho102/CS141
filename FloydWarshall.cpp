#include <iostream>
using namespace std;

int main() {
  int array[5][5];
  // int bt[5][5];

  // bt[0][0] = 0;
  // bt[0][1] = 1;
  // bt[0][2] = 1;
  // bt[0][3] = 100;
  // bt[0][4] = 1;
  // bt[1][0] = 100;
  // bt[1][1] = 0;
  // bt[1][2] = 100;
  // bt[1][3] = 2;
  // bt[1][4] = 2;
  // bt[2][0] = 100;
  // bt[2][1] = 3;
  // bt[2][2] = 0;
  // bt[2][3] = 100;
  // bt[2][4] = 100;
  // bt[3][0] = 4;
  // bt[3][1] = 100;
  // bt[3][2] = 4;
  // bt[3][3] = 0;
  // bt[3][4] = 100;
  // bt[4][0] = 100;
  // bt[4][1] = 100;
  // bt[4][2] = 100;
  // bt[4][3] = 5;
  // bt[4][4] = 0;

  array[0][0] = 0;
  array[0][1] = 5;
  array[0][2] = 6;
  array[0][3] = 3;
  array[0][4] = -4;
  array[1][0] = 100;
  array[1][1] = 0;
  array[1][2] = 100;
  array[1][3] = 1;
  array[1][4] = 7;
  array[2][0] = 100;
  array[2][1] = 4;
  array[2][2] = 0;
  array[2][3] = 100;
  array[2][4] = 100;
  array[3][0] = 100;
  array[3][1] = 100;
  array[3][2] = -5;
  array[3][3] = 0;
  array[3][4] = 100;
  array[4][0] = 100;
  array[4][1] = 100;
  array[4][2] = 3;
  array[4][3] = 6;
  array[4][4] = 0;

  for (int i=0; i < 5; ++i) {
    for (int j=0; j< 5; ++j) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
  //  cout << endl << endl;
  // for (int i=0; i < 5; ++i) {
  //   for (int j=0; j< 5; ++j) {
  //     cout << bt[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  

  cout << endl;

  for (int k = 0; k < 5; ++k) {
    cout << endl << "Iteration " << k+1 << endl;
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        if ((array[i][k] != 100) && (array[k][j] != 100)){
          if (array[i][k] + array[k][j] < array[i][j]) {
            cout << "array[" << i <<"][" << k << "] + array[" << k << "][" << j << "] < array[" << i << "][" << j << "]" << endl;
            cout << array[i][k] << " + " << array[k][j] << " < " << array[i][j] << endl << endl;
            array[i][j] = array[i][k] + array[k][j];
            // bt[i][j] = k+1;
          }
        }
      }
    }
    for (int i=0; i < 5; ++i) {
    for (int j=0; j< 5; ++j) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
  }


  return 0;
}
