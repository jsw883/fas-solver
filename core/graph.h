// =============================================================================

/* Title   : graph.h
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

#ifndef GRAPH_H
#define GRAPH_H

#include <utility>
#include <unordered_map>
#include <vector>

// =============================================================================
// Graph class

template <class EdgeW>
class Graph {
  public:
    // declare data structures
    typedef std::pair<int, EdgeW> Edge;
    class Node {
      public:
        int id_;
        std::vector<Edge> in_edges, out_edges;
      public:
        Node(int id) : id_(id) { }
    };
  public:
    // declare variables
    std::unordered_map<int, Node> nodes;
    int num_nodes;
    int num_edges;
    EdgeW sum_weights;
  public:
    // constructors
    Graph() : num_nodes(0), num_edges(0), sum_weights(0) { }
    // supplementary
    void clear();
    void summary();
};

// empty everything
template <class EdgeW>
void Graph<EdgeW>::clear() {
  // clear node map
  nodes.clear();
  // reset counters
  num_nodes = 0;
  num_edges = 0;
  sum_weights = 0;
}

// print simple graph summary
template <class EdgeW>
void Graph<EdgeW>::summary() {
  // print summary
  printf("summary\n");
  printf("  nodes: %d\n", num_nodes);
  printf("  edges: %d\n", num_edges);
  printf("  sum of weights: %f\n", sum_weights);
}

// =============================================================================

#endif

// =============================================================================