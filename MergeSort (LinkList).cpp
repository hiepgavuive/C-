struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mid(ListNode* head){
        ListNode* p = head;
        ListNode* pp = head->next;
        
        while(pp != NULL && pp->next != NULL){
            p = p->next;
            pp = pp->next->next;
        }
        
        return p;
    }
    
    ListNode* Merge(ListNode* L, ListNode* R){
        if(L == NULL) return R;
        else if(R == NULL) return L;
        
        if(L->val <= R->val){
            ListNode* p = L->next;
            ListNode* P = L;
            ListNode* pp = R;
            ListNode* PP = R;
            
            while(p != NULL && pp != NULL){
                if(p->val > pp->val){
                    pp = pp->next;
                    P->next = PP;
                    PP->next = p;
                    P = PP;
                    PP = pp;
                }else{
                    P = p;
                    p = p->next;
                }
            }if(pp != NULL) P->next = pp;
            
            return L;
        }else{
            ListNode* p = L;
            ListNode* P = L;
            ListNode* pp = R->next;
            ListNode* PP = R;
            
            while(p != NULL && pp != NULL){
                if(pp->val > p->val){
                    p = p->next;
                    PP->next = P;
                    P->next = pp;
                    PP = P;
                    P = p;
                }else{
                    PP = pp;
                    pp = pp->next;
                }
            }if(p != NULL) PP->next = p;
            
            return R;
        }
    }
    
    ListNode* MergeSort(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* L = head;
        ListNode* p = mid(head);
        ListNode* R = p->next;
        p->next = NULL;
        
        L = sortList(L);
        R = sortList(R);
        return Merge(L, R);
    }
};