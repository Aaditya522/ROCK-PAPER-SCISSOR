#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib> // For rand and srand
#include<ctime>
#include<stdlib.h> // file used for cls;
using namespace std;

class Game{
    public:
    string sign;
    int score;
    Game(){
        score=0;
    }
};

class player : public Game{
    public:
    player(){
        //default;
    }

    string setValue(int value){
        if(value==1){
          sign = "rock";
        }
        else if(value==2){
            sign = "paper";
        }
        else if(value==3){
            sign = "scissor";
        }
        return sign;
    }

    int points(){
        score++;
        return score;
    }

};

class bot : public Game{
    public:
    bot(){
        //default;
    }
    string setValue(){
        int value = 1 + (rand() % 3);
            if(value==1){
                sign = "rock";
            }
            else if(value==2){
                sign = "paper";
            }
            else if(value==3){
                sign = "scissor";
            }

          return sign;
    }

    int points(){
        score++;
        return score;
    }
};



int main(){

    srand(static_cast<unsigned int>(time(0)));

    cout<<endl;   //HEADING TITLE;
    for(int i=0;i<19;i++){
        if(i==9){
            cout<<" ROCK-PAPER-SCISSOR ";
        }
        else{
            cout<<"#";
        }
    }
    cout<<endl<<endl;

    cout<< "Please Hit 'S + Enter' to continue..."<<endl;

    string input;
    cin>>input;
    cout<<endl<<endl;
    
    int p_score=0;
    int b_score=0;


    cout<<"Select '1' for Rock, "<< endl <<"Select '2' for Paper and"<< endl <<"Select '3' for Scissor."<<endl<<endl;

    int n_times=0;
    cout<<"Enter the duration of the Game: ";cin >> n_times;
    cout<<endl<<endl;

    cout<<"Have a nice Gameplay! "<<endl<<endl;
    int n = n_times;

    if(input == "s" || input == "s" ){   //PLAYER VS BOT;
        player p;
        bot b;

        for(int i=0;i<n;i++){
            int value;
            do {
                cout << "Enter '0' to Exit the Game.................................... OR"<<endl;
                cout << "Enter '1', '2', or '3': ";
                cin >> value; cout<<endl<<endl;
            }while(value < 0 || value > 3); 

            system("cls"); //erases previous outputs;

            if(value==0){   //EXITING THE GAME;
                cout<<"Exited Successfully"<<endl;
                break;
                return 0; 
            }
        string str1=p.setValue(value);   // player's input for rock-paper-scissor;
        string str2=b.setValue();        // bot's input for rock-paper-scissor;

        if(str1==str2){
            cout<<"It's a tie!"<<endl<<endl;
            n++;
            continue;
        }
        else{
            if((str1 == "rock" && str2 == "scissor") || (str1 == "paper" && str2 == "rock") || (str1 == "scissor" && str2 == "paper")){
                
                cout<<"Player's: "<<str1<<" and "<<" Bot's: "<<str2<<endl;
                p_score = p.points();
                cout << "Player's score: " << p_score << endl;
                cout << "Bot's score: " << b_score << endl << endl;
            }   // PLAYER winning;
            else{
                cout<<"Player's: "<<str1<<" and "<<" Bot's: "<<str2<<endl;
                b_score = b.points();
                cout << "Player's score: " << p_score << endl;
                cout << "Bot's score: " << b_score << endl << endl;
            }   // BOT winning;
        }
    }       //FOR LOOP;
    }       //PLAYER VS BOT;



    if(p_score == b_score){
        cout << "It's a tie!"<<endl;
    }
    else if(p_score>b_score){
        cout<<"Congratulations! You won with "<<p_score<<" points."<<endl;
    }
    else{
        cout<<"Bot Win with "<<b_score<<" points." <<endl;
    }
    return 0;
 }