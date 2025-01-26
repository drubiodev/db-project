#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "file.h"
#include "common.h"

int create_db_file(char *filename)
{
  // check if file exists
  int fd = open(filename, O_RDONLY);
  if (fd != -1)
  {
    close(fd);
    printf("File already exists\n");
    return STATUS_ERROR;
  }

  // create file
  fd = open(filename, O_RDWR | O_CREAT, 0644);

  if (fd == -1)
  {
    perror("open");
    return STATUS_ERROR;
  }

  return fd;
}