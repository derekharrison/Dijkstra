/*
 * main.cpp
 *
 *  Created on: Jul 27, 2020
 *      Author: d-w-h
 */

#include <iostream>
#include <stdio.h>

#include "../inc/dijkstra.hpp"
#include "../inc/functions.hpp"

int main(int argc, char* argv[])
{
    int size_graph = 10;
    float density_graph = 0.5;
    bool** adj_mat = bool2D(size_graph);
    float** weight_mat = float2D(size_graph);
    float* distance_from_start = new float[size_graph];
    int* prev_vertex = new int[size_graph];

    /* Populate adjancy and weight matrices with random data */
    populate_adj_and_weight(adj_mat, weight_mat, size_graph, density_graph);

    /* Create Dijkstra algorithm object */
    Dijkstra myg(adj_mat, weight_mat, size_graph);

    /* Print adjancy matrix */
    myg.print_adj_mat();

    /* Print weight matrix */
    myg.print_weight_mat();

    /* Execute Dijkstra algorithm */
    myg.dijkstra_algo();

    /* Get data */
    myg.get_sum_node(distance_from_start);
    myg.get_prev_vertex(prev_vertex);

    /* Print results */
    myg.print_results();

    /* Free data */
    delete_bool2D(adj_mat, size_graph);
    delete_float2D(weight_mat, size_graph);
    delete [] distance_from_start;
    delete [] prev_vertex;

    return 0;
}
