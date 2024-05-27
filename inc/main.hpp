#ifndef MAIN_H
#define MAIN_H
#include"user.hpp"
#include"header.hpp"
 //extern struct tree root_node1;
 //extern user obj;
 //extern struct User onj;
 #include"ticket.hpp"
extern struct tree *root_node;
extern struct User *head_1;
extern struct User *head_2;
extern struct User *head_3;
extern struct User *head_4;
extern struct User *head_5;
extern struct User *head_6;
extern struct User *head_7;
extern struct User *head_8;

extern void creator();
extern bool is_num(string&);
extern bool is_float(string&);
//extern tree * insert_in_tree(tree * root_address,user * user_address);
extern bool  login();
extern void show_stations();
extern void booking();
//void checking(tree * root_address,int *usr_id,string *password);
extern tree * create(tree * address);
extern tree * create_tree(tree * address);
extern User* store(User* address, user* user_address);
extern void  insert(user * user_address);
extern bool check(User * address,int * ur_id,string *);
extern void train_instance(int n);
extern void get_vector(vector <int> new_vector);
extern void class_seats(int train_id);
extern void ticket_cancellation(int);
extern pair<string,int> preferences(train_instance_class * train_pointer);
#endif
