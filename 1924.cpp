#include <iostream>
#include <string>
using namespace std;

int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
string weekday[8] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
int main() {
	int x,y;
	cin >> x >> y;

	for (int i = 1; i < x; ++i) {
		y += month[i];
	}

	cout << weekday[y % 7];

}