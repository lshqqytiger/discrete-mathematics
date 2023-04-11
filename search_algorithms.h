#include <string.h>
#ifndef length
#define length 0
#endif

#define Binary "binary"

int binary_search(int* arr, int target){
    int i = 0;
    int j = length;
    int m;
    while(j - i > 1){
        m = (i + j) / 2;
        if(target > arr[m]) i = m + 1;
        else j = m;
        printf("Now search [%d, %d]. Mid Point: %d\n", i, j, m);
    }
    return target == arr[i] ? i : -1;
}

void fallback(int* arr){
    printf("Cannot find algorithm.\n");
}

void* find_algorithm(char* n){
    if(!strcmp(n, Binary)) return &binary_search;
    return &fallback;
}