typedef Point2D<double> Points;
double areaPolygon(vector<Points> polygon) {
    double area = 0.0;

    for (int i = 0, n = polygon.size(); i < n; i++) {
        area += polygon[i].cross(polygon[(i + 1) % n]);
    }

    return abs(area) / 2.0;
}