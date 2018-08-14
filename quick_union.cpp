/*! \file
 * Description
 */
 
/* INCLUDES */
//#include <cstdlib> // To call atoi()
//#include <fcntl.h> // To call open()
//#include <iomanip> // To call setw()
//#include <iostream> // To call cout/cin
//#include <sstream> // To call stringstream
//#include <stdint.h> // To use uint8_t
//#include <stdlib.h> // To call malloc()/sleep()
//#include <unistd.h> // To call read()
#include "quick_union.hpp"

/* MACROS */

/*! \namespace std */
using namespace std;

/*!
 * \details Constructor of QuickUnion class containing N objects. Set id of each objects to itself.
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
QuickUnion::QuickUnion(int N) {
  this->id = new int[N];
  this->size = N;

  for (int i = 0; i < N; i++)
    this->id[i] = i;
}

/*!
 * \details Destructor of QuickUnion class
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
QuickUnion::~QuickUnion() {
  delete [] this->id;
}

/*!
 * \details Chase parent pointers until reach root
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int QuickUnion::root(int p) {
  while (p != this->id[p])
    p = this->id[p];
    
  return p;
}

/*!
 * \details Connect objects p and q
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void QuickUnion::connect(int p, int q) {
  int i = root(this->id[p]);
  int j = root(this->id[q]);
	
	this->id[i] = j; // Change root of p to point to root of q
}

/*!
 * \details Return true if objects p and q are connected.
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
bool QuickUnion::connected(int p, int q) {
  return (root(this->id[p]) == root(this->id[q])); // Check if p and q have the same root
}
