#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ALPHA_CNT 26

int n, k;
int w[ALPHA_CNT];
bool comb[ALPHA_CNT];

// a t i n c
int main(void) {
    cin >> n >> k;
    k -= 3;
    vector<string> v;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string s2;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'c' || s[i] == 'i' || s[i] == 'n' || s[i] == 't')
                continue;
            s2.append(s.at(i));
            s.at(i);
        }

        v.push_back(s);
    }
}