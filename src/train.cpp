
#include"train.hpp"
#include<tuple>
#include"ticket.hpp"
extern user * user_logged_in_pointer;
extern string g_date;
int seat;
int t_id;
float s_time;
float d_time;
vector <pair<passenger *,string>>passenger_vector;
map<string,vector<train_instance_class*>*> train_map;
vector<train_instance_class*>* train_instance_vector;
vector <ticket *>ticket_instances;
// vector<tuple<int,int,int>*> intermediate_vector_sleeper;
// vector<tuple<int,int,int>*> intermediate_vector_ac_2nd;
// vector<tuple<int,int,int>*> intermediate_vector_ac_3rd;
// vector<tuple<int,int,int>*> intermediate_vector_ac_1st;

// vector<tuple<int,int,int>*> intermediate_vector_sitting;
int source_km;
int des_km;
int sr_km;
void train_instance(int n)
{
    ifstream file_output;
    file_output.open("train_list.txt");
    string line;
    int count=1;
  //  int count2=1;
    vector<string> train_parameters(4);
    bool b=0;
    while(getline(file_output,line))
    {
        if(count==n)
        {
            istringstream my_s(line);
            string word;
            int o=0;
                // cout<<o<<"o value-----------"<<endl;
            int pos = line.rfind('-');
            train_parameters[3] = line.substr(pos+1);
            int pos1 = line.rfind('-',pos-1);
            cout<<train_parameters[3]<<endl;
            train_parameters[2] = line.substr(pos1+1,(pos-1)-pos1);
            cout<<train_parameters[2]<<endl;
            while(getline(my_s,word,'-') and o<=1)
            {
                train_parameters[o]=word;
                b=1;
                o++; 
            }
            /*
            int c=1;
            while(getline(my_s,word,'-'))
            {
                if(c==5)
                {
                    train_parameters[2]= stoi(word);
                    cout<<"arr"<<train_parameters[2]<<endl;
                }
                else if(c==6)
                {
                    train_parameters[3]=stoi(word);
                    cout<<"rea"<<train_parameters[3]<<endl;
                }
                c++;
            }*/
        }
        count++;
    }
    /*
        while(getline(file_output,line))
        {
        if(count2==7+n)
        {
            istringstream my_s(line);
            string word;
            while(getline(my_s,word,'-'))
            {
                istringstream my_word(word);
                string last_word;
                int c=0;
                bool b1= false;
                bool b2=false;
                while (getline(my_word,last_word,','))
                {
                    if(last_word == user_logged_in_pointer->user_source)
                    {
                        b1=true;
                    }
                    if(b1)
                    {
                        getline(my_word, last_word, ',');
                        cout<<last_word<<endl;
                        train_parameters[2]=last_word;
                        b2=true;
                    }
                    if(b2)
                    {
                        sr_km=stoi(last_word);
                    }
                }
                    if(last_word==user_logged_in_pointer->user_destination)
                    {
                        c++;
                        getline(my_word, last_word, ',');
                        cout<<last_word<<endl;
                        train_parameters[3]=last_word;
                        if(c==3)
                        {
                            des_km=stoi(last_word);
                        }
                    }
                }  
            }           
        }*/
    cout<<"sd: "<<train_parameters[0]<<endl;
     auto it = train_map.find(g_date);
    // cout<<g_date<<endl;
    if(it == train_map.end())
    {
        train_instance_class * train_instance_vector1=new train_instance_class(stoi(train_parameters[0]),train_parameters[1],user_logged_in_pointer->user_source,user_logged_in_pointer->user_destination,train_parameters[2],train_parameters[3]);
        train_map.insert(make_pair(g_date,new vector<train_instance_class*>));
        auto itr = train_map.find(g_date);
        train_instance_vector = itr->second;
        itr->second->push_back(train_instance_vector1);
        //train_instance_vector.push_back(train_instance_vector1);
    }
    else
    {
        train_instance_vector = it->second;
        bool b =true;
        for(auto ie:(*train_instance_vector))
        {
            if(ie->train_id == stoi(train_parameters[0]))
            {
                b = false;
            }
        }
        if(b)
        {
            train_instance_class * train_instance_vector1=new train_instance_class(stoi(train_parameters[0]),train_parameters[1],user_logged_in_pointer->user_source,user_logged_in_pointer->user_destination,train_parameters[2],train_parameters[3]);
            (*train_instance_vector).push_back(train_instance_vector1);
        }
    }
}


