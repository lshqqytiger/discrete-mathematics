#include "utils.h"
#ifndef length
#define length 0
#endif

void heapify(int* arr, int idx, int len){
    int largest = idx;
    int left_child_idx = 2 * idx + 1;
    int right_child_idx = 2 * idx + 2;
    if((left_child_idx < len) && (arr[left_child_idx] > arr[largest])) largest = left_child_idx;
    if((right_child_idx < len) && (arr[right_child_idx] > arr[largest])) largest = right_child_idx;
    if(largest != idx){
        swap(&arr[largest], &arr[idx], sizeof(int));
        heapify(arr, largest, len);
    }
}

void heap_from(int* arr){
    for(int i = length / 2 - 1; i > -1; i--) heapify(arr, i, length);
}