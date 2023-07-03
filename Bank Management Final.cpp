#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cctype>
#include<ctime>
using namespace std;
class Person
{
    string firstName;
    string middleName;
    string lastName;
    string phoneNumber;
    string dateOfBirth;
    string CNIC;
    string gender;

public:
    Person(){};
    Person(string f, string m, string l, string p, string d, string c,string g)
    {
     firstName=f;
     middleName=m;
     lastName=l;
     phoneNumber=p;
     dateOfBirth=d;
     CNIC=c;
     gender=g;
    }
    void setFirstName(string);
    void setMiddleName(string);
    void setLastName(string);
    void setPhoneNumber(string);
    void setDateOfBirth(string);
    void setCNIC(string);
    void setGender(string);
    string getFirstName(void);
    string getMiddleName(void);
    string getLastName(void);
    string getPhoneNumber(void);
    string getCNIC(void);
    string getGender(void);
    string getDateOfBirth(void);
};
class Transaction
{
private:
    string date;
    string type;

public:
    // default
    Transaction()
    {
        date="";
        type = "";
    }
    Transaction(string d, string t)
    {
        date=d;
        type = t;
    }
    // setters
    void setDate(string d);
    void setType(string t);

    // getters
    string getDate();
    string getType();
};
// child class
class Transfer : Transaction
{
private:
    double Transfer_amount;

public:
    // default
    Transfer()
    {
        Transfer_amount = 0.0;
    }
    Transfer(double a,string d, string t):Transaction(d,t)
    {
        Transfer_amount = a;
    }
    // setters
    void setTransfer(double a);
    int getTransferAmount();
};
// child class
class Deposit : Transaction
{
private:
    double Deposit_amount;

public:
    // default
    Deposit()
    {
        Deposit_amount = 0.0;
    }
    Deposit(string d, double a, string t):Transaction(d,t)
    {
        Deposit_amount = a;
    }
    // setter for all
    void setDeposit(double a);
    // getters
    int getDepositAmount();
};
class Withdraw : Transaction
{
private:
    double Withdraw_amount;

public:
    // default
    Withdraw()
    {
        Withdraw_amount = 0.0;
    }
    Withdraw(string d,double a,string t):Transaction(d,t)
    {
        Withdraw_amount = a;
    }
    // setter for all
    void setWithdraw(double a);
    // getters
    double getDrawAmount();
};
class Installments
{
private:
    double duration;
    double monthlyInstallment;
public:
    // default
    Installments()
    {
        duration = 0;
    }
    Installments(int d)
    {
        duration = d;
    }
    // indiviualsetters
    void setDuration();
    void setMonthlyInstallment(double,double);
    // getters
    double getMonthlyInstallment();
    double getDuration();
};
// Derived Class 2
class Interest
{
private:
    double Interest_amount;
    double rate;
public:
    // default
    Interest()
    {
        Interest_amount = 0.0;
    }
    Interest(double a, float r, double T)
    {
        Interest_amount = a;
        rate = r;
    }
    void setIntrestAmount(double a);
    void setRate(double d);
    double getInterestAmount();
    double getRate();
};
// child class
class Loan: public Interest, public Installments
{
private:
    double Loan_amount;
    int Loan_description;
    int flagl;
    int remInst;
    double remLoan;
public:
    // default
    Loan()
    {
        Loan_amount = 0.0;
        Loan_description = 0;
        flagl=0;

    }
    Loan(double a, int d)
    {
        Loan_amount = a;
        Loan_description = d;
    }

    // setters
    void setAmount();
    void setLoanDescription(int);

    // getters
    double getLoanAmount();
    int getLoanDescription();
    int getFlagl();
    void payInstallment();
};
class Account 
{
    long long int accountNumber;
    string dateOfOpening;
    double balance;
    string PIN;
    vector<Deposit> deposits;
    vector<Transfer> transfers;
    vector<Withdraw> withdraws;
    Loan loan;

public:
    Account(string d="NotSet", double b=0, string p="NotSet")
    {
        dateOfOpening=d;
        balance=b;
        PIN=p;
        accountNumber = static_cast<long long int>(time(nullptr));
    }
    void setAccountNumber();
    void setDateOfOpening(string);
    void setPIN(string);
    void setBalance(double);
    long long int getAccountNumber(void);
    string getDateOfOpening(void);
    string getPIN(void);
    double getBalance(void);
    void setDeposits(Deposit);
    void setTransfers(Transfer);
    void setWithdraws(Withdraw);
    vector<Deposit> getDeposits(void);
    vector<Transfer> getTransfers(void);
    vector<Withdraw> getWithdraws(void);
    void setLoan(Loan l)
    {
        loan=l;
    }
    Loan getloan()
    {
        return loan;
    }
    

};
class Customer : public Person
{

