#include <stdio.h>
int partition(int arr[], int sp, int ep) {
  int pivot = arr[sp];
  int i = sp + 1;
  int j = ep;
  while (i <= j) {
    while (arr[i] <= pivot){
      i++;
    }
    while (arr[j] > pivot){
      j--;
    }
    if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[sp];
  arr[sp] = arr[j];
  arr[j] = temp;
  return j;
}
int quicksort(int arr[], int sp, int ep) {
  if (sp < ep) {
    int pivotindex = partition(arr, sp, ep);
    quicksort(arr, sp, pivotindex - 1);
    quicksort(arr, pivotindex + 1, ep);
  }
  return 0;
}

int main() {
  int n;
  int arr[100];
  printf("Enter length of array : ");
  scanf("%d", &n);
  for (int i = 0; i < n ; i++) {
    printf("Enter number %d : ", i + 1);
    scanf("%d", &arr[i]);
  }
  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n ; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}