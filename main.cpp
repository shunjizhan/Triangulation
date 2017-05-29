#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atof */
#include "triangulation.h"
using namespace std;

int main() {
  int m, n;
  double X, Y, Z;
  string x, y, z;
  Triangulation t;

  cin >> m >> n;
  cout << m << " " << n << endl;

  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    X = atof(x.c_str());
    Y = atof(y.c_str());
    Z = atof(z.c_str());

    cout << X << " " << Y << " " << Z << endl;
    t.addPoint(X, Y, Z);
  }

  for (int j = 0; j < n; j++) {
    cin >> x >> y >> z;
    X = atof(x.c_str());
    Y = atof(y.c_str());
    Z = atof(z.c_str());

    cout << X << " " << Y << " " << Z << endl;
    t.addPoint(X, Y, Z);
  }

  t.print();

  return 0;
}