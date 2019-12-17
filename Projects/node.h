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

		
    Node(const Node<T>& obj)
		{
			data = obj.data;
			link = Copy(obj.link);
      child = Copy(obj.child);
      sibling = Copy(obj.sibling);
		}

    Node<T>& operator=(const Node<T>& rhs)
		{
			if(this != &rhs)
			{
				data = rhs.data;
				Clear(link);
				link = Copy(rhs.link);
        Clear(child);
				child = Copy(rhs.child);
        Clear(sibling);
				sibling = Copy(rhs.sibling);
			}

			return *this;			
		}
    
	public:
		Node() : Node(T(),NULL,NULL,NULL) {}

		Node(const T& data) : Node(data,NULL,NULL,NULL) {}

		Node(const T& data,Node<T>* link,Node<T>* child,Node<T>* sibling) : data(data), link(link),child(child),sibling(sibling) {}

		~Node() {}
	
		T& GetData() {return data;}

		const T& GetData() const {return data;}

		Node<T>* GetLink() {return link;}

    const Node<T>* GetLink() const {return link;}

    Node<T>* GetChild() {return child;}

    const Node<T>* GetChild() const {return child;}

    Node<T>* GetSibling() {return sibling;}

		const Node<T>* GetSibling() const {return sibling;}

		void SetData(const T& data) {this->data = data;}

		void SetLink(Node<T>* link) {this->link = link;}

    void SetChild(Node<T>* child) {this->child = child;}

    void SetSibling(Node<T>* sibling) {this->sibling = sibling;}

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

	template<typename T>
	void Clear(Node<T>*& root)
	{
		Node<T> *tmp;

		while(root != NULL)
		{
			tmp = root;
			root = root->GetLink();
			delete tmp;
			tmp = NULL;
		}
	}

	template<typename T>
	Node<T>* Copy(Node<T>* root)
	{
		if(root == NULL)
		{
			return NULL;
		}
		
		Node<T> *head = new Node<T>(root->GetDate());
		Node<T> *tmp2 = head;
		Node<T> *tmp1 = root->GetLink();

		while(tmp1 != NULL)
		{
			tmp2->SetLink(new Node<T>(tmp1->GetData()));
			tmp1 = tmp1->GetLink();
			tmp2 = tmp2->GetLink();
		}

		return head;
	}

}			
#endif
