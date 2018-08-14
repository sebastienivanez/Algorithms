/*! \file
 * Algorithm to solve dynamic connectivity problem
 *
 * Problem:
 *   Given a set of N objects.
 *   . Connect/Union command: connect two objects
 *   . Connected/Find query: Is there a path connecting the two objects ?
 */
#ifndef _UNION_FIND_H
#define _UNION_FIND_H
   
/* INCLUDES */

/* MACROS */

/*!
 * \details class
 * \author  Sebastien Ivanez
 * \date    14/08/2018
 */
class UnionFind {
  int *id; // Id of object
  int *cc_size; // Size of connected component
  int nb_cc; // Number of connected components

  int find(int p); // Private method only accessible by class methods

  public:
    // Constructors
    UnionFind(int N);
    ~UnionFind();

    // Other methods
    void connect(int p, int q);
    bool connected(int p, int q);
    int count();
};
#endif