void get_vector(vector<int> new_vector)
{
    for(int i=0;i<new_vector.size();i++)
    {
        cout<<new_vector[i]<<endl;
        train_instance(new_vector[i]);
    }
}


tuple<pair<string,int>,passenger *>* preference_ac_2nd(train_instance_class * train_pointer,string train_class,bool b)
{
    string preference;
    if(b)
    {
        goto select;
    }
    //pair<string,int>preference_vector;
    cout<<"lower \tupper"<<endl;
    cin>>preference;
    select:
        string name;
        cout<<"Enter the name;"<<endl;
        getline(cin,name);
        int age;
        re:
        cout<<"Enter the age;"<<endl;
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
        passenger * new_passenger=new passenger(name,age);
        bool b1=0;
        bool b2=0;
        bool b3=0;
        bool b4=0;
        if(b)
        {
            goto a2_u;
        }
    if(preference=="lower")
    {
        a2_l:
        if(train_pointer->lower_berth_ac_2nd.size())
        {
            seat = train_pointer->lower_berth_ac_2nd[0];
            train_pointer->lower_berth_ac_2nd.erase(train_pointer->lower_berth_ac_2nd.begin());
            cout<<"the train seat is:"<<train_pointer->lower_berth_ac_2nd[0]<<endl;
            b1=1;
        }
        if(b3 && b4)
        {
            passenger_vector.push_back(make_pair(new_passenger,"ac_2nd"));
            return nullptr; 
        }
        if(!b1)
        {
            b3=1;
            goto a2_u;
        }
        return new tuple(pair(train_class,train_pointer->lower_berth_ac_2nd[0]),new_passenger);
    }
    else
    {
        a2_u:
        if(train_pointer->upper_berth_ac_2nd.size())
        {
            seat = train_pointer->upper_berth_ac_2nd[0];
            train_pointer->upper_berth_ac_2nd.erase(train_pointer->upper_berth_ac_2nd.begin());
            cout<<"the train seat is:"<<train_pointer->upper_berth_ac_2nd[0]<<endl;
            b2=1;
        }
        if(b3 && b4)
        {
            passenger_vector.push_back(make_pair(new_passenger,"ac_2nd"));
            return nullptr; 
        }
        if(!b2)
        {
            b4=1;
            goto a2_l;
        }
        return new tuple(pair(train_class,train_pointer->upper_berth_ac_2nd[0]),new_passenger);
    }
}
  
tuple<pair<string,int>,passenger *>* preference_ac_1st(train_instance_class * train_pointer,string train_class)
{
    pair<string,int>preference_vector;
    string name;
	int age;
    cout<<"Enter the name;"<<endl;
    getline(cin,name);
    re:
    cout<<"Enter the age;"<<endl;
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
    passenger * new_passenger=new passenger(name,age);
    bool b1=0;
    if(train_pointer->ac_1st.size())
    {
         seat = train_pointer->ac_1st[0];
         train_pointer->ac_1st.erase(train_pointer->ac_1st.begin());
         cout<<"the train seat is:"<<train_pointer->ac_1st[0]<<endl; 
         b1=1;
    }
    if(!b1)
    {
        passenger_vector.push_back(make_pair(new_passenger,"ac_1st"));
        return nullptr; 
    }
    return new tuple(pair(train_class,train_pointer->ac_1st[0]),new_passenger);
}



tuple<pair<string,int>,passenger *>* preference_sitting(train_instance_class * train_pointer,string train_class)
{
pair<string,int>preference_vector;
string name;
int age;
cout<<"Enter the name;"<<endl;
getline(cin,name);
re:
cout<<"Enter the age;"<<endl;
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
passenger * new_passenger=new passenger(name,age);
bool b1=0;
if(train_pointer->sitting.size())
{
    seat = train_pointer->sitting[0];
    train_pointer->sitting.erase(train_pointer->sitting.begin());
    cout<<"the train seat is:"<<train_pointer->sitting[0]<<endl;
    b1=1;
}
if(!b1)
{
    passenger_vector.push_back(make_pair(new_passenger,"sitting"));
    return nullptr; 
}
return new tuple(pair(train_class,train_pointer->ac_1st[0]),new_passenger);
}



