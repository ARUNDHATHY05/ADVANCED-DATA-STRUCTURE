#include <stdio.h>
#include <stdlib.h>
struct BST
{
 
     int data;
     struct BST *left;
     struct BST *right;
 
};
 
typedef struct BST NODE;
NODE *node;
NODE* createtree(NODE *node, int data)
 
{
 
     if (node == NULL)
     {
 
     NODE *temp;
     temp= (NODE*)malloc(sizeof(NODE));
     temp->data = data;
     temp->left = temp->right = NULL;
     return temp;
     }
 
     if (data < (node->data))
     {
          node->left = createtree(node->left, data);
     }
 
     else if (data > node->data)
     {
          node -> right = createtree(node->right, data);
     }
 
     return node;
 
}
 
 
void inorder(NODE *node)
{
 
     if(node != NULL)
     {
          inorder(node->left);
          printf("%d\t", node->data);
          inorder(node->right);
     }
}
 
void preorder(NODE *node)
{
 
     if(node != NULL)
     {
          printf("%d\t", node->data);
          preorder(node->left);
          preorder(node->right);  
     }
}
 
void postorder(NODE *node)
{
 
     if(node != NULL)
     {
          postorder(node->left);
          postorder(node->right);
          printf("%d\t", node->data);
     }
}
 
 
int main()
{
     int data, ch, i, n;
     NODE *root=NULL;
     while (ch!=5)
     {
          printf("\n\n1.Insertion in Binary Search Tree");
          printf("\n2.Inorder");
          printf("\n3.Preorder");
          printf("\n4.Postorder");
          printf("\n5.Exit\n");
          printf("\nEnter your Choice: ");
 
          scanf("%d", &ch);
 
          switch (ch)
          {
               case 1:   printf("\nEnter size of tree: " );
                         scanf("%d", &n);
                         printf("\nEnter the elements of tree)\n");
 
                         for(i=0; i<n; i++)
                         {
                              scanf("%d", &data);
                              root=createtree(root, data);
                         }
                         break;
 
               case 2:   printf("\nInorder Traversal: \n");
                         inorder(root);
                         break;
 
               case 3:   printf("\nPreorder Traversal: \n");
                         preorder(root);          
                         break;
 
               case 4:   printf("\nPostorder Traversal: \n");
                         postorder(root);    
                         break;
 
               case 5:   exit(0);
 
               default:  printf("\nEnter valid choice\n");
                         break;
 
          }
     }
}
