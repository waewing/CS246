#include <iostream>
#include <string>
#include <cstdlib>
#include "node.h"
using namespace std;


class Hashtable
{
    private:

        Node<int>* data[28];
        
        int hash(int n)
        {
            return n%28;
        }
    
    public:

        HashTable()
        {
            for(int i=0;i<28;i+=1)
            {
                data[i] = NULL;
            }
        }

        ~HashTable()
        {
            for(int i=0;i<28;i+=1)
            {
                Clear(data[i]);
            }
        }

};