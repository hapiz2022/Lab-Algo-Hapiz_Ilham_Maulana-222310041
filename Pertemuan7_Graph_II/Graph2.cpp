#include <iostream>
#include <vector>

#define max 10000000

using namespace std;

void DijkstrasTest();

int main() {
  DijkstrasTest();
  getchar();
  return 0;
}

class Node;
class Edge;

void Dijkstras();
vector<Node *> *AdjacentRemainingNodes(Node *node);
Node *ExtractSmallest(vector<Node *> &nodes);
int Distance(Node *node1, Node *node2);
bool Contains(vector<Node *> &nodes, Node *node);
void PrintShortestRouteTo(Node *destination);

vector<Node *> nodes;
vector<Edge *> edges;

class Node {
public:
  Node(char id) : id(id), previous(NULL), distanceFromStart(max) {
    nodes.push_back(this);
  }

public:
  char id;
  Node *previous;
  int distanceFromStart;
};

class Edge {
public:
  Edge(Node *node1, Node *node2, int distance)
      : node1(node1), node2(node2), distance(distance) {
    edges.push_back(this);
  }
  bool Connects(Node *node1, Node *node2) {
    return ((node1 == this->node1 && node2 == this->node2) ||
            (node1 == this->node2 && node2 == this->node1));
  }

public:
  Node *node1;
  Node *node2;
  int distance;
};

///////////////////
void DijkstrasTest() {
  Node *a = new Node('1');
  Node *b = new Node('2');
  Node *c = new Node('3');
  Node *d = new Node('4');
  Node *e = new Node('5');
  Node *f = new Node('6');

  Edge *e1 = new Edge(a, b, 7);
  Edge *e2 = new Edge(a, c, 9);
  Edge *e3 = new Edge(a, f, 14);
  Edge *e4 = new Edge(b, a, 7);
  Edge *e5 = new Edge(b, c, 10);
  Edge *e6 = new Edge(b, d, 15);
  Edge *e7 = new Edge(c, a, 9);
  Edge *e8 = new Edge(c, b, 10);
  Edge *e9 = new Edge(c, d, 11);
  Edge *e10 = new Edge(c, f, 2);
  Edge *e11 = new Edge(d, b, 15);
  Edge *e12 = new Edge(d, c, 11);
  Edge *e13 = new Edge(d, e, 6);
  Edge *e14 = new Edge(e, d, 6);
  Edge *e15 = new Edge(e, f, 9);
  Edge *e16 = new Edge(f, a, 14);
  Edge *e17 = new Edge(f, c, 2);
  Edge *e18 = new Edge(f, e, 9);

  a->distanceFromStart = 0; // set start node
  Dijkstras();
  PrintShortestRouteTo(e);
}

///////////////////

void Dijkstras() {
  while (nodes.size() > 0) {
    Node *smallest = ExtractSmallest(nodes);
    vector<Node *> *adjacentNodes = AdjacentRemainingNodes(smallest);

    const int size = adjacentNodes->size();
    for (int i = 0; i < size; ++i) {
      Node *adjacent = adjacentNodes->at(i);
      int distance = Distance(smallest, adjacent) + smallest->distanceFromStart;

      if (distance < adjacent->distanceFromStart) {
        adjacent->distanceFromStart = distance;
        adjacent->previous = smallest;
      }
    }
    delete adjacentNodes;
  }
}

// Find the node with the smallest distance,
// remove it, and return it.
Node *ExtractSmallest(vector<Node *> &nodes) {
  int size = nodes.size();
  if (size == 0)
    return NULL;
  int smallestPosition = 0;
  Node *smallest = nodes.at(0);
  for (int i = 1; i < size; ++i) {
    Node *current = nodes.at(i);
    if (current->distanceFromStart < smallest->distanceFromStart) {
      smallest = current;
      smallestPosition = i;
    }
  }
  nodes.erase(nodes.begin() + smallestPosition);
  return smallest;
}

// Return all nodes adjacent to 'node' which are still
// in the 'nodes' collection.
vector<Node *> *AdjacentRemainingNodes(Node *node) {
  vector<Node *> *adjacentNodes = new vector<Node *>();
  const int size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge *edge = edges.at(i);
    Node *adjacent = NULL;
    if (edge->node1 == node) {
      adjacent = edge->node2;
    } else if (edge->node2 == node) {
      adjacent = edge->node1;
    }
    if (adjacent && Contains(nodes, adjacent)) {
      adjacentNodes->push_back(adjacent);
    }
  }
  return adjacentNodes;
}

// Return distance between two connected nodes
int Distance(Node *node1, Node *node2) {
  const int size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge *edge = edges.at(i);
    if (edge->Connects(node1, node2)) {
      return edge->distance;
    }
  }
  return -1;
}

// Does the 'nodes' vector contain 'node'
bool Contains(vector<Node *> &nodes, Node *node) {
  const int size = nodes.size();
  for (int i = 0; i < size; ++i) {
    if (node == nodes.at(i)) {
      return true;
    }
  }
  return false;
}

void PrintShortestRouteTo(Node *destination) {
  vector<Node *> route;
  Node *current = destination;

  while (current) {
    route.push_back(current);
    current = current->previous;
  }

  cout << "Distance from A to E: " << destination->distanceFromStart << endl;
  cout << "Shortest Path Route: ";
  for (int i = route.size() - 1; i >= 0; --i) {
    cout << route[i]->id << " ";
  }
  cout << endl;
}
