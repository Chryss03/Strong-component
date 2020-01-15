#include "scc.h"
using namespace std;


int main()
{
    int kase;
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Type 1 for linear\n";
    cout << "Type 2 for quadratic\n";
    cin >> kase;
    if(kase == 2)
        cout << "Following are strongly connected components in given graph: \n";
    g.printSCCs(kase);

    return 0;
}
