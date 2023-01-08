#include <iostream>

using namespace std;

#define ROOT 0

int v[10001];
int l[10001];
int r[10001];
int p[10001];
int sz = 1;

void insert(int val) {
    v[sz] = val;
    int nxt = ROOT;

    if (sz == 1) {
        l[nxt] = sz;
        r[nxt] = sz;
        p[sz++] = nxt;
        return;
    }

    while(true) {
        if (nxt == ROOT) {
            nxt = l[ROOT];
            continue;
        }

        if (v[sz] < v[nxt]) {
            if (l[nxt] == -1) {
                l[nxt] = sz;
                p[sz] = nxt;
                break;
            }
            else {
                nxt = l[nxt];
            }
        }
        else if (v[sz] > v[nxt]) {
            if (r[nxt] == -1) {
                r[nxt] = sz;
                p[sz] = nxt;
                break;
            }
            else {
                nxt = r[nxt];
            }
        }
        else
            break;
    }

    sz++;
}

void traverse(int nxt) {
    if (v[nxt] < 0) return;

    if (l[nxt] > 0)
        traverse(l[nxt]);
    if (r[nxt] > 0)
        traverse(r[nxt]);

    if (nxt != ROOT)
        cout << v[nxt] << '\n';
}


int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    fill(v, v + 10001, -1);
    fill(l, l + 10001, -1);
    fill(r, r + 10001, -1);
    fill(p, p + 10001, -1);

    while (true) {
        int tmp;
        cin >> tmp ;

        insert(tmp);
        if (cin.eof() == true)
            break;
    }

    traverse(l[ROOT]);
    return 0;
}




/*
cout << "V: ";
    for (int i = 0; i < sz; i++)
        cout << v[i] << '\t';
    cout << '\n';
    cout << "P: ";
    for (int i = 0; i < sz; i++)
        cout << p[i] << '\t';
    cout << '\n';
    cout << "L: ";
    for (int i = 0; i < sz; i++)
        cout << l[i] << '\t';
    cout << '\n';
    cout << "R: ";
    for (int i = 0; i < sz; i++)
        cout << r[i] << '\t';
    cout << '\n';

*/