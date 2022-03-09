#include <iostream>

using namespace std;

class problem {
    public:
        int x;
        int y;
        int knx;
        int kny;
        int kx;
        int ky;
        int cnt;

        problem() {
            x = 0;
            y = 0;
            kx = 0;
            ky = 0;
            knx = 0;
            kny = 0;
            cnt = 0;
        }

        void input() {
            cin >> x;
            cin >> y;

            kx = x - x;
            ky = y - x;

            knx = 0;
            kny = 0;
        }

        void calc() {

        }
};

int main(void) {
    /*
        difference 를 구하고

    */
    return 0;
}