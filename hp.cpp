#include <iostream>
#include <ctime>
using namespace std;

const int rows = 7;
const int col = 7;

int maxships =11;
int matrix[rows][col];
 //Clearing the Matrix:
void Clear()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
 
//Displaying the Game Board:
void Displaytheboard()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


//Counting the Number of Ships:
int Ships()
{
    int a = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 1)
                a++;
        }
    }
    return a;  
}

//Placing Ships Randomly:

void Placeships()
{
    int d = 0;
    while (d < maxships)
    {
        int x = rand() % rows;
        int y = rand() % col;
        if (matrix[x][y] != 1)
        {
            d++;
            matrix[x][y] = 1;
        }
    }
}


//Attacking Ships:
bool Guess(int x, int y)
{
    if (matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}


//Main Function:
int main()
{
    srand(time(NULL));
    Clear();
    Placeships();
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    int ml, ml2;
    char prompt;
    while (1)
    {
      
        cout << "Enter your location";
        cin >> ml >> ml2;
        if (Guess(ml, ml2))
            cout << "Hit" << endl;
        else
            cout << "Miss" << endl;
        cout << "There are ships: " << Ships() << endl;
        cout << "do you want to continue (y/n)";
        cin >> prompt;
        if (prompt == 'n')
            break;
    }
    system("clear");
    cout << "Game Over!" << endl;
    Displaytheboard();
    getchar();
    return 0;
}
