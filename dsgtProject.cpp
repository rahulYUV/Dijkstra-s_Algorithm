// Shortest Path Finder Using Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>  // For checking valid character input

using namespace std;



// Graph class to represent the nodes and edges
class Graph {
private:
    unordered_map<char, vector<pair<char, int>>> adjacencyList; // Adjacency list to store edges and weights

public:
    // Function to add an edge between two nodes with a specific weight
    void addEdge(char from, char to, int weight) {
        adjacencyList[from].push_back({to, weight});
        adjacencyList[to].push_back({from, weight}); //  it's an undirected graph
    }

    // Function to get neighbors of a given node
    vector<pair<char, int>> getNeighbors(char node) const {
        if (adjacencyList.find(node) != adjacencyList.end()) {
            return adjacencyList.at(node); // Return neighbors if the node exists
        }
        return {}; // Return empty vector if node not found
    }

    // Function to return all nodes in the graph
    vector<char> getNodes() const {
        vector<char> nodes;
        for (const auto& pair : adjacencyList) {
            nodes.push_back(pair.first);
        }
        sort(nodes.begin(), nodes.end()); // Sort the nodes alphabetically
        return nodes;
    }

    // Function to display the graph visually
    void displayGraph() const {
        cout << "\n===== Graph Visualization =====\n\n";
        cout << "    A---4---B\n";
        cout << "   / \\     / \\\n";
        cout << "  2   \\   3   1\n";
        cout << " /     \\ /     \\\n";
        cout << "C---5---D---2---E\n";
        cout << " \\             /\n";
        cout << "  6           4\n";
        cout << "   \\         /\n";
        cout << "    \\       /\n";
        cout << "     \\     /\n";
        cout << "      \\   /\n";
        cout << "       \\ /\n";
        cout << "        F\n";
        cout << "\n================================\n\n";
    }

    // Function to check if a node exists in the graph
    bool nodeExists(char node) const {
        return adjacencyList.find(node) != adjacencyList.end();
    }
};

// Struct to store the result of Dijkstra's algorithm
struct DijkstraResult {
    unordered_map<char, int> distances;   // Distance of each node from the start
    unordered_map<char, char> previousNodes;  // Previous nodes to reconstruct the path
};

// Function to perform Dijkstra's algorithm to find the shortest path
DijkstraResult dijkstra(const Graph& graph, char start) {
    unordered_map<char, int> distances;  // Distance from start to each node
    unordered_map<char, char> previousNodes;  // To track the shortest path
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq; // Min-heap for distances

    //  for loop to initialize distances and previous nodes
    vector<char> nodes = graph.getNodes();
    for (size_t i = 0; i < nodes.size(); i++) {
        char node = nodes[i];
        distances[node] = numeric_limits<int>::max();
        previousNodes[node] = '\0'; // Null character
    }

    // Distance to start node is 0
    distances[start] = 0;
    pq.push({0, start}); // Add start node to priority queue

    // Dijkstra's main loop
    while (!pq.empty()) {
        char current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > distances[current]) continue;  // Skip if current distance is outdated

        // Check neighbors
        for (const auto& neighbor : graph.getNeighbors(current)) {
            char next = neighbor.first;
            int weight = neighbor.second;
            int distance = currentDist + weight;

            // Update distance if shorter path found
            if (distance < distances[next]) {
                distances[next] = distance;
                previousNodes[next] = current;
                pq.push({distance, next});
            }
        }
    }

    return {distances, previousNodes};
}

// Function to reconstruct the path from start to end using the previous nodes
vector<char> reconstructPath(const unordered_map<char, char>& previousNodes, char start, char end) {
    vector<char> path;
    for (char at = end; at != '\0'; at = previousNodes.at(at)) {
        path.push_back(at);  // Trace back from end to start
    }
    reverse(path.begin(), path.end());  // Reverse to get the correct order
    return path.front() == start ? path : vector<char>{}; // Return path if it starts with the start node
}

// Function to print the shortest path and distance
void printShortestPath(const Graph& graph, char start, char end) {
    DijkstraResult result = dijkstra(graph, start);
    vector<char> path = reconstructPath(result.previousNodes, start, end);

    if (path.empty()) {
        cout << "No path exists between " << start << " and " << end << endl;
    } else {
        cout << "Shortest path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << "\nTotal distance: " << result.distances[end] << " units\n";
    }
}

// Function to validate if the input is a single alphabet character
bool isValidInput(char input) {
    return isalpha(input);
}

int main() {
    Graph graph;

    // Adding edges to the graph (predefined graph with weights)
    graph.addEdge('A', 'B', 4);
    graph.addEdge('A', 'C', 2);
    graph.addEdge('B', 'D', 3);
    graph.addEdge('B', 'E', 1);
    graph.addEdge('C', 'D', 5);
    graph.addEdge('C', 'F', 6);
    graph.addEdge('D', 'E', 2);
    graph.addEdge('E', 'F', 4);

    // Display the graph visualization
    graph.displayGraph();

    char start, end;
        int num ;
        do{

      
    // Input validation for start node
    do {
        cout << "Enter the source node: ";
        cin >> start;
        if (!isValidInput(start)) {
            cout << "Invalid input! Please enter a valid node character (A-F).\n";
        } else if (!graph.nodeExists(start)) {
            cout << "Node '" << start << "' does not exist in the graph. Please try again.\n";
        }
    } while (!isValidInput(start) || !graph.nodeExists(start));

    // Input validation for end node
    do {
        cout << "Enter the destination node: ";
        cin >> end;
        if (!isValidInput(end)) {
            cout << "Invalid input! Please enter a valid node character (A-F).\n";
        } else if (!graph.nodeExists(end)) {
            cout << "Node '" << end << "' does not exist in the graph. Please try again.\n";
        }
    } while (!isValidInput(end) || !graph.nodeExists(end));

    // Display the shortest path result
    cout << "\n===== Shortest Path Calculation =====\n";
    cout << "From " << start << " to " << end << ":\n";
    printShortestPath(graph, start, end);
    cout << "=====================================\n";
    cout<<" do you want to continue click 1 for yes and 0 for no  :"<<endl;
    cin>>num;
        }
    while(num);

    // Pause before exit
    cout << "\nPress any key to exit...\n";
    cin.get();  // To capture the 'Enter' key
    cin.get();  // Pause before exit
    
    return 0;
}
