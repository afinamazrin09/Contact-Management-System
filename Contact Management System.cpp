#include <iostream>  // For input and output operations
#include <vector>    // For using dynamic array (vector)
#include <string>    // For using string data type
#include <algorithm> // For standard algorithms (like search or sort)
#include <fstream>   // For file handling (reading and writing files)
#include <iomanip>   // For formatting output with setw
using namespace std;

// Display Menu Function
void DisplayMenu() {

    //•	Purpose: Displays the main menu with options for managing contacts.
	//•	Explanation: Outputs each option number and its corresponding action, making it easy for users to understand the available operations.
	//•	Usage: Called in the main loop to show the menu every time the user needs to select an action.

    cin.ignore();
    cout << "----------CONTACT MANAGEMENT SYSTEM----------" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Update Contact" << endl;
    cout << "4. Delete Contact" << endl;
    cout << "5. View All Contacts" << endl;
    cout << "6. Save Contact to File" << endl;
    cout << "7. Exit" << endl;
    cout << "---------------------------------------------" << endl;
}

// Struct to define ContactDetail
struct ContactDetail {

    //• Purpose: Encapsulates essential contact information (name, email, phone number) for streamlined data management.
    //• Explanation: A structured grouping of contact details, facilitating unified access and storage.
    //• Usage: Instantiated to represent individual contacts and can be stored in collections for efficient management.

    string name;
    string email;
    string number; 
};

// Global vector to store all contacts
vector<ContactDetail> ContactList;

// Function to add a new contact
void addContact() {

    //•	Purpose: Adds a new contact to ContactList.
	//•	Explanation: Prompts the user to enter a name, email, and phone number. After clearing the input buffer, getline() is
    //   used for name and email to allow spaces, while cin is used for the number. The contact is then appended to ContactList.
	//•	Usage: Called when the user selects the option to add a new contact. 
    
    ContactDetail NewContact;
    cout << "Enter Name: ";
    cin.ignore(); // Clear input buffer only once before taking string input
    getline(cin, NewContact.name);
    cout << "Enter Email: ";
    getline(cin, NewContact.email);
    cout << "Enter Number: ";
    getline(cin,NewContact.number);

    // Add new contact to global ContactList
    ContactList.push_back(NewContact);
    cout << "Contact of " << NewContact.name << " is Successfully Added" << endl;
}

// Function to search for a contact by name, email, or number
void SearchContact(){

    //•	Purpose: Searches for a contact by name, email, or phone number.
	//•	Explanation: Takes an integer input (SearchChoice) to determine the search criterion. Based on the choice, 
    //  it searches ContactList for a matching contact and displays the result. If no match is found, an error message is shown.
	//•	Usage: Called when the user selects the search option.

    int SearchChoice;
    cout << "Search Choice" << endl << "1. By Name" << endl << "2. By Email" << endl << "3. By Number" << endl;
    cout <<"Enter Your Choice: ";
    cin >> SearchChoice;

    bool found = false; //to check if a contact is found

    if (SearchChoice == 1){ // Search by name
        string FindName;
        cout << "Enter Name to Search: ";
        cin.ignore();
        getline(cin, FindName);

        // Iterate through contacts to find a match
        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].name == FindName) { 
            cout << "Contact Found!" << endl;
            cout << "Name: " << ContactList[i].name << endl;
            cout << "Email: " << ContactList[i].email << endl;
            cout << "Number: " << ContactList[i].number << endl;
            found = true;
            break; 
            }
        }

    } else if (SearchChoice == 2){ // Search by email
        string FindEmail;
        cout << "Enter Email to Search: ";
        cin.ignore();
        getline(cin, FindEmail);

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].email == FindEmail) { 
            cout << "Contact Found!" << endl;
            cout << "Name: " << ContactList[i].name << endl;
            cout << "Email: " << ContactList[i].email << endl;
            cout << "Number: " << ContactList[i].number << endl;
            found = true;
            break; 
            }
        }

    } else if (SearchChoice == 3){ // Search by number
        string FindNumber;
        cout << "Enter Number to Search: ";
        cin >> FindNumber;

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].number == FindNumber) { 
            cout << "Contact Found!" << endl;
            cout << "Name: " << ContactList[i].name << endl;
            cout << "Email: " << ContactList[i].email << endl;
            cout << "Number: " << ContactList[i].number << endl;
            found = true;
            break; 
            }
        }    
    } else { 
        cout << "Invalid choice";
        return;
    }
