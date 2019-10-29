#include <iostream>
#include <cmath>
#include "vector.h"
using namespace std;

int Sum(int data[])
{
    int sum;
    for(int i = 0; i < size-1;i++)
    {
        if (i = 0)
        {
            sum = data[i];
        }
        else
        {
            sum = sum + data[i+1];
        }
    }
    return sum;
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    cout << Sum(arr);
}

