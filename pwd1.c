#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
/* getwd()  does  not malloc(3) any memory.  The buf argument should be a pointer to an array at least PATH_MAX bytes long.  If the length of the absolute pathname of the cur‐
       rent working directory, including the terminating null byte, exceeds PATH_MAX bytes, NULL is returned, and errno is set  to  ENAMETOOLONG.   (Note  that  on  some  systems,
       PATH_MAX may not be a compile-time constant; furthermore, its value may depend on the filesystem, see pathconf(3).)  For portability and security reasons, use of getwd() is
       deprecated.*/
int
main ()
{
  int i;
  char buffer[PATH_MAX];
  char *x = getcwd (buffer, PATH_MAX);
  if (x == NULL)
    {
      printf ("system failed\n");
      exit (-2);
    }
  else
    printf ("%s\n", x);
  return 0;
}
