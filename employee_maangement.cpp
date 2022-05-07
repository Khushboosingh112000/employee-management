#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct emp
{
    string name,id,address;
    string contact,sal;
};
emp e[100];
int total=0;
void empdata()
{
    int choice=0;
    cout<<"How many employess data do you want to enter??";
    cin>>choice;
    for(int i=total;i<choice+total;i++)
    {
        cout<<"Enter data"<<i+1<<endl;
        cout<<"Employee Name: ";
        cin>>e[i].name;
        cout<<"ID: ";
        cin>>e[i].id;
        cout<<"Address: ";
        cin>>e[i].address;
        cout<<"Contact:";
        cin>>e[i].contact;
        cout<<"salary:";
        cin>>e[i].sal;
        cout<<"\n";
    }
    total=total+choice;
}
void show()
{
    if(total!=0)
    {
        for(int i=0;i<total;i++)
        {
            cout<<"Data of employee"<<i+1<<endl;
            cout<<"Employee Name:"<<e[i].name<<endl;
            cout<<"ID:"<<e[i].id<<endl;
            cout<<"Address :"<<e[i].address<<endl;
            cout<<"Salary:"<<e[i].sal<<endl;
            cout<<"Contact:"<<e[i].contact<<endl;
        }
    }
    else
    {
        cout<<"Your record is empty"<<endl;
    }
}
void search()
{
    if(total!=0)
    {
        string id;
        cout<<"Enter id of data which you want to search"<<endl;
        cin>>id;
        for(int i=0;i<total;i++)
        {
            if(id==e[i].id)
            {
                cout<<"Data of employee"<<i+1<<endl;
                cout<<"Employee Name:"<<e[i].name<<endl;
                cout<<"ID:"<<e[i].id<<endl;
                cout<<"Address :"<<e[i].address<<endl;
                cout<<"Salary:"<<e[i].sal<<endl;
                cout<<"Contact:"<<e[i].contact<<endl;  
                break;  
            }
            if(i==total-1)
            {
                cout<<"No such record found"<<endl;
            }
        }
    }
    else
    {
        cout<<"Your record is empty"<<endl;
    }
}
void update()
{
    if(total!=0)
    {
        string id;
        cout<<"Enter id of data which you want to update"<<endl;
        cin>>id; 
        for(int i=0;i<total;i++)
        {
            if(id==e[i].id)
            {
                cout<<"Previous Data"<<endl;
                cout<<"Data of employee"<<i+1<<endl;
                cout<<"Employee Name:"<<e[i].name<<endl;
                cout<<"ID:"<<e[i].id<<endl;
                cout<<"Address :"<<e[i].address<<endl;
                cout<<"Salary:"<<e[i].sal<<endl;
                cout<<"Contact:"<<e[i].contact<<endl;  
                cout<<"\nNew Data"<<endl;
                cout<<"Enter data"<<i+1<<endl;
                cout<<"Employee Name: ";
                cin>>e[i].name;
                cout<<"ID: ";
                cin>>e[i].id;
                cout<<"Address: ";
                cin>>e[i].address;
                cout<<"Contact";
                cin>>e[i].contact;
                cout<<"sal :";
                cin>>e[i].sal;  
                break;  
            }
            if(i==total-1)
            {
                cout<<"No such record found"<<endl;
            }
        }      
    }
    else
    {
        cout<<"your record is empty"<<endl;
    }
}
void del()
{
    if(total!=0)
    {
        char user;
        cout<<"Press 1 to delete full record"<<endl;
        cout<<"Press 2 to delete specific record"<<endl;
        user=getch();
        if(user=='1')
        {
            total=0;
            cout<<"All record is deleted"<<endl;
        }
        else if(user='2')
        {
            string id;
            cout<<"Enter id od data which u want to delete"<<endl;
            cin>>id;
            for(int i=0;i<total;i++)
            {
                if(id==e[i].id)
                {
                    for(int j=i;j<total;j++)
                    {
                        e[j].name=e[j+1].name;
                        e[j].id=e[j+1].id;
                        e[j].address=e[j+1].address;
                        e[j].contact=e[j+1].contact;
                        e[j].sal=e[j+1].sal;
                        total--;
                        break;
                    }
                    if(i==total-1)
                    {
                        cout<<"No such record found!!"<<endl;
                    }
                }
            }

        }
    }
    else
    {
        cout<<"Your record is empty"<<endl;
    }
}
int main()
{
    cout<<"\n \n \t \t Employee Management System"<<endl;
    cout<<"\n \n \t \t SIGN UP"<<endl;
    string username,password;
    cout<<"\n \n \t \t Enter username: ";
    cin>>username;
    cout<<"\n \n \t \t Enter password:";
    cin>>password;
    cout<<"\n \n \t \t Your id is creating please wait";
    for(int i=0;i<4;i++)
    {
        cout<<".";
        Sleep(1000);
    }
    cout<<"\n \n \t \t Your id is created successfully"<<endl;
    system("CLS");
    start:
    cout<<"\n \n \t \t Employee Management System"<<endl;
    cout<<"\n \n \t \t LOGIN"<<endl;
    string username1,password1;
    cout<<"Username:";
    cin>>username1;
    cout<<"Password:";
    cin>>password1;
    if(username1==username&& password1==password)
    {
        system("CLS");
        char user;
        while(1)
        {
            cout<<"Press 1 to enter data"<<endl;
            cout<<"Press 2 to show data"<<endl;
            cout<<"Press 3 to search data"<<endl;
            cout<<"Press 4 to update data"<<endl;
            cout<<"Press 5 to delete data"<<endl;
            cout<<"Press 6 to logout"<<endl;
            user=getch();
            switch(user)
            {
                case '1':
                empdata();
                break;
                case '2':
                show();
                break;
                case '3':
                search();
                break;
                case '4':
                update();
                break;
                case '5':
                del();
                break;
                case '6':
                goto start;
                break;
                default:
                cout<<"\a Invalid input"<<endl;
                break;
            }
        }
    }
    else if(username1!=username)
    {
        cout<<"Your username is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }
    else if(password1!=password)
    {
        cout<<"Your password is incorrect"<<endl;
        Sleep(3000);
        goto start;
    }
    return 0;
}