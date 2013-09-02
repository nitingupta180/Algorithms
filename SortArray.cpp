/* Given an array a[] = {0, 1, 1, 0, 2, 2, 1, 0, 1, 2, 1, 0} */

#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int a[], int len) {
	int low, mid, high;
	for(low = mid = 0, high = len - 1; mid <= high; ) {
		a[mid] == 0 ? swap(&a[low++], &a[mid++]) : (a[mid] == 1 ? mid++ : swap(&a[mid], &a[high--]));
	}
	for(int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main_sort() {
	int a[] = {0, 1, 1, 0, 2, 2, 1, 0, 1, 2, 1, 0};
	int len = sizeof(a)/sizeof(a[0]);
	sort(a, len);
	return 0;
}
