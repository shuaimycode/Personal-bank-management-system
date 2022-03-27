#include <iostream>
#include<cmath>
#include"Class SavingAccount.h"
using namespace std;

double SavingAccount::total = 0;

SavingAccount:: SavingAccount( int date, int id, double rate )
 : lastdate(date),id(id),rate(rate),balance(0),accumulation(0)
{
    cout<<date<<"\t#"<<id<<"is created"<<endl;
}

void SavingAccount::record( int date, double amount )
{
    accumulation = accumulate( date );
    lastdate = date;
    amount = floor( amount * 100 + 0.5 ) / 100;
    balance += amount;
    total += amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingAccount::deposit( int date, double amount )
{
    record( date, amount );
}

void SavingAccount::withdraw( int date, double amount )
{
    if( amount > getBalance() )
    {
        cout<<"Error : not enough money"<<endl;
    }
    else
    {
        record( date, -amount );
    }
}

void SavingAccount::settle( int date )
{
    double interest = accumulate( date ) / 365 * rate;  //¼ÆËãÄêÏ¢
    if( interest != 0)
    {
        record( date, interest );
    }
    accumulation = 0;
}

void SavingAccount::show()
{
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}


