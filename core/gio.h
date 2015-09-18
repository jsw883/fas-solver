// =============================================================================

/* Title   : gio.cpp
 * Summary : Methods for graph input / output functionality
 * Author  : James Williams
 * Date    : 2015-09-17
 * Version : 1.0
 * 
 * Implements load and save methods for graph input / output functionality.
 */

// =============================================================================
// Headers

#ifndef GIO_H
#define GIO_H

#include <fstream>

#include "unpair.h"
#include "graph.h"

// =============================================================================

// Load a saved graph edgelist (directed, possibly weighted)
template<typename EdgeW>
void load_graph(Graph<EdgeW>& graph, char *filename, bool weighted) {
  
  // file input stream for reading
  std::ifstream finput;
  finput.open(filename);
  
  // declare variables for while loop
  typename std::unordered_map<int, typename Graph<EdgeW>::Node>::iterator iter,
    src_iter, dst_iter;
  int src_id, dst_id;
  EdgeW w = 1;
  bool src_flag, dst_flag;
  
  // initialize counters
  graph.num_nodes = 0;
  graph.num_edges = 0;
  graph.sum_weights = 0;
  
  // while there exist edges to read
  while (!finput.eof()) {
    
    // read edge
    if (weighted) {
      finput >> src_id >> dst_id >> w;
    } else {
      finput >> src_id >> dst_id;
    }
    
    // attempt to insert node and / or get iterator
    unpair(src_iter, src_flag) = graph.nodes.emplace(src_id,
      typename Graph<EdgeW>::Node(src_id));
    unpair(dst_iter, dst_flag) = graph.nodes.emplace(dst_id,
      typename Graph<EdgeW>::Node(dst_id));
    graph.num_nodes += src_flag + dst_flag;
    
    // add edge
    src_iter->second.out_edges.push_back(std::make_pair(dst_id, w));
    dst_iter->second.in_edges.push_back(std::make_pair(src_id, w));
    graph.num_edges++;
    graph.sum_weights += w;
    
  }
  
  finput.close();
  
}

// Save a graph edgelist (directed, possibly weighted)
template<typename EdgeW>
void save_graph(Graph<EdgeW>& graph, char *filename, bool weighted) {
  
  // file output stream for writing
  std::ofstream foutput;
  foutput.open(filename);
  
  // declare variables for while loop
  typename std::unordered_map<int, typename Graph<EdgeW>::Node>::iterator
    node_iter;
  typename std::vector<std::pair<int, EdgeW> > edges;
  typename std::vector<std::pair<int, EdgeW> >::iterator edge_iter;
  int src_id, dst_id;
  EdgeW w = 1;
  
  // iterate nodes
  for (node_iter = graph.nodes.begin(); node_iter != graph.nodes.end();
    node_iter++) {
    
    // get src id
    src_id = node_iter->first;
    
    // iterate out edges (as in edges are copies for traversal efficiency)
    edges = node_iter->second.out_edges;
    for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++) {
      
      // get dst id and w
      dst_id = edge_iter->first;
      w = edge_iter->second;
      
      // write edge
      if (weighted) {
        foutput << src_id << " " << dst_id << " " << w << "\n";
      } else {
        foutput << src_id << " " << dst_id << "\n";
      }
      
    }
    
  }
  
  foutput.close();
  
}

// =============================================================================

#endif

// =============================================================================