#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

const int global_data = 10;
int main() {
	const int data = 10;
	int* p = const_cast<int*>(&data);
	*p = 11;
	cout << *p << data << endl;
	p = const_cast<int*> (&global_data);
	*p = 11;
	cout << *p << global_data << endl;
}
