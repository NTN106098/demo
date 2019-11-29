#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Id;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;


NODE *insert(int item,NODE *root)
{
    NODE *temp,*cur,*prev;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->Id=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
        return temp;
    prev=NULL;
    cur=root;
    while(cur!=NULL)
        {
            prev=cur;
            if(cur->Id < item )
                cur=cur->rlink;
            else
                cur=cur->llink;

        }
        if(item<prev->Id)
            prev->llink=temp;
        else
            prev->rlink=temp;
        return root;
}
NODE *construct(NODE *root)
{
    int a,n,i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements to be inserted in the tree\n");
    for (i=0;i<n;i++)
        {
            scanf("%d",&a);
            root=insert(a,root);
        }
        printf("Tree Constructed Successfully!!!!!!\n");
        return root;
}
void preorder(NODE *root)
{
    if(root!=NULL)
        {
            printf("%d\t",root->Id);
            preorder(root->llink);
            preorder(root->rlink);
        }
}

void inorder(NODE *root)
{
    if(root!=NULL)
        {
            inorder(root->llink);
            printf("%d\t",root->Id);
            inorder(root->rlink);
        }
}

void postorder(NODE *root)
{
        if(root==NULL)
            return ;
        else
            {
                postorder(root->llink);
                postorder(root->rlink);
                printf("%d\t",root->Id);
            }
}
int search_element(NODE *root,int key)
{
    NODE *cur;
    int n=0;
    cur=root;
    if (cur!=NULL)
        {
            if (key==cur->Id)
                n=1;
            else if (key<cur->Id)
                return search_element(cur->llink,key);
            else
                return search_element(cur->rlink,key);
        }
        else
            return n;
}

NODE *minValueNode(NODE* node)
{
    NODE *current = node;
/* loop to find the leftmost leaf */
    while (current->llink != NULL)
            current = current->llink;
    return current;
}


NODE *delete_element(NODE *root,int key)
{
        if (root == NULL)
            return root;
        if (key < root->Id)
            root->llink = delete_element(root->llink, key);
        else if (key > root->Id)
            root->rlink = delete_element(root->rlink, key);
        else
            {
// node with only one child or no child
                if (root->llink == NULL)
                    {
                        NODE *temp = root->rlink;
                        free(root);
                        return temp;
                    }
                else if (root->rlink == NULL)
                    {
                        NODE *temp = root->llink;
                        free(root);
                        return temp;
                    }
// node with two children: Get the inorder successor (smallest
// in the right subtree)
                else
                {
                NODE *temp = minValueNode(root->rlink);
                root->Id = temp->Id;
                root->rlink = delete_element(root->rlink, temp->Id);
                }
            }
        return root;
}