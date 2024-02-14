#include "contact.h"


void Init(struct index *&Head) {
    Head = new struct index;
    if (Head == NULL) {
        cout << "Initialization failed." << endl;
        return;
    }
    Head->next = NULL;
    Head->firstLetter = 'A';
    Head->firstPerson = NULL;
    struct index *scanner = new struct index;
    scanner = Head;
    for (int timer = 66; timer <= 90; timer++) {    //66 = B, 90 = Z
        scanner->next = new struct index;
        scanner->next->firstLetter = (char) timer;
        scanner->next->firstPerson = NULL;
        scanner = scanner->next;
    }
    scanner = nullptr;
    delete scanner;
}

void NewPerson(struct index *&Head) {
    string firstNameInput, lastNameInput;
    while (UntilBreak) {
        //if the first letter of first name and last name is not UPPERCASE, decline and re input
        while (UntilBreak) {
            cout << "Please input first name" << endl;
            cin >> firstNameInput;
            if (firstNameInput[0] >= 65 && firstNameInput[0] <= 90) break;
            cout << "Input invalid, please check whether the first letter is using UPPERCASE." << endl;
        }
        while (UntilBreak) {
            cout << "Please input last name" << endl;
            cin >> lastNameInput;
            if (lastNameInput[0] >= 65 && lastNameInput[0] <= 90) break;
            cout << "Input invalid, please check whether the first letter is using UPPERCASE." << endl;
        }
        if (!PersonExist(Head, firstNameInput, lastNameInput, false))   break;
        cout << "The person already exists, please check your input." << endl;
    }
    //if the person not exist, continue
    //using insertion sort, insert the person node right into the correct place
    //to do so, a feature of string is used: compare string directly using < and >
    //in cpp, system will automatically compare ascii code of every letter
    //for example, "Mike" > "Make" ? returns true and "Mike" > "mike" returns false
    //when length is various, system will also return compare result BY LETTER
    //for example, "c" > "aaaaa" ? returns true because only the first letter is being compared
    struct index *indexScanner = new struct index;
    for (indexScanner = Head; indexScanner->firstLetter < lastNameInput[0] && indexScanner->next != NULL; indexScanner = indexScanner->next);

    person *newPerson = new person;
    if (indexScanner->firstPerson == NULL) {    //if first person under current index
        indexScanner->firstPerson = newPerson;
    } else {
        //if insertion point is 0, insert it
        if (lastNameInput < indexScanner->firstPerson->lastName) {
            newPerson->next = indexScanner->firstPerson;
            indexScanner->firstPerson = newPerson;
        } else {    //if insertion point is not 0, search for a correct place and insert it
            person *personScanner = indexScanner->firstPerson;
            for (; personScanner->next != NULL && lastNameInput <= personScanner->next->lastName; personScanner = personScanner->next);
            newPerson->next = personScanner->next;
            personScanner->next = newPerson;
        }
    }
    //fill data
    newPerson->firstName = firstNameInput;
    newPerson->lastName = lastNameInput;
    cout << "Please input telephone number" << endl;
    cin >> newPerson->tel;
    cout << "Please input qq" << endl;
    cin >> newPerson->qq;
    cout << "Please input wechat" << endl;
    cin >> newPerson->wechat;
    while (UntilBreak) {
        cout << "Please input email" << endl;
        cin >> newPerson->email;
        int atCount = 0, atPos = 0, pointCount = 0, pointPos = 0;
        for(int timer = 0; timer < newPerson->email.length(); timer++) {
            if (newPerson->email[timer] == '@') {
                atCount++;
                atPos = timer;
            }
            if (newPerson->email[timer] == '.') {
                pointCount++;
                pointPos = timer;
            }
        }
        if (atCount == 1 && pointCount == 1 && atPos < pointPos && pointPos - atPos > 1)    break;
        cout << "Input invalid. Please check Email format." << endl;
    }
    indexScanner = nullptr;
    delete indexScanner;
    newPerson = nullptr;
    delete newPerson;
}

//if output = true, show information on screen
bool PersonExist(struct index *Head, string firstName, string lastName, bool output) {
    struct index *indexScanner = new struct index;
    for (indexScanner = Head; indexScanner->firstLetter < lastName[0] && indexScanner->next != NULL; indexScanner = indexScanner->next);
    if (indexScanner->firstPerson == NULL) {    //not found, return
        if (output) cout << "Person not found." << endl;
        indexScanner = nullptr;
        delete indexScanner;
        return false;
    }
    for (person *personScanner = indexScanner->firstPerson; personScanner != NULL; personScanner = personScanner->next) {
        if (personScanner->firstName == firstName && personScanner->lastName == lastName) { //found, return
            if (output) {
                cout << "Person found." << endl;
                cout << "Name: " << personScanner->firstName << " " << personScanner->lastName << endl;
                cout << "Telephone number: " << personScanner->tel << endl;
                cout << "qq: " << personScanner->qq << endl;
                cout << "wechat: " << personScanner->wechat << endl;
                cout << "email: " << personScanner->email << endl;
            }
            indexScanner = nullptr;
            personScanner = nullptr;
            delete indexScanner;
            delete personScanner;
            return true;
        }
    }
    //not found, return
    if (output) cout << "Person not found." << endl;
    indexScanner = nullptr;
    delete indexScanner;
    return false;
}

