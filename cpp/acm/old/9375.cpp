#include<iostream>
#include<map>
#include<string>

using namespace std;

int T;
int N;

int main(void) {
    cin >> T;

    while (T--) {

        cin >> N;
        int summation = 1;

        map<string, int> check;
        for (int i = 0; i < N; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            auto iter = check.find(s2);
            if (iter != check.end())
                iter->second ++;
            else
                check.emplace(s2, 2);
        }

        for (auto& p : check) {
            summation *= p.second;
        }
        cout << --summation << "\n";
    }
    return 0;
}