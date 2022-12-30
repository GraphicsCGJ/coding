#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class c1{
public:
    int l;
    int r;
    c1(int l, int r) {
        this->l = l;
        this->r = r;
    }
};

int N;
vector<c1> vec1;

bool comp(c1& a, c1& b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        c1 c1_1(l,r);

        vec1.push_back(c1_1);
    }

    sort(vec1.begin(), vec1.end(), comp);

    // for (auto& c : vec1) {
    //     cout << c.l << ":" << c.r<< " ";
    // }
    // cout << endl;

    int begin_time = 0;
    int cnt = 0;
    for (auto& c : vec1) {
        if (begin_time > c.l)
            continue;
        cnt++;
        begin_time = c.r;
    }

    cout << cnt << endl;


    return 0;
}