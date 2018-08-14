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

/* MACROS */
void test_union_find();

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
