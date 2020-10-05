#include<stdio.h>

void printArray(int array[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}

void selectionSort(int array[], int n)
{
  int i, j, index, temp;
  for (i = 0; i < n-1; i++)  // n-1 as last element is always sorted.
  {
    index = i;
    for (j = i+1; j < n; j++)        // Find the minimum element
      if (array[j] < array[index])
        index = j;
    printf("While i = %d\n",i);
    printf("Minimum Element = %d\n",array[index]);

    temp = array[index];    /* Swap the minimum element with first element of unsorted array so that size of sorted array will increase. */
    array[index] = array[i];
    array[i] = temp;
    printf("Elements swapped are %d & %d\n",array[i], array[index]);
  }

  printf("Array after %d iterations - \n",i+1);
  printArray(array, n);   // During Sorting
  printf("\n");

}

int main()
{
  
  int n;
  printf("No. of elements in an array: ");
  scanf("%d",&n);
  int array[n];
  printf("Enter elements of array: ");
  for(int i=0; i<n; i++)
    scanf("%d", &array[i]);
  // we can calculate the number of elements in an array by using sizeof(array)/sizeof(array[0])
  printf("Un-Sorted array: \n");
  printArray(array, n);     // Unsorted array
  selectionSort(array, n);     // Call the sorting routine
  printf("\nSorted array: \n");
  printArray(array, n);   // Sorted array
  return 0;
}