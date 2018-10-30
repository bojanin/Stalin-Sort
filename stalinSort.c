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

int intcmp(void *elem1, void *elem2){
    int *int1 = elem1;
    int *int2 = elem2;
    return *int1 - *int2;
}

/*
 * generic stalin sort implementation, *should* work with any generic types or structs.
 * returns the number of array elements removed
 */

void *stalinSort(void *arrAddress, int size, int elemSize, int (*cmpfn)(void*,void*)){
    if(size < 2) return 0;
    int removed = 0;
    int removedSize = size;
    for(int i = 0; i < removedSize - 1; i++){
        void *currElemAddress = (char*)arrAddress + i*elemSize;
        void *nextElemAddress = (char*)arrAddress + (i + 1) * elemSize;
        if(cmpfn(currElemAddress,nextElemAddress) > 0){
            memmove(currElemAddress, nextElemAddress,(size - i)* elemSize);
            removed++;
            removedSize--;
        }
    }
    if(removed != 0){
    void *newAddr = malloc(removedSize * elemSize);
    memcpy(newAddr,arrAddress,removedSize * elemSize);
    arrAddress = newAddr;
    }
    return arrAddress;
}

int main(int argc, char *argv[]){
    int arr[] = {1 ,2,3,2,6 ,5,7,8,9};
    stalinSort(&arr,9,sizeof(int), intcmp);
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++){
        printf("num[%i]: %i\n",i, arr[i]);
    }
    return 0;
}
