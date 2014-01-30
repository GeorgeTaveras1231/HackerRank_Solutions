
struct Node
{
	int data;
	Node *next;
};
/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void Print(Node *head)
{
  if(head != NULL)
  {
      std::cout<<head->data<<std::endl;
      Print(head->next);
  }
}
/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    
    return temp;
}
/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertAtEnd(Node *head,int data)
{
    //if head is NULL, create a new Node and make it the head of the list
    if(head == NULL)
    {
        head = new Node;
        head->data = data;
        return head;
    }
    else
    {
        Node* iter;
        iter = head;
        //iterate through the linked list and stop at the last Node
        while(iter->next != NULL)
        {
            
            iter = iter->next;
        }
    
        //create a new Node
        Node* temp = new Node;
        temp->data = data;
    
        //connect the new Node to the last node on the list
        iter->next = temp;
    
        return head;
    }
}
/*
  Insert Node at a given position in a linked list 
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node* head, int data, int position)
{
    //if list uninitialized
    if (head == NULL)
    {
        //create new node and make it the head of the list
        head = new Node;
        head->data= data;
            
        return head;
    }
    else
    {
        //begin the iterator at the head
        Node* iter;
        iter = head; 
            
        //init loop counter
        int counter;
            
        //create new node
        Node* temp = new Node;
        temp->data = data;
            
        //if new node is to be the new head(position 0)
        if(position == 0)
        {
            temp->next = iter;
            head = temp;
            return head;
        }
       
        //if the position is not at the head, loop until reached position
        for(counter = 1; counter <= position; counter ++)
        {
            //if counter has reached position
            if(counter == position)
            {
                //connect the cords
                temp->next = iter->next;
                iter->next = temp;
            }
        
            iter = iter->next;

        }
        
        return head;
    }
}

/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete (Node* head, int position)
{
    
    //if deleting head
    if(position == 0)
    {
        //create a buffer pointer to point at the head
        Node* to_delete = head;
        
        //re-assign the head to the next item in the linked list
        head = head-> next;
        
        //delete the original head
        delete to_delete;
        
        //return the new head
        return head;
    }
    else
    {
        //initiaize counter and iterators
        
        //counter is a numerical representation of the iteration through the linked list
        int counter = 1;
        
        //these iterators are pointers to the links in the linked list
        Node* prev = head;
        Node* to_delete = prev->next;
        Node* next = to_delete->next;
        
        while(counter++ != position)
        {
            prev = to_delete;
            to_delete = next;
            next = to_delete->next;
        } 
        //after reached desired position
        
        //connect the previous link to the following link
        prev->next = next;
        
        //assign the "next" link of the link that will be deleted to be NULL
        to_delete->next = NULL;
        
        //delete the link
        delete to_delete;
        
        return head;
        
    }
   
}

/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  if(head != NULL)
  {
      if(head->next != NULL)
          ReversePrint(head->next);
      
      std::cout<< head->data <<std::endl;
  }
}

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

/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node* headA, Node* headB)
{
    if(headA->data == headB->data)
    {
        if(headA->next == NULL && headB->next == NULL)
        return 1;//if end of the list
           
        if((headA->next == NULL && headB->next != NULL)||(headA->next != NULL && headB->next == NULL))
        return 0;//if lists are not same length
           
        return CompareLists(headA->next,headB->next);
    }
    else
    {
        return 0;
    }
}

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node* headA, Node* headB)
{
    if(headA == NULL) return headB;
    if(headB == NULL) return headA;

    Node* iterA = headA;
    Node* iterB = headB;

    if(headA->data < headB->data)
    {
        headA->next = MergeLists(headA->next, headB);
        return headA;
    }else
    {
        headB->next = MergeLists(headA, headB->next);
        return headB;
    }
    
    
}

/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    static int counter;
    int final;
    if(head->next != NULL)
    {
        final = GetNode(head->next, positionFromTail);
        counter++;
    }else{
        counter = 0;
    }
    if(counter == positionFromTail) final = head->data;
    return final;
}
