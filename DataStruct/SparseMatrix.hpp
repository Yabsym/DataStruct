
#pragma once
#include"SeqTable.hpp"

namespace DataStruct {

	template <typename element>
	class Triplet
	{
	public:
		int row, col; //�����±�
		element e; //����
		Triplet() {
			e = element();
		} //�����ṩĬ�Ϲ��캯�����Ա㴴���������
		Triplet(int r, int c, element v)
		{
			row = r; col = c; e = v;
		}
	};
	template<typename element>
	class SparseMatrix :
		public SeqTable<Triplet<element>>{//�̳ж�Ӧ��SeqTable��
		//�Թ��з�ʽ�̳и���
	public:
		SparseMatrix(int r, int c, int n = 10)//��һ�е���˼���ǵ��ø���Ĺ��캯��
		{//���캯��
			rows = r;
			cols = c;
			SeqTable<Triplet<element>>::resize(n);
		}

		int getIndex(int r, int c)
		{//�����ܾ�����±�ת��Ϊϡ������е��±꣬�Ա���� 
		 //TODO���뽫�����˳����ң���Ϊ���ֲ���
		 //�Ҳ�����ʱ�򣬷���ǡ�ñ�rc��Ĵ洢Ԫ�ص��±�
			int i = 0;
			if (r > this->rows || c > this->cols)
				throw DataStructException(1, "error index");
			for (i = 0; i < this->length; i++)
			{
				Triplet<element>& t = this->getElem(i);//ȡ���ã����ٶ��󿽱� 
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
					element v = element();//����ΪĬ��ֵ
					if (k < this->size() && i == this->getElem(k).row && j == this->getElem(k).col)
					{
						v = this->getElem(k).e;//�������Ԫ�أ��͸�ΪԪ��ֵ
						k++;
					}
					printf("%4d", v);
				}
				putchar('\n');
			}
			putchar('\n');
		}

	private://Ȩ�޷��ʿ���
		int rows, cols;//���д�С
	};
}