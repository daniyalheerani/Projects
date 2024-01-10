#include <iostream>
#include<fstream>
#include<string> 
using namespace std;
struct storeData{
	int item_id;
	string item_name;
	float price_hrs,used_hrs;
};
class file_operations{
	public:
	int item_id;
	string item_name;
	float price_hrs,Amount,used_hrs;
	void storeData(int id, string name, float priceH, float usedH){
		fstream mf;
		mf.open("info.txt",ios_base::app);
		this->item_id=id;
		this->item_name=name;
		this->price_hrs=priceH;
		this->used_hrs=usedH;
		Amount=price_hrs*used_hrs;
		mf<<endl;
		mf<<item_id;
		mf<<endl;
		mf<<item_name;
		mf<<endl;
		mf<<price_hrs;
		mf<<endl;
		mf<<used_hrs;
		mf<<endl;
		mf<<Amount;
		mf<<endl;
		mf<<endl;
		mf.close(); 
	}
	void fetchData(){
		fstream infile;
		infile.open("info.txt",ios_base::in);
		infile>>item_id;
		infile>>item_name;
		infile>>price_hrs;
		infile>>used_hrs;
		infile>>Amount;
		cout<<"Item ID\tItem name\tPrice per hour\tused hours\tAmount"<<endl;
		while(!infile.eof()){
			cout<<item_id<<"\t"<<item_name<<"\t\t"<<price_hrs<<"\t\t"<<used_hrs<<"\t\t"<<Amount<<endl;
			infile>>item_id;
			infile>>item_name;
			infile>>price_hrs;
			infile>>used_hrs;
			infile>>Amount;
		}
		infile.close();
	}
	void editData(int id){
		int ID;
		string name;
		float price,used,amount;
		fstream infile;
		fstream mf;
		mf.open("t.txt");
		infile.open("info.txt");
		infile>>item_id;
		infile>>item_name;
		infile>>price_hrs;
		infile>>used_hrs;
		infile>>Amount;
		while(!infile.eof()){
			infile>>item_id>>item_name>>price_hrs>>used_hrs>>Amount;
			if(item_id != id){
				mf<<item_id<<endl;
				mf<<item_name<<endl;
				mf<<price_hrs<<endl;
				mf<<used_hrs<<endl;
				mf<<Amount<<endl;
			}
			else{
				cout<<"enter new id:";
				cin>>ID;
				cout<<"enter new item name:";
				cin>>name;
				cout<<"enter new price per hour:";
				cin>>price;
				cout<<"enter used hours:";
				cin>>used;
				amount=used*price;
				
				mf<<endl;
				mf<<ID;
				mf<<endl;
				mf<<name;
				mf<<endl;
				mf<<price;
				mf<<endl;
				mf<<used;
				mf<<endl;
				mf<<amount;
				mf<<endl;
				}
			infile>>item_id;
			infile>>item_name;
			infile>>price_hrs;
			infile>>used_hrs;
			infile>>Amount;	
		}
		mf.close();
		infile.close();
		if(remove("item.txt")!=0){
			cout<<"file did not removed."<<endl;
		}
		else{
			cout<<"ok. file removed."<<endl;
		}
		if(rename("t.txt","item.txt")!=0){
			cout<<"file did not renamed."<<endl;	
		}
		else{
			cout<<"file is renamed successfully."<<endl;
		}
	}
	void deleteData(int id){
		fstream infile;
		fstream mf;
		mf.open("temp.txt");
		infile.open("info.txt");
		infile>>item_id;
		infile>>item_name;
		infile>>price_hrs;
		infile>>used_hrs;
		infile>>Amount;
		while(!infile.eof()){
			infile>>item_id>>item_name>>price_hrs>>used_hrs>>Amount;
			if(item_id != id){
				mf<<item_id;
				mf<<endl;
				mf<<item_name;
				mf<<endl;
				mf<<price_hrs;
				mf<<endl;
				mf<<used_hrs;
				mf<<endl;
				mf<<Amount;
				mf<<endl;
			}
			else{
				cout<<"Record deleted!"<<endl;
			}
			infile>>item_id;
			infile>>item_name;
			infile>>price_hrs;
			infile>>used_hrs;
			infile>>Amount;	
		}
		mf.close();
		infile.close();
		if(remove("info.txt")!=0){
			cout<<"file did not removed."<<endl;
		}
		else{
			cout<<"ok. file removed."<<endl;
		}
		if(rename("temp.txt","info.txt")!=0){
			cout<<"file did not renamed."<<endl;
		}
		else{
			cout<<"file is renamed successfully."<<endl;
		}
	}
};

fstream mf;
int main(int argc, char** argv) {
	storeData s;
	int item_id;
	string item_name;
	float price_hrs,used_hrs;
	file_operations obj1,obj2;
	int choice;
	char option='y';
	while(1){
		cout<<"Which of the following tasks you want to perform: "<<endl;
		cout<<"1. Capture the user's input and save it to the file."<<endl;
		cout<<"2. Retrieve the information from the file and display it on the screen."<<endl;
		cout<<"3. Use ID to find a specific record and change any field of that record."<<endl;
		cout<<"4. Remove a record from a database."<<endl;
		cout<<"Enter your answer: ";
		cin>>choice;
		
		if(choice==1){
			while(option=='y'||option=='Y'){
				cout<<"Would you like to enter more data Y/N: ";
				cin>>option;
				if(option=='n'||option=='N'){
					mf.close();
					continue;
				}
			cout<<"Enter item ID: ";cin>>s.item_id;
			cout<<"Enter item Name: ";cin>>s.item_name;
			cout<<"Enter price per hour: ";cin>>s.price_hrs;
			cout<<"Enter quantity of hours used: ";cin>>s.used_hrs;
			item_id=s.item_id;
			item_name=s.item_name;
			price_hrs=s.price_hrs;
			used_hrs=s.used_hrs;
			obj1.storeData(item_id,item_name,price_hrs,used_hrs);
			}
			cout<<"If you want to perform any  other task then enter Y else enter N";
			char t;
			cin>>t;
			if(t=='N'||t=='n'){
				exit(0);
			}	
		}
		if(choice==2){
			obj1.fetchData();
			cout<<"If you want to perform any  other task then enter Y else enter N";
			char t;
			cin>>t;
			if(t=='N'||t=='n'){
				exit(0);
			}
		}
		if(choice==3){
			int id;
			cout<<"Enter ID to edit: ";cin>>id;
			obj1.editData(id);
			cout<<"If you want to perform any  other task then enter Y else enter N";
			char t;
			cin>>t;
			if(t=='N'||t=='n'){
				exit(0);
			}
		}
		if(choice==4){
			int id;
			cout<<"Enter ID to delete record: ";cin>>id;
			obj1.deleteData(id);
			cout<<"If you want to perform any  other task then enter Y else enter N";
			char t;
			cin>>t;
			if(t=='N'||t=='n'){
				exit(0);
			}
		}

	}
	
	
	return 0;
}
