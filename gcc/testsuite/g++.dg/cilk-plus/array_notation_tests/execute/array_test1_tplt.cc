/* { dg-do run } */
/* { dg-options " "} */

#include <cstdlib>
#include <string.h>
template <class T> int main2 (int argc, char **argv);

int main(int argc, char **argv)
{
  int x = 0, y = 0, z = 0;
  if (argc == 1)
    {
      char *array[2];
      array[0] = strdup ("a.out");
      array[1] = strdup ("5");
      y = main2<int> (2, array);
      z = main2<long> (2, array);
      z = main2<long long> (2, array);
    }
  else
    x = main2<int> (argc, argv);
      
  return x+y+z;
}
template <class T>
int main2 (int argc, char **argv)
{
  T array[10];
  int ii = 0, x = 2, z= 0 , y = 0;

  for (ii = 0; ii < 10; ii++)
    array[ii] = 10;

  array[0:10:1] = 15;

  for (ii = 0; ii < 10; ii++)
    if (array[ii] != 15)
      abort ();
  

  array[0:5:2] = 20;

  for (ii = 0; ii < 10; ii += 2)
    if (array[ii] != 20)
      abort ();


  x = atoi(argv[1]);
  z = (10-atoi(argv[1]))/atoi(argv[1]);

  array[x:5:z] = 50;
  
  for (ii = x; ii < 10; ii += z)
    if (array[ii] != 50)
      abort ();

  x = atoi(argv[1]);
  z = (10-atoi(argv[1]))/atoi(argv[1]);
  y = 10-atoi(argv[1]);
  
  array[x:y:z] = 505;
  for (ii = x; ii < 10; ii += z)
    if (array[ii] != 505)
      abort ();
    

  x = atoi(argv[1]);
  z = (10-atoi(argv[1]))/atoi(argv[1]);
  y = 10-atoi(argv[1]);
  
  array[x:y:((10-atoi(argv[1]))/atoi(argv[1]))] = 25;

  for (ii = x; ii < 10; ii += z)
    if (array[ii] != 25)
      abort ();
  
  x = atoi(argv[1]);
  z = (10-atoi(argv[1]))/atoi(argv[1]);
  y = 10-atoi(argv[1]);
 
  array[atoi(argv[1]):(10-atoi(argv[1])):((10-atoi(argv[1]))/atoi(argv[1]))] =
    1400;
  for (ii = x; ii < 10; ii += z)
    if (array[ii] != 1400)
      abort ();
  

  array[atoi("5"):5:1] = 5555;
  
  for (ii = atoi ("5"); ii < 10; ii++)
    if (array[ii] != 5555)
      abort ();
  

  array[atoi("5"):atoi("5"):atoi("1")] = 9999;
  for (ii = atoi ("5"); ii < (atoi ("5") + atoi ("5")); ii += atoi ("1"))
    if (array[ii] != 9999)
      abort ();
  exit (0);
  return 0;
}
