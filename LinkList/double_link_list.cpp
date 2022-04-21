/**
* @author: SiKun
* @date: 2022/4/21 14:09
* @description: 
*/
#include <iostream>

using namespace std;

typedef struct DNode {
    int data;               // 数据域
    struct DNode *prior;    // 指向直接前驱
    struct DNode *next;     // 指向直接后继
} DNode, *DLinkList;

/**
 * 初始化双链表
 * @param L
 * @return
 */
bool InitDLinkList(DLinkList &L) {
    L = new DNode;          // 分配内存空间
    if (L == NULL) {
        return false;       // 内存不足，分配失败
    }
    L->prior = NULL;        // 头结点的prior永远指向NULL
    L->next = NULL;         // 头结点之后暂时还没有节点
    return true;
}

/**
 * 在p后面插入s结点
 * @param p
 * @param s 是否插入成功
 * @return
 */
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) {       // 非法参数
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) {   // 如果p有后续节点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}

/**
 * 删除p的后后序点
 * @param p 结点p
 * @return 是否删除成功
 */
bool DeleteNextDNode(DNode *p) {
    if (p == NULL) {
        return false;
    }
    DNode *q = p->next;         // 找到p的后序结点q
    if (q == NULL) {            // p没有后续结点
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) {      // q结点不是最后一个
        q->next->prior = p;
    }
    delete q;                   // 释放结点空间
    return true;
}