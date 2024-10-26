#include <stdio.h>
void merge(int arr[],int sp,int mp,int ep){
  int n1 = mp-sp+1;
  int n2 = ep-mp;
  int leftarr[n1],rightarr[n2];
  for(int i = 0;i<n1;i++){
    leftarr[i] = arr[sp+i];
  }
  for(int j = 0;j<n2;j++){
    rightarr[j] = arr[mp+1+j];
  }
  int i = 0;
  int j = 0;
  int k = sp;
  while(i<n1 && j<n2){
    if(leftarr[i]<=rightarr[j]){
      arr[k] = leftarr[i];
      i++;
    }
    else{
      arr[k] = rightarr[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    arr[k] = leftarr[i];
    i++;
    k++;
  }
  while(j<n2){
    arr[k] = rightarr[j];
    j++;
    k++;
  }
}
void mergeSort(int arr[], int sp, int ep) {
  if (sp < ep) {
    int mp = sp + (ep - sp) / 2;
    mergeSort(arr, sp, mp);
    mergeSort(arr, mp + 1, ep);
    merge(arr, sp, mp, ep);
  }
}
int main() {
  int n;
  int arr[100];
  printf("Enter length of array: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
  mergeSort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}