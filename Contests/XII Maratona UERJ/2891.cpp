#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

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

// returns true if is collinear or false otherwise
bool collinear(Point2D<double> p1, Point2D<double> p2, Point2D<double> p3) { 
    return ((p2.x - p1.x) * (p3.y - p2.y)) == ((p2.y - p1.y) * (p3.x - p2.x));
}

// Complexity: O (n * log(n))
// Returns a vector of indices of the convex hull in counterclockwise order.
// Points on the edge of the hull between two other points are not considered part of the hull.
// If you want to also include points which are on the edges of the convex hull, change the `<=` to `<` in cross product.
typedef Point2D<double> P;
vector<P> ConvexHull(vector<P> pts) {
    sort(pts.begin(), pts.end());
    vector<P> h;

    for (int step = 1; step <= 2; step++) {
        int start = (int)h.size();

        for (auto p : pts) {
            while ((int)h.size() >= start + 2 && h[(int)h.size() - 2].cross(h[(int)h.size() - 1], p) <= 0) {
                h.pop_back();
            }

            h.push_back(p);
        }

        h.pop_back();
        reverse(pts.begin(), pts.end());
    }

    return h;
}

typedef Point2D<double> Points;
double areaPolygon(vector<Points> polygon) {
    double area = 0.0;
	int n = (int)polygon.size();

    for (int i = 0; i < n; i++) {
        area += polygon[i].cross(polygon[(i + 1) % n]);
    }

    return abs(area) / 2.0;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while (true) {
		bool flag = false;
		vector<Point2D<double>> v;

		for (int i = 0, a, b; i < 5; i++) {
			cin >> a >> b;
			
			v.push_back(Point2D<double>(a, b));

			if (a != 0 || b != 0) {
				flag = true;
			}
		}

		if (!flag) {
			break;
		}

		int n = (int)v.size();
		double ans = 0.0;

		for (int i = 0; i < n; i++) {
			vector<Point2D<double>> pts;
			
			pts.push_back(v[i]);

			int cnt = 0, j = (i + 1) % n;
	
			while (cnt < 3) {
				pts.push_back(v[j]);
				j = (j + 1) % n;
				cnt++;
			}

			vector<Point2D<double>> quadrilateral = ConvexHull(pts);

			if (quadrilateral.size() < 4) {
				continue;
			}
			
			double area = areaPolygon(quadrilateral);
			ans = max(ans, area);
		}

		cout << ans << endl;
	}

    return 0;
}