    string customerOccupation;
    string fatherName;
    string nextOfKin;
    vector <Account> accounts;
public:
    Customer(){};
    Customer(string f, string m, string l, string p, string d, string c,string g, string oc, string ft, string n):Person (f, m, l, p, d, c, g)
    {
        customerOccupation=oc;
        fatherName=ft;
        nextOfKin=n;
    }
    void setCustomerOccupation(string);
    void setFatherName(string);
    void setNextOfKin(string);
    string getCustomerOccupation(void);
    string getFatherName(void);
    string getNextOfKin(void);
    void setAccount(Account a)
    {
        accounts.push_back(a);
    }
    vector <Account> getAccounts()
    { 
        return accounts;
    }
    void updateAccounts(int i,Account a)
    {
        accounts[i]=a;
    }
};
class Management : public Person
{
    string designation;
    string dateOfJoining;
public:
    Management(){};
    Management(string f, string m, string l, string p, string d, string c, string g, string desg, string doj) : Person(f, m, l, p, d, c, g)
    {
        designation = desg;
        dateOfJoining = doj;
    }
    void setDesignation(string);
    void setDateOfJoining(string);
    string getDesignation();
    string getDateofJoining();
};
class Administrator : public Management
{
    string adminId;
    string adminPassword;
    double adminSalary;

public:
    Administrator(){};
    Administrator(string f, string m, string l, string p, string d, string c, string g, string desg, string doj, string id, string pass, double sal) : Management(f, m, l, p, d, c, g, desg, doj)
    {
        adminId = id;
        adminPassword = pass;
        adminSalary = sal;
    }
    void setAdminId(string);
    void setAdminPassword(string);
    void setAdminSalary(double);
    string getAdminId(void);
    string getAdminPassword(void);
    double getAdminSalary(void);
};
class Employee : public Management
{
    string profession;
    string employeeId;
    double employeeSalary;
    string employeePassword;

public:
    Employee(){};
    Employee(string f, string m, string l, string p, string d, string c, string g, string desg, string doj, string emppassword, string profession, string empid, double empsalary) : Management(f, m, l, p, d, c, g, desg, doj)
    {
        this->profession = profession;
        employeeId = empid;
        employeeSalary = empsalary;
        employeePassword = emppassword;
    }
    void setProfession(string);
    void setEmployeeId(string);
    void setemployeePassword(string);
    void setEmployeeSalary(double);
    string getProfession();
    string getEmployeeId();
    string getemployeePassword();
    double getEmployeeSalary();
};
class Bank
{
    string name;
    string helpineNumber;
    string url;
    vector <Customer> customers;
    vector<Administrator> administrator;
    vector<Employee> employees;
public:
    Bank(){};
    void setCustomer(Customer c);
    void setAdministrator(Administrator a);
    void setEmployee(Employee e);

    string getName(void);
    string getHP(void);
    string getURL(void);
    vector<Customer> getCustomers()
    {
        return customers;
    }
    void updateCustomer(int i, Customer cus)
    {
        customers[i]=cus;
    }
        vector<Administrator> getAdministrator()
    {
        return administrator;
    }
    vector<Employee> getEmployees()
    {
        return employees;
    }



};

class Address
{
    string country;
    string city;
    string streetNumber;
    string houseNumber;

public:
    Address();
    Address(string, string, string, string);
    void setCountry(string);
    void setCity(string);
    void setNumber(string);
    void setHouseNumber(string);
    string getCountry(void);
    string getCity(void);
    string getNumber(void);
    string getHouseNumber(void);
};
class Security
{
    string guardId;
    string currentShift;

public:
    Security();
    Security(string, string);
    void getGuardId(string);
    void getCurrentShift(string);
    string getGuardId(void);
    string getCurrentShift(void);
};
class Parking
{
    string slotId;
    string vehicleNumber;
    string vehicleOwnerName;

public:
    Parking();
    Parking(string, string, string);
    void getSlotId(string);
    void getVehiclceNumber(string);
    void getVehicleOwnerName(string);
    string getSlotId(void);
    string getVehiclceNumber(void);
    string getVehicleOwnerName(void);
};

// Derived class


