#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  char Y[100];
  char X[100];
  Y[0] = '-';
  X[0] = '-';
  int m=1;
  int n=1;
  char input;
  cout << "Enter sequence 1(press 'Q' when finished: ";
  cin >> input;
  while (input !='Q') {
    Y[m] = input;
    ++m;
    cin >> input;
  }
  cout << "Enter sequence 2(press 'Q' when finished: ";
  cin >> input;
  while (input !='Q') {
    X[n] = input;
    ++n;
    cin >> input;
  }

  double array[m][n];
  double num = 0;
  for (int i=0; i<m;++i){
    array[i][0] = num;
    num += -0.2;
  }
  cout << endl;
  num = 0;
  for (int i=0; i<n;++i){
    array[0][i] = num;
    num += -0.2;
  }
  cout << endl;

  for(int i=1; i <m; ++i) {
    for (int j=1; j <n; ++j) {
      double diagonal = 0;
      double vertical = 0;
      double horizontal = 0;
      if (Y[i]==X[j]) {
        diagonal = array[i-1][j-1]+1;
      }
      else {
        if ((Y[i]=='C' && X[j] =='G') || (Y[i]=='G' && X[j] =='C') || (Y[i]=='A' && X[j] =='T') || (Y[i]=='T' && X[j] =='A')) {
          diagonal = array[i-1][j-1]-0.15;
        }
        else {
          diagonal = array[i-1][j-1]-0.1;
        }        
      }
      vertical = array[i-1][j] - 0.2;
      horizontal = array[i][j-1] - 0.2;
      array[i][j] = max(diagonal, max(vertical, horizontal));
    }
  }

 for(int i=0; i <m; ++i) {
    for (int j=0; j <n; ++j) {
        if (array[i][j] < 0.1 && array[i][j] > -0.1)
        {
          array[i][j] = 0;
        }
        cout << array[i][j] << "  ";
    }
    cout << endl;
  }
cout << endl;
cout << endl;

  double backtrack[2*max(m,n)];
  char Y1[2*max(m,n)];
  char X1[2*max(m,n)];
  int counter = 0;
  int i = m-1;
  int j = n-1;
  bool finished = false;
  bool idone = false;
  bool jdone = false;
  backtrack[0] = array[i][j];
  while (!finished) {
      if (array[i][j]+0.2 == array[i-1][j]){
        Y1[counter] = Y[i];
        X1[counter] = '-';
        --i;
      }
      else if (array[i][j]+0.2 == array[i][j-1]) {
        Y1[counter] = '-';
        X1[counter] = X[j];
        --j;
        // horizontal
      }
      else if (!jdone || !idone) {
          Y1[counter] = Y[i];
          X1[counter] = X[j];
          --i;
          --j;
        }
      

      if (i==0 && j ==0) {
          finished = true;
      }
      else if (i == 0) {
          idone= true;
      }
      else if (j==0) {
        jdone = true;
      }
      ++counter;
      backtrack[counter] = array[i][j];
  }
  for (int i=0; i <= counter-1; ++i) {
    cout << backtrack[i] << "->";
  }
  cout << backtrack[counter] << endl;
  cout << endl;
  for (int i=counter-1; i >=0; --i) {
    cout << X1[i] << " ";
  }
  cout << endl;
  for (int i=counter-1; i >= 0; --i) {
    cout << Y1[i] << " ";
  }
  return 0;
}
