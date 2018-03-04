#include "a2.h"
Point hull[100000];
int hullCounter =0;

//function creates a triangle to check which side the line being made is on
int whichSide(Point a, Point b, Point c){
    int val = lineDistance(a,b,c);
    
    if(val > 0){
        return 1;
    }
    else{
        return -1;
    }
}
int lineDistance(Point a, Point b, Point c){
    int val = fabs ((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
    return val;
}
// function to find the squared distance
int distance(Point a, Point b){
    int val = (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
    return val;
}
void quickHull(Vertex *v, int num, Point p1, Point p2,int side){
    int index = -1;
    int maxDistance = 0;
    int i;
    Point temp;
    
    for(i = 0; i < num ; i++) {
        
        temp.x = v->x[i];
        temp.y = v->y[i];
        int dist = lineDistance(p1,p2,temp);
        
        if(whichSide(p1,p2,temp) == side && dist > maxDistance){
            index = i;
            maxDistance = dist;
            hull[hullCounter] = temp;
            hullCounter++;
        }
    }
    
    if(index == -1){
        hull[hullCounter] = p1;
        hullCounter++;
        hull[hullCounter] = p2;
        hullCounter++;
        return;
    }
    temp.x = v->x[index];
    temp.y = v->y[index];
    
    quickHull(v,num,temp, p1, -whichSide(temp,p1,p2));
    quickHull(v,num,temp, p2, -whichSide(temp,p2,p1));
}

void countHull(Vertex *v, int num){
    int minX = 0;
    int maxX = 0;
    int i;
    Point min,max;
    
    if(num < 3){
        return;
    }
    
    //find max and min x indexes
    for(int i=0; i<num; i++){
        if(v->x[i] < v->x[minX]){
            minX = i;
        }
        if(v->x[i] > v->x[maxX]){
            maxX = i;
        }
    }
    
    //assignment points to struct
    min.x = v->x[minX];
    min.y = v->y[minX];
    max.x = v->x[maxX];
    max.y = v->y[maxX];
    
    
    quickHull(v,num,min,max, 1);
    quickHull(v,num,min,max, -1);
    
    printf("Points on convex hull: %d\n",hullCounter);
    
    for(i=0; i<hullCounter; i++) {
        printf("%.2lf %.2lf\n",hull[i].x,hull[i].y);
    }
}

