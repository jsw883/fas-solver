// =============================================================================

/* Title   : fas.h
 * Summary : Solvers for the Feedback Arc Set (FAS)
 * Author  : James Williams
 * Date    : 2015-09-15
 * Version : 1.0
 * 
 * These solvers for the Feedback Arc Set (FAS) are from the paper by Hassin and
 * Rubinstein, "Approximations for the maximum acyclic subgraph problem" (1994).
 * 
 * Method 1
 * 
 * Let A1 = {(i,j) ∈ A | i < j}, A2 = {(i,j) ∈ A | i > j}. Clearly, (V, A1) and
 * (V, A2) are directed acyclic graphs, and since A1 ∪ A2 = A, we have the bound
 * max(w(A1), w(A2)) ≥ 0.5*w(A), where w(α) is the sum of weights in the induced
 * subgraph (V, α).
 */

// =============================================================================
// Headers

#ifndef FAS_H
#define FAS_H

#include "graph.h"

// =============================================================================
// Feedback Arc Set (FAS)

// Method 1
template<typename EdgeW>
void fas_method1(Graph<EdgeW>& source_graph, Graph<EdgeW>& output_graph) {
  
  // declare variables for while loop
  Graph<EdgeW> graph1, graph2;
  typename std::unordered_map<int, typename Graph<EdgeW>::Node>::iterator node_iter,
    src_iter, dst_iter;
  typename std::vector<std::pair<int, EdgeW> > edges;
  typename std::vector<std::pair<int, EdgeW> >::iterator edge_iter;
  int src_id, dst_id;
  EdgeW w;
  bool src_flag, dst_flag;
  
  // iterate nodes
  for (node_iter = source_graph.nodes.begin();
    node_iter != source_graph.nodes.end(); node_iter++) {
    
    // get src id
    src_id = node_iter->first;
    
    // iterate out edges (as in edges are copies for traversal efficiency)
    edges = node_iter->second.out_edges;
    for (edge_iter = edges.begin(); edge_iter != edges.end(); edge_iter++) {
      
      // get dst id and w
      dst_id = edge_iter->first;
      w = edge_iter->second;
      
      // select graph reference based on node id inequality 
      Graph<EdgeW>& active_graph = (src_id < dst_id) ? graph1 : graph2;
        
      // attempt to insert node and / or get iterator
      unpair(src_iter, src_flag) = active_graph.nodes.emplace(src_id,
        typename Graph<EdgeW>::Node(src_id));
      unpair(dst_iter, dst_flag) = active_graph.nodes.emplace(dst_id,
        typename Graph<EdgeW>::Node(dst_id));
      active_graph.num_nodes += src_flag + dst_flag;
      
      // add edge
      src_iter->second.out_edges.push_back(std::make_pair(dst_id, w));
      dst_iter->second.in_edges.push_back(std::make_pair(src_id, w));
      active_graph.num_edges++;
      active_graph.sum_weights += w;
      
    }
    
  }
  
  // return graph with most weight retained
  output_graph = (graph1.sum_weights > graph2.sum_weights) ? graph1 : graph2;
  
}

// =============================================================================

#endif

// =============================================================================
