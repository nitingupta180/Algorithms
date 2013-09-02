#include <iostream>

using namespace std;

int lcs(char* X, char* Y, int m, int n) {
	int L[6/*m*/ + 1][7/*n*/ + 1];
	int i, j;
	for(int i = 0; i <= m; i++) {
		for(int j = 0; j <= n; j++) {
			if(j == 0 || i == 0) {
				L[i][j] = 0;
			} else if(X[i] == Y[j]) {
				L[i][j] = 1 + L[i-1][j-1];
			} else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	return L[m][n];
}

int main_lcs() {
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);
	cout << "Length of LCS is " << lcs(X, Y, m, n) << endl;
	return 0;
}
