#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <sstream>
#include "Pair.h"

namespace ds
{
	template <class K,class V>
	class Map
	{
	private:
		Pair<K,V>* data;
		int size;
		int capacity;

		void Resize(int value) 
		{
			if(value > 0)
			{
				int minimum = (capacity < value)?(capacity):(value);
				Pair<K,V>* tmp = new Pair<K,V>[minimum];

				for(int i = 0;i < minimum;i += 1)
				{
					tmp[i] = data[i];
				}

				delete[] data;
				capacity = value;
				data = new Pair<K,V>[capacity];

				for(int i = 0;i < minimum;i += 1)
				{
					data[i] = tmp[i];
				}

				delete[] tmp;
			}
		}
	public:
		Map() : Map(10) {}
	
		Map(int n) : capacity(n), size(0)
		{
			if(capacity <= 0)
			{
				capacity = 0;
			}
			
			data = new Pair<K,V>[capacity];
		}
	
		Map(const Map<K,V>& obj)
		{
			size = obj.size;
			capacity = obj.size;
			data = new Pair<K,V>[capacity];

			for(int i = 0;i < size;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Map<K,V>& operator=(const Map<K,V>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				capacity = rhs.size;
				delete[] data;
				data = new Pair<K,V>[capacity];

				for(int i = 0;i < size;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}

			return *this;
		}

		~Map() {delete[] data;}

		int Length() const {return size;}

		int Capacity() const {return capacity;}

		bool IsEmpty() const {return (size == 0);}

		V& operator[](const K& key) 
		{
			for(int i = 0;i < size;i += 1)
			{
				if(key == data[i].GetKey())
				{
					return data[i].GetValue();
				}
			}
			throw "Invalid Key";
		}

		const V& operator[](const K& key) const 
		{
			for(int i = 0;i < size;i += 1)
			{
				if(key == data[i].GetKey())
				{
					return data[i].GetValue();
				}
			}
			throw "Invalid Key";
		}

		V& Get(const K& key) 
		{
			for(int i = 0;i < size;i += 1)
			{
				if(key == data[i].GetKey())
				{
					return data[i].GetValue();
				}
			}
			throw "Invalid Key";
		}

		const V& Get(const K& key) const 
		{
			for(int i = 0;i < size;i += 1)
			{
				if(key == data[i].GetKey())
				{
					return data[i].GetValue();
				}
			}
			throw "Invalid Key";
		}

		bool HasKey(const K& key)
		{
			for(int i = 0;i < size;i += 1)
			{
				if(data[i].GetKey() == key)
				{
					return true;
				}
			}
			return false;
		}

		void Put(const K& key,const V& value)
		{
			if(!HasKey(key))
			{
				if(size == capacity)
				{
					Resize(capacity * 2);
				}
			}
			
			data[size] = Pair<K,V>(key,value);
			size += 1;
		}

		void Remove(const K& key)
		{
			if(HasKey(key) && size > 0)
			{
				int i = 0;
				
				while(data[i].GetKey() != key)
				{
					i += 1;
				}
				size -= 1;
				
				for(int i;i < size;i += 1)
				{
					data[i] = data[i+1];
				}
			}
		}

		void Optimize()
		{
			Resize(size);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(int i = 0;i < size;i += 1)
			{
				out << data[i];

				if(i + 1 < size)
				{
					out << ",";
				}
			}

			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Map<K,V>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif