#ifndef Class SavingAccount_H_INCLUDED
#define Class SavingAccount_H_INCLUDED

class SavingAccount     //���ڴ���˻���
{
private:
    int id;                 //�˺�
    double balance;         //���
    double rate;            //������
    int lastdate;           //�ϴα������
    double accumulation;    //�����ۼ�֮��
    static double total;    //�����˻����ܽ��
    //��¼ÿһ���ˣ�dateΪ���ڣ�amountΪ���
    void record( int date, double amount );

    //��õ�ָ�����ڽ����ۼ��ܺ�
    double accumulate( int date ) const
    {
        return accumulation + balance * ( date - lastdate );
    }

public:
    SavingAccount( int date, int id, double rate );     //���캯��
    int getId() const { return id; }
    double getBalance() const { return balance; }
    double getRate() const { return rate; }
    static double getTotal() {  return total; }
    void deposit( int date, double amount );       //�����ֽ�
    void withdraw( int date, double amount );      //ȡ���ֽ�

    //������Ϣ��ÿ��1��1�յ��ô˺���
    void settle( int date );

    //��ʾ�˻���Ϣ
    void show();
};

#endif // 2_H_INCLUDED
