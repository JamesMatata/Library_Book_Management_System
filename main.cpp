#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class temp{
    string id, name, author, searched;
    fstream file;

public:
    void addBook();
    void showAll();
    void findBook();
}obj;

int main(){
    int choice;
    lb:
    {
        cout<<"\n############################--KiLib-BookStore--################################\n";
        cout<<"\n 1. Show all Books";
        cout<<"\n 2. Find a Book";
        cout<<"\n 3. Add books(ADMIN)";
        cout<<"\n 4. Exit\n";
        cout<<"__________________________________________________________________________________\n";
        cout<<" Enter your choice: ";
        cin>>choice;
        system("cls");
    }

    switch(choice){
        case 1:
            cin.ignore();
            obj.showAll();
            goto lb;
        break;
        case 2:
            cin.ignore();
            obj.findBook();
            goto lb;
        break;
        case 3:
            cin.ignore();
            obj.addBook();
            goto lb;
        break;
        case 4:
            cin.ignore();
            return 0;
        break;
        default:
            cout<<"\nChoose a number between 1 and 4";
    }
    cout<<"\n\n\n--------------------------------------KiLib----------------------------------------";

    return 0;
}

void temp :: addBook(){
    cout<<"\n Enter Book ID: ";
    getline(cin, id);
    cout<<"\n Enter Book Name: ";
    getline(cin, name);
    cout<<"\n Enter Book's Author name: ";
    getline(cin, author);

    // getline helps you read a input strings with white spaces

    // ios::out - means you want to open a file i the output mode(for writing data)
    // ios::in - means you want to open a file in the input mode(for extracting data)
    // ios::app - means you want to open a file in the append mode(for writing data to a file after the last byte.
                    // You use this mode if you want to preserve existing data in the file and don't want to override it
                    // as you do if you use the ios::out file mode

    file.open("bookData.txt",ios :: out | ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
    system("cls");
    showAll();
}

void temp :: showAll(){
    file.open("bookData.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    while(!file.eof()){
        cout<<"\n";
        cout<<"\t Book Id \t\t Book Name \t\t Author's Name"<<endl;
        while(!file.eof()){
            cout<<"\t "<<id<<" \t\t\t "<<name<<" \t\t\t "<<author<<endl;
            getline(file, id, '*');
            getline(file, name, '*');
            getline(file, author, '\n');
        }
    }
    file.close();
}

void temp :: findBook(){
    showAll();
    cout<<"\n Enter Book ID/Name/Author Name: ";
    getline(cin,searched);
    system("cls");

    file.open("bookData.txt", ios :: in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');

    cout<<"\n";
    bool bookFound = false;
    while(!file.eof()){
        if(searched == id || searched == name ||searched == author){
            cout<<"\t Book Id \t\t\ Book Name \t\t Author's Name"<<endl;
            cout<<"\t "<<id<<" \t\t\t "<<name<<" \t\t\t "<<author<<endl;
            bookFound = true;

            cout<<"\t\tBook Successfully found";
        }
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
    }
    if(!bookFound == true){
        cout<<"\t\tBook not Found!";
    }
    file.close();
}
