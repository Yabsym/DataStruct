#pragma once
#include"LinkList.hpp"
namespace DataStruct {
	typedef class polynomial_element {
	public:
		polynomial_element(double coef = 0, int index = 0) {
			this->index = index;
			this->coefficient = coef;
		}
		double coefficient;
		int index;
	}p_element;

	class Polynomial :private LinkList<polynomial_element> {
	public:
		Polynomial() :LinkList<polynomial_element>() {

		}
		void addElem(const polynomial_element& elem) {
			//优化 -> do--while循环
			if (this->size() == 0)
				this->append(elem);
			else
				for (unsigned int i = 0; i < this->size(); ++i) {
					if (this->getElem(i).index == elem.index) {
						this->getElem(i).coefficient += elem.coefficient;
						return;
					}
					else if (this->getElem(i).index > elem.index) {
						this->insert(i, elem);
						return;
					}
					else {
						this->append(elem);
						return;
					}
				}

		}
		Polynomial& operator+(Polynomial& dat) {
			//修改为while循环？-->
			for (unsigned int i = 0, j = 0; i < dat.size();) {
				int src = dat.getElem(i).index, dst = this->getElem(j).index;
				if (src == dst) {
					this->getElem(j).coefficient += dat.getElem(i).coefficient;
					++i;
					++j;
				}
				else if (src < dst) {
					this->insert(i, dat.getElem(i));
					++i;
				}
				else if (src > dst)
					++j;
			}
			return *this;
		}
		Polynomial& operator-(Polynomial& dat) {
			//修改为while循环？-->
			for (unsigned int i = 0, j = 0; i < dat.size();) {
				int src = dat.getElem(i).index, dst = this->getElem(j).index;
				if (src == dst) {
					this->getElem(j).coefficient -= dat.getElem(i).coefficient;
					++i;
					++j;
				}
				else if (src < dst) {
					polynomial_element tmp = dat.getElem(i);
					tmp.coefficient = -tmp.coefficient;//
					this->insert(i, dat.getElem(i));
					++i;
				}
				else if (src > dst)
					++j;
			}
			return *this;
		}
		void output() {
			if (this->size() > 0) {
				//可优化--->
				//getElem 每次均从头开始查找元素
				//解决方法
				//-->转化为SeqList输出
				//-->开放dat头指针接口
				printf("%lf*x^%d", this->getElem(0).coefficient, this->getElem(0).index);
				for (unsigned int i = 1; i < this->size(); ++i) {
					printf("%+lf*x^%d", this->getElem(i).coefficient, this->getElem(i).index);
				}
			}
			putchar('\n');
		}
	};
}