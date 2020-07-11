#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using namespace std;
/* This class implements a bit unusual scheme for storing edges of the graph,
 * in order to retrieve the backward edge for a given edge quickly. */
#define mp make_pair
class FlowGraph {
public:
    struct Edge {
        int from, to, capacity, flow;
    };

private:
    /* List of all - forward and backward - edges */
    vector<Edge> edges;

    /* These adjacency lists store only indices of edges in the edges list */
    vector<vector<size_t> > graph;

public:
    explicit FlowGraph(size_t n): graph(n) {}

    void add_edge(int from, int to, int capacity) {
        /* Note that we first append a forward edge and then a backward edge,
         * so all forward edges are stored at even indices (starting from 0),
         * whereas backward edges are stored at odd indices in the list edges */
        Edge forward_edge = {from, to, capacity, 0};
        Edge backward_edge = {to, from, 0, 0};
        graph[from].push_back(edges.size());
        edges.push_back(forward_edge);
        graph[to].push_back(edges.size());
        edges.push_back(backward_edge);
    }

    size_t size() const {
        return graph.size();
    }

    void print_graph(){
    	for(auto ed:graph){
    		for(auto x:ed){
    			cout<<x<<" ";
    		}
    		cout<<endl;
    	}
    }

    const vector<size_t>& get_ids(int from) const {
        return graph[from];
    }

    const Edge& get_edge(size_t id) const {
        return edges[id];
    }

    void add_flow(size_t id, int flow) {
        /* To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
         * due to the described above scheme. On the other hand, when we have to get a "backward"
         * edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
         * should be taken.
         *
         * It turns out that id ^ 1 works for both cases. Think this through! */
        edges[id].flow += flow;
        edges[id ^ 1].flow -= flow;
    }
};

FlowGraph read_data() {
    int vertex_count, edge_count;
    std::cin >> vertex_count >> edge_count;
    FlowGraph graph(vertex_count);
    for (int i = 0; i < edge_count; ++i) {
        int u, v, capacity;
        std::cin >> u >> v >> capacity;
        graph.add_edge(u - 1, v - 1, capacity);
    }
    // graph.print_graph();
    return graph;
}

int bfs(int s, int t, std::vector<pair<int,int>>& parent, FlowGraph& graph){

	//fill(parent.begin(),parent.end(),-1);
	for(int i =0;i<parent.size();i++)
		parent[i].first = -1;
	parent[s].first = -2;
	queue<pair<int,int>>q;

	q.push(mp(s,INT_MAX));
	int new_flow;
	while(!q.empty()){
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		std::vector<size_t> edes;
		edes = graph.get_ids(cur);
		// cout<<cur<<" "<<edes.size()<<endl;
		for(auto ed:edes){
			FlowGraph::Edge next = graph.get_edge(ed);

			// cout<<cur<<"-->"<<next.to<<endl;
			if(parent[next.to].first==-1 && (next.capacity- next.flow)){

				parent[next.to].first = cur;
				parent[next.to].second = ed;
				new_flow = min(flow,next.capacity - next.flow);
				if(next.to == t)
					return new_flow;
				q.push(mp(next.to,new_flow));
			}

		}

	}

	return 0;


}


int max_flow(FlowGraph& graph, int from, int to) {
    int flow = 0;
    std::vector<pair<int,int>> parent(graph.size());
    /* your code goes here */
    int new_flow;

    while(new_flow = bfs(from,to,parent,graph)){
    	// cout<<"returned from bfs flow = "<<new_flow<<endl;
    	// for(auto x:parent)
    	// 	cout<<x.first<<" ";
    	// cout<<endl;
    	flow += new_flow;
    	int cur = to;
    	while(cur!=from){
    		int prev = parent[cur].first;
    		// cout<<"prev is "<<prev<<endl;
    		// FlowGraph::Edge e1= graph.get_edge(prev);
    		graph.add_flow(parent[cur].second,new_flow);
    		cur = prev;
    	}
    }




    return flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    FlowGraph graph = read_data();

    std::cout << max_flow(graph, 0, graph.size() - 1) << "\n";
    return 0;
}
