#include <iostream>
#include <vector>
#include "HierarchicalNum.h"
using namespace std;
template<class T>
class Sequence {
private:
	vector<T>items;
	vector<vector<T>>sequenceVector;
	unsigned int maxNum;
	unsigned int swapNum;
public:
	Sequence() {//无参构造方法
		this->maxNum = 1;
		this->swapNum = 0;
	}
	Sequence(const unsigned int len) {//长度构造方法
		this->maxNum = 1;
		this->swapNum = 0;
		unsigned int factNum = len - 1;
		while (this->maxNum *= factNum, factNum-- > 1){}
		while (len--) { this->items.push_back(0); }
	}
	Sequence(const vector<T> f_items) {//数组构造方法
		this->items = f_items;
		this->maxNum = 1;
		this->swapNum = 0;
		unsigned int factNum = this->items.size() - 1;
		while (this->maxNum *= factNum, factNum-- > 1){}
	}
	void swapVectorItem(const unsigned int index, const unsigned int indexa) {//交换item数组中的两个元素
		T tempItem = this->items[index];
		this->items[index] = this->items[indexa];
		this->items[indexa] = tempItem;
	}
	vector<vector<T>>getSequence() {//获取item数组所能排成的所有唯一序列(未完工)

	}
	unsigned int sequenceCount() {//获取所有唯一序列的个书
		return this->sequenceVector.size();
	}
	T pushBackItem(const T item) {//往item数组的尾部插入元素
		this->items.push_back(item);
		this->maxNum *= this->items.size() - 1;
	}
	T popBackItem(const T item) {//删除item数组尾部元素(未完工)

	}
};
