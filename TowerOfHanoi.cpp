/* WAP for Tower of Hanoi */

#include <iostream>

using namespace std;

void move(int disk, char fromPeg, char toPeg, char sparePeg) {
	if(disk == 1) {
		cout << "Move disk " << disk << " from " << fromPeg << " to " << toPeg << endl;
	} else {
		move(disk - 1, fromPeg, sparePeg, toPeg);
		cout << "Move disk " << disk << " from " << fromPeg << " to " << toPeg << endl;
		move(disk - 1, sparePeg, toPeg, fromPeg);
	}
}

int main_toh() {
	int no_of_disks;
	cout << "Enter number of disks : ";
	cin >> no_of_disks;
	char fromPeg = 'A', toPeg = 'B', sparePeg = 'C';
	move(no_of_disks, fromPeg, toPeg, sparePeg);
	return 0;
}
