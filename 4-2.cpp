// Implement Longest Common Subsequence dynamic programming algorithm

#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

void printLCS(const vector<vector<pair<int, string>>> v, const string & s, const int i, const int j) {
    if (i == 0 || j == 0) {
        return ;
    }
    if (v.at(i).at(j).second == "D") {
        printLCS(v, s, i-1, j-1);
        cout<<s.at(i-1)<<endl;
    } else if(v.at(i).at(j).second == "U") {
        printLCS(v, s, i-1, j);
    } else {
        printLCS(v, s, i, j-1);
    }
}

void findLCS(const string & s1, const string & s2) {
    const int n = s1.length(), m = s2.length();
    vector<vector<pair<int, string>>> v(n+1, vector<pair<int, string>>(m+1, pair<int, string>(0, "n")));
    for(int i = 0; i < n; i++) {
        v.at(i).at(0).first = 0;
    }
    for(int j = 0; j < m; j++) {
        v.at(0).at(j).first = 0;
    }
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            if(s1.at(i-1) == s2.at(j-1)) {
                v.at(i).at(j) = make_pair(v.at(i-1).at(j-1).first + 1, "D");
            } else if (v.at(i-1).at(j).first >= v.at(i).at(j-1).first) {
                v.at(i).at(j) = make_pair(v.at(i-1).at(j).first, "U");
            } else {
                v.at(i).at(j) = make_pair(v.at(i).at(j-1).first, "L");
            }
        }
    }

    printLCS(v, s1, n, m);
}

int main(void) {
    findLCS("ABDCABD", "ADBDCBD");
    return 0;
}