void Edit(struct index *&Head, string firstName, string lastName) {
    struct index *indexScanner = new struct index;
    for (indexScanner = Head; indexScanner->firstLetter < lastName[0] && indexScanner->next != NULL; indexScanner = indexScanner->next);
    if (indexScanner->firstPerson == NULL) {    //not found, return
        cout << "Person not found." << endl;
        indexScanner = nullptr;
        delete indexScanner;
        return;
    }
    person *personConnect = indexScanner->firstPerson;
    for (person *personScanner = indexScanner->firstPerson; personScanner != NULL; personScanner = personScanner->next) {
        if (personScanner->firstName == firstName && personScanner->lastName == lastName) { //found, change info
            cout << "Person found." << endl;
            cout << "Name: " << personScanner->firstName << " " << personScanner->lastName << endl;
            cout << "Telephone number: " << personScanner->tel << endl;
            cout << "qq: " << personScanner->qq << endl;
            cout << "wechat: " << personScanner->wechat << endl;
            cout << "email: " << personScanner->email << endl;
            //delete first person
            if (personScanner == indexScanner->firstPerson) {
                indexScanner->firstPerson = personScanner->next;
            } else {    //delete another person
                personConnect->next = personConnect->next->next;
            }
            indexScanner = nullptr;
            delete indexScanner;
            delete personScanner;
            cout << "Input new information:" << endl;
            NewPerson(Head);
            return;
        }
    }
    //not found, return
    cout << "Person not found." << endl;
    indexScanner = nullptr;
    delete indexScanner;
    return;
}

void Delete(struct index *&Head, string firstName, string lastName) {
    struct index *indexScanner = new struct index;
    for (indexScanner = Head; indexScanner->firstLetter < lastName[0] && indexScanner->next != NULL; indexScanner = indexScanner->next);
    if (indexScanner->firstPerson == NULL) {    //not found, return
        cout << "Person not found." << endl;
        indexScanner = nullptr;
        delete indexScanner;
        return;
    }
    int connectLock = 1;
    person *personConnect = indexScanner->firstPerson;
    for (person *personScanner = indexScanner->firstPerson; personScanner != NULL; personScanner = personScanner->next) {
        //personConnect will start its traverse in second round and keep its->next = personScanner
        if (connectLock == 0)   personConnect = personConnect->next;
        if (personScanner->firstName == firstName && personScanner->lastName == lastName) { //found, change info
            cout << "Person found." << endl;
            cout << "Name: " << personScanner->firstName << " " << personScanner->lastName << endl;
            cout << "Telephone number: " << personScanner->tel << endl;
            cout << "qq: " << personScanner->qq << endl;
            cout << "wechat: " << personScanner->wechat << endl;
            cout << "email: " << personScanner->email << endl;
            char del;
            while(UntilBreak) {
                cout << "Do you sure you want to delete this person?(y/n): ";
                cin >> del;
                if (del == 'y' || del == 'n')   break;
                cout << "Input invalid. Only 'y' or 'n' is accepted." << endl;
            }
            //delete
            if (del == 'y') {
                //delete first person
                if (personScanner == indexScanner->firstPerson) {
                    indexScanner->firstPerson = personScanner->next;
                } else {    //delete another person
                    personConnect->next = personConnect->next->next;
                }
            } else {    //cancel
                personScanner = nullptr;
            }
            indexScanner = nullptr;
            delete indexScanner;
            delete personScanner;
            return;
        }
        connectLock = 0;
    }
    //not found, return
    cout << "Person not found." << endl;
    indexScanner = nullptr;
    delete indexScanner;
    return;
}

void Output(struct index *Head) {
    struct index *indexScanner = new struct index;
    person *personScanner = new person;
    for (indexScanner = Head; indexScanner != NULL; indexScanner = indexScanner->next) {
        for (personScanner = indexScanner->firstPerson; personScanner != NULL; personScanner = personScanner->next) {
            cout << "Name: " << personScanner->firstName << " " << personScanner->lastName << endl;
            cout << "Telephone number: " << personScanner->tel << endl;
            cout << "qq: " << personScanner->qq << endl;
            cout << "wechat: " << personScanner->wechat << endl;
            cout << "email: " << personScanner->email << endl;
            cout << endl;
        }
    }
    cout << "All information have shown." << endl;
    indexScanner = nullptr;
    personScanner = nullptr;
    delete indexScanner;
    delete personScanner;
}

void LoadExampleData(struct index *&Head) {
    ifstream read;
    read.open("ExampleData.dat");
    for (int timer = 0; timer < 17; timer++) {
        string firstNameInput, lastNameInput;
        read >> firstNameInput;
        read >> lastNameInput;
        struct index *indexScanner = new struct index;
        for (indexScanner = Head; indexScanner->firstLetter < lastNameInput[0] && indexScanner->next != NULL; indexScanner = indexScanner->next);
        person *newPerson = new person;
        if (indexScanner->firstPerson == NULL) {    //if first person under current index
            indexScanner->firstPerson = newPerson;
        } else {
            //if insertion point is 0, insert it
            if (lastNameInput < indexScanner->firstPerson->lastName) {
                newPerson->next = indexScanner->firstPerson;
                indexScanner->firstPerson = newPerson;
            } else {    //if insertion point is not 0, search for a correct place and insert it
                person *personScanner = indexScanner->firstPerson;
                for (; personScanner->next != NULL && lastNameInput <= personScanner->next->lastName; personScanner = personScanner->next);
                newPerson->next = personScanner->next;
                personScanner->next = newPerson;
            }
        }
        //fill data
        newPerson->firstName = firstNameInput;
        newPerson->lastName = lastNameInput;
        read >> newPerson->tel;
        read >> newPerson->qq;
        read >> newPerson->wechat;
        read >> newPerson->email;
        indexScanner = nullptr;
        delete indexScanner;
        newPerson = nullptr;
        delete newPerson;
    }
    read.close();
}