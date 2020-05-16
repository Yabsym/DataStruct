#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
static char screen[40][80];//��Ļ��ӡר�û�����

class BinTree
{
public:
	char data;//������ݣ���β�����ģ����
	BinTree* lchild, * rchild;//���Һ���ָ��
	BinTree(char d)
	{//���캯��
		data = d;
		lchild = NULL;
		rchild = NULL;
	}
	~BinTree()
	{//�����������ݹ��ͷ��ӽ��
		if (lchild) delete lchild;
		if (rchild) delete rchild;
	}
	//���뺬Ҷ�ӽ���ָ���ǵķ�ʽ����������
	static BinTree* create(const char* str, int& index)
	{//TODO:ʵ������������ַ�������������
		char ch = str[index++];
		if (ch == '#') return NULL;
		BinTree* node = new BinTree(ch);
		node->lchild = create(str, index);
		node->rchild = create(str, index);
		return node;
	}
	//�ݹ��������
	int deep()
	{
		int ldeep = (lchild == NULL) ? 0 : lchild->deep();
		int rdeep = (rchild == NULL) ? 0 : rchild->deep();
		return 1 + (ldeep > rdeep ? ldeep : rdeep);
	}
	inline int count() const{
		return 1 + count(this->lchild) + count(this->rchild);
	}
	int count(BinTree* node)const {
		return node == nullptr ? 0 : 1 + count(node->lchild) + count(node->rchild);
	}
	//���뺬Ҷ�ӽ���ָ���ǵķ�ʽ����������
	BinTree* create()
	{
		char ch;
		scanf("%c", &ch);
		if (ch == '#') return NULL;
		BinTree* node = new BinTree(ch);
		node->lchild = create();
		node->rchild = create();
		return node;
	}
	//�������������
	void output()
	{
		memset(screen, ' ', sizeof(screen));//����ӡ�ĵط��ÿո�ռλ
		draw(0, 0, NULL);//��(0,0)����͸��ڵ㿪ʼ����������screen������
		int height = deep() * 2;//��ӡ�߶ȵ�������ȵ�2������ΪԪ��ֵҪ���һ��
		for (int i = 0; i < height; i++)
		{
			screen[i][40] = '\0';
			printf("%s\n", screen[i]);
		}
	}
	//�������������screen�������л��ƶ�����ͼ��
	int draw(int startx, int y, BinTree* parent)
	{//���㷨��ȻҲ�õ��ݹ�������������ڽ�ѧ�Ϳ��˵㣬�ܹ���⼴��
	//startx��ʾ��ǰ������˵���ʼx����
		int endx = startx;//endx��ʾ��ǰ�������Ҷ˵�x����
		if (lchild) endx = lchild->draw(startx, y + 2, this) + 1;//��������
		int centerx = endx;//������������x���꣬���Ǹ��ڵ��x����
		screen[y][endx++] = data;
		if (rchild) endx = rchild->draw(endx, y + 2, this) + 1;//��������
		if (parent)
		{//����и���㣬����Ĵ�������Լ��ĸ��ڵ��ӡ�����ߵ������
			if (parent->lchild == this)
			{
				for (int x = centerx; x <= endx; x++)
					screen[y - 1][x] = '-';
				screen[y - 1][centerx] = '/';
			}
			else
			{
				for (int x = startx; x <= centerx; x++)
					screen[y - 1][x] = '-';
				screen[y - 1][centerx] = '\\';
			}
		}
		return endx;
	}
	void preOrder()
	{//TODO:��ʵ���������
		printf("%c", data);
		if (lchild) lchild->postOrder();
		if (rchild) rchild->postOrder();
	}
	void postOrder()
	{//TODO:��ʵ�ֺ������
		if (lchild) lchild->postOrder();
		if (rchild) rchild->postOrder();
		printf("%c", data);
	}
	//������������ع�������
	static BinTree* rebuildByPreIn(const char* PreOrder, const char* InOrder, int Len)
	{
		//���PΪ�գ����̷���
		if (Len == 0) return NULL;
		//ȡPreOrder�ĵ�һ��Ԫ����Ϊ���ڵ�r
		char r = PreOrder[0];
		BinTree* R = new BinTree(r);
		//����r��InOrder�г��ֵ�λ��pos
		int pos = 0;
		while (pos < Len)
		{
			if (InOrder[pos] == r) break;
			pos++;
		}
		//�ع����������ع���R->lchild,PL,ML)
		R->lchild = rebuildByPreIn(PreOrder + 1, InOrder, pos);
		pos++;
		//�ع����������ع���R->rchild,PR,MR)
		R->rchild = rebuildByPreIn(PreOrder + pos, InOrder + pos, Len - pos);
		return R;
	}
};