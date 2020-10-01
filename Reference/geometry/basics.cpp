// returns -1 for negative numbers, 0 for zero, and 1 for positive numbers.
template <class T> int sgn(T x) {
	return (T(0) < x) - (x < T(0));
}

template <class T> struct Point2D { 
	T x, y;

	Point2D(T x = 0, T y = 0) : x(x), y(y) {}

	bool operator < (Point2D p) { return tie(x,y) < tie(p.x, p.y); }
	bool operator == (Point2D p) { return tie(x,y) == tie(p.x, p.y); }
	bool operator != (Point2D p) { return !(tie(x,y) == tie(p.x, p.y)); }
	Point2D operator - (Point2D p) { return Point2D(x - p.x, y - p.y); }
	Point2D operator + (Point2D p) { return Point2D(x + p.x, y + p.y); }
	Point2D operator * (T k) { return Point2D(k * x, k * y); }
	Point2D operator / (T k) { return Point2D(x / k, y / k); }

	T dot(Point2D p) { return x * p.x + y * p.y; }
	T cross(Point2D p) { return x * p.y - y * p.x; }
	T cross(Point2D a, Point2D b) const { return (a - *this).cross(b - *this); }
	T dist2() const { return x * x + y * y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); } // angle to x-axis in interval [-pi, pi]
	Point2D unit() const { return *this / dist(); } // makes dist()=1
	Point2D perp() const { return Point2D(-y, x); } // rotates +90 degrees
	Point2D normal() const { return perp().unit(); }

	// Returns point rotated 'a' radians ccw around the origin
	Point2D rotate(double a) const {
		return Point2D(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}

	double distanceToPoint(Point2D b) {
		return sqrt(((x - b.x) * (x - b.x)) + ((y - b.y) * (y - b.y)));
	}
	
	// Returns true if this point lies on the line segment from point 's' to point'e'
	// Use (distanceToSegment(s, e) <= EPS) instead when using Point2D<double>.
	bool onSegment(Point2D s, Point2D e) {
		return (*this).cross(s, e) == 0 && (s - *this).dot(e - *this) <= 0;
	}

	// Returns the shortest distance between this point and the line segment from point s to e.
	double distanceToSegment(Point2D &s, Point2D &e) {
		if (s == e) {
			return ((*this) - s).dist();
		}

		auto d = (e - s).dist2();
		auto t = min(d, max(.0,((*this) - s).dot(e - s)));
		
		return (((*this) - s) * d - (e - s) * t).dist() / d;
	}

	// Returns the signed perpendicular distance between point p and the line containing points a and b.
	// Positive value on left side and negative on right as seen from a towards b. a==b gives nan.
	double distanceToLine(Point2D &a, Point2D &b) {
		return (double)(b - a).cross((*this) - a) / (b - a).dist();
	}

	// Returns true if p lies within the polygon. 
	// If strict is true, it returns false for points on the boundary.
	// The algorithm uses products in intermediate steps so watch out for overflow.
	bool isInsidePolygon(vector<Point2D> &polygon, bool strict = true) {
		int cnt = 0, n = int(polygon.size());

		for (int i = 0; i < n; i++) {
			Point2D q = polygon[(i + 1) % n];

			if (onSegment(polygon[i], q)) {
				return !strict;
			}
			//or: if (distanceToSegment(polygon[i], q) <= EPS) return !strict;
			cnt ^= (((*this).y < polygon[i].y) - ((*this).y < q.y)) * (*this).cross(polygon[i], q) > 0;
		}

		return cnt;
	}

	// Returns where p is as seen from s towards e. (1/0/-1) ⇔ left/on line/right.
	// If the optional argument eps is given 0 is returned if p is within distance eps from the line.
	int sideOf(Point2D s, Point2D e) { 
		return sgn(s.cross(e, (*this)));
	}

	int sideOf(Point2D &s, Point2D &e, double eps) {
		auto a = (e - s).cross((*this) - s);
		double l = (e - s).dist() * eps;

		return (a > l) - (a < -l);
	}

	friend ostream& operator << (ostream& os, Point2D p) {
		return os << "(" << p.x << "," << p.y << ")"; 
	}
};

//The circumcirle of a triangle is the circle intersecting all three vertices.
// ccRadius returns the radius of the circle going through points A, B and C.
double ccRadius(Point2D<double> &A, Point2D<double> &B, Point2D<double> &C) {
	return (B - A).dist() * (C - B).dist() * (A - C).dist() / abs((B - A).cross(C - A)) / 2;
}

// ccCenter returns the center of the same circle
Point2D<double> ccCenter(Point2D<double> &A, Point2D<double> &B, Point2D<double> &C) {
	Point2D<double> b = C - A, c = B - A;
	assert(b.cross(c) != 0); // no circumcircle if A,B,C aligned
	return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}

// returns true if is collinear or false otherwise
bool collinear(Point2D<double> p1, Point2D<double> p2, Point2D<double> p3) { 
    return ((p2.x - p1.x) * (p3.y - p2.y)) == ((p2.y - p1.y) * (p3.x - p2.x));
}

// Return -1: a < b, 0: a == b, 1: a > b
int compareFloats(double a, double b, double eps = EPS) {
	return (a > b + eps) - (a < b - eps);
}
