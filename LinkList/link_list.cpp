/**
* @author: SiKun
* @date: 2022/4/20 13:24
* @description: 不带头结点的链表
*/

#include <iostream>

using namespace std;


typedef struct LNode {     // 定义单链表结点类型
    int data;             // 每个节点存放一个数据元素
    struct LNode *next;   // 指针指向下一个节点
} LNode, *LinkList;        // LNode强调的是一个节点，LinkList强调一个链表的头指针

/**
 * 初始化一个空的单链表
 * @param L 单链表
 */
bool InitList(LinkList &L) {
    L = NULL;       //头指针域置空，避免脏数据
    return true;
}

/**
 * 单链表判空操作
 * @param L
 * @return
 */
bool Empty(LinkList &L) {
    if (L == NULL) {
        return true;
    }else {
        return false;
    }
}


int main() {
    LinkList L;         // 声明一个空链表，此时并没有声明任何节点
    InitList(L);     // 初始化链表
}
