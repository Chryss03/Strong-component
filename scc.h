#ifndef SCC_H_INCLUDED
#define SCC_H_INCLUDED
#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;


class Graph
{
    int V;
    list<int> *adj;


    void makeStack(int v, bool visited[], stack<int> &Stack);
    bool makeUnvisited(bool visited[]);
    void DFS(int v, bool visited[], vector<int> &vect, int kase);

public:

    Graph(int V);
    void addEdge(int v, int w);
    void printSCCs(int kase);
    void printSCCForV(vector<int> &vect);
    Graph getTranspose();
};

#endif // SCC_H_INCLUDED
