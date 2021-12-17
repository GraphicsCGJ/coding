#include <iostream>
#include<vector>

using namespace std;

int used;

void get_val(int *cur_val, int& used) {

}

int main(void) {
    int used_bit = 1;
    int final_val[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int cur_val[10] {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (true) {
        bool flag = true;
        for (int i = 0; i < 10; i++) {
            if (final_val[i] != cur_val[i]) {
                flag = false;
                break;
            }
        }
        if (flag == true)
            break;

        /* 1. check cur_val is descending number. */
        for (int i = 1; i < used_bit; i++) {

        }

        v.push_back()
    }


    return 0;
}