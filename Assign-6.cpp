//Vector Container for searching and sorting 

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//item class created 
class item{
  public:
    char name[10];
    int quantity,cost,code;
    bool operator==(const item& i1)
    {
        if(code==i1.code)
        return 1;
        return 0;
    }
    bool operator<(const item& i1)
    {
        if(code<i1.code)
        return 1;
        return 0;
    }
};
//end of the class item

vector<item>o1;      //vector declaration with object o1
//function declarations 
void print(item& i1); 
void display();
void insert();
void search();
void dlt();
bool compare(const item &i1, const item &i2)
{
    return i1.cost < i2.cost;
}
bool comp(const item &i1, const item &i2)
{
    return i1.code < i2.code;
}

void insert()  //data insertion 
{
    item i1;
    cout<<"\nEnter the item name:";
    cin>>i1.name;
    cout<<"\nEnter the quantity:";
    cin>>i1.quantity;
    cout<<"\nEnter the item cost:";
    cin>>i1.cost;
    cout<<"\nEnter the item code:";
    cin>>i1.code;
    o1.push_back(i1);   //push data into vector 
}

void display()    //display data
{
    for_each(o1.begin(),o1.end(),print);     
    
}
void print(item& i1)   //print every item
{   cout<<"\n--------------------";
    cout<<"\nItem Name:"<<i1.name;
    cout<<"\nItem Quantity:"<<i1.quantity;
    cout<<"\nItem Cost:"<<i1.cost;
    cout<<"\nItem Code:"<<i1.code;
    cout<<"\n--------------------";
}

void search()  //search item
{
    int x;
    vector<item>::iterator p;  //declaring iterator
    item i1;       //object of class item
    cin>>x;
    cout<<"\nEnter on what basis: 1. By Code 2. By Name";
    switch(x){
    case 1: cout<<"\nEnter the item code to be searched:";
            cin>>i1.code;
            p=find(o1.begin(),o1.end(),i1);   //iterating operation
            if(p==o1.end())
            cout<<"\nNot Found";
            else
            cout<<"\nFound";
            break;
    case 2: cout<<"\nEnter the item name:";
            cin>>i1.name;
            p=find(o1.begin(),o1.end(),i1);
            if(p==o1.end())
            cout<<"\nNot Found";
            else
             cout<<"\nFound";
            break;
            }
}

void dlt()  //delete item 
{
    vector <item>::iterator p; //declaring iterator 
    item i1;     //object of class item
    cout<<"\nEnter the item code to be deleted:";
    cin>>i1.code;
    p=find(o1.begin(),o1.end(),i1);   //iterating operation
    if(p==o1.end())
    {cout<<"\nNot Found";}
    else
    {o1.erase(p);   //erase function to delete the item
     cout<<"\nItem Deleted";
    }
}

//main function 
int main()
{
    int ch,w;
    do{
        cout<<"\n***** MENU *****";
        cout<<"\n1. Insert Item";
        cout<<"\n2. Display Item";
        cout<<"\n3. Search Item";
        cout<<"\n4. Sort Items";
        cout<<"\n5. Delete Item";
        cout<<"\n6. Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)  
        {
            case 1: insert();
                    break;
            case 2: display();
                    break;
            case 3: search();
                    break;
            case 4: { cout<<"Please select on what basis: 1. Cost 2. Code";
                      cin>>w;
                    switch(w)
                    {
                    case 1: sort(o1.begin(),o1.end(),compare);
                            cout<<"\n\nSorted on the basis of cost";
                            display();
                            break;
                    case 2: sort(o1.begin(),o1.end(),comp);
                            cout<<"Sorted on the basis of code";
                            display();
                            break;
                    }
            } break;
            case 5: dlt();
                    break;
            case 6: 
                    exit(0);
            default: cout<<"Invalid Input Given, Please Check Again";
        }
    } while(ch!=7);
return 0;
}

//EOP
