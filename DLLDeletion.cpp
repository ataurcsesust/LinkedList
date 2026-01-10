#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
     int data;
     Node* next;
     Node* back;

 public:
     Node(int data1, Node* next1,Node *back1){
         data=data1;
         next= next1;
         back=back1;
     }
 public:
     Node(int data2)
      {
          data = data2;
          next=nullptr;
          back=nullptr;
      }
};

Node* ArrayToDLL(vector<int>&arr){
       Node *head= new Node(arr[0]);
       Node *prev = head;

       for(int i=1;i<arr.size();i++){
            Node *temp = new Node(arr[i],nullptr,prev);
            prev->next = temp;
            prev=temp;
       }

       return head;
}

Node* RemoveHead(Node *head){
       if(head==nullptr) return head;
       if(head->next==nullptr){
          delete(head);
          return nullptr;
       }

       Node *temp = head;
       head=head->next;
       head->back=nullptr;
       temp->next=nullptr;
       delete(temp);
       return head;
}

Node* RemoveTail(Node *head){
       if(head==nullptr) return head;
       if(head->next==nullptr){
          delete(head);
          return nullptr;
       }
       Node *temp = head;
       while(temp->next!=nullptr){
           temp=temp->next;
       }
       
       Node *prev = temp->back;
       prev->next=nullptr;
       temp->back=nullptr;
       delete(temp);
       
       return head;
}


Node* RemoveKthElement(Node *head, int pos){
      if(head==nullptr) return head;
      if(head->next==nullptr){
         if(pos==1){
            delete(head);
            return nullptr;
         }
         else return head;
      }

      if(pos==1){
          Node *temp = head;
          head=head->next;
          head->back=nullptr;
          temp->next=nullptr;
          delete(temp);
          return head;
      }

      Node *temp =head;
      int cnt =0;
      while(temp->next!=nullptr){
           cnt++;
           if(cnt==pos){

                Node *prev =temp->back;
                Node *posv=temp->next;
                temp->back=nullptr;
                temp->next=nullptr;
                prev->next=posv;
                posv->back=prev;
                delete temp; 
                return head;
               
           }
           temp=temp->next;
      }

      cnt++;

      if(cnt==pos){
          Node *prev= temp->back;
          temp->back=nullptr;
          prev->next=nullptr;
          delete(temp);
      }

     return head;
}


Node* RemoveElementValue(Node *head, int val){
      if(head==nullptr) return head;
      if(head->next==nullptr){
         if(head->data==val){
            delete(head);
            return nullptr;
         }
         else return head;
      }

      if(head->data==val){
          Node *temp = head;
          head=head->next;
          head->back=nullptr;
          temp->next=nullptr;
          delete(temp);
          return head;
      }

      Node *temp =head;
  
      while(temp->next!=nullptr){
          
           if(temp->data==val){
                Node *prev =temp->back;
                Node *posv=temp->next;
                temp->back=nullptr;
                temp->next=nullptr;
                prev->next=posv;
                posv->back=prev;
                delete temp;
                return head;
               
           }
           temp=temp->next;
      }

    

      if(temp->data==val){
          Node *prev= temp->back;
          temp->back=nullptr;
          prev->next=nullptr;
          delete(temp);
      }

     return head;
}


Node* RemoveNode(Node *temp){
     Node *prev= temp->back;
     Node *posv= temp->next;


     Node *head=temp;
     while(head->back!=nullptr){
         head=head->back;
     }

       if(prev == nullptr && posv == nullptr){
         delete temp;
         return nullptr;
    }

     if(posv==nullptr){
          prev->next=nullptr;
          temp->back=nullptr;
          delete(temp);
          return head;
     }

     if(prev==nullptr){
         head = posv;
         posv->back=nullptr;
         temp->next=nullptr;
         delete(temp);
         return head;
     }

     temp->back=nullptr;
     temp->next=nullptr;
     prev->next=posv;
     posv->back=prev;
     delete(temp);
     return head;

}

void print(Node *head){
       Node  *move = head;
        while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
      }
     
     cout<<endl;
}

int main(){
        vector<int> v={1,2,3,4,5,6,20};
         // vector<int> v={1,3};
        Node* head= ArrayToDLL(v);
        print(head);

        head = RemoveHead(head);
        print(head);

        head = RemoveTail(head);
        print(head);

        head= RemoveKthElement(head,1);
        print(head);

        head= RemoveElementValue(head,5);
        print(head);

        head= RemoveNode(head->next->next);
        print(head);

    return 0;
}