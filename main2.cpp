#include "vector.h"
#include <iostream>
#include <string>
using namespace std;

     void Count(Vector<int>& vec, int n)
         {
             vec.Clear();
             
             for(int i = 0; i < n; i++)
             {
                 vec.Insert(rand()%100+1); 
             }
        }

     void Reverse(Vector<int>& vec)
     {
        int x = vec.Size();
        int tmp;
        for(int i = 0; i < x/2; i++) 
        {
            tmp = vec[i];
            vec[i] = vec[(x-1)-i];
            vec[(x-1)-i] = tmp;
        }
     }


int main()
{
    srand(time(NULL));
    Vector<int> t;
    Count(t,10);
    cout << t << "\n";
    Reverse(t);
    cout << t << "\n";
    return 0;
    
}
