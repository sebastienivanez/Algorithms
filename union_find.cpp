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
    this->id[i] = i; // Set id of each objects to itself
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
 * \details  Return id of connected component corresponding to object p
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int UnionFind::find(int p) {
  int p_tmp = p;

  while (p_tmp != (this->id[p_tmp]))
    p_tmp = this->id[p_tmp];

  while (p != p_tmp) {
    int pid = this->id[p];

    this->id[p] = p_tmp;
    p = pid;
  }

  return p_tmp;
}

/*!
 * \details Connect objects p and q
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
void UnionFind::connect(int p, int q) {
  int pid = find(p);
  int qid = find(q);

  if (pid == qid)
    return;
		
  // make smaller root point to larger one
  if (this->cc_size[pid] < this->cc_size[qid]) { 
		this->id[pid] = qid; 
		this->cc_size[qid] += this->cc_size[pid]; 
	} else {
		this->id[qid] = pid; 
		this->cc_size[pid] += this->cc_size[qid]; 
	}

  this->nb_cc--;
}

/*!
 * \details Return true if objects p and q are connected
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
bool UnionFind::connected(int p, int q) {
  return (find(p) == find(q));
}

/*!
 * \details Counts number of connected components
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
int UnionFind::count() {
  return this->nb_cc;
}
