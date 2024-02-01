#include <cstddef>
//
// Created by Jinx on 2023/12/6.
//
const int MaxNumEdges=50; // 最大边数
const int MaxNumVertices=10;
template<class NameType, class DistType> class Graph
{ private:
    SeqList<NameType> VerticesList(MaxNumVertices); //顶点表
    DistType Edge [MaxNumVertices] [MaxNumVertices]; //邻接矩阵
    int CurrentEdges; //当前边数
    int FindVertex (Seqlist <NameType> &L; const NameType &Vertex)
    {return L.Find(Vertex);}
    int GetVertexPos (const NameTyoe &Vertex)
    {return FindVertex(VerticesList);}
    // 给出了顶点Vertex在图中的位置
    public:
    Graph (const int sz=MaxNumEdges);
    int GraphEmpty() const {return VerticesList.IsEmpty();}
    int GraphFull() const{return VerticesList.IsFull() ||
    CurrentEdges= =MaxNumEdges;}
    int NumberofVertices() {return VerticesList.last;}
    int NumberofEdges() {return CurrentEdges;}
    NameType Getvalue(const int i)
    {return i>=0 && i<VerticesList.last ? VerticesList.data[i] : NULL;}
    DistType Getweight (const int v1,const int v2);
    int GetFirstNeighbor(const int v);
    int GetNextNeighbor(const int v1,const int v2);
    void InsertVertex(const NameType & Vertex);
    void InsertEdge(const int v1,const int v2, DistType weight);
    void removeVertex(const int v);
    void removeEdge(cosnt int v1,const int v2);
}
template<NameType,DistType>
void Graph<NameType,DistType> :: DFS( )
{ int *visited=new int[NumVertices];
    for ( int i=0; i<NumVertices; i++) visited[i]=0;
    DFS(0,visited); //从顶点0开始深度优先搜索
    delete[] visited;
}