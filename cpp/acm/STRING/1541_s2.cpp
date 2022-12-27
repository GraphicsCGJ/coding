#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getSum(string s) {
    string token = "+";
    size_t pos = 0;

    int value = 0;
    while ((pos = s.find(token)) != string::npos) {
        value += stoi(s.substr(0, pos));
        s.erase(0, pos + token.length());
    }

    value += stoi(s);

    return value;
}

int main(void) {
    string s;
    string token = "-";
    cin >> s;

    size_t pos = 0;
    int globalSum = 0;
    bool isFirst = true;
    while ((pos = s.find(token)) != string::npos) {
        int localSum = getSum(s.substr(0, pos));

        globalSum += (isFirst == true ? localSum : -localSum);
        isFirst = false;
        s.erase(0, pos + token.length());
    }

    int localSum = getSum(s);
    globalSum += (isFirst == true ? localSum : -localSum);
    cout << globalSum << endl;

    return 0;
}
