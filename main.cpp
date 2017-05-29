#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atof */
#include "triangulation.h"
using namespace std;

int main() {
  int m, n;
  double intX, intY;
  string x, y, t;

  cin >> m >> n;
  cout << m << " " << n << endl;

  for (int i = 0; i < m; i++) {
    cin >> x >> y >> t;
    intX = atof(x.c_str());
    intY = atof(y.c_str());

    cout << intX << " " << intY << endl;
  }

  for (int j = 0; j < n; j++) {
    cin >> x >> y >> t;
    intX = atof(x.c_str());
    intY = atof(y.c_str());

    cout << intX << " " << intY << endl;
  }

  return 0;
}