#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cerr << endl << "DEBUG: (" << (#x) << " = " << x << ")" << endl;
#define dbgArray(v) for (auto i : v) cerr << i << " "; cerr << endl;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);

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

	// Returns true if this point lies on the line segment from point 's' to point'e'
	bool onSegment(Point2D s, Point2D e) {
		return (*this).cross(s, e) == 0 && (s - *this).dot(e - *this) <= 0;
	}

    // Returns the shortest distance between this point and the line segment from point s to e.
    double distanceToLineSegment(Point2D &s, Point2D &e) {
        if (s == e) {
            return ((*this) - s).dist();
        }

        auto d = (e - s).dist2(), t = min(d, max(.0,((*this) - s).dot(e - s)));
        return (((*this) - s) * d - (e - s) * t).dist() / d;
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
            //or: if (distanceToLineSegment(p[i], q) <= EPS) return !strict;
            cnt ^= (((*this).y < polygon[i].y) - ((*this).y < q.y)) * (*this).cross(polygon[i], q) > 0;
        }

        return cnt;
    }

	friend ostream& operator << (ostream& os, Point2D p) {
		return os << "(" << p.x << "," << p.y << ")"; 
	}
};

// Return -1: a < b, 0: a == b, 1: a > b
int compareFloats(double a, double b, double eps = EPS) {
	return (a > b + eps) - (a < b - eps);
}

const int MAXN = 10010;

struct Edge {
    int to;
    int flow;
    int cap;
    int rev;
    int id;

    Edge(int to, int flow, int cap, int rev, int id = -1) :
        to(to), flow(flow), cap(cap), rev(rev), id(id) {}
};

vector<Edge> g[MAXN];
int dist[MAXN], ptr[MAXN];

void addEdge(int from, int to, int cap, int id = 0) {
    g[from].push_back(Edge(to, 0, cap, g[to].size(), id));
    g[to].push_back(Edge(from, 0, 0, g[from].size() - 1, -id));
}

bool dinicBFS(int s, int t) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (Edge e : g[u]) {
            int v = e.to;

            if (dist[v] < 0 && e.flow < e.cap) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist[t] >= 0;
}

int dinicDFS(int s, int t, int flow) {
    if (s == t) {
        return flow;
    }

    for (int &i = ptr[s]; i < int(g[s].size()); i++) {
        Edge &e = g[s][i];

        if (e.cap > e.flow) {
            int v = e.to;

            if (dist[v] == dist[s] + 1) {
                int tmp_flow = dinicDFS(v, t, min(flow, e.cap - e.flow));

                if (tmp_flow > 0) {
                    e.flow += tmp_flow;
                    g[v][e.rev].flow -= tmp_flow;

                    return tmp_flow;
                }
            }
        }
    }

    return 0;
}

int dinic(int s, int t) {
    int max_flow = 0;

    while (dinicBFS(s, t)) {
        memset(ptr, 0, sizeof(ptr));

        while (int flow = dinicDFS(s, t, INF)) {
            max_flow += flow;
        }
    }

    return max_flow;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        memset(g, 0, sizeof(g));

        vector<Point2D<long long>> polygon;
        set<int> st_x, st_y;

        for (int i = 0, x, y; i < n; i++) {
            cin >> x >> y;
            polygon.push_back(Point2D<long long>(x, y));
            st_x.insert(x);
            st_y.insert(y);
        }

        vector<Point2D<long long>> judges;

        for (auto x : st_x) {
            for (auto y : st_y) {
                judges.push_back(Point2D<long long>(x, y));
            }
        }
        
        set<int> tmp1, tmp2;
        map<int, int> mp;
        int cnt = 0;

        for (int i = 0; i < int(judges.size()); i++) {
            if (!judges[i].isInsidePolygon(polygon, false)) {
                int u = judges[i].x;
                int v = judges[i].y;
                if (!mp[u]) mp[u] = ++cnt;
                if (!mp[v]) mp[v] = ++cnt;

                tmp1.insert(mp[u]);
                tmp2.insert(mp[v]);
                addEdge(mp[u], mp[v], 1);
            }
        }

        int s = 0, t = cnt + 5;

        for (auto x : tmp1) addEdge(s, x, 1);
        for (auto x : tmp2) addEdge(x, t, 1);

        int mx_flow = dinic(s, t);
        // int mx_flow = 0;
        cout << int(st_x.size()) + int(st_y.size()) - mx_flow << endl;
    }
    cout << endl;

    return 0;
}