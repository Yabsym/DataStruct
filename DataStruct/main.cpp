////////#include"BFS.hpp"
////////#include"MapDye.hpp"
////////constexpr char map[10][11] = {
////////		"XXXXXXXXXX",
////////		"X X    X X",
////////		"X    X X X",
////////		"X     XX X",
////////		"X XX  XX X",
////////		"X X    X X",
////////		"X      X X",
////////		"X XXX XX X",
////////		"XX       X",
////////		"XXXXXXXXXX",
////////};
////////
////////constexpr bool mapDye[][7] = {
////////	{ false, true, true, true, true, true, false },
////////	{ true, false, false, false, false, true, false },
////////	{ true, false, false, true, true, false, false },
////////	{ true, false, true, false, true, true, false },
////////	{ true, false, true, true, false, true, false },
////////	{ true, true, false, true, true, false, false },
////////	{ false, false, false, false, false, false, false }
////////};
////////
////////bool judge(const char& dat) {
////////	return dat == ' ' ? true : false;
////////}
////////int main() {
////////	DataStruct::Maze<char> dat((const char*)map, 10, 11);
////////	dat.findPath(std::pair<int, int>(1, 1), std::pair<int, int>(8, 8), judge);
////////	std::vector<std::pair<int, int>> path = dat.getPath();
////////	DataStruct::MapDye colorMap((const bool*)mapDye,7);
////////	colorMap.getDye(4);
////////	return 0;
////////}
//////#include"String.hpp"
//////#include"SparseMatrix.hpp"
//////int main() {
//////	DataStruct::String test("abcdefg");
//////	DataStruct::String test2 = "world";
//////	DataStruct::SeqTable<DataStruct::String> st;
//////	DataStruct::String  test3;
//////	test.split(st, 'a');//div
//////	char c = test2[3];//index
//////	//test2.remove(2, 2);//remove
//////	test2.insert(0,"test");//insert
//////	test.replace("cde", "abcdefg");
//////	test.find("def");
//////
//////	DataStruct::SparseMatrix<int> m(6, 7);
//////	m.append(DataStruct::Triplet<int>(0, 1, 12));
//////	m.append(DataStruct::Triplet<int>(0, 2, 9));
//////	m.append(DataStruct::Triplet<int>(2, 0, -3));
//////	m.append(DataStruct::Triplet<int>(2, 4, 14));
//////	m.append(DataStruct::Triplet<int>(3, 2, 24));
//////	m.append(DataStruct::Triplet<int>(4, 1, 18));
//////	m.append(DataStruct::Triplet<int>(5, 0, 15));
//////	m.append(DataStruct::Triplet<int>(5, 3, -7));
//////	m.output();
//////	m.transpose();//测试快速转置
//////	m.output();
//////	return 0;
//////}
////
////#include<iostream>
////#include<string>
////#define NULL 0
////using namespace std;
////typedef struct node
////{
////	char data = char();
////	struct node* lchild, * rchlid;
////}node, * BiTree;
////void CreateBiTree(BiTree& T)
////{
////	char ch;
////	cin >> ch;
////	if (ch == '#')
////		T = NULL;//递归结束，建空树
////	else        //递归创建二叉树
////	{
////		T = new node; //生成根结点
////		T->data = ch;//根结点的数据域置于ch
////		CreateBiTree(T->lchild);//递归创建左子树
////		CreateBiTree(T->rchlid);//递归创建右子树
////	}
////}
////int DoubleTraverse(BiTree T)
////{
////	if (T == NULL)//若为空树则返回
////		return 0;
////	else if (T->lchild == NULL && T->rchlid == NULL)//若左孩子和右孩子皆为空，则输出结点的值
////		cout << T->data;
////	else
////	{
////		cout << T->data;//输出结点的值
////		cout << DoubleTraverse(T->lchild);//按双序遍历左子树
////		cout << T->data;//输出结点的值
////		cout << DoubleTraverse(T->rchlid);//按双序遍历右子树
////	}
////}
////void main()
////{
////	string ch = "abc##de#g##f###";
////	BiTree T;
////	CreateBiTree(T);
////	DoubleTraverse(T);
////	while (1);
////}
////
//
//
//#include<iostream>
//#include<stdlib.h>
//#include<time.h>
//#include <graphics.h>
//
//using namespace std;
//
///**************************/
///*栈的函数*/
//struct Stack
//{
//	int* stack;
//	int base;
//	int top;
//};
//
//Stack* CreateStack(int Capacity)  //创建栈
//{
//	Stack* S = new Stack;
//	S->stack = new int[Capacity];
//	S->base = 0;
//	S->top = -1;
//	return S;
//}
//
//void DestroyStack(Stack* S)    //销毁栈
//{
//	delete S;
//	S = NULL;
//}
//
//bool EmptyStack(Stack* S)   //判断栈是否为空
//{
//	if (S->top == -1)
//		return false;
//	else
//		return true;
//}
//
//void PushStack(Stack* S, int elem)    //出栈
//{
//	S->top++;
//	S->stack[S->top] = elem;
//}
//
//void PopStack(Stack* S)    //入栈
//{
//	if (EmptyStack(S))
//		S->top--;
//}
//
//int TopStack(Stack* S)   //返回栈顶元素
//{
//	return S->stack[S->top];
//}
///************************/
///************************/
//
///************************/
///****辅助深度优先算法判断是否是死的函数***/
//struct BBS
//{
//	int right = 0;
//	int upside = 1;
//	int left = 2;
//	int below = 3;
//};
//
//void CCC(BBS* S, int n)
//{
//	if (n == 0)
//		S->right = -1;
//	if (n == 1)
//		S->upside = -1;
//	if (n == 2)
//		S->left = -1;
//	if (n == 3)
//		S->below = -1;
//}
//
//bool AA(BBS* S)
//{
//	if (S->below == -1 && S->left == -1 && S->right == -1 && S->upside == -1)
//		return 0;
//	else
//		return 1;
//}
//
//void BB(BBS* S)
//{
//	S->right = 0;
//	S->upside = 1;
//	S->left = 2;
//	S->below = 3;
//}
///******************/
///******************/
//
//struct Coordinate  //迷宫点类
//{
//	bool Judgment = 1;   //判断是否为墙，1为是，0为不是
//	bool Judgemet_2 = 0;  //prim算法用到，深度优先算法没用
//};
//
//struct Coordinated  //prim算法用到，深度优先算法没用
//{
//	int adress;
//};
//
///*********************/
///********prime算法***********/
//void Sequence(Coordinated* Arry, int n, int& sum)   //把元素从数组删除
//{
//	int i;
//	for (i = n; i < sum; i++)
//	{
//		Arry[i] = Arry[i + 1];
//	}
//	sum--;
//}
//
//void Store(Coordinated* map_1, Coordinate* map_2, int map, int& k, int n)     //把元素储存进数组
//{
//	if (((map + 2) % n != 0) && map_2[map + 1].Judgemet_2 == 0)
//	{
//		map_1[k].adress = map + 1;
//		map_2[map_1[k].adress].Judgemet_2 = 1;
//		k++;
//	}
//	if (((map - 1) % n != 0) && map_2[map - 1].Judgemet_2 == 0)
//	{
//		map_1[k].adress = map - 1;
//		map_2[map_1[k].adress].Judgemet_2 = 1;
//		k++;
//	}
//	if (((map - n) / n != 0) && map_2[map - n].Judgemet_2 == 0)
//	{
//		map_1[k].adress = map - n;
//		map_2[map_1[k].adress].Judgemet_2 = 1;
//		k++;
//	}
//	if (((map + n) / n != n - 1) && map_2[map + n].Judgemet_2 == 0)
//	{
//		map_1[k].adress = map + n;
//		map_2[map_1[k].adress].Judgemet_2 = 1;
//		k++;
//	}
//}
//
//void PrimeMap(Coordinate* map, int n)
//{
//	Coordinated* map2 = new Coordinated[(n * n - 3 * n - 2) / 2];
//	srand((unsigned)time(0));
//
//	int k = 2;
//	map2[0].adress = n + 2;
//	map2[1].adress = 2 * n + 1;
//	map[n + 2].Judgemet_2 = 1;
//	map[2 * n + 1].Judgemet_2 = 1;
//
//	int b;
//	while (k != 0)
//	{
//		b = rand() % k;
//		if ((map2[b].adress / n) % 2 == 0)
//			if (map[map2[b].adress + n].Judgment + map[map2[b].adress - n].Judgment > 0)
//			{
//				map[map2[b].adress + n].Judgment = 0;
//				map[map2[b].adress].Judgment = 0;
//				map[map2[b].adress - n].Judgment = 0;
//				Store(map2, map, map2[b].adress + n, k, n);
//				Store(map2, map, map2[b].adress - n, k, n);
//				Sequence(map2, b, k);
//				continue;
//			}
//			else
//			{
//				Sequence(map2, b, k);
//				continue;
//			}
//		if ((map2[b].adress / n) % 2 == 1)
//			if (map[map2[b].adress + 1].Judgment + map[map2[b].adress - 1].Judgment > 0)
//			{
//				map[map2[b].adress + 1].Judgment = 0;
//				map[map2[b].adress].Judgment = 0;
//				map[map2[b].adress - 1].Judgment = 0;
//				Store(map2, map, map2[b].adress + 1, k, n);
//				Store(map2, map, map2[b].adress - 1, k, n);
//				Sequence(map2, b, k);
//				continue;
//			}
//			else
//			{
//				Sequence(map2, b, k);
//				continue;
//			}
//	}
//	map[1].Judgment = 0;
//	map[n * n - 2].Judgment = 0;
//	delete map2;
//}
///*******prim算法**********/
///***********************/
//
///***********************/
///***图的深度优先算法***/
//void CreateMap(Coordinate* map, int n)       //生成迷宫数组的函数，map为指向数组的指针，n为迷宫大小
//{
//	/*初始化数据*/
//	int k = 0;
//	int b;
//	int Num = (n - 1) / 2;
//	enum Direction { right, upside, left, below };    //方向
//
//	BBS* Q = new BBS;
//	Stack* ABS = CreateStack(Num * Num);
//
//	srand((unsigned)time(0));      //随机数种子
//
//	PushStack(ABS, n + 1);
//	map[n + 1].Judgment = 0;
//
//	//生成一个储存迷宫信息的数组
//	while (EmptyStack(ABS))
//	{
//		//如果栈为空，则退出
//		if (!AA(Q))
//		{
//			PopStack(ABS);
//			BB(Q);
//			continue;
//		}
//
//		b = rand() % 4;   //随机数
//
//		CCC(Q, b);
//
//		//生成迷宫算法
//		switch (b)
//		{
//		case right:
//			if ((TopStack(ABS) + 2) % n != 0)
//			{
//				if (map[TopStack(ABS) + 2].Judgment == 1)
//				{
//					map[TopStack(ABS) + 1].Judgment = 0;
//					map[TopStack(ABS) + 2].Judgment = 0;
//					PushStack(ABS, TopStack(ABS) + 2);
//					BB(Q);
//					break;
//				}
//				else
//					break;
//			}
//			else
//				break;
//		case upside:
//			if (TopStack(ABS) - 2 * n > 0)
//			{
//				if (map[TopStack(ABS) - 2 * n].Judgment == 1)
//				{
//					map[TopStack(ABS) - n].Judgment = 0;
//					map[TopStack(ABS) - 2 * n].Judgment = 0;
//					PushStack(ABS, TopStack(ABS) - 2 * n);
//					BB(Q);
//					break;
//				}
//				else
//					break;
//			}
//			else
//				break;
//		case left:
//			if ((TopStack(ABS) - 1) % n != 0)
//			{
//				if (map[TopStack(ABS) - 2].Judgment == 1)
//				{
//					map[TopStack(ABS) - 1].Judgment = 0;
//					map[TopStack(ABS) - 2].Judgment = 0;
//					PushStack(ABS, TopStack(ABS) - 2);
//					BB(Q);
//					break;
//				}
//				else
//					break;
//			}
//			else
//				break;
//		case below:
//			if (TopStack(ABS) + 2 * n < n * n - 1)
//			{
//				if (map[TopStack(ABS) + 2 * n].Judgment == 1)
//				{
//					map[TopStack(ABS) + n].Judgment = 0;
//					map[TopStack(ABS) + 2 * n].Judgment = 0;
//					PushStack(ABS, TopStack(ABS) + 2 * n);
//					BB(Q);
//					break;
//				}
//				else
//					break;
//			}
//			else
//				break;
//		}
//	}
//
//	//设置起点和出口
//	map[1].Judgment = 0;
//	map[n * n - 2].Judgment = 0;
//
//	DestroyStack(ABS);
//	delete Q;
//}
//
///***********************/
///***图的深度优先算法***/
//
//Stack* Pathfinding(Coordinate* map, int n)     //寻找迷宫路径的函数，返回一个储存路径的栈，map为指向迷宫数组的指针，n为迷宫大小
//{
//	int k = 1;
//	Stack* x = CreateStack(n * n);
//	Stack* v = CreateStack(n * n);
//	PushStack(x, 1);
//	PushStack(x, n + 1);
//
//	while (1)
//	{
//		map[x->stack[k - 1]].Judgment = 1;
//		if (map[TopStack(x) + 1].Judgment == 0)
//		{
//			map[x->stack[k - 1]].Judgment = 0;
//			PushStack(x, TopStack(x) + 1);
//			k++;
//			continue;
//		}
//		else if (map[TopStack(x) + n].Judgment == 0 && TopStack(x) + n < (n * n - 1))
//		{
//			map[x->stack[k - 1]].Judgment = 0;
//			PushStack(x, TopStack(x) + n);
//			k++;
//			continue;
//		}
//		else if (map[TopStack(x) - 1].Judgment == 0)
//		{
//			map[x->stack[k - 1]].Judgment = 0;
//			PushStack(x, TopStack(x) - 1);
//			k++;
//			continue;
//		}
//		else if (map[TopStack(x) - n].Judgment == 0 && TopStack(x) - n > 0)
//		{
//			map[x->stack[k - 1]].Judgment = 0;
//			PushStack(x, TopStack(x) - n);
//			k++;
//			continue;
//		}
//		else if (TopStack(x) == n * n - 2)
//		{
//			map[x->stack[k - 1]].Judgment = 0;
//			while (EmptyStack(x))
//			{
//				PushStack(v, TopStack(x));
//				PopStack(x);
//			}
//			DestroyStack(x);
//			return v;
//		}
//		else
//		{
//			map[TopStack(x)].Judgment = 1;
//			PopStack(x);
//			map[TopStack(x)].Judgment = 0;
//			k--;
//		}
//	}
//}
//
//void picture_one(Coordinate* map, int n)      //画迷宫的函数，map为指向储存迷宫数组的指针，n为迷宫大小
//{
//	// 初始化图形模式
//	initgraph(n * 10, n * 10);
//
//	//画图，黑色为墙，白色为通路
//	for (int x = 0; x < n; x++) {
//		for (int y = 0; y < n; y++) {
//			if (map[n * x + y].Judgment == 0) {
//				setfillcolor(LIGHTBLUE);
//				solidrectangle(x * 10, y * 10, x * 10 + 10, y * 10 + 10);
//			}
//			else
//			{
//				//Sleep(10);
//				setfillcolor(CYAN);
//				solidrectangle(x * 10, y * 10, x * 10 + 10, y * 10 + 10);
//			}
//		}
//	}
//	getchar();              // 按任意键继续
//}
//
//void picture_two(Stack* s, int n)  //画迷宫路径的函数，s为储存迷宫路径的函数，n为迷宫大小
//{
//	int num;
//	int x, y;
//	setfillcolor(LIGHTRED);   //颜色
//	while (EmptyStack(s))
//	{
//		num = TopStack(s);
//		PopStack(s);
//		x = num / n;
//		y = num % n;
//		solidrectangle(x * 10, y * 10, x * 10 + 10, y * 10 + 10);  //画矩阵
//		Sleep(10);
//	}
//	getchar();         //按任意键继续
//	closegraph();      //关闭幕布
//}
//
//int main()
//{
//	int n = 2;
//	int b;
//
//	while (n % 2 == 0)
//	{
//		cout << "请输入迷宫大小（大小为奇数）：";
//		cin >> n;
//		cout << endl;
//	}
//
//	Coordinate* s = NULL;
//	while (s == NULL)
//		s = new Coordinate[n * n];
//
//	cout << "1:深度遍历" << endl;
//	cout << "2：prim算法" << endl;
//	cin >> b;
//
//	switch (b)
//	{
//	case 1:CreateMap(s, n); break;
//	case 2:PrimeMap(s, n); break;
//	}
//	cin.ignore();
//
//	picture_one(s, n);
//	Stack* Q = Pathfinding(s, n);
//	picture_two(Q, n);
//	delete s;
//	DestroyStack(Q);
//
//
//
//	return 0;
//}
//

