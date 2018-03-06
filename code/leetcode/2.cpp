#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans;
        int tmp1=0;
        while(l1!=NULL)
        {
            tmp1 = tmp1*10+*l1.val;
            l1 = l1.next;
        }
        int tmp2=0;
        while(l2!=NULL)
        {
            tmp2 = tmp2*10+l2.val;
            l2 = l2.next;
        }
        int tmp = tmp1+tmp2;
        while(tmp)
        {
            int now = tmp%10;
            tmp/=10;
            *ans = now;
        }
        return ans;
    }
};

int main()
{

    return 0;
}
