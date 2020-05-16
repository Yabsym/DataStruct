#pragma once
#pragma once
#include<vector>
#include"DataStructException.hpp"
#include"SeqTable.hpp"

namespace DataStruct {
	std::allocator<int> a;
	template<typename element>
	class node {
	public:
		node(element dat, node* prev, node* next) {
			this->dat = dat;
			this->prev = prev;
			this->next = next;
		}
		element dat;
		node* prev;
		node* next;

	};
	template<typename element>
	class LinkList
	{
	public:
		LinkList() noexcept {
			length = 0;
			tail = head = nullptr;
			return;
		}
		
		LinkList(const element& dat) {
			length = 0;
			tail = head = nullptr;
			append(dat);
		}
		
		void append(const element& dat) {
			if (head == nullptr) {
				this->head = static_cast<node<element>*>(malloc(sizeof(node<element>)));
				if (head == nullptr)
					throw DataStructException(1, "can not allocate memory space");
				this->head->prev = nullptr;//No loop
				this->head->next = nullptr;
				this->head->dat = dat;
				this->tail = this->head;
				length = 1;
			}
			else {
				node<element>* tmp = static_cast<node<element>*>(malloc(sizeof(node<element>)));
				if (tmp == nullptr)
					throw DataStructException(1, "can not allocate memory space");
				tmp->dat = dat;
				tmp->next = nullptr;
				tmp->prev = this->tail;
				this->tail->next = tmp;
				this->tail = tmp;
				++this->length;
			}
		}
		
		void insert(unsigned int pos, const element& dat) {
			node<element>* tmp;
			if (this->head == nullptr) {
				while (pos--)
					this->append(dat);
				return;
			}
			if (this->length < pos) {
				int dValue = pos - this->length;
				while (dValue--) {
					tmp = static_cast<node<element>*>(malloc(sizeof(node<element>)));
					if (tmp == nullptr)
						throw DataStructException(1, "can not allocate memory space");
					tmp->next = nullptr;
					tmp->dat = dat;
					tmp->prev = this->tail;
					this->tail = tmp;
					++this->length;
				}
				return;
			}
			if (pos > this->length / 2) {//
				tmp = this->tail;
				for (int i = this->length - pos; i > 0; --i)
					tmp = tmp->prev;
			}
			else {
				tmp = this->head;
				while (pos--)
					tmp = tmp->next;
			}
			if (tmp == this->head) {
				node<element>* newNode = static_cast<node<element>*>(malloc(sizeof(node<element>)));
				if (newNode == nullptr)
					throw DataStructException(1, "can not allocate memory space");
				newNode->next = this->head;
				newNode->prev = nullptr;
				newNode->dat = dat;
				this->head = newNode;
				if (this->head != nullptr)
					this->head->prev = newNode;
				++this->length;
				return;
			}
			if (tmp == this->tail) {
				append(dat);
				return;
			}
			node<element>* pre = tmp->prev;
			pre->next = static_cast<node<element>*>(malloc(sizeof(node<element>)));
			if (pre->next == nullptr)
				throw DataStructException(1, "can not allocate memory space");
			pre->next->next = tmp;
			pre->next->prev = tmp->prev;
			tmp->prev = pre->next;
			pre->next->dat = dat;
			return;
		}
		
		void del(unsigned int pos) {
			node<element>* tmp = this->head;
			if (head == nullptr)
				throw DataStructException(1, "link list is empty");
			if (pos <0 || pos>this->length)
				throw DataStructException(1, "error position");
			if (pos > this->length / 2) {//
				tmp = this->tail;
				for (int i = this->length - pos; i > 0; --i)
					tmp = tmp->prev;
			}
			else {
				tmp = this->head;
				while (pos--)
					tmp = tmp->next;
			}
			if (tmp == this->head)
				this->head = tmp->next;
			else if (tmp == this->tail)
				this->tail = tmp->prev;
			else {
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			free(tmp);
		}

		void clear() {
			node<element>* tmp = head;
			while (length-- && tmp) {
				tmp = tmp->next;
				free(head);
				head = tmp;
			}
			this->length = 0;
			this->head = nullptr;
			this->tail = nullptr;
		}

		inline const unsigned int size() const noexcept {
			return this->length;
		}
		/*
		LinkList<element>& operator=(const SeqTable<element>& dat) {
			this->clear();
			int size = dat.size();
			for (int i = 0; i < size; ++i)
#ifdef UNKNOW_ERROR
				this->append(dat[i]);
#else
				this->append(dat.getArray()[i]);
#endif 
			return *this;
		}
		*/
		element& operator[](const int pos) {
			return getElem(pos);
		}
		
		inline element& back(void) {
			if (this->tail == nullptr)
				throw DataStructException(0, "over array");
			return this->tail->dat;
		}

		void delete_back(void) {
			if (this->tail == nullptr)
				return;
			else if (this->tail->prev == nullptr)
				delete this->tail;//only one
			else {
				node<element>* tmp = this->tail;
				this->tail = this->tail->prev;
				this->tail->next = nullptr;
				std::free(tmp);
			}
			return;
		}

		~LinkList() {
			this->clear();
		}
	protected:
		element& getElem(unsigned int pos) {
			node<element>* tmp = this->head;
			if (head == nullptr)
				throw DataStructException(1, "link list is empty");
			if (pos <0 || pos>=this->length)
				throw DataStructException(1, "error position");
			if (pos > this->length / 2) {//
				tmp = this->tail;
				for (int i = this->length - pos; i > 0; --i)
					tmp = tmp->prev;
			}
			else {
				tmp = this->head;
				while (pos--)
					tmp = tmp->next;
			}
			return tmp->dat;
		}
	private:
		node<element>* head;
		node<element>* tail;
		unsigned int length;
	};

}