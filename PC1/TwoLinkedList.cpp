//
// Created by ruben on 4/12/19.
//

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "TwoLinkedList.h"

UTEC::Node::Node(int value){
    next=nullptr;
    this->value=value;
}

UTEC::TwoLinkedList::TwoLinkedList(){
    head1 = nullptr;
    head2 = nullptr;
    head = nullptr;
    tail = nullptr;
    tail1 = nullptr;
    tail2 = nullptr;
}

UTEC::TwoLinkedList::~TwoLinkedList(){
    clear(head1);
    clear(head2);
}

void UTEC::TwoLinkedList::clear(UTEC::Node *current){
    if(current){
        clear(current->next);
        delete current;
    }
    head = nullptr;
    tail = nullptr;
}


void UTEC::TwoLinkedList::push_back1(int value){
    Node* temp = new Node(value);
    if(head == nullptr) {
        if (head1 == nullptr && tail1 == nullptr) {
            head1 = temp;
            tail1 = temp;
        } else {
            tail1->next = temp;
            tail1 = temp;
        }
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void UTEC::TwoLinkedList::push_back2(int value) {
    Node *temp = new Node(value);
    if(head == nullptr){
    if (head2 == nullptr && tail2 == nullptr) {
        head2 = temp;
        tail2 = temp;
    } else {
        tail2->next = temp;
        tail2 = temp;
    }
}
    else{
        tail->next = temp;
        tail = temp;
    }
}

std::string UTEC::TwoLinkedList::merge(int value){
    if(head1 != nullptr && head2 != nullptr && head == nullptr){
        Node* temp = new Node(value);
        tail1->next = temp;
        tail1 = temp;

        tail2->next = temp;
        tail2 = temp;

        head = temp;
        tail = temp;
        return "Operación Exitosa";
    }
    else if(head != nullptr){
        return "Operación duplicada";
    }

}

bool UTEC::TwoLinkedList::is_merged(){
    return head;
}

std::string UTEC::TwoLinkedList::getlist(int param){
    std::string lista;
        if (param == 2) {
                Node *temp1 = head2;
                while(temp1 != head){
                    lista.append(std::to_string(temp1->value) + " ");
                    temp1 = temp1->next;
                }
                return lista;
        }

        else if(param == 0) {
                Node *temp0 = head;
                while(temp0 != nullptr){
                    lista.append(std::to_string(temp0->value) + " ");
                    temp0 = temp0->next;
                }
                return lista;
        }

        else if(param == 1){
                Node *temp1 = head1;
                while(temp1 != head){
                    lista.append(std::to_string(temp1->value) + " ");
                    temp1 = temp1->next;
                }
                return lista;
        }
        else{
            return "";
        }
}

std::string UTEC::TwoLinkedList::getlist_o(int param){
    std::string lista;
    if (param == 2) {
        Node *temp1 = head2;
        while(temp1 != head){
            lista.append(std::to_string(temp1->value) + ",");
            temp1 = temp1->next;
        }
        return lista;
    }

    else if(param == 0) {
        Node *temp0 = head;
        while(temp0 != nullptr){
            lista.append(std::to_string(temp0->value) + ",");
            temp0 = temp0->next;
        }
        return lista;
    }

    else if(param == 1){
        Node *temp1 = head1;
        while(temp1 != head){
            lista.append(std::to_string(temp1->value) + ",");
            temp1 = temp1->next;
        }
        return lista;
    }
    else{
        return "";
    }
}


void UTEC::TwoLinkedList::save(std::string output){
    std::fstream file(output, std::ios::out);
    file<<getlist_o(1)<<"\n";
    file<<getlist_o(2)<<"\n";
    file<<getlist_o(0)<<"\n";
    file.close();
}


