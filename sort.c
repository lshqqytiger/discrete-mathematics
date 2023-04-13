#include <stdio.h>
#define length 20
#include "sort_algorithms.h"
#include "benchmark.h"

int main(int argc, char** argv){
    if(argc == 1){
        printf("Available algorithms: bubble, insertion, heap\n");
        return 0;
    }
    int list[length] = { 4, 15, 17, 9, 10, 8, 5, 12, 1, 2, 16, 3, 19, 20, 6, 18, 7, 11, 13, 14 };
    double start, end;
    void(* algorithm)(int* arr) = find_algorithm(argv[1]);
    printf("Sorting Algorithm: %s\nBefore sort: ", argv[1]);
    print_array(list);
    start = time();
    algorithm(list);
    end = time();
    printf("After sort: ");
    print_array(list);
    printf("Time spent: %lfsec\n", end - start);
    return 0;
}