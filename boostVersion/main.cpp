#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>

using namespace boost;

// Тип графа: ненаправленный, с целочисленными вершинами
typedef adjacency_list<vecS, vecS, undirectedS> Graph;
typedef graph_traits<Graph>::vertex_descriptor Vertex;

// Посетитель для записи расстояний во время BFS
class DistanceRecorder : public default_bfs_visitor 
{
    private:
        std::vector<size_t>& distances;
    public:
        DistanceRecorder(std::vector<size_t>& distances) : distances(distances) {}

        template <typename Edge, typename Graph>
        void tree_edge(Edge e, const Graph& g) 
        {
            Vertex sour = source(e, g);
            Vertex tar = target(e, g);
            distances[tar] = distances[sour] + 1;
        }
};

[[nodiscard]] Graph fileToMyGraph(std::istream &in)
{
    size_t size;
    in >> size;

    Graph gr(size);

    in >> size;
    for (; size > 0; --size) 
    {
        size_t node1;
        size_t node2;
        in >> node1 >> node2;
        add_edge(node1, node2, gr);
    }
    return gr;
}

int main() 
{
    try
    {
        std::string filename = "graph.txt";
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }
        Graph gr(fileToMyGraph(file));
        size_t start;
        file >> start;
        file.close();

        // Вектор для хранения расстояний
        std::vector<size_t> distances(num_vertices(gr), 0);
        distances.at(start) = 0;

        // Создание посетителя и запуск BFS
        DistanceRecorder vis(distances);
        breadth_first_search(gr, vertex(start, gr), visitor(vis));

        // Вывод результатов
        std::for_each(distances.cbegin(), distances.cend(), [](const size_t &dist)
        {
            std::cout << dist << std::endl;
        });
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}