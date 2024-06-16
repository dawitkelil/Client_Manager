#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Function to print the table
void printTable(const vector<vector<string>>& table) {
    int colWidth = 20; // Fixed column width for all columns
    int numCols = table[0].size();

    // Print the top border of the table
    for (int i = 0; i < numCols; i++) {
        cout << "+";
        for (int j = 0; j < colWidth; j++) {
            cout << "-";
        }
    }
    cout << "+" << endl;

    // Print the rows of the table
    for (const auto& row : table) {
        for (const auto& cell : row) {
            cout << "| " << setw(colWidth - 1) << left << cell;
        }
        cout << "|" << endl;

        // Print the border after each row
        for (int i = 0; i < numCols; i++) {
            cout << "+";
            for (int j = 0; j < colWidth; j++) {
                cout << "-";
            }
        }
        cout << "+" << endl;
    }
}

int main() {
    vector<vector<string>> table = {
        {"Name", "Number", "Email", "Location", "Remarks"}
    };

    string clientName, clientEmail, clientLocation, clientRemarks;
    int clientsNumber;
    
    char addMore;
    do {
        cout << "What is your client's Name? ";
        cin.ignore(); // to clear any remaining characters in the buffer
        getline(cin, clientName);
        
        cout << "What is your client's Number? ";
        cin >> clientsNumber;
        cin.ignore(); // to clear any remaining characters in the buffer
        
        cout << "What is your client's Email? ";
        getline(cin, clientEmail);
        
        cout << "Where is your client located? ";
        getline(cin, clientLocation);
        
        cout << "What are their Remarks? ";
        getline(cin, clientRemarks);
        
        table.push_back({clientName, to_string(clientsNumber), clientEmail, clientLocation, clientRemarks});

        cout << "Do you want to add another client? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
    
    cout << endl << endl;
    
    printTable(table);

    return 0;
}
