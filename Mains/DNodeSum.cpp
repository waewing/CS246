#include <iostream>
#include <cmath>
#include "node.h"
using namespace std;

int Sum(DNode<int>* root)
{
    int sum;
    for(DNode<T>* tmp = head; tmp!=NULL; tmp = tmp->GetNext())
    {
        if(tmp = root)
        {
            sum = tmp->GetData();
        }
        else
        {
            sum = sum + tmp->GetData();
        }
    }
    return sum;
}