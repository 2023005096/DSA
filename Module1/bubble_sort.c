#include <stdio.h>
int main() {
  int len, temp, c = 0;
  int arr[100];
  printf("Enter length of array : ");
  scanf("%d", &len);
  for (int i = 0; i < len; i++) {
    printf("Enter number at index %d : ", i);
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        c += 1;
      }
    }
    if (c == 0) {
      for (int k = 0; k < len; k++) {
        printf("%d ", arr[k]);
      }
      exit(0);
    }
  }
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
