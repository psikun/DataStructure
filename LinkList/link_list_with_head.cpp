/**
* @author: SiKun
* @date: 2022/4/20 13:03
* @description: 带头结点单链表定义
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
    L = new LNode;       // 生成一个新的节点作为头结点，用头指针L指向头结点
    if (L == NULL) {
        return false;    // 内存不足分配失败
    }
    L->next = NULL;      //头结点指针域置空,避免脏数据
    return true;
}

/**
 * 单链表判空操作
 * @param L
 * @return
 */
bool Empty(LinkList &L) {
    if (L->next == NULL) {   // 第0个结点为头结点
        return true;
    } else {
        return false;
    }
}

/**
 * 在带头结点的单链表L中获取第i个结点
 * @param L 带头节点的单链表L，因为无需对链表修改，所以无需使用&L
 * @param i 位序i
 * @return 返回该结点
 */
LNode *GetElem(LinkList L, int i) {
    int j = 1;                 // 计数，初始值为1
    LNode *p = L->next;        // 第一个结点指针赋值给p
    if (i == 0) {
        return L;               //若i等于0，则返回头结点
    }
    if (i < 1) {
        return NULL;            // i不合法
    }
    while (p && j < i) {        // 从第一个结点开始找，查找第i个结点
        p = p->next;
        j++;
    }
    return p;                   // 返回第i个结点的指针，若i大于表长，则返回NULL
}

/**
 * 按值查找，找到数据域==e的结点
 * @param L 链表，L指向头结点
 * @param e 要找的值
 * @return 结点
 */
LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;             // p指向第一个结点
    while (p && p->data != e) {     // 从第1个结点开始查找数据域为e的结点
        p = p->next;
    }
    return p;                       // 找到后返回该结点的指针，否则返回NULL(最后一个p->next为NULL)
}

/**
 * 获取链表长度
 * @param L 带头结点的链表
 * @return 表长
 */
int Length(LinkList L) {
    int len = 0;
    LNode *p = L;       // 头指针赋值给p
    while (p->next != NULL) {
        len++;
    }
    return len;
}


/**
 * 在指定结点后插操作(带头结点)
 * @param L 带头结点的链表
 * @param e 要插入的值
 * @return 是否插入成功
 */
bool InsertNextNode(LNode *p, int e) {
    if (p == NULL) {
        return false;                         // i值不合法
    }
    LNode *s = new LNode;                     // 创建一个s结点
    if (s == NULL) {
        return false;                         // 内存不足，分配失败
    }
    s->data = e;                              // s的数据域赋值为e
    s->next = p->next;                        // s的next指针指向p的下一个指针
    p->next = s;                              // 将结点s插入到p之后
    return true;
}

/**
 * 在指定结点前插操作(带头结点)
 * @param L 带头结点的链表
 * @param i 位序i
 * @param e 要插入的值
 * @return 是否插入成功
 */
bool InsertPriorNode(LNode *p, int e) {
    if (p == NULL) {                // 传入结点为空
        return false;
    }
    LNode *s = new LNode;
    if (s == NULL) {                // 内存不足分配失败
        return false;
    }
    s->next = p->next;          // 将s结点连接到p后边
    p->next = s;
    s->data = p->data;            // s结点与p结点交换数据域，p中元素复制到s中
    p->data = e;                    // 用e覆盖p的数据域
    return true;
}

/**
 * 按位序插入(带头结点)
 * @param L 带头结点的链表
 * @param i 位序i
 * @param e 要插入的值
 * @return 是否插入成功
 */
bool ListInsert(LinkList &L, int i, int e) {
    LNode *p = GetElem(L, i - 1);           // 获取第i个位置的前驱结点
    return InsertNextNode(p, e);              // 插入成功
}

/**
 * 按位序删除(带头结点)
 * @param L 带头结点的链表
 * @param i 位序i
 * @param e 接收删除的值
 * @return 是否删除成功
 */
bool ListDelete(LinkList &L, int i, int &e) {
    LNode *p = GetElem(L, i - 1);       // 寻找前驱结点
    if (p == NULL) {
        return false;
    }
    if (p->next == NULL) {
        return false;                     // p为最后一个结点
    }
    LNode *q = p->next;                   // 令q指向被删除的结点
    e = q->data;                          // 用e返回元素的值
    p->next = q->next;                    // 断开结点q
    delete q;                             // 释放空间
    return true;                          // 删除成功
}

/**
 * 删除指定节点p
 * @param p 要删除的节点
 * @return 是否删除成功
 */
bool DeleteNode(LNode *p) {
    if (p == NULL) {
        return false;
    }
    LNode *q = p->next;              // 令q指向p的后继结点
    if (q == NULL) {
        return false;
    }
    p->data = p->next->data;        // 和后继节点交换数据域
    p->next = q->next;              // 断开q
    delete q;                       // 删除q节点
    return true;                    // 删除成功
}

/**
 * 头插法建立新链表(链表的逆置！！！！！！)
 * @param L 链表
 * @param n 链表长度
 * @return 建立的链表
 */
void List_HeadInsert(LinkList &L, int n) {
    L = new LNode;          // 创建头结点
    L->next = NULL;         // 好习惯
    for (int i = 0; i < n; i++) {
        LNode *p = new LNode; // 生成新结点
        cin >> p->data;         // 赋值给新结点值
        p->next = L->next;      // p的next指向L的后继节点
        L->next = p;            // L后继指向P
    }
}

/**
 * 尾插法建立单链表
 * @param L 单链表
 * @param n 链表长度
 */
void List_TailInsert(LinkList &L, int n) {
    L = new LNode;
    L->next = NULL;
    LNode *r = L;       // r为表尾指针
    for (int i = 0; i < n; i++) {
        LNode *p = new LNode;  // 生成新结点
        cin >> p->data;        // 输入新结点的值
        p->next = NULL;        // p为最后一个结点，next为NULL
        r->next = p;           // 将p接到尾结点
        r = p;                 // r指向新的尾结点
    }
}
