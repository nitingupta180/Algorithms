#include <iostream>

using namespace std;

int main_minCoin() {
	int coins[] = {1, 3, 5};
	int size = sizeof(coins)/sizeof(coins[0]);
	int sum = 13;
	int* minArray = (int*) malloc(sizeof(int) * (sum + 1));
	minArray[0] = 0;
	for(int i = 1; i <= sum; i++) {
		minArray[i] = INT_MAX;
	}

	for(int i = 1; i <= sum; i++) {
		for(int j = 0; j < size; j++) {
			if(coins[j] <= i && minArray[i - coins[j]] + 1 < minArray[i]) {
				minArray[i] = minArray[i - coins[j]] + 1;
			}
		}
	}
	cout << "Minimum number of coins required : " << minArray[sum] << endl;
	return 0;
}
