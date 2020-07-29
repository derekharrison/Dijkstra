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

    /* Initialize adjancy and weight matrices */
    init_adj_and_weight(adj_mat, weight_mat, size_graph);

    /* Populate matrices with random data */
    populate_adj_and_weight(adj_mat, weight_mat, size_graph, density_graph);

    /* Create Dijkstra algorithm object */
    Dijkstra myg(adj_mat, weight_mat, size_graph);

    /* Print adjancy matrix */
    myg.print_adj_mat();

    /* Print weight matrix */
    myg.print_weight_mat();

    /* Execute Dijkstra algorithm */
    myg.dijkstra_algo();

    /* Print results */
    myg.print_results();

    return 0;
}
