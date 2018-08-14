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
#include "union_find.cpp"
#include "quick_find.cpp"
#include "quick_union.cpp"

/* MACROS */
void test_union_find();
void test_quick_find();
void test_quick_union();

/*! \namespace std */
using namespace std;

/*!
 * \details Entry function to project.
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int main() 
{
  test_union_find();
  test_quick_find();
  test_quick_union();
  return 0;
}

/*!
 * \details Test for union find algorithm from coursera
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void test_union_find()
{
  UnionFind uf(10);
  bool reply;

  uf.connect(4, 3);
  uf.connect(3, 8);
  uf.connect(6, 5);
  uf.connect(9, 4);
  uf.connect(2, 1);
  reply = uf.connected(0, 7);
  cout << "uf.connected(0, 7) = " << reply << endl;
  reply = uf.connected(8, 9);
  cout << "uf.connected(8, 9) = " << reply << endl;
}

/*!
 * \details Test for quick find algorithm from coursera
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void test_quick_find()
{
  QuickFind qf(10);
  bool reply;

  qf.connect(4, 3);
  qf.connect(3, 8);
  qf.connect(6, 5);
  qf.connect(9, 4);
  qf.connect(2, 1);
  reply = qf.connected(0, 7);
  cout << "qf.connected(0, 7) = " << reply << endl;
  reply = qf.connected(8, 9);
  cout << "qf.connected(8, 9) = " << reply << endl;
}

/*!
 * \details Test for quick find algorithm from coursera
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void test_quick_union()
{
  QuickUnion qu(10);
  bool reply;

  qu.connect(4, 3);
  qu.connect(3, 8);
  qu.connect(6, 5);
  qu.connect(9, 4);
  qu.connect(2, 1);
  reply = qu.connected(0, 7);
  cout << "qu.connected(0, 7) = " << reply << endl;
  reply = qu.connected(8, 9);
  cout << "qu.connected(8, 9) = " << reply << endl;
}
