#include <iostream>
#include <vector>
using namespace std;
class unsignedHierarchicalNum
{
private:
	vector<unsigned int>num;
	unsigned int len;
	unsigned int toUnsignedInt(vector<unsigned int>& num) {
		unsigned int u_i = 0;
		unsigned int digitNum = 1;
		auto it = num.end() - 1;
		while (num.begin() <= it) {
			u_i += *it * digitNum;
			digitNum *= digitNum + 1;
			it--;
		}
		return u_i;
	}
	void add(const int addNum, vector<unsigned int>& n) {
		unsigned int upNum = toUnsignedInt(n) + addNum;
		auto it = n.end() - 1;
		unsigned int levelUp = 2;
		while (it <= n.begin()) {
			*it = upNum % levelUp;
			upNum /= levelUp;
			levelUp++;
			it--;
			*it = upNum;
		}
	}
	void sub(const int subNum, vector<unsigned int>& n) {
		unsigned int upNum = toUnsignedInt(n) - subNum;
		auto it = n.end() - 1;
		unsigned int levelUp = 2;
		while (it <= n.begin()) {
			*it = upNum % levelUp;
			upNum /= levelUp;
			levelUp++;
			it--;
			*it = upNum;
		}
	}
public:
	unsignedHierarchicalNum(const unsigned int n, const unsigned int numLen = 0) {
		if (numLen) {
			this->len = numLen;
			this->num.reserve(numLen);
		}
		else {
			unsigned int tim = 1;
			unsigned int i = 1;
			while (tim >= n) {
				tim *= ++i;
			}
			this->len = i;
			this->num.reserve(i);
		}
		add(n, this->num);
	}
	unsignedHierarchicalNum operator+(const int n) {
		unsignedHierarchicalNum num(this->toUnsignedInt() + n);
		return num;
	}
	unsignedHierarchicalNum operator-(const int n) {
		unsignedHierarchicalNum num(this->toUnsignedInt() - n);
		return num;
	}
	unsignedHierarchicalNum& operator++() {
		add(1, this->num);
		return *this;
	}
	unsignedHierarchicalNum& operator--() {
		sub(1, this->num);
		return *this;
	}
	unsignedHierarchicalNum operator++(int) {
		unsignedHierarchicalNum num = *this;
		add(1, this->num);
		return num;
	}
	unsignedHierarchicalNum operator--(int) {
		unsignedHierarchicalNum num = *this;
		sub(1, this->num);
		return num;
	}
	unsignedHierarchicalNum& operator+=(const int addNum) {
		add(addNum, this->num);
		return *this;
	}
	unsignedHierarchicalNum& operator-=(const int subNum) {
		sub(subNum, this->num);
		return *this;
	}
	unsignedHierarchicalNum& operator=(unsignedHierarchicalNum& n) {
		this->len = n.len;
		this->num = n.num;
		return *this;
	}
	unsigned int getPosNum(const unsigned int position) {
		if (position >= num.size()) {
			return NULL;
		}
		else {
			return num[position];
		}
	}
	unsigned int toUnsignedInt() {
		unsigned int u_i = 0;
		unsigned int digitNum = 1;
		auto it = this->num.end() - 1;
		while (this->num.begin() <= it) {
			u_i += *it * digitNum;
			digitNum *= digitNum + 1;
			it--;
		}
		return u_i;
	}
};