tuple<pair<string,int>,passenger *>* preferences(train_instance_class * train_pointer,string train_class,bool b)
{
     string preference;
    if(b)
    {
        goto select;
    }
    //pair<string,int>preference_vector;
   // cout<<sr_km<<endl<<des_km<<endl;
    cout<<"lower \t middle\t upper"<<endl;
        cin>>preference;
        select:
        bool b1 =0;
        bool b2=0;
        bool b3=0;
        bool b4=0;
        bool b5=0;
        bool b6=0;
       
        string name;
            int age;
            cout<<"Enter the name;"<<endl;
            cin>>name;
            cout<<"Enter the age;"<<endl;
            cin>>age;
            passenger * new_passenger=  new passenger(name,age);
    if (train_class=="sleeper")
    {   
        if(b)
        {
            goto s_u;
        }
        if(preference=="lower")
        {
            s_l:
            if(train_pointer->lower_berth_sleeper.size())
            {
               seat = train_pointer->lower_berth_sleeper[0];
               train_pointer->lower_berth_sleeper.erase(train_pointer->lower_berth_sleeper.begin());
               b1=1;
               cout<<"the train seat is:"<<train_pointer->lower_berth_sleeper[0]<<endl;
            }
            if(b4 && b5 && b6)
            {
                passenger_vector.push_back(make_pair(new_passenger,"sleeper")); 
                return nullptr; 
            }
            if(!b1)
            {
                b4=1;
                goto s_m;
            }      
            return new tuple(pair(train_class,train_pointer->lower_berth_sleeper[0]),new_passenger);
        }
        else if (preference=="middle")
        {
            s_m:
                if(train_pointer->middle_berth_sleeper.size()!=0)
                {
                    seat = train_pointer->middle_berth_sleeper[0];
                    train_pointer->middle_berth_sleeper.erase(train_pointer->middle_berth_sleeper.begin());
                    b2=1;
                    cout<<"the train seat is "<<train_pointer->middle_berth_sleeper[0]<<endl;
                }
                if(b4 && b5 && b6)
                {
                    passenger_vector.push_back(make_pair(new_passenger,"sleeper")); 
                    return nullptr; 
                }
                if(!b2)
                {
                    b5=1;
                    goto s_u;                
                }
            	return new tuple(pair(train_class,train_pointer->middle_berth_sleeper[0]),new_passenger);
        }
        else
        {
            s_u:
                if(train_pointer->upper_berth_sleeper.size()!=0)
                {
                    seat = train_pointer->upper_berth_sleeper[0];
                    train_pointer->upper_berth_sleeper.erase(train_pointer->upper_berth_sleeper.begin());
                    cout<<"the train seat is"<<train_pointer->upper_berth_sleeper[0]<<endl;
                    b3=1;
                }
                if(b4 && b5 && b6)
                {
                    passenger_vector.push_back(make_pair(new_passenger,"sleeper"));
                    return nullptr; 
                }    
                if(!b3)
                {
                    b6=1;
                    goto s_l;
                }
                return new tuple(pair(train_class,train_pointer->upper_berth_sleeper[0]),new_passenger);
        }
    }
        else
        {
            if(b)
            {
                goto a3_u;
            }
            cout<<"lower \t middle\t upper"<<endl;
            cin>>preference;
            if(preference=="lower")
            {
                a3_l:
                if(train_pointer->lower_breath.size()!=0)
                {
                    seat = train_pointer->lower_berth_ac_3rd[0];
                    train_pointer->lower_berth_ac_3rd.erase(train_pointer->lower_berth_ac_3rd.begin());
                    cout<<"the train seat is:"<<train_pointer->lower_berth_ac_3rd[0]<<endl;
                    b1=1;
                }
                if(b4 && b5 && b6)
                {
                    passenger_vector.push_back(make_pair(new_passenger,"ac_3rd"));
                    return nullptr; 
                }
                if(!b1)
                {
                    b4=1;
                    goto a3_m;
                }
                return new tuple(pair(train_class,train_pointer->lower_berth_ac_3rd[0]),new_passenger);
            }
            else if (preference=="middle")
            {
                a3_m:
                if(train_pointer->middle_breath.size()!=0)
                {
                    seat = train_pointer->middle_berth_ac_3rd[0];
                    cout<<"the train seat is "<<train_pointer->middle_berth_ac_3rd[0]<<endl;
                    train_pointer->middle_berth_ac_3rd.erase(train_pointer->middle_berth_ac_3rd.begin());
                    b2=1;
                }
                if(b4 && b5 && b6)
                {
                    passenger_vector.push_back(make_pair(new_passenger,"ac_3rd"));
                    return nullptr; 
                }
                if(!b2)
                {
                    b5=1;
                    goto a3_u;
                }
                return new tuple(pair(train_class,train_pointer->middle_berth_ac_3rd[0]),new_passenger);
            }
            else
            {
                a3_u:
                if(train_pointer->upper_breath.size()!=0)
                {
                    seat = train_pointer->upper_berth_ac_3rd[0];
                    cout<<"the train seat is"<<train_pointer->upper_berth_ac_3rd[0]<<endl;
                    b3=1;
                    train_pointer->upper_berth_ac_3rd.erase(train_pointer->upper_berth_ac_3rd.begin());
                }     
                if (b4 && b5 && b6) 
                {
                    passenger_vector.push_back(make_pair(new_passenger,"ac_3rd"));
                    return nullptr; 
                }
                if(!b3)
                {
                    b6=1;
                    goto a3_l;
                }
                return new tuple(pair(train_class,train_pointer->upper_berth_ac_3rd[0]),new_passenger);
            }
        }
    }   
  int price_calculation(train_instance_class * pointer,string train_class, int ticket_count)
  {
    fstream file_output;
    int s_fare;
    int km_fare;
    file_output.open("train_list.txt");
    string line;
    int count=1;
    int n;
    if(t_id==12675)
    {
        n=1;
    }
    else if(t_id==12679)
    {
        n=2;
    }
    else if(t_id==22637)
    {
        n=3;
    }
    else if(t_id==12639)
    {
        n=4;
    }
    else if(t_id==12671)
    {
        n=5;
    }
    else
    {
        n=6;
    }
    while(getline(file_output,line))
    {
        if(count==7+n)
        {
            //cout<<line<<endl;
            istringstream iss(line);
            string word;
            while(getline(iss,word,'-'))
            {
                //cout<<word<<endl;
             //   cout<<word.substr(0,word.find(','))<<endl;
            if (word.substr(0,word.find(',')) == user_logged_in_pointer->user_source)
            {  
                int index = word.rfind(',');
                s_fare= stoi(word.substr(index+1));
                int index1 = word.rfind(',',index-1);
                s_time = stof(word.substr(index1+1,index));
             //  cout<<s_fare<<endl;
            }  
        // cout<<word.substr(0,word.find(','))<<endl;   
            if (word.substr(0,word.find(',')) == user_logged_in_pointer->user_destination)
            {  
                int index = word.rfind(',');
                km_fare= stoi(word.substr(index+1));
                int index1 = word.rfind(',',index-1);
                d_time = stof(word.substr(index1+1,index));
             //  cout<<km_fare<<endl;
            }
            }
            break;
        }
        count++;
    }
    if(train_class=="sleeper")
    {
        return 1 *(km_fare-s_fare);
    }
    else if(train_class=="ac_3rd")
    {
    return 2*(km_fare-s_fare);
    }
    else if(train_class=="ac_2nd")
    {
    return 3*(km_fare-s_fare);
    }
    else if(train_class=="ac_1st")
    {
    return 4*(km_fare-s_fare);
    }
    else if(train_class=="sitting")
    {
    return 0.5*(km_fare-s_fare);
    }
    else
    {
        return 0;
    }
  }
