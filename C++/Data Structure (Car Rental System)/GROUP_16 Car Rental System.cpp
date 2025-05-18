#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

const int MAX_USERS = 100;

void user_page();


struct CarModel
{
    int id;
	string name, brand, colour, body_type, segment, fuel;
    double capacity, horsepower, price;
};

struct User 
{
    string username;
    string password;
    string email;
    string icno;
    string secureCode;
};

struct invoice
{
	string card_hold,cust_name, cust_phone, car_model,car_colour;
	int invoice_no,car_ID,days;
	double rental_amount,caution, advance,car_price;
};

struct card
{
	string holdername,expdate,cardnum;
	int CVV;
};

class quickSort 
{
public:
    void Swap(int x, int y, int a[]) 
	{
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }

    int Partition(int left, int right, int a[]) 
	{
        int pivot = a[left];
        int pivotpos = left;
        for (int i = left + 1; i <= right; i++) 
		{
            if (a[i] < pivot) 
			{
                pivotpos++;
                Swap(pivotpos, i, a);
            }
        }

        Swap(left, pivotpos, a);
        return pivotpos;
    }

    void QuickSort(int left, int right, int a[]) 
	{
        if (left < right) 
		{
            int pivotpos = Partition(left, right, a);
            QuickSort(left, pivotpos - 1, a);
            QuickSort(pivotpos + 1, right, a);
        }
    }
    
    void Swap2(int x, int y, int a[]) 
	{
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }

    int Partition2(int left, int right, int a[]) 
	{
        int pivot = a[left];
        int pivotpos = left;
        for (int i = left + 1; i <= right; i++) 
		{
            if (a[i] > pivot) 
			{
                pivotpos++;
                Swap2(pivotpos, i, a);
            }
        }

        Swap2(left, pivotpos, a);
        return pivotpos;
    }

    void QuickSort2(int left, int right, int a[]) 
	{
        if (left < right) 
		{
            int pivotpos = Partition2(left, right, a);
            QuickSort2(left, pivotpos - 1, a);
            QuickSort2(pivotpos + 1, right, a);
        }
    }
    
};

class admin;

class CarLinkedList
{
public: 
    struct node
    {
        CarModel data;
        node* next;
    };

protected:
    node* head;

public:
    CarLinkedList()
    {
        head = NULL;
    }

