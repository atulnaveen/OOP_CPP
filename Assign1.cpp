/*Mathematical Operations on Complex Numbers*/
#include<iostream>
using namespace std;
class complex
{
  float x,y;
  public:
   complex operator +(complex);
   complex operator -(complex);
   complex operator *(complex);
   complex operator /(complex);
   friend istream & operator >>(istream &input,complex &t)
   {
    cout<<"Enter Real Part:";
    cin>>t.x;
    cout<<"Enter Imaginary Part:";
    cin>>t.y;
   }
   friend ostream & operator <<(ostream &output,complex &t)
   {
    output<<t.x<<"+"<<t.y<<"i"<<endl;
   }
};
complex complex::operator +(complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return(temp);
}
complex complex::operator -(complex c)
{
    complex temp;
    temp.x=x-c.x;
    temp.y=y-c.y;
    return(temp);
}
complex complex::operator *(complex c)
{
    complex temp;
    temp.x=(x*c.x)-(y*c.y);
    temp.y=(y*c.x)+(x*c.y);
    return(temp);
}
complex complex::operator /(complex c)
{
    complex temp;
    temp.x=((x*c.x+y*c.y)/((c.x*c.x)+(c.y*c.y)));
    temp.y=((y*c.x-x*c.y)/((c.x*c.x)+(c.y*c.y)));
    return(temp);
}
int main()
{   complex c1,c2,c3,c4,c5,c6;
    //cout<<"Default complex number is:"<<c1<<endl;
    cout<<"Enter first complex number"<<endl;
    cin>>c1;
    cout<<"Enter the second complex number"<<endl;
    cin>>c2;
    cout<<"-----------------------------------"<<endl;
    cout<<"Complex numbers are:\n"<<c1<<c2<<endl;
    c3=c1+c2;
    cout<<"Addition: "<<c3;
    c4=c1-c2;
    cout<<"Subtraction: "<<c4;
    c5=c1*c2;
    cout<<"Multiplication: "<<c5;
    c6=c1/c2;
    cout<<"Division: "<<c6;
    return 0;
}