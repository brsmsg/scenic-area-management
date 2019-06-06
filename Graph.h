#pragma once

struct Vex {
	int num;	//������
	char name[20];	//��������
	char desc[1024];	//�������
};

struct Edge {
	int vex1;	//����1
	int vex2;	//����2
	int weight;	//Ȩֵ
};

typedef struct Path {
	int vex[20];//����һ��·��
}* PathList, Path;

class CGraph {
private:
	int m_aAdjMatrix[20][20];	//�ڽӾ���
	Vex m_aVexs[20];	//��������
	int m_nVexnum;	//�������
public:
	void setM_nVexnum(int num) {
		m_nVexnum = num;
	}
	void init();	//��ʼ��ͼ�ṹ
	int InsertVex(Vex sVex);	//������붥������
	int InsertEdge(Edge sEdge);	//�߱��浽�ڽӾ���
	Vex GetVex(int v);	//��ѯ������Ϣ
	int FindEdge(int v, Edge aEdge[]);	//��ѯ��ָ���������ڵı�
	int GetVexnum() {
		return m_nVexnum;
	}	//��ȡ��ǰ��������
	void outputMatrix();
	int DFSTraverse(int nVex, Path pList[]);//����DFS�������õ��������
	void DFS(int nVex, bool bVisited[], int &nIndex, Path pList[], int &count);	//DFS������������ͼ
	int FindShortPath(int nVexStart, int nVexEnd, bool aVisited[]);	//��v1 v2���·��
	void FindMinTree(Edge Path[]);	//����С������
};