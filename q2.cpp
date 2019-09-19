#include "vector.h"
#include <iostream>
#include <string>
using namespace std;

double Range(Vector<double>& x)
{
    for(int i=0;i < x.length(); i++)
    {
        if(x[i] > x[i=1])
        {
            int tmp;
            tmp = x[i];
            x[i] = x[i+1];
            x[i=1] = tmp;
        }
    }

    if(x[i]-x[0] < 0)
    {
        return(x[i]-x[0]/-1);
    }
    else
    {
        return(x[i]-x[0]);
    }
}

int main
{
    double Vector arry[10];
    Range(arry);

return 0;
}