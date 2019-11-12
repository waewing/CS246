#include <iostream>
using namespace std;

int T(int n)
{
    if(n < 1)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return T(n-1)+2*n+1;
    }
}

int main()
{
    for(int i = 0; i < 11; i++)
        {
            cout<< "T(" << i << ") = " << T(i) << "\n";
        }

    return 0;
}
    