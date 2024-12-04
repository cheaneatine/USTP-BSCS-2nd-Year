#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a point in 2D plane
struct Point
{
    int x, y;
};

// Function to find the orientation of three points (p, q, r)
// Returns:
// 0 if p, q, r are collinear
// 1 if clockwise
// 2 if counterclockwise
int orientation(const Point &p, const Point &q, const Point &r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to find the convex hull using Divide-and-Conquer
void convexHullUtil(vector<Point> &points, int left, int right, vector<Point> &hull)
{
    if (right - left + 1 <= 3)
    {
        for (int i = left; i <= right; ++i)
            hull.push_back(points[i]);
        return;
    }

    // Find the mid point
    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    // Recursively find the convex hull for the left and right halves
    vector<Point> leftHull, rightHull;
    convexHullUtil(points, left, mid, leftHull);
    convexHullUtil(points, mid + 1, right, rightHull);

    // Merge the convex hulls of left and right halves
    int leftmost = 0, rightmost = 0;
    for (int i = 0; i < leftHull.size(); ++i)
    {
        if (leftHull[i].x < leftHull[leftmost].x)
            leftmost = i;
    }
    for (int i = 0; i < rightHull.size(); ++i)
    {
        if (rightHull[i].x > rightHull[rightmost].x)
            rightmost = i;
    }

    int upperTangentLeft = leftmost, upperTangentRight = rightmost;
    int lowerTangentLeft = leftmost, lowerTangentRight = rightmost;
    bool upperTangentFound = false, lowerTangentFound = false;
    while (!upperTangentFound || !lowerTangentFound)
    {
        upperTangentFound = true;
        while (orientation(rightHull[upperTangentRight], leftHull[upperTangentLeft], leftHull[(upperTangentLeft + 1) % leftHull.size()]) != 2)
        {
            upperTangentLeft = (upperTangentLeft + 1) % leftHull.size();
        }

        lowerTangentFound = true;
        while (orientation(leftHull[lowerTangentLeft], rightHull[lowerTangentRight], rightHull[(rightHull.size() + lowerTangentRight - 1) % rightHull.size()]) != 2)
        {
            lowerTangentRight = (rightHull.size() + lowerTangentRight - 1) % rightHull.size();
        }
    }

    // Merge the upper and lower tangents to form the convex hull
    for (int i = upperTangentLeft; i != lowerTangentLeft; i = (i + 1) % leftHull.size())
        hull.push_back(leftHull[i]);
    hull.push_back(leftHull[lowerTangentLeft]);

    for (int i = lowerTangentRight; i != upperTangentRight; i = (i + 1) % rightHull.size())
        hull.push_back(rightHull[i]);
    hull.push_back(rightHull[upperTangentRight]);
}

// Function to find the convex hull
vector<Point> convexHull(vector<Point> &points)
{
    vector<Point> hull;
    if (points.size() < 3)
        return hull;

    // Sort the points based on their x-coordinates
    sort(points.begin(), points.end(), [](const Point &p1, const Point &p2)
         { return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y); });

    // Find the convex hull using Divide-and-Conquer
    convexHullUtil(points, 0, points.size() - 1, hull);

    return hull;
}

int main()
{
    vector<Point> points = {{1, 1}, {4, 6}, {8, 2}, {5, 4}, {2, 3}};

    cout << "Given points: [";
    for (int i = 0; i < points.size(); ++i)
    {
        cout << "(" << points[i].x << ", " << points[i].y << ")";
        if (i != points.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    vector<Point> hull = convexHull(points);

    cout << "Convex Hull: [";
    for (int i = 0; i < hull.size(); ++i)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")";
        if (i != hull.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

/*

Best Case: O(n log n) - When the points are already sorted by x-coordinate,
which minimizes the time taken in sorting and finding the convex hulls.

Average Case: O(n log n) - Same as the best case.

Worst Case: O(n log n) - This is the complexity of the divide-and-conquer algorithm,
which is dominated by sorting. However, the actual running time may vary depending on
the distribution of points.

*/