// DATE: 01-MAY-2024
// Question URL: https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1
// Question: Arrange Consonants and Vowels
// Description: Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival.
// Approach: 1. Brute Force Code is Self-Explanatory.

class Solution
{
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {
        struct Node *vowels = NULL, *consonants = NULL, *t1 = NULL, *t2 = NULL;
        
        while(head != NULL){
            if(head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u'){
                if(vowels == NULL){
                    t1 = head;
                    vowels = head;
                }
                else{
                    t1->next = head;
                    t1 = head;
                }
            }
            else{
                if(consonants == NULL){
                    t2 = head;
                    consonants = head;
                }
                else{
                    t2->next = head;
                    t2 = head;
                }
            }
            
            head = head->next;
        }
        
        if(t2 != NULL) t2->next = NULL;
        if(t1 != NULL) t1->next = consonants;
        
        return vowels != NULL ? vowels : consonants;
    }
};