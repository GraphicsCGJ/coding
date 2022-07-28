#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int health;
int people_max;

class ca {
    public:
        int attack;
        int people;
};

ca* ca_arr;

void backtracking(vector<int> &ca_stack, int health_local) {
    bool has_no_path = true;
    for (int i = 0; i < N; i++) {
        if (find(ca_stack.begin(), ca_stack.end(), i) == ca_stack.end()) {

            int ca_stack_attack = 0;
            for (int vi : ca_stack)
                ca_stack_attack += ca_arr[vi].attack;

            ca_stack_attack += ca_arr[i].attack;

            if (health_local - ca_stack_attack < 0)
                continue;
            has_no_path = false;

            ca_stack.push_back(i);
            health_local -= ca_stack_attack;
            backtracking(ca_stack, health_local);
            health_local += ca_stack_attack;
            ca_stack.pop_back();
        }
    }

    if (has_no_path) {
        int people_localmax = 0;
        for (int vi : ca_stack)
            people_localmax += ca_arr[vi].people;

        if (people_max < people_localmax)
            people_max = people_localmax;
    }

    return;
}

int main(void) {
    cin >> N >> health;
    ca_arr = new ca[N];

    people_max = 0;

    for (int i = 0; i < N; i++)
        cin >> ca_arr[i].attack;

    for (int i = 0; i < N; i++)
        cin >> ca_arr[i].people;

    vector<int> v;
    v.reserve(N);
    backtracking(v, health);

    cout << people_max << endl;

    return 0;
}