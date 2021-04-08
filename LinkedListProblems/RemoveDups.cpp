/**
 * Remove Dups: Write code to remove duplicates from an unsorted linked list.
 * How would you solve this problem if a temporary buffer is not allowed.
*/
#include "../LinkedList/LinkedList.h"
#include <unordered_set>
#include <utility>

class Solution{
    public:
        //Properties
        LinkedList data;

        //Constructor
        Solution(LinkedList data){
            this->data = data;
        }

        //Method
        void RemoveDups(){
            Node* cur = data.getHead();
            Node* prev;
            Node* next;
            std::unordered_set<int> seen;
            while(cur){
                if(!seen.count(cur->value)){
                    seen.insert(cur->value);
                } else {
                    //Delete Dup
                    //Temp Pointers
                    prev = cur->prev;
                    next = cur->next;
                    //Linking
                    prev->next = next;
                    next->prev = prev;
                    //Removing Old Pointers
                    cur->prev = nullptr;
                    cur->next = nullptr;
                    //Advance
                    cur = next;
                    continue;
                }
                cur = cur->next;
            }
        }
};

int main(){
    //Creating Test Data
    std::vector<int> data = {1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 8};
    LinkedList testData = LinkedList(data);
    //testData.printList();

    //Solution
    Solution removeDups = Solution(testData);
    removeDups.RemoveDups();
    //removeDups.data.printList();

    return 0;
}