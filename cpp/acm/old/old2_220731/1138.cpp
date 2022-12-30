#include<iostream>

using namespace std;

int arr[11];
int result[11];
bool visited[11];

int main(void) {

    int N;
    cin >> N;


    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        result[i] = 0;
        visited[i] = false;
    }

    for (int i = 0; i < N; i++) {

        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (visited[j] == true) {
                continue;
            }
            else {
                if (cnt == arr[i]) {
                    visited[j] = true;
                    result[j] = i + 1;
                    break;
                }
                else {
                    cnt++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";d
    }
    cout << endl;
}