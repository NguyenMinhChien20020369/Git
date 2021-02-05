#include<bits/stdc++.h>
using namespace std;

const int number_of_wrong_guesses_max=7;

string choose_word(){
    int word_count=0;string word;
    ifstream input("word_array.txt");
    while(!input.eof())
    {
        input>>word;word_count++;
    }
    ifstream input1("word_array.txt");
    int random_number=rand()%word_count+1;
    for(int i=0;i<random_number;i++)
    {
        input1>>word;
    }
    return word;
}

void initialization(string& guessed_word,string& secret_word){
    for(int i=0;i<secret_word.length();i++){
        guessed_word+="-";
    }
}

void enter_and_update(char& guess_word,string& secret_word,string& guessed_word,int& number_of_wrong_guesses){
    cout<<"Your guess: ";
    cin>>guess_word;bool check=false;
    for(int i=0;i<secret_word.length();i++){
        if(secret_word[i]==guess_word){
            check=true;
            guessed_word[i]=guess_word;
        }
    }
    if(!check){
            number_of_wrong_guesses++;
        }
}

const string figure[]=
{
         "   -------------    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |                \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |                \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |           |    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|    \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |                \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          /     \n"
         "   |     \n"
         " -----   \n",
         "   -------------    \n"
         "   |           |    \n"
         "   |           O    \n"
         "   |          /|\\  \n"
         "   |          / \\  \n"
         "   |     \n"
         " -----   \n",
};

void render_game(char& guess_word,string& secret_word,string& guessed_word,int& number_of_wrong_guesses)
{
    cout<<figure[number_of_wrong_guesses]<<endl;
    cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    do{
        enter_and_update(guess_word,secret_word,guessed_word,number_of_wrong_guesses);
        cout<<figure[number_of_wrong_guesses]<<endl;
        cout<<guessed_word<<endl<<"Number of wrong guesses: "<<number_of_wrong_guesses<<endl;
    }while(number_of_wrong_guesses<number_of_wrong_guesses_max&&guessed_word!=secret_word);
}

void play_hang_man()
{
    char t;
    do{
    srand(time(0));
    string secret_word=choose_word(),guessed_word;
    initialization(guessed_word,secret_word);
    char guess_word;
    int number_of_wrong_guesses=0,maximum_number_of_wrong_guesses=number_of_wrong_guesses_max;
    render_game(guess_word,secret_word,guessed_word,number_of_wrong_guesses);
    if(number_of_wrong_guesses==number_of_wrong_guesses_max){
        cout<<"You lose. The correct word is "<<secret_word<<endl;
    }else cout<<"Congratulations! You win!"<<endl;
    cout<<"Enter "<<'"'<<"y"<<'"'<<" to continue, enter a character that does not match "<<'"'<<"y"<<'"'<<" to stop: ";
    cin>>t;
    }while(t=='y');
}

int main(){
    play_hang_man();
}


