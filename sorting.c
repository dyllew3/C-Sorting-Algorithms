#include <stdlib.h>
#include<stdio.h>
#include "sorting.h"
//This is an implementation of various sorting algorithms in C using ints

//checks if an array is ordered, if ordered returns 1 if not returns 0
//O(n) time complexity and O(1) space complexity
unsigned char is_ordered(int * array,int length){
  int i;
  for (i = 1; i < length; i++) {
    /* code */
    if (array[i - 1] > array[i])
      return 0;
  }
  return 1;
}

/*This sorting algorithm sorts an array by heapifying the
 array in O(n) time aprroximately then sorts that min heap by
swapping the top of the heap with the the end which starts at the length-1
 and decrements until it gets to the start
 Runs in  O(nlogn) time and uses O(1)
*/
void heapsort(int * array, int length){
  heapify(array,length);
  int end = length - 1;
  while(end > 0){
    swap( 0, end,array,length);
    end--;
    sift_down(array, 0, end);
  }
}


//merge sort is when the array is continually divided in half
// until it is either 1 or 2 elements in length. It then sorts an
// merges two of these adjacent arrays until the array is remade and
// is sorted
//runs in O(n log(n)) time and O(n) space
int * mergesort(int * array, int low, int high){
  int * result;
  if (high - low > 2) {

    int * left;
    int * right;

    int mid;
    if ( (low + high)%2 == 0 )
      mid = (low + high)/2 ;
    else
    mid = (low + high + 1)/2;
    left = mergesort(array, low, mid);
    right = mergesort(array, mid, high);
    result =  merge(left,right,(mid-low),(high-mid));
    free(left);
    free(right);
    //return array;
  }
  else if(high - low == 2){
    result = malloc(sizeof(int) * (high - low));
    if(array[low] > array[high]){
      result[0] = array[high];
      result[1] = array[low];
    }
    else{
      result[0] = array[low];
      result[1] = array[high];

    }
  }
  else{
    result = malloc(sizeof(int));
    result[0] = array[low];
  }
  return result;
}


//merges two sorted arrays and returns a sorted array that is the combination
// of the two arrays in O(n + m)  time n = array a length, m = array b length
int * merge(int * array_a, int * array_b, int a_len, int b_len){

    int index = 0;
    int * result = malloc(sizeof(int) * (a_len + b_len));
    int i = 0;
    int j = 0;

    while(i < a_len && j < b_len) {

      //put smallest element at current index of each array onto the array
      //then increment their index
      if (array_a[i] < array_b[j]) {
        /* code */
        result[index] = array_a[i];
        index++;
        i++;
      }
      else{
        result[index] = array_b[j];
        index++;
        j++;
      }
    }
    //put any remaining elements of a onto the result array
    while (i < a_len) {
      result[index] = array_a[i];
      index++;
      i++;
    }

    //put any remaining elements of b onto the result
    while (j < b_len) {
      /* code */
      result[index] = array_b[j];
      index++;
      j++;
    }
    return result;
}

void quicksort(int * array, int low,int high){
  int i = low;
  int j = high;
    // Get the pivot element from the middle of the list
    int pivot = array[i + (j-i)/2];

    // Divide into two lists
    while (i <= j) {
            // If the current value from the left list is smaller than the pivot
            // element then get the next element from the left list
            while (array[i] < pivot) {
                    i++;
            }
            // If the current value from the right list is larger than the pivot
            // element then get the next element from the right list
            while (array[j] > pivot) {
                    j--;
            }

            // If we have found a value in the left list which is larger than
            // the pivot element and if we have found a value in the right list
            // which is smaller than the pivot element then we exchange the
            // values.
            // As we are done we can increase i and j
            if (i <= j) {
                    swap(i, j,array,j+ 1);
                    i++;
                    j--;
            }
    }
    // Recursion
    if (low < j)
            quicksort(array,low, j);
    if (i < high)
            quicksort(array,i, high);
}

