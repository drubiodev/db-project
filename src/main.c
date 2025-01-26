#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

// #include "common.h"
#include "file.h"
// #include "parse.h"

void print_usage(char *argv[])
{
  printf("Usage: %s -f <filepath> [-n] [-p <port>] [-l]\n", argv[0]);
  printf("Options:\n");
  printf("  -f <filepath>  Path to the file to be served\n");
  printf("  -n             Create a new file\n");
  printf("  -p <port>      Port to listen on\n");
  printf("  -l             List files in the directory\n");

  return;
}

int main(int argc, char *argv[])
{
  char *filepath = NULL;
  char *portarg = NULL;
  unsigned short port = 0;
  bool newfile = false;
  bool list = false;
  int c;
  int dbfd = -1;

  while ((c = getopt(argc, argv, "nf:a:l")) != -1)
  {
    switch (c)
    {
    case 'n':
      newfile = true;
      break;
    case 'f':
      filepath = optarg;
      break;
    case 'p':
      portarg = optarg;
      break;
    case 'l':
      list = true;
      break;
    case '?':
      printf("Unknown option -%c\n", c);
      break;
    default:
      return -1;
    }
  }

  // require filepath
  if (filepath == NULL)
  {
    printf("Filepath is required argument\n");
    print_usage(argv);
    return -1;
  }

  // create file
  if (newfile)
  {
    dbfd = create_db_file(filepath);
  }
}
