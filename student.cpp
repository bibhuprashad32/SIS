#include <bits/stdc++.h>
#include "picosha2.h"
using namespace std;

class student
{
    private:
        string name;
        int roll;
        string father;
        string mother;
        string DOB;
        string contact;
        string address;
        string blood;
        static int currRoll;
        string pwd;
        bool isPasswordSet = false;
        bool isLogin = false;
        // int otp = 1234;
        string token;
        int age;
        string email;
        string aadhar;

    string fetchToken() 
    {
        const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string randomString;
        srand(time(0));

        for (size_t i = 0; i < 32; ++i) 
        {
            randomString += characters[rand() % characters.size()];
        }

        return randomString;
    }
    
    string hashPassword(const std::string& password) 
    {
        return picosha2::hash256_hex_string(password);
    }

    void setPassword()
    {
        string password;
        cout << "enter new password: ";
        cin >> password;
        this->pwd = hashPassword(password);
        cout << "Password set Successfully" << endl;
        this->isPasswordSet = true;
        this->getToken();
    }

    void getToken()
    {
        string rawToken = fetchToken();
        
        cout << "\t====== WARNING! ======"<<endl;
        cout << "Your updated token is ===>>\t" << rawToken << "\t<<===" << endl;
        cout << "Keep this safe, it can be used for password recovery\n";
        cout << "Can be used for once" << endl << endl;
        this->token = hashPassword(rawToken);
    }

    void setEmail()
    {
        string emailAddress;
        bool isValid;
        cout << "Enter your email address: ";
        do
        {
            cin >> emailAddress;
            size_t atPos = emailAddress.find('@');
            size_t dotPos = emailAddress.find('.', atPos);
            isValid = (atPos != string::npos) && (dotPos != string::npos) && (atPos < dotPos) && (atPos + 1 != dotPos) && (dotPos != emailAddress.length()-1);
            if (!isValid)
            {
                cout << "Your email must contain a '@' symbol and a domain name (e.g. user@domain.com).\nPlease enter a valid email address: " << endl;
            }
        } while (!isValid);
        this->email = emailAddress;
    }

    void setDOB()
    {
        string dayStr, monthStr, yearStr;
        int day, month, year;
        do
        {
            cout << "Enter your birth year (1800-2200): ";
            cin >> yearStr;
            if (isDigitOnly(yearStr)) { year = stoi(yearStr);}
            else year = -1;
        } while (year < 1800 || year > 2200);

        do
        {
            cout << "Enter a month (1-12): ";
            cin >> monthStr;
            if (isDigitOnly(monthStr)) { month = stoi(monthStr);}
            else month = -1;
        } while (month < 1 || month > 12);

        do
        {
            cout << "Enter a day (1-31): ";
            cin >> dayStr;
            if (isDigitOnly(dayStr)) { day = stoi(dayStr);}
            else day = -1;
        } while (day < 1 || day > 31);

        this->DOB = to_string(day) + "/" + to_string(month) + "/" + to_string(year);


    }
    void setBlood()
    {
        string bt; //bloodtype
        const unordered_set<string> validBloodTypes = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-", "Unknown"};
        do
        {
            cout << "Enter a valid blood type (A+, A-, B+, B-, AB+, AB-, O+, O-, Unknown): ";
            cin >> bt;
        } while (validBloodTypes.find(bt) == validBloodTypes.end());
        this->blood = bt;
    }

    void setRoll()
    {
        cout << "Your assigned Roll No. is ";
        this->roll = currRoll++;
        cout << this->roll << endl;
    }

    void setAge()
    {
        string taStr;
        int ta; //tempAge
        cout << "Enter age: ";
        cin >> taStr;
        if (isDigitOnly(taStr)) { ta = stoi(taStr);}
        else ta = -1;
        while(ta <= 0 || ta > 150)
        {
            cout << "age must be +ve digit and not more than 150\n Enter Age: ";
            cin >> taStr;
            if (isDigitOnly(taStr)) { ta = stoi(taStr);}
            else ta = -1;
        }
        this->age = ta;
    }

    void setAadhar()
    {
        cout << "Please Enter your Aadhar Number: ";
        bool flag = true;
        string tc; //tempaadhar
        
        while(flag)
        {
            cin >> tc;
            flag = false;
            if (tc.length() != 12)
            {
                flag = true;
                cout << "please enter a 12 digit aadhar number: ";
                continue;
            }
            for (char c : tc)
            {
                if (!isdigit(c))
                {
                    flag = true;
                    cout << "aadhar number must contain digits only.\n";
                    break;
                }
            }

        }
        this->aadhar = tc;
    }

    void setContact()
    {
        cout << "Please Enter your Phone Number: ";
        bool flag = true;
        string tc; //tempContact
        
        while(flag)
        {
            cin >> tc;
            flag = false;
            if (tc.length() != 10)
            {
                flag = true;
                cout << "please enter a 10 digit number: ";
                continue;
            }
            for (char c : tc)
            {
                if (!isdigit(c))
                {
                    flag = true;
                    cout << "contact number must contain digits only.\n";
                    break;
                }
            }

        }
        this->contact = tc;
    }

    void setParents()
    {
        this->setFather();
        this->setMother();
    }

    void setFather()
    {
        string tf; //tempName
        cout << "Enter your father's full name: ";
        tf = this->takeInput();
        while(tf.length() <= 2)
        {
            cout << "Father's name can't have less than 2 characters.\n";
            cout << "Please enter full name: ";
            tf = "";
            tf = this->takeInput();
            // getline(cin, tn); // replace all with tn = this->takeInput();
        }
        this->father = tf;
    }

