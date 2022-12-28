#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int K;

int maximum;
vector<string> vec;


int main(void) {
    maximum = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        vec.push_back(str);

        // for (int j = 0; j < M; j++) {
        //     field[i][j] = str[j] == '0' ? false : true;
        // }
    }
    cin >> K;

    for (int i = 0; i < N; i++) {
        int cnt = 0;

        for (int j = 0; j < M; j++) {
            cnt = (vec[i][j] == '0' ? cnt + 1 : cnt);
        }
        if (cnt % 2 == K % 2 && cnt <= K) {
            int maximum_local = 0;
            for (int j = 0; j < N; j++)
                if (vec[i] == vec[j])
                    maximum_local++;
            if (maximum < maximum_local)
                maximum = maximum_local;
        }
    }

    cout << maximum << endl;
    return 0;
}