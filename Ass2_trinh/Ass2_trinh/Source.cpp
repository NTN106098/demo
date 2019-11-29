#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
int main()
{
    int item,ch,key,n;
    NODE *root;
    root=NULL;
        while (1)
        {
            printf("\nEnter the choice\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search an Element\n6.Delete an Element\n7:Exit\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: root=construct(root);
                        break;
                case 2: preorder(root);
                        break;
                case 3: inorder(root);
                        break;
                case 4: postorder(root);

                        break;
                case 5: if (root==NULL)
                            printf("List Empty\n");
                        else
                        {

                            printf("Enter the element\n");
                            scanf("%d",&key);
                            n=search_element(root,key);
                            if(n)
                                printf("Key found\n");
                            else
                                printf("Not found\n");
                        }
                        break;
                case 6:
                    if (root==NULL)
                        printf("List Empty\n");
                    else
                    {
                        printf("Enter the element\n");
                        scanf("%d",&key);
                        n=search_element(root,key);
                    if(n)
                        root=delete_element(root,key);
                    else
                        printf("Not found\n");
                    }
                    break;
                    case 7: exit(0);
                    default: printf("Wrong Choice\n");
            }
        }
}