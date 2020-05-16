#pragma once
#include<vector>
#include "map.hpp"
#include "DataStructException.hpp"

namespace DataStruct {
	class MapDye:public Map<bool>{
	public:
		MapDye(const bool* mapInf, const int limit) :
			Map<bool>(mapInf, limit, limit) {
			if (this->max_X < 0)
				throw DataStructException(1, "Error param");
		}
		
		std::vector<char>& getDye(const unsigned int colors) {
			using namespace std;
			if (this->max_X == 0 || colors == 0 ) {
				this->dyeAns.clear();
				return this->dyeAns;
			}
			dyeAns.resize(this->max_X);
			char color = 0;
			int dyeIndex = 1;
			dyeAns[0] = color;
			while (dyeIndex < this->max_X) {
				while (color < colors && dyeIndex < this->max_X) {
					dyeAns[dyeIndex] = color;
					while (!detection(dyeIndex) && color < colors) {
						this->dyeAns[dyeIndex] = ++color;
					}
					if (color < 4) {
						color = 0;
						++dyeIndex;
					}
				}
				if (color >= colors) {
					color = dyeAns[--dyeIndex] + 1;
				}
			}
			return this->dyeAns;
		}
		                                                                                                                                                          
	protected:
		bool detection(const int index) {
			std::pair<int, int> point;
			point.second = index;
			for (int i = 0; i < index; ++i) {
				point.first = i;
				if (this->getElem(point) == 1 && this->dyeAns[index] == this->dyeAns[i]) {
					return false;
				}
			}
			return true;
		}
	private:
		std::vector<char> dyeAns;
	};
}