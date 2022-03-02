#include <iostream>

using namespace std;

int NUM[101];

int main() {
	int N, count,value,from;
	from = 0;
	count = 0;
	cin >> N;
	while (count < N) {
		cin >> value;
		count++;
		while (NUM[from] != 0) {
			from = (from+1) % N;
		}
		NUM[from] = value;
		from = (value + from)%N;
	}
	for (int i = 0; i < N; ++i) {
		cout << NUM[i]<<" ";
	}

}