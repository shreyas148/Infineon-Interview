#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;


// Function to read bias from file
double read_bias() {
    int bias = 50;
    ifstream myfile ("bias.txt");
    myfile >> bias;
    return bias;
}

// Function to simulate a biased coin flip
bool coin_flip(double bias) {
    int randoml = rand()%100;
    if (randoml > bias){
        cout << "tails" << endl;
    } else {
        cout << "heads" << endl;
    }

    return randoml > bias;
}

int main() {
    double bias = read_bias();
    
    bool first_flip, second_flip;
    do {
        first_flip = coin_flip(bias);
        second_flip = coin_flip(bias);
        if (first_flip && !second_flip) {
            cout << "Person 1 wins!" << endl;
        } else if (!first_flip && second_flip) {
            cout << "Person 2 wins!" << endl;
        } else {
            cout << "Toss discarded, flipping again.\n" << endl;
        }
    } while (first_flip == second_flip); // Redo if both flips are the same
    
    return 0;
}

