/** 简单链表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#define TSIZE 45

struct film{
  char title[TSIZE];
  int rating;
};

typedef struct film Item;
typedef struct node {
  Item item;
  struct node* next;
} Node;

typedef Node * List;

/**
 * @brief 函数原型
 * 操作：初始化一个链表
 * 前提条件：plist指向一个链表
 * 后置条件：链表被初始化为空
 */
void InitializeList(List * plist);

/** 确定链表是否为空定义 */
bool ListIsEmpty(const List *plist);

/** 确认链表是否已满 */
bool ListIsFull(const List * plist);

/** 确认链表中的项数 */
unsigned int ListItemCount(const List * plist);

/** 在链表末尾添加项 */
bool AddItem(Item item, List *plist);

/** 把函数作用于链表的每一项 */
void TraverseList(const List *plist, void(*pfun)(Item item));

/** 释放已分配的内存 */
void EmptyTheList(List *plist);

#endif


