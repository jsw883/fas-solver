// =============================================================================

/* Title   : graph.cpp
 * Summary : Directed, weighted graph data structure using C++11
 * Author  : James Williams
 * Date    : 2015-09-15
 * Version : 1.0
 * 
 * Implements a directed, weighted graph data structure based on the new C++11
 * unordered map for efficient node storage, where edges are stored in vectors
 * under each node, where edge weights are duplicated to prevent cache misses.
 * 
 * Currently, variables are public and can be manipulated directly, but should
 * eventually be private with an appropriate collection of getters and setters
 * allowing nodes and edges to be accessed conveniently (and yet efficiently).
 * 
 * The edge vectors should be implemented as a set, which is based on a binary
 * search tree, allowing for fast search, insertion, and deletion of nodes, as
 * graphs are often manipulated during algorithms.
 */

// =============================================================================
// Headers
 
#include "graph.h"

// =============================================================================