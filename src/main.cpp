#include <iostream>
#include "menu.cpp"
#include "order.cpp"
#include "delivery.cpp"

using namespace std;
                                     //all member mutual .
int main() {
  int choice;
 cout << "   Welcome to Cafe System   \n"

  do {
        cout << "\nMain Menu:\n";
        cout << "1. Show Menu\n";
        cout << "2. Add Order\n";
        cout << "3. Cancel Order\n";
        cout << "4. Update Order\n";
        cout << "5. Show Orders\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            showMenu();  
        }
        else if(choice == 2) {
            addOrder(); 
        }
        else if(choice == 3) {
            cancelOrder(); 
        }
        else if(choice == 4) {
            updateOrder(); 
        }
        else if(choice == 5) {
            showOrders();  
        }
        else if(choice == 6) {
            cout << "Exiting program. Thank you!\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

 } while(choice != 6);

    return 0;
}

