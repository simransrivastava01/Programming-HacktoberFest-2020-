#include<stdio.h>

int rec_binary_search(int arr[], int left, int right, int x) {
  int result;
  if (right >= left) {
    int mid = left + (right - left)/2;
    if (arr[mid] == x)  return mid;
    if (arr[mid] > x) return rec_binary_search(arr, left, mid-1, x);
    result = rec_binary_search(arr, mid+1, right, x);
    return result;
  }
  return -1;       // when element is not present in array.
}

int main() {
  int loc,x;
  int n;
  printf("Number of elements in array: ");
  scanf("%d",&n);
  int array[n];
  printf("Element to be found: ");
  scanf("%d",&x);  // element to be searched in the array
  printf("Enter elements of array: ");
  for(int i=0; i<n; i++)
  {
      scanf("%d",&array[i]);
  }
  loc=rec_binary_search(array,0,n,x);
  if(loc != -1)
    printf("Element found at location : %d",loc);
  else
    printf("Element not present in the array.");
  return 0;
}
