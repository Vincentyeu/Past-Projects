//Computer Shop Management System
//Yeu Nian Yong
//Nur Aleeya Erika Binti Mohd Erman
//Farhatul Husna Al-Amin Binti Hisyammudin Alamin
//Liow Chee Yee
//Nazmi Fu Keng Cun

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct lp_specs  //struct 1 to store computer specs
{
    int receipt_number, x;
    string customerName, date;
    int quantity[10], menu2[10];
    int amount[10],total=0,price[20];
	string name[20],GPU[20],CPU[20], ram[20];
	lp_specs *next;
	
}Lpspecs,*q, *temp;

lp_specs *start_ptr = NULL;
lp_specs *head = NULL;
lp_specs *last = NULL;

struct admin //struct 2 to store admin data
{string username,password;
}dm[10];

struct admin_in //struct 3 to store data input by admin
{string uname,pass;
}admin_in1;

void daily_summary() //function to display the order list made by user to admin (function with defination outside the class)
{
    int i, num;
    string str = "\t\t===========================================\n";

    system("cls");
    lp_specs *temp;

    temp = start_ptr;

    if (temp == NULL)
    {
        cout << endl << str;
        cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty\n";
        cout << str << endl;
    }

    else
    {
        cout << "\n";
        cout << "================================================================================================" << endl;
        cout << " \t\t\tHere is the Daily Summary of All Orders \n";
        cout << "================================================================================================\n"
             << endl;

        while (temp != NULL)
        {

            cout << "Receipt Number : " << temp->receipt_number << endl;
            cout << "Customer Name  : " << temp->customerName << endl;
            cout << "Order Date     : " << temp->date << endl
                 << endl;

            cout << "+===================+==============================+====================+=======================+" << endl;
            cout << "|   Computer CPU    |         Computer Name        |      Quantity      |     Total Price (RM)  |" << endl;
            cout << "+===================+==============================+====================+=======================+" << endl;

            for (i = 0; i < temp->x; i++)
            {
                cout << "\t" << Lpspecs.CPU[temp->menu2[i] - 1];
                cout << "\t" << Lpspecs.name[temp->menu2[i] - 1];
                cout << "\t\t\t\t" << temp->quantity[i];
                cout << "\t\t" << temp->amount[i] << ".00" << endl;
                cout << "+-------------------+------------------------------+--------------------+-----------------------+" << endl;
            }
            
            for (i = 0; i < temp->x; i++)
                {
                	temp->total = temp->total + temp->amount[i];
				}

            cout << "\nTotal Bill is : " << "RM" << temp->total << ".00 \n";

            cout << "\n=================================================================================================\n"
                 << endl;

            temp = temp->next;
        }
    }
} // End daily summary


class computerType  //class (1) computerType including the features for users
{
	public:
		coputerType() //contructor 
		{
			
		}
		
		~computerType() //destructor
		{
			
		}
		
		void take_order();
        void delete_order();
        void modify();
        void order_list();
        friend void daily_summary(); //friend function (1)
        void exit();

}computer; //class name 

class cp_specs : public computerType //class (2) cp_specs & inheritance (1) to computerType
{
	public:
		void laptop_specs(); 
}lp;

void read_data() //function to read admin data from Admin.txt file and store into struct admin
{
	int i=0;
	ifstream fin;
	fin.open("Admin.txt");
			
	while (fin >> dm[i].username >> dm[i].password) //read data from Admin.txt file until the end of the file
	{   
		i++; //This represents the number of lines we could extract from the txt file	
	}			
}

class adm : public computerType // class (3) adm & inheritence (2) to computerType
{

	public:
	    int choice;
		const int size=7;
	    