if (!found) {
    cout << "Contact Not Found." << endl;
    }
}

//function to update the contact by name, email or number
void UpdateContact()
{   
    //•	Purpose: Updates an existing contact’s details based on the name, email, or phone number.
	//•	Explanation: Prompts the user to choose the field to search by, then finds the contact and 
    //  updates all details (name, email, and number). If no match is found, it notifies the user.
	//•	Usage: Called when the user selects the update option.

    int UpdateChoice;
    cout << "Update Choice" << endl << "1. Name" << endl << "2. Email" << endl << "3. Number" << endl;
    cout <<"Enter Your Choice: ";
    cin >> UpdateChoice;
    bool found = false;

    //update the contact by name
    if (UpdateChoice == 1) {
        string FindName;
        cout << "Enter Name to Update: ";
        cin.ignore();
        getline(cin, FindName);

        for (size_t i = 0; i < ContactList.size(); i++) 
        {
             if (ContactList[i].name == FindName) { 
                ContactDetail NewContact;
                cout << "Enter NEW Name: "; 
                getline(cin, NewContact.name); 
                ContactList[i].name = NewContact.name;
                found = true;
                cout << "Contact Details of " << FindName << " Has Been Updated";
                break;
            }   
        }       
    } else if (UpdateChoice == 2) { //update the contact by email
        string FindEmail;
        cout << "Enter Email to Update: ";
        cin.ignore();
        getline(cin, FindEmail);

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].email == FindEmail) { 
                ContactDetail NewContact;
                cout << "Enter NEW Email: ";
                getline(cin, NewContact.email);
                ContactList[i].email = NewContact.email;
                found = true;
                cout << "Contact Details of " << FindEmail << " Has Been Updated";
                break;
            }
        }
    } else if (UpdateChoice == 3){ //update the contact by number
        string FindNumber;
        cout << "Enter Number to Update: ";
        cin >> FindNumber;

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].number == FindNumber) { 
                ContactDetail NewContact;
                cout << "Enter NEW Number: ";
                cin >> NewContact.number; 
                ContactList[i].number = NewContact.number;
                found = true;
                cout << "Contact Details of " << FindNumber << " Has Been Updated";
                break;
            }
        } 
    } else { 
        cout << "Invalid choice";
        return; 
    }
    if (!found) {
        cout << "Contact not found." << endl;
    } 
}

// Function to delete a contact by name, email, or number
void DeleteContact (){

    //•	Purpose: Deletes a contact from ContactList.
	//•	Explanation: Uses remove_if to find and remove a contact by name, email, or phone number. 
    //  If a match is found, the contact is erased from ContactList.
	//•	Usage: Called when the user selects the delete option.

    int DelChoice;
    cout << "Delete Choice" << endl << "1. By Name" << endl << "2. By Email" << endl << "3. By Number" << endl;
    cout <<"Enter Your Choice: ";
    cin >> DelChoice;

    bool found = false;

    if (DelChoice == 1){ // Delete by name
        string DelName;
        cout << "Enter Name to Delete: ";
        cin.ignore();
        getline(cin, DelName);

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].name == DelName) { 
            ContactList[i].name = "";
            ContactList[i].email = "";
            ContactList[i].number = "";
            found = true;
            cout << "Contact Details of " << DelName << " Has Been Cleared";
            } 
        }

    }else if (DelChoice == 2){ // Delete by email
        string DelEmail;
        cout << "Enter Email to Delete: ";
        cin.ignore();
        getline(cin, DelEmail);

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].email == DelEmail) { 
            ContactList[i].name = "";
            ContactList[i].email = "";
            ContactList[i].number = "";
            found = true;
            cout << "Contact Details of " << DelEmail << " Has Been Cleared";
            } 
        }
    }else if (DelChoice ==3){ // Delete by number
        string DelNumber;
        cout << "Enter Number to Delete: ";
        cin >> DelNumber;

        for (size_t i = 0; i < ContactList.size(); i++) {
            if (ContactList[i].number == DelNumber) { 
            ContactList[i].name = "";
            ContactList[i].email = "";
            ContactList[i].number = "";
            found = true;
            cout << "Contact Details of " << DelNumber << " Has Been Cleared";
            } 
        }
    }else { 
        cout << "Invalid choice";
        return;
    }
    if (!found) {
    cout << "Contact Not Found." << endl;
    }
}

