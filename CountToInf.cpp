#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX/2;

class DistanceVectorRouting {
public:
    DistanceVectorRouting(int numNodes, const vector<vector<int>>& edges)
        : numNodes(numNodes) {
        // Initialize the distance and next-hop tables
        dist.resize(numNodes + 1, vector<int>(numNodes + 1, INF));
        nextHop.resize(numNodes + 1, vector<int>(numNodes + 1, -1));
        adjList.resize(numNodes + 1);

        // Distance to self is 0
        for (int i = 1; i <= numNodes; i++) {
            dist[i][i] = 0;
            nextHop[i][i] = i;
        }

        // Set initial distances based on the provided edges and build adjacency list
        for (const auto& edge : edges) {
            int src = edge[0], dest = edge[1], cost = edge[2];
            adjList[src].push_back({dest, cost});
            adjList[dest].push_back({src, cost});
            dist[src][dest] = cost;
            dist[dest][src] = cost;
            nextHop[src][dest] = dest;
            nextHop[dest][src] = src;
        }
    }

    void removeEdge(int src, int dest) {
        // Remove edge from adjacency list
        adjList[src].erase(remove_if(adjList[src].begin(), adjList[src].end(),
                                     [dest](const pair<int, int>& p) { return p.first == dest; }),
                           adjList[src].end());
        adjList[dest].erase(remove_if(adjList[dest].begin(), adjList[dest].end(),
                                      [src](const pair<int, int>& p) { return p.first == src; }),
                            adjList[dest].end());
        dist[src][dest] = INF;
        dist[dest][src] = INF;
        nextHop[src][dest] = -1;
        nextHop[dest][src] = -1;
    }

    bool runDVRAlgorithm() {
        bool updated;
        bool countToInf = false;
        vector<vector<int>> prevDist;
        numIter = 0;
        do {
            updated = false;
            prevDist = dist; // Copy current distances to use as the reference for this iteration
            numIter++;
            for (int src = 1; src <= numNodes; src++) {
                for (int dest = 1; dest <= numNodes; dest++) {
                    if (src == dest) continue;

                    int minCost = INF; // Start with the direct distance

                    // Calculate the minimum distance from neighbors
                    for (const auto& neighbor : adjList[src]) {
                        if (prevDist[neighbor.first][dest] != INF) {
                            int newCost = neighbor.second + prevDist[neighbor.first][dest];
                            if (newCost < minCost) {
                                minCost = newCost;
                                nextHop[src][dest] = neighbor.first;
                            }
                        }
                    }

                    // Update if we found a shorter path
                    if (dist[src][dest] != minCost) {
                        dist[src][dest] = minCost;
                        updated = true;
                    }

                    if(dist[src][dest]>100 && dist[src][dest]<INF) return true;
                }
            }
        } while (updated);
        return countToInf;
    }

    void printRoutingTables() const {
        cout << "Number of Iterations : " << numIter << endl;
        for (int node = 1; node <= numNodes; node++) {
            cout << "Routing Table for Node " << node << ":\n";
            for (int dest = 1; dest <= numNodes; dest++) {
                if (dist[node][dest] == INF) {
                    cout << "  To Node " << dest << ": Unreachable\n";
                } else {
                    cout << "  To Node " << dest << ": Cost = " << dist[node][dest]
                         << ", Next Hop = " << nextHop[node][dest] << '\n';
                }
            }
            cout << '\n';
        }
    }

private:
    int numNodes, numIter;
    vector<vector<int>> dist;
    vector<vector<int>> nextHop;
    vector<vector<pair<int, int>>> adjList; // adjacency list representation
};

int main() {
    int numNodes = 5;
    vector<vector<int>> edges = {
        {1, 2, 3},
        {1, 3, 5},
        {2, 3, 2},
        {2, 4, 4},
        {3, 4, 1},
        {4, 5, 6}
    };

    DistanceVectorRouting dvr(numNodes, edges);

    // Initial run to generate routing tables
    dvr.runDVRAlgorithm();
    cout << "Initial Routing Tables:\n";
    dvr.printRoutingTables();

    // Simulate the failure of the link between nodes 4 and 5
    cout << "\nSimulating link failure between nodes 4 and 5...\n";
    dvr.removeEdge(4,5);

    // Re-run the DVR algorithm after link failure
    bool countToInfinity = dvr.runDVRAlgorithm();

    // Check if count-to-infinity problem was detected
    if (countToInfinity) {
        cout << "Count-to-Infinity problem detected: Some distances exceed 100.\n";
        // Print routing tables after link failure
        cout << "Routing Tables after link failure:\n";
        dvr.printRoutingTables();
    } else {
        cout << "No count-to-infinity problem detected.\n";
    }

    return 0;
}
