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
#include "union_find.hpp"

/* MACROS */

/*! \namespace std */
using namespace std;

/*!
 * \details Constructor of UnionFind class containing N objects
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
UnionFind::UnionFind(int N) {
  this->nb_cc = N;
  this->id = new int[N];
  this->cc_size = new int[N];

  for (int i = 0; i < N; i++) {
    this->id[i] = i;
    this->cc_size[i] = 1; // Set initial size of each connected component to 1
  }
}

/*!
 * \details Destructor of UnionFind class
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
UnionFind::~UnionFind() {
  delete [] this->id;
  delete [] this->cc_size;
}

/*!
 * \details  Return id of connected component corresponding to object x
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int UnionFind::find(int x) {
  int x_tmp = x;

  while (x_tmp != (this->id[x_tmp]))
    x_tmp = this->id[x_tmp];

  while (x != x_tmp) {
    int xid = this->id[x];

    this->id[x] = x_tmp;
    x = xid;
  }

  return x_tmp;
}

/*!
 * \details Connect objects x and y
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void UnionFind::connect(int x, int y) {
  int xid = find(x);
  int yid = find(y);

  if (xid == yid)
    return;
		
  // make smaller root point to larger one
  if (this->cc_size[xid] < this->cc_size[yid]) { 
		this->id[xid] = yid; 
		this->cc_size[yid] += this->cc_size[xid]; 
	} else {
		this->id[yid] = xid; 
		this->cc_size[xid] += this->cc_size[yid]; 
	}

  this->nb_cc--;
}

/*!
 * \details Return true if objects x and y are connected
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
bool UnionFind::connected(int x, int y) {
  return (find(x) == find(y));
}

/*!
 * \details Counts number of connected components
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int UnionFind::count() {
  return this->nb_cc;
}
