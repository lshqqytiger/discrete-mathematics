#include <stdio.h>
#define length 5
#include "sort_algorithms.h"
#include "benchmark.h"

int main(int argc, char** argv){
    if(argc == 1){
        printf("Available algorithms: bubble, insertion\n");
        return 0;
    }
    int list[length] = { 3, 2, 4, 1, 5 };
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