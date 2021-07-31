#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, bool> m_table;
map<int, bool>::iterator p;

typedef struct Node{
    int level = 1;
    int location;
    Node* walk_b = nullptr;
    Node* walk_f = nullptr;
    Node* teleport = nullptr;
}Node;

Node* walk_back(Node* node){
    p = m_table.find(node->location - 1);
    if(p == m_table.end()){

        Node* new_Node = new Node;
        new_Node->level = node->level + 1;
        new_Node->location = node->location - 1;

        m_table[new_Node->location] = true;

        return new_Node;
    }

    return nullptr;
    
}

Node* walk_front(Node* node){
    p = m_table.find(node->location + 1);
    if(p == m_table.end()){

        Node* new_Node = new Node;
        new_Node->level = node->level + 1;
        new_Node->location = node->location + 1;

        m_table[new_Node->location] = true;
        
        return new_Node;
    }

    return nullptr;
}

Node* teleport(Node* node){
    p = m_table.find(node->location * 2);
    if(p == m_table.end()){

        Node* new_Node = new Node;
        new_Node->level = node->level + 1;
        new_Node->location = node->location * 2;

        m_table[new_Node->location] = true;
        
        return new_Node;
    }

    return nullptr;
}

int find_fastest_time(int start, int target){
    queue<Node*> que;
    
    Node* root = new Node;
    root->location = start;
    m_table[start]=true;
    que.push(root);

    while(true){
        Node* temp = que.front();
        que.pop();
        if (temp != nullptr){
            if((temp->location) == target){
                return temp->level-1;
            }

            temp->walk_b = walk_back(temp);
            que.push(temp->walk_b);
            temp->walk_f = walk_front(temp);
            que.push(temp->walk_f);
            temp->teleport = teleport(temp);
            que.push(temp->teleport);

        }
    }
}

int main(void){
    int start, target;
    cin >> start>> target;
    
    cout << find_fastest_time(start, target);

}