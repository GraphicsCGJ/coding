#include <iostream>
#include <cmath>

using namespace std;

class input {
    public:
        /* variables */
        int n;

        /* method */
        void get() {
            cin >> this->n;
        }

        int calc() {
            int mul = 1;
            int digit = 0;
            int tmp1 = n;
            int result = 0;

            while (tmp1 > 0) {
                digit++;
                tmp1 /= 10;

                // cout << "digit: " << digit << endl;
            }

            for (int i = 1; i <= digit; i++) {
                int added = 0;
                if (i < digit) {
                    added = (int)pow(10, i) * i - (int)pow(10, i-1) * (i);
                }
                else {
                    tmp1 = n - (int)pow(10, i - 1) + 1;
                    // printf("tmp1: %d\n", tmp1);
                    added = tmp1 * digit;
                }

                result += added;
                // printf("result: %d , added: %d\n", result, added);
            }

            return result;
        }

};

int main(void) {
    input in;
    in.get();
    cout << in.calc() << endl;
    return 0;
}