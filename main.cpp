#include<iostream>
#include<cmath>
#include"Class SavingAccount.h"
using namespace std;

int main()
{
    //建立几个账户
    SavingAccount sa0(1,21325302,0.015);
    SavingAccount sa1(1,58320212,0.015);
    //几笔账务
    sa0.deposit(5,5000);
    sa1.deposit(25,10000);
    sa0.deposit(45,5500);
    sa1.withdraw(60,4000);
    //开户后第90天为银行计息日，结算所有账户年息
    sa0.settle(90);
    sa1.settle(90);
    //输出账户信息
    sa0.show();
    sa1.show();
    cout<<"Total: "<<SavingAccount::getTotal()<<endl;
    return 0;
}
