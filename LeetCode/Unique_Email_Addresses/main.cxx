#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;


//// START
/*
## Unique Email Addresses

*/
class Solution {
	public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> ss;
		for (string email: emails){
			string str;
			bool inDomain=false;
			bool plus = false;
			for (char c : email){
				if (inDomain){
					str.push_back(c);
				}else if (c == '@'){
					inDomain = true;
					str.push_back(c);
				}else if (c == '+'){
					plus = true;
				}else if (plus || c == '.'){
					continue;
				}else {
					str.push_back(c);
				}
			}
			ss.insert(str);
		}
		return ss.size();
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


