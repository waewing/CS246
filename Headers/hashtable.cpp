#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "node.h"
using namespace std;
using namespace ds;


class HashTable
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

        void Insert(int value)
        {
            int index = hash(value);
            if(data[index] == NULL)
            {
                data[index] = new Node<int>(value);
            }
            else
            {
                Node<int>* tmp = new Node<int>(value);
                tmp->SetLink(data[index]);
                data[index] = tmp;
            }
        }

        bool Search(int value)
        {
            int index = hash(value);
            for(Node<int>* tmp = data[index]; tmp!=NULL;tmp=tmp->GetLink())
            {
                if(tmp->GetData() == value)
                {
                    return true;
                }
            }
            return false;
        }

        void Remove(int value)
        {
            int index = hash(value);
            Node<int>* prev=NULL;
            Node<int>* tmp=data[index];
            while(tmp!=NULL && tmp->GetData()!= value)
            {
                prev = tmp;
                tmp = tmp->GetLink();
            }
            if(tmp!= NULL)
            {
                prev->SetLink(tmp->GetLink());
                delete tmp;
                tmp = NULL;
            }
        }

        bool IsEmpty(int value)
        {
            return data[hash(value)] == NULL;
        }
};

void RandomValues(int data[], int n,int l,int h)
{
    int max = (l<h)?(h):(l);
    int min = l+h-max;
    srand(time(NULL));
    for(int i=0 ; i<n; i+=1)
    {
        data[i] = min+rand()%(max-min+1);
    }
}

bool SumMultiple(int a[],int n)
{
    HashTable table;
    for(int i=0;i<n;i+=1)
    {
        if(table.IsEmpty(28-a[i]%28))
        {
            return true;
        }
        else
        {
            table.Insert(a[i]);
        }
    }
    return false;
}

void Print(int data[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Index " << i << " [" << data[i] << "]\n";
    }
}


int main()
{

 int arr[100];
 RandomValues(arr,100,0,100);
 Print(arr,100);
 cout << SumMultiple(arr,100) << "\n";

 

 return 0;

}