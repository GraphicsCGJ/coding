#include <iostream>
#include <cmath>
#include<set>

using namespace std;


const int tmp = 666;

int main(void) {
    set<int, std::less<int>> s;
    int idx;

    /* insert */
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        sum += (int)pow(10, i) * tmp;

        for (int n1 = 0; n1 <= 9; n1++) {
            for (int n2 = 0; n2 <= 9; n2++) {
                for (int n3 = 0; n3 <= 9; n3++) {
                    for (int n4 = 0; n4 <= 9; n4++) {
                        int m[4] = {3, 4, 5, 6};
                        int n[4];
                        int sum2 = sum;

                        n[0] = n1;
                        n[1] = n2;
                        n[2] = n3;
                        n[3] = n4;

                        for (int j = 0; j < i; j++) {
                            m[j] -= 3;
                        }

                        for (int j = 0; j < 4; j++) {
                            sum2 += (int)pow(10, m[j]) * n[j];
                        }

                        s.insert(sum2);
                    }
                }
            }
        }

    }

    cin >> idx;
    auto iter = s.begin();
    std::advance(iter, idx - 1);
    cout << *iter << endl;

    return 0;
}