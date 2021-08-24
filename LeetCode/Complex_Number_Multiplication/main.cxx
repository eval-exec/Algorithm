#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Complex Number Multiplication

*/


class Num {
	public:
	int real;
	int complex;
	static	Num fromstr(string num){
		int p = 1;
		for (;p < num.size();p++){
			if (num[p] == '+') break;
		}
		auto n = Num{};
		n.real = stoi(num.substr(0,p));
		n.complex = stoi(num.substr(p+1,num.size() - p-2));
		return n;
	}
	string str(){
		string ret;
		ret += to_string(real);
		ret += "+";
		ret += to_string(complex);
		ret += "i";
		return ret;
	}
};

class Solution {
	public:
	string complexNumberMultiply(string num1, string num2) {
		auto n1 =  Num::fromstr(num1);
		auto n2 =  Num::fromstr(num2);
		auto r = Num{};
		r.real = n1.real * n2.real + n1.complex * n2.complex;
		r.complex = n1.complex*n2.real + n1.real*n2.complex;
		return r.str();
	}
};
//// END
struct T{

};

TEST(Solution,test){
	T ts[] = {
		{

		},
		{

		},

	};


	for (T t : ts){
		Solution solution;

	}
}

int main() {
	testing::InitGoogleTest();

	return RUN_ALL_TESTS();
}


