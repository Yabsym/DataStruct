#pragma once
#include"LinkList.hpp"
namespace DataStruct {
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
	class queue :private SeqTable<element> {
	public:
		queue() {

		}
		element pop() {
			element dat = this->getElem(0);
			this->del(0);
			return dat;
		}
		element readDat() {
			return this->getElem(0);
		}
		void push(const element& dat) {
			this->append(dat);
		}
		inline unsigned int queue_size(void) const noexcept {
			return this->size();
		}
		inline void queue_clear(void) {
			this->clear();
		}
		bool isEmpty(void) const noexcept{
			return this->size() <= 0 ? true : false;
		}
	};

	template<typename element>
	class priority_queue :private LinkList<element> {

	};
}