#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<stack>
//std::stack<int, std::allocator<int>> s;
//
//using namespace std;
//#include "tree.hpp"
//int main(){
//
//	BinTree* tree;
//	int index = 0;
//	//先序遍历创建二叉树
//	tree = BinTree::create("AB##CDF###E##", index);
//	tree->output();
//	cout << "后序遍历顺序为：";
//	tree->postOrder();//测试后序遍历结果
//	cout << endl;
//	std::cout << tree->count() << std::endl;
//	cout << "中序遍历顺序为：";
//	tree->preOrder();//测试后序遍历结果
//	delete tree;
//	cout << endl;
//	//已知先序和中序，重构二叉树
//	tree = BinTree::rebuildByPreIn("abdgcefh", "dgbaechf", 8);
//	tree->output();
//	delete tree;
//	return 0;
//}
#include"graph.hpp"
//#define SELECT_BEGIN_NODE
#define MAX_VERTEX_NUM 8
#define MIN(x,y) (x)>(y)?(y):(x)
void Prim(ALGraph& G
#ifdef SELECT_BEGIN_NODE
	,int node
#endif // SELECT_BEGIN_NODE
)
{
	char adjvex[MAX_VERTEX_NUM];
	int lowcost[MAX_VERTEX_NUM];
	bool U[MAX_VERTEX_NUM] = { 0 };
	memset(lowcost, 127, sizeof(lowcost));
#ifndef SELECT_BEGIN_NODE
	int begin_index = 0, index, nodeCount = 1;
#else
	int begin_index = node, index, nodeCount = 1;
#endif
	///////////////////////////////////////////////////////
InserNextNode:
	lowcost[begin_index] = 0; U[begin_index] = true;
	ArcNode* tmp = G.vertices[begin_index].firstarc;
	do {
		lowcost[tmp->adjvex] = MIN(tmp->info, lowcost[tmp->adjvex]);
	} while (tmp = tmp->nextarc);
	if (++nodeCount > G.vexnum) return;
	int min_tmp = INT_MAX;
	for (int j = 0; j < G.vexnum; ++j) {
		if (!U[j] && lowcost[j] < min_tmp)
			min_tmp = lowcost[index=j];
	}
	U[index] = true;
	printf("%c -> %c : %d\n", G.vertices[begin_index].data, G.vertices[index].data, min_tmp);
	begin_index = index;
	goto InserNextNode;
	/////////////////////////////////////////////////////////
	//TODO:请实现Prim算法，约40行
}
void Krusal(ALGraph& G)
{
	int union_set[MAX_VERTEX_NUM];
	for (int v = 0; v < G.vexnum; v++)
		union_set[v] = v;
	
	//TODO:请利用并查集实现Krusal算法，约20行
}
int main()
{//测试用例
	ALGraph G("123456", 0);//6个结点的无向图
	G.addArc(0, 1, 6); G.addArc(0, 2, 1); G.addArc(0, 3, 5);
	G.addArc(1, 2, 5); G.addArc(1, 4, 3);
	G.addArc(2, 3, 5); G.addArc(2, 4, 6); G.addArc(2, 5, 4);
	G.addArc(3, 5, 2); G.addArc(4, 5, 6);
	G.output();
	Prim(G
#ifdef SELECT_BEGIN_NODE
		, 2
#endif // SELECT_BEGIN_NODE
	); //测试Prim算法
	Krusal(G); //测试Krusal算法
	return 0;
}