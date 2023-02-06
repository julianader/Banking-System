#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Transaction{
    protected:
        string transactionName, transactionDate; 
        int transactionID;
    public:
        Transaction(){
            transactionName = "";
            transactionDate = "";
    		transactionID = 0;
        }
        Transaction(string tname, string tdate, int tID){
    		transactionName = tname;
    		transactionDate = tdate;
    		transactionID = tID;
        }
        //SETTERS
        void set_transactionName(string tname){
            this->transactionName = tname;
        }
        void set_transactionDate(string tdate){
            this->transactionDate = tdate;
        }
        void set_transactionID(int tID){
            this->transactionID = tID;
        }
        
        //GETTERS
        string get_transactionName(){
            return transactionName;
        }
        string get_transactionDate(){
            return transactionDate;
        }
        int get_transactionID(){
            return transactionID;
        }
        //display_info
        void display_transaction_info(){
            cout<<"************ Displaying Transaction Information ************"<<endl;
            cout<<"|Transaction Name:      "<<transactionName<<endl;
            cout<<"|Transaction Date:      "<<transactionDate<<endl;
            cout<<"|Transaction ID:        "<<transactionID<<endl;
            cout<<"*********************************************************"<<endl;
        }
};

int generateID(){
    static bool initialized = false;
    if (!initialized){
        srand(time(0));
        initialized = true;
    }
    return rand();
}

class Client{
    protected:
        string clientName, clientEmail, clientPhone, clientAddress, clientPassword;
        Transaction arr[5];
        int clientID;
    public:
        Client(){
            clientName = "";
            clientEmail = "";
    		clientPhone = "";
    		clientAddress = "";
    		clientPassword = "";
    		clientID = 0;
        }
    	Client(string name, string email, string phone, string address){
    		clientName = name;
    		clientEmail = email;
    		clientPhone = phone;
    		clientAddress = address;
    		clientID = 0;
        }
    //SETTERS:
        void set_clientName(string name){
            this->clientName = name;
        }
        void set_clientEmail(string email){
            this->clientEmail = email;
        }
        void set_clientPhone(string phone){
            this->clientPhone = phone;
        }
        void set_clientAddress(string address){
            this->clientAddress = address;
        }
        void set_clientPassword(string password){
            this->clientPassword = password;
        }
        void set_clientID(int cID){
            this->clientID = cID;
        }
        void set_Transaction(Transaction array[]){
            for (int i=0; i<5; i++){
                this->arr[i] = array[i];
            }
        }
    //GETTERS:
        string get_clientName(){
            return clientName;
        }
        string get_clientEmail(){
            return clientEmail;
        }
        string get_clientAddress(){
            return clientAddress;
        }
        string get_clientPhone(){
            return clientPhone;
        }
        string get_clientPassword(){
            return clientPassword;
        }
        int get_clientID(){
            return clientID;
        }
        
        Transaction get_Transaction(){
            return arr[5];
        }
        
        //Display Method:
        void display_client_info(){
            cout<<"************ Displaying Client's Information ************"<<endl;
            cout<<"|Name:                "<<clientName<<endl;
            cout<<"|Email:               "<<clientEmail<<endl;
            cout<<"|Phone:               "<<clientPhone<<endl;
            cout<<"|Address:             "<<clientAddress<<endl;
            cout<<"|ID:                  "<<clientID<<endl;
            cout<<"*********************************************************"<<endl;
        }
};

template <class T>
class clientNode{
    public:
        Client data;
        clientNode<T>* next;
        
        clientNode(){
            data = 0;
            next = nullptr;
        }

        clientNode(Client D){
            data = D;
            next = nullptr;
        }
};

template <class T>
class clientList: public Client{
	clientNode<T>* head;
	int listSize;
	public: 
    	clientList(){
    	    head= NULL;
    	}
    	
        clientNode<T>* headptr[10];
        int size=0; // The size of the array of transactions
        
        void createTransaction(){
            string transName, transDate;
            int transID;
            cout<<"Kindly enter the transaction Name:";
            cin>>transName;
            arr[size].set_transactionName(transName);
            cout<<"Kindly enter the transaction Date:";
            cin>>transDate;
            arr[size].set_transactionDate(transDate);
            cout<<"Kindly enter the transaction ID:";
            cin>>transID;
            arr[size].set_transactionID(transID);
            for (int i=0; i<size; i++){
                if (arr[i].get_transactionID() == arr[size].get_transactionID()){
                    cout<<"This ID already Exist!"<<endl;
                    return;
                }else{
                    arr[size].set_transactionID(transID);
                }
            }
            size++;
            cout<<"The Transaction is added SUCCESSFULLY!"<<endl;
            if (size==5 || size>5){
                cout<<"You can't add more than 5 transactions!"<<endl;
            }
        }
        
