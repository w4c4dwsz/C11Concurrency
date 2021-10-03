#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
	int k;
	cin >> k;
	int num;
	char c;
	queue<int> data[10000];
	int cnt = 0;
	while (scanf_s("%d%c", &num, &c) != EOF) {
		data[cnt].push(num);
		if (c == '\n')
			cnt++;
	}

	while (true) {
		int flag = 0;
		for (int i = 0; i < cnt; i++) {
			int count = 0;
			while (!data[i].empty() && count < k) {
				cout << data[i].front() << ',';
				data[i].pop();
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	return 0;
}