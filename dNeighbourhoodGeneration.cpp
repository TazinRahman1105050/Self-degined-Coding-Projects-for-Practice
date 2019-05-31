#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;



string constructString(string s, int index, char repl) {
        string output;
		if(index == 0) {
            output = repl + s.substr(1, s.length());
            //cout<< output<<' ';
			return output;
		}
		else if(index == s.length() - 1) {
		    output = s.substr(0, s.length() - 1) + repl;
            //cout<< output << ' ';
			return output;
		}
		else {
		    output = s.substr(0, index) + repl + s.substr(index + 1, s.length());
            //cout<< output << ' ';
			return output;
		}

}
vector <string> generateHelper(string s, vector <int> used, int distance, vector <string> candidates) {
		if(distance > 0) {
			candidates.push_back(s);
			for(int i = 0; i < s.length(); i++) {
				if(!(std::find(used.begin(), used.end(), i) != used.end())) {
					used.push_back(i);
					char *tmp = "ATCG";
					for(int j=0; j<4; j++) {
						if(tmp[j] != s[i]) {
							string newString = constructString(s, i, tmp[j]);
							candidates=generateHelper(newString, used, distance - 1, candidates);
						}
					}
					used.pop_back();
				}
			}
		}
		return candidates;

}

vector<string> generate(string s, int distance) {
		vector<int> used;
        vector<string> candidates;
		//candidates.push_back(s);
		candidates = generateHelper(s, used, distance, candidates);

		return candidates;
	}
int main()
{
    freopen("input.txt","r",stdin);
    string new1;
    int d;
    cin>> new1;
    cin>> d;
    vector <string> vec;
    vec = generate(new1, d+1);
    for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << ' ';
	}
    return 0;

}
