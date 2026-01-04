#include<iostream>
#include<fstream>
using namespace std;
                    //SIGN UP....
void signup()
{
    string u,p,r;
    cout<<"Create username:";
    cin>>u;
    cout<<"Create password:";
    cin>>p;
    cout<<"Enter your role:";
    cin>>r;
    ofstream f("user.csv",ios::app);
    f << u <<","<< p <<"," << r <<endl;
    f.close();

    cout<<"Sign up Successfully:";       
    }
             //LOGIN.....
 bool login( string roleinput)
{
    string u,p,line,fu,fp,fr;

    cout<<"Username:";
    cin>>u;
    cout<<"Password:";
    cin>>p;

    ifstream f("user.csv");
    getline(f,line) ;   //header skip

    while (getline(f,line))
    {
        int i=0;
        fu =fp =fr ="";

        while (line[i] != ',') fu += line[i++];
        i++;
        while(line[i] != ',') fp +=line[i++];
        i++;
        while (i < line.length()) fr += line[i++];

        if (u == fu && p == fp && roleinput == fr)
        return true;
    }
    return false;
}
         //Menu Load and View.......
         int id[50],price[50],n=0;
         string name[50];

void loadMenu()
 {
    ifstream f("menu.csv");
    while (f >> id[n] >> name[n] >> price[n])
     {
        cout << "Loaded: " << id[n] << " " << name[n] << " " << price[n] << endl; // check
        n++;
    }
    f.close();
 }
void viewMenu()
{
    cout << "\n--- MENU ---\n";
    for (int i = 0; i < n; i++)
        cout << id[i] << " " << name[i] << " " << price[i] << endl;
}
        //Add items........
void addItem()
 {
    cout << "ID: ";
    cin >> id[n];
    cin.ignore(); // ignore leftover newline
    cout << "Name: ";
    getline(cin, name[n]); // read full line with spaces
    cout << "Price: ";
    cin >> price[n];
    n++;
}
      //Update Item.....
void updateItem()
{
    int x;
    cout<<"Enter ID to update:";
    cin>>x;
    for(int  i=0 ; i < n ;i++ )
        if(id[i]==x)
        {
          cout<<"New Name:";
          cin>>name[i];
          cout<<"New Price";
          cin>>price[i];
        }        
}  
       //Delete Item......
void deleteItem()
{
    int x;
    cout<<"Enter ID to delete:";
    cin>>x;
    for(int i=0 ; i < n ; i++ )
        if(id[i] ==x)
        {
        for( int j = i ; j < n-1 ; j++)
        {
          id[j] = id [ j+1 ];
          name [j] = name [ j+1 ];
          price[j] = price[ j+1 ];    
        }
        n--;
        }   
} 
        //Save Menu....
void saveMenu() 
{
    ofstream f("menu.csv");
    for (int i = 0; i < n; i++)
    f << id[i] << " " << name[i] << " " << price[i] << endl;
    f.close();
}
   // Main Function......
    int main()
    {
        loadMenu();
        int choice;
        string role;
        cout << "1. Sign Up\n2. Login\nChoice: ";
        cin >> choice;

    if (choice == 1)
        signup();

         cout << "Enter role (admin/user): ";
          cin >> role;

    if (!login(role))
     {
        cout << "Login Failed!";
        return 0;
    }

    if (role == "admin")
     {
        int ch;
        do
         {
            cout << "\n1.View\n2.Add\n3.Update\n4.Delete\n5.Exit\nChoice: ";
             cin >> ch;
            if (ch == 1) viewMenu();
            else if (ch == 2) addItem();
            else if (ch == 3) updateItem();
            else if (ch == 4) deleteItem();
            saveMenu();
        } 
        while (ch != 5);
    } 
    else
     {
        cout << "\nWelcome User!";
        viewMenu();
    }
}

