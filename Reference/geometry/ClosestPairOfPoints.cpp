// Complexity: O(n * log(n))
typedef Point2D<double> P;
double closestPairOfPoints(vector<P> pts) {
	auto cmp = [](P a, P b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }; 
	set<P, decltype(cmp)> st(cmp);
	int n = (int)pts.size();

	sort(pts.begin(), pts.end(), [](P a, P b) { return a.x != b.x ? a.x < b.x : a.y < b.y; });

	double min_dist = DBL_MAX;

	for (int i = 1; i < n; i++) {
		min_dist = min(min_dist, (pts[i] - pts[i - 1]).dist());
	}

	st.insert(pts[0]);
	st.insert(pts[1]);

	for (int i = 2, j = 0; i < n; i++) {
		while (pts[j].x < pts[i].x - min_dist) {
			st.erase(pts[j++]);
		}

		for (auto pt : st) {
			if (abs(pt.y - pts[i].y) <= min_dist) {
				min_dist = min(min_dist, (pt - pts[i]).dist());
			}
		}

		st.insert(pts[i]);
	}

	return min_dist;
}