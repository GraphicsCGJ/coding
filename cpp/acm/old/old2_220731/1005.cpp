#include <iostream>
#include <vector>
using namespace std;

#define N 1000

class craft_c {
    public:
        vector<int> pv;
        int cost;
};

craft_c craftList[N + 1];
int dp[N + 1];
int n;
int rules;

int calc (int idx) {
    if (craftList[idx].pv.empty() == true) {
        return craftList[idx].cost;
    }
    else if (dp[idx] != -1) {
        return dp[idx];
    }
    else {
        int maxvalue = -1;
        for (int i = 0; i < craftList[idx].pv.size(); i++) {
            int pi = craftList[idx].pv[i];

            int localvalue = calc(pi) + craftList[idx].cost;
            if (maxvalue < localvalue) maxvalue = localvalue;
        }

        dp[idx] = maxvalue;
        return maxvalue;
    }
}

int main(void) {
    int T;
    int target;
    cin >> T;

    while (T--) {
        cin >> n;
        cin >> rules;

        for (int i = 1; i <= n; i++) {
            cin >> craftList[i].cost;
            craftList[i].pv.clear();
            dp[i] = -1;
        }

        for (int i = 1; i <= rules; i++) {
            int p, c;
            cin >> p >> c;
            craftList[c].pv.push_back(p);
        }

        cin >> target;
        cout << calc(target) << endl;
    }
    return 0;
}