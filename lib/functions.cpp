/*
 * functions.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: d-w-h
 */

#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../inc/functions.hpp"

bool** bool2D(const int size) {
    bool** p = new bool*[size];

    for(int i = 0; i < size; ++i)
        p[i] = new bool[size];

    return p;
}

float** float2D(const int size) {
    float** p = new float*[size];

    for(int i = 0; i < size; ++i)
        p[i] = new float[size];

    return p;
}

void delete_bool2D(bool** p, int size) {
    for(int i = 0; i < size; ++i)
        delete [] p[i];

    delete [] p;
}

void delete_float2D(float** p, int size) {
    for(int i = 0; i < size; ++i)
        delete [] p[i];

    delete [] p;
}

void init_adj_mat(bool** adj_mat, bool** adj_mat_ref, int size_graph) {
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j) {
            adj_mat[i][j] = adj_mat_ref[i][j];
        }
}

void init_weight_mat(float** weight_mat, float** weight_mat_ref, int size_graph) {
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j) {
        	weight_mat[i][j] = weight_mat_ref[i][j];
        }
}

void init_sum_node(float* sum_node, int size_graph) {
    sum_node[0] = 0.0;
    for(int i = 1; i < size_graph; ++i) {
        sum_node[i] = inf;
    }
}

void init_visited(bool* visited, int size_graph) {
    visited[0] = true;
    for(int i  = 1; i < size_graph; ++i) {
        visited[i] = false;
    }
}

void init_adj_and_weight(bool** adj_mat, float** weight_mat, int size_graph) {
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j) {
            adj_mat[i][j] = false;
            weight_mat[i][j] = 0.0;
        }
}

void populate_adj_and_weight(bool** adj_mat, float** weight_mat, int size_graph, float density) {
    init_adj_and_weight(adj_mat, weight_mat, size_graph);
	srand(time(NULL));
    float max_weight = 10;
    for(int i = 0; i < size_graph; ++i)
        for(int j = 0; j < size_graph; ++j) {
            float rand_num = (float) rand() / RAND_MAX;
            if(i != j) {
                adj_mat[i][j] = rand_num > (1 - density);
                if(adj_mat[i][j] == true) {
                    rand_num = (float) rand() / RAND_MAX;
                    weight_mat[i][j] = max_weight * rand_num;
                }
            }
        }
}
