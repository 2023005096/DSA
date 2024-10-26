#include <stdio.h>
int main() {
  int a[100];
  int i, n, x, c = 0;
  printf("Enter length of array : ");
  scanf("%d", &n);
  printf("Enter element to search : ");
  scanf("%d", &x);
  for (i = 0; i < n; i++) {
    printf("Enter number %d : ", i + 1);
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++) {
    if (a[i] == x) {
      printf("Element is at index %d\n", i);
      printf("Successfull\n");
      c = 1;
      break;
    }
  }
  if (c == 0) {
    printf("Unsuccessfull!!\n");
  }
  return 0;
}