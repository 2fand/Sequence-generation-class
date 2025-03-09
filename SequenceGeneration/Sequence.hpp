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
	void swapVectorItem(const unsigned int index, const unsigned int indexa) {//交换item数组中的两个元素
		T tempItem = this->items[index];
		this->items[index] = this->items[indexa];
		this->items[indexa] = tempItem;
	}
public:
	Sequence() {//无参构造方法
		this->maxNum = 1;
		this->swapNum = 0;
	}
	Sequence(unsigned int len) {//长度构造方法
		this->maxNum = 1;
		this->swapNum = 0;
		unsigned int factNum = len;
		while (this->maxNum *= factNum, factNum-- > 1){}
		while (len--) { this->items.push_back(0); }
	}
	Sequence(const vector<T> f_items) {//数组构造方法
		this->items = f_items;
		this->maxNum = 1;
		this->swapNum = 0;
		unsigned int factNum = this->items.size();
		while (this->maxNum *= factNum, factNum-- > 1){}
	}
	vector<vector<T>>getSequence() {//获取item数组所能排成的所有唯一序列
		this->sequenceVector.clear();
		if (this->items.size()) {
			this->sequenceVector.push_back(this->items);
			this->swapNum = 1;
			int swapIndex = this->items.size() - 2;
			int index = 0;
			vector<T>tempItems = this->items;
			while (swapNum < this->maxNum) {
				for (swapIndex = this->items.size() - 2, index = 0; index < this->items.size() - 1; index++, swapIndex--) {
					swapVectorItem(index, index + getPosNum(swapNum, swapIndex));
				}
				if (isUnique(this->items)) {
					this->sequenceVector.push_back(this->items);
				}
				this->items = tempItems;
				swapNum++;
			}
		}
		else {
			this->sequenceVector.push_back(this->items);
		}
		return this->sequenceVector;
	}
	unsigned int sequenceCount() {//获取所有唯一序列的个书
		return this->sequenceVector.size();
	}
	T pushBackItem(const T item) {//往item数组的尾部插入元素
		this->items.push_back(item);
		this->maxNum *= this->items.size();
		return item;
	}
	T popBackItem(const T item) {//删除item数组尾部元素
		if (this->items.size()) {
			T item = this->items.back();
			this->maxNum /= this->items.size();
			this->items.pop_back();
			return item;
		}
		else {
			return NULL;
		}
	}
};
