# Ameen-AI-Assignment
This repository has the CPP code for 15 AI search algorithms
# 1. British Museum Search
A depth-first search variant that explores all paths systematically, keeping track of the entire path. It’s often used to find a goal node by backtracking through possible routes.

# 2. DFS (Depth-First Search)
Explores as far as possible along each branch before backtracking. Useful for pathfinding and checking connectivity in graphs.

# 3. BFS (Breadth-First Search)
Explores all neighbors at the current depth before moving to nodes at the next depth level. Finds shortest paths in unweighted graphs.

# 4. DFS + BFS
Runs DFS and BFS sequentially, demonstrating both traversal orders from the same start node.

# 5. DFS + History
A DFS variant that records the exact order in which nodes are visited, useful for debugging or analysis of traversal.

# 6. BFS + History
Similar to DFS + History but for BFS, keeping track of the visit order to understand how BFS explores nodes.

# 7. Hill Climb
A greedy algorithm that moves to the neighbor with the best heuristic (lowest cost) value until no better neighbor is found. It can get stuck in local minima.

# 8. Beam Search
A heuristic search that explores a fixed number of best nodes (beam width) at each level, balancing between breadth and heuristic pruning.

# 9. Hill Climb + History
Hill Climbing with a recorded path of nodes visited, showing the sequence of moves made.

# 10. Beam Search + History
Beam Search that also tracks and returns the nodes visited during the search process.

# 11. Oracle
A goal test function used in search algorithms to determine if a node meets the goal criteria.

# 12. Branch and Bound with Oracle
Searches for the optimal solution using cost-based pruning, guided by an oracle function to detect goal nodes.

# 13. Branch and Bound + Cost + Estimated Heuristics
An informed search combining actual cost and heuristic estimates (like A*), pruning paths that are costlier or less promising.

# 14. Branch and Bound + History
Branch and Bound that keeps track of nodes visited during the search to analyze or debug the search process.

# 15. A*
An optimal and complete informed search algorithm that uses both path cost and heuristic estimates to find the least-cost path to the goal efficiently.

