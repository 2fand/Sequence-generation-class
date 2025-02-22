#include <iostream>
#include "HierarchicalNum.h"
using namespace std;
unsigned int getPosNum(const unsigned int u_i, const unsigned int index) {//获取阶乘数某一位的数
	unsigned int digitNum = 1;
	unsigned int i = index + 1;
	while (i > 1) {
		digitNum *= i--;
	}
	return u_i / digitNum % (index + 2);
}
