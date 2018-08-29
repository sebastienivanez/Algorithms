/*! \file
 * Description
 */
 
/* INCLUDES */
#include <stdio.h> // To call printf()
#include <stdbool.h> // To use bool in c
#include <time.h>

/* MACROS */

/*!
 * \details Quadratic solution n²
 * \author  Sebastien Ivanez
 * \date    29/08/18
 */
bool quadraticSolution(const unsigned int *data, const unsigned int sum)
{
  for (unsigned int i = 0; i < sizeof(data); i++)
    for (unsigned int j = i+1; j < (sizeof(data)-1); j++)
      if ((data[i] + data[j]) == sum)
        return true;
  
  return false;
}

/*!
 * \details Log solution nln(n)
 * \author  Sebastien Ivanez
 * \date    29/08/18
 */
bool logSolution(const unsigned int *data, const unsigned int sum)
{
  unsigned int data_tmp;

  for (unsigned int i = 0; i < sizeof(data); i++) {
    data_tmp = sum - data[i];

    for (unsigned int j = i+1; j < (sizeof(data)-1); j++)
      if (data[j] == data_tmp)
        return true;
  }
  
  return false;
}

/*!
 * \details Linear solution n
 * \author  Sebastien Ivanez
 * \date    29/08/18
 */
bool linearSolution(const unsigned int *data, const unsigned int sum)
{
  unsigned int i = 0;
  unsigned int j = sizeof(data)-1;
  
  while (i < j)  {
    if ((data[i] + data[j]) < sum)
      i++;
    else if ((data[i] + data[j]) > sum)
      j--;
    else
      return true;
  }

  return false;
}

/*!
 * \details Entry function to project.
 * \author  Sebastien Ivanez
 * \date    29/08/18
 */
int main() 
{
  const unsigned int a[] = {1,2,4,4};
  const unsigned int sum = 8;
  bool result = false;
  clock_t time;

//  result = quadraticSolution(a, sum);
//  result = logSolution(a, sum);
  result = linearSolution(a, sum);
  time = clock();

  printf("Result = %u in %f\n", result, (double)time/CLOCKS_PER_SEC);
	return 0;
}