		void login() //function indentify admin username & password and display interface of admin page
		{
			read_data();
			int index = GetNameIndex(admin_in1.uname, size);
			
			if(index == -1)
			{
				cout<<"\n\t\tAccount does not exist";
				cout<<"\n\t\tPlease register as an admin\n";
			}
			
			else if(index >=0)
			{
				if (!PasswordMatches(index, admin_in1.pass)) // If Password & Username does not match 
				{
					cout<<"\n\t\tPassword incorrect!";
					cout<<"\n\t\tPlease try again\n";
				}
			
			    else if(PasswordMatches(index, admin_in1.pass)) // If Password & Username are match 
		    	{
		    		do
					{
		    			system("cls");
			    	    cout<<"\t\t==========================================";
			    	    cout<<"\n\t\t||\t\tADMIN PAGE\t\t||";
			    	    cout<<"\n\t\t==========================================";
			    	    cout<<"\n\t\t******************************************";
			    	    cout<<"\n\t\t*\tWELCOME back "<<admin_in1.uname<<"\t\t*";
			    	    cout<<"\n\t\t******************************************";
			    	    cout<<"\n\t\t==========================================";
			    	    cout<<"\n\t\t|\t[1] Add Product \t\t |";
			    	    cout<<"\n\t\t|\t[2] Display Product \t\t |";
			    	    cout<<"\n\t\t|\t[3] Add Admin \t\t\t |";
			    	    cout<<"\n\t\t|\t[4] Daily Summary of Total Sale\t |";
			    	    cout<<"\n\t\t|\t[5] Exit Admin Page\t\t |";
			    	    cout<<"\n\t\t==========================================";
			    	    cout<<"\n\t\t\tPlease enter your choice : ";
			        	cin>>choice;
			        	features(choice);
					}
					while(choice !=5 ); //Exit the admin page while admin input = 5
		    		
			    }
			}	
			    
	    }
	    
	    void features(int c) // function can be access by admin
	    {
	    	switch(c)
	    	{
	    		case 1:
	    			{
	    				system("cls");
	    				add_product();
	    				system("PAUSE");
	    				break;
					}
	    			
	    		
	    		case 2:
	    			{
					    system("cls");
	    				display_product();
	    				system("PAUSE");
	    				break;
					}
	    			
	    		
	    		case 3:
	    			{
	    				system("cls");
	    				add_admin();
	    				system("PAUSE");
	    				break;
					}
	    			
	    			
	    		case 4:
	    			{
	    				system("cls");
	    				daily_summary();
                        system("PAUSE");
	    				break;
					}
					
				case 5:
					{
						goto b;
						system("PAUSE");
	    				break;
					}		
			}
			
		  b:
		  	  cout<<"\n\t\t******************************************";
			  cout<<"\n\t\t*  THANKYOU "<<admin_in1.uname<<"\t\t\t *";
			  cout<<"\n\t\t*\t\t\tHAVE A NICE DAY  *";
		      cout<<"\n\t\t******************************************\n";
			
		}
		
		void add_product() //Function for admin to add product 
		{string cp_name,cp_CPU,cp_GPU,cp_RAM;
		 int cp_price;
		 
			cout<<"\t\t==========================================";
			cout<<"\n\t\t|\t\tADD PRODUCT\t\t |";
			cout<<"\n\t\t==========================================";
			
			cout<<"\n\t\tEnter Computer Name            : ";
			fflush(stdin);
			getline(cin,cp_name);
			cout<<"\t\tEnter Computer CPU(eg: Intel i5) : ";
			fflush(stdin);
			getline(cin,cp_CPU);
			cout<<"\t\tEnter Computer GPU(eg: RTX 3060) : ";
			fflush(stdin);
			getline(cin,cp_GPU);
			cout<<"\t\tEnter Computer RAM(eg: 32 GB)    : ";
			fflush(stdin);
			getline(cin,cp_RAM);
			cout<<"\t\tEnter Computer Price             : ";
			fflush(stdin);
			cin>>cp_price;
			
			
			ofstream fout; //declaring variable output to file
			fout.open("LaptopNAME.txt", ios::app);
			
         	if (!fout)
         	{
         		cout << "No such file found";
			}
			
            else 
			 {
			 	fout <<"\n"<<cp_name ;
                cout << "\t\tComputer Name updated successfully\n";
             } 

			fout.close();
			
			fout.open("LaptopCPU.txt", ios::app); //open txt file and add record to the file using append mode
		    if(fout.is_open())  //make sure the file can be open
		    {
		    	fout<<"\n"<<cp_CPU;
		    	cout << "\t\tComputer CPU updated successfully\n";
			}
			fout.close(); //close file
			
			fout.open("LaptopGPU.txt", ios::app);
			if(fout.is_open())
		    {
		    	fout<<"\n"<<cp_GPU;
		    	cout << "\t\tComputer GPU updated successfully\n";
			}
			fout.close();
			
			fout.open("LaptopRAM.txt", ios::app);
			if(fout.is_open())
		    {
		    	fout<<"\n"<<cp_RAM;
		    	cout << "\t\tComputer RAM updated successfully\n";
			}
			fout.close();
			
			fout.open("LaptopPRICE.txt", ios::app);
			if(fout.is_open())
		    {
		    	fout<<"\n"<<cp_price;
		    	cout << "\t\tComputer Price updated successfully\n";
			}
			fout.close();
				
		}
		
