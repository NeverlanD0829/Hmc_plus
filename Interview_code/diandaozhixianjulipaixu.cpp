#include <vector>
#include <cmath>

struct Point2d
{
    double x;
    double y;
};
// 辅助函数：计算点到直线的距离
double distanceToLine(const Point2d& linePoint1, const Point2d& linePoint2, const Point2d& point)
{
    double numerator = std::abs((linePoint2.y - linePoint1.y) * point.x - (linePoint2.x - linePoint1.x) * point.y + linePoint2.x * linePoint1.y - linePoint2.y * linePoint1.x);
    double denominator = std::sqrt(std::pow(linePoint2.y - linePoint1.y, 2) + std::pow(linePoint2.x - linePoint1.x, 2));
    
    return numerator / denominator;
}
// 排序函数
bool reorderPoints(const std::vector<Point2d>& two_point_line, std::vector<Point2d>& points)
{
    if (two_point_line.size() != 2)
    {
        // 直线由两个点定义
        return false;
    }
    // 提取直线上的两个点
    Point2d linePoint1 = two_point_line[0];
    Point2d linePoint2 = two_point_line[1];
    // 使用 lambda 函数作为排序的比较函数，按照点到直线的距离升序排序
    auto compareDistanceToLine = [&](const Point2d& point1, const Point2d& point2)
    {
        return distanceToLine(linePoint1, linePoint2, point1) < distanceToLine(linePoint1, linePoint2, point2);
    };
    // 对点集合进行排序
    std::sort(points.begin(), points.end(), compareDistanceToLine);
    return true;
}
