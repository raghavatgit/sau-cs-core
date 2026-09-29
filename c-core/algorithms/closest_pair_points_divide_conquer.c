#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct { float x, y; } Point;
float dist(Point p1, Point p2) { return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); }
