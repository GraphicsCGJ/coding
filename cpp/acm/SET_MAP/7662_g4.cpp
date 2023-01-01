#include <iostream>
#include <set>

using namespace std;

int T;
int N;

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    while (T--) {
        multiset<int> s1;

        cin >> N;

        while(N--) {
            char command;
            int value;
            cin >> command >> value;

            switch (command)
            {
                case 'I':
                    s1.emplace(value);

                    // cout << "I: " << value << endl;
                    break;

                default:
                    if (s1.size() == 0)
                        continue;
                    else {
                        if (value == 1) {
                            auto iter = s1.end();
                            iter--;
                            // cout << "D: " << *iter << endl;

                            s1.erase(iter);
                        }
                        else {
                            auto iter = (s1.begin());

                            // cout << "D: " << *iter << endl;
                            s1.erase(iter);
                        }
                    }
                    break;
            }

        }

        if (s1.size() == 0) {
            cout << "EMPTY\n";
        }
        else {
            auto iter = s1.end();
            iter--;
            cout << *iter << " " <<  *(s1.begin()) << "\n";
        }

    }

    return 0;
}




// #include <iostream>

// using namespace std;

// int T, N;

// class C1 {
// public:
//     int value;
//     int idx1;
//     int idx2;
// };

// C1* pq1[1000000];
// C1* pq2[1000000];
// C1 data[1000000];

// int qsize1, qsize2, dataSize;

// int main(void) {
//     cin.tie(0);
//     ios_base::sync_with_stdio(0);

//     cin >> T;

//     while (T--) {
//         cin >> N;
//         qsize1 = 0;
//         qsize1 = 0;
//         dataSize = 0;

//         for (int i = 0; i < N; i++) {
//             char c;
//             int tmp;
//             cin >> c >> tmp;

//             C1 c1;
//             c1.value = tmp;

//             switch (c) {
//                 case 'I': {

//                     break;
//                 }
//                 case 'D': {

//                     break;
//                 }
//                 default:
//                     break;
//             }
//         }
//     }

//     return 0;
// }