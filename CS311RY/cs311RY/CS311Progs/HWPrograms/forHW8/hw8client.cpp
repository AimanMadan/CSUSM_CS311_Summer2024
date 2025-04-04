// CS311 Yoshii SUM24 - hw8client.cpp
//   ** should be completed!!!
//
// Note that the client knows about elem.h functions.
// It can create el_t objects.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create id+other info to add to the table. e.g. el_t X(30, "C#"...);
//
// NEVER delete my comments!!
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Aiman Madan
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>
#include <string>

// This App is used for managing a hash table that stores musical elements, 
// identified by a unique id, along with additional information like song key, mode, and BPM.
// Users can add, find, delete, display, and save elements to and from the table.

int main()
{
    // cout an explanation of what this App should be used for. 
    cout << "Welcome to Ai.man Hash Table Manager App!" << endl;
    cout << "This specific application allows you to manage a hash table that stores musical elements." << endl;
    cout << "You are able to add, find, delete, display, & save the elements in the table." << endl;

    htable HT;
    string fname; // file name - get the file name here
                  // in the client in case the way I get them is application dependent

    cout << "What is the input file? (.txt file)";
    cin >> fname;
  
    ifstream fin(fname.c_str(), ios::in);
    HT.fillTable(fin);
    // make sure some of elements collide. 
    HT.displayTable();
    cout << endl;
    fin.close();
  
    //I cannot open fout inside a case 
    ofstream fout("newout.txt", ios::out);  


    int selection;
    do {

        cout << "MENU: ---- " << endl; 
        cout << "1 Add an element" << endl; 
        cout << "2 Find an element" << endl;
        cout << "3 Delete an element" << endl;
        cout << "4 Display the table" << endl;
        cout << "5 Save the table to a file at the end" << endl;    
        cout << "6 Quit" << endl;
        cin >> selection;

        int theid;
        string thekey;
        string themode;
        int thebpm;
        el_t theelement;
        int s;

        switch (selection) {

        case 1:  // Add and indicate the slot
            cout << "What is the id to add? ";
            cin >> theid;
            cout << "What is the song key?" ;
            cin >> thekey;
            //  Here get two more pieces of info
            cout << "What is the mode (e.g., minor, major)? ";
            cin >> themode;
            cout << "What is the BPM (beats per minute)? ";
            cin >> thebpm;
            //  Create the element with all the info using the 2nd constructor
            theelement = el_t(theid, thekey, themode, thebpm);
            s = HT.add(theelement);
            cout << "Added the element in slot " << s << endl;
            break;

        case 2: // Find and indicate the element
            cout << "What is the id to find? ";
            cin >> theid;
            theelement =  HT.find(theid); // find based on theid
            cout << "Found this:" << endl;
            cout << "[" << theelement << "]" << endl;
            break;      

        case 3: // Delete and indicate the slot
            cout << "What is the id to find and delete? ";
            cin >> theid;
            s  =  HT.deleteIt(theid); // find and delete it based on theid
            if (s == -1) 
                cout << "Not found!" << endl; 
            else
                cout << "Found it and deleted it from slot:" << s << endl;
            break;      

        case 4: // Display the table
            cout << "The current contents are: " << endl;
            HT.displayTable();
            break;

        case 5: // Save in the same format as input file
            // the output file is newout.txt
            HT.saveTable(fout);
            cout << "Saved the updated table in newout.txt" << endl;
            fout.close();
            break;

        default:
            cout << "bye" << endl;
        }
    }
    while (selection != 6);

 }
