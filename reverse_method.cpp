/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* Reverse(Node* head)
{
        if(head == NULL)
        {
            //list is empty
            return NULL;
        }
        else if(head->next == NULL)
        {
            //list only has one link
            //or end of the list in the recursive loop
            return head;
        }
        else
        {
            Node* prev = head;//previous node placeholder
            Node* iter = head-> next;//current node placeholder

            Node* new_head;//final result and new head of list
            
            //recursive call
            //when it reaches the end of the list it will return the current "head", which is the last node in the list
            //that value will travel through the recursions and stay the same, making the last item in the list the new head
            new_head = Reverse(iter);
            //ends once the (head->next == NULL) condition is true, which would mean the end of the list    
            
            prev->next = NULL;//dump the "next" pointer from the node that is previous to the current node
            iter->next = prev;//connect the current node to the previous node
            return new_head;//return new head
            
        }
    
}
