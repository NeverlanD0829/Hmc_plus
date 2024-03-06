#include <iostream>
#include <cmath>

class Point {
public:
    double x, y;

    Point(double _x, double _y) : x(_x), y(_y) {}
};

class Line {
public:
    double A, B, C;
    // 通过两点坐标确定直线
    Line(const Point& p1, const Point& p2) {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = p1.y * (p2.x - p1.x) + p1.x * (p1.y - p2.y);
    }
    // 判断点是否在直线上
    bool isPointOnLine(const Point& p) const {
        return std::fabs(A * p.x + B * p.y + C) < 1e-9;
    }
};

int main() {
    // 两点坐标
    Point p1(1.0, 2.0);
    Point p2(3.0, 4.0);
    // 创建直线
    Line line(p1, p2);
    // 判断另一点是否在直线上
    Point testPoint(2.0, 3.0);
    if (line.isPointOnLine(testPoint)) {
        std::cout << "点在直线上" << std::endl;
    } else {
        std::cout << "点不在直线上" << std::endl;
    }
    return 0;
}
