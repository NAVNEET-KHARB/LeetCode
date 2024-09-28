/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int binToDec(string binary){
        int pow = 1;
        int n = binary.size();
        int dec = 0;
        for(int i = n-1; i>=0; i--){
            dec += int(binary[i]-'0') * pow;
            cout<<dec<<"\t";
            pow *= 2;
        }
        return dec;
    }
public:
    int getDecimalValue(ListNode* head) {
        string binary = "";
        ListNode* temp = head;
        while(temp){
            binary += to_string(temp->val);
            temp = temp->next;
        }
        return binToDec(binary);
    }
};