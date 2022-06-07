/*BY Cebastian Santiago
* Leetcode 3
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>


int lengthOfLongestSubstring(std::string s){
	//variables
	std::map<char, int> hash;
	int max = 0;
	int l = 0;
	int r = 1;
	//if an empty string
	if (s.empty()){
		return 0;
	}


	if (s.size() == 1){
		return 1;
	}

	if (s.size() == 2){
		if (s[0] != s[1]) {
			return 2;
		}
		else{
			return 1;
		}
	}

	hash.insert({ s[0],1 });

	//a b c a b c b b
	//  l   r
	//loop through the string 
	for (r = 1; r <= s.size()-1; r++) {
		//check if we've not seen the letter before
		if (hash.find(s[r]) == hash.end()) {
			//if we haven't seen it add it to the hash
			hash.insert({ s[r] , 1});
		}
		//else updated the window 
		//thill we dont have the right pointer anymore
		//a b c a b c b b
		//  l   r
		//and insert the element back into the hash
		else {
			while (hash.find(s[r]) != hash.end()) {
				hash[s[l]]--;
				if (hash[s[l]] <= 0) {
					hash.erase(s[l]);
				}
				l++;
			}
			hash.insert({ s[r],1 });
		}
		max = std::max(max, r - l + 1);
	}
	return max;
}


int main(int argc, char* argv[]) {
	std::string str = "abcabcbb";

	std::cout << lengthOfLongestSubstring(str) << std::endl;
	
	return 0;
}