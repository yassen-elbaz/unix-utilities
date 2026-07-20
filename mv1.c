#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int
main (int argc, char *argv[])
{
  if (argc != 3)
    {
      printf ("Usage: %s <source> <destination>\n", argv[0]);
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
      printf ("Could not create destination file\n");
      close (fd1);
      exit (-3);
    }

  char buf[100];
  int num_read;

  while ((num_read = read (fd1, buf, sizeof (buf))) > 0)
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

  if (unlink (argv[1]) != 0)
    {
      printf ("Could not delete source file\n");
      exit (-6);
    }

  return 0;
}
