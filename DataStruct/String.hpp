#include"SeqTable.hpp"

namespace DataStruct {
	class String :private SeqTable<char> {
	public:
		String(int capital = 100) :SeqTable<char>() {
			this->SeqTable<char>::resize(capital);
		}
		String(const char* str) :SeqTable<char>() {
			if (str == nullptr)
				throw DataStructException(1, "Error memory");
			while (*str)
				this->SeqTable::append(*str++);
		}
		inline int size() const {
			return this->SeqTable::size();
		}
		inline void append(const char* str) {
			if (str == nullptr)
				throw DataStructException(1, "Error memory");
			while (*str)
				this->SeqTable::append(*str++);
		}
		inline void append(const char c) {
			this->SeqTable::append(c);
		}
		inline void append(const String& str) {
			for (int i = 0; i < str.size(); ++i) {
				this->SeqTable::append(str.getElem(i));
			}
		}
		
		int find(const char c) {
			for (int i = 0; i < this->SeqTable::size(); ++i) {
				if (c == this->getElem(i))
					return i;
			}
			return -1;
		}
		
		void  replace(const char* str,const char * dst) {
			Redo:
			int index = this->find(str);
			if (index == -1)
				return;
			else {;
				if (std::strlen(dst) - std::strlen(str) > this->capactiy() - this->size())
					this->resize(this->capactiy() + std::strlen(dst));
				int len_Src = std::strlen(str);
				int len_Dst = std::strlen(dst);
				if (len_Src == len_Dst)
					for (int i = 0; i < len_Dst; ++i)
						this->getElem(i + index) = dst[i];
				else if (len_Src > len_Dst) {
					for (int i = 0; i < len_Dst; ++i)
						this->getElem(i + index) = dst[i];
					for (int i = index + len_Dst; i < this->size() - len_Src + len_Dst;++i) {
						this->getElem(i) = this->getElem(i + len_Src - len_Dst);
					}
				}
				else if (len_Dst > len_Src) {
					for (int i = this->size(); i >= index; --i) {
						this->getElem(i + len_Dst - len_Src) = this->getElem(i);
					}
					for (int i = 0; i < len_Dst; ++i)
						this->getElem(i + index - 1) = dst[i];
				}
			}
			goto Redo;
		}

		inline int replace(const String& str,const String &dst) {
			replace(str.getArray(), dst.getArray());
		}

		int find(const char* str) {
			int n = this->size(), m = strlen(str);
			if (m > n)
				return -1;
			this->getNext(str);
			int j = 0;
			for (int i = 0; i < n; i++) {
				while (j && str[j] != this->getElem(i))
					j = next[j];
				if (str[j] == this->getElem(i))
					j++;
				if (j == m) {
					return i - m + 2;
				}
			}
			return -1;
		}
		inline int find(const String& str) {
			if (str.size() > this->size())
				return -1;
			return find(str.getDatPoint());
		}

		char& operator[](int index){
			return this->getElem(index);
		}
		String& operator=(const String& str) {
			this->resize(str.size() << 1);
			this->clear();
			//std::memcpy(this->getDatPoint(), str.getDatPoint(), str.size());
			for (int i = 0; i < str.size(); ++i) {
				this->append(str.getDatPoint()[i]);
				
			}
			return *this;
		}
		void split(SeqTable<String>* dat, const char c) {
			String str;
			int num = 0;
			for (int i = 0; i < this->size(); ++i) {
				if (this->getDatPoint()[i] == c)
					++num;
			}
			dat->resize(++num);
			for (int i = 0; i < this->size(); ++i) {
				if (this->getDatPoint()[i] != c)
					str.append(this->getDatPoint()[i]);
				else {
					//str.append(this->getDatPoint()[i]);
					str.append((const char)0);
					dat->append(str);
					str.clear();
				}
			}
			dat->append(str);
			return;
		}
		void split(SeqTable<String>& dat, const char c) {
			String str;
			int num = 0;
			for (int i = 0; i < this->size(); ++i) {
				if (this->getDatPoint()[i] == c)
					++num;
			}
			dat.resize(++num);
			for (int i = 0; i < this->size(); ++i) {
				if (this->getDatPoint()[i] != c)
					str.append(this->getDatPoint()[i]);
				else {
					//str.append(this->getDatPoint()[i]);
					str.append((const char)0);
					dat.append(str);
					str.clear();
				}
			}
			dat.append(str);
			return;
		}
		void clear(void) {
			this->SeqTable<char>::clear();
		}
		void remove(const int pos, const int len) {
			if (pos > this->size())
				throw(1, "error index");
			if (pos + len > this->size())
				this->getElem(pos) = 0;
			else {
				for (int i = 0; i < len; ++i) {
					this->getElem(pos) = this->getElem(pos + len + i);
				}
				this->getElem(pos + len + len) = 0;
			}
		}
		void insert(const int pos, const char * str) {
			if (this->capactiy() <= this->size() + strlen(str))
				this->resize(this->size() + strlen(str) + 1);
			
			for (int i = strlen(str); i >= 0; --i)
				this->getElem(strlen(str) + pos + i) = this->getElem(i);
			this->getElem(this->size() + strlen(str)) = 0;
			for (int i = pos; i < this->size() - 1; ++i) {
				this->getElem(i) = str[i - pos];
			}
			this->setUse(this->size() + strlen(str) - 1);
		}
		void insert(const int pos, String& str) {
			if (this->capactiy() <= this->size() + str.size())
				this->resize(this->size() + str.size() + 1);

			for (int i = str.size(); i >= 0; --i)
				this->getElem(str.size() + pos + i) = this->getElem(i);
			this->getElem(this->size() + str.size()) = 0;
			for (int i = pos; i < this->size() - 1; ++i) {
				this->getElem(i) = str[i - pos];
			}
			this->setUse(this->size() + str.size() - 1);

		}
		~String() {
		}

	protected:
		inline void getNext(const char* p) {
			next.resize(std::strlen(p));
			int m = strlen(p);
			next[0] = next[1] = 0;
			for (int i = 1; i < m; i++) {
				int j = next[i];
				while (j && p[i] != p[j])j = next[j];
				next[i + 1] = p[i] == p[j] ? j + 1 : 0;
			}
		}
		
		int compare(const String& str) {
			int len = str.size();
			for (int i = 0, j = 0; i < len && j < this->size(); ++j, ++i) {
				if (str.getDatPoint()[i] != this->getDatPoint()[j])
					return this->getDatPoint()[j] - str.getDatPoint()[i];
			}
			return this->size() - len;
		}
	private:
		SeqTable<int> next;
	};
}