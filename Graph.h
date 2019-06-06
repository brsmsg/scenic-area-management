#pragma once

struct Vex {
	int num;	//景点编号
	char name[20];	//景点名称
	char desc[1024];	//景点介绍
};

struct Edge {
	int vex1;	//顶点1
	int vex2;	//顶点2
	int weight;	//权值
};

typedef struct Path {
	int vex[20];//保存一条路径
}* PathList, Path;

class CGraph {
private:
	int m_aAdjMatrix[20][20];	//邻接矩阵
	Vex m_aVexs[20];	//顶点数组
	int m_nVexnum;	//顶点个数
public:
	void setM_nVexnum(int num) {
		m_nVexnum = num;
	}
	void init();	//初始化图结构
	int InsertVex(Vex sVex);	//顶点加入顶点数组
	int InsertEdge(Edge sEdge);	//边保存到邻接矩阵
	Vex GetVex(int v);	//查询顶点信息
	int FindEdge(int v, Edge aEdge[]);	//查询与指定顶点相邻的边
	int GetVexnum() {
		return m_nVexnum;
	}	//获取当前顶点数量
	void outputMatrix();
	int DFSTraverse(int nVex, Path pList[]);//调用DFS函数，得到遍历结果
	void DFS(int nVex, bool bVisited[], int &nIndex, Path pList[], int &count);	//DFS方法遍历整个图
	int FindShortPath(int nVexStart, int nVexEnd, bool aVisited[]);	//求v1 v2最短路径
	void FindMinTree(Edge Path[]);	//求最小生成树
};