    ~CarLinkedList()
    {
        node* temp = head;
        while (temp != NULL)
        {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void insertToNode(const CarModel& data)
    {
        node* newNode = new node;
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayModels()
    {
        node* temp = head;
        int i = 1;
        while (temp != NULL)
        {
            // data brand colour body_type segment capacity horsepower fuel price
            cout << "Model (" << i << ")       | " << temp->data.name << endl;
            cout << "ID              | " << temp->data.id << endl;
            cout << "Brand           | " << temp->data.brand << endl;
            cout << "Colour          | " << temp->data.colour << endl;
            cout << "Body Type       | " << temp->data.body_type << endl;
            cout << "Segment         | " << temp->data.segment << endl;
            cout << "Capacity        | " << temp->data.capacity << " L " << endl;
            cout << "Horsepower      | " << temp->data.horsepower << " PS " << endl;
            cout << "Fuel            | " << temp->data.fuel << endl;
            cout << "Price /per day  | RM " << fixed << setprecision(2) << temp->data.price << endl;
            cout << endl;
            temp = temp->next;
            i++;
        }
    }

    node* findID(const int id)
    {
        node* temp = head;
        while (temp != NULL)
        {
            if (temp->data.id == id)
            {
                return temp; // Found the node and return the node
                break;
            }
            temp = temp->next;
        }
        return NULL; // ID not found in the linked list
    }
	    
	 bool editCar(const int id, string& filePath, string brand)
	{
	    ifstream refreshEdit(filePath.c_str(), ios::in);
	    string empty;
	    int modelId;
	    string modelName, modelBrand, modelColour, modelBody_type, modelSegment, modelFuel;
	    double modelCapacity, modelHorsepower, modelPrice;
	    bool success = false;
	    bool found = false;
	    while (refreshEdit >> modelId) // Read data from file
	    {
	        getline(refreshEdit, empty);
	        getline(refreshEdit, modelName);
	        getline(refreshEdit, modelBrand);
	        getline(refreshEdit, modelColour);
	        getline(refreshEdit, modelBody_type);
	        getline(refreshEdit, modelSegment);
	        refreshEdit >> modelCapacity;
	        getline(refreshEdit, empty);
	        refreshEdit >> modelHorsepower;
	        getline(refreshEdit, empty);
	        getline(refreshEdit, modelFuel);
	        refreshEdit >> modelPrice;
	        getline(refreshEdit, empty);
	        getline(refreshEdit, empty);
	
	        if (modelId == id) // Found the car user wants to edit
	        {
	            found = true;
	            system("CLS");
	            cout << "Enter the new name: ";
	            getline(cin, modelName);
	            modelBrand=brand;
	            cout << "Enter the colour: ";
	            getline(cin, modelColour);
	            cout << "Enter the body type: ";
	            getline(cin, modelBody_type);
	            cout << "Enter the car segment: ";
	            getline(cin, modelSegment);
	            cout << "Enter the capacity (L): ";
	            cin >> modelCapacity;
	            cout << "Enter the horsepower (PS): ";
	            cin >> modelHorsepower;
	            fflush(stdin);
	            cout << "Enter the car fuel: ";
	            getline(cin, modelFuel);
	            fflush(stdin);
	            cout << "Enter the car price (per day): ";
	            cin >> modelPrice;
	
	            CarModel edit;
	            edit.id = modelId;
	            edit.name = modelName;
	            edit.brand = modelBrand;
	            edit.colour = modelColour;
	            edit.body_type = modelBody_type;
	            edit.segment = modelSegment;
	            edit.capacity = modelCapacity;
	            edit.fuel = modelFuel;
	            edit.horsepower = modelHorsepower;
	            edit.price = modelPrice;
	
	            insertToNode(edit); //insert into linkedlist
	        }
	        else
	        {
	            CarModel data;
	            data.id = modelId;
	            data.name = modelName;
	            data.brand = modelBrand;
	            data.colour = modelColour;
	            data.body_type = modelBody_type;
	            data.segment = modelSegment;
	            data.capacity = modelCapacity;
	            data.fuel = modelFuel;
	            data.horsepower = modelHorsepower;
	            data.price = modelPrice;
	
	            insertToNode(data); //insert into linkedlist
	        }
	    }
	
	    refreshEdit.close();
	
	    if (found)
	    {
	        updateCar(filePath.c_str(), id); //get the status whether new data is insert to new txt using linked list
	        success = true;
	    }
	    else
	    {
	        cout << "Error occurred! Car not found." << endl;
	    }
	
	    return success;
	}

	void updateCar(const string& filePath, int id)
	{
	    ofstream temfile("temporary.txt"); // Temporary file to act as a new file
	
	    if (!temfile)
	    {
	        cout << "Error in opening the temporary file" << endl;
	    }
	
	    node* temp = head;
	    while (temp != NULL)
	    {
	        temfile << temp->data.id << endl;
	        temfile << temp->data.name << endl;
	        temfile << temp->data.brand << endl;
	        temfile << temp->data.colour << endl;
	        temfile << temp->data.body_type << endl;
	        temfile << temp->data.segment << endl;
	        temfile << temp->data.capacity << endl;
	        temfile << temp->data.horsepower << endl;
	        temfile << temp->data.fuel << endl;
	        temfile << temp->data.price << endl;
	        temfile << endl;
	
	        temp = temp->next;
	    }
	    
	    temfile.close();
	
	        cout << "Car file updated." << endl;
	        cout << "\nLoading..";
	        for (int i = 0; i < 2; i++)
	        {
	            sleep(1);
	            cout << "..";
	        }
	        cout << "\n\n";
	        system("PAUSE");
	        system("CLS");
	   
	}
	
	bool deleteCar(const string& filePath, int id)
{
    ifstream refreshDlt(filePath.c_str(), ios::in);
    string empty;
    int modelId;
    string modelName, modelBrand, modelColour, modelBody_type, modelSegment, modelFuel;
    double modelCapacity, modelHorsepower, modelPrice;
    bool success = false;
    bool found = false;
    
    if(!refreshDlt)
    {
    	cout<<"Error in opening file."<<endl;
	}

    while (refreshDlt >> modelId) // Read data from file
    {
        getline(refreshDlt, empty);
        getline(refreshDlt, modelName);
        getline(refreshDlt, modelBrand);
        getline(refreshDlt, modelColour);
        getline(refreshDlt, modelBody_type);
        getline(refreshDlt, modelSegment);
        refreshDlt >> modelCapacity;
        getline(refreshDlt, empty);
        refreshDlt >> modelHorsepower;
        getline(refreshDlt, empty);
        getline(refreshDlt, modelFuel);
        refreshDlt >> modelPrice;
        getline(refreshDlt, empty);
        getline(refreshDlt, empty);

        CarModel data;
        data.id = modelId;
        data.name = modelName;
        data.brand = modelBrand;
        data.colour = modelColour;
        data.body_type = modelBody_type;
        data.segment = modelSegment;
        data.capacity = modelCapacity;
        data.fuel = modelFuel;
        data.horsepower = modelHorsepower;
        data.price = modelPrice;

        insertToNode(data); // Insert into linked list
    }

    refreshDlt.close();

    node* dltnode = findID(id);

    if (dltnode != NULL)
    {
        node* temp = head;
        node* prev = NULL;

        while (temp != NULL && temp->data.id != id)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            if (prev == NULL) // Deleting the head node
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;
            found = true;
        }
    }
    else
    {
    	cout<<"Error. Car not found ! "<<endl;
    	found=false;
	}
	
	    if (found)
	    {
	        updateCar(filePath.c_str(), id); 
	        success=true;
	    }
	    else
	    {
	        cout << "Error occurred! Car not found." << endl;
	        success=false;
	    }

    return success;
}
    void saveToFile(const string& filePath);
   
};


// Forward declaration of Proton class
class Proton;

class Car
{
protected:
	CarLinkedList modelList;
    int type, seater,days;
    char brand;
    int selectedId;
	double rentalfee;
	
public:
    void menu();

    void selectBrand();
    int selectModel();
    void rentCar();
    void payment();
    void create_invoice(string username)
    {
		CarLinkedList::node* invNode = modelList.findID(selectedId);
    	
		int size=1,index =0,ID,caution;
		
		 // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(NULL)));
    
    // Generate a random number between 1000 and 9999
    int invoiceNO = 1000 + (rand() % 9000);

		invoice inv[size];
		string name, phone;
		fflush(stdin);
		cout<<"Enter your full name : ";
		getline(cin,name);
		cout<<"Enter your phone number : ";
		getline(cin,phone);
		
		cout << "\nLoading..";
	    for (int i = 0; i < 2; i++)
	    {
	        sleep(1);
	        cout << "..";
	    }
	    cout << "\n\n";
	    system("CLS");
	    
	    double total = invNode->data.price*days+30;
	    
	    if(invNode->data.price > 120)
	    {
	    	caution = 50;
		}
		else
		{
			caution = 20;
		}
		
		cout<<"\n\t\t==================================================================="<<endl;
		cout<<"\t\t                      Wheels On Rent - Customer Invoice              "<<endl;
		cout<<"\t\t ==================================================================="<<endl ;
		cout<<"\t\t  1.Invoice NO.                  : ----------------------  #IN"<<invoiceNO<<endl;
		cout<<"\t\t  2.Customer Name                : ----------------------  "<<name<<endl;
		cout<<"\t\t  3.Customer Phone Number        : ----------------------  "<<phone<<endl;
		cout<<"\t\t  4.Car ID                       : ----------------------  "<<invNode->data.id<<endl;
		cout<<"\t\t  5.Car Model                    : ----------------------  "<<invNode->data.name<<endl;
		cout<<"\t\t  6.Car Colour                   : ----------------------  "<<invNode->data.colour<<endl;
		cout<<"\t\t  7.Price per day                : ----------------------  "<<invNode->data.price<<endl;
		cout<<"\t\t  8.Number of days renting       : ----------------------  "<<days<<endl;
		cout<<"\t\t  9.Caution Money                : ----------------------  RM 30.00"<<endl;
		cout<<"\t\t  10.Advanced                    : ----------------------  RM 0.00 "<<endl;
		cout<<"\t\t  || Your Total Rental Amount is  || --------------------  RM "<<total<<endl;
	
    
    ofstream writeinvoice("invoice.txt",ios::app);
    

		if(!writeinvoice)
		{
			cout<<"Error in writing invoice file."<<endl;
		}
		else
		{
				inv[index].invoice_no = invoiceNO;
				inv[index].cust_name = name;
				inv[index].cust_phone = phone;
				inv[index].car_ID = invNode->data.id;
	   			inv[index].car_model = invNode->data.name;
	   			inv[index].car_colour = invNode->data.colour;
	    		inv[index].car_price = invNode->data.price;
	    		inv[index].days = days;
	    		inv[index].caution = 30;
	    		inv[index].advance = 0;
	    		inv[index].rental_amount = total;
				
				writeinvoice<<inv[index].invoice_no<<endl;
				writeinvoice<<inv[index].cust_name<<endl;
				writeinvoice<<inv[index].cust_phone<<endl;
				writeinvoice<<inv[index].car_ID<<endl;
				writeinvoice<<inv[index].car_model<<endl;
				writeinvoice<<inv[index].car_colour<<endl;
				writeinvoice<<inv[index].car_price<<endl;
				writeinvoice<<inv[index].days<<endl;
				writeinvoice<<inv[index].caution<<endl;
				writeinvoice<<inv[index].advance<<endl;
				writeinvoice<<inv[index].rental_amount<<endl;
				
				index++;
				size++;
				invoiceNO=invoiceNO+1;
		}
   		 	system("PAUSE");
			payment();
	}
    
     void sortCarPage(char brand)
	{
	    quickSort q;
		CarModel data[100];
	    int c=0;
	    
		system("CLS");
		cout << "=================================" << endl;
	    cout << "              Sort Car           " << endl;
	    cout << "=================================" << endl;
	    cout << "1. Sort Car by Price (Lowest to Highest)" << endl;
	    cout << "2. Sort Car by Price (Highest to Lowest)" << endl;
	    cout << "Enter your selection: ";
	
	    int choice;
	    cin >> choice;
	
	    if (choice == 1)
		{
		    // Perform ascending order sorting logic
		    cout << "\nSorting car by price in ascending order..." << endl;
		    
		    ifstream Carfile;
		    
		    if(seater== 4 && brand =='A')
		    {
				Carfile.open("Toyota4S.txt");
			}
			else if(seater==6 && brand =='A')
			{
				Carfile.open("Toyota6S.txt");
			}
		    else if(seater==4 && brand =='B')
		    {
		    	Carfile.open("Proton4S.txt");
			}
			else if(seater==6 && brand == 'B') 
			{
				Carfile.open("Proton6S.txt");
			}
			else if(seater ==4 && brand == 'C')
			{
				Carfile.open("BMW4S.txt");
			 } 
			else if(seater == 6 && brand =='C')
			{
				Carfile.open("BMW6S.txt");
			}
			else 
			{
				cout<<seater;
				cout<<brand;
				cout<<"Error occur ! Invalid car type or car brand ."<<endl;
			}
			
			if(!Carfile)
			{
				cout<<"Unable to open the file";
				exit(1);
			}
			
			
		   while (Carfile >> data[c].id >> ws && getline(Carfile, data[c].name) && getline(Carfile, data[c].brand) &&
           getline(Carfile, data[c].colour) && getline(Carfile, data[c].body_type) && getline(Carfile, data[c].segment) &&
           Carfile >> data[c].capacity >> data[c].horsepower >> ws && getline(Carfile, data[c].fuel) && Carfile >> data[c].price)
			{
				
				c++;
			}

			
			Carfile.close();
			
			int prices[c];
	        for (int i = 0; i < c; i++) {
	            prices[i] = data[i].price;
	        }
	
	        // Apply Quick Sort algorithm to sort prices
	        q.QuickSort(0, c - 1, prices);
	
	        // Reorder data array based on sorted prices
	        CarModel sortedData[100];
	        for (int i = 0; i < c; i++) {
	            for (int j = 0; j < c; j++) {
	                if (data[j].price == prices[i]) {
	                    sortedData[i] = data[j];
	                    break;
	                }
	            }
	        }
	
	        // Update the original data array with sorted data
	        for (int i = 0; i < c; i++) {
	            data[i] = sortedData[i];
	        }
	
	        // Display sorted data
	        for (int i = 0; i < c; i++) 
			{
	            cout << "\nPrice/per day    | " << data[i].price << endl;
	            cout << "Car Model        | " << data[i].name << endl;
	            cout << "Car ID	         | " << data[i].id << endl;
	            cout << "Car Brand        | " << data[i].brand << endl;
	            cout << "Car Colour       | " << data[i].colour << endl;
	            cout << "Car Body Type    | " << data[i].body_type << endl;
	            cout << "Car Segment      | " << data[i].segment << endl;
	            cout << "Car Capacity     | " << data[i].capacity << endl;
	            cout << "Car Horsepower   | " << data[i].horsepower << endl;
	            cout << "Car Fuel         | " << data[i].fuel << endl;
	            fflush(stdin);
	            
	            // Print other details...
	            cout << endl;
	        }
        
	}
	else if (choice == 2)
	{
		    // Perform descending order sorting logic
		    cout << "Sorting car by price in descending order..." << endl;
		    ifstream Carfile2;
		    
			if(seater==4 && brand =='A')
		    {
				Carfile2.open("Toyota4S.txt");
			}
			else if(seater==6 && brand =='A')
			{
				Carfile2.open("Toyota6S.txt");
			}
		    else if(seater==4 && brand =='B')
		    {
		    	Carfile2.open("Proton4S.txt");
			}
			else if(seater==6 && brand == 'B') 
			{
				Carfile2.open("Proton6S.txt");
			}
			else if(seater ==4 && brand == 'C')
			{
				Carfile2.open("BMW4S.txt");
			 } 
			else if(seater == 6 && brand =='C')
			{
				Carfile2.open("BMW6S.txt");
			}
			else 
			{
				cout<<"Error occur ! Invalid car type or car brand ."<<endl;
			}
			
			if(!Carfile2)
			{
				cout<<"Unable to open the file";
				exit(1);
			}
			
			
			while (Carfile2 >> data[c].id >> ws && getline(Carfile2, data[c].name) && getline(Carfile2, data[c].brand) &&
           getline(Carfile2, data[c].colour) && getline(Carfile2, data[c].body_type) && getline(Carfile2, data[c].segment) &&
           Carfile2 >> data[c].capacity >> data[c].horsepower >> ws && getline(Carfile2, data[c].fuel) && Carfile2 >> data[c].price)
			{
				
				c++;
			}

			
			Carfile2.close();
			
			int prices[c];
	        for (int i = 0; i < c; i++) {
	            prices[i] = data[i].price;
	        }
	
	        // Apply Quick Sort algorithm to sort prices
	        q.QuickSort2(0, c - 1, prices);
	
	        // Reorder data array based on sorted prices
	        CarModel sortedData[100];
	        for (int i = 0; i < c; i++) 
			{
	            for (int j = 0; j < c; j++) 
				{
	                if (data[j].price == prices[i]) 
					{
	                    sortedData[i] = data[j];
	                    break;
	                }
	            }
	        }
	
	        // Update the original data array with sorted data
	        for (int i = 0; i < c; i++) 
			{
	            data[i] = sortedData[i];
	        }
	
	        // Display sorted data
	        for (int i = 0; i < c; i++) {
	            
	            cout << "Price/per day    | " << data[i].price << endl;
	            cout << "Car Model        | " << data[i].name << endl;
	            cout << "Car ID           | " << data[i].id << endl;
	            cout << "Car Brand        | " << data[i].brand << endl;
	            cout << "Car Colour       | " << data[i].colour << endl;
	            cout << "Car Body Type    | " << data[i].body_type << endl;
	            cout << "Car Segment      | " << data[i].segment << endl;
	            cout << "Car Capacity     | " << data[i].capacity << endl;
	            cout << "Car Horsepower   | " << data[i].horsepower << endl;
	            cout << "Car Fuel         | " << data[i].fuel << endl;
	            fflush(stdin);
	            cout << endl;
	        }
		    
	}
	else
		{
		    cout << "Invalid selection. Please try again." << endl;
		    system("pause");
        	menu();
		}
	}
	
	//Search Car ID
	void searchCar(char brand)
	{
		CarModel t[100];
		int i=0;
		
		ifstream Carfile1;
		
			if(seater==4 && brand =='A')
		    {
				Carfile1.open("Toyota4S.txt");
			}
			else if(seater==6 && brand =='A')
			{
				Carfile1.open("Toyota6S.txt");
			}
		    else if(seater==4 && brand =='B')
		    {
		    	Carfile1.open("Proton4S.txt");
			}
			else if(seater==6 && brand == 'B') 
			{
				Carfile1.open("Proton6S.txt");
			}
			else if(seater ==4 && brand == 'C')
			{
				Carfile1.open("BMW4S.txt");
			 } 
			else if(seater == 6 && brand =='C')
			{
				Carfile1.open("BMW6S.txt");
			}
			else 
			{
				cout<<"Error occur ! Invalid car type or car brand ."<<endl;
			}
		
		
		while (Carfile1 >> t[i].id >> ws && getline(Carfile1, t[i].brand) && getline(Carfile1, t[i].name) &&
           getline(Carfile1, t[i].colour) && getline(Carfile1, t[i].body_type) && getline(Carfile1, t[i].segment) &&
           Carfile1 >> t[i].capacity >> t[i].horsepower >> ws && getline(Carfile1, t[i].fuel) && Carfile1 >> t[i].price)
			{
				
				i++;
			}

			
		Carfile1.close();
		
		system("CLS");
		cout << "What is the Car ID you want to search ?" << endl;
		
		int table[200]; 
				int first,last,mid; 
				int found;
				int target;
				//Setting up the array
				for(i=0; i<10; i++)
				{
					table[i] = t[i].id;

				} 
				first =0; 
				last = 10-1; 
				found = 0;
				fflush(stdin);
				//Input the target
				cout<<"\nPlease Enter an ID to search : ";
				cin>>target;
				//The binary search 
				while( (found==0) && (first <= last) )
				{ 
					mid = (first + last) / 2;
					if( target == table[mid])
					{
						found = 1;
					}		
					else
					{
						if( target < table[mid] )
							last = mid - 1;
						else
							first = mid + 1;
						
					}
				}
				
				if(found)
				{
					 cout << "\nCar ID has been found." << endl;
					 cout << "Car ID		  : " << t[mid].id << endl;
			         cout << "Car Model	  : " << t[mid].name << endl;
			         cout << "Car Brand	  : " << t[mid].brand << endl;
	            	 cout << "Car Colour	  : " << t[mid].colour << endl;
	            	 cout << "Car Body Type     : " << t[mid].body_type << endl;
	            	 cout << "Car Segment       : " << t[mid].segment << endl;
	            	 cout << "Car Capacity      : " << t[mid].capacity << endl;
	            	 cout << "Car Horsepower    : " << t[mid].horsepower << endl;
	            	 cout << "Car Fuel          : " << t[mid].fuel << endl;
	            	 system("PAUSE");
	            	 system("CLS");
					 	
				}
				else
				{
					cout<<"\n\t\t\t\tThe ID that you have entered does not exist."<<endl;
					system("PAUSE");
	            	system("CLS");
	
				}
	}
	
	//Select option 
	int selectOpt()
	{
	    int choice;
	    Car c;
	    
	   
	    cout << "        *    CHOOSE AN OPTION    *          " << endl;
	    cout << "____________________________________________" << endl;
	    cout << "1. Sort car" << endl;
	    cout << "2. Search car" << endl;
	    cout << "3. Rent a car" << endl;
	    cout << "Please enter your selection [1/2/3]: ";
	    cin >> choice;
	    
	    return choice;
	}
};

class Proton : public Car
{
private:
    int modelId;
	string modelName, modelBrand, modelColour, modelBody_type, modelSegment, modelFuel;
    double modelCapacity, modelHorsepower, modelPrice;

public:
    Proton()
    {
        cout << " \t\t [ PROTON ] \t" << endl;
    }

    void loadModelsFromFile()
    {
        string empty;

        ifstream file;
        if (seater == 4)
        {
            file.open("Proton4S.txt");
        }
        else
        {
            file.open("Proton6S.txt");
        }

        if (!file)
        {
            cout << "Failed to open file." << endl;
            return;
        }

        while (file>> modelId)
        {
        	getline(file, empty);
            getline(file, modelName);
            getline(file, modelBrand);
            getline(file, modelColour);
            getline(file, modelBody_type);
            getline(file, modelSegment);
            file >> modelCapacity;
            getline(file, empty);
            file >> modelHorsepower;
            getline(file, empty);
            getline(file, modelFuel);
            file >> modelPrice;
            getline(file, empty);
            getline(file, empty);

            CarModel data;

            data.id = modelId;
            data.name = modelName;
            data.brand = modelBrand;
            data.colour = modelColour;
            data.body_type = modelBody_type;
            data.segment = modelSegment;
            data.capacity = modelCapacity;
            data.fuel = modelFuel;
            data.horsepower = modelHorsepower;
            data.price = modelPrice;

            modelList.insertToNode(data);
        }

        file.close();
    }

    void displayModel(char brand)
    {
    	int opt;
    	
        cout << "Proton Car Models:" << endl;
        modelList.displayModels();
        // add display sort n search
        opt = selectOpt();
        
        if(opt==1)
        {
        	sortCarPage(brand);
        	selectedId = selectModel();
        	rentCar();
		}
		else if(opt==2)
		{
			searchCar(brand);
			modelList.displayModels();
			selectedId = selectModel();
			rentCar();
		}
		else if(opt==3)
		{
			selectedId = selectModel();
			rentCar();
		}
		else
		{
			cout<<"Invalid option ! "<<endl;
			system("PAUSE");
			system("CLS");
			modelList.displayModels();
		}
    }

    
};

class Toyota : public Car
{
private:
    int modelId;
	string modelName, modelBrand, modelColour, modelBody_type, modelSegment, modelFuel;
    double modelCapacity, modelHorsepower, modelPrice;

public:
    Toyota()
    {
        cout << " \t\t [ Toyota ] \t" << endl;
    }

    void loadModelsFromFile()
    {
        string empty;

        ifstream file;
        if (seater == 4)
        {
            file.open("Toyota4S.txt");
        }
        else
        {
            file.open("Toyota6S.txt");
        }

        if (!file)
        {
            cout << "Failed to open file." << endl;
            return;
        }

        while (file>> modelId)
        {
        	getline(file, empty);
            getline(file, modelName);
            getline(file, modelBrand);
            getline(file, modelColour);
            getline(file, modelBody_type);
            getline(file, modelSegment);
            file >> modelCapacity;
            getline(file, empty);
            file >> modelHorsepower;
            getline(file, empty);
            getline(file, modelFuel);
            file >> modelPrice;
            getline(file, empty);
            getline(file, empty);

            CarModel data;

            data.id = modelId;
            data.name = modelName;
            data.brand = modelBrand;
            data.colour = modelColour;
            data.body_type = modelBody_type;
            data.segment = modelSegment;
            data.capacity = modelCapacity;
            data.fuel = modelFuel;
            data.horsepower = modelHorsepower;
            data.price = modelPrice;

            modelList.insertToNode(data);
        }

        file.close();
    }

    void displayModel(char brand)
    {
    	int opt;
        cout << "Toyota Car Models:" << endl;
        modelList.displayModels();
        // add display sort n search
        opt = selectOpt();
        
        if(opt==1)
        {
        	sortCarPage(brand);
        	selectedId = selectModel();
        	rentCar();
		}
		else if(opt==2)
		{
			searchCar(brand);
			modelList.displayModels();
			selectedId = selectModel();
			rentCar();
		}
		else if(opt==3)
		{
			selectedId = selectModel();
			rentCar();
		}
		else
		{
			cout<<"Invalid option ! "<<endl;
			system("PAUSE");
			system("CLS");
			modelList.displayModels();
		}
    }

    
};

class BMW : public Car
{
private:
    int modelId;
	string modelName, modelBrand, modelColour, modelBody_type, modelSegment, modelFuel;
    double modelCapacity, modelHorsepower, modelPrice;

public:
    BMW()
    {
        cout << " \t\t [ BMW ] \t" << endl;
    }

    void loadModelsFromFile()
    {
        string empty;

        ifstream file;
        if (seater == 4)
        {
            file.open("BMW4S.txt");
        }
        else
        {
            file.open("BMW6S.txt");
        }

        if (!file)
        {
            cout << "Failed to open file." << endl;
            return;
        }

        while (file>> modelId)
        {
        	getline(file, empty);
            getline(file, modelName);
            getline(file, modelBrand);
            getline(file, modelColour);
            getline(file, modelBody_type);
            getline(file, modelSegment);
            file >> modelCapacity;
            getline(file, empty);
            file >> modelHorsepower;
            getline(file, empty);
            getline(file, modelFuel);
            file >> modelPrice;
            getline(file, empty);
            getline(file, empty);

            CarModel data;

            data.id = modelId;
            data.name = modelName;
            data.brand = modelBrand;
            data.colour = modelColour;
            data.body_type = modelBody_type;
            data.segment = modelSegment;
            data.capacity = modelCapacity;
            data.fuel = modelFuel;
            data.horsepower = modelHorsepower;
            data.price = modelPrice;

            modelList.insertToNode(data);
        }

        file.close();
    }

    void displayModel(char brand)
    {
    	int opt;
        cout << "BMW Car Models:" << endl;
        modelList.displayModels();
        // add display sort n search
        opt = selectOpt();
        
        if(opt==1)
        {
        	sortCarPage(brand);
        	selectedId = selectModel();
        	rentCar();
		}
		else if(opt==2)
		{
			searchCar(brand);
			modelList.displayModels();
			selectedId = selectModel();
			rentCar();
		}
		else if(opt==3)
		{
			selectedId = selectModel();
			rentCar();
		}
		else
		{
			cout<<"Invalid option ! "<<endl;
			system("PAUSE");
			system("CLS");
			modelList.displayModels();
		}
    }

    
};

void Car::menu()
{
	system("CLS");
    cout << " ===========================================" << endl;
    cout << "             CHOOSE A CAR TYPE              " << endl;
    cout << " ===========================================" << endl;
    cout << " 1. 4-5 Seater" << endl;
    cout << " 2. 6 and more Seater" << endl;
    cout << " Please enter your choice [ 1 / 2 ] : ";
    cin >> type;

    fflush(stdin);
    cout << "\nLoading..";
    for (int i = 0; i < 2; i++)
    {
        sleep(1);
        cout << "..";
    }
    cout << "\n\n";
    system("CLS");

    switch (type)
    {
    case 1:
        seater = 4;
        break;
    case 2:
        seater = 6;
        break;

    default:
        cout << "Please enter a valid choice !" << endl;
        system("pause");
        menu();
    }

    selectBrand();
}

void Car::selectBrand()
{
	char brand2;
    cout << " ===========================================" << endl;
    cout << "             CHOOSE A CAR BRAND             " << endl;
    cout << " ===========================================" << endl;

    cout << " A. Toyota" << endl;
    cout << " B. Proton" << endl;
    cout << " C. BMW" << endl;
    cout << " Please enter your choice [ A / B / C ] : ";

    cin >> brand2;

    fflush(stdin);
    cout << "\nLoading..";
    for (int i = 0; i < 2; i++)
    {
        sleep(1);
        cout << "..";
    }
    cout << "\n\n";
    system("CLS");

    switch (brand2)
    {
    case 'A':
        // go to toyota
        {
        	brand='A';
        	Toyota toyota;
            toyota.seater = seater; 
            toyota.loadModelsFromFile();
            toyota.displayModel(brand);
			break;
		}
        
    case 'B':
        // goto proton
        {
        	brand='B';
        	Proton proton;
            proton.seater = seater; 
            proton.loadModelsFromFile();
            proton.displayModel(brand); 
			break;
		}
            
        
    case 'C':
        // goto bmw
        {
        	brand='c';
        	BMW bmw;
            bmw.seater = seater; 
            bmw.loadModelsFromFile();
            bmw.displayModel(brand);
			break;
		}
        	
        
    default:
        cout << "Please enter a valid choice !" << endl;
        system("pause");
        menu();
    }
}

int Car::selectModel()
{
	int id;
	
	cout<<"\nPlease enter the Car ID that you want to rent : ";
	cin>>id;
	
	return id;
}

int readUsersInfo(User users[])
{
    int size = 0;
    ifstream inFile("user.txt");  
    if (inFile)
    {
        while (size < MAX_USERS && inFile >> users[size].username >> users[size].password >> users[size].email >> users[size].icno >> users[size].secureCode) 
        {
            size++;
        }
        inFile.close();
    }
    return size;
}


void writeUsersInfo(const User users[], int size)
{
    ofstream outFile("user.txt"); 
    if (outFile)
    {
        for (int i = 0; i < size; i++)
        {
            outFile << users[i].username << " " << users[i].password << " " << users[i].email << " " << users[i].icno << " " << users[i].secureCode << endl;
        }
        outFile.close();
    }
}


void insertionSort(User users[], int size)
{
    int i, j;
    User temp;
    for (i = 1; i < size; i++)
    {
        temp = users[i];
        j = i - 1;
        while (j >= 0 && users[j].username > temp.username)
        {
            users[j + 1] = users[j];
            j--;
        }
        users[j + 1] = temp;
    }
}
    bool isValidICno(const string& icno) 
	{
        if (icno.length() != 12) {
            return false;
        }

        for (size_t i = 0; i < icno.length(); ++i) {
            if (!isdigit(icno[i])) {
                return false;
            }
        }

        return true;
    }
    
class ADTqueue 
{ 
private: 
	string info[5]; 
	int head,tail; 
public: 
	ADTqueue() 
	{ 
		tail = -1; 
		head = 0; 
	} 
	
	int empty() 
	{ 
		if(head == tail+1) 
			return 1; 
	
		else 
		return 0; 
	} 
	
	int full() 
	{ 
		if(tail == 4) 
		return 1; 
		else 
		return 0; 
	} 
	
	void append(string detail) 
	{ 
		if (!full()) 
		{ 
			tail++; 
			info[tail] = detail; 
		} 
		else 
		{ 
			cout<<"Queue is full! You entered extra information. Error occur. "<<endl; 
		} 
	} 
	
	string serve() 
	{ 
		string detail; 
		if(!empty()) 
		{ 
			detail = info[head]; 
			head++; 
		return detail; 
		} 
		else 
		{ 
			cout<<"Queue is Empty"<<endl; 
			return 0; 
		} 
	
	} 
}; 

class ADTstack
{
	private:
		card credit_debit[20];
		int topstack;
		
	public:
		ADTstack()
		{
			topstack = -1;
		}
		
		int empty()
		{
		if(topstack==-1)
			return 1;
		else
			return 0;
		}
	
		int full()
		{
		if(topstack==19)
			return 1;
		
		else
			return 0;
		}
	
		void push(string name,string num,string date,int cvv)
		{
			ofstream write("card.txt",ios::app);
			
			if (!full())
			{
				topstack++;
				credit_debit[topstack].holdername = name;
				credit_debit[topstack].cardnum = num;
				credit_debit[topstack].expdate = date;
				credit_debit[topstack].CVV = cvv; 
				
				write<<credit_debit[topstack].holdername<<endl;
				write<<credit_debit[topstack].cardnum <<endl;
				write<<credit_debit[topstack].expdate <<endl;
				write<<credit_debit[topstack].CVV <<endl;
				
				cout<<"Card Added Succesfully"<<endl;
			}
			else
			{
				cout<<"Stack is Full"<<endl;
			}
		}
	
		string pop()
		{
			string out;
		
			if(!empty())
			{	
				out = credit_debit[topstack].holdername;
				topstack--;
				return out;
			}
			else
			{
				cout<<"Stack is Empty"<<endl;
				return 0;
			}
		}
		
		void display()
		{
			cout<<"Existing Card \n";
			for(int i=0;i<20;i++)
			{
				cout<<credit_debit[topstack].holdername<<endl;
				cout<<credit_debit[topstack].cardnum<<endl;
				cout<<credit_debit[topstack].expdate<<endl;
				cout<<credit_debit[topstack].CVV<<endl;
			}
		}
};

class Customer {
private:
    User users[MAX_USERS];
    int size;
    bool cus_access;
 	string username, password;
public:
    Customer() 
	{
        size = 0;
        cus_access = false;
    }
    
    string getName()
    {
    	return username;
	}
	
   void cust_Login()
{
    system("CLS");
    cout << "\t\t\t---------------------------------------------\n\n";
    cout << "\t\t\t            CUSTOMER LOGIN PAGE              \n\n";
    cout << "\t\t\t---------------------------------------------\n\n";
    cout << "\t\tPlease enter your username: ";
    cin >> username;
    cout << "\n\t\tPlease enter your password: ";
    cin >> password;

    int size = 0;
    User users[MAX_USERS];
    size = readUsersInfo(users);
    
    insertionSort(users, size);

    string usernames[MAX_USERS];
    for (int i = 0; i < size; i++) {
        usernames[i] = users[i].username;
    }

    BinarySearch(username, password, 0, size - 1, usernames, users, size);
}


void cust_Registration()
{
    string username, password, email, icno, secureCode;
    cout << "\t\t\t---------------------------------------------\n\n";
    cout << "\t\t\t           CUSTOMER REGISTRATION PAGE         \n\n";
    cout << "\t\t\t---------------------------------------------\n\n";
    cout << "\t\tPlease enter your username: ";
    cin >> username;
    cout << "\n\t\tPlease enter your password: ";
    cin >> password;
    cout << "\n\t\tPlease enter your email: ";
    cin >> email;
    cout << "\n\t\t***Your IC number should have 12 digits***" << endl;

    bool validIC = false;
    do
    {
        cout << "\n\t\tPlease enter your IC number: ";
        cin >> icno;
        if (isValidICno(icno))
        {
            validIC = true;
        }
        else
        {
            cout << "\n\t\tInvalid IC number format! Please try again.\n" << endl;
        }
    } while (!validIC);

    cout << "\n\t\t***This is for password recovery to help you get back your account, in case you forget your password***" << endl;
    cout << "\n\t\tPlease enter your secure code: ";
    cin >> secureCode;

    int size;
    User users[MAX_USERS];
    size = readUsersInfo(users);

    for (int i = 0; i < size; i++)
    {
        if (users[i].username == username)
        {
            cout << "\n\t\tUsername already exists. Please choose a different username.\n" << endl;
            cout << "\t\tPlease enter your username: ";
            cin >> username;
            return;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (users[i].secureCode == secureCode)
        {
            cout << "\n\t\tSecure code already taken. Please choose a different secure code.\n" << endl;
            cout << "\n\t\tPlease enter your secure code: ";
            cin >> secureCode;
            return;
        }
    }

    users[size].username = username;
    users[size].password = password;
    users[size].email = email;
    users[size].icno = icno;
    users[size].secureCode = secureCode;
    size++;

    writeUsersInfo(users, size);

    cout << "\n\t\tRegistration successful! You can now login with your username and password.\n" << endl;
    system("PAUSE");
    system("CLS");
    user_page();
}


	void PasswordRecovery()
	{
	    string username, email, secureCode;
	    cout << "\t\t\t---------------------------------------------\n\n";
	    cout << "\t\t\t           PASSWORD RECOVERY PAGE            \n\n";
	    cout << "\t\t\t---------------------------------------------\n\n";
	    cout << "\t\tPlease enter your username: ";
	    cin >> username;
	    cout << "\n\t\tPlease enter your email: ";
	    cin >> email;
	    cout << "\n\t\tPlease enter your Secure Code: ";
	    cin >> secureCode;
	
	    int size;
	    User users[MAX_USERS];
	    size = readUsersInfo(users);
	
	    insertionSort(users, size);
	
	    string* usernames = new string[size];
	    for (int i = 0; i < size; i++) {
	        usernames[i] = users[i].username;
	    }
	
	    int foundIndex = -1;
	    int first = 0;
	    int last = size - 1;
	    while (first <= last) {
	        int mid = (first + last) / 2;
	        if (usernames[mid] == username) {
	            foundIndex = mid;
	            break;
	        }
	        else if (usernames[mid] < username) {
	            first = mid + 1;
	        }
	        else {
	            last = mid - 1;
	        }
	    }
	
	    if (foundIndex != -1 && users[foundIndex].username == username && users[foundIndex].email == email && users[foundIndex].secureCode == secureCode) 
		{
	        cout << "\n\t\tYour password is: " << users[foundIndex].password << endl;
	        system("pause");
	        user_page();
	    }
	    else 
		{
	        cout << "\n\t\tInvalid username,email, or secureCode. Please try again.\n" << endl;
	        PasswordRecovery();
	    }
	
	    delete[] usernames;
	
	    system("pause");
}


void BinarySearch(const string& username, const string& password, int first, int last, const string* usernames, const User* users, int size)
{
    if (first > last)
    {
        cout << "\n\t\tInvalid username or password! Please try again.\n";
        system("PAUSE");
        cust_Login();
        return;
    }

    int mid = (first + last) / 2;
    if (usernames[mid] == username)
    {
        if (users[mid].password == password)
        {
            cout << "\n\t\tLogin Successful!\n";
            cus_access = true;
            system("PAUSE");
            system("CLS");
        }
        else
        {
            cout << "\n\t\tInvalid username or password! Please try again.\n";
            system("PAUSE");
            cust_Login();
        }
    }
    else if (usernames[mid] < username)
    {
        BinarySearch(username, password, mid + 1, last, usernames, users, size);
    }
    else
    {
        BinarySearch(username, password, first, mid - 1, usernames, users, size);
    }
    
    if (cus_access)
    {
        cout << "Directing you to the user menu page..." << endl;
        fflush(stdin);
        cout << "\nLoading..";
        for (int i = 0; i < 2; i++)
        {
            sleep(1);
            cout << "..";
        }
        cout << "\n\n";
        system("CLS");
        user_menu();
    }
}

		void user_menu()
		{
			int menuo;
			system("CLS");
			cout<<" [WheelsOnRent] - Your best platform to rent an ideal car "<<endl;
			cout<<"Welcome , "<<username<<endl; 
			cout<<" ___________________________________________________________ "<<endl;
			cout<<endl;
			cout<<"                         CUSTOMER MENU                       "<<endl;
			cout<<" ___________________________________________________________ "<<endl;
			cout<<" 1. Rent A Car"<<endl;
			cout<<" 2. Edit Account Details"<<endl;
			cout<<" 3. Add a card"<<endl;
			cout<<" 4. Logout"<<endl;
			cout<<" Please enter your choice [ 1 / 2 / 3 / 4 ] : ";
			cin>>menuo;
			cin.ignore();
			switch(menuo)
			{
				case 1:
					{
						Car *cus = new Car;
						cus->menu();
						delete cus;
						break;
					}
					
				case 2:
					editAcc();
					break;
				
				case 3:
					add_card();
					break;	
					
				case 4:
					cus_access=false;
					cout << "\nLoading..";
				    for (int i = 0; i < 2; i++)
				    {
				        sleep(1);
				        cout << "..";
				    }
				    cout << "\n\n";
					system("CLS");
					cout<<"Logout successfully ! Thank you. "<<endl;
					cout<<"Please visit us again."<<endl;
					exit(1);
					break;
					
				default:
					cout<<"Invalid choice ! Please choose again. "<<endl;
					user_menu();
			}
		}
		
		
	void add_card()
	{
	string holder_name,exp_date,card_num;
	int CVV;
	ADTstack st;
	
	system("cls");
	cout << " ===========================================" << endl;
    cout << "                 Add new card               " << endl;
    cout << " ===========================================" << endl;

	cout << " Enter Your Card Details" << endl;
	
    cout << " Enter Holdername:" ;
    fflush(stdin);
    getline(cin,holder_name);
    
	cout << " Enter Card number: ";
	fflush(stdin);
    getline(cin,card_num);
	
    cout << " Enter Expiry date:";
    fflush(stdin);
    getline(cin,exp_date);
    
    cout << " Enter CVV: " ;
    cin>>CVV;
    
    st.push(holder_name,card_num,exp_date,CVV);
	user_menu();
	
	}	
	
	void editAcc()
{
    cout << username;
    system("CLS");

    ifstream readuser("user.txt");

    if (!readuser.is_open())
    {
        cout << "Failed to open user file." << endl;
    }
    else
    {
        string data;
        string pw, email, ic, secure;
        string f1;
        while (getline(readuser, data))
        {
            istringstream iss(data);

            string usernameee;
            string details;
            if (iss >> usernameee && usernameee == username) // Found the matching username
            {
                string newname, newpw, newemail, newsecure;
                cout << "Your current account details : " << endl;
                cout << "Name       : " << username << endl;

                while (iss >> pw >> email >> ic >> secure)
                {
                    f1 = pw;
                    int length = f1.size(); //detect the length of password string
                    cout << "Password    : " << f1.at(0);
                    for (int j = 2; j < length; j++) //count the number of "*" to display according to
                    {                                //length of password excluding first and last character
                        cout << "*";
                    }
                    cout << f1.at(length - 1) << endl; //display the last character of password
                    cout << "Email       : " << email << endl;
                    cout << "IC No       : " << ic << endl;
                }

                fflush(stdin);
                cout << "Enter your new username : ";
                getline(cin, newname);
                cout << "Enter your new password : ";
                getline(cin, newpw);
                cout << "Enter your new email : ";
                getline(cin, newemail);
                cout << "Enter your new secure code : ";
                getline(cin, newsecure);

                ADTqueue c;
                c.append(newname);
                c.append(newpw);
                c.append(newemail);
                c.append(ic); //ic cannot be changed, so just insert the old one
                c.append(newsecure);

                readuser.close(); // Close the file before renaming

                ofstream writeuser("newuser.txt", std::ios_base::app);

                if (!writeuser.is_open())
                {
                    cout << "Failed to open user file for writing." << endl;
                }
                else
                {
                    ifstream readuser2("user.txt");

                    if (!readuser2.is_open())
                    {
                        cout << "Failed to open user file." << endl;
                    }
                    else
                    {
                        string data2;
                        string pw2, email2, ic2, secure2;

                        while (getline(readuser2, data2))
                        {
                            istringstream iss(data2);

                            string usernameee2;
                            string details;
                            
                            if (iss >> usernameee2 && usernameee2 == username)
                            {
                                // Write each element in the queue to the file
                                while (!c.empty())
                                {
                                    string newdata = c.serve();
                                    writeuser << newdata << " "; // Write the data to the file
                                }
                                writeuser << endl;
                            }
                            else
                            {
                            	writeuser << data2 << " ";
                                writeuser << endl;
							}              
                            
                        }
                    }
                    
                    writeuser.close();   
                    readuser2.close();   

                    int dltold = remove("user.txt");
                    if (dltold == 0)
                    {
                        int okma = rename("newuser.txt", "user.txt");
                        cout << "\nLoading..";
                        for (int i = 0; i < 2; i++)
                        {
                            sleep(1);
                            cout << "..";
                        }
                        cout << "\n\n";
                        system("CLS");

                        if (okma == 0)
                        {
                            cout << "Edit successful! Your details have been updated." << endl;
                            username = newname;
                            system("PAUSE");
                            user_menu();
                        }
                        else
                        {
                            cout << "Error occurred. Details were not updated." << endl;
                            remove("newuser.txt");
                            system("PAUSE");
                            user_menu();
                        }
                    }
                    else
                    {
                        cout << "Error occurred. Cannot remove old data." << endl;
                    }
                }
            }
        }
        
    }
}

	
};

void Car::rentCar()
{
        ofstream rent("rent.txt", ios::app);

        if (rent.is_open())
        {
            CarLinkedList::node* selectedNode = modelList.findID(selectedId);

            if (selectedNode != NULL)
            {
            	ifstream check("rent.txt", ios::in);
            	if (check.is_open()) 
				{
				    string line;
				    bool booked = false;
				    stringstream ss;
				    ss << selectedNode->data.id;
					string idString = ss.str();

				    while (getline(check, line)) 
					{
				        if (line == idString)
				        {
				        	cout<<"Sorry, this car is already rented. Please select another car."<<endl;
				        	system("PAUSE");
				        	booked=true;
				        	menu(); 
						}
				    }
				    
				    if(!booked)
				    {
				    	rent << selectedNode->data.id << endl; // Append the ID to the file
				    	system("CLS");
				    	cout<<"How many days do you want to rent ? ";
				    	cin>>days;
				    	rentalfee=selectedNode->data.price*days;
						cout<<"Car found successful. Directing to payment page..."<<endl;
						cout<<"\nLoading..";
					    for(int i=0;i<2;i++)
					    {
					        sleep(1);
					    	cout<<"..";
						}
						cout<<"\n\n";
						Customer customer;
						string nameee = customer.getName();
						create_invoice(nameee);
						
					}
					check.close();
				} 
				else 
				{
				    cout << "Failed to open file." << endl;
				}
				 
               
            }
            else
            {
            	while(selectedNode == NULL)
            	{
            		cout << " Invalid car ID. Please enter again." << endl;
                    selectedId = selectModel();
					rentCar();
				}
		    }
        }
        else
        {
            cout << "Error in opening file" << endl;
        }
}

void user_page()
{
    int sel;
    system("CLS");
     	cout << "\t\t\t---------------------------------------------\n\n";
        cout << "\t\t\t         Welcome to the Customer Main Page    \n\n";
        cout << "\t\t\t--------------      MENU       --------------\n\n";
        cout << "                                                    \n\n";
        cout << "\t\t\t|    Press 1 to LOGIN                      |" << endl;
        cout << "\t\t\t|    Press 2 to REGISTER                   |" << endl;
        cout << "\t\t\t|    Press 3 if you forgot your PASSWORD   |" << endl;
        cout << "\t\t\t Please enter your choice :    ";
    	cin >> sel;
	Customer *user = new Customer;
    switch (sel)
    {
	    case 1:
	    {
	    	
	        user->cust_Login();
	        delete user;
	        break;
	    }
	    case 2:
        	system("cls");
            user->cust_Registration();
            break;

        case 3:
        	system("cls");
            user->PasswordRecovery();
            break;

    default:
        cout << "Please enter a valid choice!" << endl;
        system("pause");
        user_page();
    }
    
    delete user;
}

void Car:: payment()
	{
	string holder_name,exp_date,card_num,empty;
	int CVV,first=0,last=9,mid,found=0,success=0;
	
	system("cls");
	cout << " =============================================" << endl;
    cout << "                Pay with credit card          " << endl;
    cout << " =============================================" << endl;


	do{
	cout << " \nEnter Your Card Details" << endl;
	
    cout << " Enter Holdername:" ;
    fflush(stdin);
    getline(cin,holder_name);
    
	cout << " Enter Card number: ";
	getline(cin,card_num);
	
    cout << " Enter Expiry date:";
    fflush(stdin);
    getline(cin,exp_date);
    
    cout << " Enter CVV: " ;
    cin>>CVV;
    
    card credit_debit[10];
	fstream read;
	read.open("card.txt");
	
	if (!read)
    {
        cout << "No card exists. Please add a card to pay. " << endl;
        system("PAUSE");
        system("CLS");
        Customer* jt= new Customer;
        jt->add_card();
        delete jt;
       
    }
    else
	{
		int i=0;
		while (getline(read,credit_debit[i].holdername))  
    	{
			getline(read,credit_debit[i].cardnum);
			getline(read,credit_debit[i].expdate);
			read>>credit_debit[i].CVV;
			
			getline(read,empty);
			
    		if(holder_name==credit_debit[i].holdername && card_num==credit_debit[i].cardnum && exp_date==credit_debit[i].expdate && CVV== credit_debit[i].CVV)
    		{
    			cout<<" Payment Successfull !!"<<endl;
    			cout<<" Thank you. Please come again"<<endl;
    			success=1;
    			exit(1);
			}
			{
				success=0;
			}
			i++;
    	}
		
		if(success!=1)
		{
			cout<<" Invalid credit card ! "<<endl;
		}	
		
	}
	}while(success!=1);
}


class admin :public Car 
{ 	
	private: 
	int id,opt;
	string password, filepath;
	CarModel car;
	char brandc,typec;
	
	bool access;
	
	public:
		
		admin()
		{
			access=false;
		}
		
		void login()
		{
			fflush(stdin);
			cout<<"Enter admin ID :";
			cin>>id;
			fflush(stdin);
		
			cout<<"Enter admin password:";
			getline(cin,password);
			
			ifstream ad;
			int id2;
			string password2;
			
            ad.open("admin.txt");
			if(ad)
			{
				while(!ad.eof())
				{
					ad>>id2>>password2;
					if(id==id2 && password == password2)
					{
						cout<<"\nLogin Successful ! "<<endl;
						access=true;
						admin_menu();
					}
				}
				if(!access)
				{
					cout<<"Login failed"<<endl;
					system("PAUSE");
					system("CLS");
					login();
				}
				
			}
			else
			{
				cout<<"Error opening admin file"<<endl;
			}
			
		}
		
		void admin_menu()
		{
			if(!access)
			{
				login();
			}
		
				int opt;
				
				system("CLS");
				cout<<"===================================="<<endl;
				cout<<"           ADMIN       MODE         "<<endl;
				cout<<"===================================="<<endl;
				cout<<" 1. View Customer"<<endl;
				cout<<" 2. View Invoice"<<endl;
				cout<<" 3. Search Invoice"<<endl;
				cout<<" 4. Add Car"<<endl;
				cout<<" 5. Edit Car"<<endl;
				cout<<" 6. Delete Car"<<endl;
				cout<<" 7. Process Returned Car"<<endl;
				cout<<" 8. Log out"<<endl;
				cout<<"Please enter you choice [ 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 ] : ";
				cin>>opt;
			
			switch(opt)
			{
				case 1:
					viewCustomerInfo();
					break;
					
				case 2:
					view_invoice();
					break;
					
				case 3:
					search_invoice();
					break;
					
				case 4:
					addCar();
					break;
					
				case 5:
					editCar();
					break;
					
				case 6: 
					deleteCar();
				    break;
				    
				case 7: 
					returnCar();
				    break;
				
				case 8:
					access=false;
					system("CLS");
					cout<<" Log out successful"<<endl;
					system("PAUSE");
					exit(1);
					break;
				    
				default:
					cout<<"Invalid option ! Please select again. "<<endl;
					system("PAUSE");
					admin_menu();
			}
		}
		
		void addCar()
		{
			system("CLS"); 
			CarLinkedList* addcar = new CarLinkedList;
			
			cout<<"Which brand of car do you want to add?"<<endl;
			cout<<" [ T : Toyota |  P : Proton |  B : BMW ] ";
			cin>>brandc;
			cout<<"Which type does the car belong ?"<<endl;
			cout<<" [ A : 4 - 5 seaters |  B : 6 and more seater ] "; 
			cin>>typec;
			
			
			if(brandc=='T'&&typec=='A')
			{
				filepath="Toyota4S.txt";
			}
			else if(brandc=='T'&&typec=='B')
			{
				filepath="Toyota6S.txt";
			}
			else if(brandc=='P'&&typec=='A')
			{
				filepath="Proton4S.txt";
			}
			else if(brandc=='P'&&typec=='B')
			{
				filepath="Proton6S.txt";
			}
			else if(brandc=='B'&&typec=='A')
			{
				filepath="BMW4S.txt";
			}
			else if(brandc=='B'&&typec=='B')
			{
				filepath="BMW6S.txt";
			}
			else
			{
				cout<<"Invalid car type ! "<<endl;
				addCar();
			}
			
				cout<<"Enter car ID : ";
				cin>>car.id;
				cin.ignore();
				cout<<"\nEnter car name : ";
				getline(cin,car.name);
				fflush(stdin);
				cout<<"\nEnter car brand : ";
				getline(cin,car.brand);
				fflush(stdin);
				cout<<"\nEnter car colour : ";
				getline(cin,car.colour);
				fflush(stdin);
				cout<<"\nEnter car body type : ";
				getline(cin,car.body_type);
				cout<<"\nEnter car segment : ";
				getline(cin,car.segment);
				fflush(stdin);
				cout<<"\nEnter car fuel : ";
				getline(cin,car.fuel);
				cout<<"\nEnter car capacity (L): ";
				cin>>car.capacity;
				cout<<"\nEnter car horsepower (PS) : ";
				cin>>car.horsepower;
				cout<<"\nEnter car price (per day) : ";
				cin>>car.price;
				addcar->insertToNode(car);
    			addcar->saveToFile(filepath.c_str());
    			delete addcar;
    			admin_menu();
		}
		
	void editCar()
		{
			int first,last,mid,i,found;
			int target;
			string brand;
			
			int numCars = 0;//number of cars
    		string nothing;
    		
    		bool successful=false;
    		
			CarLinkedList* editcar = new CarLinkedList;
			system("CLS");
			cout<<"Which brand of car do you want to edit?"<<endl;
			cout<<" [ T : Toyota |  P : Proton |  B : BMW ] ";
			cin>>brandc;
			cout<<"Which type does the car belong ?"<<endl;
			cout<<" [ A : 4 - 5 seaters |  B : 6 and more seater ] "; 
			cin>>typec;
			fflush(stdin);
			cout<<" Enter the car ID of the car : "; 
			cin>>target;
			cin.ignore();
			
			if(brandc=='T'&&typec=='A')
			{
				filepath="Toyota4S.txt";
				brand="Toyota";
			}
			else if(brandc=='T'&&typec=='B')
			{
				filepath="Toyota6S.txt";
				brand="Toyota";
			}
			else if(brandc=='P'&&typec=='A')
			{
				filepath="Proton4S.txt";
				brand="Proton";
			}
			else if(brandc=='P'&&typec=='B')
			{
				filepath="Proton6S.txt";
				brand="Proton";
			}
			else if(brandc=='B'&&typec=='A')
			{
				filepath="BMW4S.txt";
				brand="BMW";
			}
			else if(brandc=='B'&&typec=='B')
			{
				filepath="BMW6S.txt";
				brand="BMW";
			}
			else
			{
				cout<<"Invalid car type ! "<<endl;
				editCar();
			}
			
			ifstream check(filepath.c_str(), ios::in);
			
			if (!check) 
		{
        		cout << "Error opening file" << endl;
		}

   
	    while (getline(check, nothing)) 
		{
	        numCars++;
	    }
	
	    check.close();
	
	  CarModel* cars = new CarModel[numCars];
	
	
	   ifstream check2(filepath.c_str(), ios::in);
	   
		   for (int i = 0; i < numCars; i++) 
		{
		    check2 >> cars[i].id;
		    getline(check2, nothing); 
		    getline(check2, cars[i].name);
		    getline(check2, cars[i].brand);
		    getline(check2, cars[i].colour);
		    getline(check2, cars[i].body_type);
		    getline(check2, cars[i].segment);
		    check2 >> cars[i].capacity;
		    getline(check2, nothing);
		    check2 >> cars[i].horsepower;
		    getline(check2, nothing);
		    getline(check2, cars[i].fuel);
		    check2 >> cars[i].price;
		    getline(check2, nothing);
		    getline(check2, nothing);
		}
	
	    check2.close();
	    
		// Sorting car id using selection sort
	for (int i = 0; i < numCars - 1; i++) 
	{
	    int min = i;
	    
	    for (int j = i + 1; j < numCars; j++) 
	    {
	        if (cars[j].id < cars[min].id)
	        {
	            min = j;
	        }
	    }
	    
	    if (cars[min].id < cars[i].id)
	    {
	        CarModel temp = cars[i];
	        cars[i] = cars[min];
	        cars[min] = temp;
	    }
	}
	    // Binary search to find the car user want to edit
		first = 0;
		last = numCars - 1;
		found = 0;
		
		while (first <= last) 
		{
		    int mid = (first + last) / 2;
		
		    if (cars[mid].id == target) 
			{
		        found = 1;
		        break;
		        
		    } else if (cars[mid].id < target) 
			{
		        first = mid + 1;
		    } else 
			{
		        last = mid - 1;
		    }
		}
		
		if (found == 1) 
		{
		    cout << "Car found ! " << endl;
		    system("PAUSE");
		    successful=editcar->editCar(target,filepath,brand);//call editCar in linkedlist to set the node
		   
		    	if(successful)
			    {
			    	 renameFile();
			    	 cout<<"Car data updated successfully!!!"<<endl;
				    system("PAUSE");
				    system("CLS");
				}
				else
				{
					cout<<"The car data is not saved"<<endl;
					system("PAUSE");
				    system("CLS");
				   
				}
			     admin_menu();
		} 
		else
		{
		    cout << "Car not found! Please enter again." << endl;
		    system("PAUSE");
		    system("CLS");
		    editCar();
		}

    delete[] cars;	
    delete editcar;
			
	}	
	
	void deleteCar()
	{
		int target;
		bool successful;
		CarLinkedList* dltcar = new CarLinkedList;
			system("CLS");
			cout<<"Which brand of car do you want to delete?"<<endl;
			cout<<" [ T : Toyota |  P : Proton |  B : BMW ] ";
			cin>>brandc;
			cout<<"Which type does the car belong ?"<<endl;
			cout<<" [ A : 4 - 5 seaters |  B : 6 and more seater ] "; 
			cin>>typec;
			fflush(stdin);
			cout<<" Enter the car ID of the car : "; 
			cin>>target;
			cin.ignore();
			
			if(brandc=='T'&&typec=='A')
			{
				filepath="Toyota4S.txt";
			}
			else if(brandc=='T'&&typec=='B')
			{
				filepath="Toyota6S.txt";
			}
			else if(brandc=='P'&&typec=='A')
			{
				filepath="Proton4S.txt";
			}
			else if(brandc=='P'&&typec=='B')
			{
				filepath="Proton6S.txt";
			}
			else if(brandc=='B'&&typec=='A')
			{
				filepath="BMW4S.txt";
			}
			else if(brandc=='B'&&typec=='B')
			{
				filepath="BMW6S.txt";
			}
			else
			{
				cout<<"Invalid car type ! "<<endl;
				deleteCar();
			}
			
			successful = dltcar->deleteCar(filepath.c_str(),target);//call deletecar in linkedlist to set the node
			
			
	    	if(successful)
		    {
		    	renameFile();
		    	 cout<<"Car data deleted successfully!!!"<<endl;
			    system("PAUSE");
			    system("CLS");
			}
			else
			{
				cout<<"The car data is not deleted"<<endl;
				system("PAUSE");
			    system("CLS");
			   
			}
		     admin_menu();
			
	}
	
	void renameFile()
	{
		if (filepath == "Toyota4S.txt") 
			{
	        remove("Toyota4S.txt");
			rename("temporary.txt", "Toyota4S.txt");
	        } 
			else if (filepath == "Toyota6S.txt") 
			{
		        remove("Toyota6S.txt");
		        rename("temporary.txt", "Toyota6S.txt");
		           
		    } else if (filepath == "Proton4S.txt") 
			{
		        remove("Proton4S.txt");
		        rename("temporary.txt", "Proton4S.txt");
		           
		    } else if (filepath == "Proton6S.txt") 
			{
		        remove("Proton6S.txt");
		        rename("temporary.txt", "Proton6S.txt");
		            
		    } else if (filepath == "BMW4S.txt") 
			{
		        remove("BMW4S.txt");
		        rename("temporary.txt", "BMW4S.txt");
		            
		    } else if (filepath == "BMW6S.txt") 
			{
		        remove("BMW6S.txt");
		        rename("temporary.txt", "BMW6S.txt");
		          
		    } 
			else 
			{
		        cout << "Invalid file" << endl;
		    }
		    
	}

void returnCar()
{
    int num = 0, returnid;
    string line;
    int i, j, current;
    bool valid = false, done;
    
    ifstream rt("rent.txt", ios::in);
    
    if (rt)
    {
        while (getline(rt, line))
        {
            num++;
        }
    }
    else
    {
        cout << "No car rented." << endl;
        system("PAUSE");
        admin_menu();
    }
    
    rt.close();
    
    int* rtcars = new int[num];
    
    ifstream rt2("rent.txt", ios::in);
    
    for (int i = 0; i < num; i++)
    {
        rt2 >> rtcars[i];
        getline(rt2, line);
    }
    
    rt2.close();
    
    for (i = 1; i < num; i++) // sort rented car id using insertion sort
    {
        current = rtcars[i];
        j = i;
        while (j > 0 && current < rtcars[j - 1])
        {
            rtcars[j] = rtcars[j - 1];
            j--;
        }
        rtcars[j] = current;
    }
    
    system("CLS");
    
    if (num != 0)
    {
        cout << "Car ID rented by customers :" << endl;
        for (i = 0; i < num; i++)
        {
            cout << rtcars[i] << endl;
        }
        
        cout << "\nEnter the ID of the car you want to return: " << endl;
        cin >> returnid;
        
        for (int x = 0; x < num; x++) // sequential search to confirm the correct id return
        {
            if (rtcars[x] == returnid)
            {
                valid = true;
                break; // Exit the loop since a match is found
            }
        }
    }
    else
    {
        cout << "No records of rented cars." << endl;
        system("PAUSE");
    }
    
    if (valid)
    {
        ofstream newww("rent2.txt", ios::out); // new rent file to rewrite data
        
        if (newww)
        {
            cout << "\nUpdating file..." << endl;
            
            int k = 0;
            
            while (k < num)
            {
                if (rtcars[k] == returnid)
                {
                    rtcars[k] = rtcars[k + 1];
                    num--; // Decrement the value of num after deleting a data entry
                }
                newww << rtcars[k] << endl;
                k++;
            }
            
            newww.close(); // Close the file after writing
            
            remove("rent.txt"); // Remove the original file
            
            int o = rename("rent2.txt", "rent.txt");
            
            cout << "\nLoading..";
            for (int i = 0; i < 2; i++)
            {
                sleep(1);
                cout << "..";
            }
            cout << "\n\n";
            system("CLS");
            
            if (o == 0)
            {
                cout << "Car returned successfully. Thank you." << endl;
                system("PAUSE");
                admin_menu();
            }
            else
            {
                cout << "Rename failed." << endl;
                remove("rent2.txt");
            }
        }
        else
        {
            cout << "Error occurred. Could not write new file." << endl;
        }
    }
    else
    {
        remove("rent2.txt");
        cout << "\nLoading..";
        for (int i = 0; i < 2; i++)
        {
            sleep(1);
            cout << "..";
        }
        cout << "\n\n";
        system("CLS");
        cout << "Car did not return successfully." << endl;
        system("PAUSE");
        admin_menu();
    }
    
    delete[] rtcars;
}

	void viewCustomerInfo()
	{
	    int size,opts;
	    User users[MAX_USERS];
	    size = readUsersInfo(users);
		int i=1;
		string none, f1;
		const int nameWidth = 25;
		
		system("CLS");
	
	    cout<<"\n-----------------------------------------------------------------------------------Customer Information-----------------------------------------------------------------------------------"<<endl;  
	
	    for (int i = 0; i < size; i++)
	    {
                f1=users[i].password; //copy password string into another name
                int length = f1.size(); //detect the length of password string
                cout<<i+1<<" . Customer Name : "<<left<<setw(nameWidth)<<users[i].username;
                cout<<"| Customer Email : "<<left<<setw(nameWidth)<<users[i].email;
                 cout<<"| Customer IC No : "<<left<<setw(nameWidth)<<users[i].icno;
                cout<<"| Customer Password : ";
                for(int j=0;j<length;j++)//count the number of "*" to display according to 
                {                    //length of password excluding first and last character
                    cout<<"*";
                }
                cout << endl;
	    }
	   cout<<"\n\n"<<endl;
	    cout<<" 1. Sort customers information"<<endl;
	    cout<<" 2. Return to menu"<<endl;
	    cout<<"Please enter your selections [1/2] : ";
	    cin>>opts;
	    
	    switch(opts)
	    {
	    	case 1:
	    		sortCustomerInfo();
	    		displaySortedCustomerInfo();
	    		admin_menu();
	    		break;
	    	case 2:
	    		admin_menu();
			break; 
			default:
				cout<<"Invalid choice !"<<endl;
				viewCustomerInfo();
		}
	    
	}

	void sortCustomerInfo()
	{
		 cout << "\nLoading..";
	    for (int i = 0; i < 2; i++)
	    {
	        sleep(1);
	        cout << "..";
	    }
	    cout << "\n\n";
		system("CLS");
	    int size;
	    User users[MAX_USERS];
	    size = readUsersInfo(users);
	
	    insertionSort(users, size);
	
	    writeUsersInfo(users, size);
	
	    cout << "\n\t\tCustomer information sorted successfully.\n" << endl;
	    system("pause");
	}

	void displaySortedCustomerInfo()
	{
	    system("CLS");
	    ifstream inFile("user.txt");
	    string line;
	    string username, password, email, icno;
	    int i=1;
	    const int nameWidth = 20;
	    
	    if (inFile)
	    {
	        cout << "\t\t\t---------------------------------------------\n\n";
	        cout << "\t\t\t     SORTED CUSTOMER INFORMATION           \n\n";
	        cout << "\t\t\t---------------------------------------------\n\n";
	
	       while (getline(inFile, line))
	        {
	        	stringstream ss(line); // Use stringstream to split the line into columns
	        	ss >> username >> password >> email >> icno;
                // Display the information with asterisks (*) for the password
	            int length = password.size();
                cout<<i<<" . Customer Name : "<<left<<setw(nameWidth)<<username;
                cout<<"| Customer Email : "<<left<<setw(nameWidth)<<email;
                 cout<<"| Customer IC No : "<<left<<setw(nameWidth)<<icno;
                cout<<"| Customer Password : ";
                for(int j=0;j<length;j++)//count the number of "*" to display according to 
                {                    //length of password excluding first and last character
                    cout<<"*";
                }
                 cout << endl;
                 i++;
	        }
	        system("pause");
	        admin_menu();
	    }
	    else
	    {
	        cout << "Error opening file." << endl;
	    }
	}
	
	void view_invoice()
	{
		invoice in[50];
		int i=0,j=1;
		string empty;
		ifstream readinvoice("invoice.txt");
		//readinvoice.open("invoice.txt");
		
		if(readinvoice)
		{
			system("cls");
			cout << "\t\t ===========================================" << endl;
    		cout << "\t\t             All current Invoice            " << endl;
    		cout << "\t\t ===========================================" << endl<<endl;
    		
			while(readinvoice>>in[i].invoice_no)
			{
				getline(readinvoice, empty);
				getline(readinvoice,in[i].cust_name);
				getline(readinvoice,in[i].cust_phone);
				readinvoice>>in[i].car_ID;
				getline(readinvoice, empty);
				getline(readinvoice,in[i].car_model);
				getline(readinvoice,in[i].car_colour);
				readinvoice>>in[i].car_price;
				getline(readinvoice, empty);
				readinvoice>>in[i].days;
				getline(readinvoice, empty);
				readinvoice>>in[i].caution;
				getline(readinvoice, empty);
				readinvoice>>in[i].advance;
				getline(readinvoice, empty);
				readinvoice>>in[i].rental_amount;
				getline(readinvoice, empty);
				
				cout<<"\n\t\t  Revcord "<<j<<"============================================================="<<endl; 
				cout<<"\t\t  1.Invoice NO.                  : ----------------------  #IN"<<in[i].invoice_no<<endl;
				cout<<"\t\t  2.Customer Name                : ----------------------  "<<in[i].cust_name<<endl;
				cout<<"\t\t  3.Customer Phone Number        : ----------------------  "<<in[i].cust_phone<<endl;
				cout<<"\t\t  4.Car ID                       : ----------------------  "<<in[i].car_ID<<endl;
				cout<<"\t\t  5.Car Model                    : ----------------------  "<<in[i].car_model<<endl;
				cout<<"\t\t  6.Car Colour                   : ----------------------  "<<in[i].car_colour<<endl;
				cout<<"\t\t  7.Price per day                : ----------------------  "<<in[i].car_price<<endl;
				cout<<"\t\t  8.Number of days renting       : ----------------------  "<<in[i].days<<endl;
				cout<<"\t\t  9.Caution Money                : ----------------------  RM "<<in[i].caution<<endl;
				cout<<"\t\t  10.Advanced                    : ----------------------  RM "<<in[i].advance<<endl;
				cout<<"\t\t  ||Total Rental Amount is  ||   :-----------------------  RM "<<in[i].rental_amount<<endl<<endl;
				
				i++;
				j++;
			}
		}
		else
		{
			cout<<"Unable to open file invoice";
		}
		
		system("PAUSE");
		
		admin_menu();
	}
	
	void search_invoice()  //binary search
	{
		invoice in[50];
		int first=0,found=0,mid,last,i=0,target_invoice;
		string empty;
		
		ifstream readinvoice;
		readinvoice.open("invoice.txt");
		
		if(readinvoice)
		{
			system("cls");
			cout << "  =============================================================================" << endl;
    		cout << "                               Search Invoice                                 " << endl;
    		cout << " =============================================================================" << endl;
    		
    		
    		cout << "Enter the Invoice ID to search: #IN";
    		cin>>target_invoice;
    		
    		
    		while(readinvoice>>in[i].invoice_no)
    		{
    			getline(readinvoice,empty);
				getline(readinvoice,in[i].cust_name);
				getline(readinvoice,in[i].cust_phone);
				readinvoice>>in[i].car_ID;
				getline(readinvoice,empty);
				getline(readinvoice,in[i].car_model);
				getline(readinvoice,in[i].car_colour);
				readinvoice>>in[i].car_price;
				getline(readinvoice,empty);
				readinvoice>>in[i].days;
				getline(readinvoice,empty);
				readinvoice>>in[i].caution;
				getline(readinvoice,empty);
				readinvoice>>in[i].advance;
				getline(readinvoice,empty);
				readinvoice>>in[i].rental_amount;
				getline(readinvoice,empty);
			
				i++; 	
			}
			
		}
		else
		{
			cout<<"Unable to open file invoice";
		}
			
			last=i;
	
    		while( (found==0) && (first <= last) )//binary search for searching invoice
			{
				mid = (first + last) / 2;
		
				if( target_invoice == in[mid].invoice_no)
				{
					found =1;
				}		
				else
				{
					if( target_invoice<in[mid].invoice_no)
					{
						last= mid - 1;
					}
					else
					{
						first = mid + 1;
					}
				}
			}
			
			if(found)
			{
				cout<<"\n\t\t  ============================================================================="<<endl;
				cout<<"\t\t                         Car Rental - Customer Invoice                        "<<endl;
				cout<<"\t\t  ============================================================================"<<endl ;			
				cout<<"\t\t  1.Invoice NO.                  : ----------------------  #IN"<<in[mid].invoice_no<<endl;
				cout<<"\t\t  2.Customer Name                : ----------------------  "<<in[mid].cust_name<<endl;
				cout<<"\t\t  3.Customer Phone Number        : ----------------------  "<<in[mid].cust_phone<<endl;
				cout<<"\t\t  4.Car ID                       : ----------------------  "<<in[mid].car_ID<<endl;
				cout<<"\t\t  5.Car Model                    : ----------------------  "<<in[mid].car_model<<endl;
				cout<<"\t\t  6.Car Colour                   : ----------------------  "<<in[mid].car_colour<<endl;
				cout<<"\t\t  7.Price per day                : ----------------------  "<<in[mid].car_price<<endl;
				cout<<"\t\t  8.Number of days renting       : ----------------------  "<<in[mid].days<<endl;
				cout<<"\t\t  9.Caution Money                : ----------------------  RM "<<in[mid].caution<<endl;
				cout<<"\t\t  10.Advanced                    : ----------------------  RM "<<in[mid].advance<<endl;
				cout<<"\t\t  ||Total Rental Amount is  ||   :-----------------------  RM "<<in[mid].rental_amount<<endl<<endl;
			}
			else
				{
					cout<<"\n Invoice not found";
				}
			 system("PAUSE");
			 admin_menu();
	}
	
		friend class CarLinkedList;
};

void CarLinkedList::saveToFile(const string& filePath) //saveToFile
{
    ofstream ac(filePath.c_str(), ios::app);
    if (ac)
    {
        node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        ac<<endl;
        ac<<temp->data.id<<endl;
        ac<<temp->data.name<<endl;
        ac<<temp->data.brand<<endl;
        ac<<temp->data.colour<<endl;
        ac<<temp->data.body_type<<endl;
        ac<<temp->data.segment<<endl;
        ac<<temp->data.capacity<<endl;
        ac<<temp->data.horsepower<<endl;
        ac<<temp->data.fuel<<endl;
        ac<<temp->data.price<<endl;

        ac.close();
        cout << "Car saved successfully !!! " << endl;
        system("PAUSE");
        
    }
    else
    {
        cout << "Error opening file." << endl;
    }
}

int main()
{
	main_page:
    int select;
	
    ifstream start("logo.txt"); //display logo read from txt

    if (!start)
    {
        cout << "Cannot open logo file." << endl;
    }
    
    char str[1000];
    while (start)
    {
        start.getline(str, 1000);
        if (start)
            cout << str << endl;
    }
    start.close();
    
    cout<<"\n\t\t\t<<<<<<<<< Wheels On Rent <<<<<<<<<"<<endl;
	cout<<"\t\t\t1. Login / Register"<<endl;
	cout<<"\t\t\t2. Admin Mode"<<endl;
	cout<<"\t\t\t3. Exit"<<endl;
	cout<<"\t\t\tPlease enter your selection number: ";
	cin>>select;
	fflush(stdin);
    cout<<"\nLoading..";
    for(int i=0;i<2;i++)
    {
        sleep(1);
    	cout<<"..";
	}
	cout<<"\n\n";

    system("CLS");
    switch (select)
    {
    case 1:
        // login/register
        user_page();
        break;
    case 2:
        // admin mode
        {
	        admin obj;
	        obj.login();
		}
        
        break;
    case 3:
        cout << "System Exit";
        exit(1);
        break;
    default:
        cout << "Invalid selection, please enter again"<<endl;
        system("pause");
        system("cls");
        main();
    }

    return 0;
}
