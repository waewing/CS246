#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <sstream>
#include <string>

template <class T>
class Vector
    {
        private:
    
            T* data; // dynamic array
            int size;
            int capacity; // represnets the current maximum size of our array
            void Resize()
                {

                    T* tmp=new T[capacity];
                    for(int i=0; i<capacity ;i++)
                    {
                        tmp[i] = data[i];
                    }

                    delete[] data;

                    capacity = capacity*2;
                    data = new T[capacity];
                    for(int i=0; i<size ; i++)
                    {
                        data[i] = tmp[i];
                    }

                    delete[]tmp;
                }
        public:

          Vector()
            {
                size = 0;
                capacity = 10;
                data = new T[capacity];
                for(int i=0; i < capacity; i++)
                {
                    data[i] = T();
                }
            }

          Vector(const Vector<T>& obj)
            {
                size = obj.size;
                capacity = obj.capacity;
                data = new T[capacity];
                for(int i=0; i<capacity; i++)
                {
                        data[i] = obj.data[i]; // example of a deep copy where all elements are copied
                }
            }   

         Vector<T>& operator=(const Vector<T>& rhs)
            {
                if(this != &rhs)
                {
                size = rhs.size;
                capacity = rhs.capacity;
                delete[] data; // if not deleted a memory leak will occur
                data = new T[capacity];
                for (int i = 0; i<size; i++)
                {
                    data[i] = rhs.data[i]; // overloaded assignement operator
                }
                }
                return *this;
            }
            
         ~Vector()
            {
                delete[] data;
            }

         std::string ToString() const
            {
                std::stringstream out;
                out << "[ ";
                for(int i = 0; i < size; i++)
                {
                    out << data[i];
                    if(i != size-1)
                    {
                        out << ", ";
                    }
                }
                out << "] ";
                return out.str();
            }

         friend std::ostream& operator<<(std::ostream& out, const Vector<T>& obj)
            {
             out << obj.ToString();
             return out;
            }

         void Insert(const T& value)
            {
             if(size = capacity)
             {
                 Resize();
             }
             data[size]=value;
             size++;
            }

         void Remove()
            {
             if(size < 0)
             {
                 size--;
             }
            }

        T& operator[](int index)
            {
             if(index <= 0 && index < size)
             {
                return data[index];
             }
             throw "Out of Bounds";
            }
        
        const T& operator[](int index)
            {
             if(index <= 0 && index < size)
             {
                return data[index];
             }
             throw "Out of Bounds";
            }

         bool IsEmpty() const
            {
                return size = 0;
            }   
         
         int Size() const
            {
                return size;
            }
        
         int Capacity() const
            {
                return capacity;
            }

         void Clear()
            {
                for(int i = 0; i < capacity; i++)
                {
                    data[i] = T();
                }
                size = 0;
            }

         void Fill(const T& value, int n)
            {
                Clear();
                for(int i = 0; int < n; i++)
                {
                    Insert(value);
                }
            }         

         
};

#endif