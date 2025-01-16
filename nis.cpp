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
                {
                    student* s1 = new student();
                    studentList.push_back(s1);
                    break;
                }
            
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
                            
                            cout << "1. Get User Details\n2. Login\n3. Forgot Password\n4. Switch User\n5. Main menu\n6. Terminate Program\n";
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
                                case 5:
                                {
                                    flag = false;
                                    break;
                                }
                                case 6:
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
                        else
                        {
                            cout << "Logged in as " << user->getName() << endl;
                            cout << "1. Get User Details\n2. Modify Details\n3. Change Password\n4. Logout\n5. Terminate Program\n";
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
                                    user->modifyDetails();
                                    break;
                                }
                                case 3:
                                {
                                    user->changePwd();
                                    break;
                                }
                                case 4:
                                {
                                    user->logout();
                                    break;
                                }
                                case 5:
                                {
                                    user->logout();
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
                cout << "invalid input, enter a valid choice...\n";
        }
    }

    
}

