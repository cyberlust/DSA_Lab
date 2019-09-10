#include <bits/stdc++.h>

using namespace std;


class Node
{
	public:
		Node *right;
		Node *left;
		Node *par;
		int data;
};

Node* search(Node *root,int key);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
Node* max(Node* root);
Node* min(Node* root);
Node* successor(Node* root,int key);
Node* predecessor(Node* root,int key);
void delete_(Node *root, Node *del);
void transplant(Node* root, Node* z, Node* y);

ifstream fpi;
ofstream fpo;


int main(int argc, char* argv[])
{
	//ifstream fpi;
	fpi.open(argv[1]);
	//ofstream fpo;
	fpo.open("bst.txt");

	string c,cmd;
	Node *root = (Node*)malloc(sizeof(Node));
	root = NULL;
	while(fpi>>c)
	{
		cmd = c;
		
		Node *new_node = (Node*)malloc(sizeof(Node));
		if(cmd=="insert")
		{	
			fpi>>c;
			int d = stoi(c);
			Node *p = (Node*)malloc(sizeof(Node));
			p=NULL;
			Node *y = (Node*)malloc(sizeof(Node));
			y = root;
			new_node->data = d;
			if(y==NULL)
			{
				root = new_node;
				cout<<new_node->data<<" inserted"<<endl;
				fpo<<new_node->data<<" inserted"<<endl;
			}
			else
			{
				while(y!=NULL)
				{
					p = y;
					if(new_node->data < y->data)
						y = y->left;
					else
						y = y->right;
				}
				new_node->par = p;
				if(new_node->data < p->data)
					p->left = new_node;
				else
					p->right = new_node;
				cout<<new_node->data<<" inserted"<<endl;
				fpo<<new_node->data<<" inserted"<<endl;
			}
			

		}
		else if(cmd=="inorder")
		{
			inorder(root);
			fpo<<endl;
			cout<<endl;
		}
		else if(cmd=="preorder")
		{
			preorder(root);
			cout<<endl;
			fpo<<endl;
		}
		else if(cmd=="postorder")
		{
			postorder(root);
			cout<<endl;
			fpo<<endl;
		}
		else if(cmd=="delete")
		{
			fpi>>c;
			int d = stoi(c);
			Node* del = search(root, d);
			if(del==NULL)
			{
				cout<<d<<" does not exist"<<endl;
				fpo<<d<<" does not exist"<<endl;
			}
			else
			{
				delete_(root, del);
				cout<<del->data<<" deleted"<<endl;
				fpo<<del->data<<" deleted"<<endl;	
			}
		}
		else if(cmd=="search")
		{
			fpi>>c;
			int d = stoi(c);
			search(root, d);
			Node* ser = search(root,d);
			if(ser!=NULL)
			{
				cout<<ser->data<<" found"<<endl;
				fpo<<ser->data<<" found"<<endl;
			}
			else
			{
				cout<<d<<" not found"<<endl;
				fpo<<d<<" not found"<<endl;
			}

		}
		else if(cmd=="successor")
		{
			fpi>>c;
			int d = stoi(c);
			Node* suc1 = search(root, d);
			if(suc1!=NULL)
			{
				Node* suc = successor(root, d);
				if(suc!=NULL)
				{
					cout<<suc->data<<endl;
					fpo<<suc->data<<endl;
				}
				else
				{
					cout<<"successor of "<< d <<" does not exist"<<endl;
					fpo<<"successor of "<< d <<" does not exist"<<endl;
				}
			}
			else
			{
				cout<< d <<" does not exist"<<endl;
				fpo<< d <<" does not exist"<<endl;
			}
		}
		else if(cmd=="predecessor")
		{
			fpi>>c;
			int d = stoi(c);
			Node* pre1 = search(root, d);
			if(pre1!=NULL)
			{
				Node* pre = predecessor(root, d);
				if(pre!=NULL)
				{
					cout<<pre->data<<endl;
					fpo<<pre->data<<endl;
				}
				else
				{
					cout<<"predecessor of "<< d <<" does not exist"<<endl;
					fpo<<"predecessor of "<< d <<" does not exist"<<endl;
				}
			}
			else
			{
				cout<< d <<" does not exist"<<endl;
				fpo<< d <<" does not exist"<<endl;
			}
		}
		else if(cmd=="maximum")
		{
			Node* maxi = max(root);
			if(maxi!=NULL)
			{
				cout<<maxi->data<<endl;
				fpo<<maxi->data<<endl;
			}
			else
			{
				cout<<endl;
				fpo<<endl;
			}
		}
		else if(cmd=="minimum")
		{
			Node* mini = min(root);
			if(mini!=NULL)
			{
				cout<<mini->data<<endl;
				fpo<<mini->data<<endl;
			}
			else
			{
				cout<<endl;
				fpo<<endl;
			}
		}
	}
	fpi.close();
	fpo.close();
}