// Transport class
class Transport
{
private:
    string vehicletype;
    string Model;
    int plateNumber;

public:
    // default
    Transport()
    {
        vehicletype = "";
        Model = "";
        plateNumber = 0;
    }
    Transport(string v, string m, int p)
    {
        vehicletype = v;
        Model = m;
        plateNumber = p;
    }
    // setters
    void setVehicleType(string v);
    void setModel(string m);
    void setPlateNumber(int p);
    // getters
    string getVehicleType();
    string getModel();
    int getPlateNumber();
};
bool isNumeric(const string) ;
bool isAlphanumeric(const string &str);
int main()
{ 
    ofstream outc;
    outc.open("Customers.txt");
    ofstream oute;
    oute.open("Employee.txt");
    ofstream outa;
    outa.open("Administrator.txt");
    ofstream outac;
    outac.open("Account.txt");
    Bank bank;  
    while (1)
    {
        cout<<"Select from the menu below"<<endl;
        int check1;
        int flagl=0;
        cout<<"1.Customer\n2.Management";
        cin>>check1;
        switch (check1)
        {
            case 1:
            {
                cout<<"Select from the menu below"<<endl;
                int check2;
                cout<<"1.Sign up\n2.Sign in";
                cin>>check2;
                switch (check2)
                {
                    case 1:
                    {
                        string firstName;
                        string middleName;
                        string lastName;
                        string phoneNumber;
                        string dateOfBirth;
                        string CNIC;
                        string gender;
                        string customerOccupation;
                        string fatherName;
                        string nextOfKin;   
                        cout<<"Enter your First Name: ";
                        cin>>firstName;
                        cout<<"Enter you Middle Name: ";
                        cin>>middleName;
                        cout<<"Enter your Last Name: ";
                        cin>>lastName;
                        cout<<"Enter your phone number: ";
                        cin>>phoneNumber;
                        cout<<"Enter your DateOfBirth: ";
                        cin>>dateOfBirth;
                        cout<<"Enter your CNIC: ";
                        cin>>CNIC;
                        cout<<"Enter your gender: ";
                        cin>>gender;
                        cout<<"Enter your occupation: ";
                        cin>>customerOccupation;
                        cout<<"Enter your father name: ";
                        cin>>fatherName;
                        cout<<"Enter name of your next of kin: ";
                        cin>>nextOfKin;
                        Customer c(firstName , middleName, lastName,phoneNumber,dateOfBirth,CNIC,gender,customerOccupation,fatherName,nextOfKin);
                        bank.setCustomer(c);
                        cout<<"You have successfully registered as our valued customer "<<endl;
                        outc<<"\t\t\t\t\t====  CUSTOMER NUMBER "<<bank.getCustomers().size()<<" ====\n";
                        outc<<"Customer name: "<<firstName<<" "<<middleName<<" "<<lastName<<endl;
                        outc<<"Phone Number: "<<phoneNumber<<endl;
                        outc<<"Date of Birth: "<<dateOfBirth<<endl;
                        outc<<"CNIC: "<<CNIC<<endl;
                        outc<<"Gender: "<<gender<<endl;
                        outc<<"Occupation: "<<customerOccupation<<endl;
                        outc<<"Father Name: "<<fatherName<<endl;
                        outc<<"Next of Kin: "<<nextOfKin<<endl;
                        break;       
                    }
                    case 2:
                    {
                        string cnic;
                        cout<<"Enter your CNIC: ";
                        cin>>cnic;
                        for(int i=0;i<bank.getCustomers().size();i++)
                        {
                            if (cnic==bank.getCustomers()[i].getCNIC())
                            {
                                cout<<"Customer Name: \t\t "<<bank.getCustomers()[i].getFirstName()<<"\t"<<bank.getCustomers()[i].getMiddleName()<<"\t"<<bank.getCustomers()[i].getLastName();
                                cout<<"\nCNIC: \t\t"<<bank.getCustomers()[i].getCNIC()<<endl;
                                int check3;
                                cout<<"Already had an account? Select from below: \n1.Sign In\n2.Create Account\n";
                                cin>>check3;
                                
                                switch (check3)
                                {
                                    
                                    case 1:
                                    {
                                        long long int ac;
                                        string p;
                                        cout<<"Enter your account number: ";
                                        cin>>ac;
                                        cout<<"Enter your PIN: ";
                                        cin>>p;
                                        for(int y=0;y<=bank.getCustomers()[i].getAccounts().size();y++)
                                        {
                                            
                                             if ((bank.getCustomers()[i].getAccounts()[y].getAccountNumber()==ac)&&(bank.getCustomers()[i].getAccounts()[y].getPIN()==p))
                                            {
                                                
                                                cout<<"Account Number: "<<bank.getCustomers()[i].getAccounts()[y].getAccountNumber()<<endl;
                                                cout<<"Balance: "<<bank.getCustomers()[i].getAccounts()[y].getBalance()<<endl;
                                                cout<<"Which transaction you want to proceed:\n1.Deposit\n2.Withdraw\n3.Transfer\n4.Take Loan\n5.Pay Installment";
                                                int check4;
                                                cin>>check4;
                                        
                                                switch(check4)
                                                {
                                                    case 1:
                                                    {
                                                        string date;
                                                        double amount;
                                                        string type;
                                                        cout<<"Enter date of transaction: ";
                                                        cin>>date;
                                                        type="Deposit";
                                                        cout<<"Enter amount to be deposited: ";
                                                        cin>>amount;
                                                        Deposit d(date,amount,type);
                                                        double b;
                                                        b=bank.getCustomers()[i].getAccounts()[y].getBalance()+amount;
                                                        Customer cus;
                                                        cus=bank.getCustomers()[i];
                                                        Account ac;
                                                        ac=cus.getAccounts()[y];
                                                        ac.setBalance(b);//account object with updated balance
                                                        cus.updateAccounts(y, ac);//Customer with updated account
                                                        bank.updateCustomer(i,cus);
                                                        cout<<"You have successfully deposited PKR "<<amount; 
                                                        break;       

                                                    }
                                                    case 2:
                                                    {
                                                        string date;
                                                        double amount;
                                                        string type;
                                                        cout<<"Enter date of transaction: ";
                                                        cin>>date;
                                                        type="Withdraw";
                                                        cout<<"Enter amount you wanted to withdraw: ";
                                                        double a;
                                                        cin>>a;
                                                        if (a<=bank.getCustomers()[i].getAccounts()[y].getBalance())
                                                        {
                                                            amount=a;
                                                            Withdraw w(date,amount,type);
                                                            double b;
                                                            b=bank.getCustomers()[i].getAccounts()[y].getBalance()-amount;
                                                            Customer cus;
                                                            cus=bank.getCustomers()[i];
                                                            Account ac;
                                                            ac=cus.getAccounts()[y];
                                                            ac.setBalance(b);
                                                            cus.updateAccounts(y, ac);
                                                            bank.updateCustomer(i,cus);
                                                            cout<<"You have successfully withdrawn PKR "<<amount;                                                             
                                                        }
                                                        else
                                                        {
                                                            cout<<"Sorry your transaction can not be processed\n ";
                                                        }
                                              
                                                        break;                                                        
                                                    }
                                                    case 3:
                                                    {
                                                        string date;
                                                        double amount;
                                                        long long int acco;
                                                        string type;
                                                        cout<<"Enter date of transaction: ";
                                                        cin>>date;
                                                        type="Transfer";
                                                        cout<<"Enter account number to which you wanted to transfer money: ";
                                                        cin>>acco;
                                                        cout<<"Enter amount you wanted to transfer: ";
                                                        double a;
                                                        cin>>a;
                                                        if (a<=bank.getCustomers()[i].getAccounts()[y].getBalance())
                                                        {
                                                            
                                                            for(int j=0; j<bank.getCustomers().size();j++)
                                                            {

                                                                for(int k=0; k<bank.getCustomers()[j].getAccounts().size();k++)
                                                                {
                                                                    if (acco==bank.getCustomers()[j].getAccounts()[k].getAccountNumber())
                                                                    {
                                                                        amount=a;
                                                                        Transfer t(amount,date,type);
                                                                        double x,w;
                                                                        x=bank.getCustomers()[i].getAccounts()[y].getBalance()-amount;
                                                                        Customer cus;
                                                                        cus=bank.getCustomers()[i];
                                                                        Account ac;
                                                                        ac=cus.getAccounts()[y];
                                                                        ac.setBalance(x);
                                                                        cus.updateAccounts(y, ac);
                                                                        bank.updateCustomer(i,cus);
                                                                        w=bank.getCustomers()[j].getAccounts()[k].getBalance()+amount;
                                                                        Customer cus1;
                                                                        cus1=bank.getCustomers()[j];
                                                                        Account ac1;
                                                                        ac1=cus1.getAccounts()[k];
                                                                        ac1.setBalance(w);
                                                                        cus1.updateAccounts(k, ac1);
                                                                        bank.updateCustomer(j,cus1);
                                                                        cout<<"You have successfully transfered an amount of PKR "<<amount<<" to account: "<<acco<<endl;
                                                                    }
                                                                }
                                                            }                                                            
                                                        }
                                                        else
                                                        {
                                                            cout<<"Sorry your transaction can not be processed\n ";
                                                        }
                                              
                                                        break;                                                       
                                                    }
                                                    case 4:
                                                    {

                                                        Loan l;
                                                        l.setAmount();
                                                        if (l.getFlagl())
                                                        {
                                                            Customer cus=bank.getCustomers()[i];
                                                            Account ac=cus.getAccounts()[y];
                                                            l.setDuration();
                                                            l.setRate(l.getDuration());
                                                            l.setIntrestAmount(l.getLoanAmount());
                                                            l.setMonthlyInstallment(l.getLoanAmount(),l.getInterestAmount());
                                                            cout<<"Enter loan description: ";
                                                            int d;
                                                            cin>>d;
                                                            l.setLoanDescription(d);
                                                            ac.setLoan(l);
                                                            cus.updateAccounts(y, ac);
                                                            bank.updateCustomer(i,cus);
                                                            break;
                                                        }    
                                                    }
                                                    case 5:
                                                    {
                                                        Customer cus=bank.getCustomers()[i];
                                                        Account ac=cus.getAccounts()[y];

                                                        Loan l=bank.getCustomers()[i].getAccounts()[y].getloan();
                                                        if(l.getFlagl())
                                                        {
                                                            cout<<"Total loan you took from the bank: "<<l.getLoanAmount()+l.getInterestAmount()<<endl;
                                                            cout<<"Monthly Installment: "<<l.getMonthlyInstallment()<<endl;
                                                            cout<<"Conform by pressing y to pay monthly installment: "<<endl;
                                                            char ch;
                                                            cin>>ch;
                                                            if (ch=='y'||ch=='Y')
                                                            {
                                                                l.payInstallment();
                                                            }
                                                           
                                                        }
                                                        else
                                                        {
                                                            cout<<"You have not applied for any loan yet."<<endl;
                                                        }
                                                        ac.setLoan(l);
                                                        cus.updateAccounts(y, ac);
                                                        bank.updateCustomer(i,cus);
                                                        break;

                                                    }
                                                }



                                            }
                  
                                        }
                                        break;
                                    }
                                    case 2:
                                    {
                                        string dateOfOpening;
                                        double balance;
                                        string PIN;
                                        string ch;
                                        cout<<"Enter date of opening: ";
                                        cin>>dateOfOpening;
                                        cout<<"Enter your initial balance in Rupees";
                                        cin>>balance;
                                        while(1)
                                        {
                                            cout<<"Select a PIN (it should be of 5 digits and contains only numbers: )";
                                            cin>>ch;
                                            if (isNumeric(ch)&& ch.size()==5)
                                                {
                                                    PIN=ch;
                                                    break;
                                                }
                                            else
                                            {
                                                cout<<"Invalid input\n";
                                            }
                                        } 
                                        Account a(dateOfOpening,balance,PIN);
                                        Customer cus;
                                        cus=bank.getCustomers()[i];
                                        cus.setAccount(a);
                                        bank.updateCustomer(i,cus);
                                        cout<<bank.getCustomers()[i].getAccounts().size();
                                        cout<<"Hello";
                                        cout<<"Your account has successfully added with account number: "<<a.getAccountNumber()<<endl;  
                                        outac<<"\t\t\t\t\t====Account of Customer of CNIC:"<<bank.getCustomers()[i].getCNIC()<<"====\n";
                                        outac<<"Account Number: "<<a.getAccountNumber()<<endl;
                                        outac<<"Date of Opening: "<<dateOfOpening<<endl;
                                        outac<<"Balance: "<<balance<<endl;
                                        outac<<"PIN: "<<PIN<<endl;

                                        break;
                                    }
                                   
                                    
                                }



                            }
                        }
                        
                        break;
                    }   
                         
                }
            break;
            }
            case 2:
            {
                cout<<"Select from the menu below\n1.Administrator\n2.Employee";
                int check6;
                cin>>check6;
                switch (check6)
                {
                    case 1:
                    {
                        cout<<"Press 1 for adding administrator and press 2 if you already an administrator: ";
                        int check7;
                        cin>>check7;
                        switch(check7)
                        {

                            
                            case 1:
                            {
                                string firstName;
                                string middleName;
                                string lastName;
                                string phoneNumber;
                                string dateOfBirth;
                                string CNIC;
                                string gender;
                                string designation;
                                string dateOfJoining;
                                string adminId;
                                string adminPassword;
                                double adminSalary;
                                cout << "Enter your First Name: ";
                                cin >> firstName;
                                cout << "Enter you Middle Name: ";
                                cin >> middleName;
                                cout << "Enter your Last Name: ";
                                cin >> lastName;
                                cout << "Enter your phone number: ";
                                cin >> phoneNumber;
                                cout << "Enter your DateOfBirth: ";
                                cin >> dateOfBirth;
                                cout << "Enter your CNIC: ";
                                cin >> CNIC;
                                cout << "Enter your gender: ";
                                cin >> gender;
                                cout << "Enter your designation: ";
                                cin >> designation;
                                cout << "Enter your dateOfJoining: ";
                                cin >> dateOfJoining;
                                cout << "Enter your adminSalary: ";
                                cin >> adminSalary;
                                cout << "Enter your adminId: ";
                                if (isAlphanumeric(adminId))
                                {
                                    cin >> adminId;
                                }
                                else
                                {
                                    cout << "Invalid input" << endl;
                                    cout << "Enter your AdminID again!";
                                    cin >> adminId;
                                }
                                cout << "Enter your adminPassword: ";
                                if (isAlphanumeric(adminPassword))
                                {
                                    cin >> adminPassword;
                                }
                                else
                                {
                                    cout << "Invalid input" << endl;
                                    cout << "Enter your AdminPassword again!";
                                    cin >> adminPassword;
                                }
                                Administrator a(firstName, middleName, lastName, phoneNumber, dateOfBirth, CNIC, gender, designation, dateOfJoining, adminId, adminPassword, adminSalary);
                                bank.setAdministrator(a);
                                cout << "Administrator has successfully registered" << endl;
                                outa<<"\t\t\t\t\t====  ADMIN NUMBER "<<bank.getAdministrator().size()<<" ====\n";
                                outa<<"Admin name: "<<firstName<<" "<<middleName<<" "<<lastName<<endl;
                                outa<<"Phone Number: "<<phoneNumber<<endl;
                                outa<<"Date of Birth: "<<dateOfBirth<<endl;
                                outa<<"CNIC: "<<CNIC<<endl;
                                outa<<"Gender: "<<gender<<endl;
                                outa<<"Designation: "<< designation<<endl;
                                outa<<"Date of joining: "<< dateOfJoining<<endl;
                                outa<<"Admin Id: "<< adminId<<endl;
                                outa<<"Admin Password: "<< adminPassword<<endl;
                                outa<<"Admin Salary: "<< adminSalary<<endl;
                                break;
                            }

                            case 2:
                            {
                                cout << "Enter Admin ID:" << endl;
                                // string adminid;
                                string id;
                                cin >> id;
                                cout << "Enter Login Password" << endl;
                                // string adminpassword;
                                string p;
                                cin >> p;
                                for (int i = 0; i < bank.getAdministrator().size(); i++)
                                {
                                    if ((bank.getAdministrator()[i].getAdminId() == id) && (bank.getAdministrator()[i].getAdminPassword() == p))
                                    {
                                        cout << "Welcome Admin" << endl;
                                        cout << "Administrator Name: \t\t" << bank.getAdministrator()[i].getFirstName() << endl;
                                        cout << "MiddletName:\t\t" << bank.getAdministrator()[i].getMiddleName() << endl;
                                        cout << "LastName:"
                                            << "\t\t" << bank.getAdministrator()[i].getLastName() << endl;
                                        cout << "AdminID: \t\t" << bank.getAdministrator()[i].getAdminId() << endl;
                                        cout << "Admin Password:" << "\t\t" << bank.getAdministrator()[i].getAdminPassword() << endl;
                                        cout << "AdminDesignation: \t\t" << bank.getAdministrator()[i].getDesignation() << endl;
                                        cout << "AdminSalary: \t\t" << bank.getAdministrator()[i].getAdminSalary() << endl;
                                        cout << "AdminPhoneNumber: \t\t" << bank.getAdministrator()[i].getPhoneNumber() << endl;
                                        cout << "AdminCNIC: \t\t" << bank.getAdministrator()[i].getCNIC() << endl;
                                        cout << "AdminDateOfBirth: \t\t" << bank.getAdministrator()[i].getDateOfBirth() << endl;
                                        cout << "AdminDateOfJoining: \t\t" << bank.getAdministrator()[i].getDateofJoining() << endl;
                                    }
                                }
                                break;
                            }
                        } 
                        break;   
                    }
                    case 2:
                    {
                        cout<<"Press 1 for adding employee and press 2 if you already an employee: ";
                        int check8;
                        cin>>check8;
                        switch(check8)
                        {
                            case 1:
                            {
                                string firstName;
                                string middleName;
                                string lastName;
                                string phoneNumber;
                                string dateOfBirth;
                                string CNIC;
                                string gender;
                                string designation;
                                string dateOfJoining;
                                string profession;
                                string employeeId;
                                string employeePassword;
                                double employeeSalary;
                                cout << "Enter your First Name: ";
                                cin >> firstName;
                                cout << "Enter you Middle Name: ";
                                cin >> middleName;
                                cout << "Enter your Last Name: ";
                                cin >> lastName;
                                cout << "Enter your phone number: ";
                                cin >> phoneNumber;
                                cout << "Enter your DateOfBirth: ";
                                cin >> dateOfBirth;
                                cout << "Enter your CNIC: ";
                                cin >> CNIC;
                                cout << "Enter your gender: ";
                                cin >> gender;
                                cout << "Enter your designation: ";
                                cin >> designation;
                                cout << "Enter your dateOfJoining: ";
                                cin >> dateOfJoining;
                                cout << "Enter your employeeSalary: ";
                                cin >> employeeSalary;
                                cout << "Enter your EmployeeId: ";
                                if (isAlphanumeric(employeeId))
                                {
                                    cin >> employeeId;
                                }
                                else
                                {
                                    cout << "Invalid input" << endl;
                                    cout << "Enter your EmployeeID again!";
                                    cin >> employeeId;
                                }
                                cout << "Enter your EmployeePassword: ";
                                if (isAlphanumeric(employeePassword))
                                {
                                    cin >> employeePassword;
                                }
                                else
                                {
                                    cout << "Invalid input" << endl;
                                    cout << "Enter your EmployeePassword again!";
                                    cin >> employeePassword;
                                }
                                cout<<"Enter your profession: ";
                                cin>>profession;
                                Employee e(firstName, middleName, lastName, phoneNumber, dateOfBirth, CNIC, gender, designation, dateOfJoining, employeeId,profession, employeePassword, employeeSalary);
                                bank.setEmployee(e);
                                cout << "Employee has successfully registered" << endl;
                                oute<<"\t\t\t\t\t====  EMPLOYEE NUMBER "<<bank.getEmployees().size()<<" ====\n";
                                oute<<"Employee name: "<<firstName<<" "<<middleName<<" "<<lastName<<endl;
                                oute<<"Phone Number: "<<phoneNumber<<endl;
                                oute<<"Date of Birth: "<<dateOfBirth<<endl;
                                oute<<"CNIC: "<<CNIC<<endl;
                                oute<<"Gender: "<<gender<<endl;
                                oute<<"Designation: "<< designation<<endl;
                                oute<<"Date of joining: "<< dateOfJoining<<endl;
                                oute<<"Profession: "<<profession<<endl;
                                oute<<"Id : "<<employeeId<<endl;
                                oute<<"Password: "<<employeePassword<<endl;
                                oute<<"Salary: "<<employeeSalary<<endl;
                                break;
                            }
                            case 2:
                            {
                                cout << "\t\tEnter your LOGIN details to proceed to your Administrator Account!" << endl;
                                string employeeId;
                                cout <<"Enter Employee ID:" << endl;
                                cin >> employeeId;
                                string employeepassword;
                                cout << "Enter Login Password" << endl;
                                cin >> employeepassword;
                                for (int i = 0; i < bank.getEmployees().size(); i++)
                                {
                                    if (bank.getEmployees()[i].getEmployeeId() == employeeId && bank.getEmployees()[i].getemployeePassword() == employeepassword)
                                    {
                                        cout << "\t\t\t"<< "Welcome Employee" << endl;
                                        cout << "Employee Name: \t\t" << bank.getEmployees()[i].getFirstName() << "\t\t" << bank.getEmployees()[i].getMiddleName()<< "\t\t" << bank.getEmployees()[i].getLastName() << endl;
                                        cout << "Employee ID: \t\t" << bank.getEmployees()[i].getEmployeeId() << endl;
                                        cout << "Employee Password:" << "\t\t" << bank.getEmployees()[i].getemployeePassword() << endl;
                                        cout << "Employee Designation: \t\t" << bank.getEmployees()[i].getDesignation() << endl;
                                        cout << "Employee Salary: \t\t" << bank.getEmployees()[i].getEmployeeSalary() << endl;
                                        cout << "Employee Phone Number: \t\t" << bank.getEmployees()[i].getPhoneNumber() << endl;
                                        cout << "Employee CNIC: \t\t" << bank.getEmployees()[i].getCNIC() << endl;
                                        cout << "Employee DateOfBirth: \t\t" << bank.getEmployees()[i].getDateOfBirth() << endl;
                                        cout << "Employee DateOfJoining: \t\t" << bank.getEmployees()[i].getDateofJoining() << endl;
                                    }
                                }        

                                break;
                            }
                        }
                    break;    
                    }

                }

            break;   
            }
        }


    }   
    return 0;
}
void Person::setFirstName(string f)
{
    firstName = f;
}
void Person::setMiddleName(string m)
{
    middleName = m;
}
void Person::setLastName(string l)
{
    lastName = l;
}
void Person::setPhoneNumber(string p)
{
    phoneNumber = p;
}
void Person::setDateOfBirth(string d)
{
    dateOfBirth = d;
}
void Person::setCNIC(string c)
{
    CNIC = c;
}
void Person::setGender(string g)
{
    gender = g;
}
string Person::getFirstName(void)
{
    return firstName;
}
string Person::getMiddleName(void)
{
    return middleName;
}
string Person::getLastName(void)
{
    return lastName;
}
string Person::getPhoneNumber(void)
{
    return phoneNumber;
}
string Person::getDateOfBirth(void)
{
    return dateOfBirth;
}
string Person::getCNIC(void)
{
    return CNIC;
}
string Person::getGender(void)
{
    return gender;
}
void Management::setDesignation(string d)
{
    designation = d;
}
void Management::setDateOfJoining(string da)
{
    dateOfJoining = da;
}
string Management::getDesignation(void)
{
    return designation;
}
string Management::getDateofJoining(void)
{
    return dateOfJoining;
}
void Administrator::setAdminId(string id)
{
    adminId = id;
}
void Administrator::setAdminPassword(string p)
{
    adminPassword = p;
}
void Administrator::setAdminSalary(double s)
{
    adminSalary = s;
}
string Administrator::getAdminId(void)
{
    return adminId;
}
string Administrator::getAdminPassword(void)
{
    return adminPassword;
}
double Administrator::getAdminSalary(void)
{
    return adminSalary;
}
void Employee ::setProfession(string p)
{
    profession = p;
}
void Employee ::setEmployeeId(string id)
{
    employeeId = id;
}
void Employee ::setemployeePassword(string pa)
{
    employeePassword = pa;
}
void Employee ::setEmployeeSalary(double s)
{
    employeeSalary = s;
}
string Employee ::getProfession(void)
{
    return profession;
}
string Employee ::getEmployeeId(void)
{
    return employeeId;
}
string Employee ::getemployeePassword(void)
{
    return employeePassword;
}
double Employee ::getEmployeeSalary(void)
{
    return employeeSalary;
}
void Account::setAccountNumber()
{
    static long long int  n = 51980000000;
    accountNumber = n;
    n++;
}
void Account::setDateOfOpening(string d)
{
    dateOfOpening = d;
}
void Account::setPIN(string p)
{
    PIN = p;
}
void Account::setBalance(double b)
{
    balance = b;
}
long long int Account::getAccountNumber(void)
{
    return accountNumber;
}
string Account::getDateOfOpening(void)
{
    return dateOfOpening;
}
string Account::getPIN(void)
{
    return PIN;
}
double Account::getBalance(void)
{
    return balance;
}
void Transaction::setDate(string d)
{
    date = d;
}

