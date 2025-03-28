#include <stdio.h>

void insertion_sort(int[], int);

int main() {

  int a[] = {6, 5, 2, 9, 1, 3};

  for (int i = 0; i < 6; i++) {
    printf("%d,", a[i]);
  }

  insertion_sort(a, 6);

  for (int i = 0; i < 6; i++) {
    printf("%d,", a[i]);
  }

  return 0;
}

void insertion_sort(int a[], int n) {
  int temp;
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (a[j] < a[j - 1]) {
        temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
      } else {
        break;
      }
    }
  }
}
