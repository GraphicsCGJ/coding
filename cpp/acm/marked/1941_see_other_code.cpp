#include <iostream>
#include <set>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class pp {
    public:
        int i;
        int j;
        char c;
        bool operator==(const pp &p2) {
            return (this->i == p2.i && this->j == p2.j);
        }

        bool operator<(const pp& p2) const {
            if (this->i < p2.i)
                return true;
            else if (this->i > p2.i)
                return false;
            else {
                if (this->j < p2.j)
                    return true;
                return false;
            }
        }
};

int cnt = 0;
char field[5][5];

void recur(set<pp> &visited, set<pp> &excepted) {
    // exception
    // for (pp pi : visited) {
    //     cout << pi.i << ":" << pi.j << " ";
    // }
    // cout << endl << "E:   ";
    // for (pp pi : excepted) {
    //     cout << pi.i << ":" << pi.j << " ";
    // }
    // cout << endl;
    set<pp> excepted_local = excepted;
    int ycnt = 0;

    for (pp pi : visited)
        ycnt += (pi.c == 'Y' ? 1 : 0);
    if (ycnt >= 4) return;

    // end
    if (visited.size() == 7) {
        cnt++;
        // for (pp pi : visited) {
        //     cout << pi.i << ":" << pi.j << " ";
        // }
        // cout << endl;
        return;
    }

    // find
    for (pp pi : visited) {
        for (int i = 0; i < 4; i++) {
            int ni = pi.i + dx[i];
            int nj = pi.j + dy[i];

            if (ni < 0 || ni >= 5 || nj < 0 || nj >= 5)
                continue;

            // cout << ni << ":" << nj << endl;
            pp pn;
            pn.i = ni;
            pn.j = nj;
            pn.c = field[ni][nj];

            if ((excepted_local.find(pn) == excepted_local.end()) && (visited.find(pn) == visited.end())) {
                visited.insert(pn);
                recur(visited, excepted_local);
                visited.erase(pn);
                excepted_local.insert(pn);
            }
        }
    }
}

int main(void) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> field[i][j];
        }
    }

    set<pp> visited;
    set<pp> excepted;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            pp p;
            p.i = i;
            p.j = j;
            p.c = field[i][j];

            visited.insert(p);
            recur(visited, excepted);
            visited.erase(p);
            excepted.insert(p);
        }
    }

    cout << cnt << endl;


    return 0;
}