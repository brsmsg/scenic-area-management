#pragma once
#include "Graph.h"

class CTourism {
private:
	CGraph m_Graph;
public:
	void CreateGraph();	//读取文件，创建景区图
	void GetSpointInfo();	//查寻指定景点信息，显示到相邻静待你的距离
	void TravelPath();	//调用DFSTraverse(), 并将结果打印
	void FindShortPath();	//查询两个景点之间最短路径和距离
	void DesignPath();	//设计电路图
};