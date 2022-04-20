/**
* @author: SiKun
* @date: 2022/4/16 10:36
* @description: 静态顺序表
*/

#include <iostream>

using namespace std;


// 顺序表的存储结构(静态分配)
#define MAXSIZE 100     // 定义线性表的最大长度
typedef struct {
    int data[MAXSIZE];  // 顺序表的元素
    int length;         // 顺序表当前的长度
} SqList;               // 顺序表表的类型定义

/**
 * 初始化一个顺序表
 * @param L 静态顺序表
 */
void InitList(SqList &L) {
    for (int i = 0; i < MAXSIZE; i++) {
        L.data[i] = 0;  // 将所有数据元素设置为默认初始值(避免脏数据)
    }
    L.length = 0;       // 顺序表初始长度为0
}

/**
 * 顺序表的插入操作(在L的位序i处插入元素e)
 * @param L 静态顺序表
 * @param i 位序i
 * @param e 要插入的元素
 * @return 是否插入成功
 */
bool ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1) {       // 判断i的合法性
        return false;
    }
    if (L.length >= MAXSIZE) {             // 当前存储空间已满
        return false;
    }
    /*
     * 由于data最大长度为MaxSize不是length。
     * 所以length可以取到，并且指向最后一个元素的下一个空间
     */
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;                      // i为位序，i-1为数组中第i个位置
    L.length++;                             // 长度加1
    return true;
}

/**
 * 顺序表的删除操作(删除L中第i个位置元素，并用引用变量e返回)
 * @param L 顺序表L
 * @param i 位序i
 * @param e 接收删除的值
 * @return
 */
bool ListDelete(SqList &L, int i, int &e) {
    if (i < 1 || i > L.length + 1) { return false; }    // i位置不合法
    e = L.data[i - 1];                                  // 将要删除的元素赋值给e
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];                      // 将第i个位置之后的元素向前移动,i即表示数组中的i+1
    }
    L.length--;                                         // 表长度减1
    return true;
}