void inorder(Node* root)//, ofstream fp)
{
	Node *x ;
	x = root;
	if(x!=NULL)
	{
		inorder(x->left);
		fpo<<x->data<<" ";
		cout<<x->data<<" ";
		inorder(x->right);
	}
}

void preorder(Node* root)//, ofstream fp)
{
	Node *x;
	x = root;
	if(x!=NULL)
	{
		fpo<<x->data<<" ";
		cout<<x->data<<" ";
		preorder(x->left);
		preorder(x->right);
	}
}

void postorder(Node* root)//, ofstream fp)
{
	Node *x;
	x = root;
	if(x!=NULL)
	{
		postorder(x->left);
		postorder(x->right);
		fpo<<x->data<<" ";
		cout<<x->data<<" ";
	}
}


Node* search(Node *root,int key)
{
	Node *x;
	x = root;
	if(x!=NULL && x->data!=key)
	{
		if(x->data>key)
			return search(x->left,key);
		return search(x->right,key);
	}
	return x;
}

Node* successor(Node* root,int key)
{
	Node *x = search(root, key);
	Node *y = (Node*)malloc(sizeof(Node));
	if(x!=NULL)
	{
		if(x->right!=NULL)
		{
			return min(x->right);
		}
		else
		{
			y = x->par;
			while(y!=NULL && y->right==x)
			{
				x = y;
				y = y->par;
			}
			return y;
		}
	}
	else
	{
		return x;
	}
}

Node* predecessor(Node* root,int key)
{
	Node *x = search(root, key);
	Node *y = (Node*)malloc(sizeof(Node));
	if(x!=NULL)
	{
		if(x->left!=NULL)
		{
			return max(x->left);
		}
		else
		{
			y = x->par;
			while(y!=NULL && y->left==x)
			{
				x = y;
				y = y->par;
			}
			return y;
		}
	}
	else
	{
		return x;
	}
}

Node* min(Node* root)
{
	Node* x;
	x = root;
	if(x!=NULL)
	{
		while(x->left!=NULL)
		{
			x = x->left;
		}	
		return x;
	}
}

Node* max(Node* root)
{
	Node* x;
	x = root;
	if(x!=NULL)
	{
		while(x->right!=NULL)
		{
			x = x->right;
		}
		return x;
	}
}

void delete_(Node *root, Node* del)
{
	Node *z = del;                                        // Node to be deleted
	if(z->right==NULL)
	{
		transplant(root, z, z->left);
	}
	else if(z->left==NULL)
	{
		transplant(root, z, z->right);
	}
	else
	{
		Node* y = min(z->right);
		if(y->par != z)
		{
			transplant(root, z, z->right);
			y->right = z->right;
			y->right->par = y;
		}
		transplant(root, z, y);
		y->left = z->left;
		y->left->par = y;
	}
}

void transplant(Node* root, Node* z, Node* y)
{
	if(z==root)
	{
		root = y;
	}
	else
	{
		if(z->par->left==z)
		{
			z->par->left=y;
		}
		else
		{
			z->par->right=y;
		}
	}
	if(y!=NULL)
	{
		z->par = y->par;
	}
}