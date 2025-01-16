#include "student.cpp"

int main()
{
    vector<student*> studentList;
    int choice1, choice2;
    while(true)
    {
        
        cout << "1. Student Registration\n2. Student Information System\n3. exit\n";
        cout << "Enter your choice: ";
        cin >> choice1;

        switch (choice1)
        {
            case 3:
                exit(0);
            case 1:
                {cout << "enter student name: ";
                string name;
                int age;
                cin >> name;
                cout << "enter student age: ";
                cin >> age;
                student* s1 = new student(name, age);
                studentList.push_back(s1);
                break;}
            
            case 2:
               {
                cout << "Enter your Roll No.: ";
                int roll;
                cin >> roll;
                if(roll >= studentList.size())
                    cout << "user not exist\n";
                else
                {
                    student* user = studentList[roll];
                    cout << "User Found !!!\n";
                    cout << "\t\tWelcome " << user->getName() << " !!!\n";
                    bool flag = true;
                    
                    while(flag)
                    {
                        bool loginChk = user->loginStatus();
                        if(!loginChk)
                        {
                            
                            cout << "1. getDetails\n2. Login\n3. Forget Password\n4. Main menu\n5. Terminate Program\n6. Change password\n7. Switch User\n";
                            cout << "Enter your choice: ";
                            cin >> choice2;
                            switch(choice2)
                            {
                                case 1:
                                {
                                    user->getDetails();
                                    break;
                                }
                                case 2:
                                {
                                    user->login(roll);
                                    break;
                                }
                                case 3:
                                {
                                    user->forgetPwd();
                                    break;
                                }
                                case 4:
                                {
                                    flag = false;
                                    break;
                                }
                                case 5:
                                {
                                    exit(0);
                                }
                                case 6:
                                {
                                    user->changePwd();
                                    break;
                                }
                                case 7:
                                {
                                    cout << "Enter your Roll No.: ";
                                    int tempRoll;
                                    cin >> tempRoll;
                                    if(tempRoll >= studentList.size())
                                        cout << "user not exist\n";
                                    else
                                    {
                                        roll = tempRoll;
                                        user = studentList[roll];
                                        cout << "User Found !!!\n";
                                        cout << "\t\tWelcome " << user->getName() << " !!!\n";
                                    }
                                    break;
                                }
                                default:
                                {
                                    cout << "invalid input";
                                    break;
                                }

                            }
                        }
                        else
                        {
                            cout << "Logged in as " << user->getName() << endl;
                            cout << "1. modifyDetails\n2. Change Password\n3. Forget Password\n4. Logout\n5. Terminate Program\n";
                            cout << "Enter your choice: ";
                            cin >> choice2;

                            switch(choice2)
                            {
                                case 1:
                                {
                                    user->modifyDetails();
                                    break;
                                }
                                case 2:
                                {
                                    user->changePwd();
                                    break;
                                }
                                case 3:
                                {
                                    user->forgetPwd();
                                    break;
                                }
                                case 4:
                                {
                                    user->logout();
                                    break;
                                }
                                case 5:
                                {
                                    exit(0);
                                }
                                default:
                                {
                                    cout << "invalid input";
                                    break;
                                }

                            }

                        }
                        
                    }
                }
                break;
                }
            
            default:
                return 0;
        }
    }

    
}

