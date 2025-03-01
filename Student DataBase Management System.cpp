#include<iostream>
using namespace std;

struct StudentDataBase{
    char Name[100],LastName[100],Class[100],Phone[100],Email[100];
    int ID,Calculas,Programming,English,Computer,DLD;
};

//Function to Store Student Data
void SDBMS(int N);

//Function to Show all Student Data
void DisplaySD();

int main(){
    //Create File
    FILE *SDMS;
    //open file
    SDMS = fopen("Student DataBase Management System.txt","w");
    //Write text in file
    fprintf(SDMS,"\t------: Welcome to Student DataBase Management System :------\n");
    //close file
    fclose(SDMS);
    cout<<endl<<"\t------: Welcome to Student DataBase Management System :------"<<endl;
    cout<<"\t=============================================================";
    cout<<endl<<"\t=========----:Student DataBase Management System:---=========="<<endl;
    //There Are Menu to Choice
    int Condition=0,Choice;
    while(Condition !=  1){
        cout<<"======================================="<<endl;
        cout<<"Menu:"<<endl;
        cout<<"------"<<endl;
        cout<<"1 : Add Student Data:"<<endl;
        cout<<"2 : Search for Student by ID:"<<endl;
        cout<<"3 : Display All Student All Data:"<<endl;
        cout<<"4 : Exit Program:"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"Enter Choice : ";
        cin>>Choice;
    switch(Choice){

    case 1:
    //Add Student Details
    SDBMS(Choice);
    break;
    case 2:
    //Search by Id to Find Student Details
    SDBMS(Choice);
    break;
    case 3:
    //Show All Student Details
    DisplaySD();
    break;
    case 4:
    cout<<"----------------------------"<<endl;
    cout<<"Program Exit Successfully."<<endl;
    cout<<"----------------------------"<<endl;
    Condition = 1;
    break;
    default:
    cout<<"Try Again Enter Correct Choice";
    break;
    }
    }
return 0;
}

void SDBMS(int N){
    FILE *SDMS;
    //Open File
    SDMS = fopen("Student DataBase Management System.txt","a");
    //Student Information System
    //MAX Student is 100
    struct StudentDataBase SDS[100];
    // If N is 1 You can Add Student Details
    if(N == 1){
    int Number;
    cout<<"Enter Student Number : ";
    cin>>Number;

    for(int i=0;i<Number;i++){
    cout<<"--:Enter "<<i+1<<" Student Information System:--"<<endl;
    cout<<"Enter Name : ";
    cin>>SDS[i].Name;
    cout<<"Enter Last Name : ";
    cin>>SDS[i].LastName;
    cout<<"Enter ID : ";
    cin>>SDS[i].ID;
    cout<<"Enter Phone Number : ";
    cin>>SDS[i].Phone;
    cout<<"Enter Email : ";
    cin>>SDS[i].Email;
    cout<<"Enter Class : ";
    cin>>SDS[i].Class;
    cout<<"Enter Calculas Marks : ";
    cin>>SDS[i].Calculas;
    cout<<"Enter Programming Marks : ";
    cin>>SDS[i].Programming;
    cout<<"Enter English Marks : ";
    cin>>SDS[i].English;
    cout<<"Enter Computer Marks : ";
    cin>>SDS[i].Computer;
    cout<<"Enter DLD Marks : ";
    cin>>SDS[i].DLD;
    //Data Save in File
    fprintf(SDMS,"|-----------------------|%s| Information -----------------------|\n",SDS[i].Name);
    fprintf(SDMS,"Name      : %s\nLast Name : %s\nID    : %d\nPhone : %s\nEmail : %s\nClass : %s\n",SDS[i].Name,SDS[i].LastName,SDS[i].ID,SDS[i].Phone,SDS[i].Email,SDS[i].Class);
    fprintf(SDMS,"Calculas Mark    : %d\nProgramming Mark : %d\nEnglish Mark     : %d\nComputer Mark    : %d\nDLD Mark         : %d\n",SDS[i].Calculas,SDS[i].Programming,SDS[i].English,SDS[i].Computer,SDS[i].DLD);
    fprintf(SDMS,"....................................................\n");
    int Total=SDS[i].Calculas+SDS[i].Programming+SDS[i].English+SDS[i].Computer+SDS[i].DLD,Percentage=Total/5;
    fprintf(SDMS,"Total Mark : %d\n",Total);
    fprintf(SDMS,"....................................................\n");
    fprintf(SDMS,"Percentage : %d%\n",Percentage);
    fprintf(SDMS,"....................................................\n");
    }
    fclose(SDMS);
    //if N is 2 You can Search by ID
    }else if(N == 2){
    int ID;
    cout<<"Enter  Student ID : ";
    cin>>ID;
    for(int i=0;i<ID;i++){
    if(ID == SDS[i].ID){
    cout<<"|-----------------------"<<SDS[i].Name<<"- Information -----------------------|\n";
    cout<<"Name      : "<<SDS[i].Name<<endl;
    cout<<"Last Name : "<<SDS[i].LastName<<endl;
    cout<<"ID        : "<<SDS[i].ID<<endl;
    cout<<"Phone     : "<<SDS[i].Phone<<endl;
    cout<<"Email     : "<<SDS[i].Email<<endl;
    cout<<"Class     : "<<SDS[i].Class<<endl;
    cout<<"...................................................."<<endl;
    cout<<"Calculas Marks    : "<<SDS[i].Calculas<<endl;
    cout<<"Programming Marks : "<<SDS[i].Programming<<endl;
    cout<<"Computer Marks    : "<<SDS[i].Computer<<endl;
    cout<<"English Marks     : "<<SDS[i].English<<endl;
    cout<<"DLD Marks         : "<<SDS[i].DLD<<endl;
    cout<<"...................................................."<<endl;
    int Total=SDS[i].Calculas+SDS[i].Programming+SDS[i].English+SDS[i].Computer+SDS[i].DLD,Percentage=Total/5;
    cout<<"Total Mark : "<<Total<<endl;
    cout<<"...................................................."<<endl;
    cout<<"Percentage : "<<Percentage<<endl;
    cout<<"...................................................."<<endl;
    }
    }
    }
}

void DisplaySD(){
    FILE *SDMS;
    SDMS = fopen("Student DataBase Management System.txt","r");
    char File=fgetc(SDMS);
    while(File != EOF){
        cout<<File;
        File=fgetc(SDMS);
    }
    fclose(SDMS);
}
