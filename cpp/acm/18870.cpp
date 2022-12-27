#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;

vector<int> vec1;
set<int> set1;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        set1.insert(tmp);
        vec1.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        // int tmptmp = set1.find(vec1[i])
        cout << distance(set1.begin(), set1.find(vec1[i])) << ' ';

    }
    cout << endl;



    return 0;
}