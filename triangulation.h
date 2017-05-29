#include <string>
#include <stdlib.h>     /* atof */
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  double x, y, z;
  Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }

  Point(double x, double y, double z) {
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

  void addPoint(double x, double y, double z) {
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

  void addPoint(double x, double y, double z) {
    if (z == 1) {
      upper.addPoint(x, y, z);
    } else {
      lower.addPoint(x, y, z);
    }
  }

  void print() {
    upper.print();
    lower.print();

    cout << "-------" << endl;
    Point p1, p2, p3;
    p1 = upper.allPoints[0];
    p2 = upper.allPoints[1];
    p3 = lower.allPoints[0];
    p1.print();
    p2.print();
    p3.print();
    double area = getArea(p1, p2, p3);
    cout << area << endl;
  }

  double getDistance(Point p1, Point p2) {
    double d1 = abs(p1.x - p2.x);
    double d2 = abs(p1.y - p2.y);
    double d3 = abs(p1.z - p2.z);
    return sqrt((d1 * d1) + (d2 * d2) + (d3 * d3));
  }

  double getArea(Point p1, Point p2, Point p3) {
    double a = getDistance(p1, p2);
    double b = getDistance(p2, p3);
    double c = getDistance(p1, p3);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }

};










