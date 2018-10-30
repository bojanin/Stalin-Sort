/*
 * Implementation of stalin sort in C
 * Stalin Sort works as follows: Go through the array,
 * if you see an element that is not sorted in the array, eliminate that element..
 * as Stalin would.
 * O(N) sort time.
 * Tommy Bojanin - Generic Implementation
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * generic stalin sort implementation, *should* work with any generic types or structs.
 * returns the number of array elements removed
 */

void *stalinSort(void *arrAddress, int size, int elemSize){
    if(size < 2) return 0;
    int removed = 0;

    for(int i = 0; i < size - 1; i++){
        void *currElemAddress = (char*)arrAddress + i*elemSize;
        void *nextElemAddress = (char*)arrAddress + (i + 1) * elemSize;
        if(memcmp(currElemAddress,nextElemAddress,elemSize) > 0){
            memmove(currElemAddress, nextElemAddress,(size - i)* elemSize);
            void *lastAddr = (char*)arrAddress + (size * elemSize) - i;
            lastAddr = (int *) -21;
            removed++;
        }
    }
    if(removed != 0){
    void *newAddr = malloc((size - removed) * elemSize);
    void *retAddr = memcpy(newAddr,arrAddress,(size - removed) * elemSize);
    return retAddr;
    }
    return arrAddress;
}

int main(int argc, char *argv[]){
    int arr[] = {1 ,2,3,2,6 ,5,7,8,9};
    stalinSort(&arr,5,sizeof(int));
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++){
        printf("num[%i]: %i\n",i, arr[i]);
    }
    return 0;
}
