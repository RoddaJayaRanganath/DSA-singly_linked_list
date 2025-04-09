void remove_duplicates(struct node **head)
{
    if(*head == NULL)
    {
        printf("sorry!, we don't have linked list !");
        return;
    }
    else
    {
        struct node *temp1 = *head;
        while(temp1!=NULL)
        {
            struct node *prev = temp1;
            struct node *temp2 = temp1->next;
            while(temp2!=NULL)
            {
                // deletion of the duplicate node;
                if(temp1->data == temp2->data && temp2->next!=NULL)
                {
                    prev->next = temp2->next;
                    free(temp2);
                    temp2 = prev->next;
                }
                // if last node is duplicate of any node in linked list;
                else if(temp1->data == temp2->data && temp2->next==NULL)
                {
                    prev->next = NULL;
                    free(temp2);
                    temp2 = NULL;
                    break;
                }
                else
                {
                    prev = temp2;
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
    }
}