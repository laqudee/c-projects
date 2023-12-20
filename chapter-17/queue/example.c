/** use Queue */
#include <stdio.h>
#include "queue.h"

int main(void)
{
  Queue line;
  Item temp;
  char ch;
  InitializeQueue(&line);
  puts("Testing the Queue interface. Type a to add value.");
  puts("type d to delete a value, and type q to quit.");
  while((ch = getchar()) != 'q')
  {
    if(ch != 'a' && ch != 'd')
      continue;
    if(ch == 'a')
    {
      printf("Enter an item: ");
      scanf("%d", &temp);
      if(!QueueIsFull(&line))
      {
        printf("Putting %d into queue\n", temp);
        EnQueue(temp, &line);
      }
      else
        puts("Queue is full!");
    }
    else
    {
      if(QueueIsEmpty(&line))
        puts("Queue is empty!");
      else
      {
        DeQueue(&temp, &line);
        printf("Removing %d from queue\n", temp);
      }
    }
    printf("Queue now has %d items\n", QueueItemCount(&line));
    puts("Type a to add, d to delete, q to quit.");
  }
  EmptyTheQueue(&line);
  puts("Done!");
  return 0;
}
