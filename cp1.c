#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      printf ("Usage: %s file-name\n", argv[0]);
      exit (-1);
    }
  int fd1 = open (argv[1], O_RDONLY);
  if (fd1 < 0)
    {
      printf ("Could not open source file\n");
      exit (-2);
    }
  int fd2 = open (argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);


  if (fd2 < 0)
    {
      printf ("Could not open destination file\n");
      exit (-3);
    }
  char buf[100];
  int num_read;

  while ((num_read = read (fd1, buf, 100)) > 0)
    {
      if (write (fd2, buf, num_read) < 0)
	{
	  printf ("Write failed\n");
	  close (fd1);
	  close (fd2);
	  exit (-4);
	}
    }

  if (num_read < 0)
    {
      printf ("Read failed\n");
      close (fd1);
      close (fd2);
      exit (-5);
    }

  close (fd1);
  close (fd2);
  return 0;
}
