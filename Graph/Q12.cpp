#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

Node* buildTree(string postfix) {
    stack<Node*> st;
    for (char ch : postfix) {
        if (isalnum(ch)) {
            st.push(new Node(ch));
        } else {
            Node* node = new Node(ch);
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            st.push(node);
        }
    }
    return st.top();
}

void inorder(Node* root) {
    if (root) {
        if (!isalnum(root->data)) cout << "(";
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        if (!isalnum(root->data)) cout << ")";
    }
}

int main() {
    string postfix = "ab+ef*g*-";
    Node* root = buildTree(postfix);
    cout << "Infix Expression (from tree): ";
    inorder(root);
    cout << endl;
    return 0;
}
