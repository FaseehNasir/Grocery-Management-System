#include<bits/stdc++.h>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

void admin_registration();
void customer_registration();
void user_menu();

void login_admin();
void login_customer();

void create_account_admin() ;
void create_account_customer() ;

void place_your_order();
void admin_module();
void add_product();
void check_inventory();
void del_product();
void update();
void search();
void display_recipt();

ofstream file1 ;
ifstream file2 ;
fstream file3;

// registration type
int registration_type()
{
	system("CLS") ;
	int type ;
	cout << "\n\n\t\t =================== Welcome to Registration Module ===================" ;
	cout << "\n Choose your account type " ;
	cout << "\n  1. Admin" ;
	cout << "\n  2. Customer" ;
	cout << "\n  3. Exit the system" ;
	cout << "\n\n  Account type: " ;
	cin >> type ;
	
	switch(type) {
		case 1: admin_registration(); break;
		case 2: customer_registration(); break;
		case 3: exit(0);
		default:
			cout << "\n Invalide choice!!!" ;
			registration_type();
	}
}

// registration module for admin
void admin_registration()
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Welcome to Admin Registration Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Kindly create your own username and password" << endl << endl;
	
	string username, password ;
	// get the username and password
	cout << "\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	
	// now open the file to save the username and password
	file1.open("admin_login.txt", ios::app|ios::binary) ;
	
	if(!file1) { cout << "\n Can not open the requested file."	;}
	else {
		cout << endl ;
		file1 << username << ":" << password << endl ;
		file1.close() ;
	}
	cout << "\n Your account has been created." << endl ;
	cout << "\n Redirecting to Admin Login module......" ;
	sleep(2) ;
	// call admin login
	login_admin();
}

void customer_registration()
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Welcome to Customer Registration Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Kindly create your own username and password" << endl << endl;
	
	string username, password ;
	// get the username and password
	cout << "\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	
	// now open the file to save the username and password
	file1.open("customer_login.txt", ios::app|ios::binary) ;
	
	if(!file1) { cout << "\n Can not open the requested file."	;}
	else {
		cout << endl ;
		file1 << username << ":" << password << endl ;
		file1.close() ;
	}
	cout << "\n Your account has been created." << endl ;
	cout << "\n Redirecting to Customer Login module......" ;
	sleep(2) ;
	login_customer();
}

// login for admin
void login_admin() 
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Admin Login Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Enter your credentials to login" ;
	
	string username, password ;
	bool _log = false ;
	
	// get the username and password of the admin user
	cout << "\n\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	// open the file in read mode to check the data
	file2.open("admin_login.txt", ios::in|ios::binary) ;
	if(file2.is_open()) {
		string line ;
		while(getline(file2, line)) {
			if(line == (username+":"+password)) 
			{
				_log = true ;
				cout << "\n Logged in successfully." ;
				system("pause"); 
				admin_module();
				break ;
			}
		}
		if(_log == false) {
			cout << "\n Incorrect username or password!!!" ;
			cout << "\n Or you may not have been registered into the system" ;
		}
		file2.close();
	}
	
}

// login for customer
void login_customer() 
{
	system("CLS") ;
	cout << "\n\n\t\t ************** Customer Login Module ************** " ;
	cout << "\n\n" ;
	cout << "\n Enter your credentials to login" ;
	
	string username, password ;
	bool _log = false ;
	
	// get the username and password of the admin user
	cout << "\n\n Username: " ;
	cin >> username ;
	cout << "\n Password: " ;
	cin >> password ;
	// open the file in read mode to check the data
	file2.open("customer_login.txt", ios::in|ios::binary) ;
	if(file2.is_open()) {
		string line ;
		while(getline(file2, line)) {
			if(line == (username+":"+password)) {
				_log = true ;
				cout << "\n Logged in successfully." ;
				sleep(1);
				place_your_order();
				break ;
			}
		}
		if(_log == false) {
			cout << "\n Incorrect username or password!!!" ;
			cout << "\n Or you may not have been registered into the system" ;
		}
		file2.close();
	}
	
}

