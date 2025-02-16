#include <iostream>
#include <vector>
using namespace std;
class unsignedHierarchicalNum
{
private:
	vector<unsigned int>num;
	unsigned int len;
	unsigned int toUnsignedInt(vector<unsigned int>& num) {//(把某一个无符号vector数组)转为无符号整数
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
	void add(const int addNum, vector<unsigned int>& n) {//num自增某一个数
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
	void sub(const int subNum, vector<unsigned int>& n) {//num自减某一个数
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
	unsignedHierarchicalNum(const unsigned int n, const unsigned int numLen = 0) {//有参构造方法
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
	unsignedHierarchicalNum operator+(const int n) {//加号运算符
		unsignedHierarchicalNum num(this->toUnsignedInt() + n);
		return num;
	}
	unsignedHierarchicalNum operator-(const int n) {//减号运算符
		unsignedHierarchicalNum num(this->toUnsignedInt() - n);
		return num;
	}
	unsignedHierarchicalNum& operator++() {//前置自增运算符
		add(1, this->num);
		return *this;
	}
	unsignedHierarchicalNum& operator--() {//前置自减运算符
		sub(1, this->num);
		return *this;
	}
	unsignedHierarchicalNum operator++(int) {//后置自增运算符
		unsignedHierarchicalNum num = *this;
		add(1, this->num);
		return num;
	}
	unsignedHierarchicalNum operator--(int) {//后置自减运算符
		unsignedHierarchicalNum num = *this;
		sub(1, this->num);
		return num;
	}
	unsignedHierarchicalNum& operator+=(const int addNum) {//加等运算符
		add(addNum, this->num);
		return *this;
	}
	unsignedHierarchicalNum& operator-=(const int subNum) {//减等运算符
		sub(subNum, this->num);
		return *this;
	}
	unsignedHierarchicalNum& operator=(unsignedHierarchicalNum& n) {//赋值运算符
		this->len = n.len;
		this->num = n.num;
		return *this;
	}
	unsigned int getPosNum(const unsigned int position) {//获取阶进制数某一位的数
		if (position >= num.size()) {
			return NULL;
		}
		else {
			return num[position];
		}
	}
	unsigned int toUnsignedInt() {//把阶进制数转成十进制的无符号整数
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