		void display_product() //function to display the products to admin that currently exist  
		{string str1= "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		 string str2 = "+----+---------------------+---------------------+------------------------+-----------------------+--------------------+\n";
	     int  i = 0, j = 0, k = 0, l = 0, m = 0;
	     
			ifstream fin;  //declaring variable to reading data from file
			fin.open("LaptopNAME.txt"); //open txt file for reading mode
         	while(getline(fin,Lpspecs.name[i])) //read the data from txt file and store into struct computer specs
			{
		     	i++; 
			}
			fin.close(); //close file

			fin.open("LaptopCPU.txt");
			while(getline(fin,Lpspecs.CPU[j]))
			{
				j++;
			}
			fin.close();
			
			fin.open("LaptopGPU.txt");
			while(getline(fin,Lpspecs.GPU[k]))
			{
				k++;
			}
			fin.close();
			
			fin.open("LaptopRAM.txt");
			while(fin>>Lpspecs.ram[l])
			{
				l++;
			}
			fin.close();
			
			fin.open("LaptopPRICE.txt");
			while(fin>>Lpspecs.price[m])
			{
				m++;
			}
			fin.close();
			
			cout<<"\t\t\t\t==========================================="; //interface to display existing product
			cout<<"\n\t\t\t\t|\tBELOW ARE THE EXISTING PRODUCT \t  |";
			cout<<"\n\t\t\t\t===========================================";
			
			cout << "\n"<<str1;
            cout << " ID "
            << "\t COMPUTER RAM(GB)"
            << "\tCOMPUTER CPU"
            << "\t\tCOMPUTER GPU"
            << "\t\tCOMPUTER NAME"
            << "\t   COMPUTER PRICE(RM)" << endl;
            cout <<str1;
			
			for(int n=0;n<m;n++) //display the data stored in struct computer specs(Lpspecs)
			{
				cout<<"["<<n+1<<"]"
				<<"\t\t"<<Lpspecs.ram[n]
				<<"\t\t"<<Lpspecs.CPU[n]
				<<"\t\t"<<Lpspecs.GPU[n]
				<<"\t\t"<<Lpspecs.name[n]
				<<"\t\t"<<Lpspecs.price[n]<<".OO"<<endl;
				cout<<str2;
			}
		}
		
		void add_admin() //function to add new admin 
		{string usernam,upassw;
			ofstream fout;
			fout.open("Admin.txt", ios::app);
			
			cout<<"\t\t==========================================";
			cout<<"\n\t\t|\t\tADD ADMIN \t\t |";
			cout<<"\n\t\t==========================================";
			cout<<"\n\t\tMaximum of the admins are 10";
			cout<<"\n\t\tEnter new admin username : ";
			fflush(stdin);
			getline(cin,usernam); //get new username for new admin from existing admin
			cout<<"\t\tEnter new admin password : ";
			fflush(stdin);
			getline(cin,upassw); //get new password for new admin from existing admin
			
		    if(fout.is_open())
		    {
		    	fout<<"\n"<<usernam<<"\n"<<upassw; //store new username and password into txt file
		    	cout << "\t\tAdmin added successfully\n"; //msg to show if the data is successfully updated 
			}
		}
	    
