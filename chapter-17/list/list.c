/** 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/** 局部函数原型 */
static void CopyToNode(Item item, Node * pnode);

/** 接口函数 */
/** 把链表设置为空 */
void InitializeList(List * plist)
{
  *plist = NULL;
}

bool ListIsEmpty(const List * plist)
{
  if (*plist == NULL)
    return true;
  else
    return false;
}

bool ListIsFull(const List * plist)
{
  Node * pt;
  bool full;
  pt = (Node *) malloc(sizeof(Node));
  if (pt == NULL)
    full = true;
  else
    full = false;
  free(pt);

  return full;
}

unsigned int ListItemCount(const List * plist)
{
  unsigned int count = 0;
  Node * pnode = *plist; /** 设置链表的开始 */
  while(pnode != NULL)
  {
    ++count;
    pnode = pnode->next; /** 设置下一个节点 */
  }
  return count;
}

bool AddItem(Item item, List * plist)
{
  Node * pnew;
  Node * scan = *plist;
  pnew = (Node *)malloc(sizeof(Node));
  if (pnew == NULL)
    return false; /** 失败时退出函数 */
  CopyToNode(item, pnew);
  pnew->next = NULL;
  if(scan == NULL)
    *plist = pnew;
  else
  {
    while(scan->next != NULL)
      scan = scan->next;
    scan->next = pnew;
  }
  return true;
}

void TraverseList(const List * plist, void (*pfun)(Item item))
{
  Node * pnode = *plist;
  while(pnode != NULL)
  {
    (*pfun)(pnode->item);
    pnode = pnode->next;
  }
}

void EmptyTheList(List * plist)
{
  Node * psave;
  while(*plist != NULL)
  {
    psave = (*plist)->next; /** 保存下一个节点的地址 */
    free(*plist); /** 释放当前节点 */
    *plist = psave; /** 前进至下一个节点 */
  }
}

/** 局部函数定义 */
static void CopyToNode(Item item, Node * pnode)
{
  pnode->item = item; /** 拷贝结构 */
}
