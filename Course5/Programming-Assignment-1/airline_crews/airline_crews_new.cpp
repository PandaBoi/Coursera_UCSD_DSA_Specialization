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

FlowGraph make_graph(std::vector<std::vector<bool>>& adj_matrix) {
    int vertex_count;
    // std::cin >> vertex_count >> edge_count;
    int N = adj_matrix.size();
    int M = adj_matrix[0].size();
    vertex_count = N+M+2;
    FlowGraph graph(vertex_count);
    
    for (int i = 0; i <N; i++) { graph.add_edge(0, i + 1, 1); }
        for (int i = 0; i < M; i++) { graph.add_edge(N + 1 + i,N + M + 1, 1); }
        for (int i = 0; i <N; i++) {
            for (int j = 0; j < M; j++) {
                if (!adj_matrix[i][j]) { continue; }
                graph.add_edge(i + 1,N + 1 + j, 1);
            }
        }
    // graph.print_graph();
    return graph;
}

vector<vector<bool>> ReadData() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> adj_matrix(N, vector<bool>(M));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j) {
        int bit;
        cin >> bit;
        adj_matrix[i][j] = (bit == 1);
      }
    return adj_matrix;
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


void max_flow(FlowGraph& graph, int from, int to,int left_size,int right_size) {
    int flow = 0;
    std::vector<pair<int,int>> parent(graph.size());
    std::vector<int> matching(left_size,-1);

    /* your code goes here */
    int new_flow;

    while(new_flow = bfs(from,to,parent,graph)){
    	// cout<<"returned from bfs flow = "<<new_flow<<endl;
    	// for(auto x:parent)
    	// 	cout<<x.first<<" ";
    	// cout<<endl;
    	flow = new_flow;
    	int cur = to;
    	while(cur!=from){
    		int prev = parent[cur].first;
    		// cout<<"prev is "<<prev<<endl;
    		// FlowGraph::Edge e1= graph.get_edge(prev);
    		graph.add_flow(parent[cur].second,new_flow);
    		cur = prev;
    	}
    }

    for(int i =0;i<left_size;i++){
        for(auto id:graph.get_ids(i+1)){
            FlowGraph::Edge e1 = graph.get_edge(id);
            if(e1.flow == 1){
                matching[i] = e1.to - left_size;
                break;
            }
            matching[i] = -1;

        }
    }

    for(auto x:matching)
        cout<<x<<" ";

    // return flow;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::vector<std::vector<bool> > adj_matrix = ReadData();
  FlowGraph graph = make_graph(adj_matrix);
  max_flow(graph, 0, graph.size() - 1,adj_matrix.size(),adj_matrix[0].size());
    // std::cout <<  << "\n";
    return 0;
}