void Transaction::setType(string t)
{
    type = t;
}
// getters functions
//  getters
string Transaction::getDate()
{
    return date;
}
string Transaction::getType()
{
    return type;
}
// Transfer Child class of Transaction
// setters definition
//  setters
void Transfer::setTransfer(double a)
{
    Transfer_amount = a;
}
// getters
int Transfer::getTransferAmount()
{
    return Transfer_amount;
}
// Deposit Child class of Transaction
// setters definition
void Deposit::setDeposit(double a)
{
    Deposit_amount = a;
}
// getters
int Deposit::getDepositAmount()
{
    return Deposit_amount;
}
// Withdraw Child class of Transaction
// setters definition
void Withdraw::setWithdraw(double a)
{
    Withdraw_amount = a;
}
// getters
double Withdraw::getDrawAmount()
{
    return Withdraw_amount;
}

// Base class LOAN
// setters definition
void Loan::setAmount()
{
    cout<<"Enter your monthly income: ";
    double income;
    cin>>income;                                        
    cout<<"Enter loan description: ";
    if(flagl==0)
    {
        if((income>=50000 && income<100000))
        {
            cout<<"You can take loan upto 200000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<200000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }
            
        }
        else if((income>=100000 && income<150000))
        {
            cout<<"You can take loan upto 300000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<=300000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }

                                                                    
        }
        else if((income>=150000 && income<200000))
        {
            cout<<"You can take loan upto 400000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<=400000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;

            } 
        }
        else if((income>=200000 && income<250000))
        {
            cout<<"You can take loan upto 500000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<=500000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }
        }
        else if((income>=250000 && income<300000))
        {
            cout<<"You can take loan upto 700000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<=700000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }
        }
        else if((income>=300000 && income<350000))
        {
            cout<<"You can take loan upto 900000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<=900000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }
        }
        else if((income>=350000 && income<400000))
        {
            cout<<"You can take loan upto 200000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<=1000000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }

                                                                            
        }
        else if((income>4000001))
        {
            cout<<"You can take loan upto 200000. Enter amount you want to take: ";
            double a;
            cin>>a;
            if(a<1500000)
            {
                cout<<"You are eligible for loan"<<endl;
                cout<<"You have successfully given a loan of amount is: "<<a<<endl;
                Loan_amount=a;
                flagl++;
            }

                                                                    
        }
        else
        {
            cout<<"You are not eligible for loan"<<endl;
        }
    }
}
void Loan::setLoanDescription(int d)
{
    Loan_description = d;
    remInst=getDuration();
    remLoan=Loan_amount+getInterestAmount();
}
// getters
double Loan::getLoanAmount()
{
    return Loan_amount;
}
int Loan::getLoanDescription()
{
    return Loan_description;
}
// Installments Child class oF LOAN
// setters definition
void Installments::setDuration()
{
    cout<<"Select loan Duration from the menu below: "<<endl;
    cout<<"\t\t\t1. 1 year"<<endl;
    cout<<"\t\t\t2. 2 year"<<endl;
    cout<<"\t\t\t3. 3 year"<<endl;
    int i;
    cin>>i;
    switch(i)
    {
        case 1:
        {
            duration=12;
            break;
        }
        case 2:
        {
            duration=24;
            break;
        }
        case 3:
        {
            duration=36;
            break;
        }
    }
}
// getters
double Installments::getDuration()
{
    return duration;
}
// Interest Child class of LOAN
// setters definition
void Interest::setIntrestAmount(double a)
{
    Interest_amount = a*rate/100;
}
void Interest::setRate(double d)
{
    if (d==12)
    {
        rate=10;
    }
    else if (d==24)
    {
        rate=12;
    }
    else if (d==36)
    {
        rate=15;
    }
}
// getters
double Interest::getInterestAmount()
{
    return Interest_amount;
}
double Interest::getRate()
{
    return rate;
}
// Transport class
// setters definition
void Transport::setVehicleType(string v)
{
    vehicletype = v;
}
void Transport::setModel(string m)
{
    Model = m;
}
void Transport::setPlateNumber(int p)
{
    plateNumber = p;
}
// getters
string Transport::getVehicleType()
{
    return vehicletype;
}
string Transport::getModel()
{
    return Model;
}
int Transport::getPlateNumber()
{
    return plateNumber;
}
// Address, Parking,  Security, Bank, Customer

