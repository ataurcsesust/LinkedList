#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
     int data;
     Node* next;

 public:
     Node(int data1, Node* next1){
         data=data1;
         next= next1;
     }
 public:
     Node(int data2)
      {
          data = data2;
           next=nullptr;
      }
};

Node* ArrayTOLinkedList(vector<int>&v){
     Node* head = new Node(v[0]);
     Node* move = head;
     for(int i=1;i<v.size();i++){
          Node* temp = new Node(v[i]);      
          move->next= temp;
          move=move->next;
     }
     return head;
}

Node* RemoveHead(Node* head){
      if(head == nullptr){
          return nullptr;
      }
      
      Node* temp = head;
      head= head->next;
      delete(temp);          //delete frees memory, not the pointer itself 
      return head;

}

Node* RemoveLast(Node* head){
      if(head==nullptr) return nullptr;
      if(head->next==nullptr){
           delete(head); return nullptr;
      }

      Node *temp = head;
      while(temp->next->next!=nullptr){
           temp=temp->next;
      }

      delete(temp->next);
      temp->next=nullptr;
      return head;
}

Node* RemoveAtPosition(Node *head,int pos){
        if(head==nullptr) return nullptr;
        if(pos==1){
              Node *temp=head;
              head = head->next;
              delete(temp);     
              return head;
        }

        int cnt = 0 ;  
        Node *prev=nullptr, *move=head;
        while(move!=nullptr){
            cnt++;
            if(cnt==pos){
                prev->next=move->next;
                delete(move);
                break;
            }
            prev=move;
            move=move->next;
        }

        return head;


}



Node* RemoveVal(Node *head,int val){
        if(head==nullptr) return nullptr;
        if(head->data==val){
              Node *temp=head;
              head = head->next;
              delete(temp);     
              return head;
        }

        Node *prev=nullptr, *move=head;
        while(move!=nullptr){
            
            if(move->data==val){
                prev->next=move->next;
                delete(move);
                break;
            }
            prev=move;
            move=move->next;
        }

        return head;


}

int main() {
       vector<int> v={1,2,3,4,5,6,20,9,20};
     
     Node* head= ArrayTOLinkedList(v);
   
     Node* move = head;
    
     while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
     }
     
     cout<<endl;
     head= RemoveAtPosition(head,4);
     head= RemoveHead(head);
     move = head;
     while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
     }
     
     cout<<endl;


     head= RemoveLast(head);
     move = head;
     while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
     }
     
     cout<<endl;
  

     head= RemoveVal(head,20);
     move = head;
     while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
     }
     
     cout<<endl;

     return 0;
}
