#include <iostream>
#include <string>
#include <vector>

template <typename E>
class LinkedList {

    private:
        struct Node {

            private:
                E value;
                Node* next;
                Node* prev;

            public:
                Node(E val){
                    value = val;
                    next = nullptr;
                    prev = nullptr;
                }

                Node(Node* prevptr, Node* nextptr, E val){
                    prev = prevptr;
                    next = nextptr;
                    value = val;
                }

                ~Node(){
                   delete &value;
                }

                E getValue(){
                    return value;
                }

                Node* getNext() {
                    return next;
                }

                Node* getPrev(){
                    return prev;
                }

                void setValue(E val){
                    value = val;
                }

                void setNext(Node* node){
                    next = node;
                }

                void setPrev(Node* node){
                    prev = node;
                }
        };

        Node* beginning;
        Node* end;

        bool add(Node* prevptr, Node* currptr, E value){
            if(currptr == nullptr){
                Node* node = new Node(value);
                if(prevptr == nullptr){
                    beginning = node;;
                }
                else{
                    prevptr -> setNext(node);
                    node -> setPrev(prevptr);

                }
                end = node;
                return true;
            }
            return add(currptr, currptr -> getNext(), value);
        }

        bool remove(Node* prevptr, Node* currptr, E value){
            if(currptr == nullptr){
                return false;
            }

            if(currptr -> getValue() == value){
                if(prevptr != nullptr){
                    prevptr -> setNext(currptr -> getNext());
                }
                if(currptr -> getNext() != nullptr){
                    currptr -> getNext() -> setPrev(prevptr);
                }
                
                delete currptr;
                return true;
            }
            
            return remove(currptr, currptr -> getNext(), value);
        }

        int size(Node* ptr){
            if(ptr == nullptr){
                return 0;
            }
            return 1 + size(ptr -> getNext());
        }
       
        void print(Node* ptr){
            if(ptr == nullptr){
                return;
            }

            if(ptr -> getNext() == nullptr){
                std::cout << ptr -> getValue() << std::endl;
                return;
            }

            std::cout << ptr -> getValue() << ", ";
            print(ptr -> getNext());
        }

        void removeAll(Node* ptr){
            if(ptr == nullptr){
                return;
            }
            removeAll(ptr -> getNext());
            ptr -> setNext(nullptr);
            ptr -> setPrev(nullptr);
            delete ptr;
        }

    public:
        LinkedList(std::vector<E> collection);
        LinkedList();
        ~LinkedList();    

        bool add(E value){
            return add(nullptr, beginning, value);
        }   

        bool remove(E value){
            return remove(nullptr, beginning, value);
        }

        int size(){
            return size(beginning);
        }

        std::string toString(){
            return toString(beginning);
        }

        void print(){
            print(beginning);
        }

        Node* getBeginning(){
            return beginning;
        }

        Node* getEnd(){
            return end;
        }
};

template <typename E>
LinkedList<E>::LinkedList(std::vector<E> collection) {
    if(collection.size() == 0){
        return;
    }

    Node* temp = nullptr;
    for(E e : collection){
        Node* node = new Node(e);

        if(temp != nullptr){
            temp -> setNext(node);
            node -> setPrev(temp);
        }
        else{
            beginning = node;
        }

        temp = node;
    }

    end = temp;
}

template <typename E>
LinkedList<E>::LinkedList(){
    beginning = nullptr;
    end = nullptr;
}

template <typename E>
LinkedList<E>::~LinkedList() {
    removeAll(beginning);
}