void Address::setCountry(string c)
{
    country = c;
}
void Address::setCity(string ci)
{
    city = ci;
}
void Address::setNumber(string N)
{
    streetNumber = N;
}
void Address :: setHouseNumber(string H)
{
    houseNumber = H;
}

string Address::getCountry()
{
    return country;
}
string Address::getCity()
{
    return city;
}
string Address::getNumber()
{
    return streetNumber;
}
string Address::getHouseNumber()
{
    return houseNumber;
}

// Parking

void Parking::getSlotId(string ID)
{
    slotId = ID;
}
void Parking::getVehiclceNumber(string vnum)
{
    vehicleNumber;
}
void Parking::getVehicleOwnerName(string Oname)
{
    vehicleOwnerName = Oname;
}
string Parking::getSlotId()
{
    return slotId;
}
string Parking::getVehiclceNumber()
{
    return vehicleNumber;
}
string Parking::getVehicleOwnerName()
{
    return vehicleOwnerName;
}

// Security

void Security::getGuardId(string id)
{
    guardId = id;
}
void Security::getCurrentShift(string Cshift)
{
    currentShift = Cshift;
}
string Security::getGuardId()
{
    return guardId;
}
string Security::getCurrentShift()
{
    return currentShift;
}

// Bank

string Bank::getName()
{
    return name;
}
string Bank::getHP()
{
    return helpineNumber;
}
string Bank::getURL()
{
    return url;
}


