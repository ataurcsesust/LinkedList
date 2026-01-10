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

void print(Node *head){
       Node  *move = head;
        while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
      }
     
     cout<<endl;
}


Node* InsertHead(Node *head, int val){
       Node *temp = new Node(val,head);
       return temp;
}

Node* InsertTail(Node *head,int val){
       if(head==nullptr){
           
           return new Node(val);
       }
       Node *newNode = new Node(val);
       Node *move = head;
       while(move->next!=nullptr){
           move=move->next;
       }
       move->next=newNode;
       return head;
}

Node* InsertAtPosition(Node *head, int pos,int val){
       if(head==nullptr){
          if(pos==1){
            return new Node(val);
          }
          else return head;
       }
       if(pos==1){
          Node *newNode = new Node(val,head);
          return newNode;
       }

       Node *move = head;
       int cnt = 0;
       while(move!=nullptr){
           cnt++;
           if(cnt==pos-1){
               Node *newNode = new Node(val,move->next);
               move->next = newNode;
               break;
           }
           move=move->next;
       }
       return head;
}

Node* InsertBeforeVal(Node *head,int val,int give){
       if(head==nullptr) return head;
       if(head->data==val){
          Node *newNode = new Node(give,head);
          return newNode;
       }

       Node *move = head;
      
       while(move->next!=nullptr){
          
           if(move->next->data==val){
               Node *newNode = new Node(give,move->next);
               move->next = newNode;
               break;
           }
           move=move->next;
       }
       return head;
}

Node* InsertAfterVal(Node *head,int val,int give){
       if(head->data==val){
          Node *newNode = new Node(give,head->next);
           head->next=newNode;
           return head;
       }

       Node*move = head;
      
       while(move!=nullptr){
           if(move->data==val){
               Node *newNode = new Node(give,move->next);
               move->next=newNode;
               break;
           }
           move=move->next;
       }
       return head;
}



int main() {
        vector<int> v={1,2,3,4,5,6,20};
        Node* head= ArrayTOLinkedList(v);
        print(head);

        head = InsertHead(head,1000);
        print(head);

        head=InsertTail(head,78);
        print(head);

        head= InsertAtPosition(head,10,99);
        print(head);

        head = InsertBeforeVal(head,99,864);
        print(head);

        head=InsertAfterVal(head,99,95);
        print(head);

    
     return 0;
}
