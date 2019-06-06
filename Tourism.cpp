#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "Tourism.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void CTourism::CreateGraph() {
	FILE *f1= NULL;
	FILE *f2 = NULL;
	int num = 0;
	char name[20];
	char des[1024];
	if ((f1 = fopen("D:\\study\\�����\\���ݽṹ���㷨�ۺ�ʵ��\\�����������Ϣ\\vex.txt", "r")) == NULL) {
		cout << "open file vex error!";
		return;
	}
	if ((f2 = fopen("D:\\study\\�����\\���ݽṹ���㷨�ۺ�ʵ��\\�����������Ϣ\\edge.txt", "r")) == NULL) {
		cout << "open file edge error!";
		return;
	}
	fscanf(f1, "%d", &num);
	m_Graph.setM_nVexnum(num);
	m_Graph.init();
	while (!feof(f1)) {
		Vex v = {0, 0, 0};
		fscanf(f1, "%d\n%s\n%s\n", &v.num, &v.name, &v.desc);
		m_Graph.InsertVex(v);
	}
	while (!feof(f2)) {
		Edge e = {0, 0, 0};
		fscanf(f2, "%d\t%d\t%d", &e.vex1, &e.vex2, &e.weight);
		m_Graph.InsertEdge(e);
	}
	m_Graph.outputMatrix();
	fclose(f1);
	fclose(f2);
}

void CTourism::GetSpointInfo() {
	int n;
	Edge aEdge[200];
	cout << "����Ҫ��ѯ�Ķ�����";
	cin >> n;
	Vex v = m_Graph.GetVex(n);
	cout << v.name << endl
		<< v.desc << endl;
	int count = m_Graph.FindEdge(n, aEdge);
	for (int i = 0; i < count; i++) {
		cout << aEdge[i].vex1 << "->" << aEdge[i].vex2 << "\t" << aEdge[i].weight << "m" << endl;
	}
}

void CTourism::TravelPath() {
	cout << "�����ʼ������";
	int nVex;
	Path pList[500];	//����·���Ľṹ������
	cin >> nVex;
	int count = m_Graph.DFSTraverse(nVex, pList);
	for (int i = 1; i <= count; i++){
		int j;
		for (j = 0; j < m_Graph.GetVexnum()-1; j++) {
			cout << m_Graph.GetVex(pList[i].vex[j]).name << "->";
		}
		cout << m_Graph.GetVex(pList[i].vex[j]).name;
		cout << endl;
	}
	
}

void CTourism::FindShortPath() {
	int VexStart, VexEnd;
	bool aVisited[200] = {false};
	cout << "������ʼ�ڵ㣺";
	cin >> VexStart;
	cout << "������ֹ��㣺";
	cin >> VexEnd;
	m_Graph.FindShortPath(VexStart, VexEnd, aVisited);
}

void CTourism::DesignPath() {
	Edge e[100];
	m_Graph.FindMinTree(e);
}