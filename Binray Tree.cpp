#include <iostream>
#include <queue>
#include <string>
using namespace std;

template <class T = int>
class Node{
    public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data, Node<T>* left = NULL, Node<T>* right = NULL):
    data(data), left(left), right(right){}
};

template <class T = int>
class BinaryTree{
    Node<T>* root;
    size_t _max_size;
    size_t _size;
    
    public:
    BinaryTree(size_t max_size = 0):
    root(NULL), _size(0), _max_size(max_size){}

    void inorder(){
        inorder(root);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(){
        postorder(root);
    }

    void printLevel(size_t level){
        printLevel(root, level);
    }

    size_t height(){
        return height(root);
    }

    void levelOrder(){
        for(int i = 1; i <= height(); i++){
            printLevel(i);
            cout << endl;
        }
    }

    void insert(T data){
        if(!root){
            root = new Node<T>(data);
            return;
        }

        queue<Node<T>*> q;
        q.push(root);

        while(!q.empty()){
            Node<T>* temp = q.front();
            q.pop();

            if(temp->left)
               q.push(temp->left);
            else{
                temp->left = new Node<T>(data);
                return;
            }

            if(temp->right)
               q.push(temp->right);
            else{
                temp->right = new Node<T>(data);
                return;
            }
        }
    }

    void BuildFromPreorder(string pre, string in){
        root = BuildFromPreorder(pre, in, 0, in.length() - 1);
    }
    
    private:
    void inorder(Node<T>* root){
        if(root){
            inorder(root->left);
            cout << root->data;
            inorder(root->right);
        }
    }

    void preorder(Node<T>* root){
        if(root){
            cout << root->data;
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node<T>* root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout << root->data;
        }
    }

    void printLevel(Node<T>* root, size_t level){
        if(!root)
            return;
        else if(level == 1)
            cout << root->data << " ";
        else if(level > 0){
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }

    size_t height(Node<T>* root){
        if(!root)
            return 0;
        size_t lh = height(root->left) + 1;
        size_t rh = height(root->right) + 1;
        if(rh > lh)
            return rh;
        else
            return lh;
    }

    Node<T>* BuildFromPreorder(string pre, string in, size_t inStart, size_t inEnd){
        static size_t preIndex = 0;
        Node<T>* temp = new Node<T>(pre[preIndex]);
        size_t inIndex = in.find(pre[preIndex++]);
        if(inStart > inEnd)
            return NULL;
        if(inStart == inEnd)
            return temp;
        temp->left = BuildFromPreorder(pre, in, inStart, inIndex - 1);
        temp->right = BuildFromPreorder(pre, in, inIndex + 1, inEnd);
        return temp;
    }  
};

template <>
class BinaryTree<int>{
    Node<>* root;
    size_t _max_size;
    size_t _size;
    
    public:
    BinaryTree(size_t max_size = 0):
    root(NULL), _size(0), _max_size(max_size){}

    void inorder(){
        inorder(root);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(){
        postorder(root);
    }

    void printLevel(size_t level){
        printLevel(root, level);
    }

    size_t height(){
        return height(root);
    }

    void levelOrder(){
        for(int i = 1; i <= height(); i++){
            printLevel(i);
            cout << endl;
        }
    }

    void insert(int data){
        if(!root){
            root = new Node<>(data);
            return;
        }

        queue<Node<>*> q;
        q.push(root);

        while(!q.empty()){
            Node<>* temp = q.front();
            q.pop();

            if(temp->left)
               q.push(temp->left);
            else{
                temp->left = new Node<>(data);
                return;
            }

            if(temp->right)
               q.push(temp->right);
            else{
                temp->right = new Node<>(data);
                return;
            }
        }
    }

    void BuildFromPreorder(string pre, string in){
        // cout << "template special" << endl;
        root = BuildFromPreorder(pre, in, 0, in.length() - 1);
    }
    
    private:
    void inorder(Node<>* root){
        if(root){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node<>* root){
        if(root){
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node<>* root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void printLevel(Node<>* root, size_t level){
        if(!root)
            return;
        else if(level == 1)
            cout << root->data << " ";
        else if(level > 0){
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }

    size_t height(Node<>* root){
        if(!root)
            return 0;
        size_t lh = height(root->left) + 1;
        size_t rh = height(root->right) + 1;
        if(rh > lh)
            return rh;
        else
            return lh;
    }

    Node<>* BuildFromPreorder(string pre, string in, size_t inStart, size_t inEnd){
        static size_t preIndex = 0;
        Node<>* temp = new Node<>((pre[preIndex]) - '0');
        size_t inIndex = in.find(pre[preIndex++]);
        if(inStart > inEnd)
            return NULL;
        if(inStart == inEnd)
            return temp;
        temp->left = BuildFromPreorder(pre, in, inStart, inIndex - 1);
        temp->right = BuildFromPreorder(pre, in, inIndex + 1, inEnd);
        return temp;
    }  
};


int main(){
    BinaryTree<> t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.insert(7);
    // cout << t.height() << endl;
    // t.BuildFromPreorder("12453", "42513");
    t.levelOrder();
    return 0;
}
