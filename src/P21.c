#include "a2.h"

//function for winding order if zero collinear case <0 cw >0 ccw
//needs 3 points to form triangle
int winding(Point a, Point b, Point c){
    int val =  (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    
    if(val == 0){
        return 0;
    }
    else if(val > 0){
        return 1;
    }
    else {
        return 2;
    }
}

//function to find left most point
Point leftPoint(Vertex *v,int numPoints){
    int i=0;
    Point leftM;
    leftM.x = v->x[0];
    leftM.y = v->y[0];
    
    //loop if there is a point that has less x value sub it into variable
    while(i < numPoints){
        if(v->x[i] < leftM.x){
            leftM.y = v->y[i];
            leftM.x = v->x[i];
        }
        //if points x values are equal but new one has highers y
        else if(v->x[i] == leftM.x && v->y[i] < leftM.y){
            leftM.y = v->y[i];
            leftM.x = v->x[i];
        }
        
        i++;
    }
    return leftM;
}

void run(Vertex *v, int counter){
    Point left = leftPoint(v,counter);
    Point hullArray[100000];
    Point end;
    Point hullPoint = left;
    int i=0;
    int j;
    
    //do while point being read is left most eg all points encased
    do{
        hullArray[i] = hullPoint;
        end.x = v->x[0];
        end.y = v->y[0];
        
        for(j=1; j < counter; j++){
            Point temp;
            temp.x = v->x[j];
            temp.y = v->y[j];
            // if winding == 2 that means point creates a line such that it is winding ccw and encases iner points
            if((end.x == hullPoint.x && end.y == hullPoint.y) || winding(hullArray[i], end ,temp ) == 2){
                end.x = v->x[j];
                end.y = v->y[j];
            }
        }
        hullPoint = end;
        i++;
        
    }while(end.x != hullArray[0].x && end.y != hullArray[0].y);
    
    //print
    printf("%d points:\n",i + 1);
    for(j=0;j<i;j++){
        
        printf("(%lf, %lf)\n",hullArray[j].x,hullArray[j].y);
    }
}
