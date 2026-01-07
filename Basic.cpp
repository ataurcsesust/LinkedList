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
          Node* temp = new Node(v[i]);               // Array to Linked list conversion
          move->next= temp;
          move=move->next;
     }
     return head;
}

int main() {
     vector<int> v={1,2,3,4,5};
     Node* y= new Node(v[0],nullptr);
     cout <<y->data<<' '<<y->next<<' ' <<y <<endl;   // here y is pointer so we use, y->data is the value at that address, and y->next is the next pointer value


     Node val= Node(v[0],nullptr);
     cout<<val.data<<' '<<val.next<<' ' <<&val <<endl;  // here val is object so we use   

     Node* head= ArrayTOLinkedList(v);
     Node* move = head;
     while(move!=nullptr){
          cout<<move->data<<' ';
          move = move->next;
     }
     return 0;
}
