#pragma once
#include"LinkList.hpp"
namespace DataStruct {
	template<typename element>
	class stack :private LinkList<element> {
	public:
		stack() noexcept {

		}
		void push(const element& dat) {
			this->append(dat);
		}
		element pop(void) {
			element tmp = this->back();
			this->delete_back();
			return tmp;
		}
		inline unsigned int stack_size(void) const noexcept {
			return this->size();
		}
		inline void stack_clear(void) {
			this->clear();
		}
	};
}