/**
* @author: SiKun
* @date: 2022/4/20 10:43
* @description:  动态顺序表
*/

#include <iostream>

using namespace std;

#define InitSize 100    // 表长度的初始定义
typedef struct {
    int *data;          // 指示动态分配数组的指针，指向第一个位置
    int MaxSize;        // 顺序表的最大容量
    int length;         // 顺序表当前的长度
} SeqList;              // 顺序表的类型定义(动态分配)

/**
 * 初始化顺序表
 * @param L 动态分配顺序表
 */
void InitList(SeqList &L) {
    // 用malloc函数申请一片连续的空间
    //L.data = (int *) malloc(InitSize * sizeof(int));
    L.data = new int[InitSize];         // 为顺序表分配一个大小为MAXSIZE的数组空间
    L.length = 0;                       // 当前表长为0
    L.MaxSize = InitSize;               // 最大长度为初始化长度
}

/**
 * 增加动态数组长度
 * @param L 动态数组
 * @param len 要扩充的长度
 */
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;                        // 定义一个新的指针，用来暂存data数据
    L.data = new int[L.MaxSize + len];      // 扩充数组长度为MaxSize+len
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];                   // 将数据复制回扩充后的数组
    }
    L.MaxSize = L.MaxSize + len;            // 顺序表最大长度增加了len
    delete p;                               // 释放暂存节点空间
}

/**
 * 顺序表按位查找
 * @param L 动态数组
 * @param i 位序i
 * @param e 接收位序i的值
 * @return 是否查找成功
 */
bool GetElems(SeqList &L, int i, int &e) {
    if (i < 1 || i > L.length) {        // 若直接return L.data[i-1]则可能会出现i不合法问题
        return false;
    }
    e = L.data[i - 1];                  // 将第i个元素赋值给e
    return true;
}

/**
 * 顺序表按值查找(在L中查找第一个元素值等于e的元素，并返回其位序)
 * @param L 动态数组
 * @param e 要查找的值，e不需要被修改，所以无需&e
 * @return 位序
 */
int LocateElems(SeqList &L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;   // 数组下标为i的元素值等于e，返回其位序i+1;
        }
    }
    return 0;               // 由于返回的是位序i，i从1开始，所以可以返回0
}