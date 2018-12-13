#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main (int argc, char* argv[]) {
    int i = 0, el = 0;
    int s = atoi(argv[1]); 
    int values[s];

    for (i = 0; i < s; i ++){
        scanf("%d", &el); 
        values[i] = el; 
    }		   
    clock_t end;
    clock_t start = clock();
     
    qsort(values, s, sizeof(int), cmpfunc);
    end = clock();

    double difference = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time: %f", difference); 

    for( i = 0 ; i < s; i++ ) {   
        printf("%d ", values[i]);
    }

    return(0);
}