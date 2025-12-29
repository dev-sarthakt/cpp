#include <iostream>
#include <future>
#include <chrono>
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

void go_right(Node* start, string str){
    Node*p = start;
    int i = 0;
    while (p != nullptr)
    {
        if (p->name == str)
        {
            cout << i << " steps right " << " " << p << " " << p->name << endl;
            return ;
        }
        else{
            p = p->succ;
            i++;
        }
    }
}

void go_left(Node* start, string str){
    Node*p = start;
    int i = 0;
    while (p != nullptr)
    {
        if (p->name == str)
        {
            cout << i << " steps left " << " " << p << " " << p->name << endl;
            return ;
        }
        else{
            p = p->prev;
            i++;
        }
    }
}

void find(Node* start, string str){
    auto f1 = async(launch::async, go_left, start, str);
    auto f2 = async(launch::async, go_right, start, str);
}

int main(){
    Node *start = create_Node("0");
    Node *temp_1 = start;
    for (int i = 1; i < 500000; i++)
    {
        temp_1 = temp_1->add(to_string(i));
    }
    Node *mid = temp_1;
    for (int i = 500000; i <= 1000000; i++)
    {
        temp_1 = temp_1->add(to_string(i));
    }
    auto begin = chrono::high_resolution_clock::now();
    find(mid, "999999");
    auto end = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::microseconds>(end-begin)).count() << " mics" << endl;
    return 0;
}
