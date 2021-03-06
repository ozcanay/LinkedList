#include <iostream>
#include <unordered_set>
#include <vector>

struct Node {
    int data;
    Node* next;
};

void printList(Node* headPtr);
void appendNode(Node* headPtr, int data);
void pushNode(Node* headPtr, int data);
void deleteNode(Node* headPtr, int data);
int getListSize(Node* headPtr);
void replaceNode(Node* headPtr, int pos, int data);
void insertNode(Node* headPtr, int pos, int data);
void removeDuplicateNode(Node* headPtr);
int getMiddleValue(Node* headPtr);
bool isPresentData(Node* headPtr, int data);
Node* reverseList(Node* headPtr);
int nthToLastNodeIterative(Node* headPtr, int n);
Node* addNodes(Node* headPtr1, Node* headPtr2); // CTCI 2.4
Node* createLinkedList(const std::vector<int>& vec);

Node* createLinkedList(const std::vector<int>& vec) {
    if(!vec.empty()) {
        std::vector<Node *> ptrs;

        for (auto data : vec) {
            Node *node = new Node;
            node->data = data;
            ptrs.push_back(node);
        }

        Node *headPtr = ptrs.front();

        for (int i = 0; i < ptrs.size() - 1; i++) {
            ptrs[i]->next = ptrs[i + 1];
        }

        ptrs.back()->next = nullptr;

        return headPtr;
    }
}

void printList(Node* headPtr) {
    Node* currentPtr = headPtr;

    while(currentPtr) {
        std::cout << currentPtr->data << " ";
        currentPtr = currentPtr->next;
    }
    std::cout << std::endl;
}

void appendNode(Node* headPtr, int data) {
    Node* newNodePtr = new Node;
    newNodePtr->next = nullptr;
    newNodePtr->data = data;

    Node* currentPtr = headPtr;

    while(currentPtr->next) {
        currentPtr = currentPtr->next;
    }

    currentPtr->next = newNodePtr;
}

void pushNode(Node** ptrToHeadPtr, int data) {
    Node* new_head = new Node;
    new_head->data = data;
    new_head->next = *ptrToHeadPtr;
    *ptrToHeadPtr = new_head;
}

void deleteNode(Node* headPtr, int data) {
    if(!headPtr) return;
    Node* currentPtr = headPtr;

    if(headPtr->data == data) {
        Node* temp = headPtr->next;
        headPtr->data = headPtr->next->data;
        headPtr->next = headPtr->next->next;
        delete temp;
    }

    while(currentPtr->next) {
        if(currentPtr->next->data == data) {
            Node* temp = currentPtr->next;

            if(currentPtr->next->next)
                currentPtr->next = currentPtr->next->next;
            else {
                currentPtr->next = nullptr;
                break;
            }

            delete temp;
        }
        currentPtr = currentPtr->next;
    }
}

int getListSize(Node* headPtr) {
    int size = 0;
    Node* currentPtr = headPtr;

    while(currentPtr) {
        size++;
        currentPtr = currentPtr->next;
    }
    return size;
}

void replaceNode(Node* headPtr, int pos, int data) {
    Node* newNodePtr = new Node;
    newNodePtr->data = data;
    newNodePtr->next = nullptr;

    Node* currentPtr = headPtr;
    int index = 1;

    while(currentPtr) {
        if(index == pos - 1) {
            Node* tempPtr = currentPtr->next;
            currentPtr->next = newNodePtr;

            newNodePtr->next = tempPtr->next;
            return;
        }
        index++;
        currentPtr = currentPtr->next;
    }
}

void insertNode(Node* headPtr, int pos, int data) {
    Node* newNodePtr = new Node;
    newNodePtr->data = data;
    newNodePtr->next = nullptr;

    Node* currentPtr = headPtr;
    int index = 1;

    while(currentPtr) {
        if(index == pos - 1) {
            Node* tempPtr = currentPtr->next;
            currentPtr->next = newNodePtr;

            newNodePtr->next = tempPtr;
            return;
        }
        index++;
        currentPtr = currentPtr->next;
    }
}

//CTCI Question
void removeDuplicateNode(Node* headPtr) {
    Node* current = headPtr;
    Node* prev = nullptr;
    std::unordered_set<int> node_values {};

    while(current) {
        if(node_values.find(current->data) != node_values.end()) {
            // If a value has been encountered before.
            prev->next = current->next;
            delete current;
        } else {
            // If a value is encountered the first time
            node_values.insert(current->data);
            prev = current;
        }

        current = current->next;
    }
}

