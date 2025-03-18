#include "graph.hpp"

#include <stdexcept>
#include <limits>
#include <queue>

myGraph::graph::graph(const size_t size) : adjacencyMatrix{std::vector<std::vector<size_t>>{size}}
{
}

myGraph::graph::graph(graph &&other) : adjacencyMatrix{std::move(other.adjacencyMatrix)}
{
}
        
void myGraph::graph::addEdge(const size_t node1, const size_t node2)
{
    if (node1 >= adjacencyMatrix.size() || node2 >= adjacencyMatrix.size()) throw std::out_of_range("There are no such nodes!"); // Если таких узлов не существует возвращаем исключение
    adjacencyMatrix[node1].push_back(node2);
    adjacencyMatrix[node2].push_back(node1);
}

[[nodiscard]] std::vector<size_t> myGraph::graph::bfs(const size_t start)
{
    std::vector<size_t> distances(adjacencyMatrix.size(), std::numeric_limits<size_t>::max());
    std::queue<size_t> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) 
    {
        size_t vertex = q.front();
        q.pop();

        for (size_t neighbor : adjacencyMatrix[vertex]) 
        {
            if (distances[neighbor] == std::numeric_limits<size_t>::max()) 
            {
                distances[neighbor] = distances[vertex] + 1;
                q.push(neighbor);
            }
        }
    }
    return distances;
}