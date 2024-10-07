#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next;  // Shared ownership of next node
    std::weak_ptr<Node> prev;    // Weak pointer to avoid circular reference

    ~Node() {
        std::cout << "Node destroyed" << std::endl;
    }
};

int main() {
    // Create two shared_ptr nodes
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    // Link nodes
    node1->next = node2;          // node1 owns node2
    node2->prev = node1;          // node2 refers back to node1, using weak_ptr to avoid circular reference

    return 0;
}

/*
    Node destroyed
    Node destroyed
*/