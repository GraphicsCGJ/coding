#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class op_c {
    public:
        int *a;
        int *b;
        char op;
        bool done;

        op_c(int *a, int *b, char op) {
            this->a = a;
            this->b = b;
            this->op = op;

            done = false;
        }

        int job() {
            switch (op)
            {
            case '+':
                return *a + *b;
                break;
            case '-':
                return *a + *b;
                break;
            case '*':
                return *a * *b;
                break;
            default:
                return -1;
                break;
            }
        }

        void setDone() {
            this->done = true;
        }

};

vector<int> storage;
vector <char> storage2;
vector<op_c> opes;
vector<int> permutations;

int main(void) {
    int n;
    char op = '/';

    cin >> n;



    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int tmp;
            cin >> tmp;
            storage.push_back(tmp);
        }
        else {
            char tmp;
            cin >> tmp;
            storage2.push_back(tmp);
        }
    }

    for (int i = 0; i < storage2.size(); i++) {
        permutations.push_back(i);
    }

    do {
        opes.clear();
        vector<int> storage_tmp = storage;
        vector<char> storage2_tmp = storage2;

        for (int i = 0; i < storage2_tmp.size(); i++) {
            opes.push_back(op_c(&storage_tmp[i], &storage_tmp[i+1], storage2_tmp[i]));
        }

        // for (auto &vi : opes) {
        //     cout << *vi.a << vi.op << *vi.b << endl;
        // }

        // for (auto &i : permutations) {
        for (int i = 0; i < permutations.size(); i++) {
            int ii = permutations[i];
            int value = opes[ii].job();
            *opes[ii].a = value;
            *opes[ii].b = value;
            opes[ii].b = opes[ii].a;
            if (ii - 1 >= 0)
                opes[ii - 1].b = opes[ii].a;
            if (ii + 1 < opes.size())
                opes[ii + 1].a = opes[ii].a;
        }

        for (auto &vi : opes) {
            cout << *vi.a << vi.op << *vi.b << endl;
        }
        cout << endl;

        break;

    } while (next_permutation(permutations.begin(), permutations.end()));

    return 0;
}