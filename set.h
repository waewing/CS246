 
#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
    template <class T>
    class Set
    {
        private:
            int size;
            int capacity;
            T* data;

            void Resize()
            {
                int oldCapacity = capacity;
                T* tmp = new T[oldCapacity];

                for(int i = 0; i < oldCapacity; i++)
                {
                    tmp[i]=data[i];
                }

                capacity *= 2;
                delete[] data;
                data = new T[capacity];

                for(int i = 0; i < oldCapacity; i++)
                {
                    data[i] = tmp[i];
                }
                delete[] tmp;
            }

        public:

            Set() : size(0), capacity(20)
            {
                data = new T[capacity];
            }

            Set(const Set<T>& obj)
            {
                size = obj.size;
                capacity = obj.capacity;
                data = new T[capacity];

                for(int i = 0; i < size; i++)
                {
                    data[i] = obj.data[i];
                }
            }

            Set<T>& operator=(const Set<T>& rhs)
            {
                if(this != &rhs)
                {
                    size = rhs.size;
                    capacity = rhs.capacity;
                    delete[] data;
                    data = new T[capacity];

                    for(int i = 0 ; i < size; i++)
                    {
                        data[i] = rhs.data[i];
                    }
                }
                return *this;
            }

            ~Set()
            {
                delete[] data;
            }

            bool Contain(const T& value)
            {
                for(int i = 0; i < size; i++)
                {
                    if(data[i] == value)
                    {
                        return true;
                    }
                }
                return false;
            }

            int Cardinality() const
            {
                return size;
            }

            bool IsEmpty() 
            {
                return (size==0);
            }

            void Add(const T& value)
            {
                if(!Contain(value))
                {
                    if(size = capacity)
                    {
                        Resize();
                    }
                    data[size] = value;
                    size++;
                }
            }

            void Remove(const T& value)
            {
                int i = 0;
                while(i < size && data[i] != value)
                {
                    i++;
                }
                if(i != size)
                {
                    size--;
                    for(i; i <size;i++)
                    {
                        data[i] = data[i+1];
                    }
                }
            }

            friend Set<T> Union(Set<T> & A,Set<T>& B);

            friend Set<T> Intersection(Set<T>& A, Set<T> B)
                {
                    Set<T> R;
                    if(A.Cardinality() < B.Cardinality())
                    {
                        R =  A;
                    }
                    else
                    {
                        R = B;
                    }

                        for(int i = 0; i<R.Cardinality(); i++)
                        {
                            if(!B.Contain(R.Data[i]))
                            {
                                Remove(R.Data[i]);
                                i--;
                            }
                        }
                    return R;
                }

            friend Set<T> Difference(Set<T> A, Set<T> B);

            friend bool Subset(Set<T> A, Set<T> B);

    };
}

#endif
