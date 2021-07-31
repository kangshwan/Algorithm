#include <iostream>
#include <map>
#include <queue>

#define MAX 1000005

bool visited[MAX] = {false,};

using namespace std;

typedef struct Node{
    int level = 1;
    int location;
    Node* walk_b = nullptr;
    Node* walk_f = nullptr;
    Node* teleport = nullptr;
}Node;

Node* walk_back(Node* node){
    int next_loc = node->location - 1;
    if(next_loc >= 0 && !visited[next_loc]){

        Node* new_Node = new Node;
        new_Node->level = node->level + 1;
        new_Node->location = node->location - 1;

        visited[next_loc] = true;

        return new_Node;
    }

    return nullptr;
    
}

Node* walk_front(Node* node){
    int next_loc = node->location + 1;

    if(next_loc <= MAX && !visited[node->location+1]){

        Node* new_Node = new Node;
        new_Node->level = node->level + 1;
        new_Node->location = next_loc;

        visited[next_loc] = true;
        
        return new_Node;
    }

    return nullptr;
}

Node* teleport(Node* node){
    int next_loc = node->location * 2;

    if(next_loc <= MAX && !visited[node->location*2]){

        Node* new_Node = new Node;
        new_Node->level = node->level + 1;
        new_Node->location = next_loc;

        visited[next_loc] = true;
        
        return new_Node;
    }

    return nullptr;
}

int find_fastest_time(int start, int target){
    queue<Node*> que;
    
    Node* root = new Node;
    root->location = start;
    visited[start]=true;
    que.push(root);

    while(!que.empty()){
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