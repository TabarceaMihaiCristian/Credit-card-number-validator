//Credit card number validator
//Luhn algorithm

#include <bits/stdc++.h>
using namespace std;

// Function that finds and eliminates spaces from the inputed card number
void find_spaces(char card_number[], int &l);

// Function that separates the numbers greater than 9 in 2 digits
int getdigits(int number);

// Function that adds the double of every second digit from right to left 
int sumoddpos(char card_number[], int l);

// Function that adds all the odd numbered digits from right to left
int sumevenpos(char card_number[], int l);

int main(){

    char card_number[50];
    int lenght;
  
    cout<<"Enter a credit card number:"<<"\n";
    cin.getline(card_number,50); // Input of the credit card number
    lenght = strlen(card_number); // Lenght of the inputed string representing the card number

    find_spaces(card_number, lenght);

    int result; // Final result that will contain the sum of the two sums returned by the functions
    result = sumoddpos(card_number, lenght) + sumevenpos(card_number, lenght);

    if(!(result % 10)) // If the result is divisble by 10 than the card number is a valid one; Else it is not a valid card number
        cout<<"VALID CARD NUMBER"<<"\n";
    else
        cout<<"INVALID CARD NUMBER"<<"\n";
        
    return 0;
}

// Function that eliminates the spaces from the inputed string representing the card number
void eliminate_spaces(char card_number[], int poz, int &l){

    for(int i = poz; i < l-1; i++)
        card_number[i] = card_number[i+1];

    l--;
    card_number[l] = 0;
}

void find_spaces(char card_number[], int &l){

    for(int i = 0; i < l; i++)
        if(card_number[i] == ' '){
             eliminate_spaces(card_number, i, l);
            i--;
        }
}

int getdigits(int number){

    return (number % 10 + (number / 10) % 10);
}

int sumoddpos(char card_number[20], int l){

    int sum = 0;

    for(int i = l-2; i >= 0; i-=2)
        sum += getdigits((card_number[i] - '0') * 2);

    return sum;
}

int sumevenpos(char card_number[20], int l){
    
    int sum = 0;

    for(int i = l-1; i >= 0; i-=2)
        sum += (card_number[i] - '0');

    return sum;
}
