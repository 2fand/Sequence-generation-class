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
		unsigned int timNum = 2;
		int it = num.size() - 1;
		while (0 <= it) {
			u_i += num[it--] * digitNum;
			digitNum *= timNum++;
		}
		return u_i;
	}
	void add(const int addNum, vector<unsigned int>& n) {//num自增某一个数
		unsigned int upNum = toUnsignedInt(n) + addNum;
		int it = n.size() - 1;
		unsigned int levelUp = 2;
		while (it >= 0) {
			n[it] = upNum % levelUp;
			upNum /= levelUp;
			levelUp++;
			it-- ? n[it] = upNum : 0;
		}
	}
	void sub(const int subNum, vector<unsigned int>& n) {//num自减某一个数
		unsigned int upNum = toUnsignedInt(n) - subNum;
		int it = n.size() - 1;
		unsigned int levelUp = 2;
		while (it >= 0) {
			n[it] = upNum % levelUp;
			upNum /= levelUp;
			levelUp++;
			it-- ? n[it] = upNum : 0;
		}
	}
public:
	unsignedHierarchicalNum(const unsigned int n, const unsigned int numLen = 0) {//有参构造方法
		unsigned int tim = 1;
		unsigned int i = numLen ? numLen : 1;
		while (!numLen && tim < n) {
			tim *= ++i;
		}
		this->len = i;
		for (; i; i--) {
			this->num.push_back(0);
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
	unsigned int operator=(unsigned int n) {//无符号整数赋值运算符
		unsigned int upNum = n;
		int it = this->num.size() - 1;
		unsigned int levelUp = 2;
		while (it >= 0) {
			this->num[it] = upNum % levelUp;
			upNum /= levelUp;
			levelUp++;
			it-- ? this->num[it] = upNum : 0;
		}
		return n;
	}
	unsignedHierarchicalNum& operator=(unsignedHierarchicalNum& n) {//阶进制数赋值运算符
		this->len = n.len;
		this->num = n.num;
		return *this;
	}
	unsigned int getPosNum(const unsigned int position) const {//获取阶进制数某一位的数
		return position >= num.size() ? NULL : num[position];
	}
	unsigned int toUnsignedInt() {//把阶进制数转成十进制的无符号整数
		unsigned int u_i = 0;
		unsigned int digitNum = 1;
		unsigned int timNum = 2;
		int it = this->num.size() - 1;
		while (0 <= it) {
			u_i += this->num[it--] * digitNum;
			digitNum *= timNum++;
		}
		return u_i;
	}
};
