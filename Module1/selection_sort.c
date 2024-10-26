#include <stdio.h>
int main() {
  int i, j, small, n;
  int arr[100];
  printf("Enter ngth of array : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter number %d : ", i + 1);
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n - 1; i++) {
    small = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[small]) {
        small = j;
      int temp = arr[small];
      arr[small] = arr[i];
      arr[i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}