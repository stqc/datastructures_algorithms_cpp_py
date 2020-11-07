class graph:
    adj_list={}
    def __init__(self,vertex):

        self.adj_list[vertex]=[]

    def add_vertex(self, vertex):
        if self.adj_list.get(vertex):
            print('vertex already exists')
        else:
            self.adj_list[vertex]=[]

    def add_edge(self,v1,v2):
        if self.adj_list.get(v1) is not None and self.adj_list.get(v2) is not None:
            if v2 not in self.adj_list[v1] and v1 not in self.adj_list[v2]:
                self.adj_list[v1].append(v2)
                self.adj_list[v2].append(v1)
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
