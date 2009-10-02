#include <cstdlib>
#include <iostream>
#define WIDTH 3
#define HEIGHT 3

int W = WIDTH, H = HEIGHT;
int m = 2,n = 2;
int nummons = 2;
int key = 0;



using namespace std;
string clrhome = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
char player [] = "player"; 
char yn, clas, weapon = 0;
char space [] = "\n\n\n";
int atk, acc, hp, lvl, patk, pacc, plvl, matk, macc, mlvl, exp, nexp;
double php,mhp; //makes the hp things un bugged
char choice;//main input durring gameplay
double a,d,ch;//choice, damage, chance hit
double bd,ad;// base damage, additional damage
float r; //any random variable
int potion(0), snade(0); //items
int i;//item var
int endn=0;
int rm;
int position = 5;
namespace spider
{
          char name [] = "big spider";
          int mhp = 50;
          int matk = 20;
          int macc= 50;
          int mlvl = 1;
          }
		  
namespace jesus
{
          char name [] = "jesus";
          int mhp = 50000000;
          int matk = 2;
          int macc= 5000000;
          int mlvl = 100000;
          }		  
		  
		  
		  
	
namespace tutmonster
{
          char name [] = "baby seal";
          int mhp = 50;
          int matk = 20;
          int macc= 50;
          int mlvl = 1;
          }
void battlechoice()
		  { cout<<"1. attack"<<endl<<"2. item"<<endl;
			cin >> a;
			cout<<endl;
		  }			  
	
void  levelup()
{ 
	lvl++;
	cout << "Good job, now you are level "<< lvl<<endl;
	exp = 0;
	nexp = lvl*3;
}

		  
void useitem ()
{
     usestart:
    cout <<clrhome<< "                      Inventory:"<< space<<space;
    cout << "1. potions: "<< potion<<endl;
    cout << "2. smoke gernades: "<<snade<<endl;
    cout << "3. exit"<< space;
    cout << "What do you want to use?" <<endl;
    cin >> a;
    if (a == 1) goto potion;
    if (a == 2 ) goto snade;
    if (a == 3) {
          i = 0;
          goto end;
          }
    else 
    { 
         cout << " that isnt a choice..." <<endl;
         cin.get();
         cout << clrhome;
         goto usestart;
         }
    potion:
    if (potion > 0)
    {       
    php=php+25;
    potion=potion-1;
    cout << " you drink yur potion, gaining 25 hp."<<endl;
    cout << "hp: " << php;
    i = 1;
    cin.get();
    cin.get();
    cout << clrhome;
    goto end;
}
    cout <<" sorry you dont have a potion to use"<<endl;
    i = 0;
    cin.get();
    cin.get();
    cout << clrhome;
    goto end;
    snade:
    if (snade > 0)
    {       
    snade=snade-1;
    cout << "You toss the smoke gernade and run away."<<endl;
    i = 2;
    cin.get();
    cin.get();
    cout << clrhome;
    goto end;
}
    cout <<" sorry you dont have a smoke gernade to use"<<endl;
    i = 0;
    cin.get();
    cin.get();
    cout << clrhome;
    goto end;
    
    end:
    i=i;
    }
    
     
void
giveitem (int id, int count)
{
        if (id == 1)
           {
               potion= potion+count;
               cout << "you gain " << count << " potions.\n";
               goto end;
               }
        if (id == 2)
           {
               snade= snade+count;
               cout << "you gain " << count << " smoke gernades.\n";
               goto end;
               }
        if (id == 3)
        {
               key++;
               cout << "you found a key!";
               goto end;
               }       
        cout << "nice try hacker"<<endl;
        end: 
        a=a;          
}
               
               

double damage(int patk2, int pacc2, int plvl2, int macc2, int mlvl2)//ignore the variables' names, its player's atk, acc, then lvl, and then defenders acc and lvl 
{
    ch = pacc2 / macc2;
    if (ch >= 1) ch = 1;
    r = rand() % 1;
    if (ch >= r ) goto hit;
    if (ch < r) goto miss;
    hit:
    bd = (patk2 - ( .5*macc2))+5*plvl;
    ad = ((pacc2/macc2)-1) * bd;
    d = bd+ad ;
    if (d <= 0) d = 1;
    return (d);
    miss: 
    d = 0;
    return (d);
}
    
    
    
    
              
               

