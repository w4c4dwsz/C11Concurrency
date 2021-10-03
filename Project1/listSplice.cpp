#include <iostream>
#include <list>

using namespace std;

void out_put(list<int>& l) {
	cout << "list = [";
	for (auto it = l.begin(); it != l.end(); it++)
		cout << *it << ",";
	cout << "]" << endl;
}

int main() {
	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	list<int> new_l;
	auto aim = l.begin();
	advance(aim, 5);
	l.splice(new_l.begin(), l, l.begin(), aim);

	out_put(l);
	out_put(new_l);
}