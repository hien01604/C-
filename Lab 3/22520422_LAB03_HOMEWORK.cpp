#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

// Structure for points in K-D Tree and Closest Pair
struct Point {
    vector<double> coords;
    Point(double x, double y) : coords({x, y}) {}
};

struct Point2D {
    double x, y;
    Point2D(double x, double y) : x(x), y(y) {}
};

// K-D Tree Node
struct KDNode {
    Point point;
    KDNode *left, *right;
    KDNode(Point p) : point(p), left(nullptr), right(nullptr) {}
};

// Functions for K-D Tree nearest neighbor search
KDNode* buildKDTree(vector<Point>& points, int depth = 0) {
    if (points.empty()) return nullptr;
    int k = points[0].coords.size();
    int axis = depth % k;
    sort(points.begin(), points.end(), [axis](Point a, Point b) { return a.coords[axis] < b.coords[axis]; });
    int median = points.size() / 2;
    Point medianPoint = points[median];
    vector<Point> leftPoints(points.begin(), points.begin() + median);
    vector<Point> rightPoints(points.begin() + median + 1, points.end());
    KDNode *node = new KDNode(medianPoint);
    node->left = buildKDTree(leftPoints, depth + 1);
    node->right = buildKDTree(rightPoints, depth + 1);
    return node;
}

double squaredDistance(const Point& a, const Point& b) {
    double dist = 0;
    for (int i = 0; i < a.coords.size(); i++) {
        dist += pow(a.coords[i] - b.coords[i], 2);
    }
    return dist;
}

void nearestNeighborSearch(KDNode* root, Point target, KDNode*& bestNode, double& bestDist, int depth = 0) {
    if (!root) return;
    double dist = squaredDistance(root->point, target);
    if (dist < bestDist) {
        bestDist = dist;
        bestNode = root;
    }
    int axis = depth % target.coords.size();
    KDNode* nextBranch = (target.coords[axis] < root->point.coords[axis]) ? root->left : root->right;
    KDNode* otherBranch = (nextBranch == root->left) ? root->right : root->left;
    nearestNeighborSearch(nextBranch, target, bestNode, bestDist, depth + 1);
    if (pow(target.coords[axis] - root->point.coords[axis], 2) < bestDist) {
        nearestNeighborSearch(otherBranch, target, bestNode, bestDist, depth + 1);
    }
}

void createKDTreeAndSearch() {
    vector<Point> points = { {1, 2}, {3, 6}, {5, 1}, {9, 6}, {4, 7}, {8, 2} };
    KDNode* root = buildKDTree(points);
    Point target(6, 4);
    KDNode* bestNode = nullptr;
    double bestDist = INFINITY;
    nearestNeighborSearch(root, target, bestNode, bestDist);
    cout << "Nearest Neighbor to (" << target.coords[0] << ", " << target.coords[1] << "): ";
    cout << "(" << bestNode->point.coords[0] << ", " << bestNode->point.coords[1] << ") with distance " << sqrt(bestDist) << endl;
}

// Closest Pair of Points in 2D
double distance(const Point2D& a, const Point2D& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closestPairHelper(vector<Point2D>& pointsX, vector<Point2D>& pointsY) {
    if (pointsX.size() <= 3) {
        double minDist = INFINITY;
        for (size_t i = 0; i < pointsX.size(); ++i)
            for (size_t j = i + 1; j < pointsX.size(); ++j)
                minDist = min(minDist, distance(pointsX[i], pointsX[j]));
        return minDist;
    }
    int mid = pointsX.size() / 2;
    Point2D midPoint = pointsX[mid];
    vector<Point2D> leftX(pointsX.begin(), pointsX.begin() + mid);
    vector<Point2D> rightX(pointsX.begin() + mid, pointsX.end());
    vector<Point2D> leftY, rightY;
    for (const auto& p : pointsY) {
        if (p.x <= midPoint.x) leftY.push_back(p);
        else rightY.push_back(p);
    }
    double dLeft = closestPairHelper(leftX, leftY);
    double dRight = closestPairHelper(rightX, rightY);
    double d = min(dLeft, dRight);
    vector<Point2D> strip;
    for (const auto& p : pointsY)
        if (abs(p.x - midPoint.x) < d)
            strip.push_back(p);
    double minStripDist = d;
    for (size_t i = 0; i < strip.size(); ++i)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j)
            minStripDist = min(minStripDist, distance(strip[i], strip[j]));
    return min(minStripDist, d);
}

double closestPair(vector<Point2D>& points) {
    vector<Point2D> pointsX = points;
    vector<Point2D> pointsY = points;
    sort(pointsX.begin(), pointsX.end(), [](const Point2D& a, const Point2D& b) { return a.x < b.x; });
    sort(pointsY.begin(), pointsY.end(), [](const Point2D& a, const Point2D& b) { return a.y < b.y; });
    return closestPairHelper(pointsX, pointsY);
}

void findClosestPair() {
    vector<Point2D> points = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    double minDist = closestPair(points);
    cout << "Closest Pair Distance: " << minDist << endl;
}

void executeOption(int option) {
    switch (option) {
        case 1:
            createKDTreeAndSearch();
            break;
        case 2:
            findClosestPair();
            break;
        default:
            cout << "Invalid option selected." << endl;
            break;
    }
}

int main() {
    int option;
    cout << "Select an option:\n";
    cout << "1: K-D Tree Nearest Neighbor Search\n";
    cout << "2: Closest Pair of Points in 2D\n";
    cout << "Enter option: ";
    cin >> option;
    executeOption(option);
    return 0;
}
