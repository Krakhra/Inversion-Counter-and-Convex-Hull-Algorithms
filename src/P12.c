#include "a2.h"

int divide(int array[],int first, int last){
    int mid;
    mid = (first+last)/2;
    int initial;
    initial = first;
    int midIndex;
    midIndex= mid+1;
    int finalIndex = last - first +1;
    int final[finalIndex];
    int finalInd=0;
    int inversion = 0;
    int i;
    
    while (initial <= mid && midIndex <= last) {
        
        if (array[initial] <= array[midIndex]) {
            final[finalInd] = array[initial];
            finalInd++;
            initial++;
        }
        //count inversions
        else {
            final[finalInd] = array[midIndex];
            finalInd++;
            midIndex++;
            inversion += mid - initial;
        }
    }
    
    //place remaining elements into left array
    while (initial <= mid){
        final[finalInd] = array[initial];
        finalInd++;
        initial++;
    }
    
    //place into right
    while (midIndex <= last){
        final[finalInd] = array[midIndex];
        midIndex++;
        finalInd++;
    }
    
    //put merged items into original
    int temp = last - first + 1;
    for (i=0 ; i<temp ; i++){
        array[i+first] = final[i];
    }
    
    
    return inversion;
    
}

int inversionCountMerge(int array[], int first, int last) {
    //get middle index
    int mid = (first + last)/2;
    int total = 0;
    
    if (first >= last) {
        return 0;
    }
    
    //divide array recursively and start the inversion incrementing, total inversions will be sum of 2 parts and merging
    total = total + inversionCountMerge(array, first, mid);
    total = total + inversionCountMerge(array, mid+1, last);
    total = total + divide(array, first, last);
    
    return total;
}

