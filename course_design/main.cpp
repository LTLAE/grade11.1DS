#include "contact.h"

int main() {
    struct index *contact;
    Init(contact);
    LoadExampleData(contact);
    char menu;
    string firstName, lastName;
    while(UntilBreak) {
        cout << "--------------------" << endl;
        cout << "Contact" << endl;
        cout << "1 for new person, 2 for search, 3 for edit, 4 for delete, 5 for show all, 6 for quit." << endl;
        cin >> menu;
        switch (menu) {
            case '1':
                NewPerson(contact);
                break;
            case '2':
                cout << "Please input the person's name:" << endl;
                cin >> firstName >> lastName;
                PersonExist(contact, firstName, lastName, true);
                break;
            case '3':
                cout << "Please input the person's name:" << endl;
                cin >> firstName >> lastName;
                Edit(contact, firstName, lastName);
                break;
            case '4':
                cout << "Please input the person's name:" << endl;
                cin >> firstName >> lastName;
                Delete(contact, firstName, lastName);
                break;
            case '5':
                Output(contact);
                break;
            case '6':
                cout << "Quitting..." << endl;
                abort();
            default:
                cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
                //clear input stream by cpp_learners@CSDN
                cout << "Input invalid. Please input again." << endl;
        }
    }
}
