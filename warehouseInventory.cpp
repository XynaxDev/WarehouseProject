#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
    long id;
    string name;
    int quantity;
    Node* next;
public:
    Node(long id, string name, int quantity) : id(id), name(name), quantity(quantity), next(nullptr) {}
};

void displayInfo(Node*& head) {
    Node* temp = head;
    if (head == nullptr) {
        cout << "\033[1;31mError: No items are currently available in the inventory to display!\033[0m\n";
    }
    else {
        int sno = 1;
        cout << "\033[33m\t     Warehouse Data\t\t\033[0m\n";
        cout << "\033[1;34m========================================\033[0m" << endl;
        cout << "\033[1;36mS.No.\tID\tName\t\tQuantity\033[0m" << endl;
        cout << "\033[1;34m========================================\033[0m" << endl;
        while (temp != nullptr) {
            cout << left << setw(8) << sno << setw(8) << temp->id << setw(16) << temp->name << setw(5) << temp->quantity << endl;
            temp = temp->next;
            sno++;
        }
        cout << "\033[1;34m----------------------------------------\033[0m" << endl;
    }

}

bool alreadyPresent(Node*& head, long id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (id == temp->id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* insertItem(long id, string name, int quantity, Node*& head, Node*& tail) {
    Node* nodeToInsert = new Node(id, name, quantity);
    if (head == nullptr) {
        head = tail = nodeToInsert;
    }
    else {
        tail->next = nodeToInsert;
        tail = nodeToInsert;
    }
    cout << "\033[1;32mItem added Successfully!\033[0m\n";
    return tail;
}

void searchById(long id, Node*& head) {
    Node* temp = head;
    bool isFound = false;
    int sno = 1;
    while (temp != nullptr) {
        if (temp->id == id) {
            isFound = true;
            break;
        }
        sno++;
        temp = temp->next;
    }

    if (isFound) {
        cout << "\033[33m\t     Warehouse Data\t\t\033[0m\n";
        cout << "\033[1;34m========================================\033[0m" << endl;
        cout << "\033[1;36mS.No.\tID\tName\t\tQuantity\033[0m" << endl;
        cout << "\033[1;34m========================================\033[0m" << endl;
        cout << left << setw(8) << sno << setw(8) << temp->id << setw(16) << temp->name << setw(5) << temp->quantity << endl;
        cout << "\033[1;34m----------------------------------------\033[0m" << endl;
    }
    else {
        cout << "\033[1;31mError: No item found with the ID " << id << ". Please verify the ID and try again!\033[0m\n";
    }
}

void updateQuantity(long id, int quantity, Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            temp->quantity = quantity;
            cout << "\033[1;32mQuantity updated successfully!\033[0m" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "\033[1;31mError: Unable to update quantity! No item found with the ID " << id << ". Please verify the ID and try again.\033[0m\n";
}

void removeItem(long id, Node*& head) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->id == id) {
        head = temp->next;
        delete temp;
        temp->next = nullptr;
        cout << "\033[1;32mItem removed Successfully!\033[0m\n";
        return;
    }

    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "\033[1;31mError: No item found with the ID " << id << ". Please check the ID and try again!\033[0m\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    temp->next = nullptr;
    cout << "\033[1;32mItem removed Successfully!\033[0m\n";
}

bool isEmpty(Node*& head) {
    if (head == nullptr) {
        return true;
    }
    return false;
}

int main() {
    Node* node = nullptr;
    Node* head = node;
    Node* tail = node;

    long id;
    string name;
    int quantity;
    // for decor of texts i have used ANSI escape codes
    cout << "\033[1;36m*****************************************************\033[0m" << endl;
    cout << "\033[1;35m*                                                   *\033[0m" << endl;
    cout << "\033[1;35m*    Welcome to the Warehouse Inventory System!     *\033[0m" << endl;
    cout << "\033[1;35m*                                                   *\033[0m" << endl;
    cout << "\033[1;36m*****************************************************\033[0m" << endl;

    int choice = 0;
    // int testcase = 1;
    while (choice != 6) {
        // cout << "\n\033[38;5;45mTest case: \033[0m" << testcase << endl;
        cout << "\033[1;33m\nPlease choose an operation\033[0m\n";
        cout << "\033[1;34m----------------------------------------\033[0m" << endl;
        cout << "\033[1;32m  1.\033[0m \033[3mAdd a New Item\033[0m" << endl;
        cout << "\033[1;32m  2.\033[0m \033[3mRemove an Item\033[0m" << endl;
        cout << "\033[1;32m  3.\033[0m \033[3mSearch for an Item by ID\033[0m" << endl;
        cout << "\033[1;32m  4.\033[0m \033[3mUpdate Item Quantity\033[0m" << endl;
        cout << "\033[1;32m  5.\033[0m \033[3mDisplay Warehouse Information\033[0m" << endl;
        cout << "\033[1;32m  6.\033[0m \033[3mExit the Program\033[0m" << endl;
        cout << "\033[1;34m----------------------------------------\033[0m" << endl;
        cout << "\033[1;33mEnter your choice:\033[0m ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "Enter Id of the item: ";
            if (cin >> id) {
                cout << "";
            }
            else {
                cout << "\033[1;31mInvalid input! Please enter a valid integer.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            if (alreadyPresent(head, id)) {
                cout << "\033[1;31mError: The ID " << id << " is already in use! Please try a unique ID.\033[0m\n";
                break;
            }
            cout << "Enter Name of the item: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Quantity of the item: ";
            if (cin >> quantity) {
                cout << "";
            }
            else {
                cout << "\033[1;31mInvalid input! Please enter a valid integer.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            insertItem(id, name, quantity, head, tail);
            break;
        case 2:
            if (isEmpty(head)) {
                cout << "\033[1;31mError: No items are currently available to remove!\033[0m\n";
                break;
            }
            cout << "Enter Id of the item: ";
            if (cin >> id) {
                cout << "";
            }
            else {
                cout << "\033[1;31mInvalid input! Please enter a valid integer.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            removeItem(id, head);
            break;
        case 3:
            if (isEmpty(head)) {
                cout << "\033[1;31mError: No items are currently available to serach!\033[0m\n";
                break;
            }
            cout << "Enter Id of the item: ";
            if (cin >> id) {
                cout << "\n";
            }
            else {
                cout << "\033[1;31mInvalid input! Please enter a valid integer.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            searchById(id, head);
            break;
        case 4:
            if (isEmpty(head)) {
                cout << "\033[1;31mError: No items are currently available to update!\033[0m\n";
                break;
            }
            cout << "Enter Id of the item: ";
            if (cin >> id) {
                cout << "";
            }
            else {
                cout << "\033[1;31mInvalid input! Please enter a valid integer.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            cout << "Enter new Quantity: ";
            if (cin >> quantity) {
                cout << "";
            }
            else {
                cout << "\033[1;31mInvalid input! Please enter a valid integer.\033[0m\n";
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
            updateQuantity(id, quantity, head);
            break;
        case 5:
            displayInfo(head);
            break;
        case 6:
            cout << "Thank you for using my \033[1;31mWarehouse Inventory System.\033[0m\n"
                "For any query, please contact me at \033[3;34m\033[4mworkforxynax@gmail.com\033[0m Goodbye!\n";
            break;
        default:
            cout << "\033[1;31mInvalid choice! Please try again.\033[0m\n";
            break;
        }
        // testcase++;
    }
}