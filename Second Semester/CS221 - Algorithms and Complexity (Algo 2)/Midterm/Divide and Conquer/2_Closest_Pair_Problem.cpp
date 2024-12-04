#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

// Structure to represent a point in 2D plane
struct Point
{
    int x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to compare points based on their x-coordinates
bool compareX(const Point &p1, const Point &p2)
{
    return p1.x < p2.x;
}

// Function to compare points based on their y-coordinates
bool compareY(const Point &p1, const Point &p2)
{
    return p1.y < p2.y;
}

// Function to find the minimum distance between two points in a strip
double stripClosest(vector<Point> &strip, double d)
{
    double min_dist = d;

    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i)
    {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; ++j)
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < min_dist)
                min_dist = dist;
        }
    }

    return min_dist;
}

// Function to find the minimum distance between two points using Divide and Conquer
double closestPairUtil(vector<Point> &points, size_t left, size_t right)
{
    if (right - left <= 3)
    {
        double min_dist = numeric_limits<double>::max();
        for (size_t i = left; i < right; ++i)
        {
            for (size_t j = i + 1; j < right; ++j)
            {
                double dist = distance(points[i], points[j]);
                if (dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }

    size_t mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    double dl = closestPairUtil(points, left, mid);
    double dr = closestPairUtil(points, mid + 1, right);

    double d = min(dl, dr);

    vector<Point> strip;
    for (size_t i = left; i < right; ++i)
    {
        if (abs(points[i].x - midPoint.x) < d)
            strip.push_back(points[i]);
    }

    return min(d, stripClosest(strip, d));
}

// Function to find the closest pair of points
double closestPair(vector<Point> &points)
{
    sort(points.begin(), points.end(), compareX);
    return closestPairUtil(points, 0, points.size());
}

int main()
{
    vector<Point> points = {{2, 3}, {12, 30}, {4, 1}, {7, 16}, {5, 5}};

    cout << "Given points: ";
    for (const auto &point : points)
        cout << "(" << point.x << ", " << point.y << ") ";
    cout << endl;

    double min_dist = closestPair(points);

    cout << "Closest pair: ";
    // Printing points with minimum distance
    for (size_t i = 0; i < points.size(); ++i)
    {
        for (size_t j = i + 1; j < points.size(); ++j)
        {
            if (distance(points[i], points[j]) == min_dist)
                cout << "(" << points[i].x << ", " << points[i].y << ") and ("
                     << points[j].x << ", " << points[j].y << ") with distance = " << min_dist << endl;
        }
    }

    return 0;
}

/*

Best Case: O(n log n) - When the points are already sorted by
x-coordinate, which minimizes the time taken in sorting.

Average Case: O(n log n) - Same as the best case.

Worst Case: O(n log n) - This is the complexity of the divide-and-conquer
algorithm. However, the actual running time may vary depending on the number of points and their distribution in the plane.

*/