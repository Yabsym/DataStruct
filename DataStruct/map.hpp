#pragma once
#include <utility>
namespace DataStruct {
	template<typename type>
	class Map {
	public:
		Map() {
			this->mapDat = nullptr;
			this->max_X = 0;
			this->max_Y = 0;
		}
		Map(const type* map, const int max_X, const int max_Y) {
			this->mapDat = map;
			this->max_X = max_X;
			this->max_Y = max_Y;
		}
		const type& operator[](const std::pair<int, int> index) {
			return *(this->mapDat + index.first * this->max_Y + index.second);
		}
	protected:
		const type& getElem(const std::pair<int, int> index) {
			return *(this->mapDat + index.first * this->max_Y + index.second);
		}
		const type* mapDat;
		int max_X;
		int max_Y;
	};
}