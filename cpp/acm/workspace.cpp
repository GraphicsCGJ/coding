#include<iostream>
#include<string>

using namespace std;

string s;
int lvl = 0;
int p = 0;

class C1 {
public:
    C1() = default;
    char op;
    C1* l;
    C1* r;
};

C1 makeTree() {
    int curlvl = lvl;
    C1 c1;

    while (p < s.length()) {
        char c = s[p];

        if (c == '(') {
            p++;
            C1 c2 = makeTree();
        }
        else if (c == ')') {
            return c1;
        }
        else if (c ==   )

        p++;
    }

    return c1;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> s;

    return 0;
}