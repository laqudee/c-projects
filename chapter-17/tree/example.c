/** use Tree Type */
/** 使用二叉查找树 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "../util.h"

char menu(void);

void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *str);

int main(void)
{
  Tree pets;
  char choice;
  InitializeTree(&pets);
  while((choice = menu()) != 'q')
  {
    switch(choice)
    {
      case 'a': addpet(&pets); break;
      case 'l': showpets(&pets); break;
      case 'f': findpet(&pets); break;
      case 'n': printf("%d pets\n", TreeItemCount(&pets)); break;
      case 'd': droppet(&pets); break;
      default: puts("Switching error");
    }
  }
  DeleteAll(&pets);
  puts("Done");
  return 0;
}

char menu(void)
{
  int ch;
  puts("Neville Pet Club Membership System");
  puts("a) add pet      l) show list of pets");
  puts("f) find pet     n) number of pets");
  puts("d) drop pet     q) quit");
  while((ch=getchar()) != EOF)
  {
    while(getchar() != '\n')
      continue;
    ch = tolower(ch);
    if (strchr("alrfdnq", ch) == NULL)
      puts("Please enter a, l, f, d, n, or q");
    else
      break;
  }
  if (ch == EOF)
    ch = 'q';
  return ch;
}

void addpet(Tree * pt)
{
  Item temp;
  if (TreeIsFull(pt))
    puts("No room in club.");
  else
  {
    puts("enter name of pet:");
    s_gets(temp.petname, SLEN);
    puts("enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    AddItem(&temp, pt);
  }
}

void showpets(const Tree * pt)
{
  if (TreeIsEmpty(pt))
    puts("No pets.");
  else
    Traverse(pt, printitem);
}

void printitem(Item item)
{
  printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}

void findpet(const Tree *pt)
{
  Item temp;
  if (TreeIsEmpty(pt))
  {
    puts("No entries.");
    return;
  }
  puts("enter name of pet you wish to find:");
  s_gets(temp.petname, SLEN);
  puts("enter kind of pet:");
  s_gets(temp.petkind, SLEN);
  uppercase(temp.petname);
  uppercase(temp.petkind);
  printf("%s the %s ", temp.petname, temp.petkind);
  if(InTree(&temp, pt))
    puts("is in the club.");
  else
    puts("is not in the club.");
}

void droppet(Tree *pt)
{
  Item temp;
  if (TreeIsEmpty(pt))
  {
    puts("No pets.");
    return;
  }
  puts("enter name of pet you wish to remove:");
  s_gets(temp.petname, SLEN);
  puts("enter kind of pet:");
  s_gets(temp.petkind, SLEN);
  uppercase(temp.petname);
  uppercase(temp.petkind);
  if (DeleteItem(&temp, pt))
    puts("The pet was removed.");
  else
    puts("The pet was not found.");
}

void uppercase(char *str)
{
  while (*str)
  {
    *str = toupper(*str);
    str++;
  }
}

