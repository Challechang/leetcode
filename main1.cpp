//
// Created by rbcheng on 8/22/17.
//

#include <iostream>
#include <stack>

#define MAXVEX 999999
using namespace std;

typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode {
    int in;
    unsigned int data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int num_vertex;
}GraphAdjList;
GraphAdjList *graphAdjList = new GraphAdjList();
bool visited[MAXVEX];


int add_vertex(unsigned int id) {
    for (int i = 0; i < graphAdjList->num_vertex; i++) {
        if (graphAdjList->adjList[i].data == id) {
            return i;
        }
    }
    int index = graphAdjList->num_vertex;
    graphAdjList->num_vertex++;
    graphAdjList->adjList[index].data = id;
    return index;
}

int is_contained(unsigned int id) {
    for (int i = 0; i < graphAdjList->num_vertex; i++) {
        if (graphAdjList->adjList[i].data == id) {
            return i;
        }
    }
    return -1;
}

void Add(unsigned int id, unsigned int dependID) {
    int id_index = add_vertex(id);
    int dependID_index = add_vertex(dependID);
    EdgeNode *edgeNode = new EdgeNode();
    edgeNode->adjvex = dependID_index;
    if (graphAdjList->adjList[id_index].firstedge == NULL) {
        graphAdjList->adjList[id_index].firstedge = edgeNode;
    } else {
        edgeNode->next = graphAdjList->adjList[id_index].firstedge->next;
        graphAdjList->adjList[id_index].firstedge->next = edgeNode;
    }

}



bool isCycle(unsigned int id) {
    stack<int> m_stack;
    int count = 0, id_count = 0;
    for (int i = 0; i < graphAdjList->num_vertex; i++) {
        if (graphAdjList->adjList[i].data == id) {
            EdgeNode *first = graphAdjList->adjList[i].firstedge;
            while (first) {
                id_count++;
                first = first->next;
            }
            m_stack.push(i);
            break;
        }
    }
    while(!m_stack.empty()) {
        int top_vertex = m_stack.top();
        m_stack.pop();
        count++;
        EdgeNode *e = graphAdjList->adjList[top_vertex].firstedge;
        while (e) {
            int k = e->adjvex;
            if (!(--graphAdjList->adjList[k].in))
                m_stack.push(k);
            e = e->next;
        }
    }
    if (count < id_count)
        return false;
    else
        return true;
}

void dfs(GraphAdjList *gl, int i, int index, bool &cycle) {
    EdgeNode *p;
    visited[i] = true;
    p = gl->adjList[i].firstedge;
    while (p) {
        if (p->adjvex == index) {
            cycle = true;
            return;
        }
        if (!visited[p->adjvex])
            dfs(gl, p->adjvex, index, cycle);
        p = p->next;
    }
}

bool isCycle1(unsigned int id) {
    int index = is_contained(id);
    if (index == -1)
        return false;
    bool cycle = false;
    dfs(graphAdjList, index, index, cycle);
    return cycle;
}

void output() {
    for (int i = 0; i < graphAdjList->num_vertex; ++i) {
        VertexNode vertex = graphAdjList->adjList[i];
        EdgeNode *first = vertex.firstedge;
        cout<< "data:" << vertex.data << " ";
        while (first) {
            cout << first->adjvex << " ";
            first = first->next;
        }
        cout << endl;
    }
}

int main() {
    int count = 5;
    unsigned int num1, num2;
    for (int i = 0; i < count; ++i) {
        cin >> num1 >> num2;
        Add(num1, num2);
    }
    cout << isCycle1(1) <<endl;
    output();
}
