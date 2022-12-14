//Map Associative Container

#include<iostream>
#include<map>
#include<cstring>
using namespace std;
typedef map<string,int> popmap;
int main()
{
    popmap popu; 
    popu.insert(pair<string,int>("Maharashtra",125));
    popu.insert(make_pair("MadhyaPradesh",90));
    popu.insert(popmap::value_type("Bihar",120));
    popu.insert(popmap::value_type("UttarPradesh",150));
    popu.insert(make_pair("Jharkhand",95));
    popu.insert(pair<string,int>("WestBengal",110)); 

    popmap::iterator p=--popu.end();  // iterator p for map container 
    popu.erase(p); // removing the last entry from the database
    
    cout<<"Total no. of states in the database: "<<popu.size()<<endl;
    
    for(p=popu.begin();p!=popu.end();p++){
        cout<<p->first<<":"<<p->second<<" million"<<"\n";
    }
    string s;
    int n;
    cout<<"Enter name: ";
    cin>>s;
    n=popu[s];
    cout<<"\nPopulation: "<<n<<" million"<<endl;
    cout<<"End";
    return 0;
}
