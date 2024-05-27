
#include"user.hpp"
struct tree *root_node;
struct User *head_1;
struct User *head_2;
struct User *head_3;
struct User *head_4;
struct User *head_5;
struct User *head_6;
struct User *head_7;
struct User *head_8;
int user::vol_int=20190000;
user * user_logged_in_pointer=nullptr;

tree * create(tree * address)
{
    return new tree();
}


tree * create_tree(tree * address)
{
    tree *root_node=create(root_node);
    root_node->left=create(root_node->left);//a-m
    root_node->right=create(root_node->right);//m-z
    root_node->left->left=create(root_node->left->left);//male
    root_node->left->right=create(root_node->left->right);//female
    root_node->right->left=create(root_node->right->left);//male
    root_node->right->right=create(root_node->right->right);//female
    root_node->left->left->left=create(root_node->left->left->left);//below 50
    root_node->left->left->right=create(root_node->left->left->right);//above 50
    root_node->left->right->left=create(root_node->left->left->left);//below 50
    root_node->left->right->right=create(root_node->left->left->right);//above 50
    root_node->right->left->left=create(root_node->left->left->left);//below 50
    root_node->right->left->right=create(root_node->left->left->right);//above 50
    root_node->right->right->left=create(root_node->left->left->left);//below 50
    root_node->right->right->right=create(root_node->left->left->right);//above 50
    address=root_node;
    return address;
}



User* store(User* address, user* user_address) 
{
    cout<<user_address<<"user address in store function"<<endl;
    User * temp1=address;
    cout<<temp1<<"head inside store function----------"<<endl;
    User * temp2=nullptr;
    // User * temp2=nullptr;
    if (temp1==NULL)
    {
        cout<<"inside if-----------------"<<endl;
        address=new User;
        address->instance=user_address;
        address->next=NULL;
    }
    else if(temp1!=NULL)
    {
        temp2=address;
        while (temp1->next != NULL)
        {
            cout << temp1->next << "-------------------------";
            temp1 = temp1->next;
            temp2 = temp1;
        }
        temp2->next = new User;
        temp2 = temp2->next;
        temp2->instance = user_address;
        temp2->next = NULL;
        
    }
    return address; 
}

void  insert(user * user_address)
{
    cout<<user_address<<"user address"<<endl;
    root_node->left->left->left->header=head_1;
    root_node->left->left->right->header=head_2;
    root_node->left->right->left->header=head_3;
    root_node->left->right->right->header=head_4;
    root_node->right->left->left->header=head_5;
    root_node->right->left->right->header=head_6;
    root_node->right->right->left->header=head_7;
    root_node->right->right->right->header=head_8;
    if(user_address->user_name[0]>=65 and user_address->user_name[0]<=77)
            {
                if(user_address->user_gender=="male")
                {
                    if (user_address->user_age<50)
                    {
                        cout<<head_1<<"head pointer-----------------"<<endl;
                        head_1=store(head_1,user_address);
                        cout<<head_1<<"head pointer------------------------"<<endl;

                        cout<<head_1<<"head"<<endl;
                    }
                
                    else
                    {
                        head_2=store(head_2,user_address);
                    }
                    
                }
                if(user_address->user_gender=="female")
                {
                    if (user_address->user_age<50)
                    {
                        head_3=store(head_3,user_address);
                    }
                    else
                    {
                        head_4=store(head_4,user_address);
                    }
                    
                }
            }
            else
            if(user_address->user_name[0]>=78 and user_address->user_name[0]<=90)
            {
                if(user_address->user_gender=="male")
                {
                    if (user_address->user_age<50)
                    {
                        head_5=store(head_5,user_address);
                    }
                    else
                    {
                        head_6=store(head_6,user_address);
                    }
                    
                }
                if(user_address->user_gender=="female")
                {
                    if (user_address->user_age<50)
                    {
                        head_7=store(head_7,user_address);
                    }
                    else
                    {
                        head_8=store(head_8,user_address);
                    }  
                }
            }
            // User * temp=head_7;
            // while(temp!=NULL)
            // {
            //     cout<<temp<<"              temp"<<endl;
            //     cout<<temp->instance<<"        instance"<<endl;
            //     cout<<temp->instance->user_name<<"         user name"<<endl;
            //     cout<<temp->instance->user_id<<"     id\n"<<endl;
            //     temp=temp->next;
            // }
        }


void creator()
{
    system("clear");
    string name;
    int age;
    string gender;
    string password;
    cout<<"Enter your name(first letter caps):"<<endl;
    getline(cin,name);
    re:
    cout<<"Enter your age:"<<endl;
    getline(cin,checks);
    if(is_num(checks))
    {
        age = stoi(checks);
    }
    else
    {
        cout<<"Invalid input"<<endl;
        goto re;
    }
    cout<<"Enter gender(full small letters):"<<endl;
    getline(cin,gender);
    cout<<"Set a password:"<<endl;
    getline(cin,password);
    user *user_pointer = new user(name,age,gender,password);
    insert(user_pointer);
}


bool check(User * address,int * ur_id,string * pass)
{
    User * temp=address;
    // bool s=false;
    while(temp!=NULL)
    {
        if(temp->instance->user_id==*ur_id && temp->instance->user_password == *pass)
        {
            user_logged_in_pointer=temp->instance;
            // cout<<temp->instance->user_id;
            return true;
            break;
        }
        temp=temp->next;
    }
    return false;
}

bool login()
{
    string name;
    string password;
    int ur_id;
    cout<<"enter the name"<<endl;
    getline(cin,name);
    re:
    cout<<"enter the user id"<<endl;
    getline(cin,checks);
    if(is_num(checks))
    {
        ur_id = stoi(checks);
    }
    else
    {
        cout<<"Invalid input"<<endl;
        goto re;
    }
    cout<<"enter the password"<<endl;
    getline(cin,password);
    bool p=false;

    if (name[0]>=65 and name[0]<=77)
    {
        bool s=(check(head_1,&ur_id,&password)||check(head_2,&ur_id,&password)||check(head_3,&ur_id,&password)||check(head_4,&ur_id,&password));
        if(s)
        {
            p=true;
        }
    }
    else
    {
        bool s=(check(head_5,&ur_id,&password)||check(head_6,&ur_id,&password)||check(head_7,&ur_id,&password)||check(head_8,&ur_id,&password));
        if(s)
        {
            p=true;
        }
    }
    return p;
}




