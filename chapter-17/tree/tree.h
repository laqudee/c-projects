/** 二叉查找树 */
/** 树中不允许有重复项 */
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define SLEN 20

typedef struct item {
  char petname[SLEN];
  char petkind[SLEN];
} Item;

#define MAXITEMS 10

typedef struct trnode {
  Item item;
  struct trnode *left; /** 指向左分枝的指针 */
  struct trnode *right; /** 指向右分枝的指针 */
} Trnode;

typedef struct tree {
  Trnode *root; /** 根节点指针 */
  int size; /** 树的大小 */
} Tree;

/** 初始化二叉查找树 */
void InitializeTree(Tree *ptree);

/** tree is empty or not */
bool TreeIsEmpty(const Tree *ptree);

/** tree is full or not */
bool TreeIsFull(const Tree *ptree);

/** count of tree nodes */
int TreeItemCount(const Tree *ptree);

/** add item to tree */
bool AddItem(const Item *pi, Tree *ptree);

/** find item in tree */
bool InTree(const Item *pi, const Tree *ptree);

/** delete item from tree */
bool DeleteItem(const Item *pi, Tree *ptree);

/** 将函数应用于树中的每一项 */
void Traverse(const Tree *ptree, void (*pf)(Item));

/** delete all items */
void DeleteAll(Tree *ptree);

#endif
