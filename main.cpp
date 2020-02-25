//Jeremy Louie
//PIC 10C
//Falcon
//No collaborators
//"I pledge that I have neither given nor received unauthorized assistance on this assignment."

#include <iostream>
#include <vector>
#include "more.h"
#include "less.h"

//Returns position at which value is at (starting at 0)
template <class T, typename Compare = less<T>>
int binary_search(std::vector<T> v, int from, int to, T value, Compare cmp = less<T>()) {
	if (from > to) {	//if beginning index is greater than end index
		return -1;
	}
	
	int mid = (from + to) / 2;
	if (v[mid] == value) {	//if element of array v at index 'mid' is equal to variable 'value'
		return mid;
	} else if (cmp(v[mid], value)) {	//if element of array v at index 'mid' is less / greater than to variable 'value'
		return binary_search<T>(v, mid + 1, to, value, cmp);	//perform binary search on right hand half of array
	} else {	//if element of array v at index 'mid' is opposite of less / greater than to variable 'value'
		return binary_search<T>(v, from, mid - 1, value, cmp); //perform binary search on right hand half of array
	}
}

int main(int argc, const char * argv[]) {
	//Testing for integers
	std::vector<int> vi = {1, 3, 5, 10, 19};
	std::cout << binary_search(vi, 0, vi.size(), 10);
	
	//Testing for doubles
	std::vector<double> vd = {3.14, 2.7, 2.54, 0.19};
	more<double> dd;
	std::cout << binary_search(vd, 0, vd.size(), 2.7, dd);
	
	std::vector<std::string> vs = { "one", "two","zero" };
	std::string two = "two";
	less<std::string> ss;
	std::cout << binary_search(vs, 0, vs.size(), two, ss);
	
	std::cout << "\n";
}