int getMiddleValue(Node* headPtr) {
    int retVal;

    if(getListSize(headPtr) % 2 == 0) {
        std::cout << "Size of the linkedlist is even. So there is no middle node in the linkedlist.\n";
        return 0;
    }


    if(headPtr) {
        Node* fast_headPtr = headPtr;
        while(fast_headPtr && fast_headPtr->next) {
/*            std::cout << "headptr " << headPtr->data << std::endl;
            std::cout << "fast headptr " << fast_headPtr->data << std::endl;*/
            fast_headPtr = fast_headPtr->next->next;
            headPtr = headPtr->next;
        }
        retVal = headPtr->data;
    } else {
        retVal = 0;
        std::cout << "There are no nodes in the linked list. So there is no middle node.\n";
    }

    return retVal;
}

bool isPresentData(Node* headPtr, int data) {
    bool isPresent = false;
    Node* currentPtr = headPtr;

    while(currentPtr) {
        if(currentPtr->data == data) {
            isPresent = true;
            break;
        }
        currentPtr = currentPtr->next;
    }
    return isPresent;
}

Node* reverseList(Node* headPtr) {
    Node* current = headPtr;
    Node* prev = nullptr;
    Node* next = nullptr;

    while(current) {
        next = current->next;

        //// Reversing happens here.
        current->next = prev;

        //// Sliding pointer frame.
        prev = current;
        current = next;
    }
    headPtr = prev;

    return headPtr;
}
int nthToLastNodeIterative(Node* headPtr, int n) {
    if(!headPtr || n < 0) return -1;

    Node* aheadPtr = headPtr;
    Node* behindPtr = headPtr;

    while(n != 0) {
        aheadPtr = aheadPtr->next;
        n--;
    }

    while(aheadPtr) {
        behindPtr = behindPtr->next;
        aheadPtr = aheadPtr->next;
    }

    return behindPtr->data;
}

Node* addNodes(Node* headPtr1, Node* headPtr2) {

}

int main() {
/*    Node* lastPtr = new Node;
    lastPtr->data = 3;
    lastPtr->next = nullptr;

    Node* middlePtr = new Node;
    middlePtr->data = 2;
    middlePtr->next = lastPtr;

    Node* headPtr = new Node;
    headPtr->data = 1;
    headPtr->next = middlePtr;

    printList(headPtr);
    appendNode(headPtr, 4);
    printList(headPtr);
    appendNode(headPtr,8);
    printList(headPtr);
    std::cout << "Size of list is " << getListSize(headPtr) << std::endl;
    appendNode(headPtr, 34);
    printList(headPtr);

    int data = 2;
    if(isPresentData(headPtr, data)) {
        std::cout << std::to_string(data) + " is found in the list." << std::endl;
    }

    deleteNode(headPtr, 8);
    // getListSize(headPtr);
    printList(headPtr);
    replaceNode(headPtr, 4, 1);
    printList(headPtr);
    insertNode(headPtr, 2, 99);
    printList(headPtr);
    appendNode(headPtr, 61);
    printList(headPtr);


    std::cout << "Searching for the middle node...\n";
    std::cout << getMiddleValue(headPtr) << "\n";

    appendNode(headPtr, 99);
    printList(headPtr);
    appendNode(headPtr, 3);
    printList(headPtr);

    std::cout << "after removing duplicates: \n";
    removeDuplicateNode(headPtr);
    printList(headPtr);
    std::cout << "will reverse the list now: \n";
    // printList(reverseList(headPtr));
    printList(headPtr);
    std::cout << nthToLastNodeIterative(headPtr, 2) << std::endl;*/

/*    ////
    Node* headPtr2 = new Node;
    headPtr2->data = 5;
    appendNode(headPtr2, 2);
    appendNode(headPtr2, 3);
    appendNode(headPtr2, 4);
    appendNode(headPtr2, 5);


    printList(headPtr2);
    pushNode(&headPtr2, 7);
    printList(headPtr2);*/
/*    std::cout << getListSize(headPtr2) << std::endl;
    deleteNode(headPtr2, 5);
    std::cout << getListSize(headPtr2) << std::endl;
    printList(headPtr2);*/

    Node* headPtr = createLinkedList({});
    printList(headPtr);

}