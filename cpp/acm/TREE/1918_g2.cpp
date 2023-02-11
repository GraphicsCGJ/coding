#include<iostream>
#include<string>

using namespace std;

string s;
int lvl = 0;
int p = 0;

class C1 {
public:
    C1() = default;
    bool nomore;
    char op;
    C1* l;
    C1* r;
};

void postorder(C1* root) {

    if (root->l)
        postorder(root->l);
    if (root->r)
        postorder(root->r);
    cout << root->op;
}

C1* makeTree() {
    int curlvl = lvl;
    C1* root = NULL;

    while (p < s.length()) {
        char c = s[p];
        switch (c) {
            case '(': {
                p++;
                C1* new_root = makeTree();
                new_root->nomore = true;
                if (root == NULL)
                    root = new_root;
                else {
                    C1* c2 = root;
                    while (c2->r != NULL) {
                        c2 = c2->r;
                    }
                    c2->r = new_root;
                }
                break;
            }
            case ')': {
                return root;
                break;
            }
            case '+':
            case '-':
            {
                C1* c3 = new C1();
                c3->op = c;
                c3->l = root;
                root = c3;
                break;
            }
            case '*':
            case '/':
                if (root == NULL) {
                    root = new C1();
                    root->op = c;
                    root->nomore = true;
                }
                else {
                    C1* c1 = NULL;
                    C1* c2 = root;
                    while (c2->r != NULL) {
                        if (c2->nomore == true) break;
                        c1 = c2;
                        c2 = c2->r;
                    }
                    C1* c3 = new C1();
                    c3->op = c;
                    c3->nomore = true;

                    c3->l = c2;
                    if (c1 == NULL)
                        root = c3;
                    else
                        c1->r = c3;
                }
                break;
            default: {
                if (root == NULL) {
                    root = new C1();
                    root->op = c;
                }
                else {
                    C1* c2 = root;
                    while (c2->r != NULL) {
                        c2 = c2->r;
                    }
                    C1* c3 = new C1();
                    c3->op = c;
                    c2->r = c3;
                }
                break;
            }
        }
        p++;
        // postorder(root);
        // cout << '\n';
    }

    return root;
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> s;

    C1* res = makeTree();
    // cout << res->op << '\n';
    postorder(res);

    return 0;
}