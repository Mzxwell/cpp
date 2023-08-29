//
// Created by Administrator on 2023/8/29.
//

#ifndef CPP_SOLUTION_H
#define CPP_SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *result, *now = new ListNode;
        *now = ListNode();
        result = now;
        while (list1 != nullptr&&list2!= nullptr) {
            if (list1->val < list2->val) {
                now->next = list1;
                list1 = list1->next;
            } else {
                now->next = list2;
                list2 = list2->next;
            }
            now = now->next;
        }
        now->next=list2== nullptr?list1:list2;
        return result->next;
    }

};


#endif //CPP_SOLUTION_H
