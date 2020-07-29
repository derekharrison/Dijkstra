/*
 * functions.hpp
 *
 *  Created on: Jul 29, 2020
 *      Author: d-w-h
 */

#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

const int inf = 3e+8;

bool** bool2D(const int size);
float** float2D(const int size);
void delete_bool2D(bool** p, int size);
void delete_float2D(float** p, int size);
void init_bool2d(bool** bool2d, bool** bool2d_ref, int size_graph);
void init_weight2d(float** weight2d, float** weight2d_ref, int size_graph);
void init_sum_node(float* sum_node, int size_graph);
void init_visited(bool* visited, int size_graph);
void init_adj_and_weight(bool** bool2d, float** weight2d, int size_graph);
void populate_adj_and_weight(bool** bool2d, float** weight2d, int size_graph, float density);
#endif /* FUNCTIONS_HPP_ */