		int GetNameIndex(string query, int size) //function to search the index of the username
		{int index;
			
		 	for (int i=0; i<size; i++) //prevent the program from reading garbage
			 {
			 	if (query == dm[i].username)
				 {
				 	return i; //Return the index
				 }
				 
			 }
			 return -1; //return error code
		}
		
        bool PasswordMatches(int index, string Password) //function to compare the username and password within the same index
        {
        	return (Password == dm[index].password);
        }
        
        friend void read_data(); //friend function(2)
		
};


void cp_specs :: laptop_specs() //function to display the products that currently exist
{string str2 = "+----+---------------------+---------------------+------------------------+-----------------------+--------------------+\n";
 int n = 0, i = 0, j = 0, k = 0, l = 0, m = 0;
	     
			ifstream fin;
			fin.open("LaptopNAME.txt");
         	while(getline(fin,Lpspecs.name[i]))
			{
		     	i++; 
			}
			fin.close();

			fin.open("LaptopCPU.txt");
			while(getline(fin,Lpspecs.CPU[j]))
			{
				j++;
			}
			fin.close();
			
			fin.open("LaptopGPU.txt");
			while(getline(fin,Lpspecs.GPU[k]))
			{
				k++;
			}
			fin.close();
			
			fin.open("LaptopRAM.txt");
			while(fin>>Lpspecs.ram[l])
			{
				l++;
			}
			fin.close();
			
			fin.open("LaptopPRICE.txt");
			while(fin>>Lpspecs.price[m])
			{
				m++;
			}
			fin.close();
			
			for(int n=0;n<m;n++)
			{
				cout<<"["<<n+1<<"]"
				<<"\t\t"<<Lpspecs.ram[n]
				<<"\t\t"<<Lpspecs.CPU[n]
				<<"\t\t"<<Lpspecs.GPU[n]
				<<"\t\t"<<Lpspecs.name[n]
				<<"\t\t"<<Lpspecs.price[n]<<".OO"<<endl;
				cout<<str2;
			}
} //end of function Laptop_specs
		
void computerType::take_order() //function to take order (function with defination outside the class) //Aleeya 
{
    int i;
    int choice, quantity, price, None;
    string str1 = "************************************************************************************************************************\n";
    string str2 = "+-------+-----------------+---------------------------------+------------------------------+-----------------------+\n";
    system("cls");
    
    cout << "-----------------";
    cout << "\nAdd Order Details\n";
    cout << "-----------------\n\n";

    lp_specs *temp; 
    temp = new lp_specs;  // Dynamic Memory Allocation

    cout << str1;
    cout << " ID "
         << "\t COMPUTER RAM(GB)"
         << "\tCOMPUTER CPU"
         << "\t\tCOMPUTER GPU"
         << "\t\tCOMPUTER NAME"
         << "\t   COMPUTER PRICE (RM)" << endl;
    cout <<str1;
         
    lp.laptop_specs();
   

    temp = new lp_specs; // Dynamic Memory Allocation 

    string str = "-------------------------------------------\n";

    cout << str;
     
    cout<<"***Please remember your RECEIPT NUMBER***"<<endl;
    cout << "Please create a receipt number (eg.1 / eg.2): ";
    cin >> temp->receipt_number; //get input of receipt number from user 

    cout << "Enter Customer Name                         : ";
    fflush(stdin);
    getline(cin,temp->customerName); //get input of name from user

    cout << "Enter Date [DD/MM/YYYY]                     : ";
    getline(cin,temp->date); //get input of date from user

    cout << str;

    cout << "\nEnter the quantity of DIFFERENT model laptop(s) that you like to order";
    cout << "\n(Maximum order is 10 DIFFERENT model laptops(s) each transaction) : ";
    cin >> temp->x; ////get number of different laptop model from user and store into x using pointer temp

    cout << endl;

    if (temp->x <= 0)
    {
         cout << "\nInvalid order!!!\n";
         cout << str;
         system("pause");
    }

    else if (temp->x > 10)
    {
        cout << "\nYour order exceeds the maximum amount of order!!!\n";
        cout << str;
        system("pause");
    }

    else
    {
         cout << str;

         cout << "\t    Enter Computer ID\n";

         for (i = 0; i < temp->x; i++)
         {
              cout << str;

              cout << "Please Select Laptop Model (ID): ";
              cin >> temp->menu2[i];

              cout << "\nLaptop Name       : " << Lpspecs.name[temp->menu2[i] - 1]; 
              cout << "\nLaptop CPU        : " << Lpspecs.CPU[temp->menu2[i] - 1];
              cout << "\nLaptop GPU        : " << Lpspecs.GPU[temp->menu2[i] - 1];
              cout << "\nLaptop RAM        : " << Lpspecs.ram[temp->menu2[i] - 1];
              cout << "\nLaptop Price(per) : " << Lpspecs.price[temp->menu2[i] - 1] <<endl;

              cout << "\n Please enter the quantity of this Model(ID) that you want : ";
              cin >> temp->quantity[i];

              temp->amount[i] = temp->quantity[i] * Lpspecs.price[temp->menu2[i] - 1];
              cout << "\nAmount : RM " << temp->amount[i]  << endl;

              cout << str << endl;

              system("PAUSE");
        }

        cout << "\n===========================================================================" ;
        cout << "\n                     Order Taken Successfully..." ;
        cout << "\n===========================================================================" ;
        cout << "\n           Back to the main menu to print receipt for the payment" ;
        cout << "\n===========================================================================\n" ;

        system("PAUSE");

        temp->next = NULL;

        if (start_ptr != NULL)
            temp->next = start_ptr;

        start_ptr = temp;

        system("cls");
    }
} // end of take order