//function to view all contact
void ViewAllContact (){

    //•	Purpose: Displays all contacts in ContactList.
	//•	Explanation: Outputs a formatted table of contacts, showing name, email, and number. If there are no contacts, it displays “No Record found!”.
	//•	Usage: Called when the user selects the option to view all contacts.

    // Write headers for the table
    cout << "Current Record(s)" << endl;
    cout << "========================================================" << endl;
    cout << setw(5) << "No." << setw(10) << "NAME" << setw(20) << "EMAIL" << setw(18) << "NUMBER" << endl;
    cout << "--------------------------------------------------------\n";

    int counter = 0;
    for (size_t i = 0; i < ContactList.size(); i++) 
    {
        if (ContactList[i].name != "\0") // Display only valid records
        {
            counter++;
            cout << setw(4) << counter << setw(12) << ContactList[i].name << setw(18) << ContactList[i].email << setw(18) << ContactList[i].number << endl;
        }
    }    

    if (counter ==0)
    {
        cout << "No Record found !" << endl;
    }
    cout << "========================================================" << endl;
}

//function to open the file and load contacts
void OpenFile(){

    //•	Purpose: Loads contacts from a file into ContactList.
	//•	Explanation: Reads each line from CONTACT.txt, assuming it’s space-separated with name, email, and number, 
    //  then adds it to ContactList. If the file can’t be opened, it displays an error message.
	//•	Usage: Called at the start of main to load contacts from the file.

    string line;
    ifstream fileOPEN;
    fileOPEN.open("CONTACT.txt");

    if (fileOPEN.is_open()){ // Open file for reading

        //skip header lines
        for (int i=0;i<4; ++i){
            getline(fileOPEN,line);
        }

        int i = 0;
        while (getline(fileOPEN, line) && i < ContactList.size()) {
            // Stop if we reach the separator at the end
            if (line.find("====") != string::npos) {
                break;
            }

            // Check if this line looks like a record (i.e., starts with a number)
            if (isdigit(line[0])) {

                // Extract ID and Name based on column positions
                string contactName = line.substr(10, 10);     
                string contactEmail = line.substr(20, 20);  
                string contactNumber = line.substr(40, 20); 

                // Trim any extra spaces
                ContactList[i].name = contactName.substr(0, contactName.find_last_not_of(" ") + 1);
                ContactList[i].email = contactEmail.substr(0, contactEmail.find_last_not_of(" ") + 1);
                ContactList[i].number = contactNumber.substr(0, contactNumber.find_last_not_of(" ") + 1);
                
                // Convert contactNumberStr to integer
                //ContactList[i].number = stoi(contactNumber.substr(0, contactNumber.find_last_not_of(" ") + 1));
                i++;
            }
        }

        fileOPEN.close();
    } else {
        cout << "Enable to find the file!" << endl;
    }
}

//function to save contacts to a file
void SaveFile(){  

    //•	Purpose: Saves all contacts in ContactList to a file.
	//•	Explanation: Opens CONTACT.txt for writing, then writes each contact’s details in a space

    ofstream fileOUT;
    fileOUT.open("CONTACT.txt"); // Open file for writing

    // Write headers for the table
    fileOUT << "Current Record(s)" << endl;
    fileOUT << "========================================================" << endl;
    fileOUT << setw(5) << "No." << setw(10) << "NAME" << setw(20) << "EMAIL" << setw(18) << "NUMBER" << endl;
    fileOUT << "--------------------------------------------------------\n";

    int counter = 0;
    for (size_t i = 0; i < ContactList.size(); i++) 
    {
        if (ContactList[i].name != "\0")
        {
            counter++;
            fileOUT << setw(4) << counter << setw(12) << ContactList[i].name << setw(18) << ContactList[i].email << setw(18) << ContactList[i].number << endl;
        }
    } 
    
    fileOUT << "========================================================" << endl;
    fileOUT.close();
}
 
// Main function
int main(){
    cout << "---------MENU---------"<< endl;
    int choice;
    OpenFile(); // Load contacts from file on startup
    do {
        DisplayMenu();
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                SearchContact();
                break;
            case 3:
                UpdateContact();
                break;
            case 4:
                DeleteContact();
                break;
            case 5:
                ViewAllContact();
                break;
            case 6:
                SaveFile();
                cout << "File saved successfully!" << endl;
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}
