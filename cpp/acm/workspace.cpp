#include <iostream>
#include <algorithm>

using namespace std;
using ll=long long;


int N;
int filled[3];

ll arr[5000];

inline bool _contain(int* arr, ll tgt) {
  for (int i = 0; i < 3; i++)
    if (arr[i] == tgt) return true;
  return false;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  sort(arr,arr+N);
  for(int i=0;i<3;i++)
    filled[i] = i;

  bool moved = false;
  do {
    moved = false;

    int filled2[3];
    ll sum = 0;
    for (int i=0; i<3;i++)
      sum += arr[filled[i]];

    for (int i=0; i<3;i++) {
      for (int nxt = filled[i]-1; nxt <= filled[i] + 1; nxt+=2) {
        if (nxt < 0 || nxt >= N || _contain(filled, nxt)) continue;

        ll sum2 = 0;
        for (int k = 0; k < 3; k++)
          sum2 += k != i ? arr[filled[k]] : arr[nxt];
        if (abs(sum2) < abs(sum)) {
          sum = sum2;
          for (int k = 0; k < 3; k++)
            filled2[k] = (i == k ? nxt : filled[k]);
          moved = true;
        }
      }
    }

    if (moved) {
      for (int i=0;i<3;i++)
        filled[i] = filled2[i];
    }
  } while(moved);

  for (int i = 0; i < 3; i++)
    cout << arr[filled[i]] << ' ';
  cout << '\n';

  return 0;
}