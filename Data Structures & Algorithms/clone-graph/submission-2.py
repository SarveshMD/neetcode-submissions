"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        hashmap: dict = {}
        def dfs(node):
            if node is None:
                return None
            clone_node = Node(node.val)
            hashmap[node] = clone_node
            for neighbor in node.neighbors:
                new_neighbor = hashmap.get(neighbor, None)
                if (new_neighbor is not None):
                    clone_node.neighbors.append(new_neighbor)
                else:
                    clone_node.neighbors.append(dfs(neighbor))
            return clone_node
        return dfs(node)
