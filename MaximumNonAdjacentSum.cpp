/* Find sub array with maximum sum and non-adjacent numbers */

#include <iostream>

using namespace std;

int findMaxSum(int arr[], int n) {
	int incl = arr[0];
	int excl = 0, excl_new;
	for(int i = 1; i < n; i++) {
		excl_new = incl > excl ? incl : excl;
		incl = excl + arr[i];
		excl = excl_new;
	}

	return (excl > incl ? excl : incl);
}

int main_findMax() {
	int arr[] = {4, 2, 5, 1, 6};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << "Maximum Sum is : " << findMaxSum(arr, len) << endl;
	return 0;
}
