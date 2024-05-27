
#include"ticket.hpp"
extern string g_date;
extern map<string,vector<train_instance_class*>*> train_map;
extern vector<train_instance_class*>* train_instance_vector;
extern vector <ticket *>ticket_instances;
extern user * user_logged_in_pointer;
vector<ticket *>ticket_instance_vector;
int ticket::id =1000;
void booking()
{
    string source;
    string destination;
	getchar();
    cout<<"Enter the source:"<<endl;
    cin>>source;
    user_logged_in_pointer->user_source=source;
    cout<<"Enter the destination:"<<endl;
    cin>>destination;
    user_logged_in_pointer->user_destination=destination;
    ifstream file_output;
    file_output.open("train_list.txt");
    string line;
    bool word1_bool;
    bool word2_bool;
    int count=1;
    vector<int> train_list;

    while(getline(file_output,line))
    {
        if(count>7)
        {
            istringstream iss(line);
            string word;
            while(getline(iss,word,'-'))
            {
                size_t pos = word.find(',');
                if(word.substr(0,pos)==source)
                {
                    word1_bool=true;
                   // size_t pos1 = word.find(',',pos);
                   // s_time = stof(word.substr(pos+1,pos1));
                }
                else if(word.substr(0,pos)==destination)
                {
                    word2_bool=true;
                }
                if(word1_bool && word2_bool)
                {
                    train_list.push_back(count-7);
                    cout<<count<<endl;
                    break;
                }
            }
            word1_bool=false;
            word2_bool=false;
        }
        count++;
    }
    get_vector(train_list);
}


void  show_stations()
{
    //system("clear");
    cout<<"Places that you could select"<<endl;
    ifstream file_output;
    file_output.open("train_station.txt");
    string line;
    while(getline(file_output,line))
    {
        cout<<line<<"          ";
    }
    cout<<endl;
    int a;
    booking();
    while(true)
    {
        cout<<"1.Select train 2.Cancel"<<endl;
        cin>>a;
        class_seats(a);
        return;
    }
    }
  
   bool is_in_vector(int value,vector<int> vector_be_checked)
   {
   for (int i=0;i<vector_be_checked.size();i++)
   {
   if (vector_be_checked[i]==value)
   {
   return true;
   }
   }
   return false;
   }
    
    
    void ticket_cancellation(int train__id)
    {
        ticket * temp=NULL;
        bool b=0;
        for (int i=0;i<ticket_instances.size();i++)
        {
            if (ticket_instances[i]->ticket_id==train__id)
            {
                temp=ticket_instances[i];

                if(temp)
                {
                    if (temp->train_class=="ac_1st")
                    {
                                temp->train_pointer->ac_1st.insert(temp->train_pointer->ac_1st.begin(),temp->train_seat_number);
                                temp->train_pointer->class_seat[temp->train_class].first+=1;
                            }
                            else if(temp->train_class=="ac_2nd")
                            {
                                if(is_in_vector(temp->train_seat_number,temp->train_pointer->lower_berth_ac_2nd_copy))
                                {
                                    temp->train_pointer->lower_berth_ac_2nd.insert(temp->train_pointer->lower_berth_ac_2nd.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                                else if(is_in_vector(temp->train_seat_number,temp->train_pointer->upper_berth_ac_2nd_copy))
                                {
                                    temp->train_pointer->upper_berth_ac_2nd.insert( temp->train_pointer->upper_berth_ac_2nd.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                            }
                            else if(temp->train_class=="ac_3rd")
                            {
                                if(is_in_vector(temp->train_seat_number,temp->train_pointer->lower_berth_ac_3rd_copy))
                                {
                                    temp->train_pointer->lower_berth_ac_3rd.insert(temp->train_pointer->lower_berth_ac_3rd.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                                else if(is_in_vector(temp->train_seat_number,temp->train_pointer->upper_berth_ac_3rd_copy))
                                {
                                    temp->train_pointer->upper_berth_ac_3rd.insert(temp->train_pointer->upper_berth_ac_3rd.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                                else if(is_in_vector(temp->train_seat_number,temp->train_pointer->middle_berth_ac_3rd_copy))
                                {
                                    temp->train_pointer->middle_berth_ac_3rd.insert( temp->train_pointer->middle_berth_ac_3rd.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                            }
                            else if(temp->train_class=="sleeper")
                            {
                                //cout<<temp->train_seat_number<<endl;
                                if(is_in_vector(temp->train_seat_number,temp->train_pointer->lower_berth_sleeper_copy))
                                {
                                    cout<<temp->train_pointer->lower_berth_sleeper[0]<<endl;
                                    temp->train_pointer->lower_berth_sleeper.insert(temp->train_pointer->lower_berth_sleeper.begin(),temp->train_seat_number);
                                    cout<<temp->train_pointer->class_seat[temp->train_class].first<<endl;
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                     cout<<temp->train_pointer->class_seat[temp->train_class].first<<endl;
                                    cout<<temp->train_pointer->lower_berth_sleeper[0]<<endl;
                                }
                                else if(is_in_vector(temp->train_seat_number,temp->train_pointer->upper_berth_sleeper_copy))
                                {
                                    temp->train_pointer->upper_berth_sleeper.insert(temp->train_pointer->upper_berth_sleeper.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                                else if(is_in_vector(temp->train_seat_number,temp->train_pointer->middle_berth_sleeper_copy))
                                {
                                    temp->train_pointer->middle_berth_sleeper.insert(temp->train_pointer->middle_berth_sleeper.begin(),temp->train_seat_number);
                                    temp->train_pointer->class_seat[temp->train_class].first+=1;
                                }
                            }
                    }
        ticket_instances.erase(remove(ticket_instances.begin(),ticket_instances.end(),temp),ticket_instances.end());
        delete temp;
        b=1;
            }
        }
        if(b)
        {
            cout<<"ticket cancelled successfully"<<endl;
        }
        else{
            cout<<"Incorrect ticket id"<<endl;
        }
        return;
    }
  


    
    
    
    
    
