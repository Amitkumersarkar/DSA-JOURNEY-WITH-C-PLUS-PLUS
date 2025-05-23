#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    cout << "Ackermann(2, 2): " << ackermann(2, 2) << endl;
    return 0;
}