// customer_module
void place_your_order()
{ 
  	string pname ;
	int price ;
	int id ;
	int weight ;
	int nquantity ;
	double total;
	cout << "\n Please wait while the system is getting ready......" ;
	sleep(3) ;
	cout << "\n System is ready" ;
	sleep(1) ;
	system("CLS") ;
	cout << "\n\n\t\t  ==================== PLACE YOUR ORDER HERE ====================" ;
	cout << "\n\n\n We accept CASH ONLY" ;
	cout << "\n NOTE: Maximum 10 orders you can place at a time." ;
	string product_name, address;
	int quantity ;
	int orders ;
	cout << endl;
	cout << "\n How many orders do you want to place? ";
	cin >> orders ;
	// get the product_name and quantity
	ifstream myfile;
	for(int i=1; i<=orders; i++)
	{
		cout << "\n Product name: " ;
		cin >> product_name ;
		cout << "\n Quantity: " ;
		cin >> quantity ;
		file1.open("customers_order.txt",ios::app|ios::binary) ;
		myfile.open("products.txt",ios::app|ios::binary);
		  while (!myfile.eof())
  {
  myfile >> id;
  myfile >> pname;
  myfile >> price;
  myfile >> weight;
  myfile >> nquantity;
    if	(pname==product_name)
    {
    	total = price * quantity;
	}	
}
    double discount=0.2;//20%
    total = total*(1-discount);
		// write in the file
		file1 << "Product:" << product_name << " Quantity:"<< quantity << " (After Discount)Total Amount:"<< total;
		file1.close();
		sleep(1);
		cout << endl;
	}
	cout << "\n Mention your address: " ;
	string addr ;
	cin >> addr;
	file1.open("customers_order.txt",ios::app|ios::binary) ;
	file1 << " Address:" << addr << endl ;
	sleep(1);
	cout << "\n Please wait for the confirmation from the store....." ;
	sleep(2) ;
	cout << "\n Your order has been placed successfully. " ;
	cout << "\n We will reach you out as soon as possible. ";

  cout << "\n Do you want to place order again? " ;
  char ch;
  cin >> ch ;
  if(ch == 'y' || ch == 'Y') 
  {
      place_your_order();
  }
  else { 
  	cout <<endl<< "\t****************************************" << endl ;
	cout << "\t\t             Your total Bill" ;
	cout << endl <<"\t****************************************" << endl ;
	cout << "Product:" << product_name << " Quantity:"<< quantity << " (After Discount)Total Amount:"<< total << endl;
	cout << "Address:" << addr;
  sleep(4);
  user_menu(); 
  }
}

// admin_module
void admin_module()
{
	system("CLS") ;
	cout << "\n\n\t\t  ==================== ADMIN MODULE ====================" ;
	cout << "\n\n";
	cout << "\n  1. Add Product" ;
	cout << "\n  2. Check your Inventory" ;
	cout << "\n  3. Delete Product" ;
	cout << "\n  4. Update Product" ;
	cout << "\n  5. Search Product" ;
	cout << "\n  6. Exit the module" ;
	
	int choice ;
	cout << "\n\n Your choice: " ;
	cin >> choice ;
	switch(choice) {
		case 1: add_product(); break ;
		case 2: check_inventory(); break ;
		case 3: del_product(); break ;
		case 4: update(); break;
		case 5: search(); break;
		case 6: exit(0); break ;
	}
}

// update module
void update()
{
  	string product_name ;
  	string pname ;
	int price ;
	int id ;
	int weight ;
	int quantity ;
  cout << endl <<"Please Enter name of the product you want to update "<< endl;
  cin >> product_name;
  ifstream myfile;
  myfile.open("products.txt",ios::app|ios::binary);
  ofstream temp;
  temp.open("temp.txt",ios::app|ios::binary);
  

  //file1 << id << " " << product_name << " " << price << " " << weight << " " << quantity << " " <<endl;
  while (!myfile.eof())
  {
  myfile >> id;
  myfile >> pname;
  myfile >> price;
  myfile >> weight;
  myfile >> quantity;
    if (product_name == pname)
	{
		int nprice;
		int nquantity;
		char way;
	    cout << "\nEnter the thing you want to update price(p) or quantity(q) = \n"; 
		cin >> way;
		if (way == 'p' || way == 'P')
		{
			cout << "\nEnter the new price";
			cin >> nprice;
			temp << id << " "<< product_name << " "<< nprice << " "<< weight << " "<< quantity << endl;
		}
	    if (way == 'q' || way == 'Q')
		{
			cout << "\nEnter the new Quantity";
			cin >> nquantity;
			temp << id << " "<< product_name << " "<< price << " "<< weight << " "<< nquantity << endl;
		}
	}
	else
	{
	temp << id << " "<< pname << " "<< price << " "<< weight << " "<< quantity << endl;}
  }
  cout << "The record has been updated " << endl;
  	myfile.close();
  temp.close();
  remove("products.txt");
  rename("temp.txt", "products.txt");
  // send the confirmation msg
  char ch;
  cout << "\n Do you want to update more products? " ;
  cin >> ch ;
  if(ch == 'y' || ch == 'Y') 
  {
     update();
  }
  else { admin_module(); }
}

void search()
{
  	string product_name ;
  	string pname ;
	int price ;
	int id ;
	int weight ;
	int quantity ;
  cout << endl <<"Please Enter name of the product you want to search the price and quantity of "<< endl;
  cin >> product_name;
  ifstream myfile;
  myfile.open("products.txt",ios::app|ios::binary);
  //file1 << id << " " << product_name << " " << price << " " << weight << " " << quantity << " " <<endl;
  while (!myfile.eof())
  {
  myfile >> id;
  myfile >> pname;
  myfile >> price;
  myfile >> weight;
  myfile >> quantity;
    if (product_name == pname)
	{
		cout << endl<<" The price of the product is: " << price << endl <<" The quantity of the product is: " << quantity << endl;
	}
}
  	myfile.close();
  // send the confirmation msg
  char ch;
  cout << "\n Do you want to search more products? " ;
  cin >> ch ;
  if(ch == 'y' || ch == 'Y') 
  {
     search();
  }
  else { admin_module(); }
}

