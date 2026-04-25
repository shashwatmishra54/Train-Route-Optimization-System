#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 100;

// Edge structure
struct Edge
{
    int destination;
    int distance;
    int fare;
};

// Graph
vector<Edge> graph[MAX];
string stationNames[MAX];
int stationCount = 0;

// Add station
void addStation(string name)
{
    stationNames[stationCount++] = name;
}

// Add route
void addRoute(int src, int dest, int dist, int fare)
{
    graph[src].push_back({dest, dist, fare});
    graph[dest].push_back({src, dist, fare}); // Undirected Graph
}

// Display stations
void displayStations()
{
    cout << "\n===== Available Train Stations =====\n";
    for (int i = 0; i < stationCount; i++)
    {
        cout << i << "." << stationNames[i] << endl;
    }
}

// Dijkstra Algorithm
void shortestPath(int source, int destination)
{
    vector<int> dist(stationCount, INT_MAX);
    vector<int> fare(stationCount, INT_MAX);
    vector<int> parent(stationCount, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    fare[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        for (auto edge : graph[current])
        {
            int next = edge.destination;
            int newDist = dist[current] + edge.distance;
            int newFare = fare[current] + edge.fare;

            if (newDist < dist[next])
            {
                dist[next] = newDist;
                fare[next] = newFare;
                parent[next] = current;
                pq.push({newDist, next});
            }
        }
    }

    if (dist[destination] == INT_MAX)
    {
        cout << "\nNo route found!\n";
        return;
    }

    // Path
    vector<int> path;
    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    cout << "\n===== Best Route =====\n";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << stationNames[path[i]];
        if (i != 0)
            cout << " -> ";
    }

    cout << "\nTotal Distance : " << dist[destination] << " km";
    cout << "\nTotal Fare     : Rs. " << fare[destination] << endl;
}


int main()
{
    // Add Stations
    addStation("Delhi");
    addStation("Noida");
    addStation("Ghaziabad");
    addStation("Agra");
    addStation("Kanpur");
    addStation("Lucknow");
    addStation("Prayagraj");
    addStation("Varanasi");
    addStation("Patna");
    addStation("Gaya");
    addStation("Madhubani");

    
    addRoute(0,1,25,50);       
    addRoute(0,2,30,60);      
    addRoute(0,3,220,250);    
    addRoute(2,4,400,450);    
    addRoute(4,5,90,120);     
    addRoute(5,6,200,220);    
    addRoute(6,7,125,150);    
    addRoute(7,8,260,300);    
    addRoute(8,9,100,130);    
    addRoute(8,10,170,220);   
    addRoute(3,5,330,350);    
    addRoute(6,8,300,340);    

    int source, destination;

    cout << "===== Train Route Optimization System =====";
    displayStations();

    cout << "\nEnter Source Station Number : ";
    cin >> source;

    cout << "Enter Destination Station Number : ";
    cin >> destination;

    if (source < 0 || source >= stationCount || destination < 0 || destination >= stationCount)
    {
        cout << "Invalid Station Selection!\n";
        return 0;
    }

    shortestPath(source, destination);

    return 0;
}
