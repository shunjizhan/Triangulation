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

  Plane() {}

  void addPoint(double x, double y, double z) {
    allPoints.push_back(Point(x, y, z));
  }

  void print() {
    for (int i = 0; i < allPoints.size(); i++) {
      allPoints[i].print();
    }
  }
};

struct ToroidalDot {
  double right, down, minDistance;

  ToroidalDot() {
    right = -1;
    down = -1;
    minDistance = -1;
  }

  ToroidalDot(double r, double d) {
    right = r;
    down = d;
    minDistance = -1;
  }

  void print() {
    cout << "right = " << right << ", down = " << down << ", minDistance = " << minDistance << endl;
  }
};

class Triangulation {
public:
  int m, n;
  Plane upper, lower;

  Triangulation(int m, int n) {
    this->m = m;
    this->n = n;
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
    // cout << "m = " << m << "\nn = " << n << endl;
    // upper.print();
    // lower.print();

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
    upperPoints.push_back(upperPoints[0]);
    lowerPoints.push_back(lowerPoints[0]);

    // cout << upperPoints.size() << " " << lowerPoints.size() << endl;

    ToroidalDot toroidal[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        double right = getArea(upperPoints[i], lowerPoints[j], lowerPoints[j + 1]);
        double down = getArea(upperPoints[i], lowerPoints[j], upperPoints[i + 1]);
        // cout << right << " " << down << endl;
        toroidal[i][j] = ToroidalDot(right, down);
      }
    }

    for (int i = 0; i <= m ; i++) {
      toroidal[i][n].right = -1;
    }

    for (int j = 0; j <= m ; j++) {
      toroidal[m][j].down = -1;
    }

    int i = 0;
    int j = 0;
    int k = 0;
    toroidal[0][0].minDistance = 0;
    while(i <= m * 2 || j <= n * 2) {
      k++;
      i++;
      j++;
      for (int x = 0; x <= k; x++) {
        if (x <= m && (k - x) <= n) {       // dot in toroidal
          ToroidalDot left, top;
          double fromLeft, fromTop;

          if (x == 0) {                     // leftmost colume
            left = toroidal[x][k - x - 1];
            fromLeft = left.minDistance + left.right;
            toroidal[x][k - x].minDistance = fromLeft;
          } else if ((k - x) == 0) {        // top row
            left = toroidal[x - 1][k - x];
            fromTop = top.minDistance + top.down;
            toroidal[x][k - x].minDistance = fromLeft;
          } else {                          // other dots
            top = toroidal[x - 1][k - x];
            left = toroidal[x][k - x - 1];
            fromTop = top.minDistance + top.down;
            fromLeft = left.minDistance + left.right;
            if (fromTop < fromLeft) {       // left has priority
              toroidal[x][k - x].minDistance = fromTop;
            } else {
              toroidal[x][k - x].minDistance = fromLeft;
            }
          }
        }
      }
    }

    i = m;
    j = n;
    while(!(i == 0 && j == 0)) {
      cout << (i % m) + 1 << " " << (j % n) + m + 1<< " ";
      if (i == 0) {
        j--;
        cout << (j % n) + m + 1 << endl;
      } else if (j == 0) {
        i--;
        cout << (i % m) + 1<< endl;
      } else {
        ToroidalDot current = toroidal[i][j];
        ToroidalDot left = toroidal[i][j - 1];
        ToroidalDot top = toroidal[i - 1][j];
        if (abs(left.minDistance + left.right - current.minDistance) < abs(top.minDistance + top.down - current.minDistance)) {
          j--;
          cout << (j % n) + m + 1 << endl;
        } else {
          i--;
          cout << (i % m) + 1 << endl;
        }
      }
    }


    // for (int i = 0; i <= m; i++) {
    //   for (int j = 0; j <= n; j++) {
    //     toroidal[i][j].print();
    //   }
    // }

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










