#include<iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

// class Solution {
// public:

//     void printList(ListNode* head){
//         while(head != nullptr){
//             cout<<head->val<<" ";
//             head = head->next;
//         }
//         cout<<endl;
//     }

//     ListNode* mid(ListNode* head, ListNode* tail){
//         ListNode* slow = head, *fast = head;
//         while(fast != tail && fast->next != tail){
//             slow = slow->next;
//             fast = (fast->next != nullptr) ? fast->next->next : nullptr;
//         }
//         return slow;
//     }

//     ListNode* merge(ListNode *left, ListNode *right){
//         ListNode *sorted = new ListNode(0);
//         ListNode *ptr = sorted;

//         while(left != nullptr && right != nullptr){
//             if(left->val < right->val){
//                 ptr->next = left;
//                 left = left->next;
//             } else{
//                 ptr->next = right;
//                 right = right->next;
//             }
//             ptr = ptr->next;
//         }

//         while(left != nullptr){
//             ptr->next = left;
//             left = left->next;
//             ptr = ptr->next;
//         }

//         while(right != nullptr){
//             ptr->next = right;
//             right = right->next;
//             ptr = ptr->next;
//         }

//         return sorted->next;
//     }

//     ListNode * mergeSort(ListNode* head, ListNode* tail){
//         if(head == nullptr || head->next == nullptr) return head;
//         if(head->next == tail){
//             head->next = nullptr;
//             return head;
//         }
//         ListNode* middle = mid(head, tail);

//         ListNode* left = mergeSort(head, middle);
//         printList(left);

//         ListNode* right = mergeSort(middle, tail);
//         printList(right);

//         return merge(left, right);   
//     }

//     ListNode* sortList(ListNode* head) {
//         return mergeSort(head, nullptr);
//     }
// };
class Solution {
public:

    void printList(ListNode* head){
        while(head != nullptr){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    void swap(ListNode *a, ListNode *b){
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    ListNode *pivot(ListNode *head, ListNode *tail){
        ListNode *pivotNode = head;
        ListNode *swapNode = head;

        ListNode *ptr = head;
        while(ptr != tail){
            if(ptr->val < pivotNode->val){
                swapNode = swapNode->next;
                swap(swapNode, ptr);
            }
            ptr = ptr->next;
        }

        swap(pivotNode, swapNode);
        return swapNode;
    }

    ListNode *quickSort(ListNode *head, ListNode *tail){
        if(head == nullptr || head->next == nullptr || head == tail || head->next == tail) return head;
        ListNode *pivotNode = pivot(head, tail);    
        cout << "Pivot Node Value: " << pivotNode->val << endl;

        quickSort(head, pivotNode);
        quickSort(pivotNode->next, tail);
        return head;
    }
    

    ListNode* sortList(ListNode* head) {
        return quickSort(head, nullptr);
    }
};

int main(){
    // 4 -> 2 -> 1 -> 3 -> 5
    int arr[] = {-1,5,3,4,0};
    ListNode* head = new ListNode(arr[0]);
    ListNode* ptr = head;
    for(int i=1; i < 5; i++){
        ptr->next = new ListNode(arr[i]);
        ptr = ptr->next;
    }




    Solution sol;
    ListNode* sorted = sol.sortList(head);
    while(sorted != nullptr){
        cout<<sorted->val<<" ";
        sorted = sorted->next;
    }

    // ListNode* middle = sol.mid(head);
    // cout<<"Middle Node Value: "<<middle->val<<endl;
    

    return 0;

}