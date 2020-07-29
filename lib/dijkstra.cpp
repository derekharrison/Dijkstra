/*
 * dijkstra.cpp
 *
 *  Created on: Jul 29, 2020
 *      Author: d-w-h
 */

#include <iostream>

#include "../inc/dijkstra.hpp"
#include "../inc/functions.hpp"

Dijkstra::Dijkstra(bool** bool2d, float** weight2d, int size_graph) {
    this->size_graph = size_graph;

    this->bool2d = bool2D(size_graph);
    init_bool2d(this->bool2d, bool2d, size_graph);

    this->weight2d = float2D(size_graph);
    init_weight2d(this->weight2d, weight2d, size_graph);

    this->sum_node = new float[size_graph];
    init_sum_node(this->sum_node, size_graph);

    this->visited = new bool[size_graph];
    init_visited(this->visited, size_graph);

    prev_vertex = new int[size_graph];
}

Dijkstra::~Dijkstra() {
    delete_bool2D(this->bool2d, size_graph);
    delete_float2D(this->weight2d, size_graph);
    delete [] this->sum_node;
    delete [] this->visited;
    delete [] this->prev_vertex;
}

bool Dijkstra::check_unvisited(bool* visited, int size_graph) {
    for(int i = 0; i < size_graph; ++i) {
        if(visited[i] == false) {
            return false;
        }
    }

    return true;
}

void Dijkstra::dijkstra_algo() {
    int current_node = 0;
    int it_counter = 0;
    bool unvisited_is_empty = check_unvisited(visited, size_graph);
    while(unvisited_is_empty == false) {
        float min_dist = inf;
        for(int node = 0; node < size_graph; ++node) {
            if(bool2d[current_node][node] && !visited[node] && sum_node[node] > sum_node[current_node] + weight2d[current_node][node]) {
                sum_node[node] = sum_node[current_node] + weight2d[current_node][node];
                prev_vertex[node] = current_node;
            }
        }

        for(int node = 0; node < size_graph; ++node) {
            if(min_dist > sum_node[node] && !visited[node]) {
                min_dist = sum_node[node];
                current_node = node;
            }
        }

        visited[current_node] = true;
        unvisited_is_empty = check_unvisited(visited, size_graph);
        it_counter++;
        if(it_counter > size_graph + 2) {
            printf("Entered infinite loop, some vertices could not be reached\n");
            break;
        }
    }
}

void Dijkstra::print_results() {
    printf("vertex: 0, distance from vertex 0: %.1E\n", this->sum_node[0]);
    for(int i = 1; i < this->size_graph; ++i) {
        printf("vertex: %i, distance from vertex 0: %.2E, previous vertex: %i\n",
                i, this->sum_node[i], this->prev_vertex[i]);
    }
}

void Dijkstra::print_adj_mat() {
    printf("adjancy matrix\n");
    for(int i = 0; i < this->size_graph; ++i) {
        for(int j = 0; j < this->size_graph; ++j) {
            printf("(%i,%i): %d ", i, j, this->bool2d[i][j]);
        }
        printf("\n");
    }
}

void Dijkstra::print_weight_mat() {
    printf("weight matrix\n");
    for(int i = 0; i < this->size_graph; ++i) {
        for(int j = 0; j < this->size_graph; ++j) {
            printf("(%i,%i): %.1f ", i, j, this->weight2d[i][j]);
        }
        printf("\n");
    }
}

float Dijkstra::avg_path() {
    float avg_path = 0.0;

    for(int i = 0; i < this->size_graph; i++) {
        avg_path += sum_node[i];
    }

    return avg_path = avg_path / (size_graph - 1);
}
