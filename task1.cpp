//NUMBER GUESSING GAME
#include<bits/stdc++.h>
using namespace std;
int main(){
   
    int RandomNumber = rand(); //Generates random number
    cout<<"A random number is generated , try to guess it!"<<endl;
    int guessNumber;
    cout<<"Your Guess : ";
    do{
        cin>>guessNumber;
        if(guessNumber>RandomNumber){
            cout<<"Too high! try again:";
        }
        else if(guessNumber < RandomNumber){
            cout<<"Too low! Try again: ";
        }

    }
    while(guessNumber!=RandomNumber);
    cout<<"Hurray!! You guessed it right !!"<<endl;
    return 0;
}