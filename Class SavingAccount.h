#ifndef Class SavingAccount_H_INCLUDED
#define Class SavingAccount_H_INCLUDED

class SavingAccount     //活期存款账户类
{
private:
    int id;                 //账号
    double balance;         //余额
    double rate;            //年利率
    int lastdate;           //上次变更日期
    double accumulation;    //余额按日累计之和
    static double total;    //所有账户的总金额
    //记录每一笔账，date为日期，amount为金额
    void record( int date, double amount );

    //获得到指定日期金额按日累计总和
    double accumulate( int date ) const
    {
        return accumulation + balance * ( date - lastdate );
    }

public:
    SavingAccount( int date, int id, double rate );     //构造函数
    int getId() const { return id; }
    double getBalance() const { return balance; }
    double getRate() const { return rate; }
    static double getTotal() {  return total; }
    void deposit( int date, double amount );       //存入现金
    void withdraw( int date, double amount );      //取出现金

    //结算利息，每年1月1日调用此函数
    void settle( int date );

    //显示账户信息
    void show();
};

#endif // 2_H_INCLUDED
