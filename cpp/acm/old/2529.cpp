#include <iostream>
#include <stack>
#include <cmath>

using namespace std;
int n;
int r;
long long maxval;
long long minval;
char bdh[11];
int* answer;
bool* visited;

int digit(long long val) {
    int ret = 0;
    while (val != 0) {
        val /= 10;
        ret ++;
    }

    return ret;
}

void calc(int depth, int start) {
    if (depth == r) {
        long long value = 0;
        for (int i = r - 1; i >= 0; i--) {
            value += pow(10, i) * answer[(r - 1) - i];
        }

        if (minval > value) minval = value;
        if (maxval < value) maxval = value;
        return;
    }


    for (int i = 0; i <= 9; i++) {
        if (visited[i] == true) continue;
        if (start == 0) {
            answer[start] = i;
            visited[i] = true;
            calc(depth + 1, start + 1);
            visited[i] = false;
        }
        else {
            if ((bdh[start - 1] == '>' && answer[start - 1] > i) ||
                (bdh[start - 1] == '<' && answer[start - 1] < i)
            ) {
                answer [start] = i;
                visited[i] = true;
                calc(depth + 1, start + 1);
                visited[i] = false;
            }
        }
    }
}

int main(void) {

    maxval = 0;
    minval = 9999999999;
    cin >> n;
    r = n + 1;
    for (int i = 0; i < n; i++)
        cin >> bdh[i];

    answer = new int[r];
    visited = new bool[10];
    for (int i = 0; i < r; i++) {
        answer[i] = -1;
    }

    calc(0, 0);

    if (digit(maxval) == r)
        cout << maxval << endl;
    else
        cout << '0' << maxval << endl;

    if (digit(minval) == r)
        cout << minval << endl;
    else
        cout << '0' << minval << endl;

    return 0;
}
