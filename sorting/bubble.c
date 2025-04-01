#include <stdio.h>

void bubble_sort(int[], int);

void display(int a[], int n) {

  for (int i = 0; i < n; i++) {
    printf("%d,", a[i]);
  }

  printf("\n");
}

int main() {

  int a[] = {6, 5, 2, 9, 1, 3};

  printf("Before Sort: ");
  display(a, 6);

  bubble_sort(a, 6);

  printf("After Sort: ");
  display(a, 6);
}

void bubble_sort(int arr[], int n) {
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n - 1 - i); j++) {
      if (arr[j] < arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
