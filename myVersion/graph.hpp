#ifndef MY_GRAPH_HPP
#define MY_GRAPH_HPP

#include <vector>

namespace myGraph
{
    struct graph
    {
        std::vector<std::vector<size_t>> adjacencyMatrix;

        graph(const size_t size);
        graph(graph &&other);
        
        void addEdge(const size_t node1, const size_t node2);

        [[nodiscard]] std::vector<size_t> bfs(const size_t node);
    };
}

#endif // MY_GRAPH_HPP