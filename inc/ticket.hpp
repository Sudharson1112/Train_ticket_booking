#ifndef TICKET_HPP
#define TICKET_HPP
#include"header.hpp"
#include"user.hpp"
#include "train.hpp"

/*
class passenger
{
public:
string passenger_name;
int passenger_age;
passenger(string name,int age):passenger_name(name),passenger_age(age){}
};
*/
// class user;
// class passenger;
// class train_instance_class;
class ticket
{
    public:
     static int id; 
     int ticket_id;
    passenger * passenger_pointer;
    train_instance_class * train_pointer;
    int running_date;
    string train_class;
    int train_seat_number;
    int ticket_fare;
    float arrive;
    float depart;
    ticket(train_instance_class * pointer,string tr_class,int tr_fare,passenger * passenger)
    {
        this->ticket_id= id++;
        train_pointer=pointer;
        train_class=tr_class;
        ticket_fare=tr_fare;
        cout<<"inside the ticket instance"<<endl;
        passenger_pointer=passenger;
    }
    void show_ticket()
    {
        //system("clear");
        cout<<"Ticket for passesnger travelling"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Name:"<<passenger_pointer->passenger_name<<endl;
        cout<<"Age:"<<passenger_pointer->passenger_age<<endl;
        cout<<"Id:"<<get_id()<<endl;
        cout<<"source     :"<<passenger_pointer->passenger_source<<endl;
        cout<<"destination:"<<passenger_pointer->passenger_destination<<endl;
        cout<<"Journey start    :"<<arrive<<"\tJourney end    : "<<depart<<endl;
        cout<<"class      :"<<train_class<<endl;
        cout<<"seats     :"<<train_seat_number<<endl;
        cout<<"fare      :"<<ticket_fare<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
    int get_id()
    {
        return ticket_id;
    }
};


void show_stations();
void booking();
 void ticket_cancellation(int);
 //tree * insert_in_tree(tree * root_address,user * user_address);
#endif
