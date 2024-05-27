
#ifndef TRAIN_HPP
#define TRAIN_HPP
#include"header.hpp"
#include"user.hpp"
extern string checks;
extern bool is_num(string&);
class passenger;
class train
{
	public:
    int train_id;
	string train_name;
	 string source;
        string destination;
        string arrival;
        string depature;
        train(int tr__id,string tr__name,string tr__source,string tr__destination,string tr__arrival,string tr__depature) : 
            train_id(tr__id),train_name(tr__name), source(tr__source),destination(tr__destination),arrival(tr__arrival),depature(tr__depature) {};
        string get_train_name()
        {
            return train_name;
        }
        int get_train_id()
        {
            return train_id;
        }
        string get_depature()
        {
            return depature;
        }
        string get_arrival()
        {
            return arrival;
        }
};


class train_instance_class : public train
{
    public:
                map<string,pair<int,int>> class_seat;
                int train_seats;
                vector<int>lower_breath;
                vector<int>middle_breath;
                vector<int>upper_breath;
                pair<vector<int>,string>pair1;
                vector <passenger *>waiting_list_passenger;
                 
                 vector<int>sitting;
                    vector<int>lower_berth_sleeper;
                    vector<int>middle_berth_sleeper;
                    vector<int>upper_berth_sleeper;
                    vector<int>lower_berth_ac_3rd;
                    vector<int>middle_berth_ac_3rd;
                    vector<int>upper_berth_ac_3rd;
                    vector<int>lower_berth_ac_2nd;
                    vector<int>upper_berth_ac_2nd;
                    vector<int>ac_1st;
                    
                    vector<int>sitting_windows_copy;
                    vector<int>lower_berth_sleeper_copy;
                    vector<int>middle_berth_sleeper_copy;
                    vector<int>upper_berth_sleeper_copy;
                    vector<int>lower_berth_ac_3rd_copy;
                    vector<int>middle_berth_ac_3rd_copy;
                    vector<int>upper_berth_ac_3rd_copy;
                    vector<int>lower_berth_ac_2nd_copy;
                    vector<int>upper_berth_ac_2nd_copy;
                    vector<int>ac_1st_copy;

                train_instance_class(int tr__id, string tr__name, string tr__source, string tr__destination, string tr__arrival, string tr__depature) : train(tr__id,tr__name, tr__source, tr__destination,tr__arrival, tr__depature)
                {
                    class_seat["sitting"]=make_pair(24,100);
                    class_seat["sleeper"]=make_pair(24,200);
                    class_seat["ac_1st"]=make_pair(24,500);
                    class_seat["ac_2nd"]=make_pair(24,400);
                    class_seat["ac_3rd"]=make_pair(24,300);
                    sitting = {1,4,7,10,13,16,19,22};
                    lower_berth_sleeper= {1,4,7,9,12,15,17,20,23};
                    middle_berth_sleeper= {2,5,10,13,18,21};
                    upper_berth_sleeper ={3,6,8,11,14,16,19,22,24};
                    lower_berth_ac_3rd={1,4,7,9,12,15,17,20,23};
                    middle_berth_ac_3rd={2,5,10,13,18,21};
                    upper_berth_ac_3rd={3,6,8,11,14,16,19,22,24};
                    lower_berth_ac_2nd={1,4,7,9,12,15,17,20,23};
                    upper_berth_ac_2nd={3,6,8,11,14,16,19,22,24};
                    ac_1st={3,6,8,11,14,16,19,22,24};
                
                
                    sitting_windows_copy=sitting;
                    lower_berth_sleeper_copy=lower_berth_sleeper;
                    middle_berth_sleeper_copy=middle_berth_sleeper;
                    upper_berth_sleeper_copy=upper_berth_sleeper;
                    lower_berth_ac_3rd_copy=lower_berth_ac_3rd;
                    middle_berth_ac_3rd_copy=middle_berth_ac_3rd;
                    upper_berth_ac_3rd_copy=upper_berth_ac_3rd;
                    lower_berth_ac_2nd_copy=lower_berth_ac_2nd;
                    upper_berth_ac_2nd_copy=upper_berth_ac_2nd;
                    ac_1st_copy=ac_1st;
                    }
};


 void get_vector(vector <int> new_vector);
 void train_instance(int n);
 void class_seats(int train_id);
int price_calculation(train_instance_class * pointer,string train_class, int ticket_count);
void passenger_waiting_list(int);

tuple<pair<string,int>,passenger *>* preference_ac_2nd(train_instance_class * train_pointer,string,bool);
tuple<pair<string,int>,passenger *>* preference_ac_1st(train_instance_class * train_pointer,string);
tuple<pair<string,int>,passenger *>* preference_sitting(train_instance_class * train_pointer,string);
tuple<pair<string,int>,passenger *>* preferences(train_instance_class * train_pointer,string,bool);
#endif