        void printTransaction(int size){
            for (int i=0; i<size; i++){
                cout<<"All Transactions Display:"<<endl;
                cout<<"Transaction number"<< i+1 <<":"<<endl;
                arr[i].display_transaction_info();
            }
            if (size==0){
                cout<<"No Previous transactions were made!"<<endl;
            }
            cout<<"Transaction Display is Done"<<endl;
        }
        
        void deleteTransaction(){
            int deleteTransID, flag=0;
            cout<<"Please enter the ID of the transaction you want to delete"<<endl;
            cin>>deleteTransID;
            for (int i=0; i<size; i++){
                if (arr[i].get_transactionID() == deleteTransID){
                    for(int j=i; j<(size-1); j++)
                        arr[j] = arr[j+1];
                    flag=1;
                    i--;
                    size--;
                    cout<<"The Transaction is Deleted Successfully!"<<endl;
                }
            }
            if (flag==0){
                cout<<"This ID isn't present"<<endl;
            }
            
        }
        
        //////////=======================================================
        void newClientMenu(T data){
    		clientNode<T>* newNode = new clientNode<T>(data);
    		newNode->data.set_clientID(generateID());
            if(headptr[newNode->data.get_clientID()%10] == NULL){
                cout<<"Enter The Client's Name: ";
                cin>>clientName;
                newNode->data.set_clientName(clientName);
                
                cout<<"Enter The Client's Phone Number: ";
                cin>>clientPhone;
                newNode->data.set_clientPhone(clientPhone);
        
                cout<<"Enter The Client's Address: ";
                cin>>clientAddress;
                newNode->data.set_clientAddress(clientAddress);
                
                cout<<"Enter The Client's Password: ";
                cin>>clientPassword;
                newNode->data.set_clientPassword(clientPassword);
                
                cout<<"Enter The Client's Email: ";
                cin>>clientEmail;
                newNode->data.set_clientEmail(clientEmail);
                
                for(int i=0; i<10; i++){
                    clientNode<T>* tmpe = headptr[i];
                    while(tmpe!= NULL){
                        if ( tmpe->data.get_clientEmail()==newNode->data.get_clientEmail()){
                            cout<<"Email already exists!, Please try again!"<<endl;
                            delete newNode;
                            return;
                        }
                        tmpe= tmpe->next;
                    }
                }
                cout<<"\t======The Record Is Added SUCCESSFULLY To The List!======"<<endl;
                
                headptr[newNode->data.get_clientID()%10]=newNode;
                return;
            }
            
            ///===================================================
            
            cout<<"Enter The Client's Name: ";
            cin>>clientName;
            newNode->data.set_clientName(clientName);
    
            cout<<"Enter The Client's Phone Number: ";
            cin>>clientPhone;
            newNode->data.set_clientPhone(clientPhone);
    
            cout<<"Enter The Client's Address: ";
            cin>>clientAddress;
            newNode->data.set_clientAddress(clientAddress);
            
            cout<<"Enter The Client's Password: ";
            cin>>clientPassword;
            newNode->data.set_clientPassword(clientPassword);
                
            cout<<"Enter The Client's Email: ";
            cin>>clientEmail;
            newNode->data.set_clientEmail(clientEmail);
            
            for(int i=0; i<10; i++){
                clientNode<T>* tmpe = headptr[i];
                while(tmpe!= NULL){
                    if ( tmpe->data.get_clientEmail()==newNode->data.get_clientEmail()){
                        cout<<"Email already exists!, Please try again!"<<endl;
                        delete newNode;
                        return;
                    }
                    tmpe= tmpe->next;
                }
            }
            clientNode<T>* tmp1 = headptr[newNode->data.get_clientID()%10];
            while(tmp1->next != nullptr){
                tmp1 = tmp1->next;
            }
            cout<<"\t======The Record Is Added SUCCESSFULLY To The List!======"<<endl;
            tmp1->next = newNode;
            return;
        } 
        
