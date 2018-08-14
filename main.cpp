/*! \file
 * Test file for algorithms
 */
 
/* INCLUDES */
//#include <cstdlib> // To call atoi()
//#include <fcntl.h> // To call open()
//#include <iomanip> // To call setw()
#include <iostream> // To call cout/cin
//#include <sstream> // To call stringstream
//#include <stdint.h> // To use uint8_t
//#include <stdlib.h> // To call malloc()/sleep()
//#include <unistd.h> // To call read()
#include "quick_find.cpp"
#include "quick_union.cpp"
#include "quick_union_improved.cpp"

/* MACROS */
void test_quick_find();
void test_quick_union();
void test_quick_union_improved();

/*! \namespace std */
using namespace std;

/*!
 * \details Entry function to project.
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int main() 
{
  test_quick_find();
  test_quick_union();
  test_quick_union_improved();
  return 0;
}

/*!
 * \details Test for quick find algorithm from coursera
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void test_quick_find()
{
  QuickFind qf(10);
  int cost = 0;

  qf.connect(4, 3);
  cost = qf.getCost();
  cout << "qf cost = " << cost << endl;
}

/*!
 * \details Test for quick union algorithm from coursera
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void test_quick_union()
{
  QuickUnion qu(10);
  int cost = 0;

  qu.connect(4, 3);
  cost = qu.getCost();
  cout << "qu cost = " << cost << endl;
}

/*!
 * \details Test for quick union improved algorithm from coursera
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void test_quick_union_improved()
{
  QuickUnionImproved qui(10);
  int cost = 0;

  qui.connect(4, 3);
  cost = qui.getCost();
  cout << "qui cost = " << cost << endl;
}
