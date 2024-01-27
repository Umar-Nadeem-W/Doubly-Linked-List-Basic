#include <iostream>
using namespace std;
class node{

private:

    int value;
    node* next_node;
    node* previous_node;

public:

    void set_val(int v){value = v;}
    void set_next_node(node* nn){next_node = nn;}
    void set_prev_node(node* pn){previous_node = pn;}

    int get_val(){return value;}
    node* get_next_node(){return next_node;}
    node* get_prev_node(){return previous_node;}

    node(){
    value = -1;
    next_node = NULL;
    previous_node = NULL;
    }

    ~node()
    {
    delete next_node;
    delete previous_node;
    };
};


class dll{


    private :
        node* header;
        node* last_current_node;
        node* current_node;
        node* tail_node;
        int list_size;

    public:

        dll()
        {
            header = new node();
            header->set_next_node(NULL);
            header->set_prev_node(NULL);
            header->set_val(0);
            current_node =NULL;
            last_current_node =NULL;
            tail_node =NULL;
            list_size =0;
        }

void create_list(){

int NOE;
cout <<"Please enter the number of nodes you wish to store in the dll"<<endl;
cin>>NOE;

for(int i = 1; i<= NOE; i++){

int nval;
if (header ->get_next_node() == NULL)
    {
    node* newnode = new node();
    cout <<"Please enter the value you wish to store in node # "<<i<<endl;
    cin>>nval;
    newnode->set_val(nval);
    header->set_next_node(newnode);
    newnode->set_prev_node(NULL);
    last_current_node = header;
    current_node = newnode;
    list_size++;
    }
    else
        {
        node* newnode = new node();
        cout <<"Please enter the value you wish to store in node # "<<i<<endl;
        cin>>nval;
        newnode->set_val(nval);
        newnode->set_prev_node(current_node);
        newnode->set_next_node(NULL);
        current_node->set_next_node(newnode);
        last_current_node = current_node;
        current_node = newnode;
        tail_node = newnode;
        list_size++;
        }


}

}

void Display()
{
current_node = tail_node;
for(int i = list_size; i>= 1; i--)
    {
     cout <<"Element stored at node # "<<i<<" of the list is: ";
     cout<<current_node->get_val()<<endl;
     current_node = current_node->get_prev_node();
    }


}

void ins_at_start(){
    int v;
 node* newnode = new node();
 cout <<"Please enter the value you wish to store at the start of the array."<<endl;
 cin>>v;
 newnode->set_val(v);
 header->get_next_node()->set_prev_node(newnode);
 newnode->set_next_node(header->get_next_node());
 header->set_next_node(newnode);
 newnode->set_prev_node(NULL);
 cout<<newnode->get_next_node()->get_val();
 list_size++;
}


        ~dll()
        {
        delete last_current_node;
        delete current_node;
        delete tail_node;
        delete header;
        }

};


dll l1;
int main()
{
l1.create_list();
l1.Display();
l1.ins_at_start();
l1.ins_at_start();
l1.Display();
return 0;
}
