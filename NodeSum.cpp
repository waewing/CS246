#include <iostream>
#include <cmath>
#include "node.h"
using namespace std;

int Sum(Node<int>* root)
{
    int sum;
    for(Node<int>* tmp = head; tmp!=NULL; tmp = tmp->GetLink())
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

int main()
{
    
}