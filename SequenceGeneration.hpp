#pragma once
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
template<class T>
class SequenceGeneration {
private:
        class node {
        public:
                T item;
                bool from;
                node(T t = NULL, bool f = false) {//node节点类的构造方法
                        this->item = t;
                        this->from = f;
                }
        };
        vector<node*> nodeArr;
        int ic;
        vector<vector<T>>sequencArr;
        void swap_node(const unsigned int index, const unsigned int indexa) {//交换节点的位置
                node* temp = this->nodeArr[index];
                this->nodeArr[index] = this->nodeArr[indexa];
                this->nodeArr[indexa] = temp;
        }
        void generateAllSequences(const unsigned int insert_index) {//获取一个数列的所有唯一序列(核心)
                if (this->ic <= insert_index && this->ic) {
                        vector<T>v;
                        for (node* n : this->nodeArr) {
                                v.push_back(n->item);
                        }
                        if (this->sequencArr.end() == find(this->sequencArr.begin(), this->sequencArr.end(), v)) {
                                this->sequencArr.push_back(v);
                        }
                        return;
                }
                for (int i = 0; i < this->ic; i++) {
                        if (!this->nodeArr[i]->from) {
                                this->nodeArr[i]->from = true;
                                swap_node(insert_index, i);
                                generateAllSequences(insert_index + 1);
                                swap_node(insert_index, i);
                                this->nodeArr[i]->from = false;
                        }
                }
        }
public:
        SequenceGeneration() {//无参构造方法
                this->ic = 0;
        }
        SequenceGeneration(const unsigned int isize) {//大小构造方法
                this->nodeArr.reserve(isize);
                this->ic = isize;
        }
        SequenceGeneration(vector<T>v) {//数组构造方法
                for (T item : v) {
                        this->nodeArr.push_back(new node(item));
                }
                this->ic = v.size();
        }
        SequenceGeneration(SequenceGeneration& uf) {//拷贝构造方法
                for (node* n : uf.nodeArr) {
                        this->push_back(n->item);
                }
                this->ic = v.size();
        }
        oneGroupUF& operator=(oneGroupUF& uf) {//重载赋值运算符
	        this->clear();
	        for (node* n : uf.nodeArr) {
		        this->push_back(n->item);
	        }
	        this->sequencArr = uf.sequencArr;
	        return *this;
        }
        T& at(const unsigned int index) {//查询索引代表的节点的值
                assert(index < this->ic);
                return this->nodeArr[index]->item;
        }
        T& operator[](const unsigned int index) {//同at方法
                return at(index);
        }
        T push_back(const T t) {//往尾部添加节点
                this->nodeArr.push_back(new node(t));
                this->ic++;
                return t;
        }
        T pop_back() {//删除尾部节点
                if (!this->ic) {
                        return NULL;
                }
                T last = this->nodeArr.back()->item;
                delete this->nodeArr.back();
                this->nodeArr.pop_back();
                this->ic--;
                return last;
        }
        void clear() {//清空
                while (this->ic) {
                        pop_back();
                }
        }
        vector<vector<T>> generateAllSequences() {//获取一个数列的所有唯一序列
                this->sequencArr.clear();
                generateAllSequences(0);
                return this->sequencArr;
        }
        ~SequenceGeneration() {//析构方法
                clear();
        }
        unsigned int countSequences() {返回sequencArr的元素个数
                return this->sequencArr.size();
        }
        unsigned int getCapacity() {//返回nodeArr节点数组的大小
                return this->ic;
        }
};
