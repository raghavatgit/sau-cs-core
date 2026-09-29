/*
 * Graham Scan Convex Hull Algorithm
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

static Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2; // 1: clockwise, 2: counterclockwise
}
