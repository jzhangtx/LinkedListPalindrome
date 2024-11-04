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

bool IsListPalindrome(ListNode** pHead, ListNode* pTail)
{
    if (pTail == nullptr)   // the tail is found
        return true;

    if (*pHead == pTail)    // if the element count is odd, this will stop the recursion
        return true;

    if ((*pHead)->next == pTail)    // if the element count is even, this will stop the recursion
        return (*pHead)->data == pTail->data;

    if (!IsListPalindrome(pHead, pTail->next)) // before the tail is found
        return false;

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
    // the IsListPalindrome function is made recursive and change the list head
    //  so we need to use a auto value here
    return IsListPalindrome(&pList, list->next->next);
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
        std::cout << "} ";

        std::cout << (IsPalindrome(pHead) ? "is" : "is not") << " palindrome!" << std::endl;
        FreeList(pHead);
    }
}
