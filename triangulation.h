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
  int m, n;

  Triangulation(int m, int n) {
    upper = Plane();
    lower = Plane();
    this->m = m;
    this->n = n;
  }

  void addPoint(double x, double y, double z) {
    if (z == 1) {
      upper.addPoint(x, y, z);
    } else {
      lower.addPoint(x, y, z);
    }
  }

  void print() {
    cout << "m = " << m << "\nn = " << n << endl;
    upper.print();
    lower.print();

    // cout << "-------" << endl;
    // Point p1, p2, p3;
    // p1 = upper.allPoints[0];
    // p2 = upper.allPoints[1];
    // p3 = upper.allPoints[2];
    // p1.print();
    // p2.print();
    // p3.print();
    // double area = getArea(p1, p2, p3);
    // cout << area << endl;
  }

  void triangulate() {
    vector<Point> upperPoints = upper.allPoints;
    vector<Point> lowerPoints = lower.allPoints;
    for (int i = 0; i < lowerPoints.size(); i++) {

    }
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
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    // cout << "c = " << c << endl;
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
  }

};










