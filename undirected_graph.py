class graph:
    adj_list={}
    def __init__(self,vertex): #provide a vertex when creating a new graph
        self.adj_list[vertex]=[] #a new key with the vertex value is added to the adjacency list

    def add_vertex(self, vertex): #method to add more vertex
        if self.adj_list.get(vertex): #if the vertex already exists
            print('vertex already exists')
        else:
            self.adj_list[vertex]=[] #else add another key to the adjacency list

    def add_edge(self,v1,v2): #method to add an edge between nodes
        if self.adj_list.get(v1) is not None and self.adj_list.get(v2) is not None: #if the vertex exists
            if v2 not in self.adj_list[v1] and v1 not in self.adj_list[v2]: #and the edge doesn't already exist
                self.adj_list[v1].append(v2) #add vertex v2 to v1's list
                self.adj_list[v2].append(v1) #add vertex v1 to v2's list
            else:
                print('Edge already exists')

        else:
            print('one or more vertext don\'t exist in the graph')


    def __str__(self):
        if len(self.adj_list) < 0:
            return 'empty graph'
        else:
            for i in range(len(self.adj_list)):
                l= list(self.adj_list.keys())[i],'==========>',*self.adj_list[list(self.adj_list.keys())[i]]
                print(*l)
            return ''

print("created a new graph with vertex 23")
graph = graph(23)
print(graph)
print('add another vertex 2')
graph.add_vertex(2)
print(graph)
print('add an edge between 23 and 2')
graph.add_edge(23,2)
print(graph)
print('add another vertex 1')
graph.add_vertex(1)
print(graph)
print('add an edge between 1 and 2')
graph.add_edge(1,2)
print(graph)
print('try to add another edge between 23 and 2')
graph.add_edge(23,2)
print(graph)
print('add another vertex 3')
graph.add_vertex(3)
print(graph)
print('add an edge between 23 and 3')
graph.add_edge(23,3)
print(graph)
