#include <string>
#include <stdlib.h>     /* atof */
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  float x, y, z;
  Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }

  Point(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void print() {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
  }
};

struct Plane {
  vector<Point> allPoints;

  Plane() {
  }

  void addPoint(float x, float y, float z) {
    allPoints.push_back(Point(x, y, z));
  }

  void print() {
    for (int i = 0; i < allPoints.size(); i++) {
      allPoints[i].print();
    }
  }
};

class Triangulation {
public:
  Plane upper, lower;

  Triangulation() {
    upper = Plane();
    lower = Plane();
  }

  void addPoint(float x, float y, float z) {
    if (z == 1) {
      upper.addPoint(x, y, z);
    } else {
      lower.addPoint(x, y, z);
    }
  }

  void print() {
    upper.print();
    lower.print();
  }

};









