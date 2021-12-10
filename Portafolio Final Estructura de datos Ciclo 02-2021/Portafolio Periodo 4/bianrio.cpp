

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int i = 0;

class BinarySearchTree
{
   private:
   struct tree_node
   {
      tree_node* left;
      tree_node* right;
      int data;
   };
   tree_node* root;

   public:
   BinarySearchTree()
   {
      root = NULL;
   }

   bool isEmpty() const { return root==NULL; }
   void print_inorder();
   void inorder(tree_node*);
   void print_preorder();
   void preorder(tree_node*);
   void print_postorder();
   void postorder(tree_node*);
   void insert(int);
   void remove(int);
};


void BinarySearchTree::insert(int d)
{
   tree_node* t = new tree_node;
   tree_node* parent;
   t->data = d;
   t->left = NULL;
   t->right = NULL;
   parent = NULL;


   if(isEmpty()) root = t;
   else
   {
   
      tree_node* curr;
      curr = root;
   
      while(curr)
      {
         parent = curr;
         if(t->data > curr->data) curr = curr->right;
         else curr = curr->left;
      }

      if(t->data < parent->data)
      {
         parent->left = t;
      }
      else
      {
      parent->right = t;
      }
    }
}

void BinarySearchTree::remove(int d)
{
 
   bool found = false;
   if(isEmpty())
   {
      cout<<" El arbol no tiene elementos! "<<endl;
      return;
   }

   tree_node* curr;
   tree_node* parent;
   curr = root;

   while(curr != NULL)
   {
      if(curr->data == d)
      {
         found = true;
         break;
      }
      else
      {
         parent = curr;
         if(d>curr->data) curr = curr->right;
         else curr = curr->left;
      }
    }
    if(!found)
    {
      cout<<" No existe el dato! "<<endl;
      return;
    }


    
    if((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL))
    {
      if(curr->left == NULL && curr->right != NULL)
      {
         if(parent->left == curr)
         {
            parent->left = curr->right;
            delete curr;
         }
         else
         {
            parent->right = curr->left;
            delete curr;
         }
       }
       return;
    }


    if( curr->left == NULL && curr->right == NULL)
    {
      if(parent->left == curr)
      {
         parent->left = NULL;
      }
      else
      {
         parent->right = NULL;
      }
      delete curr;
      return;
    }


   
    if (curr->left != NULL && curr->right != NULL)
    {
       tree_node* chkr;
       chkr = curr->right;
       if((chkr->left == NULL) && (chkr->right == NULL))
       {
         curr = chkr;
         delete chkr;
         curr->right = NULL;
       }
       else 
       {
        

         if((curr->right)->left != NULL)
         {
            tree_node* lcurr;
            tree_node* lcurrp;
            lcurrp = curr->right;
            lcurr = (curr->right)->left;
            while(lcurr->left != NULL)
            {
               lcurrp = lcurr;
               lcurr = lcurr->left;
            }
            curr->data = lcurr->data;
            delete lcurr;
            lcurrp->left = NULL;
         }
         else
         {
            tree_node* tmp;
            tmp = curr->right;
            curr->data = tmp->data;
            curr->right = tmp->right;
            delete tmp;
         }

      }
      return;
   }

}
void BinarySearchTree::print_postorder()
{
   postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
   if(p != NULL)
   {
      if(p->left) postorder(p->left);
      if(p->right) postorder(p->right);
      cout<<"     "<<p->data<<"\n ";
   }
   else return;
}

int main()
{
    BinarySearchTree b;
    int ch,tmp,tmp1;
    while(1)
    {
       cout<<endl<<endl;
       cout<<" Operaciones basicas sobre arboles "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Creacion e insercion de elementos "<<endl;
       cout<<" 2. Impresion "<<endl;
       cout<<" 3. Borrado "<<endl;
       cout<<" 4. Salida "<<endl;
       cout<<" Ingrese su opcion : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Ingres el numero a insertar : ";
                    cin>>tmp;
                    b.insert(tmp);
                    i++;
                    break;
           case 2 : cout<<endl;
                    cout<<" Impresion "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 3 : cout<<" Ingrese el valor a borar : ";
                    cin>>tmp1;
                    b.remove(tmp1);
                    break;
           case 4:
                    return 0;

       }
    }
}
