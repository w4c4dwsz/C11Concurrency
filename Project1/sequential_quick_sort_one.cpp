#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
list<T> sequential_quick_sort(list<T> input) {
	if (input.empty())
		return input;
	list<T> result;
	result.splice(result.begin(), input, input.begin());
	const T& pivot = *result.begin();
	auto divide_point = partition(input.begin(), input.end(), [&](const T& t) {return t < pivot; });
	list<T> lower_part;
	lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
	auto new_lower = sequential_quick_sort(std::move(lower_part));
	auto new_higher = sequential_quick_sort(std::move(input));
	result.splice(result.begin(), new_lower);
	result.splice(result.end(), new_higher);
	return result;
}

int main() {
	list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(100 - i);

	auto res = sequential_quick_sort<int>(l);
	for (auto it = res.begin(); it != res.end(); it++)
		cout << *it << endl;
	return 0;
}