#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> vec1;
vector<int> vec1_copy;
vector<int> vec2;

int bsearch(vector<int>& vec, int value) {
    int l = 0;
    int r = vec.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (value == vec[mid])
            return mid;
        else if (value < vec[mid]) {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return -1;
}

bool cmp(int &a, int &b) {
    return a < b;
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        vec1.push_back(tmp);
    }

    vec1_copy = vec1;
    sort(vec1.begin(), vec1.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (vec2.size() == 0 || vec2[vec2.size() - 1] < vec1[i])
            vec2.push_back(vec1[i]);
    }

    for (int i = 0; i < N; i++) {
        int val = vec1_copy[i];
        int idx = bsearch(vec2, val);

        cout << idx << " ";
    }
    cout << endl;


    return 0;
}