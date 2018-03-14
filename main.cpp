#include<iostream>
#include<time.h>
using namespace std;
class power_window
{
public:
    int engine_status;
    char door_status;
    char window_status;
    char choice;
    void window_up(int count);
    void window_down(int count);
    void express_updown(int count);
    void delay(unsigned int sec);
};

void power_window::window_up(int count)
{
int up1,up2;
    if(count==0)//if count is 0 then window closes less.
    {
      cout<<"****"<<endl;
    }
    else//if count is 1 then window closes completely.
    {
       cout<<"Window is Going Up"<<endl;
    for(up1=1;up1<=count;++up1)
    {
        for(up2=1;up2<up1;++up2)
        {
            delay(1);
           cout<<"*";
        }
        cout<<endl;
    }
    }
}

void power_window::window_down(int count)
{
    int dn1,dn2;
    if(count==0)//if count is 0 then window opens less
    {
        cout<<"*****"<<endl;
    }
    else//if count is greater than 1 then pattern is printed.
    {
        cout<<"Window is Going Down"<<endl;
    for(dn1=1;dn1<=count;dn1++)
    {
        for(dn2=dn1;dn2<=count;dn2++)
        {
            delay(1);
           cout<<"*";
        }
          cout<<endl;
    }
    }
}

void power_window::express_updown(int count)
{
int eup1,eup2;
    int object_detect;
    cout<<"Is Object Detected?(If Yes Press 1/If No press 0"<<endl;
    cin>>object_detect;
    if(object_detect==1)//if object detected then window goes down
    {
        cout<<"Window is Going Down"<<endl;
        //printing window down pattern
    for(eup1=1;eup1<=5;eup1++)
    {
        for(eup2=eup1;eup2<=5;eup2++)
        {
           cout<<"*";
        }
        cout<<endl;
    }
    }
    else//if object not detected then window goes UP
    {
       cout<<"Window is Going Up"<<endl;
       //printing window up pattern
    for(eup1=1;eup1<=5;eup1++)
    {
        for(eup2=eup1;eup2<5;eup2++)
        {
           cout<<" ";
        }
        for(eup2=1;eup2<=eup1;eup2++)
        {
           cout<<"*";
        }
        cout<<endl;
    }
    }

}

void power_window::delay(unsigned int sec)
{
clock_t ticks1 = clock(), ticks2 = ticks1;
       while ( ( ticks2/CLOCKS_PER_SEC - ticks1/CLOCKS_PER_SEC ) < sec)
           ticks2 = clock();
           return;
}
int main()
{
    power_window powind;
    int option1,count=0;
    char option;
    while(1)
    {
        cout<<"Enter engine status(Press 1 to ON/Press 0 to OFF)"<<endl;
        cin>>powind.engine_status;
        if(powind.engine_status==0)
        {
           cout<<"Engine is Already OFF. Please Turn On."<<endl;
           continue;
        }
        else
        {
           cout<<"Engine is ON"<<endl;
        }
           cout<<"Enter Door Status(Press 'O'/'o' to Open)(Press 'C'/'ç' to Close)"<<endl;
        cin>>powind.door_status;
        if(powind.door_status=='O' || powind.door_status=='o')
             cout<<"Door is Open"<<endl;
        else if(powind.door_status=='C' || powind.door_status=='c')
             cout<<"Door is Closed"<<endl;
        else
        {
              cout<<"Invalid Value!! Please Read the Statement Carefully"<<endl;

        }
          cout<<"Enter Window Status(Press 'O'/'o' for open)(Press 'C'/'c' for close)"<<endl;
        cin>>powind.window_status;
        if(powind.window_status=='O' || powind.window_status=='o')
           cout<<"Window is Open"<<endl;
        else if(powind.window_status=='C' || powind.window_status=='c')
             cout<<"Window is Closed"<<endl;
        else
        {
             cout<<"Invalid Value!! Please Read the Statement Carefully"<<endl;

        }
        repeat:cout<<"Select operation"<<endl;
        cout<<"1. Window UP(Press 'U'/'u')"<<endl<<"2. Window Down(Press 'D'/'d')"<<endl<<"3.Express UP-DOWN Window(Press 'E'/'e')"<<endl;
        cin>>powind.choice;
        if(isalpha(powind.choice))
        {
        count++;
        while(1)
        {
            cout<<"Do you want to continue current operation?(Press 'y'/'Y' for YES/Press 'n'/'N' for NO)"<<endl;
            cin>>option;
            if((option=='y' || option=='Y') && (powind.choice=='U' || powind.choice=='u'))
            {
                cout<<"1.Window UP(Press 'U'/'u')"<<endl;
                cin>>powind.choice;
                count++;
            }
            else if((option=='y' || option=='Y') && (powind.choice=='D' || powind.choice=='d'))
            {
                cout<<"1.Window Down(Press 'D'/'d')"<<endl;
                cin>>powind.choice;
                count++;
            }
            else
            {
                break;
            }
        }
        }
        else if(option=='n' || option=='N')
        {
            break;
        }
        else
        {
            cout<<"please refer the instructions to enter option."<<endl;
            goto repeat;
        }
        if(powind.engine_status==1 && (powind.door_status=='O' || powind.door_status=='o' || powind.door_status=='C' || powind.door_status=='c') && (powind.choice=='U' || powind.choice=='u') && (powind.window_status=='O' || powind.window_status=='o'))
        {
            cout<<"UP"<<endl;
            powind.window_up(count);
        }
        else if(powind.engine_status==1 && (powind.door_status=='O' || powind.door_status=='o' || powind.door_status=='C' || powind.door_status=='c') && (powind.choice=='D' || powind.choice=='d') && (powind.window_status=='C' || powind.window_status=='c'))
        {
            cout<<"DOWN"<<endl;
            powind.window_down(count);
        }
        else if(powind.engine_status==1 && (powind.door_status=='O' || powind.door_status=='o' || powind.door_status=='C' || powind.door_status=='c') && (powind.choice=='E' || powind.choice=='e') && (powind.window_status=='C' || powind.window_status=='c') || (powind.window_status=='O' || powind.window_status=='o'))
        {
            cout<<"Express"<<endl;
            powind.express_updown(count);
        }
        else
        {
            cout<<"Wrong Operation performed! Please try again"<<endl;
        }
        cout<<"Do you want to continue?(If Yes 1 / If NO 0)"<<endl;
        cin>>option1;
        if(option1==1)
            continue;
        else
            break;
    }

    return 0;
}
