/* Find number of ways to make change given some coins */

#include <iostream>

using namespace std;

void coinDenomination(int* coin, int size, int* sol, int depth, int toFind, int start) {
	if(toFind < 0) {
		return;
	}
	if(toFind == 0) {
		for(int i = 0; i < depth; i++) {
			cout << sol[i] << " ";
		}
		cout << endl;
	} else {
		for(int i = 0; i < size; i++) {
			sol[depth] = coin[i];
			coinDenomination(coin, size, sol, depth + 1, toFind - coin[i], i);
		}
	}
}

int main_makeChange() {
	int coin[] = {1, 5, 10, 25};
	int size = sizeof(coin)/sizeof(coin[0]);
	int sol[50] = {0};
	int toFind = 25;
	coinDenomination(coin, size, sol, 0, toFind, 0);
	return 0;
}
