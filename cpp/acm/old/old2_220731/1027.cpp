#include <iostream>

using namespace std;

int N;
int building[50];


int main(void) {
    cin >> N;
    int max = 0;

    for (int i = 0; i < N; i++) {
        cin >> building[i];
    }

    for (int i = 0; i < N; i++) {
        int total_cnt = 0;
        double slope;
        for (int li = i - 1; li >= 0; li--) {
            if (li == i - 1) {
                slope = (building[li] - building[i]);
                total_cnt++;
            }
            else {
                double slope_local = (double)(building[li] - building[i]) / (double)(i - li);
                if (slope_local > slope) {
                    slope = slope_local;
                    total_cnt++;
                }
            }
        }

        for (int ri = i + 1; ri < N; ri++) {
            if (ri == i + 1) {
                slope = (building[ri] - building[i]);
                total_cnt++;
            }
            else {
                double slope_local = (double)(building[ri] - building[i]) / (double)(ri - i);
                if (slope_local > slope) {
                    slope = slope_local;
                    total_cnt++;
                }
            }
        }

        if (max < total_cnt)
            max = total_cnt;
    }
    cout << max << endl;
    return 0;
}