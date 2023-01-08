// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int arr[100];
int len;
int N;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s1;
    cin >> s1;
    // if (N == 0) {
    //     arr[len++] = 0;
    // }
    // else {
    //     while (N > 0) {
    //         arr[len++] = N % 10;
    //         N /= 10;
    //     }
    // }
    for (auto c : s1) {
        arr[len++] = c - '0';
    }
    int val = 0;
    while (true) {
        if (val > 1000) break;

        int val2 = val;
        int arr2[4];
        int len2 = 0;

        if (val2 == 0) {
            arr2[len2++] = 0;
        }
        else {
            while (val2 > 0) {
                arr2[len2++] = val2 % 10;
                val2 /= 10;
            }

        }

        reverse(arr2, arr2 + len2);

        int i = 0, j = 0;
        while (i < len && j < len2) {
            if (arr[i] == arr2[j]) {
                j++;
            }
            i++;
        }
        if (j == len2) {
            cout << "YES" << '\n';
            for (int i2 = 0; i2 < len2; i2++) {
                cout << arr2[i2];
            }
            cout << '\n';

            return 0;
        }

        val += 8;
    }

    cout << "NO\n";



    return 0;
}

