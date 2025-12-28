#include <iostream>
using namespace std;

class Node{
    public:
        Node *prev = nullptr, *succ = nullptr;
        string name;
        Node(string n) : name{n} {};
        Node(Node *p, string n, Node *s) : prev{p}, name{n}, succ{s} {};
        Node* insert(string n){
            Node *pn = new Node{prev, n, this};
            this->prev = pn;
            return pn;
        }
        Node* add(string n){
            Node* pn = new Node{this, n, succ};
            this->succ = pn;
            return pn;
        }
        Node* advance(int n) const{
            const Node *p = this;
            for (int i = 0; i < n; i++)
            {
                p = p->succ;
            }
            return const_cast<Node *>(p);
        }
};

Node* create_Node(string n){
    return new Node{n};
}

void delete_Node(Node *node){
    if (node->prev == nullptr && node->succ == nullptr)
    {
        ;
    }
    else if (node->prev == nullptr)
    {
        node->succ->prev = nullptr;
    }
    else if (node->succ == nullptr)
    {
        node->prev->succ = nullptr;
    }
    else{
        node->succ->prev = node->prev;
        node->prev->succ = node->succ;
    }
    delete node;
}

int main(){
    
    return 0;
}