        void forgotPassword(T data){
            clientNode<T>* newNode = new clientNode<T>(data);
            cout<<"Enter Your Email to recover the password: ";
            cin>>clientEmail;
            newNode->data.set_clientEmail(clientEmail);
            
            for(int i=0; i<10; i++){
                clientNode<T>* tmpe = headptr[i];
                while(tmpe!= NULL){
                    if ( tmpe->data.get_clientEmail()==newNode->data.get_clientEmail()){
                        cout<<"Your email is: ";
                        cout<<tmpe->data.get_clientEmail()<<endl;
                        cout<<"Your password is: ";
                        cout<<tmpe->data.get_clientPassword()<<endl;
                        return;
                    }
                    tmpe= tmpe->next;
                }
            }
            return;
        } 
        
        void clientHome(clientNode<T>* data){
            cout<<"===================================================================="<<endl;
            cout<<"++++++++++++++++++++ Welcome to the Banking System++++++++++++++++++"<<endl;
            cout<<"++++++++++++++++++++ Create a new client account  ++++++++++++++++++++"<<endl;
            int ans;
            do{
                cout<<"CHOOSE ONE OF THE FOLLOWING OPTIONS"<<endl;
                cout << "1. Transaction Menu" << endl;
                cout << "2. View Personal Info" << endl;
                cout << "3. Logout" << endl;
                cin>>ans;
                switch(ans){
                    case 1:{
                        transactionMenu();
                        break;
                    }
                    case 2:{
                        Print1Client(data);
                        break;
                    }
                    case 3:{
                        cout<<"You logged out of the Client Home!"<<endl;
                    }
                    default:{
                        cout<<"Please enter a valid number"<<endl;
                        break;
                    }
                }
            }while(ans!=3);
        }
        
        void transactionMenu(){
            cout<<"===================================================================="<<endl;
            cout<<"++++++++++++++++++++ Welcome to the Banking System++++++++++++++++++"<<endl;
            cout<<"++++++++++++++++++++ Welcome to the transaction system  ++++++++++++++++++++"<<endl;
            int ans;
            do{
                cout<<"CHOOSE ONE OF THE FOLLOWING OPTIONS"<<endl;
                cout << "1. Create a new transaction" << endl;
                cout << "2. View your transactions" << endl;
                cout << "3. Delete a transaction by its ID" << endl;
                cout << "4. Exit This Menu" << endl;
                cin>>ans;
                switch(ans){
                    case 1:{
                        createTransaction();
                        break;
                    }
                    case 2:{
                        printTransaction(size);
                        break;
                    }
                    case 3:{
                        deleteTransaction();
                        break;
                    }
                    default:{
                        cout<<"You logged out of the Transaction Home!"<<endl;
                        break;
                    }
                }
            }while(ans!=4);
        }
        
        void loginMenu(T data){
            cout<<"===================================================================="<<endl;
            cout<<"++++++++++++++++++++ Welcome to the Banking System++++++++++++++++++"<<endl;
            cout<<"++++++++++++++++++++ Welcome back dear client+++++++++++++++++"<<endl; 
            clientNode<T>* newNode = new clientNode<T>(data);
            cout<<"Please enter your Email: ";
            cin>>clientEmail;
            newNode->data.set_clientEmail(clientEmail);
                
            cout<<"Enter The Client's Password: ";
            cin>>clientPassword;
            newNode->data.set_clientPassword(clientPassword);
            
            for(int i=0; i<10; i++){
                clientNode<T>* tmpe = headptr[i];
                while(tmpe!= NULL){
                    if (tmpe->data.get_clientEmail()==newNode->data.get_clientEmail() && tmpe->data.get_clientPassword()==newNode->data.get_clientPassword()){
                        cout<<"YOU LOGGED IN SUCCESSFULY!"<<endl;
                        clientHome(newNode);
                        return;
                    }
                    tmpe= tmpe->next;
                }
            }
            cout<<"This email doesn't exist. Please try again!"<<endl;
        }
        
        bool Print1Client(clientNode<T>* data){
            for (int i=0; i<10; i++){
                clientNode<T>* tmp=headptr[i];
                while(tmp!=NULL){
                    if (tmp->data.get_clientEmail()== data->data.get_clientEmail()){
                        tmp->data.display_client_info();
                    }
                    tmp=tmp->next;
                }
                
            }
            return true;
        }
        
        ///////==========================================================
        
