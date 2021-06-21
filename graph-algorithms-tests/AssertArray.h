#pragma once
#include<sstream>
#include<list>

bool ASSERT_ARRAY(std::istringstream &expectedResultStrm, std::list<int> &actualResultStrm, int &size) {

	if (actualResultStrm.size() != size) return false;
	for (int i = 0; i < size; i++) {
		int temp;
		expectedResultStrm >> (int)temp;
		if (temp != actualResultStrm.front())
			return false;
		actualResultStrm.pop_front();
	}

	return true;
}

