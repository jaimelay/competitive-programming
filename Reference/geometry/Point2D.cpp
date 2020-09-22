// returns -1 for negative numbers, 0 for zero, and 1 for positive numbers.
template <class T> int sgn(T x) {
	return (T(0) < x) - (x < T(0));
}

template <class T> struct Point2D { 
	typedef Point2D P;
	T x, y;

	P(T x = 0, T y = 0) : x(x), y(y) {}

	bool operator < (P p) { return tie(x,y) < tie(p.x, p.y); }
	bool operator == (P p) { return tie(x,y) == tie(p.x, p.y); }
	bool operator != (P p) { return !(tie(x,y) == tie(p.x, p.y)); }
	P operator - (P p) { return P(x - p.x, y - p.y); }
	P operator + (P p) { return P(x + p.x, y + p.y); }
	P operator * (T k) { return P(k * x, k * y); }
	P operator / (T k) { return P(x / k, y / k); }

	T dot(P p) { return x * p.x + y * p.y; }
	T cross(P p) { return x * p.y - y * p.x; }
	T cross(P a, P b) const { return (a - *this).cross(b - *this); }
	T dist2() const { return x * x + y * y; }
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); } // angle to x-axis in interval [-pi, pi]
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }

	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}

	// Returns true if this point lies on the line segment from point 's' to point'e'
	bool onSegment(P s, P e) {
		return (*this).cross(s, e) == 0 && (s - *this).dot(e - *this) <= 0;
	}

	friend ostream& operator << (ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; 
	}
};

// Return -1: a < b, 0: a == b, 1: a > b
int compareFloats(double a, double b, double eps = EPS) {
	return (a > b + eps) - (a < b - eps);
}