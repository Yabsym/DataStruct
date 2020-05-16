#pragma once
#include "map.hpp"

#include "stack.hpp"

#include <vector>

#define DEBUG_VISITED_SHOW
#define STL_PRIORITY_QUEUE
#if defined(DEBUG_VISITED_SHOW)
#include<iostream>
#endif

#if defined(STL_PRIORITY_QUEUE)
#include<queue>
#elif defined(SELF_PRIORITY_QUEUE)
#include "queue.hpp"
#else
#include "queue.hpp"
#endif

namespace DataStruct {
	template<typename type>
	class Maze :public Map<type>{
		typedef bool (pIsAvaliable)(const type&);
	public:
		Maze(const type* map, const int32_t max_X, const int32_t max_Y) :
			Map<type>(map, max_X, max_Y) {
			pathLength = static_cast<int*>(std::calloc(max_X * max_Y, sizeof(int)));
			if (pathLength == nullptr)
				throw DataStructException(0, "Error memory");
			memset(pathLength, 0, sizeof(pathLength));
			visited = static_cast<bool*>(std::calloc(max_X * max_Y, sizeof(bool)));
			if (visited == nullptr)
				throw DataStructException(0, "Error memory");
			memset(pathLength, 0, sizeof(visited));
			path = static_cast<std::pair<int, int>*>(std::calloc(max_X * max_Y, sizeof(std::pair<int, int>)));
			if (path == nullptr)
				throw DataStructException(0, "Error memory");
			//pathLength = static_cast<int**>(calloc(max_X, sizeof(int*)));
			//if (pathLength == nullptr)
			//	throw DataStructException(0, "Error memory");
			//for (int i = 0; i < max_X; ++i) {
			//	pathLength[i] = static_cast<int*>(calloc(max_Y, sizeof(int)));
			//	if (pathLength[i] == nullptr)
			//		throw DataStructException(0, "Error memory");
			//}
		}
		void findPath(const std::pair<int, int>src,
			const std::pair<int, int>dst, const pIsAvaliable isAbaliable) {
			if (!isAbaliable(this->getElem(dst)))
				return;
			if (dst.second < 0 || dst.first < 0 ||
				dst.second>this->max_Y || dst.first>this->max_X)
				throw DataStructException(1, "Error Param of dst");
			if (src.second < 0 || src.first < 0 ||
				src.second>this->max_Y || src.first>this->max_X)
				throw DataStructException(1, "Error Param of src");
			getPathLength(dst.first, dst.second) = INT_MAX;
			this->srcPoint = src;
			this->dstPoint = dst;
#if defined(STL_PRIORITY_QUEUE)
			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmpStruct> buf;
#elif defined(SELF_PRIORITY_QUEUE)
#else
			queue<std::pair<int, int>> buf;
#endif
			std::pair<int, int> pos = src;
			getVisited(pos.first, pos.second) = true;
#if defined(STL_PRIORITY_QUEUE)
			pos.first -= dst.first;
			pos.second -= dst.second;
			buf.push(pos);
			pos.first += dst.first;
			pos.second += dst.second;
#elif defined(SELF_PRIORITY_QUEUE)
#else
			buf.push(pos);
#endif
			
#if defined(STL_PRIORITY_QUEUE)
			while (~buf.empty()) {
#else
			while (~buf.isEmpty()) {
#endif
#ifdef DEBUG_VISITED_SHOW
				debug_print_visited();
#endif
#if defined(STL_PRIORITY_QUEUE)
				std::pair<int, int> tmp = buf.top();
				tmp.first += dst.first;
				tmp.second += dst.second;
				buf.pop();
#else
				std::pair<int, int> tmp = buf.pop();
#endif
				for (char i = 0; i < 8; ++i) {
					pos.first = tmp.first + DIRECT[i].first;
					pos.second = tmp.second + DIRECT[i].second;
					if (isAbaliable(this->getElem(pos)) && getVisited(pos.first, pos.second) == false) {
						this->getVisited(pos.first, pos.second) = true;
						this->getPath(pos.first, pos.second) = tmp;
#if defined(STL_PRIORITY_QUEUE)
						pos.first -= dst.first;
						pos.second -= dst.second;
						buf.push(pos);
						pos.first += dst.first;
						pos.second += dst.second;
#elif defined(SELF_PRIORITY_QUEUE)
#else
						buf.push(pos);
#endif
						this->getPathLength(pos.first, pos.second) = getPathLength(tmp.first, tmp.second) + 1;
						if (pos == dst) {
#ifdef DEBUG_VISITED_SHOW
							printf("%d", getPathLength(dst.first, dst.second));
#endif
							return;
						}
					}
#ifdef DEBUG_VISITED_SHOW
					debug_print_visited();
#endif
				}
			}
			return;
		}
#ifdef DEBUG_VISITED_SHOW
		void debug_print_visited() {
			system("cls");
			for (int i = 0; i < this->max_X; ++i) {
				for (int j = 0; j < this->max_Y; ++j) {
					std::printf("%2d", *(visited + i * this->max_Y + j));
				}
				std::putchar('\n');
			}
			std::putchar('\n');
			for (int i = 0; i < this->max_X; ++i) {
				for (int j = 0; j < this->max_Y; ++j) {
					std::printf("%10d", *(pathLength + i * this->max_Y + j));
				}
				std::putchar('\n');
			}
		}
#endif		
		/*LinkList<std::pair<int, int>>& shortestPath(const std::pair<int, int>src,
			const std::pair<int, int>dst,
			const pIsAvaliable isAbaliable,
			const Map<type>& map) {
			if (dst.second < 0 || dst.first < 0 ||
				dst.second>map.max_Y || dst.first>map.max_X)
				throw DataStructException(1, "Error Param of dst");
			if (src.second < 0 || src.first < 0 || 
				src.second>map.max_Y || src.first>map.max_X)
				throw DataStructException(1, "Error Param of src");
			queue<std::pair<int, int>> buf;
			std::pair<int, int> pos = src;
			buf.push(pos);
			while (~buf.isEmpty()) {
				std::pair<int, int> tmp = buf.pop();
				for (char i = 0; i < 8; ++i) {
					pos.first += DIRECT[i].first;
					pos.second += DIRECT[i].second;
					if (isAbaliable(pos)) {

					}
				}
			}
			
		}*/
		std::vector<std::pair<int, int>>& getPath() {
			std::vector<std::pair<int, int>> path;
			if (getPathLength(this->dstPoint.first, this->dstPoint.second) == INT_MAX) {
				pathPoint.clear();
				return pathPoint;
			}
			std::pair<int, int>dat = getPath(this->dstPoint.first, this->dstPoint.second);
			pathPoint.push_back(this->dstPoint);
			while (1) {
				pathPoint.push_back(dat);
				dat = getPath(dat.first, dat.second);
				if (dat == this->srcPoint) {
					pathPoint.push_back(this->srcPoint);
					std::reverse(pathPoint.begin(), pathPoint.end());
					return pathPoint;
				}
			}
		}
		~Maze()
		{
			std::free(pathLength);
			std::free(visited);
			std::free(path);
		}
	protected:
		
		inline int& getPathLength(int x, int y) {
			return *(this->pathLength + x * this->max_Y + y);
		}
		inline bool& getVisited(int x, int y) {
			return *(this->visited + x * this->max_Y + y);
		}
		inline std::pair<int, int>& getPath(int x, int y) {
			return *(this->path + x * this->max_Y + y);
		}
		//int** pathLength;
		int* pathLength;
		bool* visited;
		std::pair<int, int>* path;

		std::pair<int, int> srcPoint;
		std::pair<int, int> dstPoint;
		std::vector<std::pair<int, int>> pathPoint;
		struct cmpStruct {
			bool operator()(std::pair<int, int>& operator1, std::pair<int, int>& operator2) {
				return std::abs(operator1.first * operator1.first + operator1.second * operator1.second) -
					std::abs(operator2.first * operator2.first + operator2.second * operator2.second) > 0 ? true : false;
			}
		} cmp;
	private:
		const std::pair<int, int> DIRECT[8] = {
			std::pair<int, int>(0,1),
			std::pair<int, int>(0,-1),
			std::pair<int, int>(1,0),
			std::pair<int, int>(-1,0),
			std::pair<int, int>(-1,-1),
			std::pair<int, int>(1,-1),
			std::pair<int, int>(1,1),
			std::pair<int, int>(-1,1)
		};
	};
}