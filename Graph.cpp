#include "pch.h"
#include "Graph.h"
#include <iostream>

using namespace std;

void CGraph::init() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			m_aAdjMatrix[i][j] = 0;
}

int CGraph::InsertVex(Vex sVex) {
	m_aVexs[sVex.num] = sVex;
	return sVex.num;
}

int CGraph::InsertEdge(Edge sEdge) {
	m_aAdjMatrix[sEdge.vex2][sEdge.vex1] =  m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	return sEdge.weight;
}

Vex CGraph::GetVex(int v) {
	int i;
	for (i = 0; i < m_nVexnum; i++)
		if(i == v)	
			return m_aVexs[i];
}

int CGraph::FindEdge(int v, Edge aEdge[]) {
	int count = 0;
	for (int i = 0; i < m_nVexnum; i++) {
		if (m_aAdjMatrix[v][i] != 0) {
			Edge e = { v, i, m_aAdjMatrix[v][i] };
			aEdge[count] = e;
			count++;
		}
	}
	return count;
}

void CGraph::outputMatrix() {
	int i;
	for (i = 0; i < m_nVexnum; i++)
		cout << i << "\t";
	cout << endl;
	for (int i = 0; i < m_nVexnum; i++) {
		for (int j = 0; j < m_nVexnum; j++) {
			cout << m_aAdjMatrix[i][j]<<"\t";
		}
		cout << endl;
	}
}

int CGraph::DFSTraverse(int nVex, Path pList[]) {
	int nIndex = 0;
	bool bVisited[20] = { false };
	int count = 1;
	DFS(nVex, bVisited, nIndex, pList, count);
	return count;
}

void CGraph::DFS(int nVex, bool bVisited[], int &nIndex, Path pList[], int &count) {
	int i;
	int flag = 0;	//flag = 1 时表示还有顶点没有访问过
	bVisited[nVex] = true;	//改为已经访问
	pList[count].vex[nIndex++] = nVex;	//访问顶点nVex
	for (i = 0; i < m_nVexnum; i++) {
		if (bVisited[i] == false)
			flag = 1;
	}
	if (flag == 0) {	//所有结点均被访问一次后保存一条路径
		memcpy(pList[count+1].vex, pList[count].vex, 20 * sizeof(int));
		count++;
	}
	else {
		for (i = 0; i < m_nVexnum; i++) {
			if (m_aAdjMatrix[i][nVex] != 0 && !bVisited[i]) {
				DFS(i, bVisited, nIndex, pList, count);
				bVisited[i] = false;
				nIndex--;
			}
		}
	}	//else

}

int CGraph::FindShortPath(int nVexStart, int nVexEnd, bool aVisited[]) {
	int i;
	aVisited[nVexStart] = true;
	int path[80];	//记录路径
	int dist[80];	//记录起点到i个点的最短距离
	for (i = 0; i < m_nVexnum; i++) {
		if (m_aAdjMatrix[nVexStart][i] != 0)
			path[i] = nVexStart;
		else
			path[i] = -1;
	}
	for (i = 0; i < m_nVexnum; i++) {	//dist数组初始化
		dist[i] = m_aAdjMatrix[nVexStart][i];
		if (dist[i] == 0)
			dist[i] = 32767;
	}

	//找到离第一个结点的最短的
	for (i = 0; i < m_nVexnum; i++) {
		int count = 0;
		int minpath = 32767;
		int nextvex = 0;
		for (int j = 0; j < m_nVexnum; j++) {	//求最最短边
			if (dist[j] < minpath &&dist[j] != 0 && aVisited[j] == false) {
				minpath = dist[j];
				nextvex = j;
			}
		}
		aVisited[nextvex] = true;
		dist[nextvex] = minpath;	//更新dist数组，起点到nextvex的最小距离
		for (int j = 0; j < m_nVexnum; j++) {	//以nextvex为中间点，对整个dist数组和path数组更新
			if (aVisited[j] == false && dist[nextvex] + m_aAdjMatrix[nextvex][j] < dist[j] && dist &&m_aAdjMatrix[nextvex][j] != 0) {
				dist[j] = dist[nextvex] + m_aAdjMatrix[nextvex][j];
				path[j] = nextvex;
			}
		}
		count++;
		if (nextvex == nVexEnd) {	//找到目标结点
			cout <<"distance:"<< dist[nVexEnd]<<endl;
			cout << "path:";
			int k = nVexEnd;
			do{
				cout << m_aVexs[k].name << "<";
				k = path[k];
			} while (path[k] != -1);
			cout << m_aVexs[k].name << endl;
			return 0;
		}


	}
	return 0;
}

void CGraph::FindMinTree(Edge path[]) {
	bool avisited[80] = { false };
	int dist[80] = {0};	//记录最短边
	int adj[80] = {0};	//保存相关顶点下标
	int i, j;
	int distance = 0;
	avisited[0] = true;
	for (i = 0; i < m_nVexnum; i++) {
		dist[i] = m_aAdjMatrix[0][i];
		if (dist[i] == 0)
			dist[i] = 32767;
	}
	for (i = 0; i < m_nVexnum; i++) {
		int mindist = 32767;
		int nextvex = -1;
		for ( j = 0; j < m_nVexnum; j++) {
			if (dist[j] != 0 && dist[j] < mindist && avisited[j] == false ) {
				mindist = dist[j];
				nextvex = j;
			}
		}

		if (nextvex != -1) {	//有点被选中
			avisited[nextvex] = true;
			cout << m_aVexs[adj[nextvex]].name << "  " << m_aVexs[nextvex].name << " "<<m_aAdjMatrix[adj[nextvex]][nextvex]<<endl;
			distance += m_aAdjMatrix[adj[nextvex]][nextvex];
			for (int k = 0; k < m_nVexnum; k++) {	//对dist和adj数组更新
				if (avisited[k] == false && m_aAdjMatrix[nextvex][k] < dist[k]&&m_aAdjMatrix[nextvex][k]!=0) {
					dist[k] = m_aAdjMatrix[nextvex][k];
					adj[k] = nextvex;
				}
			}
		
		}

	}
	cout << "电路总长度为：" << distance<<endl;
}
