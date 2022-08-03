//tic-tac-toe game

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char Board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int current_player;
char current_marker;

bool placemarker(int slot)
{
 int row=slot/3;
 int col;

 if(slot%3==0)
 {
    row=row-1;
    col=2;
 }
 else
    col=slot%3-1;


if(Board[row][col]!='x' && Board[row][col]!='o')
{  
    Board[row][col]=current_marker;
    return true;
}
else
{return false;}  

}

void swap_marker_and_player()
{
    if(current_player==1){current_player=2;}
    else {current_player=1;}
    
    if(current_marker=='x'){current_marker='o';}
    else {current_marker='x';}

}

void DrawBoard()
{
    
    cout<<" "<<Board[0][0]<<"|"<<" "<<Board[0][1]<<" "<<"|"<<" "<<Board[0][2]<<endl;
    cout<<" --------\n";
    cout<<" "<<Board[1][0]<<"|"<<" "<<Board[1][1]<<" "<<"|"<<" "<<Board[1][2]<<endl;
    cout<<" --------\n";
    cout<<" "<<Board[2][0]<<"|"<<" "<<Board[2][1]<<" "<<"|"<<" "<<Board[2][2]<<endl;
    cout<<"\n";
}

int winner()
{
  if( (Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2])
       || (Board[0][2]==Board[1][1] && Board[1][1]==Board[2][0])
       || (Board[0][0]==Board[0][1] && Board[0][1]==Board[0][2])
       || (Board[1][0]==Board[1][1] && Board[1][1]==Board[1][2])
       || (Board[2][0]==Board[2][1] && Board[2][1]==Board[2][2])
       || (Board[0][0]==Board[1][0] && Board[1][0]==Board[2][0])
       || (Board[0][1]==Board[1][1] && Board[1][1]==Board[2][1])
       || (Board[0][2]==Board[1][2] && Board[1][2]==Board[2][2]))
       { return current_player;}
  else 
      return -1;
}
void computer_chance()
{   int slot,player_win;
    current_player=2;
    if (current_marker=='x'){current_marker='o';}
    else{current_marker='x';}
    srand(time(NULL));
    slot= rand()%(9-1+1)+1;

    while(!placemarker(slot))
        {  
           slot= rand()%(9-1+1)+1;  // either it will go in loop bcs slot is passed which is constant ,we need passed generated random slot
        }
        
}

void Game()
{
    int slot,player_win,choice;
    char player1_marker;
   cout<<"Welcome to Tic-Tac-Toe!!..."<<endl;
   cout<<"**Menu**...."<<endl;
   cout<<"1.Play against a friend"<<endl;
   cout<<"2.Play against a Computer"<<endl;
   cout<<"3.exit"<<endl;
   cout<<"Enter your choice.."<<endl;
   cin>>choice;

   switch(choice)
   {
   case 1:
    {cout<<"Player1 choose your marker 'x' or 'o'\n";
    cin>>current_marker;
    current_player=1;
    DrawBoard();
    
    for(int i=0;i<9;i++)
    {
        cout<<"Player"<<current_player<<" it's your turn..Please select your slot...\n";
        cin>>slot;
       
       if(slot<1 || slot>9)
       {
         cout<<"slot is invalid!..Try another!.."<<endl;
            i--;continue;
       }
        if(!placemarker(slot))
        {
            cout<<"That slot is occupied!!.Try another slot.."<<endl;
            i--;continue;
        }
        
        DrawBoard();
       
        player_win=winner();
        if(player_win==1){
            cout<<"congratulations!!! player 1 won"<<endl;
            break; }
        if(player_win==2){
            cout<<"congratulations!!! player 2 won"<<endl;
            break; }  
        
        swap_marker_and_player();
       

    }
    if(player_win==-1)
    {cout<<"game is tied...\n";}  
    break;
   }
   case 2:
   { cout<<"Choose your marker 'x' or 'o'\n";
    cin>>player1_marker;
    current_player=1;

    DrawBoard();
    
    for(int i=0;i<5;i++)
    {
        cout<<" it's your turn..Please select your slot...\n";
        cin>>slot;
          current_marker=player1_marker;
          current_player=1;

       if(slot<1 || slot>9)
       {
         cout<<"slot is invalid!..Try another!.."<<endl;
            i--;continue;
       }
        if(!placemarker(slot))
        {
            cout<<"That slot is occupied!!.Try another slot.."<<endl;
            i--;continue;
        }
        
        DrawBoard();

        player_win=winner();
        if(player_win==1){
            cout<<"congratulations!!! player 1 won"<<endl;
            break; }
        if(player_win==2){
            cout<<"congratulations!!! player 2 won"<<endl;
            break; }  
        
      if(i!=4) { computer_chance();  
        
         DrawBoard();

        player_win=winner();
        if(player_win==1){
            cout<<"congratulations!!! player 1 won"<<endl;
            break; }
        if(player_win==2){
            cout<<"congratulations!!! player 2 won"<<endl;
            break; }  
      }
    }


    if(player_win==-1){cout<<"game is tied...\n";}  
    break;
       
   }}
}

int main()
{
     //srand() used for random number , when we used rabd() it generates random number
     // but there is problem with that it will generate same random no until we don't close programme & opem again
     // but we need random no everysingle time during same run srand(x) produce random no except x but it also repeats 
     // so to produce evry time we need to change x also every run it is done using time by adding
     // ctime & cstdlib fun c stands for library from c language

    Game();
    return 0;
}