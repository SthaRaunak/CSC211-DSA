#include <stdio.h>

void selection_sort(int arr[], int n) {
  int temp;
  int min_idx;
  for (int i = 0; i < n - 1; i++) {
    min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

void display(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d,", a[i]);
  }
  printf("\n");
}

int main() {
  int a[] = {6, 5, 2, 9, 1, 3};
  int n = 6;

  printf("Before Selection Sort: ");
  display(a, n);

  selection_sort(a, n);

  printf("After Selection Sort: ");
  display(a, n);
  return 0;
}
