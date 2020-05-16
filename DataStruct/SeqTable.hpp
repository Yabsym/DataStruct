#pragma once
#include"DataStructException.hpp"
#include"LinkList.hpp"
#include<cmath>

namespace DataStruct {
	template<typename element>
	class SeqTable
	{
	public:
		SeqTable() {//initialize all members
			this->initSeq();
		}
		SeqTable(const element& dat) {
			this->initSeq();
			this->append(dat);
		}
		void append(const element& dat) {
			while (this->datSize <= isUse)
				resize(this->datSize * 2);
			this->dat[this->isUse++] = dat;
		}
		void del(const unsigned int index) {
			if (index < 0 || index >= this->datSize)
				throw DataStructException(2, "the index is error");
			for (unsigned int i = index + 1; i < isUse; ++i)
				this->dat[i - 1] = this->dat[i];//mov dat
			--this->isUse;
		}
		void insert(const unsigned int index, const element& dat) {
			if (index < 0)
				throw DataStructException(2, "the index is error");
			while (this->isUse >= this->datSize || index > this->datSize)
				this->resize(this->datSize < index ? index : this->datSize * 2);
			unsigned int i = this->isUse;
			for (; i >= index; --i)
				this->dat[i] = this->dat[i - 1];
			this->dat[i] = dat;
			++this->isUse;
		}
		void resize(const int size) {
			if (size == this->datSize)
				return;
			if (this->dat == nullptr || size == 0)
				initSeq();
			else {
#ifdef ERROR
				element* tmp = static_cast<element*>(std::realloc(this->dat, size));
#endif
				element* tmp = static_cast<element*>(std::calloc(size, sizeof(element)));
				if (tmp == nullptr)
					throw DataStructException(1, "can not allocate memory space");

#ifdef DEBUG_RESIZE
				for (int i = 0; i < this->isUse; ++i) {
					tmp[i] = this->dat[i];
					printf("%d ", this->dat[i]);
				}
				putchar('\n');
#else
				for (int i = 0; i < this->isUse; ++i) {
					tmp[i] = this->dat[i];
				}
#endif
				std::free(this->dat);
				this->dat = tmp;
				this->datSize = size;//updata size of table
			}
		}
		unsigned int capactiy() const noexcept {
			return this->datSize;
		}
		unsigned int size() const noexcept {
			return this->isUse;
		}
		element& operator[](unsigned int index) {
			if (index < 0 || index >= this->datSize){
				//	throw DataStructException(2, "the index is error");
				this->resize(index << 2);
				this->isUse = index + 1;
			}
			return this->dat[index];
		}
#ifdef UNKNOW_ERROR
		element& operator[](unsigned int index) {
			if (index < 0 || index >= this->datSize)
				throw DataStructException(2, "the index is error");
			return this->dat[index];
		}
#else
		const element* getArray(void) const noexcept {
			return this->dat;
		}
#endif

		void clear() {
			std::memset(this->dat, 0, this->datSize);
			this->isUse = 0;
		}

		~SeqTable() {
			std::free(dat);
		}


		//frined operator 
	protected:
		element& getElem(const unsigned int index) const {
			if (index < 0 || index >= this->datSize)
				throw DataStructException(2, "the index is error");
			return this->dat[index];
		}
		void initSeq() {
			this->dat = static_cast<element*>(std::calloc(2, sizeof(element)));
			if (this->dat == nullptr)
				throw DataStructException(1, "can not allocate memory space");
			this->datSize = 2;
			this->isUse = 0;
		}
		element* getDatPoint(void) const noexcept {
			return this->dat;
		}
		void setUse(const int dat) {
			isUse = dat;
		}
	private:
		element* dat;
		int datSize;
		int isUse;
	};


}