void Customer::setCustomerOccupation(string Coccu)
{
    customerOccupation;
}
void Customer::setFatherName(string Fname)
{
    fatherName = Fname;
}
void Customer::setNextOfKin(string NextKin)
{
    nextOfKin = NextKin;
}
string Customer::getCustomerOccupation()
{
    return customerOccupation;
}
string Customer::getFatherName()
{
    return fatherName;
}
string Customer::getNextOfKin()
{
    return nextOfKin;
}
void Bank:: setCustomer(Customer c)
{
    customers.push_back(c);
}
bool isNumeric(const string str) 
{
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }\
    }
    return true;
}
void Account:: setDeposits(Deposit d)
{
    deposits.push_back(d);
}
void Account:: setTransfers(Transfer t)
{
    transfers.push_back(t);
}
void Account:: setWithdraws(Withdraw w)
{
    withdraws.push_back(w);
}
vector<Deposit> Account:: getDeposits(void)
{
    return deposits;
}
vector<Transfer> Account:: getTransfers(void)
{
    return transfers;
}
vector<Withdraw> Account:: getWithdraws(void)
{
    return withdraws;
}
double Installments:: getMonthlyInstallment()
{
    return monthlyInstallment;
}
void Installments:: setMonthlyInstallment(double am,double i)
{
    monthlyInstallment=(am+i)/duration;
}
int Loan::getFlagl()
{
    return flagl;
}
void Loan:: payInstallment()
{
    remInst--;
    remLoan-=getMonthlyInstallment();
    cout<<"Remaining Installments: "<<remInst<<endl;
    cout<<"Remaining Loan Amount: "<<remLoan<<endl;
}
bool isAlphanumeric(const string &str)
{
    for (char c : str)
    {
        if (!isalnum(c))
        {
            return false;
        }
    }
    return true;
}
void Bank::setAdministrator(Administrator a)
{
    administrator.push_back(a);
}
void Bank::setEmployee(Employee e)
{
    employees.push_back(e);
}
