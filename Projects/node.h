#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Node
	{
	private:
		T data;
    Node<T>* link;
    Node<T>* child;
    Node<T>* sibling;
    
	public:
		Node() : Node(T(),NULL,NULL) {}

		Node(const T& data) : Node(data,NULL,NULL) {}

		Node(const T& data,Node<T>* child,Node<T>* sibling) : data(data),child(child),sibling(sibling) {}

		~Node() {}

    Node<T>* GetLink() {return link;}

		const Node<T>* GetLink() const {return link;}

		T& GetData() {return data;}

		const T& GetData() const {return data;}

    Node<T>*& GetChild() {return child;}

    const Node<T>* GetChild() const {return child;}

    Node<T>*& GetSibling() {return sibling;}

		const Node<T>* GetSibling() const {return sibling;}

    void SetLink(Node<T>* link) {this->link = link;}

		void SetData(const T& data) {this->data = data;}

    void SetChild(Node<T>* child) {this->child = child;}

    void SetSibling(Node<T>* sibling) {this->sibling = sibling;}

    void Clear(Node<T>*& link)
    {
      Node<T> *tmp;

      while(link != NULL)
      {
        tmp = link;
        link = link->GetLink();
        delete tmp;
        tmp = NULL;
      }
    }

		std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Node<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}			
#endif
