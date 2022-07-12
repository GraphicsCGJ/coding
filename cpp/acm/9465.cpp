#include <iostream>

using namespace std;
int T;
int main(void) {
    cin >> T;

    int map[2][100001];

    while (T--) {
        int n;
        int maxVal = 0;
        cin >> n;
        // map = (int**)malloc(sizeof(int*) * 2);
        // map[0] = (int*)malloc(sizeof(int) * 2);
        // map[1] = (int*)malloc(sizeof(int) * 2);

        for (int i = 0; i < n; i++)
            cin >> map[0][i];

        for (int i = 0; i < n; i++)
            cin >> map[1][i];

        for (int i = 0; i < n; i++) {
            if (i == 1) {
                map[0][i] = map[1][i - 1] + map[0][i];
                map[1][i] = map[0][i - 1] + map[1][i];
            }
            else if (i > 1) {
                int tmp0 = map[0][i - 2] > map[1][i - 2] ? map[0][i - 2] + map[0][i] : map[1][i - 2] + map[0][i];
                int tmp1 = map[0][i - 2] > map[1][i - 2] ? map[0][i - 2] + map[1][i] : map[1][i - 2] + map[1][i];
                map[0][i] = map[1][i - 1] + map[0][i];
                map[1][i] = map[0][i - 1] + map[1][i];

                if (map[0][i] < tmp0)
                    map[0][i] = tmp0;

                if (map[1][i] < tmp1)
                    map[1][i] = tmp1;
            }

            if (maxVal < map[0][i])
                maxVal = map[0][i];

            if (maxVal < map[1][i])
                maxVal = map[1][i];
        }

        // free(map[0]);
        // free(map[1]);
        // free(map);

        cout << maxVal << endl;
    }

    return 0;
}