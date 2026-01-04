#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    int deliverychoice;
    double subtotal, deliverycharges = 0, finalbill;
    int orderID = 0;
    string address, deliveryType;
    // Read subtotal
    ifstream orderfile("order.txt");
    if (!orderfile) {
        cout << "Order file not found!" << endl;
        return 0;
    }
    orderfile >> subtotal;
    orderfile.close();
     // Read last order ID
    ifstream idfile("last_id.txt");
    if (idfile)
        idfile >> orderID;
    idfile.close();
    orderID++;
    // Delivery option
    cout << "Select delivery option:\n";
    cout << "1. Home Delivery\n";
    cout << "2. Self Pickup\n";
    cin >> deliverychoice;
    cin.ignore();
    if (deliverychoice == 1) {
    deliverycharges = 150;
    deliveryType = "Home Delivery";
    cout << "Enter delivery address: ";
    getline(cin, address);
    }
    else if (deliverychoice == 2) {
    deliverycharges = 0;
    deliveryType = "Self Pickup";
    address = "N/A";
    }
    else {
    cout << "Invalid choice!" << endl;
    return 0;
    }
    finalbill = subtotal + deliverycharges;
    // Write txt bill
    ofstream billfile("bill.txt");
    billfile << "----- FINAL BILL -----\n";
    billfile << "Order ID: " << orderID << endl;
    billfile << "Subtotal: Rs." << subtotal << endl;
    billfile << "Delivery Charges: Rs." << deliverycharges << endl;
    billfile << "Total Payable: Rs." << finalbill << endl;
    billfile << "Delivery Type: " << deliveryType << endl;
    billfile << "Address: " << address << endl;
    billfile.close();
    // Write csv bill
    ofstream csvFile("bill.csv", ios::app);
    if (csvFile.tellp() == 0) {
        csvFile << "Order ID,Subtotal,Delivery Choice,Delivery Type,Delivery Address,Delivery Charges,Final Bill\n";
    }
    csvFile << orderID << ",";
    csvFile << subtotal << ",";
    csvFile << deliverychoice << ",";
    csvFile << deliveryType << ",";
    csvFile << address << ",";
    csvFile << deliverycharges << ",";
    csvFile << finalbill << endl;
    csvFile.close();
     // Save last order ID
    ofstream saveID("last_id.txt");
    saveID << orderID;
    saveID.close();
    cout << "\nBill generated successfully!" << endl;
    cout << "Order ID: " << orderID << endl;
    cout << "Total Amount: Rs." << finalbill << endl;
    return 0;
}
