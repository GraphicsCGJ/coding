#include <iostream>
#include <list>

using namespace std;

inline static void swap(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}

void print(list<int>& l1) {
    int N = l1.size();
    auto iter = l1.begin();
    for (int i = 0; i < N;  i++) {
        cout << *iter << ' ';
        iter++;
    }
    cout << '\n';
}

int main(void) {

    int N, S;
    // vector<int> vec1;
    list<int> l1;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        l1.push_back(tmp);
    }

    cin >> S;

    // int cnt = 0;

    // print(l1);
    for (int i = 0; i < N - 1; i++) {
        auto it1 = l1.begin();
        for (int j = 0; j < i; j++) it1++;
        auto it2 = it1;
        auto it_bg = it1;
        auto it_mx = it1;
        it2++;
        int cnt = -1;
        for (int j = i; j < N - 1&& (j - i + 1) <=  S; j++) {
            if (*it1 < *it2) {
                if (*it_mx < *it2) {
                    it_mx = it2;
                    cnt = (j - i + 1);
                }
            }

            it1++; it2++;
        }

        if (cnt > 0) {
            int tmp = *it_mx;
            l1.erase(it_mx);
            l1.insert(it_bg, tmp);
            S -= cnt;
            // print(l1);
        }
    }

print(l1);



    return 0;
}