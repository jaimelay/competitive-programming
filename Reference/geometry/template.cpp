const long double EPS = 1e-9;

typedef int type;

struct Point { 
    type x, y;

    Point() {}
    Point(type x, type y) : x(x), y(y) {}

    Point operator - () { return Point(-x, -y); }
    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }

    Point operator * (type k) { return Point(k * x, k * y); }
    Point operator / (type k) { return Point(x / k, y / k); }

    type operator * (Point p) { return x * p.x + y * p.y; }
    type operator % (Point p) { return x * p.y - y * p.x; }
    type operator ! () { return (*this) * (*this); };
};

// Return -1: a < b, 0: a == b, 1: a > b
int compareFloats(type a, type b) {
  return (a > b + EPS) - (a < b - EPS);
}

double getTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) { 
   return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0); 
} 

bool isInsideTriangle(Point p, Point p1, Point p2, Point p3) {    
   double A = getTriangleArea(p1, p2, p3); 
   double A1 = getTriangleArea(p, p2, p3); 
   double A2 = getTriangleArea(p, p1, p3); 
   double A3 = getTriangleArea(p, p1, p2); 

   return compareFloats(A, A1 + A2 + A3) == 0; 
}

type getTriangleArea(Point p1, Point p2, Point p3) {
  return abs((p2 - p1) % (p3 - p1));
}

bool isInsideTriangle(Point p, Point a, Point b, Point c) {
  type A, A1, A2, A3;

  A =  getTriangleArea(a, b, c);
  A1 = getTriangleArea(p, b, c);
  A2 = getTriangleArea(a, p, c);
  A3 = getTriangleArea(a, b, p);

  return compareFloats(A, A1 + A2 + A3) == 0;
}