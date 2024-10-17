Shortest Path Finder Using Dijkstra's Algorithm
![Graph Visualization](C:\Users\Rahul Kumar\Desktop\demoalter\image.png)

📋 Project Description
This project implements Dijkstra's Algorithm to find the shortest path between two nodes in a weighted, undirected graph. It allows users to input a start and end node, calculates the shortest path, and displays the total distance. A predefined graph with nodes A to F is visualized for user reference.

🎯 Features
Shortest Path Calculation: Uses Dijkstra's algorithm to compute the shortest path between two nodes.
Input Validation: Ensures that user inputs are valid and correspond to nodes in the graph.
Graph Visualization: A predefined graph is displayed for easy reference to understand node connections.
Interactive: Users can continue finding paths between different nodes or exit the program.
Path Reconstruction: Reconstructs the entire path from the start to destination, displaying all intermediate nodes.
📊 Graph Visualization

    A---4---B
   / \     / \
  2   \   3   1
 /     \ /     \
C---5---D---2---E
 \             /
  6           4
   \         /
    \       /
     \     /
      \   /
       \ /
        F
🚀 How to Run the Program
Compile the Code: Use any C++ compiler. For example, to compile the code using g++:

bash

g++ shortest_path.cpp -o shortest_path
Run the Program:

bash

./shortest_path
Input: When prompted, enter the source node and destination node (valid inputs: A-F).

Result: The program will display the shortest path and the total distance between the selected nodes.

Continue or Exit: After displaying the result, the program will ask if you want to calculate another path.

💻 Sample Output
plaintext

===== Graph Visualization =====

    A---4---B
   / \     / \
  2   \   3   1
 /     \ /     \
C---5---D---2---E
 \             /
  6           4
   \         /
    \       /
     \     /
      \   /
       \ /
        F

====================================

Enter the source node: A
Enter the destination node: E

===== Shortest Path Calculation =====
From A to E:
Shortest path: A -> B -> E
Total distance: 5 units
=====================================
🛠️ Requirements
C++ Compiler (e.g., GCC, Clang, MSVC)
Basic knowledge of running terminal/command line programs.
📄 License
This project is licensed under the MIT License. See the LICENSE file for more detail