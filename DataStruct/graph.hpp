#pragma once
#include<iostream>
//�����
struct ArcNode {
	int adjvex;		//�ڽӵ��򣬴�������ڽӵĵ��ڱ�ͷ�����е�λ��
	ArcNode* nextarc;//ָ����ָ����һ���߻�
	int info;//���Դ�����Ϣ

	ArcNode(int adj, int w) {
		adjvex = adj;
		info = w;
		nextarc = NULL;
	}

	void output() {
		std::cout << "->" << "(" << adjvex << "," << info << ")";
	}
};

//������
struct VexNode {
	char data;//��Ŷ�����Ϣ
	ArcNode* firstarc;//ָʾ��һ���ڽӵ�
	int set = 0;//������
	VexNode() {
		firstarc = NULL;
	}

	~VexNode() {}

	void output() {
		std::cout << "����" << data;//����Ĵ�ӡ
		ArcNode* p = firstarc;
		while (p) {
			p->output();
			p = p->nextarc;//���Ĵ�ӡ
		}
		std::cout << std::endl;
	}

	void addArc(int adj, int w) {
		//�򶥵���ӻ�
		ArcNode* p = new ArcNode(adj, w);
		p->nextarc = firstarc;//����Ĳ���
		firstarc = p;
	}
};

struct Edge//��
{
	int v1;//v1����
	int v2;//v2����
	int weight;//Ȩ��
};

struct ALGraph {
	VexNode* vertices;
	int vexnum;//��������
	int kind;//ͼ�����࣬0-����ͼ��1-����ͼ
	ALGraph(const char* names, int k = 1) {
		kind = k;
		vexnum = strlen(names);
		vertices = new VexNode[vexnum];
		for (int i = 0; i < vexnum; i++) {
			vertices[i].data = names[i];
		}
	}

	~ALGraph() {}

	void output() {
		//���ͼ
		for (int i = 0; i < vexnum; i++)
			vertices[i].output();
	}

	void addArc(int tail, int head, int w = 0) {
		//��ͼ��ӻ�
		vertices[tail].addArc(head, w);
		if (kind == 0)//���������ͼ
			vertices[head].addArc(tail, w);//˫����ͨ
	}

};
