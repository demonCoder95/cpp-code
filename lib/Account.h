// Account class definition. This provides the public interface of the class and abstracts the implementation details

class Account{
    public:
        Account(int);   // constructor to initialize the initial balance
        void credit(int); // function to credit the account with a balance
        void debit(int); // function to debit the account with a balance
        int getBalance(); // function to get the current balance in Account
    private:
        int balance;
};