//partitions an array between
int partition( int * array,int left,int right){
  int pivot = array[right];
  int i = left - 1;
  int j;
  for (j = left; j < right - 1; j++) {
    //checks if less than pivot
    if (array[j] <= pivot) {
      i++;
      if(i != j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }

    }
  }
  int temp = array[i + 1];
  array[i + 1] = array[right];
  array[right] = temp;
  return i + 1;
}

//don't use ever
void bubblesort(int * array, int length){
  int i,j;
  for (i = 0; i < length; i++) {
    for (j = i + 1; j < length; j++) {
      if (array[i] > array[j]) {
        swap(i,j,array,length);
      }
    }
  }

}

void  countsort(int * array, int length, int div){
  int * result = malloc(sizeof(int) * length);
  int base = 10;
  int i;
  int count[10] = {0};
  for (i = 0; i < length; i++) {
    count[ (array[i]/div)%base ] += 1;
  }
  for ( i = 1; i < base; i++) {
    /* code */
    count[i] += count[i - 1];
  }
  for (i = length - 1; i >= 0; i--)
  {
      result[count[ (array[i]/div)%10 ] - 1] = array[i];
      count[ (array[i]/div)%10 ]--;
  }

  // Copy the output array to arr[], so that arr[] now
  // contains sorted numbers according to current digit
  for (i = 0; i < length; i++)
      array[i] = result[i];
  free(result);

}

void radixsort(int * array, int length){
  int level = 1;
  int max = find_max(array,length);
  while (level <= max) {
    countsort(array,length,level);
    level *= 10;
  }
}

void selectionsort(int * array,int length){
  int i,j;
  int min_j;
  for ( i = 0; i < length - 1; i++) {
    min_j = i;
    for (j = i + 1; j < length; j++) {
      if (array[j] < array[min_j]) {
        min_j = j;
      }
    }
    if(min_j != i)
      swap(i,min_j,array,length);
  }
}

void shellsort(int * array, int length){}

//convert an integer array into a heap using sift method
//starts on the last parent node from the bottom
void heapify(int * array, int length){

  int start = (length - 1)/2;
  		while(start >= 0){

  			sift_down(array,start,length-1);
  			start--;
  }
}


//implements sift down in a min heap, assumes heap starts at 0
//this has log(n) time approximately
void sift_down(int * heap, int start,int end){

		int curPos = start;
		while((curPos*2) + 1 <= end){

			int pos =(curPos*2) + 1;
			if(pos + 1 <= end && heap[pos] < heap[pos + 1]){
				pos = pos + 1;

			}
			if(heap[pos] >  heap[curPos]){
				int temp = heap[pos];
				heap[pos] = heap[curPos];
				heap[curPos] = temp;
			}
			else {
				break;
			}
			curPos = pos;
		}

}

void swap(int i, int j, int * array,int length){
  if(i >= length || j >= length || i < 0 || j < 0)
    return;
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;

}

void insertionsort(int * array, int length){
  int i,j;
  for (i = 0; i < length; i++) {
    i = j;
    while (j > 0 && array[j - 1] > array[j]) {
      swap(i,j,array,length);
      j--;
    }
  }
}

void print_array(int * array,int length){
  int i;
  for (i = 0; i < length; i++) {
    printf("%i",array[i]);
    if (i+1 < length) {
      printf(",");
    }
    else
      printf("\n");
  }
}



int find_min(int * array, int length){
  if(length <= 0 )
    return 0;
  int min = array[0];
  int i;
  for (i = 1; i < length; i++) {
    if (min > array[i]) {
      min= array[i];
    }
  }
  return min;
}

int find_max(int * array, int length){
  if(length <= 0 )
    return 0;
  int i;
  int max = array[0];
  for (i = 1; i < length; i++) {
    if (max < array[i]) {
      max = array[i];
    }
  }
  return max;
}
