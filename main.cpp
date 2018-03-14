#include <iostream>
#include<time.h>
using namespace std;
class Wiper//Base class1: Wiper class
{
public:
    //Data members of Wiper class
    int engine_state=0;
    int sense;
    char mode;
    //Member Functions of Wiper class
    void automode(char mode,int sense);
    void low_oscillation();
    void medium_oscillation();
    void high_oscillation();
    void delay(unsigned int Sec);
};


class power_window//Base class 2: Power Window
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

class Window_Wiper:public Wiper,public power_window
{
public:
    int ch;
    void wiperinput();
    void windowinput();
};

//Function definition of Auto mode: this function switches to any of High/Low/Medium mode based on sense values.
void Wiper::automode(char mode,int sense)
{
 if(sense>0 && sense<=25)
    low_oscillation();
 else if(sense>=26 && sense<=100)
    medium_oscillation();
 else if(sense>=101 && sense<=500)
    high_oscillation();
 else
    cout<<"Wrong operation performed"<<endl;
}
//Function definition of Low Oscillation: this function turns the wiper in low oscillation state.
void Wiper::low_oscillation()
{
    int up1,up2;
       cout<<"Wiper on Low Oscillation\n";
    for(up1=1;up1<=5;++up1)
    {
        for(up2=1;up2<up1;++up2)
        {
            delay(1);
           cout<<"*";
        }
        cout<<"\n";
    }
}
//Function definition of Medium Oscillation: this function turns the wiper in Medium oscillation state.
void Wiper::medium_oscillation()
{
   int up1,up2;
       cout<<"Wiper on Medium Oscillation\n";
    for(up1=1;up1<=5;++up1)
    {
        for(up2=1;up2<up1;++up2)
        {
            delay(1);
           cout<<"*";
        }
        cout<<"\n";
    }
}
//Function definition of High Oscillation: this function turns the wiper in High oscillation state.
void Wiper::high_oscillation()
{
    int up1,up2;
cout<<"Wiper on High Oscillation"<<endl;
    for(up1=1;up1<=5;up1++)
    {
        for(up2=up1;up2<5;up2++)
        {
           cout<<" ";
        }
        for(up2=1;up2<=up1;up2++)
        {
           cout<<"*";
        }
        cout<<endl;
    }
}
//Function to depict the oscillation
void Wiper::delay(unsigned int Sec)
{
clock_t ticks1 = clock(), ticks2 = ticks1;
       while ( ( ticks2/CLOCKS_PER_SEC - ticks1/CLOCKS_PER_SEC ) < Sec)
           ticks2 = clock();
           return;
}

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
    for(eup1=1;eup1<=count;eup1++)
    {
        for(eup2=eup1;eup2<=count;eup2++)
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
    for(eup1=1;eup1<=count;eup1++)
    {
        for(eup2=eup1;eup2<count;eup2++)
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


void Window_Wiper::wiperinput()
{
Wiper wiper;
    int option;
    //loop to allow user to perform operation until they exit from the operation
    while(1)
    {
        //Inputting Engine status and checking if the status is ON or OFF.
    cout<<"Enter status of Engine(Press 1 to Turn ON/ Press 0 to Turn OFF"<<endl;
    cin>>wiper.engine_state;
    if(wiper.engine_state==0)
    {
        cout<<"Engine is already OFF! PLease Press 1 to Turn ON"<<endl;
        continue;
    }
    else
    {
        wiper.engine_state=1;
        wiper.mode='M';
    }
    //Options to allow users to select their choice.
    cout<<"Choose Options: "<<endl<<"1.Auto(Press 'A' or 'a')"<<endl<<"2.Low Oscillation(Press 'L' or 'l')"<<endl<<"3.Medium(Press 'M' or 'm')"<<endl<<"4.High(Press 'H' or 'h')"<<endl;
    cin>>wiper.mode;
    //Inputting Sense value
    cout<<"Enter sense Value"<<endl;
    cin>>wiper.sense;
    //Switching to the operation based on selected option from the list
    if(wiper.mode=='A' || wiper.mode=='a')//switches to auto mode function
    {
        wiper.automode(wiper.mode,wiper.sense);//calling auto mode function
    }
    else if((wiper.mode=='L' || wiper.mode=='l') && (wiper.sense>0 && wiper.sense<=25))//switches to low oscillation mode
    {
        wiper.low_oscillation();//calling low oscillation function
    }
    else if((wiper.mode=='M' || wiper.mode=='m') && (wiper.sense>26 && wiper.sense<=100))//switches to medium oscillation mode
    {
        wiper.medium_oscillation();//calling medium oscillation function
    }
    else if((wiper.mode=='H' || wiper.mode=='h') && (wiper.sense>101 && wiper.sense<=500))//Switches to high oscillation mode
    {
        wiper.high_oscillation();//calling high oscillation function
    }
    else
    {
        cout<<"Invalid Option selected"<<endl;
        break;
    }
    //Input to ask user to continue the operation
    cout<<"Do you want to continue?(If YES Press 1/ If NO Press 0)"<<endl;
    cin>>option;
    if(option==1)
        continue;
    else
        break;
    }

}
void Window_Wiper::windowinput()
{
power_window powind;
    int option,option1,count=0;
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
           cout<<"Enter Door Status(Press 'O'/'o' to Open)(Press 'C'/'c' to Close)"<<endl;
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

        cout<<"Select operation"<<endl;
        cout<<"1. Window UP(Press 'U'/'u')"<<endl<<"2. Window Down(Press 'D'/'d')"<<endl<<"3.Express UP-DOWN Window(Press 'E'/'e')"<<endl;
        cin>>powind.choice;
        count++;
        while(1)
        {
            cout<<"Do you want to continue current operation?(Press 1 for YES/Press 0 for NO)"<<endl;
            cin>>option;
            if(option==1 && (powind.choice=='U' || powind.choice=='u'))
            {
                cout<<"1.Window UP(Press 'U'/'u')"<<endl;
                cin>>powind.choice;
                count++;
            }
            else if(option==1 && (powind.choice=='D' || powind.choice=='d'))
            {
                cout<<"1.Window Down(Press 'D'/'d')"<<endl;
                cin>>powind.choice;
                count++;
            }
            else if(option==1 && (powind.choice=='E' || powind.choice=='e'))
            {
                cout<<"1.Window Down(Press 'E'/'e')"<<endl;
                cin>>powind.choice;
                count++;
            }
            else
            {
                break;
            }
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
}
int main()
{
    int c;
 Window_Wiper winwip;
 while(1)
 {
 cout<<"Enter Your choice"<<endl;
 cout<<"1. Power Window(press 1)"<<endl<<"2.Wiper System(press 2)"<<endl<<"3.Exit(press 3)"<<endl;
 cin>>winwip.ch;
 if(winwip.ch==1)
 {
     winwip.windowinput();
 }
 else if(winwip.ch==2)
 {
     winwip.wiperinput();
 }
 else
 {
     break;
 }
 cout<<"Do you want to continue?(Yes Press 1/NO Press 0)"<<endl;
 cin>>c;
 if(c==1)
    continue;
 else
   break;
 }

     return 0;
}
