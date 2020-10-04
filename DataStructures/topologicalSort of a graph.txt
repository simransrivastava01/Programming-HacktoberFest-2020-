import java.util.*;
// Other imports go here
// Do NOT change the class name
class Graph
{ 
     //Implementing using adjacency Lists
    int V;
    ArrayList<LinkedList<Integer>>graph;    //array of LinkedList
    Graph(int V)
    {
        this.V=V;
        graph=new ArrayList<LinkedList<Integer>>(V);
     for(int i=0;i<V;i++)
     {
         graph.add(new LinkedList<Integer>());
     }
    }
    void addEdge(int v1,int v2)
    {
        graph.get(v1).add(v2);
    }
    //this sort is always for a DAG graph(Directed Acyclic Graph)
    void TopologicalSort()
    {
        Stack<Integer> s=new Stack<>();
        boolean visited[]=new boolean[V];
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            topologicalVisit(i,s,visited);
        }
        while(!s.isEmpty())
        {
            System.out.print(s.pop()+" ");
        }
    }
    void topologicalVisit(int vertex,Stack<Integer> s,boolean visited[])
    {
        visited[vertex]=true;
        int n;
        Iterator it=graph.get(vertex).iterator();
        while(it.hasNext())
        {
             n=(int)it.next();
            if(!visited[n])
            {
                topologicalVisit(n,s,visited);
            }
        }
        s.push(vertex);
    }
}

class Main
{
    public static void main(String[] args)
    {
        Graph g = new Graph(6);  
        g.addEdge(5, 2);  
        g.addEdge(5, 0);  
        g.addEdge(4, 0);  
        g.addEdge(4, 1);  
        g.addEdge(2, 3);  
        g.addEdge(3, 1);
        g.TopologicalSort();
        // Write your code here
    }
    }