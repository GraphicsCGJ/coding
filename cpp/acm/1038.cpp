#include <iostream>
#include <cmath>

using namespace std;

#define MAX_VALUE 1000001
typedef long long ll;

ll arr[MAX_VALUE];

int calcDigit(ll curr) {
    int n = 0;
    while (curr > 0) {
        n++;
        curr /= 10;
    }

    return n;
}

bool check(ll curr) {
    int predigit = -1;

    while (curr > 0) {
        int curdigit = curr % 10;
        if (curdigit <= predigit) return false;

        predigit = curdigit;
        curr /= 10;
    }

    return true;
}

/* alread added */
void nextVal(ll &curr) {
    int digit = calcDigit(curr);
    int tmparr[20];

    /* store current val*/
    ll curr_tmp = curr;
    int idx = 0;
    while (curr_tmp > 0) {
        tmparr[idx++] = curr_tmp % 10;
        curr_tmp /= 10;
    }

    /* calc */
    /* step 1. */

    for (int i = 0; i < digit - 1; i++) {
        if (tmparr[i] >= tmparr[i+1]) {
            tmparr[i+1] += 1;
            tmparr[i] = i;
        }
    }
    if (tmparr[digit - 1] == 10) {
        tmparr[digit] = digit;
        tmparr[digit - 1] = digit -1;
        digit++;
    }

    /* restore value*/
    ll new_curr = 0;
    for (int i = 0; i < digit; i++) {
        new_curr += ((ll)pow(10, i) * tmparr[i]);
    }
    curr = new_curr;
}

int main(void) {
    /* n 번째 */
    /* 계산을 다 해놓고, 들어온 값을 arr에서 출력만 해주자. */
    int n;
    cin >> n;

    ll curr = 0;
    for (int i = 0; i < MAX_VALUE; i++)
        arr[i] = -1;

    for (int i = 0; i < MAX_VALUE; i++) {
        if (curr > 9876543210)
            break;

        if (check(curr) == false)
            nextVal(curr);
        arr[i] = curr;
        curr++;
    }

    cout << arr[n] << endl;

    return 0;
}