void computerType :: delete_order() //function to delete order (function with defination outside the class)
{
    system("cls"); //refresh the page

    string str = "\t===========================================\n";

    if (start_ptr == NULL)
    {
        cout << endl;
        cout << str;
        cerr << "\t     Cannot delete from an Empty List\n";
        cout << str;
        cout << endl;
    }

    else
    {
        int i, num, count;
        cout << "\nEnter the receipt number you want to delete: ";
        cin >> num;
        lp_specs *q;
        lp_specs *temp;
        bool found = false;

        if (start_ptr->receipt_number == num)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;

            count--;

            if (start_ptr == NULL)
                last = NULL;

            delete q;

            cout << "\n\t\t============================================";
            cout << "\n\t\t|  The Receipt is Deleted Successfully!!!  |";
            cout << "\n\t\t============================================";
        }

        else
        {
            temp = start_ptr;
            q = start_ptr->next;

            while ((!found) && (q != NULL))
            {
                if (q->receipt_number != num)
                {
                    temp = q;
                    q = q->next;
                }

                else
                    found = true;
            }

            if (found)
            {
                temp->next = q->next;
                count--;

                if (last == q)
                    last = temp;
                delete q;

                cout << "\n\t\t============================================";
                cout << "\n\t\t|  The Receipt is Deleted Successfully!!!  |";
                cout << "\n\t\t============================================\n";
            }

            else
            {
                cout << "\n\t\t==============================================";
                cout << "\n\t\t|  Item to be deleted is not in the list!!!  |" << endl;
                cout << "\n\t\t==============================================\n";
            }
        }
    }
} //end of delete order

