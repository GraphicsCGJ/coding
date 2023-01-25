#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int N, M;

int arrN[50];
int arrM[10000];


int main(void) {
    list<int> li;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arrN[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> arrM[i];

    sort(arrM, arrM + M);



    return 0;
}