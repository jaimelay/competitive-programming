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