#include "a2.h"

int main(int argc, char **argv){
    
    if(argc <= 1){
        printf("File Error\n");
        return 0;
    }
    FILE *f =  fopen(argv[1],"r");
    int a;
    int z=0;
    int counter[100000];
    clock_t t1 ,t2;
    long elapsedT;
    Vertex *v = malloc(sizeof(Vertex));
    
    if(f){
        while(fscanf(f,"%d",&a) != EOF){
            counter[z] = a;
            z++;
        }
        int numInver;
        t1 = clock();
        numInver = brute(counter,z);
        t2 = clock();
        elapsedT = timediff(t1,t2);
        printf("Brute force time elapsed: %ld ms\n",elapsedT);
        printf("Number of Inversions: %d\n\n\n",numInver);
        t1=clock();
        inversionCountMerge(counter,0,z);
        t2 = clock();
        elapsedT = timediff(t1,t2);
        printf("Divide and Conquer time elapsed: %ld ms\n",elapsedT);
        printf("Number of Inversions: %d\n\n\n",numInver);
    }

    fclose(f);
    FILE *f2 = fopen(argv[2],"r");
    int k=0;
    if(f2){
        double x,y;

        while(fscanf(f2,"%lf %lf",&x, &y) != EOF){
            v->x[k] = x;
            v->y[k] = y;
            k++;
        }
    }else{
        return 0;
    }
    t1 = clock();
    //run(v,k);
    Point left = leftPoint(v,k);
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
        
        for(j=1; j < k; j++){
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
    
    t2 = clock();
    elapsedT = timediff(t1,t2);
    printf("Brute force time elapsed: %ld ms\n\n\n",elapsedT);
    t1= clock();
    countHull(v,k);
    t2=clock();
    elapsedT = timediff(t1,t2);
    printf("Divide and Conquer time elapsed: %ld ms\n",elapsedT);
    fclose(f2);
    return 0;
}
