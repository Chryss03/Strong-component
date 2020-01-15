#include "scc.h"


Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}


void Graph::DFS(int v, bool visited[], vector<int> &vect, int kase)
{

    visited[v] = true;
    if(kase == 1)
        vect.push_back(v);
    else
        cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited, vect, kase);
}


Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}


void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}


void Graph::makeStack(int v, bool visited[], stack<int> &Stack)
{

    visited[v] = true;


    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            makeStack(*i, visited, Stack);


    Stack.push(v);
}


bool Graph::makeUnvisited(bool visited[]){

    for(int i = 0; i < V; i++)
        visited[i] = false;

    return visited;
}


void Graph::printSCCForV(vector<int> &vect)
{
    int v;
    cout << "Entering the vertex: ";
    cin >> v;
    cout << "Following is strongly connected component with the given vertex: \n";
    vector<int>::iterator it;
    vector<int>::iterator index;
    it = vect.begin();

    while(it != vect.end())
    {
        if(*it == v)
        {
            index = it;
            it--;
            while(*it != -1)
            {
                cout << *it << " ";
                it--;
            }
            it = index;
            while(*it != -1)
            {
                cout << *it << " ";
                it++;
            }
        }
        it++;
    }
}


void Graph::printSCCs(int kase)
{
    stack<int> Stack;
    vector<int> vect;
    int v;

    bool *visited = new bool[V];

    makeUnvisited(visited);

    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            makeStack(i, visited, Stack);

    Graph gr = getTranspose();

    makeUnvisited(visited);

    vect.push_back(-1);

    while (Stack.empty() == false)
    {
        v = Stack.top();
        Stack.pop();
        if(kase == 1)
        {
            if (visited[v] == false)
            {
                gr.DFS(v, visited, vect, kase);
                vect.push_back(-1);
            }
        }
        else
            if(visited[v] == false)
            {
                gr.DFS(v,visited, vect, kase);
                cout << endl;
            }
    }
    /*for(auto it = vect.begin(); it != vect.end(); ++it )
        cout << *it << " ";
    */
    if(kase == 1)
        printSCCForV(vect);
}
