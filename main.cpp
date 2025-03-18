#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "graph.hpp"

[[nodiscard]] myGraph::graph fileToMyGraph(std::istream &in)
{
    size_t size;
    in >> size;
    myGraph::graph gr{size}; // Инициализируем граф
    for (;size > 0; --size) // заполняем рёбра
    {
        size_t node1;
        size_t node2;

        in >> node1 >> node2;

        gr.addEdge(node1, node2);
    }
    return gr;
}

int main()
{
    try
    {
        std::ifstream in{"graph.txt"}; // Открываем файл graph.txt
        if (!in.is_open()) return 1; // Если программа не смогла открыть этот файл завершаем программу с кодом ошибки 1
        myGraph::graph gr{fileToMyGraph(in)};
        size_t start;
        in >> start;
        in.close();
        auto distances = gr.bfs(start);
        std::for_each(distances.cbegin(), distances.cend(), [](const size_t &dist)
        {
            std::cout << dist << std::endl;
        });
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}