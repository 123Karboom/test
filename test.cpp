#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Edge
{
    int destination;
    int weight;
};

typedef unordered_map<char, vector<Edge>> Graph;

pair<vector<char>, int> findShortestPath(const Graph &graph, char source, char destination)
{
    vector<int> distances(26, INT_MAX);
    distances[source - 'A'] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push(make_pair(0, source));

    vector<char> previous(26);

    while (!pq.empty())
    {
        char currentVertex = pq.top().second;
        pq.pop();

        if (currentVertex == destination)
        {
            break;
        }

        if (distances[currentVertex - 'A'] == INT_MAX)
        {
            break;
        }

        if (graph.find(currentVertex) != graph.end())
        {
            for (const auto &edge : graph.at(currentVertex))
            {
                char neighbor = edge.destination;
                int weight = edge.weight;
                int distance = distances[currentVertex - 'A'] + weight;

                if (distance < distances[neighbor - 'A'])
                {
                    distances[neighbor - 'A'] = distance;
                    previous[neighbor - 'A'] = currentVertex;
                    pq.push(make_pair(distance, neighbor));
                }
            }
        }
    }

    vector<char> path;
    char current = destination;
    while (current != source)
    {
        path.push_back(current);
        if (previous[current - 'A'] == '\0')
        {
            path.clear();
            break;
        }
        current = previous[current - 'A'];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());

    return make_pair(path, distances[destination - 'A']);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<char> vertices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i];
    }

    Graph graph;
    for (int i = 0; i < m; i++)
    {
        char start, end;
        int weight;
        cin >> start >> end >> weight;
        graph[start - 'A'].push_back(Edge{end - 'A', weight});
    }

    int numQueries;
    cin >> numQueries;

    for (int i = 0; i < numQueries; i++)
    {
        char source, destination;
        cin >> source >> destination;

        if (source < 'A' || source > 'A' + n - 1 || destination < 'A' || destination > 'A' + n - 1)
        {
            cout << "no_path" << endl;
            continue;
        }

        pair<vector<char>, int> shortestPath = findShortestPath(graph, source, destination);

        if (shortestPath.first.empty())
        {
            cout << "no_path" << endl;
        }
        else
        {
            for (int j = 0; j < shortestPath.first.size(); j++)
            {
                cout << shortestPath.first[j];
                if (j != shortestPath.first.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << " " << shortestPath.second << endl;
        }
    }

    return 0;
}