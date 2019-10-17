#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "queue.h"
using namespace std;
using namespace ds;

void CountToNBinary(int n)
{
    Queue <string> q;
    string val;
    string binary[2] = {"0","1"};
    if (n>=1)
    {
        cout << "1\n";
    }
    q.Enqueue("1");

    for(int i = 2; i <= n; i++)
    {
        val = q.Peek();
        val += binary[i%2];
        cout << val << "\n";
        q.Enqueue(val);
        if(i%2 == 1)
        {
            q.Dequeue();
        }
    }
} 
int main()
{
    CountToNBinary(100);
    return 0;
}


