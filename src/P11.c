#include <time.h>
long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

int brute(int c[],int numE){
    int i=0;
    int j=0;
    int inverCounter =0;
    
    //will compare the pivot element with the elements to its right
    for(i = 0; i < numE - 1; i++){
        for(j = i + 1; j< numE; j++){
            if(c[i] > c[j] && i < j){
                inverCounter++;
            }
        }
    }
    
    return inverCounter;
}
