#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


template <class T>
int Partition(T data[], int start, int end)
    {
        T pivot = data[end];
        int pindex = start-1;
        for(int i = start; i < end; i += 1)
        {
            if(data[i] < pivot)
            {
                pindex += 1;
                T tmp = data[i];
                data[i] = data[pindex];
                data[pindex] = tmp;
            }
        }

        pindex += 1;
        T tmp = data[end];
        data[end] = data[pindex];
        data[pindex] = tmp;
        return pindex;
    }

template <class T>
void QuickSort(T data[], int start, int end)
    {
        if(start < end)
        {
            int r = Partition(data,start,end);
            QuickSort(data,start,r-1);
            QuickSort(data,r+1,end);
        }


    }

void RandomValue(int data[], int n)
{
    srand(time(NULL));
    for(int i=0 ; i<n; i+=1)
    {
        data[i] = rand()%100+1;
    }
}

void Print(int data[],int n)
{
    cout << "[";
    for(int i = 0; i < n ; i+=1 )
    {
        cout << data[i];
        if(i+1 != n)
        {
            cout << ",";
        }
    }
    cout << "]";
}


int main()
{
    int data[10];
    RandomValue(data,10);
    Print(data,10);
    cout << "\n";
    Partition(data,0,9);
    Print(data,10);
    cout << "\n";
    QuickSort(data,0,9);
    Print(data,10);
    cout << "\n";

return 0;
}