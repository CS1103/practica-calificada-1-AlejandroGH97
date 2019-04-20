//
// Created by ruben on 4/12/19.
//

#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H


namespace UTEC {

    struct Node {
        int value;
        Node *next;

        Node(int value);
    };

    class TwoLinkedList {
        Node *head1;
        Node *head2;
        Node *tail1;
        Node *tail2;
        Node *head;
        Node *tail;

    public:
        TwoLinkedList();
        ~TwoLinkedList();
        void push_back1(int value);
        void push_back2(int value);
        std::string merge(int value);
        bool is_merged();
        std::string getlist(int param);
        std::string getlist_o(int param);
        void save(std::string output);
        void clear(Node* current);
        Node* search(int param);

    };
}




#endif //PC1_TWOLINKEDLIST_H
