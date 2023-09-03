//
// Created by Administrator on 2023/8/29.
//

#include "solution.h"
#include "iostream"
using namespace std;
int main(){
    ListNode list1= ListNode(1),list2= ListNode(2),list3=ListNode(3),list4= ListNode(1),list5= ListNode(4),list6=ListNode(4);
    list1.next=&list2;
    list2.next=&list5;
    list3.next=&list6;
    list4.next=&list3;
    solution a=*new solution;
    ListNode *listNode=a.mergeTwoLists(&list1,&list4);
    while (listNode!= nullptr){
        cout << listNode->val << endl;
        listNode=listNode->next;
    }
    for (const auto& sub_vector : (new Solution0)->generate(5)) {
        cout << "{";
        for (const auto& element : sub_vector) {
            cout << element << ", ";
        }
        cout << "}\n";
    }
}