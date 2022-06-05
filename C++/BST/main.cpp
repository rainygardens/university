#include <iostream>
#include "bst.hpp"

int main() {
    bst<int> *Drzewo = new bst<int>();
    std::cout<<"A BST<int> tree object has been created. Choose an option to operate the program:\n";
    std::cout<<" 1. Insert element to the tree\n 2. Remove element from the tree\n 3. Find in tree\n 4. Print the tree\n 5. Quit\n";
    int opcja, el;
    
    while(1) {
        std::cout<<"Option: ";
        std::cin>>opcja;
        if(opcja==5) break;
        switch(opcja) {
            case 1: 
                std::cout<<"Input the element(int): ";
                std::cin>>el;
                Drzewo->insert(el);
                break;
            case 2:
                std::cout<<"Input the element: ";
                std::cin>>el;
                Drzewo->remove(el);
                break;
            case 3:
                std::cout<<"Input element: ";
                std::cin>>el;
                if(Drzewo->find(el)) 
                {
                    std::cout<<"Element is in the tree\n";
                }
                else std::cout<<"Element was not in the tree\n";
                break;
            case 4:
                std::cout<<"Tree: "<<*Drzewo;
                break;
        }
    }
    delete Drzewo;
}
