#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bnode.h"
using namespace ds;

int main()
{
    BNode <int>* root;

    int arr[]={3,10,21,30,4,1,9,2};
    for(int i = 0;i < 8;i++)
    {
        Insert(root,arr[i]);
    }

    infix(root);
}