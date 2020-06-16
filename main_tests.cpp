#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"

/**
 * @author Tyler Conley
 * The main() method found here is a series of tests that I developed for the Linked List program I made,
 * found in LinkedList.h. It is a pretty simple data structure, and only the basics are developed for it.
 * 
 * I programmed all this as practice in C++ to learn it in preparation for the next semester studying electronics.
 * This was to show myself that I am capable enough in C++ that I could jump right in to the program without having
 * to take low-level programming courses prior to starting.
 * 
 * As this was a study project, I set it upon myself to not using any 'using namespace' phrases, including namespace std.
 * As such, I have typed out std:: several times in these two files, and it really helped me to learn a lot about what was included in 
 * the std library
 */

int main(){    
    //Tests for default constructor
    std::cout << "Tests for linked list instantiated with default constructor\n" << std::endl;
    LinkedList<int> def_list{};

    std::cout << "Adding numbers 0-19 to Default Linked List" << std::endl;
    for(int i=0; i<20; i++){
        def_list.add(i);
    }
    std::cout << "All numbers added\n" << std::endl;

    std::cout << "Testing print function" << std::endl;
    def_list.print();

    std::cout << "\nTesting size function" << std::endl;
    std::cout << def_list.size() << std::endl;

    std::cout << "\nTesting remove function" << std::endl;
    std::cout << "...removing 7 from list: " << std::boolalpha << def_list.remove(7) << std::endl;
    std::cout << "...removing 7 from list: " << std::boolalpha << def_list.remove(7) << std::endl;

    std::cout << "Printing again" << std::endl;
    def_list.print();

    std::cout << "Adding 7 back in: " << std::boolalpha << def_list.add(7) << std::endl;
    std::cout << "One last print" << std::endl;
    def_list.print();


    std::cout << "Deleting Default Constructor Linked List..." << std::endl;
    delete &def_list;
    std::cout << "Default Constructor Linked List Successfully Deleted\n\n\n\n\n" << std::endl;

    //Tests for overloaded constructor
    std::cout << "Testing linked list with overloaded constructor" << std::endl;
    std::vector<int> vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LinkedList<int> ov_list(vector);
    std::cout << "Linked List initiated with numbers from 0 - 10\n" << std::endl;

    std::cout << "Testing print function" << std::endl;
    ov_list.print();

    std::cout << "Testing size function" << std::endl;
    std::cout << ov_list.size() << std::endl;

    std::cout << "\nTesting remove function" << std::endl;
    std::cout << "...removing 7 from list... " << std::boolalpha << ov_list.remove(7) << std::endl;
    std::cout << "...removing 7 from list... " << std::boolalpha << ov_list.remove(7) << std::endl;

    std::cout << "Printing again" << std::endl;
    ov_list.print();

    std::cout << "Adding 7 back in... " << std::boolalpha << ov_list.add(7) << std::endl;
    std::cout << "One last print" << std::endl;
    ov_list.print();

    delete &ov_list;
    std::cout << "Overloaded Constructor Linked List Successfully Deleted\n\n\n\n" << std::endl;

    std::vector<std::string> st_vector = {"alpha" , "beta", "contra", "demi", "elf", "goblin" , "yeppers"};

    LinkedList<std::string> st_list(st_vector);

    std::cout << "Linked List with strings initated\n" << std::endl;

    std::cout << "Testing print function" << std::endl;
    st_list.print();
    std::cout << "\nTesting size function" << std::endl;
    std::cout << st_list.size() << std::endl;

    std::cout << "\nTesting remove function" << std::endl;
    std::cout << "...removing 'contra' from list... " << std::boolalpha << st_list.remove("contra") << std::endl;
    std::cout << "...removing 'contra' from list... " <<std::boolalpha << st_list.remove("contra") << std::endl;

    std::cout << "Testing size" << std::endl;
    std::cout << st_list.size() << std::endl;
    std::cout << "\nTesting print" << std::endl;
    st_list.print();

    std::cout << "\nAdding 'contra' back in... " << std::boolalpha << st_list.add("contra") << std::endl;

    std::cout << "\nOne last print:" << std::endl;
    st_list.print();

    std::cout << "\nDeleting string linked list..." << std::endl;
    delete &st_list;
    std::cout << "String linked list deleted successfully" << std::endl; 

    return 0;
}
