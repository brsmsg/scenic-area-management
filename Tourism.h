#pragma once
#include "Graph.h"

class CTourism {
private:
	CGraph m_Graph;
public:
	void CreateGraph();	//��ȡ�ļ�����������ͼ
	void GetSpointInfo();	//��Ѱָ��������Ϣ����ʾ�����ھ�����ľ���
	void TravelPath();	//����DFSTraverse(), ���������ӡ
	void FindShortPath();	//��ѯ��������֮�����·���;���
	void DesignPath();	//��Ƶ�·ͼ
};