#include "pch.h"
#include <iostream>
#include "Tourism.h"

using namespace std;

int main() {
	int choose = 1;
	while (choose != 0) {
		cout << "-------景点信息管理系统-------" << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路径" << endl;
		cout << "5.铺设电路规划" << endl;
		CTourism tour;

		cout << "请选择要进行的操作";
		cin >> choose;
		switch (choose) {
		case 1:
			tour.CreateGraph();
			break;
		case 2:
			tour.GetSpointInfo();
			break;
		case 3:
			tour.TravelPath();
			break;
		case 4:
			tour.FindShortPath();
			break;
		case 5:
			tour.DesignPath();
		}

	}
}