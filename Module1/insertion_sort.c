#include <stdio.h>
int main() {
  int n, i, key;
  int arr[100];
  printf("Enter ngth of array : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter number %d : ", i + 1);
    scanf("%d", &arr[i]);
  }
  for (int j = 1; j < n; j++) {
    key = arr[j];
    i = j - 1;
    while (i >= 0 && arr[i] > key) {
      arr[i + 1] = arr[i];
      i = i - 1;
    }
    arr[i + 1] = key;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

