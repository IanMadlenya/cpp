//
//  main.cpp
//  hw_03_01
//
//  Created by Weiyi Chen on 7/5/14.
//  Copyright (c) 2014 Weiyi Chen. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int i_num;
    Node* Np_link;
};
typedef Node* NodePtr;

int main(int argc, const char * argv[])
{
    NodePtr Np_head = NULL;
    NodePtr Np_current;
    int i_numSuitors;
    cout << "Enter the number of suitors: ";
    cin >> i_numSuitors;
    if (i_numSuitors <= 0) {
        cout << "Invalid entry. ";
        exit(1);
    }
    else if (i_numSuitors == 1) {
        cout << "1 is the lucky winner" << endl;
        exit(1);
    }
    
    //creates a circular linked list of nodes
    Np_head = new Node;
    Np_head->i_num = 1;
    Np_head->Np_link = Np_head;
    Np_current = Np_head;
    for (int i = 2; i <= i_numSuitors; i++) {
        NodePtr Np_newNode = new Node;
        Np_newNode->i_num = i;
        Np_newNode->Np_link = Np_head; // the link field of the last node in the list refers to the node that is the head of the list.
        Np_current->Np_link = Np_newNode;
        Np_current = Np_newNode;
    }
    
    // simulate the elimination process
    Np_current = Np_head;
    do {
        Np_current = Np_current->Np_link;
        NodePtr Np_prev = Np_current;
        Np_current = Np_current->Np_link;
        NodePtr Np_next = Np_current->Np_link;
        Np_prev->Np_link = Np_next;
        cout << "Suitor " << Np_current->i_num << " eliminated, continue counting from " << Np_current->Np_link->i_num << endl;
        delete Np_current;
        Np_current = Np_next;
    }while (Np_current != Np_current->Np_link);
    
    cout << Np_current->i_num << " is the lucky winner" << endl;
    return 0;
}