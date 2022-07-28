#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class str_c {
    public:
        char c;
        str_c *l;
        str_c *r;
};

str_c *head;
str_c strArr[1000000];

string str;
string bomb;
int N;
int pos = 0;

void comp(str_c *ptr) {
    str_c *tmp = ptr;
    int cnt = 0;
    bool check = true;
    for (int i = 0; i < bomb.size(); i++) {
        if (tmp == NULL || tmp->c != bomb[i]) {
            check = false;
            break;
        }

        tmp = tmp->r;
    }

    if (check == true) {
        ptr->l->r = tmp;
        if (tmp != NULL)
            tmp->l = ptr;
        while (cnt < bomb.size() && ptr->l != NULL) {
            ptr = ptr->l;
            cnt++;
        }
    }
}

int main(void) {
    string str;

    cin >> str;
    cin >> bomb;
    N = str.size();

    memset(strArr, 0x00, sizeof(str_c) * 1000000);

    for (int i = 0; i < N; i++) {
        strArr[i].c = str[i];
        strArr[i].l = &strArr[i - 1];
        strArr[i].r = (i == N - 1) ? NULL : &strArr[i + 1];
    }

    head = new str_c;

    head->l = NULL;
    head->r = &strArr[0];
    strArr[0].l = head;

    str_c *ptr = &strArr[0];
    while (ptr != NULL) {
        comp(ptr);
        if (ptr == NULL) break;
        ptr = ptr->r;
    }

    int cnt = 0;
    ptr = head->r;
    while (ptr != NULL) {
        cout << ptr->c;
        ptr = ptr->r;
        cnt++;
    }
    if (cnt == 0) cout << "FRULA";
    cout << endl;

    return 0;
}