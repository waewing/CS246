#include <iostream>
#include <cstdlib>
#include <string>
#include "linkedlist.h"
using namespace std;


template <class T>
void InsertionSort(T data[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0 && data[j] < data[j-1])
        {
            T tmp = data[j];
            data[j] = data [j-1];
            data[j-1] = tmp;
        }
    }
}

template<class T>
void SelectionSort(T data[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int m = i;
        for(int j = i+1; j < n; j++)
        {
            if (data[m] > data[j])
            {
                m = j;
            }
        }
        if(m != i)
        {
            T tmp = data[i];
            data[i] = data[m];
            data[m] = tmp;
        }
    }
}

template<class T>
void BubbleSort(T data[], int n)
{
    for(int i = n-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if (data[j] > data[j+1])
            {
                T tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}

int main()
{
    LinkedList<int> list;
    srand(time(NULL));
    int n = 5 + rand()%26;
    for(int i = 0; i < n; i++)
    {
        list.InsertInBack(rand()%1000+1);
    }
    
    SIterator<int>* iter = list.GetIterator();
    while(iter->HasNext())
    {
        cout << Next() << "\n";
    }

    return 0;
}
