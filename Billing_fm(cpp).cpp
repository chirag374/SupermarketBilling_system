#include<iostream>
#include<fstream>
using namespace std;

class shopping {
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void List();
    void receipt();
};

void shopping::menu() // member function within class shopping
{

    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t      Supermarket main menu      \n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t_________________________________\n";
    cout << "\t\t\t\t                                 \n";
    cout << "\t\t\t\t|  1) Administrator  |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t|  2) Buyer          |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t|  3) Exit           |\n";
    cout << "\t\t\t\t|                    |\n";
    cout << "\t\t\t\t| Please select: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email: \n";
        cin >> email;

        cout << "\t\t\t Password:    \n";
        cin >> password;

        if (email == "chiragbhargava86@gmail.com" && password == "123456789") {
            administrator();
        }
        else {
            cout <<"Invalid email/password"<<endl;
        }

        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);

    default:
        cout << "Please select from the given options" << endl;
    }


}

void shopping::administrator() {
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu\n\n";
    cout << "\n\t\t\t|_____1) Add the product_____|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____2) Modify the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____3) Delete the product__|";
    cout << "\n\t\t\t|                            |";
    cout << "\n\t\t\t|_____4) Back to main menu___|";

    cout << "\n\n\t Please enter your choice: "<<endl;
    cin >> choice;

    switch (choice) {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice!";
    }


}

void shopping::buyer() {

    int choice;
    cout<<endl;
    cout << "\t\t\t Buyer \n";
    cout << "\t\t\t___________ \n";
    cout << "                  \n";
    cout << "\t\t\t 1) Buy product\n";
    cout << "                   \n";
    cout << "\t\t\t 2) Go back    \n";
    cout << "\t\t\t Enter your choice: ";

    cin >> choice;

    switch (choice) {
    case  1:
        receipt();
        break;

     case 2:
        menu();
        break;

     default:
        cout << "Invalid choice"<<endl;
     }

 }

 void shopping ::add()
 {

     fstream data;
     int c;
     int token=0;
     float p;
     float d;
     string n;

     cout<<"\n\n\t\t\t Add new product";
     cout<<"\n\n\t code of the product ";
     cin>>pcode;
     cout<<"\n\n\t Name of the product ";
     cin>>pname;
     cout<<"\n\n\t price of the product ";
     cin>>price;
     cout<<"\n\n\t Discount on product ";
     cin>>dis;

     // now we have to open a file
     /* we use file handling operation */

     data.open("database.txt",ios::in);

     if(!data)
     {
         data.open("database.txt",ios::app|ios::out);
         data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
         data.close();
     }
     else
     {
         data>>c>>n>>p>>d;

         while(!data.eof())
         {
             if(c==pcode)
             {
                 token++;
             }
             data>>c>>n>>p>>d;
         }
         data.close();



            data.open("database.txt",ios::app|ios::out);// here we openeing the file in append and writing mode
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();

     }

     cout<<"\n\n\t\t Record inserted !";
}

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code:";
    cin>>pkey;


    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't exist! ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                 data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }

    }

}

void shopping::rem()
{
    fstream data , data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t product code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";

    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t product deleted succesfully";\
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                //data>>pcode>>pname>>price>>dis;

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping::List()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|______________________________________\n";
    cout<<"proNo\t\tName\t\tprice"<<endl;
    cout<<"\n\n|______________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float disc = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database"<<endl;
    }
    else
    {
        data.close();

        List();
        cout << "\n______________________________________\n";
        cout << "\n|                                     \n";
        cout << "\n      please place the order          \n";
        cout << "\n______________________________________\n";
        do
        {
            cout << "\n\nEnter product code:";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. please try again!";
                    // Reset the input variables
                    c = 0;
                    choice = 'y';
                    break;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes, then press 'y', else press 'n': ";
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t________________RECEIPT_______________\n";
        cout << "\nproduct No\t product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    disc = amount - (amount * dis / 100);
                    total = total + disc;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << disc;

                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n_________________________________";
    cout << "\n Total Amount :" << total;
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}