    void setMother()
    {
        string tm; //tempname
        cout << "Enter your mother's full name: ";
        tm = this->takeInput();
        while(tm.length() <= 2)
        {
            cout << "mother's name can't have less than 2 characters.\n";
            cout << "Please enter full name: ";
            tm = "";
            tm = this->takeInput();
            // getline(cin, tn);
        }
        this->mother = tm;
    }


    void setAddress()
    {
        string tn;
        cout << "Enter your full Address: ";
        tn = this->takeInput();
        while(tn.length() <= 2)
        {
            cout << "Enter a valid address: \n";
            tn = this->takeInput();
            // getline(cin, tn);
        }
        this->address = tn;
    }

    void setName()
    {
        string tn; //tempname
        cout << "Enter your full name: ";
        tn = this->takeInput();
        while(tn.length() <= 2)
        {
            cout << "Your name can't have less than 2 characters.\n";
            cout << "Please Enter your full name: ";
            tn = this->takeInput();
            // getline(cin, tn);
        }
        this->name = tn;
    }

    public:
        
    
    student()
    {
        setName();
        setAge();
        setContact();
        setEmail();
        setAddress();
        setParents();
        setDOB();
        setAadhar();
        setBlood();
        setRoll();
        getToken();
    }

    

    bool validatePwd(const string& rawPwd)
    {
        string hashedPwd;
        hashedPwd = hashPassword(rawPwd);
        if(hashedPwd == pwd) return true;
        else return false;
    }

    bool validateToken(const string& rawToken)
    {
        string hashedToken;
        hashedToken = hashPassword(rawToken);
        if(hashedToken == token) return true;
        else return false;
    }

    

    bool isDigitOnly(string str)
    {
        for (char c : str)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    

    string takeInput()
    {
        string s;
        // cin.ignore();
        if (cin.peek() == '\n') cin.ignore();
        getline(cin, s);
        return s;
    }

    

    

    void login(int roll)
    {
        if(!this->isPasswordSet)
        {
            cout << "No password found in database" << endl;
            // setPassword();
            cout << "kindly use forgot password using the token provided at the time of registration" << endl;
            // this->isPasswordSet = true;
        }
        else
        {
            cout << "enter password: ";
            string password;
            cin >> password;
            if(validatePwd(password))
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

    void forgetPwd()
    {
        if(this->isLogin)
        {
            cout << "you are already logged in, to change password try change Password" << endl;
        }
        // else if(!this->isPasswordSet)
        // {
        //     cout << "No password found in database" << endl;
        //     setPassword();
        //     cout << "kindly login using the password" << endl;
        //     this->isPasswordSet = true;
        // }
        else
        {
            cout << "enter token: ";
            string temp;
            cin >> temp;
            if(validateToken(temp))
            {
                setPassword();
            }
            else
            {
                cout << "oops wrong token" << endl;
            }
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
        cout << "Father's Name: " << this->father << endl;
        cout << "Mother's Name: " << this->mother << endl;
        if(this->isLogin) cout << "Date of Birth: " << this->DOB << endl;
        if(this->isLogin) cout << "Aadhar No.: " << this->aadhar << endl;
        else 
        {
            string maskedAadhar = "********" + this->aadhar.substr(this->aadhar.length() - 4);
            cout << "Aadhar No.: " << maskedAadhar << endl;
        }
        if(this->isLogin) cout << "Contact: " << this->contact << endl;
        else 
        {
            string maskedContact = "******" + this->contact.substr(this->contact.length() - 4);
            cout << "Contact: " << maskedContact << endl;
        }
        cout << "Address: " << this->address << endl;
        cout << "Blood Group: " << this->blood << endl;
        cout << "Age: " << this->age << endl;
        cout << "Email: " << this->email << endl;
        // if(this->isLogin) cout << "TOKEN: " << this->token << endl;
        cout << "============================" << endl;
    }


    int getRoll()
    {
        return this->currRoll;
    }

    // void help()
    // {
    //     cout << "available commands are:  setPassword(), Login(roll),logout(), changePwd(), forgetPwd(), getDetails()" << endl;
    // }

    int loginStatus()
    {
        return this->isLogin;
    }

    void modifyDetails()
    {
        if(this->isLogin)
        {
            // cout << "Enter New Name: " << endl;
            // cin >> this->name;
            // cout << "Enter age: " << endl;
            // cin >> age;
            // cout << "feature not available for now";
            int choice;
            
            bool flag = true;
            while(flag)
            {
                cout << "1. Change Name\n2. Change Age\n3. Change Contact\n4. Change Email\n5. Change Address\n6. Change Father Name\n7. Change Mother Name\n8. Change DOB\n9. Change Aadhar\n10. Change Blood Type\n11. Previous Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice)
                {
                    case 1:
                        setName();
                        break;
                    case 2:
                        setAge();
                        break;
                    case 3:
                        setContact();
                        break;
                    case 4:
                        setEmail();
                        break;
                    case 5:
                        setAddress();
                        break;
                    case 6:
                        setFather();
                        break;
                    case 7:
                        setMother();
                        break;
                    case 8:
                        setDOB();
                        break;
                    case 9:
                        setAadhar();
                        break;
                    case 10:
                        setBlood();
                        break;
                    case 11:
                        flag = false;
                        break;
                    default:
                        cout << "Invalid choice!\n";
                        break;
                }
            }


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