        int partition (int arr[], int low, int high) { 
            int pivot = arr[high]; 
            clientNode<T>* headtmp = headptr[high];
            int lowindex = low;
            int lowheadindex = low;
            
            for (int i=low; i<high; i++){
                if (arr[i]<pivot){
                    int temp=arr[i];
                    clientNode<T>*tmp = headptr[i];
                    arr[i] = arr[lowindex]; 
                    headptr[i] = headptr[lowheadindex];
                    arr[lowindex] = temp;
                    headptr[lowheadindex] = tmp;
                    lowindex++;
                    lowheadindex++;
                }
            }
            int temp = arr[high];
            clientNode<T>* tmp = headptr[high];
            arr[high] = arr[lowindex];
            headptr[high] = headptr[lowheadindex];
            arr[lowindex] = temp;
            headptr[lowheadindex] = tmp;
            return lowindex;
        } 
        
        void quickSort(int arr[], int low, int high){ 
            if (low < high) { 
                int pivot = partition(arr, low, high); 
                quickSort(arr, low, pivot - 1); 
                quickSort(arr, pivot + 1, high); 
            } 
        } 
        
        bool SortAllClients(){
            int linesize[10];
            for (int i=0; i<10; i++){
                linesize[i]=0;
                clientNode<T>* tmp=headptr[i];
                cout<<"Line Output: "<<i<<endl;
                while(tmp!=NULL){
                    tmp->data.display_client_info();
                    linesize[i]++;
                    tmp=tmp->next;
                }
            }
            
            cout<<"======================================"<<endl;
            cout<<"Printing the size of each line"<<endl;
            for (int i=0; i<10; i++){
                cout<<linesize[i]<<" ";
            }
            cout<<endl;
            ////////////////////////////////
            quickSort(linesize, 0, 10-1); 
            ///////////////////////////////
            cout<<"======================================"<<endl;
            cout<<"After sorting: "<<endl;
            for (int i=0; i<10; i++){
                cout<<linesize[i]<<" ";
            }
            cout<<endl;
            cout<<"======================================"<<endl;
            for (int i=0; i<10; i++){
                linesize[i]=0;
                clientNode<T>* tmp=headptr[i];
                cout<<"Line Output: "<<i<<endl;
                while(tmp!=NULL){
                    tmp->data.display_client_info();
                    linesize[i]++;
                    tmp=tmp->next;
                }
            }
            
            return true;
        }
        
        
        ///BONUS PART!!
        void SortIDs(){
            clientNode<T>* tmp=headptr[10];
            int listsize[10];
            for (int i=0; i<10; i++){
                listsize[i]=0;
                while(tmp!=NULL){
                    listsize[i]++;
                    tmp=tmp->next;
                }
            }
            clientNode<T>* sort= headptr[10];
            for (int s=0; s<10; s++){
                while(sort!=NULL){
                    for (int j = 0; j < listsize[s] - 1; ++j) {
                        for (int i = 0; i < listsize[s] - j - 1; ++i) {
                            if (sort->data.get_clientID() > sort->next->data.get_clientID() ){
                                Client temp = sort->data;
                                sort->data = sort->next->data;
                                sort->next->data = temp;
                            }
                        }
                    }
                }
            }
            for (int i=0; i<10; i++){
                clientNode<T>* tmp=headptr[i];
                cout<<"Line Output: "<<i<<endl;
                while(tmp!=NULL){
                    tmp->data.display_client_info();
                    tmp=tmp->next;
                }
            }
        }
};

int main(){
    Client emp;
    clientList<Client> ll;
    int ans;
    do{
        cout<<"===================================================================="<<endl;
        cout<<"++++++++++++++++++++ Welcome to the Banking System++++++++++++++++++"<<endl;  
        cout<<"CHOOSE ONE OF THE FOLLOWING OPTIONS"<<endl;
        cout << "1. Login to your account" << endl;
        cout << "2. New client?" << endl;
        cout << "3. Forgot your password?" << endl;
        cout << "4. Sort clients by linked list size using the Quick Sort Algorithm"<<endl;
        cout << "5. Sort the IDs (BONUS)"<<endl;
        cout << "6. Exit the program"<<endl;
        cin>>ans;
        switch(ans){
            case 1:{
                ll.loginMenu(emp);
                break;
            }
            case 2:{
                ll.newClientMenu(emp);
                break;
            }
            case 3:{
                ll.forgotPassword(emp);
                break;
            }
            case 4:{
                ll.SortAllClients();
                break;
            }
            case 5:{
                ll.SortIDs();
                break;
            }
            case 6:{
                cout<<"Thank you for using our Banking System!"<<endl;
                cout<<"See you next Time!!"<<endl;
            }
            default:{
                cout<<"Please enter a valid number!"<<endl;
                break;
            }
        }
    }while(ans!=6);
    return 0;
}