void
playerinfo ()
{
           cout << clrhome;
           cout << " Welcome to  <ill come up with a name later>," << player << ". Please enter your name:" << endl;
           cin >> player;
           cout << clrhome;
           cout << " Hello " << player << ". Lets start with your basic class."<<endl;
           chooseclass:
           cout << " Do you want to be a: \n 1. mage \n 2. head huntsman \n 3. bible toter" <<endl;
           cin >> clas;
           string ynnote= "note: use 1 for yes and 0 for no";
           int yn;
           cout << clrhome;
           
           if (clas == '1')//mage
           {
                     cout << "are you sure you want to be a mage? \n" << ynnote << endl;
                     cin >> yn;
                     if (yn == 0)
                     {
                            cout << " ok please choose what you want."<<endl;
                            goto chooseclass;
                     }
                     if (yn == 1)
                     {
                            goto weapon;
                     }
                     cout << " please choose yes or no" <<endl;
           }
           if (clas == '2')//headhunter
           {
                     cout << "are you sure you want to be a headhunter? \n" << ynnote << endl;
                     cin >> yn;
                     if (yn == 0)
                     {
                            cout << " ok please choose what you want."<<endl;
                            goto chooseclass;
                     }
                     if (yn == 1)
                     {
                            goto weapon;
                     }
                     cout << " please choose yes or no" <<endl;
           }
           if (clas == '3')//bible toter
           {
                     cout << "are you sure you want to be a bible toter? \n" << ynnote << endl;
                     cin >> yn;
                     if (yn == 0)
                     {
                            cout << " ok please choose what you want."<<endl;
                            goto chooseclass;
                     }
                     if (yn == 1)
                     {
                            goto weapon;
                     }
                     cout << " please choose yes or no" <<endl;
           }
           cout<<clrhome;          
           cout << "thats not a class idiot"<<endl;
           goto chooseclass;
           weapon:
           cout <<clrhome;       
           cout <<"ok now you need a weapon.\n so theres 2 types of weapons. ranged and melee.\n";
           cout <<"while ranged do more damage, melees have a greater chance to hit.\n";// IF i actually get that to work. 
           weaponsel:
           cout <<"so do you want a ranged: 1 or a melee: 2\n";
           int weapontype;
           cin >> weapontype;
           if ( weapontype == 1)
           {
                cout<<clrhome;
                goto ranged;
           }
           if( weapontype == 2)
           {
               cout<<clrhome;
               goto melee;
           }
           cout << clrhome;
           cout <<" ok seriously, choose an option."<<endl;
           goto weaponsel;
           
           melee:
           cout << " ok so what weapon do you want? \n hint: theres a weapon that is that is strong,\n and one that is week with you class."<<endl;
           cout << space;
           cout << "so, first off there is the Bible."<<endl;
           cout << "  ,---------."<<endl;
           cout << "  |    _    |"<<endl;
           cout << "  |   -#-   |"<<endl;
           cout << "  |    *    |"<<endl;
           cout << "  |         |"<<endl;
           cout << "  |   the   |"<<endl;
           cout << "  |  Bible  |"<<endl;
           cout << "  ^---------^"<<endl;
           system("PAUSE");
           cout << clrhome;
           cout << "then theres the machete";
           cout << "     .   "<<endl;
           cout << "    /|   "<<endl;
           cout << "   { |   "<<endl;
           cout << "    \\|  "<<endl;
           cout << "   _||_  "<<endl;
           cout << "    U   "<<endl;
           system("pause");
           cout << clrhome;
           cout << "and theres the staff"<<endl;
           cout << "     __     "<<endl;
           cout << "    (  )    "<<endl;
           cout << "     ||     "<<endl;
           cout << "     ||     "<<endl;
           cout << "     ||     "<<endl;
           cout << "    .||.    "<<endl;
           cout << "    |__|    "<<endl;
           cout << "            "<<endl;
           system("pause");
           cout << clrhome;
           cout << "ok so, what do you want?";
           cout << "1. bible 2.machete 3. staff\n";
           cin  >> weapon;
           cout << clrhome;
           if (weapon == '1')
           { 
                      if (clas == '3')
                      {
                               cout << " you grab your bible with a holy hand" << endl;
                               atk=20;
                               acc=75;
                               goto playerend;
                               }
                      if (clas == '2') 
                      {
                               cout << "you fumble the bible around in your hands as its burns you";
                               atk=10;
                               acc=65;
                               goto playerend;
                               }
                      if (clas == '1') 
                      {
                               cout << "you read the bible looking for spells. \nGiving up you just smack things around with it. ";
                               atk=15;
                               acc=70;
                               goto playerend;
                               }
           }
           if (weapon == '2')
           { 
                      if (clas == '3')
                      {
                               cout << "You stare at the sword, thinking it against your religion, so you sayits for the will of god." << endl;
                               atk=15;
                               acc=70;
                               goto playerend;
                               }
                      if (clas == '2') 
                      {
                               cout << "You swing the sword around like magic,";
                               atk=20;
                               acc=75;
                               goto playerend;
                               }
                      if (clas == '1') 
                      {
                               cout << "You look at your sword,trying to figure out what to do with.  ";
                               atk=10;
                               acc=65;
                               goto playerend;
                               }
           }           
           if (weapon == '3')
                      { 
                      if (clas == '3')
                      {
                               cout << "You try to spin the staf around, droping it on your head." << endl;
                               atk=10;
                               acc=65;
                               goto playerend;
                               }
                      if (clas == '2') 
                      {
                               cout << "you think its awfully primitive, but what the hell, its big and hard.";
                               atk=15;
                               acc=70;
                               goto playerend;
                               }
                      if (clas == '1') 
                      {
                               cout << " you pick up the staff feel a strong power corse though you. woot.";
                               atk=20;
                               acc=75;
                               goto playerend;
                               }
           }         
           
           
           ranged:
                             cout << " ok so what weapon do you want? \n hint: theres a weapon that is that is strong,\n and one that is week with you class."<<endl;
           cout << space;
           cout << "so, first off there is the crucifix."<<endl;
           cout << "    .^.    "<<endl;
           cout << "    | |    "<<endl;
           cout << "   /   \\  "<<endl;
           cout << ".-'  j   '-."<<endl;
           cout << "*-.\\   /.-*"<<endl;
           cout << "    | |    "<<endl;
           cout << "    | |    "<<endl;
           cout << "    | |    "<<endl;
           cout << "     U     "<<endl; 
           system("PAUSE");
           cout << clrhome;
           cout << "then theres the bow and arrow";
           cout << "     .   "<<endl;
           cout << "    /|   "<<endl;
           cout << "   | |   "<<endl;
           cout << "   | |   "<<endl;
           cout << "    \\|  "<<endl;
           cout << "     . "<<endl;
           system("pause");
           cout << clrhome;
           cout << "and theres the wand"<<endl;
           cout << "      _      "<<endl;
           cout << "     | |     "<<endl;
           cout << "     | |     "<<endl;
           cout << "     | |     "<<endl;
           cout << "     |_|     "<<endl;
           system("pause");
           cout << clrhome;
           cout << "ok so, what do you want?";
           cout << "1. crucifix 2.bow and arrow 3. wand\n";
           cin  >> weapon;
           cout << clrhome;
           if (weapon == '1') weapon = '4';
           if (weapon == '2') weapon = '5';
           if (weapon == '3') weapon = '6';
           if (weapon == '4')
           { 
                      if (clas == '3')
                      {
                               cout << " you hold the crucifix out infront of you, protected from the evil demons. \n ...you think." << endl;
                               atk=30;
                               acc=66;
                               goto playerend;
                               }
                      if (clas == '2') 
                      {
                               cout << "You try to imitate the exorcist, untill you realize you cant do much wth this other than to throw \n it like a boomerang ";
                               atk=20;
                               acc=50;
                               goto playerend;
                               }
                      if (clas == '1') 
                      {
                               cout << "waving the crucifix around like a wand, you find out that it does work, but not too well.";
                               atk=25;
                               acc=60;
                               goto playerend;
                               }
           }
           if (weapon == '5')
           { 
                      if (clas == '3')
                      {
                               cout << "You look at the bow and arrow, then shrugging, thinking why the hell not." << endl;
                               atk=25;
                               acc=60;
                               goto playerend;
                               }
                      if (clas == '2') 
                      {
                               cout << "you pick up the bow and arrow, shoting better than robin hood.";
                               atk=30;
                               acc=70;
                               goto playerend;
                               }
                      if (clas == '1') 
                      {
                               cout << "You pick it up, smaking your self in the arm when you try to shoot it";
                               atk=20;
                               acc=55;
                               goto playerend;
                               }
           }           
           if (weapon == '6')
                      { 
                      if (clas == '3')
                      {
                               cout << "you flick the wand, shooting sparks out and catching your pants on fire." << endl;
                               atk=20;
                               acc=55;
                               goto playerend;
                               }
                      if (clas == '2') 
                      {
                               cout << "you playwith the wand, shooting out a few energy balls in the general direction you wanted it to go.";
                                atk=25;
                                acc=65;
                               goto playerend;
                               }
                      if (clas == '1') 
                      {
                               cout << " you twirl the wand between your figeres, making it glow with power.";
                                atk=30;
                                acc=75;
                               goto playerend;
                               }
           }
             
           playerend:
           plvl = 1;
           patk = atk;
           pacc = acc;
           php = 100;
           cout << "\n atack:"<< atk <<"\n accuracy:"<< acc <<endl;          
           cout <<"\nlets get started."<<endl;
}


