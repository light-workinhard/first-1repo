#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    cout << "Factorial of 6 : " << factorial(6) << endl;
    return 0;
}
