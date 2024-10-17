import matplotlib.pyplot as plt
import networkx as nx

#graph object 
G = nx.Graph()

# Add nodes (A to F)
nodes = ['A', 'B', 'C', 'D', 'E', 'F']
G.add_nodes_from(nodes)

# Add edges with weights
edges = [
    ('A', 'B', 4),
    ('A', 'C', 2),
    ('B', 'D', 3),
    ('B', 'E', 1),
    ('C', 'D', 5),
    ('C', 'F', 6),
    ('D', 'E', 2),
    ('E', 'F', 4)
]
G.add_weighted_edges_from(edges)

#  position of nodes
pos = nx.spring_layout(G)  # You can use other layouts like shell, circular, etc.

# Draw the nodes and edges
nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=1500, font_size=14, font_weight='bold')

# Draw the edge labels (weights)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=12)

# Display the graph
plt.title("Graph Visualization (A-F with Weights)")
plt.show()
