#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode {
	public:
		T data;
		BinaryTreeNode *left;
		BinaryTreeNode *right;
		BinaryTreeNode(T data) {
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

class Node {
	public:
		int data;
		Node *next;
		Node(int data) {
			this->data = data;
			this->next = NULL;
		}
};

Node *takeInputList() {
	int data;
	cin>>data;
	if(data == -1) return NULL;
	Node *head = NULL, *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;
			tail = tail->next;
		}
		cin>>data;
	}
	return head;
}

void printList(Node *head) {
	if(head == NULL) return ;
	Node *temp = head;
	while(temp) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

BinaryTreeNode<int> *takeInput() {
	int rootData;
	cout<<"Enter the root data: ";
	cin>>rootData;
	if(rootData == -1) return NULL;
	queue<BinaryTreeNode<int> *>pendingNodes;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	pendingNodes.push(root);
	while(pendingNodes.size() != 0) {
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		int leftChildData;
		cout<<"Enter the left child of "<<front->data<<":";
		cin>>leftChildData;
		if(leftChildData != -1) {
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		int rightChildData;
		cout<<"Enter the right child of "<<front->data<<":";
		cin>>rightChildData;
		if(rightChildData != -1) {
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void print(BinaryTreeNode<int> *root) {
	if(root == NULL) return ;
	queue<BinaryTreeNode<int> *>ans;
	ans.push(root);
	ans.push(NULL);
	while(ans.size() != 0) {
		BinaryTreeNode<int> *front = ans.front();
		ans.pop();
		if(front == NULL) {
			if(ans.size() == 0) break;
			cout<<endl;
			ans.push(NULL);
			continue;
		}
		cout<<front->data<<" ";
		if(front->left) ans.push(front->left);
		if(front->right) ans.push(front->right);
	}
}

bool isMatch(Node *head, BinaryTreeNode<int> *root) {
	if(head == NULL) return true;
	if(head->data != root->data || root == NULL) return false;
	return isMatch(head->next, root->left) || isMatch(head->next, root->right);
}

bool dfs(Node *head, BinaryTreeNode<int> *root) {
	if(root == NULL) return false;
	if(isMatch(head, root)) return true;
	return dfs(head, root->left) || dfs(head, root->right);
}

bool check(Node *head, BinaryTreeNode<int> *root) {
	return dfs(head, root);
}

int main() {
	cout<<"Enter for tree: "<<endl;
	BinaryTreeNode<int> *root = takeInput();
	print(root);
	cout<<endl;
	cout<<"Enter for linked list: "<<endl;
	Node *head = takeInputList();
	printList(head);
	bool ans = check(head, root);
	if(ans) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	cout<<endl;
	return 0;
}