void computerType :: modify() //function to modify order (function with defination outside the class) //Aleeya
{
    int i, ch, sid;
    bool found = false;
    temp = start_ptr;
    string str1 = "************************************************************************************************************************\n";
    string str2 = "+-------+-----------------+---------------------------------+------------------------------+-----------------------+\n";
    
	system("cls");

    if (temp == NULL || sid == 0)
    {
        cout << "\n\t\t=============================";
        cout << "\n\t\t|  NO RECORD TO MODIFY...!  |";
        cout << "\n\t\t=============================\n";
    }

    else
    {
        cout << "\nEnter Receipt Number To Modify: ";
        cin >> sid;

        while (temp != NULL && !found)
        {
            if (temp->receipt_number == sid)
                found = true;

            else
                temp = temp->next;

            if (found)
            {   
            
                cout << "\n====================================";
                cout << "\n|      Details of modification     |";
                cout << "\n====================================";
                cout << "\n***Fill in the new details***";
                cout << "\n***Fill in the same detail if you want to remain the same***";
                cout << "\n\nEnter the new Receipt Number : ";
                cin >> temp->receipt_number;

                cout << "Enter the new Customer Name : ";
                fflush(stdin);
                getline(cin,temp->customerName);

                cout << "Enter the new Date          : ";
                fflush(stdin);
                getline(cin,temp->date);
				
				cout << "\n(Maximum is 10 order for each transaction)";
                cout << "\nEnter the quantity of different laptop(s) : ";
                cin >> temp->x;
                cout << "\n";

                if (temp->x > 10)
                {
                    cout << "The quantity of different laptops you order is exceed the maximum amount of order!";
                    system("pause");
                }

                else
                {
                	cout << str1;
                    cout << " ID "
                    << "\t COMPUTER RAM(GB)"
                    << "\tCOMPUTER CPU"
                    << "\t\tCOMPUTER GPU"
                    << "\t\tCOMPUTER NAME"
                    << "\t  COMPUTER PRICE (RM)" << endl;
                    cout <<str1;
         
                    lp.laptop_specs();
                	
                    for (i = 0; i < temp->x; i++)
                    {
                        cout << "-----------------------------------------\n";
                        cout << "\nPlease Enter your new selection : ";
                        cin >> temp->menu2[i];
                        
                        cout << "\n====================================";
                        cout << "\nDetails of Laptop AFTER MODIFIED ";
                        cout << "\n====================================";
                        cout << "\nLaptop Name after modified: " << Lpspecs.name[temp->menu2[i] - 1];
                        cout << "\nLaptop CPU                : " << Lpspecs.CPU[temp->menu2[i] - 1];
                        cout << "\nLaptop GPU                : " << Lpspecs.GPU[temp->menu2[i] - 1];
                        cout << "\nLaptop RAM                : " << Lpspecs.ram[temp->menu2[i] - 1];
                        cout << "\nLaptop Price(per)         : " << Lpspecs.price[temp->menu2[i] - 1] <<endl;


                        cout << "\nPlease enter the quantity for this Model(ID) that you want :  ";
                        cin >> temp->quantity[i];
                        cout << "\n-----------------------------------------\n";

                        temp->amount[i] = (temp->quantity[i]) * Lpspecs.price[temp->menu2[i] -1];

                        cout << "\n----------------------------------------------------------------\n";
                        cout << "The amount you need to pay after modification is: RM" << temp->amount[i] << ".00\n";
                        cout << "----------------------------------------------------------------\n\n";

                        system("PAUSE");
                    }

                    temp = temp->next;

                    system("cls");
                }

                cout << "\n\t\t=================================";
                cout << "\n\t\t| RECORD MODIFIED SUCCESSFULLY! |";
                cout << "\n\t\t=================================\n";
            }

            else
            {
                if (temp != NULL && temp->receipt_number != sid)
                {
                    cout << "\n\t\t================================";
                    cout << "\n\t\t|  Invalid Receipt Number...!  |" ;
                    cout << "\n\t\t================================\n";
                }
            }
        }
    }
} //end of modify

