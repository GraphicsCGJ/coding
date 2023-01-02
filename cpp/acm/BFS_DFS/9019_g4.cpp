#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int a, b;

class C1 {
public:
    int value;
    string str;
};

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--) {
        cin >> a >> b;
        bool check[10000];
        fill(check, check + 10000, false);

        queue<C1> q;
        C1 src, tar;
        src.value = a;
        tar.value = b;
        check[src.value] = true;
        q.push(src);

        while(q.size() > 0) {
            src = q.front();
            q.pop();

            int local_value;
            if (src.value == tar.value)
                break;

            local_value = src.value * 2;
            local_value %= 10000;

            if (check[local_value] == false) {
                C1 tmp;
                tmp.value = local_value;
                tmp.str = src.str + 'D';
                q.push(tmp);
                check[local_value] = true;
            }

            local_value = src.value - 1;
            if (local_value < 0) local_value = 9999;
            if (check[local_value] == false) {
                C1 tmp;
                tmp.value = local_value;
                tmp.str = src.str + 'S';
                q.push(tmp);
                check[local_value] = true;
            }
            local_value = src.value / 1000;
            local_value += (src.value % 1000) * 10;
            if (check[local_value] == false) {
                C1 tmp;
                tmp.value = local_value;
                tmp.str = src.str + 'L';
                q.push(tmp);
                check[local_value] = true;
            }

            local_value = (src.value % 10) * 1000;
            local_value += (src.value / 10);
            if (check[local_value] == false) {
                C1 tmp;
                tmp.value = local_value;
                tmp.str = src.str + 'R';
                q.push(tmp);
                check[local_value] = true;
            }
        }

        for (auto& v : src.str)
            cout << v;
        cout << '\n';
    }


    return 0;
}