#include <iostream>
using namespace std;
int main()
{


    double marks[5];
    double cg[5];
    
    for(int i=0 ;i<5; i++){
        cout<<"Mark of Subject "<<i+1<<":";
        cin>>marks[i];
    }


    for(int i=0 ;i<5; i++){
        
        if (90<=marks[i]&&marks[i]<=100)
        {
        cout<<"The obtained number in Subject"<<i+1<<":"<<marks[i]<<endl;
        cout<<"The obtained grade in Subject"<<i+1<<": A+"<<endl;
        cg[i]=4.00;
        }

        else if (85<=marks[i]&&marks[i]<=89.99)
        {
        cout<<"The obtained number in Subject"<<i+1<<":"<<marks[i]<<endl;
        cout<<"The obtained grade in Subject"<<i+1<<": A"<<endl;
        cg[i]=3.75;
        }

        else if (80<=marks[i]&&marks[i]<=84.99)
        {
        cout<<"The obtained number in Subject"<<i+1<<":"<<marks[i]<<endl;
        cout<<"The obtained grade in Subject"<<i+1<<": B+"<<endl;
        cg[i]=3.50;
        }

        else if (75<=marks[i]&&marks[i]<=79.99)
        {
        cout<<"The obtained number in Subject"<<i+1<<":"<<marks[i]<<endl;
        cout<<"The obtained grade in Subject"<<i+1<<": B"<<endl;
        cg[i]=3.25;
        }

        else if (50<=marks[i]&&marks[i]<=59.99)
        {
        cout<<"The obtained number in Subject"<<i+1<<":"<<marks[i]<<endl;
        cout<<"The obtained grade in Subject"<<i+1<<": D"<<endl;
        cg[i]=2.25;
        }

        else if (0<=marks[i]&&marks[i]<=49.99)
        {
        cout<<"The obtained number in Subject"<<i+1<<":"<<marks[i]<<endl;
        cout<<"The obtained grade in Subject"<<i+1<<": F"<<endl;
        cg[i]=0.00;
        }


    }

    double CGPA;
    CGPA=(cg[0]+cg[1]+cg[2]+cg[3]+cg[4])/5;
    cout<<"Your average CGPA is= "<<CGPA<<endl<<endl;

    return 0;
}