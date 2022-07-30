#include <iostream>
#include <vector>

using namespace std;

class dot_c {
    public:
    int x;
    int y;
};

int N;
int maxArea;
vector<dot_c> v_in;


int calcArea(dot_c a, dot_c b, dot_c c) {
    int tmp = a.x*b.y + b.x*c.y + c.x*a.y;
    tmp -= a.x*c.y + b.x*a.y + c.x*b.y;

    if (tmp < 0) tmp = -tmp;

    return tmp;
}

void combination (int depth, int start, vector<dot_c> v) {
    if (depth == 3) {
        int localArea = calcArea(v[0], v[1], v[2]);
        if (maxArea < localArea)
            maxArea = localArea;
        return;
    }

    for (int i = start; i < v_in.size(); i++) {
        v.push_back(v_in[i]);
        combination(depth + 1, i + 1, v);
        v.pop_back();
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        dot_c d;
        cin >> d.x >> d.y;

        v_in.push_back(d);
    }

    vector<dot_c> v;
    maxArea = 0;

    combination(0, 0, v);

    if (maxArea % 2 == 1)
        cout << maxArea / 2 << ".5" << endl;
    else
        cout << maxArea / 2 << endl;

    return 0;
}