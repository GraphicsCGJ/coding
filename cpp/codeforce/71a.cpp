#include <iostream>
#include <string>

using namespace std;


int N;

int main(void) {
    cin >> N;
    while (N--) {
        string str;
        cin >> str;

        if (str.size() > 10) {
            string str2;
            str2 = str[0];
            str2 += to_string(str.size() - 2);
            str2 += str[str.size() - 1];
            cout << str2 << endl;
        }
        else {
        cout << str << endl;

        }
    }
    return 0;
}