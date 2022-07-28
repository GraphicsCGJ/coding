#include<iostream>
#include<vector>
#include<string>

using namespace std;

int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};


char boggle[5][5];

bool has_word(int y, int x, const string& s) {
    /* bound */
    if (y >= 5 || y < 0 || x >= 5 || x < 0)
        return false;
    /* if word is not matched */
    if (s[0] != boggle[y][x])
        return false;

    if (s.length() == 1)
        return true;

    for (int i = 0; i < 8; i++) {
        if (has_word(y + dy[i], x + dx[i], s.substr(1)))
            return true;
    }
    return false;
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> boggle[i][j];
            }
        }

        int known_word;
        cin >> known_word;

        while(known_word--) {
            bool flag = false;
            string s, s2;
            cin >> s;
            for (int y = 0; y < 5 && !flag; y++)
                for (int x = 0; x < 5 && !flag; x++)
                    flag = has_word(y, x, s);

            s2 = flag ? "YES" : "NO";

            cout << s << " " << s2 << "\n";
        }
    }

    return 0;
}