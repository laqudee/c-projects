#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

enum spectrum { red, orange, yellow, green, blue, violet};
const char *colors [] = { "red", "orange", "yellow", "green", "blue", "violet"};
#define LEN 30

int main(void)
{
  char choice[LEN];
  enum spectrum color;
  bool color_is_found = false;

  puts("Enter a color (empty line to quit):");
  while(s_gets(choice, LEN) != NULL && choice[0] != '\0')
  {
    for(color = red; color <= violet; color++)
    {
      if (strcmp(choice, colors[color]) == 0)
      {
        color_is_found = true;
        break;
      }
    }
    if (color_is_found)
      switch(color)
      {
        case red: puts("Rose are red.");
          break;
        case orange: puts("Orange are orange.");
          break;
        case yellow: puts("Yellow are yellow.");
          break;
        case green: puts("Green are green.");
          break;
        case blue: puts("Blue are blue.");
          break;
        case violet: puts("Violet are violet.");
          break;
      }
    else
      puts("Not found.");
    color_is_found = false;
    puts("Next color, please (empty line to quit):");
  }
  puts("Goodbye!");

  return 0;
}
