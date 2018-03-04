#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct v{
    double x[50000];
    double y[50000];
    int num;
}Vertex;

typedef struct p{
    double x;
    double y;
}Point;

int lineDistance(Point a, Point b, Point c);
int whichSide(Point a, Point b, Point c);
int lineDistance(Point a, Point b, Point c);
int distance(Point a, Point b);
void quickHull(Vertex *v, int num, Point p1, Point p2,int side);
void countHull(Vertex *v, int num);
int winding(Point a, Point b, Point c);
Point leftPoint(Vertex *v,int numPoints);
void run(Vertex *v, int counter);
int divide(int array[],int first, int last);
int inversionCountMerge(int array[], int first, int last) ;
int brute(int c[],int numE);
long timediff(clock_t t1, clock_t t2);

