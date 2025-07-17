#include<bits/stdc++.h>
using namespace std;

struct Contact {
    string name, phone, email;
    Contact* next;
};

class PhoneBook {
    Contact* head;
public:
    PhoneBook() { head = nullptr; }

    void addContact(string name, string phone, string email) {
        Contact* newContact = new Contact{name, phone, email, nullptr};
        if(!head) head = newContact;
        else {
            Contact* temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newContact;
        }
        cout << "Contact added.\n";
    }

    void displayContacts() {
        if(!head) {
            cout << "No contacts found.\n";
            return;
        }
        Contact* temp = head;
        cout << "Phonebook:\n";
        while(temp) {
            cout << "Name: " << temp->name << ", Phone: " << temp->phone << ", Email: " << temp->email << '\n';
            temp = temp->next;
        }
    }

    void searchContact(string name) {
        Contact* temp = head;
        while(temp) {
            if(temp->name == name) {
                cout << "Found - Name: " << temp->name << ", Phone: " << temp->phone << ", Email: " << temp->email << '\n';
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found.\n";
    }

    void deleteContact(string name) {
        if(!head) {
            cout << "Phonebook empty.\n";
            return;
        }
        if(head->name == name) {
            Contact* del = head;
            head = head->next;
            delete del;
            cout << "Contact deleted.\n";
            return;
        }
        Contact* curr = head->next;
        Contact* prev = head;
        while(curr) {
            if(curr->name == name) {
                prev->next = curr->next;
                delete curr;
                cout << "Contact deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Contact not found.\n";
    }

    void updateContact(string name) {
        Contact* temp = head;
        while(temp) {
            if(temp->name == name) {
                cout << "Enter new phone: ";
                cin >> temp->phone;
                cout << "Enter new email: ";
                cin >> temp->email;
                cout << "Contact updated.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Contact not found.\n";
    }
};

int main() {
    PhoneBook pb;
    int choice;
    while(1) {
        cout << "\nPhonebook Menu:\n";
        cout << "1. Add Contact\n2. Display All\n3. Search\n4. Delete\n5. Update\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 6) break;

        string name, phone, email;
        switch(choice) {
            case 1:
                cout << "Enter name: "; cin >> name;
                cout << "Enter phone: "; cin >> phone;
                cout << "Enter email: "; cin >> email;
                pb.addContact(name, phone, email);
                break;
            case 2:
                pb.displayContacts();
                break;
            case 3:
                cout << "Enter name to search: "; cin >> name;
                pb.searchContact(name);
                break;
            case 4:
                cout << "Enter name to delete: "; cin >> name;
                pb.deleteContact(name);
                break;
            case 5:
                cout << "Enter name to update: "; cin >> name;
                pb.updateContact(name);
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}