void computerType :: order_list() //function to display the order list(print receipt) made by user (function with defination outside the class) //Husna
{
    int i, num;
    bool found = false;

    string str = "\t\t===========================================\n";

    system("cls");

    lp_specs *temp = start_ptr;

    if (temp == NULL)
    {
        cout << endl << str;
        cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty\n";
        cout << str << endl;
    }

    else
    {
        cout << "\nEnter the Receipt Number To Print The Receipt: ";
        cin >> num;
        cout << "\n";

        while (temp != NULL && !found)
        {
            if (temp->receipt_number == num)
                found = true;

            else
                temp = temp->next;

            if (found)
            {
                cout << "================================================================================================" << endl;
                cout << "\t\t\t\t  Here is the Ordered list\n";
                cout << "================================================================================================\n"
                     << endl;

                cout << "Receipt Number : " << temp->receipt_number << endl;
                cout << "Customer Name  : " << temp->customerName << endl;
                cout << "Order Date     : " << temp->date << endl
                     << endl;

                cout << "+===================+==============================+====================+=======================+" << endl;
                cout << "|   Computer CPU    |         Computer Name        |      Quantity      |    Total Price (RM)   |" << endl;
                cout << "+===================+==============================+====================+=======================+" << endl;

                for (i = 0; i < temp->x; i++)
                {
                    cout << "\t" << Lpspecs.CPU[temp->menu2[i] - 1] ;
                    cout << "\t" << Lpspecs.name[temp->menu2[i] - 1] ;
                    cout << "\t\t\t\t" << temp->quantity[i] ;
                    cout << "\t\t" <<temp->amount[i] << ".00" << endl;
                    cout << "+-------------------+------------------------------+--------------------+-----------------------+" << endl;
                }
                
                temp->total = temp->amount[0] + temp->amount[1] + temp->amount[2] + temp->amount[3] + temp->amount[4] + temp->amount[5] + temp->amount[6] + temp->amount[7] + temp->amount[8] + temp->amount[9];

                cout << "\nTotal Bill: RM" << temp->total << ".00 ";
                cout << "\n\n";

                cout << "Thank You!!!\n";
                cout << "------------\n";
                cout << "================================================================================================\n\n";
            }

        }

        if (!found)
        {
            cout << str;
            cout << "\t\t\t  Invalid Receipt Number!\n";
            cout << str << endl;
        }
    }
} //end of orderlist




void computerType :: exit() //function exit to the main menu (function with defination outside the class)
{
    cout << "\n\t\tYou chosed to Exit.\n"
         << endl;
} //end of exit


int main()
{

    computerType computer;
    adm dm;

    int menu;

    do
    {
        system("cls");

        cout << "\t\t==================================================\n";
        cout << "\t\t\t Computer Store Management System \n";
        cout << "\t\t==================================================\n\n";
        cout << "\t\t---------------------------------------------------\n";
        cout << "\t\t||\t1. Take Order \t\t                 ||\n";
        cout << "\t\t||\t2. Delete Order\t\t\t         ||\n";
        cout << "\t\t||\t3. Modify Order List \t\t\t ||\n";
        cout << "\t\t||\t4. Print Receipt                  \t ||\n";
        cout << "\t\t||\t5. Log-in to admin\t\t\t ||\n";
        cout << "\t\t||\t6. Exit\t\t\t\t\t ||\n";
        cout << "\t\t---------------------------------------------------\n";

        cout << "\n\t\tEnter Choice: ";
        cin >> menu;

        switch (menu) //switch case
        {
        case 1:
        {
            computer.take_order();
            break;
        }

        case 2:
        {
            computer.delete_order();
            system("PAUSE");
            break;
        }

        case 3:
        {
            computer.modify();
            system("PAUSE");
            break;
        }

        case 4:
        {
            computer.order_list();
            system("PAUSE");
            break;
        }

        case 5:
        {
        	cout<<"\n\t\t---------------------------------------------------";
        	cout<<"\n\t\tPlease enter username : ";
			fflush(stdin);
			getline(cin,admin_in1.uname);
			cout<<"\t\tPlease enter password : ";
			fflush(stdin);
			getline(cin,admin_in1.pass);
            dm.login();
           
            system("PAUSE");
            break;
        }
        
        case 6:
        {
        	computer.exit();
        	goto a;
            break;
		}

        default:
        {
            cout << "Invalid input\nPlease re-enter the input\n"
                 << endl;
        }

        }

    } while (menu != 6);

a:
    cout << "\t\t===========================\n";
    cout << "\t\t\tThank You!!!\n";
    cout << "\t\t===========================\n\n";

    system("PAUSE");

    return 0;
}

