#include<iostream>
#include<vector>

using namespace std;

void vectorprint(vector<int>& v) {
    cout << "vector: ";
    for (auto& vi : v) {
        cout << vi << " ";
    }
    cout << endl;
}

void recur_bruteforfce(int n, vector<int>& v, int topick) {
    if (topick == 0) {
        vectorprint(v);
        return;
    }

    int smallest = v.empty() ? 0 : v.back() + 1;

    for (smallest; smallest < n; smallest++) {
        v.push_back(smallest);
        recur_bruteforfce(n, v, topick - 1);
        v.pop_back();
    }
}


int main(void) {

    vector<int> v;
    recur_bruteforfce(10, v, 3);

    return 0;
}