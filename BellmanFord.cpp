#include <iostream>
using namespace std;

int main() {
  int array[5][5];
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
  cout << endl;

  int iteration[5][5];
  for (int i = 0; i <5; ++i) {
    iteration[0][i] = 0;
  }
  for (int j = 0; j < 5; ++j) {
    for (int i = 1; i <5; ++i) {
      iteration[i][j] = 100;
    }
  }

  for (int i=0; i < 5; ++i) {
    for (int j=0; j< 5; ++j) {
      cout << iteration[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;




  for (int j = 0; j < 5; ++j) {
    cout << "iteration " << j+1 << endl;
    for (int v = 0; v < 5; ++v) {
      for (int u = 0; u < 5; ++u) {
        if (iteration[u][j] != 100 && iteration[u][v] != 100) {
          if (iteration[u][j] + array[u][v] < iteration[v][j]){
            iteration[v][j] = iteration[u][j-1] + array[u][v];
          }
        }
      }
    }
    for (int i=0; i < 5; ++i) {
    for (int j=0; j< 5; ++j) {
      cout << iteration[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  }
  cout << endl;
}
