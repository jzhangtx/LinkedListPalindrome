// LinkedListPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

bool IsListPalindrome(ListNode** pHead, ListNode* pTail, bool& finished)
{
    if (pTail == nullptr)    // if the element count is even, this will stop the recursion
        return true;

    if (!IsListPalindrome(pHead, pTail->next, finished)) // before the tail is found
        return false;

    if (finished)           // compared all nodes
        return true;

    if (*pHead == pTail)    // hit the middle of the list (odd number of elements)
    {
        finished = true;
        return true;
    }

    if ((*pHead)->next == pTail)    // hit the middle of the list, but still need to compare the two nodes
                                    //  (even number of elements)
        finished = true;

    // after the the tail is found, compare the node and move the head node forward
    if ((*pHead)->data != pTail->data)
        return false;

    *pHead = (*pHead)->next;

    return true;
}

bool IsPalindrome(ListNode* list)
{
    if (list->next == nullptr)
        return true;

    ListNode* pList = list;
    bool finished = false;
    // the IsListPalindrome function is made recursive and change the list head
    //  so we need to use a auto value here
    return IsListPalindrome(&pList, list->next->next, finished);
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count == 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The list: {";
        PrintList(pHead);
        std::cout << "} " << std::endl;

        std::cout << (IsPalindrome(pHead) ? "is" : "is not") << " palindrome!" << std::endl;
        FreeList(pHead);
    }
}
