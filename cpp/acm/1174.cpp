#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

typedef long long ll;
vector<ll> vec;

int digit = 1;
int arr[10] = {0,0,0,0,0,0,0,0,0,0};

void nextVal() {
    arr[9] ++;
    for (int i = 0; i < digit; i++) {
        int i2 = 9 - i;
        if (arr[i2] == 10) {
            if (i2 == 0)
        }
    }
    for (int i = 0; i < digit; i++) {
        int i2 = 9 - i;

        if (arr[i2] == 10) {
            if (i2 == 0) return;

            digit ++;
            arr[i2] = 9 - i2;
            arr[i2 - 1] = arr[i2] + 1;
        }

    }
}

ll arr2ll() {
    ll ret = 0;
    for (int i = 0; i < 10; i++) {
        ret += arr[9 - i] * pow(10, i);
    }
    return ret;
}

bool check() {
    if (digit == 1)
        return true;

    bool ret = true;
    for (int i = 0; i < digit - 1 && ret; i++) {
        if (arr[9 - i] >= arr[9 - i - 1])
            ret = false;
    }

    return ret;
}

int main(void) {
    cin >> N;

    while(true) {
        bool bool_tmp = check();
        if (bool_tmp) {
            vec.push_back(arr2ll());
        }


    }

    return 0;
}