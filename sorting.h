#ifndef SORTING
#define SORTING

unsigned char is_ordered(int * array,int length);

void heapsort(int * array, int length);

int * mergesort(int * array, int low,int high);

int * merge(int * array_a, int * array_b, int a_len, int b_len);

void quicksort(int * array, int low,int high);

int partition( int * array,int left,int right);

void bubblesort(int * array, int length);

void countsort(int * array, int length, int div);

void radixsort(int * array, int length);

void insertionsort(int * array,int length);

void shellsort(int * array, int length);

void heapify(int * array, int length);

void sift_down(int * heap, int start,int end);

void selectionsort(int * array, int length);

void print_array(int * array,int length);

void swap(int i, int j, int * array,int length);

int find_max(int * array, int length);

int find_min(int * array, int length);


#endif