void class_seats(int train_id)
{
    t_id= train_id;
    string train_class;
    int ticket_count;
    train_instance_class  * train_point=NULL;
    for (int i=0;i<train_instance_vector->size();i++)
    {
        cout<<train_instance_vector->size()<<endl;
        if((*train_instance_vector)[i]->get_train_id()==train_id)
        {
            train_point=(*train_instance_vector)[i];
            cout<<train_point<<"----------train pointer-"<<endl;
            for (auto i: (*train_instance_vector)[i]->class_seat)
            {
                cout<<i.first<<"\t"<<i.second.first<<"\t"<<i.second.second<<endl;
            }
        }
    }
    cout<<"Enter class"<<endl;
    cin>>train_class;
    tuple<pair<string,int>,passenger *>* pair_check;
    if (train_class=="sleeper")
    {
                    cout<<"Enter number of tickets"<<endl;
                    cin>>ticket_count;
                    vector<int>selected_seats;
                if (ticket_count)
                {
                      cout<<"if u select the preferences u could book only for an individual"<<endl;
                      cout<<"1.select preferences 2.continue without preferences"<<endl;
                      short int a;
                      cin>>a;
                      if(a==1)
                      {
                        int fare=0;
                        cout<<"1"<<endl;
                          for (int i=1;i<=ticket_count;i++)
                          {
                            cout<<"2"<<endl;
                              pair_check=preferences((train_instance_class*)train_point,train_class,0);
                              fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                              ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                              //cout<<get<0>(*pair_check).second<<endl;
                             // cout<<fare<<endl;
                              ticket_point->train_seat_number = seat;
                              ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                              ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                              
                              ticket_instances.push_back(ticket_point);
                              ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                              cout<<"ticket price"<<fare<<endl;
                              cout<<"--------generating ticket------------"<<endl;
                          }
                            for (int i=0;i<ticket_instances.size();i++)
                              {
                                    ticket_instances[i]->show_ticket();
                                    //intermediate_vector_sleeper.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                              }
                              cout<<"Booked tickets Thank you  :)"<<endl;     
                      }
                      else
                      {
                        for (int i=1;i<=ticket_count;i++)
                            {
                                 pair_check=preferences((train_instance_class*)train_point,train_class,1);
                              int fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                ticket_instances.push_back(ticket_point);
                                 ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                 cout<<"ticket price"<<fare<<endl;;
                            cout<<"--------generating ticket------------"<<endl;
                            }  
                            for (int i=0;i<ticket_instances.size();i++)
                            {
                                  ticket_instances[i]->show_ticket();
                                  //intermediate_vector_sleeper.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                            }
                            cout<<"Booked tickets Thank you  :)"<<endl;
                        }
                }
    }          
   else if (train_class=="ac_3rd")
    {
                    cout<<"Enter number of tickets"<<endl;
                    cin>>ticket_count;
                    vector<int>selected_seats;
                if (ticket_count)
                {
                      cout<<"if u select the preferences u could book only for an individual"<<endl;
                      cout<<"1.select preferences 2.continue without preferences"<<endl;
                      short int a;
                      tuple<pair<string,int>,passenger *>* pair_check;
                      cin>>a;
                      if(a==1)
                      {
                        int fare;
                          for (int i=1;i<=ticket_count;i++)
                          {
                              pair_check=preferences((train_instance_class*)train_point,train_class,0);
                              fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                              ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                              ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                              ticket_instances.push_back(ticket_point);
                              }
                              ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                              cout<<"ticket price"<<fare<<endl;;
                              cout<<"--------generating ticket------------"<<endl;
                            }
                            for (int i=0;i<size(ticket_instances);i++)
                              {
                                    ticket_instances[i]->show_ticket();
                                   // intermediate_vector_ac_3rd.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                              }
                              cout<<"Booked tickets Thank you  :)"<<endl;     
                      }
                      else
                      {
                        for (int i=1;i<=ticket_count;i++)
                            {
                                pair_check=preferences((train_instance_class*)train_point,train_class,1);
                              int fare = price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                ticket_instances.push_back(ticket_point);
                                 ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                 cout<<"ticket price"<<fare<<endl;;
                            cout<<"--------generating ticket------------"<<endl;
                            }  
                            for (int i=0;i<ticket_instances.size();i++)
                            {
                                  ticket_instances[i]->show_ticket();
                                  //intermediate_vector_ac_3rd.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                            }
                            cout<<"Booked tickets Thank you  :)"<<endl;
                }
                }
  
                
 else if (train_class=="ac_2nd")
    {
                    cout<<"Enter number of tickets"<<endl;
                    cin>>ticket_count;
                    vector<int>selected_seats;
                if (ticket_count!=0)
                {
                      cout<<"if u select the preferences u could book only for an individual"<<endl;
                      cout<<"1.select preferences 2.continue without preferences"<<endl;
                      short int a;
                      cin>>a;
                      if(a==1)
                      {
                        int fare;
                          for (int i=1;i<=ticket_count;i++)
                          {
                              pair_check=preference_ac_2nd((train_instance_class*)train_point,train_class,0);
                              fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                              ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                              ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                              ticket_instances.push_back(ticket_point);
                              }
                              ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                              cout<<"ticket price"<<fare<<endl;;
                              cout<<"--------generating ticket------------"<<endl;
                            }
                            for (int i=0;i<size(ticket_instances);i++)
                              {
                                    ticket_instances[i]->show_ticket();
                                   // intermediate_vector_ac_2nd.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                              }
                              cout<<"Booked tickets Thank you  :)"<<endl;     
                      }
                      else
                      {
                        for (int i=1;i<=ticket_count;i++)
                            {
                            pair_check=preference_ac_2nd((train_instance_class*)train_point,train_class,1);
                              int fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                ticket_instances.push_back(ticket_point);
                                 ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                 cout<<"ticket price"<<fare<<endl;;
                            cout<<"--------generating ticket------------"<<endl;
                            }  
                            for (int i=0;i<size(ticket_instances);i++)
                            {
                                  ticket_instances[i]->show_ticket();
                                 // intermediate_vector_ac_2nd.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                            }
                            cout<<"Booked tickets Thank you  :)"<<endl;
                }
                }
else if(train_class=="ac_1st")
{
cout<<"Enter number of tickets"<<endl;
                    cin>>ticket_count;
                    vector<int>selected_seats;
                    if(ticket_count==1)
                    {
                                      pair_check= preference_ac_1st((train_instance_class*)train_point,train_class);
                                      int fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                      for (int i=1;i<=ticket_count;i++)
                                        {
                                            ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                            ticket_instances.push_back(ticket_point);
                                        ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                        ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                        cout<<"ticket price"<<fare<<endl;
                                        cout<<"--------generating ticket------------"<<endl;
                                        }
                                        for (int i=0;i<size(ticket_instances);i++)
                                        {
                                              ticket_instances[i]->show_ticket();
                                            //  intermediate_vector_ac_1st.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                                        }
                                        cout<<"Booked tickets Thank you  :)"<<endl;     
                                      }
                        else
                        {
                        for (int i=1;i<=ticket_count;i++)
                        {
                                      pair_check=preference_ac_1st((train_instance_class*)train_point,train_class);
                                      int fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                            ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                            ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                            ticket_instances.push_back(ticket_point);
                                        ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                        cout<<"ticket price"<<fare<<endl;;
                                        cout<<"--------generating ticket------------"<<endl;
                                        }
                                        for (int i=0;i<ticket_instances.size();i++)
                                        {
                                              ticket_instances[i]->show_ticket();
                                           //   intermediate_vector_ac_1st.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                                        }
                                        cout<<"Booked tickets Thank you  :)"<<endl;
                                        }}
  else if(train_class=="sitting")
  {
  cout<<"Enter number of tickets"<<endl;
                    cin>>ticket_count;
                    vector<int>selected_seats;
                    if(ticket_count==1)
                    {
                                      pair_check=preference_sitting((train_instance_class*)train_point,train_class);
                                      int fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                      for (int i=1;i<=ticket_count;i++)
                                        {
                                            ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                             ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                                            ticket_instances.push_back(ticket_point);
                                             ticket_point->train_seat_number = seat;
                                             ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                        ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                        cout<<"ticket price"<<fare<<endl;;
                                        cout<<"--------generating ticket------------"<<endl;
                                        }
                                        for (int i=0;i<size(ticket_instances);i++)
                                        {
                                              ticket_instances[i]->show_ticket();
                                           //   intermediate_vector_sitting.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                                        }
                                        cout<<"Booked tickets Thank you  :)"<<endl;     
                                      }
                        else if(ticket_count!=1)
                        {
                        for (int i=1;i<=ticket_count;i++)
                        {
                                      pair_check = preference_sitting((train_instance_class*)train_point,train_class);
                                      int fare =price_calculation((train_instance_class*)train_point,train_class,ticket_count);
                                            ticket * ticket_point=new ticket((train_instance_class*)train_point,train_class,fare,get<1>(*pair_check));
                                             ticket_point->passenger_pointer->passenger_source = user_logged_in_pointer->user_source;
                              ticket_point->passenger_pointer->passenger_destination= user_logged_in_pointer->user_destination;
                               ticket_point->train_seat_number = seat;
                               ticket_point->arrive=s_time;
                              ticket_point->depart=d_time;
                                            ticket_instances.push_back(ticket_point);
                                        ((train_instance_class*)train_point)->class_seat[train_class].first-=1;
                                        cout<<"ticket price"<<fare<<endl;;
                                        cout<<"--------generating ticket------------"<<endl;
                                        }
                                        for (int i=0;i<ticket_instances.size();i++)
                                        {
                                              ticket_instances[i]->show_ticket();
                                           //   intermediate_vector_sitting.push_back(new tuple(sr_km,des_km,ticket_instances[i]->train_seat_number));
                                        }
                                        cout<<"Booked tickets Thank you  :)"<<endl;
                                        }}
}
                                                                 
                                        
void passenger_waiting_list(int train_id)
{
    train * train_point=NULL;
    for (int i=0;i<train_instance_vector->size();i++)
    {
        if((*train_instance_vector)[i]->get_train_id()==train_id)
        {
            train_point=(*train_instance_vector)[i];
        }
    }
    cout<<"there are"<<passenger_vector.size()<<"waiting lists"<<endl;
    if(passenger_vector.size()==0)
    {   
        return;
    }
    else
    {
        if (passenger_vector.size()!=0)
        {
            for (int i=0;i<train_instance_vector->size();i++)
            {
                if ((*train_instance_vector)[i]==train_point)
                {
                    for(int i=0;i<passenger_vector.size();i++)
                    {
                        if(passenger_vector[i].second=="sleeper")
                        {
                            if((*train_instance_vector)[i]->lower_berth_sleeper.size()!=0)
                            {
                                passenger* ps;
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                ticket_instances.push_back(ticket_point);
                                ticket_point->passenger_pointer=passenger_vector[i].first;
                                break;
                            }
                            else if(((*train_instance_vector)[i]->middle_berth_sleeper.size()!=0))
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);
                                      ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                            else if((((*train_instance_vector)[i]->upper_berth_sleeper.size()!=0)))
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);
                                      ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                        }
                        if(passenger_vector[i].second=="ac_3rd")
                        {
                            if((*train_instance_vector)[i]->lower_berth_ac_3rd.size()!=0)
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);
                                      ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                            else if(((*train_instance_vector)[i]->middle_berth_ac_3rd.size()!=0))
                            { 
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point),ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                            else if((((*train_instance_vector)[i]->upper_berth_ac_3rd.size()!=0)))
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                        }
                        if(passenger_vector[i].second=="ac_2nd")
                        {
                            if((*train_instance_vector)[i]->lower_berth_ac_2nd.size())
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                            else if(((*train_instance_vector)[i]->upper_berth_ac_2nd.size()!=0))
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                        }
                        if(passenger_vector[i].second=="ac_1st")
                        {
                            if((*train_instance_vector)[i]->ac_1st.size()!=0)
                            {
                                int fare =price_calculation((train_instance_class*)train_point,passenger_vector[i].second,1);
                                ticket * ticket_point=new ticket((train_instance_class*)train_point,passenger_vector[i].second,fare,passenger_vector[i].first);
                                      ticket_instances.push_back(ticket_point);
                                      ticket_point->passenger_pointer=passenger_vector[i].first;
                                      break;
                            }
                        }
  
                    }
                }
            }
        }
    }
}




