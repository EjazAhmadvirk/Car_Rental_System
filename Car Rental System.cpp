#include<iostream>
#include<iomanip>   
#include<fstream>  
#include<conio.h>
#include<string>
#include<windows.h>  
#include<unistd.h>   
#include<limits>    

using namespace std;
//Customer struct
struct Customer{
	string customername;
	string carmodel;
	double CNIC;
};
void welcome();
void login();
void showcardetails(const string& carmodel);
void calculaterent(const Customer& customer, int days, int& rentalfee);
void showinvoice(const Customer& customer, int days, int rentalfee);

const string cardetail[5][2]= {
{"A","Ferrari 2019"},
{"B","Hyundai 2019"},
{"C","Honda 2019"},
{"D","Ford 2019"},
{"E","Tayota 2019"}
};

int carrentalrates[5]={3000,4000,5000,6000,7000};
int main()
{
	system("color f1");
	welcome();
	login();
	Customer customer;
	int days,  rentalfee;
	cout<<"\t Please Enter Your Name  ";	
	cin.ignore();
	getline(cin,customer.customername);
	cout<<endl;
	bool carmodel= false;
	while(!carmodel){
		cout<<"Press A for Select Ferrari 2019"<<endl;
		cout<<"press B for select Hyundai 2019"<<endl;
		cout<<"press C for select Honda 2019"<<endl;
		cout<<"Press D for select Ford 2019"<<endl;
		cout<<"Press E for select Tayota 2019"<<endl;
		cout<<endl;
		cout<<"Select the car from above models"<<endl;
		cin>>customer.carmodel;
		cout<<"--------------------------------------------"<<endl;
		if(customer.carmodel == "A" || customer.carmodel == "B" ||customer.carmodel == "C" || customer.carmodel =="D" || customer.carmodel == "E"){
			showcardetails(customer.carmodel);
			carmodel=true;
		}else{
			cout<<"Enter the valid car model"<<endl;
			system("CLS");
		}
		
	}
	
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"Please provide the following informaton"<<endl;
	cout<<"Enter your CNIC:   ";
	cin>>customer.CNIC;
	
//	while(customer.CNIC.length() != 13){
//		cout<<"Invalid CNIC! Please Enter 13 digit CNIC number:  ";
//		cin>>customer.CNIC;
//	}
	
	cout<<"Number of days you want to rent the car\t";
	cin>>days;
	while(days<=0 || cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		
		cout<<"Invalid input! Please Enter the positive number of days  ";
		cin>>days;
	}
	
	calculaterent(customer, days, rentalfee);
	showinvoice(customer,days, rentalfee);
	return 0;
}
// welcome function 
void welcome(){
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\tWelcome To Car Rental System"<<endl;
	sleep(1);
	cout<<"\n\n\t\t\t\t\tStarting the program please wait....."<<endl;
	sleep(2);
	cout<<"\n\n\t\t\t\t\tLoading up files....."<<endl;
		system("CLS");
}
//login function
void login() {
    string inputPassword, filePassword;
    ifstream passwordFile("My PBL Work.txt");

    if (!passwordFile.is_open()) {
        cout << "Error: Could not open password file.\n";
        return;
    }

    getline(passwordFile, filePassword);  
    passwordFile.close();

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tCAR RENTAL SYSTEM \n\n";
    cout << "\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\tLOGIN \n";
    cout << "\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\tEnter Password: ";
    cin >> inputPassword;

    if (inputPassword == filePassword) {
        cout << "\n\n\t\t\t\t\t\tAccess granted\n";
        system("PAUSE");
        system("CLS");
    } else {
        cout << "\n\n\t\t\t\t\t\tAccess Aborted\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}
// cars detail function
void showcardetails(const string& carmodel){
	system("CLS");
	for(int i=0;i<5;i++){
		if(cardetail[i][0]==carmodel){
			cout<<"You Select the   "<<cardetail[i][1]<<endl;
			break;
			
		}
}

}
// calculate rent of cars
void calculaterent(const Customer& customer, int days, int& rentalfee)
{
	sleep(1);
	system("CLS");
	cout<<"Calculate rent please weight"<<endl;
	sleep(2);
	if(customer.carmodel == "A" )
		rentalfee = days*carrentalrates[0];
	else if(customer.carmodel == "B")
	rentalfee = days*carrentalrates[1];
	else if(customer.carmodel == "C")
		rentalfee = days*carrentalrates[2];
	else if (customer.carmodel == "D")
		rentalfee = days*carrentalrates[3];
	else if (customer.carmodel == "E")
		rentalfee = days*carrentalrates[4];
	

}
// invoice function
void showinvoice(const Customer& customer, int days, int rentalfee){
	string carmodelname;
	for(int i=0;i<5;i++){
		if(cardetail[i][0] == customer.carmodel){
			carmodelname=cardetail[i][1];
			break;
		}
	}
	cout<<"\n                  Car Rental- Customer Inoice                    "<<endl;
	cout<<"   /////////////////////////////////////////////////////////////"<<endl;
	cout<<"   |invoive No"<<"---------------------|"<<setw(14)<<"cbn123"<<"   |"<<endl;
	cout<<"   |Customer name"<<"------------------|"<<setw(14)<<customer.customername<<"   |"<<endl;
	cout<<"   |Customer CNIC"<<"------------------|"<<setw(14)<<customer.CNIC<<"   |"<<endl;
	cout<<"   |Carmodel"<<"-----------------------|"<<setw(14)<<carmodelname<<"   |"<<endl;
	cout<<"   |No of days"<<"---------------------|"<<setw(14)<<days<<"   |"<<endl;
	cout<<"   |Total rent"<<"---------------------|"<<setw(14)<<rentalfee<<"   |"<<endl;
	cout<<"   |Caustion money"<<"-----------------|"<<setw(14)<<"0"<<"   |"<<endl;
	cout<<"   |Advance"<<"------------------------|"<<setw(14)<<"0"<<"   |"<<endl;
	cout<<"   ______________________________________________________________"<<endl;
	cout<<endl;
	cout<<"   |Total Rental Amount is"<<"---------|"<<setw(14)<<rentalfee<<"   |"<<endl;
	cout<<"   _____________________________________________________________"<<endl;
	cout<<"   #This is computer generated slip it does not "<<endl;
	cout<<"    requried athuorised signature # "<<endl;
	cout<<"   /////////////////////////////////////////////////////////////////"<<endl;
	cout<<"   you are advise to pay the amount before due date"<<endl; 
	cout<<"   otherwise planty fee will be charged "<<endl;
	cout<<"   ////////////////////////////////////////////////////////////////"<<endl;
	system("PAUSE");
	system("CLS");
}


	 
	 
	 