// del_product module
void del_product()
{
  	string product_name ;
  	int pid ;
	int price ;
	int id ;
	int weight ;
	int quantity ;
  cout << "Please Enter the id of product you want to delete: ";
  cin >> pid;
  ifstream myfile;
  myfile.open("products.txt",ios::app|ios::binary);
  ofstream temp;
  temp.open("temp.txt",ios::app|ios::binary);
  

  //file1 << id << " " << product_name << " " << price << " " << weight << " " << quantity << " " <<endl;
  while (!myfile.eof())
  {
  myfile >> id;
  myfile >> product_name;
  myfile >> price;
  myfile >> weight;
  myfile >> quantity;
    if (id != pid)
	{
	temp << id << " "<< product_name << " "<< price << " "<< weight << " "<< quantity << endl;
	}
  }
  cout << "The record has been deleted " << endl;
  	myfile.close();
  temp.close();
  remove("products.txt");
  rename("temp.txt", "products.txt");
  // send the confirmation msg
  cout << "\n Product has been removed." ;
  char ch;
  cout << "\n Do you want to delete more products? " ;
  cin >> ch ;
  if(ch == 'y' || ch == 'Y') 
  {
     del_product();
  }
  else { admin_module(); }
}
// add_product module
void add_product()
{
	string product_name ;
	int price ;
	int id ;
	int weight ;
	int quantity ;
	
	cout << "\n\n\n Add your products here." ;
	cout << "\n\n" ;
	cout <<"\n Product Id: " ; cin >> id ;
	cout <<"\n Product name: " ; cin >> product_name ;
	cout << "\n Price: " ; cin >> price ;
	cout << "\n Weight: " ; cin >> weight ;
	cout <<"\n Quantity: " ; cin >> quantity ;

	file1.open("products.txt",ios::app|ios::binary) ;
	if(!file1){ cout << "\n Can not open the requested file!!" ; }
	else{
		cout << endl;
		file1 << endl <<id << " " << product_name << " " << price << " " << weight << " " << quantity << " " <<endl;
		file1.close();
	}
	// send the confirmation msg
	cout << "\n Product has been added." ;
	char ch;
	cout << "\n Do you want to add more products? " ;
	cin >> ch ;
	if(ch == 'y' || ch == 'Y') {
		add_product();
	}
	else { admin_module(); }
}

// check your inventory
void check_inventory()
{
	system("CLS") ;
	string read ;
	file3.open("products.txt",ios::out|ios::in);
	cout << "\n\n\n\t\t****************************************" << endl ;
	//file1 << endl <<id << " " << product_name << " " << price << " " << weight << " " << quantity << " " <<endl;
	cout << "\t\t             Your Inventory" ;
	cout << "\n\t\t****************************************" << endl ;
	cout << " Id  Name  Price  Weight  Quality" << endl;
	while(getline(file3, read)) {
		cout << endl ;
		cout << read << endl ;
	}
	cout << "=====================================" << endl ;

	file3.close();
	
	
	cout << "\n want to perform more operations? ";
	char ch;
	cin >> ch;
	if(ch == 'y') {
		admin_module();
	}
	else {
		exit(0);
	}	
}

// Login menu
void user_menu()
{
	char chs ;
	// there will be three modules
	int choice ;
	cout << "\n\n			###############################################" << endl ;
	cout << "				 SUPERMARKET MANAGEMENT SYSTEM " ;
	cout << "\n			###############################################" << endl ;
	cout << "\n\n\n			************ LOGIN/REGISTRATION MODULE ************" << endl ;
	cout << "\n\n\n  1. Customer Login" << endl ;
	cout << "  2. Admin Login" << endl ;
	cout << "  3. Registration" << endl ;
	cout << "  4. Exit the module" << endl ;
	cout << "\n\n  Login type as: " ;
	cin >> choice ;
	
	switch(choice) {
		case 1: login_customer() ; break ;
		case 2: login_admin() ; break ;
		case 3: registration_type(); break; 
		case 4: exit(0) ;
		default: cout << "\n Invalid choice!!" << endl ; break ;
		
		// want to perform more actions
		cout << "\n Do you want to perform more operations?" ;
		cin >> chs ;
		if (chs == 'Y' || chs == 'y' || chs == '1') { 
			system("CLS") ;
			user_menu() ; 
		}
		else if(chs == 'N' || chs == 'n' || chs == '0') {
			exit(0) ;
		}
		else {
			cout << "\n Invalid choice!!!" ;
			cout << "\n Exiting the module" ; exit(0) ;
		}
	}
}

int main()
{
	user_menu() ;
	return 0;
}

