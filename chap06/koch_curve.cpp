#include<iostream>
#include<cmath>
using namespace std;

struct Point {
  double x, y;
};

void koch(int n, Point a, Point b) {
  if (n==0) {
    return;
  }
  Point s, u, t;
  double theta = M_PI*2.0/3.0;
  s.x = a.x*2.0/3.0 + b.x*1.0/3.0;
  s.y = a.y*2.0/3.0 + b.y*1.0/3.0;
  t.x = a.x*1.0/3.0 + b.x*2.0/3.0;
  t.y = a.y*1.0/3.0 + b.y*2.0/3.0;
  u.x = cos(theta)*(b.x-t.x) - sin(theta)*(b.y-t.y) + t.x;
  u.y = sin(theta)*(b.x-t.x) + cos(theta)*(b.y-t.y) + t.y;

  koch(n-1, a, s);
  cout << s.x << " " << s.y << endl;
  koch(n-1, s, u);
  cout << u.x << " " << u.y << endl;
  koch(n-1, u, t);
  cout << t.x << " " << t.y << endl;
  koch(n-1, t, b);
}

int main() {
  int n;
  Point a, b;
  cin >> n;
  a.x = 0.0;
  a.y = 0.0;
  b.x = 100.0;
  b.y = 0.0;

  cout << a.x << " " << a.y << endl;
  koch(n, a, b);
  cout << b.x << " " << b.y << endl;
  return 0;
}
