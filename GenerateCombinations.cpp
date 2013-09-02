/* Generate all possible combinations of r elements inside an array of size N */

#include <iostream>

using namespace std;

void allSubGroups(int a[], int used[], int startIndex, int usedCount) {
	if(usedCount == 3) {
		for(int i = 0; i < usedCount; i++) {
			cout << a[used[i]] + " ";
		}
		cout << endl;
	} else {
		for(int i = startIndex; i < 6; i++) {
			used[usedCount] = i;
			allSubGroups(a, used, i + 1, usedCount + 1);
			used[usedCount] = -1;
		}
	}
}

int main_combination() {
	int a[] = {5, 4, 2, 8, 6, 0};
	int subGroupLength = 3;
	int used[] = {-1, -1, -1};
	allSubGroups(a, used, 0, 0);
	return 0;
}
