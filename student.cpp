#include <bits/stdc++.h>
using namespace std;

class student
{
    private:
        string name="";
        int roll;
        static int currRoll;
        string pwd = "";
        bool isPasswordSet = false;
        bool isLogin = false;
        int age;
    
    public:
        
    student(string name, int age)
    {
        this->name = name;
        this->age = age;
        this->roll = currRoll++;
        cout << "Your assigned roll no is " << this->roll << endl;
    }

    student(string name, int age, string pwd)
    {
        this->name = name;
        this->age = age;
        this->roll = currRoll++;
        this->pwd = pwd;
        this->isPasswordSet = true;
        cout << "Your assigned roll no is " << this->roll << endl;
    }

    void setPassword()
    {
        string password;
        cout << "enter new password: ";
        cin >> password;
        this->pwd = password;
        cout << "Password set Successfully" << endl;
    }

    void login(int roll)
    {
        if(!this->isPasswordSet)
        {
            cout << "No password found in database" << endl;
            setPassword();
            cout << "kindly login using the password" << endl;
            this->isPasswordSet = true;
        }
        else
        {
            cout << "enter password: ";
            string password;
            cin >> password;
            if(password == pwd)
            {
                this->isLogin = true;
                cout << "login success" << endl;
            }
            else
            {
                cout << "wrong credintials, try forget Password" << endl;

            }
                
        }
    }

    void changePwd()
    {
        if(this->isLogin)
        {
            setPassword();
        }
        else
        {
            cout << "please login to change password" << endl;
        }
    }

    void logout()
    {
        if(this->isLogin)
        {
            cout << "logged out !!" << endl;
            this->isLogin = false;
        }
        else
            cout << "you are not logged in" << endl;
    }

    void getDetails()
    {
        
        cout << "============================" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Roll No: " << this->roll << endl;
        cout << "Age: " << this->age << endl;
        cout << "============================" << endl;
    }

    int getRoll()
    {
        return this->currRoll;
    }

    void help()
    {
        cout << "available commands are:  setPassword(), Login(roll),logout(), changePwd(), forgetPwd(), getDetails()" << endl;
    }

    int loginStatus()
    {
        return this->isLogin;
    }

    void modifyDetails()
    {
        if(this->isLogin)
        {
            cout << "Enter New Name: " << endl;
            cin >> this->name;
            cout << "Enter age: " << endl;
            cin >> age;
        }
        else
        {
            cout << "login to modify details";
        }
    }

    string getName()
    {
        return this->name;
    }


};

int student::currRoll = 0;