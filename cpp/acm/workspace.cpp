#include<iostream>

using namespace std;
int N;

int arrows[1000001];

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    int result = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (arrows[tmp] > 0) {
            arrows[tmp]--;
            --tmp;
            arrows[tmp]++;
        }
        else {
            arrows[--tmp]++;
            result++;
        }
    }
    cout << result << '\n';

    return 0;
}
