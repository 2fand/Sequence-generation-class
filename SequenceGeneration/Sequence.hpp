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
	Sequence() {
		this->maxNum = 1;
		this->swapNum = 0;
	}
	Sequence(const unsigned int len) {
		this->maxNum = 1;
		this->swapNum = 0;
		unsigned int factNum = len;
		while (this->maxNum *= factNum, factNum-- > 1){}
		while (len--) { this->items.push_back(0); }
	}
	Sequence(const vector<T> f_items) {
		this->items = f_items;
		this->maxNum = 1;
		this->swapNum = 0;
		unsigned int factNum = this->items.size();
		while (this->maxNum *= factNum, factNum-- > 1){}
	}
	void swapVectorItem(const unsigned int index, const unsigned int indexa) {
		T tempItem = this->items[index];
		this->items[index] = this->items[indexa];
		this->items[indexa] = tempItem;
	}
	vector<vector<T>>getSequence() {

	}
	unsigned int sequenceCount() {
		return this->sequenceVector.size();
	}
	T pushBackItem(const T item) {
		
	}
	T popBackItem(const T item) {

	}
};