
#pragma once
#include"SeqTable.hpp"

namespace DataStruct {

	template <typename element>
	class Triplet
	{
	public:
		int row, col; //行列下标
		element e; //数据
		Triplet() {
			e = element();
		} //必须提供默认构造函数，以便创建对象矩阵
		Triplet(int r, int c, element v)
		{
			row = r; col = c; e = v;
		}
	};
	template<typename element>
	class SparseMatrix :
		public SeqTable<Triplet<element>>{//继承对应的SeqTable类
		//以公有方式继承父类
	public:
		SparseMatrix(int r, int c, int n = 10)//这一行的意思就是调用父类的构造函数
		{//构造函数
			rows = r;
			cols = c;
			SeqTable<Triplet<element>>::resize(n);
		}

		int getIndex(int r, int c)
		{//将稠密矩阵的下标转换为稀疏矩阵中的下标，以便访问 
		 //TODO：请将下面的顺序查找，改为二分查找
		 //找不到的时候，返回恰好比rc大的存储元素的下标
			int i = 0;
			if (r > this->rows || c > this->cols)
				throw DataStructException(1, "error index");
			for (i = 0; i < this->length; i++)
			{
				Triplet<element>& t = this->getElem(i);//取引用，减少对象拷贝 
				if (t.row > r || t.row == r && t.col >= c)
					break;
			}
			return i;
		}

		void transpose(void) {
			this->cols = this->cols ^ this->rows;
			this->rows = this->cols ^ this->rows;
			this->cols = this->cols ^ this->rows;
			int* cout = new int[this->cols + 2];
			Triplet<element>* temp = new Triplet<element>[this->size() + 2];
			for (int j = 0; j < this->size(); ++j)
				cout[j] = 0;
			for (int i = 0; i < this->size(); ++i)
				++cout[this->getElem(i).col + 1];
			for (int i = 1; i < this->size(); ++i)
				cout[i] += cout[i - 1];
			for (int i = 0; i < this->size(); ++i) {
				this->getElem(i).col = this->getElem(i).col ^ this->getElem(i).row;
				this->getElem(i).row = this->getElem(i).col ^ this->getElem(i).row;
				this->getElem(i).col = this->getElem(i).col ^ this->getElem(i).row;
				temp[cout[this->getElem(i).row ]++] = this->getElem(i);
			}
			for (int i = 0; i < this->size(); ++i)
				this->getElem(i) = temp[i];
			delete[] cout; 
			delete[] temp;
		}
		void output()
		{
			int k = 0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					element v = element();//设置为默认值
					if (k < this->size() && i == this->getElem(k).row && j == this->getElem(k).col)
					{
						v = this->getElem(k).e;//如果存在元素，就改为元素值
						k++;
					}
					printf("%4d", v);
				}
				putchar('\n');
			}
			putchar('\n');
		}

	private://权限访问控制
		int rows, cols;//行列大小
	};
}