void battletut ()
{
          cout << clrhome;
          cout << "ok so, now we should start the battle training."<<endl;
          cout << " first lets show your stats."<< space << "\n atack:"<< patk <<"\n accuracy:"<< pacc << "\nlevel:" << plvl << "\n hp:" << php <<endl;
          system("pause");
          cout << clrhome << " ok so here is your first chalange, defeat this monster."<< endl;
          system("pause");
          cout << clrhome;
          using namespace tutmonster;
          ftut:
          cout << " you are fighting a "<< name <<endl;
          cin.get();
          cout <<" 1. Attack \n 2. Skill \n 3. Item\n 4. Run" << space;
          cout << " first lets attack. type 1 and hit enter"<<endl;
          cin >> a;
          if (a == 1) goto yey;
          cout << " Ok, i said ATTACK, not that."<<endl;
          goto ftut;
          yey:
          double mhp;
          mhp = tutmonster::mhp;
          d = damage (patk,pacc,plvl,tutmonster::macc,tutmonster::mlvl);
          mhp = mhp-d;
          cout << " you do "<< d << " damage"<<endl;
          cout << " hp: " << mhp<<endl;
          cin.get();
          cin.get();
          cout << clrhome << " since it wouldn't be fair if you just got to attack him, now he can atack you\n";
          php= php-25;
          cout << space;
          cout << "he does a cheap shot to the nards, you take 25 damage\n hp:" << php <<endl;
          system("pause");
          cout << clrhome;
          giveitem (1,5);
          itut:
          cout << "you should try to use a potion." << space;
          cout <<"1. Attack \n 2. Skill \n 3. Item\n 4. Run"<< space;
          cout << "use a item. type 3 and hit enter"<<endl;
          cin >> a;
          cout <<clrhome;
          if (a == 3) goto yey2;
          cout << "Ok, i said use an item idiot, not that."<<endl;
          goto itut;
          yey2:
          useitem();
          if (i == 0) goto itut;
          if (i == 1) goto end;
          if (i == 2) goto run;
          else cout << "ok you baddly bork it asshole"<<endl; 
                 
          run:
              cout <<"run"<<endl;
          end: 
                 cout <<"The "<<tutmonster::name<<"runs away in fear.. not really some other man just came and clubed him."<<endl;
            	 cout <<"either way, heres to you killing him, a free level"<<endl;
						  
		  	cin.get();
          }    
          


