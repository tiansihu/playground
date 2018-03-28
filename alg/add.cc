#include <iostream>

using namespace std;

int add(int a, int b) {
    int s = a ^ b;
    int c = a & b;

    if (c != 0) {
        s = add(s, c << 1);
    }

    return s;
}


int main() {
    cout << add(1024, 87993235) << endl;
    return 0;
}

