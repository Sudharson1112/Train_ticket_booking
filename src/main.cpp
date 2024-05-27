#include"main.hpp"
extern vector <ticket *>ticket_instances;
string g_date;
string checks;
bool is_num(string& input) {
    istringstream iss(input);
    int value;
    iss >> noskipws >> value;
    return iss.eof() && !iss.fail();
}
bool is_float(string& input) 
{
    istringstream iss(input);
    float value;
    iss >> noskipws >> value;
    return iss.eof() && !iss.fail();
}
int main()
{
    root_node=create_tree(root_node);
    user instance2("Radha",45,"male","arun");
    user instance4("Arunmozhi",45,"male","arun");
    user instance3("Arul1",34,"male","arul");
    user instance1("Arul2",34,"male","arul");
    insert(&instance2);
    cout<<"1"<<endl;
    insert(&instance3);
    cout<<"2"<<endl;
    insert(&instance1);
    cout<<"3"<<endl;
    insert(&instance4);
    cout<<"4"<<endl;
    while(true)
    {
        cout<<"1.sign up 2.login 3.exit "<<endl;
        int input;
        getline(cin,checks);
        if(is_num(checks))
        {
            input = stoi(checks);
        }
        else
        {
            cout<<"Invalid input"<<endl;
            continue;
        }
        if (input==1)
        {
            creator();
        }
        else if(input==2)
        {
            bool s=login();
            //cout<<s<<endl;
            if(s==1)
            {
                while (true)
                {
                    cout<<"1.Book ticket 2.Show ticket 3.Cancel ticket 4.logout"<<endl;
                    int a;
                    getline(cin,checks);
                    if(is_num(checks))
                    {
                        a = stoi(checks);
                    }
                    else
                    {
                        cout<<"Invalid input"<<endl;
                        continue;
                    }
                    if(a==1)
                    {
                     int date;
                     int month;
                     re1:
                    cout<<"enter the date"<<endl;
                    getline(cin,checks);
                    if(is_num(checks))
                    {
                        date = stoi(checks);
                    }
                    else
                    {
                        cout<<"Invalid input"<<endl;
                        goto re1;
                    }
                    re2:
                    cout<<"enter month"<<endl;
                    getline(cin,checks);
                    if(is_num(checks))
                    {
                        month = stoi(checks);
                    }
                    else
                    {
                        cout<<"Invalid input"<<endl;
                        goto re2; 
                    }
                    time_t t =time(nullptr);
                    tm* now = localtime(&t);
                    if((month<=now->tm_mon+4 ) && (month==now->tm_mon+1 ? ((date >= now->tm_mday ? true: false)): true )&& (date <= 31) && (date > 0))
                    {
                        g_date = to_string(date)+to_string(month);
                        show_stations();
                    }
                    else
                    {
                    cout<<"invalid month"<<endl;
                    }}
                    if(a==2)
                    {
                    cout<<"enter the ticket id"<<endl;
                    int id;
                    getline(cin,checks);
                    if(is_num(checks))
                    {
                        id = stoi(checks);
                    }
                    else
                    {
                        cout<<"Invalid input"<<endl;
                        continue;
                    }
                    for(int i=0;i<ticket_instances.size();i++)
                    {
                    if(ticket_instances[i]->ticket_id==id)
                    {
                    ticket_instances[i]->show_ticket();
                    }
                    }
                    }
                    if(a==3)
                    {
                    re3:
                    cout<<"enter the ticket id"<<endl;
                    int id;
                    getline(cin,checks);
                    if(is_num(checks))
                    {
                        id = stoi(checks);
                    }
                    else
                    {
                        cout<<"Invalid input"<<endl;
                        goto re3;
                    }
                    ticket_cancellation(id);
                    }
                    if(a==4)
                    {
                        break;
                    }
                }
        }
        else{
            cout<<"incorrect credentials"<<endl;
            continue;
        }
        }
        else if(input==3)
        {
            break;
        }
        }
    } 
