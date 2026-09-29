#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point2D;

int orientation(Point2D p, Point2D q, Point2D r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock
}
