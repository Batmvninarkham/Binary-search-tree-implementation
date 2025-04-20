//   namtab
#include<iostream>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int data):value(data), left(nullptr), right(nullptr){}
};

class BST{
    private:
    node* root;
    //helper function that traverses the nodes recursivly till a nullptr(base case) is found
    node* travel(node* current, int data){
        if(current == nullptr){
            return new node(data);
        }
        if(data <= current->value){
            current->left = travel(current->left,data);
        }
        if(data > current->value){
            current->right = travel(current->right,data);
        }
        return current;
          }
          //traversing the node left->root->right recursivly
          void inorder(node*current){
           if(current ==nullptr){
               return;
           }
           cout<<"inorder traversal!"<<endl;
           inorder(current->left);
           cout<<current->value<<"|";
           inorder(current->right);
          }
          //traversing the nodes root->left->right recursivly
          void preorder(node* current){
           if(current == nullptr) return;
           cout<<"preorder traversal!"<<endl;
           cout<<current->value<<"|";
           preorder(current->left);
           preorder(current->right);
          }
          //traversing the nodes left->right->root recursivly
          void postorder(node* current){
           if(current == nullptr)return;
           cout<<"postorder traversal !"<<endl;
           postorder(current->left);
           postorder(current->right);
           cout<<current->value<<"|";
          }
    public:
     BST():root(nullptr){}
     //function wrapper for insertion
    void insertion(int data){
    root = travel(root,data);
   }
   //function wrapper for inorder
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
        //function wrapper for preorder
    void preorderTraversal() {
        preorder(root);
        cout << endl;
    }
        //function wrapper for postorder
    void postorderTraversal() {
        postorder(root);
        cout << endl;
    }
};
int main(){
    BST obj;
    obj.insertion(11);
    obj.insertion(14);
    obj.insertion(10);
    obj.insertion(18);
    obj.inorderTraversal();
}
