#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool arr[1024 * 3 * 2];

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N;
    int len = 2 * N;
    int step = 1;

    fill(arr, arr + len, false);
    arr[N] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < len; j++) {
            cout << (arr[j] == true ? '*' : ' ');
            // cout << (arr[j] == true ? "[*]" : "[ ]");
        }
        cout << '\n';

        if (i == N-1) break;

        vector<int> vec;
        if (step == 1) {
            for (int j = 0; j < len; j++) {
                if (arr[j] == true) {
                    vec.push_back(j-1);
                    vec.push_back(j+1);
                }
            }

            fill(arr, arr + len, false);
            for (auto& v : vec) {
                arr[v] = true;
            }
            step = 2;
        }
        else if (step == 2) {
            for (int j = 0; j < len; j++) {
                if (arr[j] == true) {
                    vec.push_back(j-1);
                    vec.push_back(j);
                    vec.push_back(j+1);
                }
            }

            fill(arr, arr + len, false);
            for (auto& v : vec) {
                arr[v] = true;
            }

            step = 3;
        }
        else {
            for (int j = 0; j < len; j++) {
                if (arr[j] == true) {
                    if (arr[j-1] == false && arr[j-2] == false)
                        vec.push_back(j-1);
                    else if (arr[j+1] ==false && arr[j+2] == false)
                        vec.push_back(j+1);
                }
            }

            fill(arr, arr + len, false);
            for (auto& v : vec) {
                arr[v] = true;
            }

            step = 1;
        }
    }



    return 0;
}