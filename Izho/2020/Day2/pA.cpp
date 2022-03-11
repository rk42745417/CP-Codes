// 100/100
#include "grader.h"
#include <bits/stdc++.h>
using namespace std;

// to compile: g++ grader.cpp solution.cpp -o test.exe
string find_next(string str) {
	auto t = get_min_max(str);
	if(!t.first.empty())
		return str;

	int l = 0, r = str.size();
	while(l < r) {
		int m = l + r >> 1;
		auto t = get_min_max(str.substr(0, m) + string(r - m, '?') + string(str.size() - r, '_'));
		if(!t.second.empty() && t.second.substr(0, r) > str.substr(0, r))
			l = m + 1;
		else
			r = m;
	}
	if(l == 0)
		return "";
	l--;

	for(char c : "ACGT") {
		if(c <= str[l])
			continue;
		auto t = get_min_max(str.substr(0, l) + c + string(str.size() - l - 1, '_'));
		if(!t.first.empty())
			return get_min_max(str.substr(0, l) + c + string(str.size() - l - 1, '?')).first;
	}

	return "";
}