void room ()
	{
	roomstart:
	cout <<"you are in room "<<position<<". where do you want to go?"<<endl;
	cout <<"1=up 2=down 3=left 4=right"<<endl;
	cin >>rm;
	if (rm==1)
		{
		if (n < H)
			{
				n++;
				goto roomend;
			};
		cout <<"cant go that way"<<endl;
		goto roomstart;
		};

		if (rm==2)
			{
			if (n > 1)
			{
				n--;
				goto roomend;
			};
		cout <<"cant go that way"<<endl;
		goto roomstart;
			};
	if (rm==4)
		{
		if (m < W)
			{
				m++;
				goto roomend;
			};
		cout <<"cant go that way"<<endl;
		goto roomstart;
		};

		if (rm==3)
			{
			if (m > 1)
			{
				m--;
				goto roomend;
			};
		cout <<"cant go that way"<<endl;
		goto roomstart;
			};
	cout<<"i said 1-4 noob"<<endl;
	goto roomstart;
roomend:
        cout <<m << n <<"\n";
		position = ((3*(n-1))+m);			
  }
	   
void battle()
{
	//mon = rand() % nummons;
	cout <<"You encounter a"<<spider::name<<". Prepare for battle";
	bstart:
	cout <<"HP:"<<hp<<endl;
	battlechoice();
	if (a == 1) {goto bfight;}
	if (a == 2) {goto bitem;}
	cout << "come on, just choice it already"<<endl;
	goto bstart;
	bfight:
	damage(patk,pacc,lvl,spider::macc,spider::mlvl);
	cout << " you do " <<d<<" damage to "<<spider::name<<"."<<endl;
	mhp= mhp-d;
	if (mhp <=0) {goto bwin;}
	goto bmon;
	bitem:
	useitem();
	goto bmon;
	bmon:
	cout << "the monster attacks you..."<<endl;
	damage(spider::matk,spider::macc,spider::mlvl,pacc,plvl);
	php= php-d;
	cout <<" he does "<<d<<" damage to you!"<<endl;
	if (php <=0){goto bloose;}
	goto bstart;
	bloose:
	cout<<" oh no, you lost!"<<endl;
	endn=1;
	goto bend;
	bwin:
	exp= exp+spider::mlvl;
	cout <<" Congrats! you won!"<<endl;
	if (position == 9)
	{
                 giveitem(3,1);
                 }
                 
	bend:
	int sdfvsdg;
}
	
	
void end () {cout <<"congrats, you finished the first pre-alpha testing"<<endl;system("pause");}	   
int main(int argc, char *argv[])
{
    //goto battle;;
    //playerinfo ();
    //battle:
    //battletut ();
    playerinfo();
	giveitem (1,5);
    move:
    room ();
	battle ();
	if (key >= 1) {goto win;}
	if (endn == 1) {goto end;}
	goto move;
	end:
	end ();
	win:
    cout << "OMG YOU WON!";
    end();

}
