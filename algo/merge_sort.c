#include <stdio.h>


void merge_sort(int array[], size_t size) {
	if (size <= 1) {
		return;
	}

	size_t n = size / 2;
	size_t m = size - n;
	int left[n], right[m];
	for (size_t i = 0; i < n; i++) {
		left[i] = array[i];
	}
	for (size_t i = n; i < size; i++) {
		right[i-n] = array[i];
	}
	merge_sort(left, n);
	merge_sort(right, m);

	size_t i = 0, j = 0;
        while (i < n || j < m) {
                if (i == n || (j < m) && (left[i] > right[j])) {
                        array[i + j] = right[j];
			j++;
                } else {
                        array[i + j] = left[i];
			i++;
                }
       }
}

int main() {
	printf("%s", "Merge sort program\n");
	printf("%s", "Enter array size: ");
	size_t n;
	scanf("%lu", &n);
	int array[n];
	int number;
	for (size_t i = 0; i < n; i++) {
		scanf("%d", &number);
		array[i] = number;
	}
	merge_sort(array, n);
	printf("%s", "Sorted array: ");
	for (size_t i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("%s", "\n");
	return 0;
}
