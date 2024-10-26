#include <stdio.h>
int main() {
  int len, num, sn, en, mn, value, c = 0;
  int arr[100];
  printf("Enter length of array : ");
  scanf("%d", &len);
  printf("Enter all numbers in sorted manner");
  for (int i = 0; i < len; i++) {
    printf("Enter number at index %d : ", i);
    scanf("%d", &arr[i]);
  }
  printf("Enter number to search : ");
  scanf("%d", &num);
  sn = 1;
  en = len;
  while (sn <= en) {
    mn = ((sn + en) / 2);
    if (arr[mn] == num) {
      printf("Element fount in index %d.\n", mn);
      c = 1;
      break;
    } else if (arr[mn] > num) {
      en = mn - 1;
    } else {
      sn = mn + 1;
    }
  }
  if (c == 0) {
    printf("Unsuccessfull!!.\n");
  }
  return 0;
}