#include <iostream>
#include <climits>
using namespace std;

int minimumDist(int dist[], bool visited[]) {
  int min = INT_MAX, index;
  for (int i = 0; i < 5; i++)
  {
    if (!visited[i] && dist[i] <= min)
    {
      min = dist[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int graph[5][5], int start) {
  int dist[5];
  bool visited[5];
  for (int i = 0; i < 5; i++)
  {
    dist[i] = INT_MAX;
    visited[i] = false;
  }

  dist[start] = 0;

  for (int i = 0; i < 5; i++)
  {
    int m = minimumDist(dist, visited);
    visited[m] = true;

    for (int i = 0; i < 5; i++)
    {
      if (!visited[i] && graph[m][i] && dist[m] != INT_MAX && dist[m] + graph[m][i] < dist[i])
      {
        dist[i] = dist[m] + graph[m][i];
      }
    }
  }

  for (int i = 0; i < 5; i++)
  {
    char str = i + 65;
    std::cout << str << "  " << dist[i] << std::endl;
  }
}

int main() {
  int graph[5][5] = {
    {0, 10, 20, 0, 0},
    {10, 0, 0, 50, 10},
    {20, 0, 0, 20, 33},
    {0, 50, 20, 0, 20},
    {0, 10, 33, 20, 0},
  };
  dijkstra(graph, 0);
  return 0;
}