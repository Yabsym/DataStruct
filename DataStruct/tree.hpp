#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
static char screen[40][80];//屏幕打印专用缓冲区

class BinTree
{
public:
	char data;//结点数据，这次不采用模板类
	BinTree* lchild, * rchild;//左右孩子指针
	BinTree(char d)
	{//构造函数
		data = d;
		lchild = NULL;
		rchild = NULL;
	}
	~BinTree()
	{//析构函数，递归释放子结点
		if (lchild) delete lchild;
		if (rchild) delete rchild;
	}
	//输入含叶子结点空指针标记的方式创建二叉树
	static BinTree* create(const char* str, int& index)
	{//TODO:实现由先序遍历字符串创建二叉树
		char ch = str[index++];
		if (ch == '#') return NULL;
		BinTree* node = new BinTree(ch);
		node->lchild = create(str, index);
		node->rchild = create(str, index);
		return node;
	}
	//递归求树深度
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
	//输入含叶子结点空指针标记的方式创建二叉树
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
	//输出整个二叉树
	void output()
	{
		memset(screen, ' ', sizeof(screen));//不打印的地方用空格占位
		draw(0, 0, NULL);//从(0,0)坐标和根节点开始，绘制树到screen缓冲区
		int height = deep() * 2;//打印高度等于树深度的2倍，因为元素值要间隔一行
		for (int i = 0; i < height; i++)
		{
			screen[i][40] = '\0';
			printf("%s\n", screen[i]);
		}
	}
	//利用中序遍历在screen缓冲区中绘制二叉树图形
	int draw(int startx, int y, BinTree* parent)
	{//此算法虽然也用到递归遍历，但不属于教学和考核点，能够理解即可
	//startx表示当前树最左端的起始x坐标
		int endx = startx;//endx表示当前子树最右端的x坐标
		if (lchild) endx = lchild->draw(startx, y + 2, this) + 1;//先左子树
		int centerx = endx;//左子树结束的x坐标，就是根节点的x坐标
		screen[y][endx++] = data;
		if (rchild) endx = rchild->draw(endx, y + 2, this) + 1;//再右子树
		if (parent)
		{//如果有父结点，下面的处理负责把自己的根节点打印连接线到父结点
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
	{//TODO:请实现先序遍历
		printf("%c", data);
		if (lchild) lchild->postOrder();
		if (rchild) rchild->postOrder();
	}
	void postOrder()
	{//TODO:请实现后序遍历
		if (lchild) lchild->postOrder();
		if (rchild) rchild->postOrder();
		printf("%c", data);
	}
	//由先序和中序重构二叉树
	static BinTree* rebuildByPreIn(const char* PreOrder, const char* InOrder, int Len)
	{
		//如果P为空，立刻返回
		if (Len == 0) return NULL;
		//取PreOrder的第一个元素作为根节点r
		char r = PreOrder[0];
		BinTree* R = new BinTree(r);
		//查找r在InOrder中出现的位置pos
		int pos = 0;
		while (pos < Len)
		{
			if (InOrder[pos] == r) break;
			pos++;
		}
		//重构左子树：重构（R->lchild,PL,ML)
		R->lchild = rebuildByPreIn(PreOrder + 1, InOrder, pos);
		pos++;
		//重构右子树：重构（R->rchild,PR,MR)
		R->rchild = rebuildByPreIn(PreOrder + pos, InOrder + pos, Len - pos);
		return R;
	}
};