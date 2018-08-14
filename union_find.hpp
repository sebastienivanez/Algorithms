/*! \file
 * Algorithm to solve dynamic connectivity problem
 *
 * Problem:
 *   Given a set of N objects.
 *   . Union command: connect two objects
 *   . Find/connected query: Is there a path connecting the two objects ?
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

  public:
    // Constructors
    UnionFind(int N);
    ~UnionFind();

    // Set/Get methods

    // Other methods
    void connect(int x, int y);
    bool connected(int x, int y);
    int count();
    int find(int x);
};
#endif
