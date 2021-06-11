#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n = 4;
  int h = 10;
  double prob[n][h];
  prob[0][0]= 0.8;
  prob[0][1]= 0.7;
  prob[0][2]= 0.65;
  prob[0][3]= 0.62;
  prob[0][4]= 0.6;
  prob[1][0]= 0.75;
  prob[1][1]= 0.7;
  prob[1][2]= 0.67;
  prob[1][3]= 0.65;
  prob[1][4]= 0.62;
  prob[2][0]= 0.9;
  prob[2][1]= 0.7;
  prob[2][2]= 0.6;
  prob[2][3]= 0.55;
  prob[2][4]= 0.5;
  prob[3][0]= 0.81;
  prob[3][1]= 0.78;
  prob[3][2]= 0.26;
  prob[3][3]= 0.32;
  prob[3][4]= 0.62;
  // prob[4][0]= 0.25;
  // prob[4][1]= 0.23;
  // prob[4][2]= 0.77;
  // prob[4][3]= 0.95;
  // prob[4][4]= 0.23;
  // prob[5][0]= 0.9;
  // prob[5][1]= 0.1;
  // prob[5][2]= 0.76;
  // prob[5][3]= 0.15;
  // prob[5][4]= 0.9;

  double array[n][h];
  for (int i = 0; i < h; ++i) {
    array[0][i] = prob[0][i];
  }

   for (int i=1; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      double min = 10;
      for (int k = 0; k <= j; ++k) {
        if (prob[i][k]*array[i-1][j-k] < min){
          // cout << "j = " << j << endl;
          // cout << "prob[" << i << "][" << k << "]*array[" <<i << "-1][" << j << "-" << k << "] = " << prob[i][k]*array[i-1][j-k] << endl;
          min = prob[i][k]*array[i-1][j-k];
        }
      }
      array[i][j] = min;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j=0;j <h; ++j) {
      cout << array[i][j] << "   ";
    }
    cout << endl;
  }

  double current_val = array[n-1][h-1];int hours[3];
  int hours_count = n-1;
   for (int i=n-1; i >= 0; --i) {
    for (int j = h; j >= 0; --j) {
      for (int k = j; k >= 0; --k) {
          if (prob[i][k]*array[i-1][j-k] == current_val){
            current_val = array[i-1][j-k];
            hours[hours_count] = k;
            --hours_count;
            break;
          }
        }
      }
    }
 
  for (int i = 0; i < h; ++i) {
    if (current_val == array[0][i]) {
      hours[hours_count] = i;
    }
  }

  for(int i = 0; i < 3; ++i) {
    cout << hours[i] << " ";
  }
  
  return 0;
}
