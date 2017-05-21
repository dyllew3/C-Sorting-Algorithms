#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include "sorting.h"

int main(int argc, char **argv) {
  	srand(time(NULL));   // should only be called once
  	int array_size = 100;
  	int r =(rand()*5)/rand();      // returns a pseudo-random integer between 0 and RAND_MAX
  	int array[array_size];
  	int i;
  	for (i = 0; i < array_size; i++) {
    /* code */
    	array[i] = r;
    	r = (rand()*5)/rand();
  	}
  	printf("Unsorted array is\n");
  	print_array(array,array_size);	
  	struct timespec  start;
  	struct timespec  end;
  	clock_gettime(CLOCK_MONOTONIC,&start);
  	//heapsort(array,array_size);
  	//quicksort(array,0,array_size);
  	//selectionsort(array,array_size);
  	//radixsort(array,array_size);
  	shellsort(array,array_size);
  	clock_gettime(CLOCK_MONOTONIC,&end);
  	double st_time =   ((double)start.tv_sec)+  (((double)(start.tv_nsec))/1000000000);

  	double end_time =   ((double)end.tv_sec)+  (((double)end.tv_nsec)/1000000000);
  	double secs =((double) end.tv_sec - start.tv_sec  ) + ((double) (end.tv_nsec - start.tv_nsec))/1000000000 ;
  	if(is_ordered(array,array_size)){
    	printf("%s\n","Sorted array is:" );
    	print_array(array,array_size);

    	printf("Time taken is %.17g\n",end_time-st_time );
  	}
  	else{
    	printf("Not properly sorted\n" );
  	}
  	return 0;
}
