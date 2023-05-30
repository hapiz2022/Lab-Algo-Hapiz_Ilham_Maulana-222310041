#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node* add_node(Node *root, int value) {
  if (root == NULL) {
    Node *node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    cout << "Data bertambah!\n";
    return node;
  } else if (value < root->data) {
    root->left = add_node(root->left, value);
  } else if (value > root->data) {
    root->right = add_node(root->right, value);
  } else if (value == root->data) {
    cout << "Data sudah ada!\n";
  }
  return root;
}

void printPreorder(struct Node *node) {
  if (node == NULL)
    return;
  cout << node->data << " ";
  printPreorder(node->left);
  printPreorder(node->right);
}

void printInorder(struct Node *node) {
  if (node == NULL)
    return;

  printInorder(node->left);

  cout << node->data << " ";

  printInorder(node->right);
}

void printPostorder(Node *node) {
  if (node == NULL)
    return;
  printPostorder(node->left);
  printPostorder(node->right);
  cout << node->data << " ";
}

/* Driver code */
int main() {
  Node *root = NULL;
  int choice, value;

  while (true) {
    cout << "\nMenu:\n";
    cout << "1. Memasukkan Nilai\n";
    cout << "2. Tampilkan secara PreOrder\n";
    cout << "3. Tampilkan secara InOrder\n";
    cout << "4. Tampilkan secara PostOrder\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu (1-5): ";
    cin >> choice;

    switch (choice) {
      case 1:
        system ("CLS");
        cout << "Masukkan nilai: ";
        cin >> value;
        root = add_node(root, value);
        break;
      case 2:
        system ("CLS");
        cout << "\nPreorder traversal of binary tree is:\n";
        printPreorder(root);
        break;
      case 3:
        system ("CLS");
        cout << "\nInorder traversal of binary tree is:\n";
        printInorder(root);
        break;
      case 4:
        system ("CLS");
        cout << "\nPostorder traversal of binary tree is:\n";
        printPostorder(root);
        break;
      case 5:
        cout << "Keluar dari program.\n";
        exit(0);
      default:
        cout << "Pilihan tidak valid.\n";
    }
  }

  return 0;
}
