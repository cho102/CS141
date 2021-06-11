#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int weights[] = {0,6,6,9,9, 15, 15};
  int cost[] = {0,9,9, 12, 12, 18, 18};

  int array[7][40];
  for (int i = 0; i < 40; ++i) {
    array[0][i] = 0;
  }
  // for (int i = 0; i < 40; ++i) {
  //   cout << array[0][i] << " ";
  // }
  // cout << endl << endl;

  for (int i = 1; i < 7; ++i) {
    for (int j=0; j < 40; ++j) {
      if (weights[i] > j) {
        array[i][j] = array[i-1][j];
      }
      else {
        array[i][j] = max(cost[i]+array[i-1][j-weights[i]], array[i-1][j]);
      }
    }
  }

  // for (int i = 0; i < 7; ++i) {
  //   for (int j=0; j < 40; ++j) {
  //     cout << array[i][j] << "  ";
  //   }
  //   cout << endl;
//   // }
// cout << endl<<endl;
char c = 'a' + 5;
cout << c << endl;
  char count = 'f';
  int counter = 0;
  char items[7];
  int j = 39;
  for (int i = 6; i > 0 ; --i) {
    if (array[i][j] > array[i-1][j]) {
      items[counter] = count;
      ++counter;
      j = j-weights[i];
    }
    --count;
  }
  cout << endl << "Items: ";

  for (int i = 0; i < 7; ++i) {
    cout << items[i] << " ";
  }

return 0;
}
