#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int T;
int N;
vector<string> vec;

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        vec.clear();
        vec.reserve(N);

        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            vec.push_back(str);
        }

        sort(vec.begin(), vec.end());

        bool check = true;
        for (int i = 0; i < N - 1 && check; i++) {
            string &s1 = vec[i];
            string &s2 = vec[i + 1];

            int minl = s1.size() < s2.size() ? s1.size() : s2.size();

            bool issame = true;
            for (int i = 0; i < minl && issame; i++) {
                if (s1[i] != s2[i])
                    issame = false;
            }

            if (issame)
                check = false;
        }

        if (check == false)
            cout << "NO";
        else
            cout << "YES";
        cout <<endl;
    }
    return 0;
}