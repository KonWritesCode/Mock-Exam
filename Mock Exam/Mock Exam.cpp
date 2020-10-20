//Password is 2569
#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>


void logInPage()
{
    const int passwordLength{ 4 };
    const int maxPasswordAttempts{ 3 };
    const int boardColumn{ 3 };
    const int boardRow{ 3 };
    //char printBoard[boardRow][boardColumn];
    int board[boardRow][boardColumn];

    std::vector<int> password{ 2,5,6,9 };
    int passwordAttempts{ 0 };

    std::vector<int> inputPassword{ 0,0,0,0 };
    int asteriskPosX{ 0 };
    int asteriskPosY{ 0 };

    do
    {
        for (int moves = 0; moves < passwordLength; moves++)
        {
            system("cls");
            if (passwordAttempts > 0 && moves == 0)
            {
                std::cout << "Wrong password, try again!\n";
            }

            //std::cout << "Enter your password\n";

            //Print the screen
            int num{ 0 };
            for (int i = 0; i < boardRow; i++)
            {
                for (int j = 0; j < boardColumn; j++)
                {
                    num++;

                    board[i][j] = num;
                    if (i == asteriskPosY && j == asteriskPosX)
                    {
                        std::cout << "|*";
                    }
                    else
                    {
                        std::cout << "|" << num;
                    }
                }
                std::cout << "|\n";
            }

            char userInput;
            std::cout << "(Use WASD or the arrow keys to navigate)\n";
            std::cout << "input: ";

            switch (userInput = _getch())
            {
            case 72: case 'w': case 'W': //Key Up
                if (asteriskPosY != 0)
                {
                    asteriskPosY--;
                }
                break;

            case 80: case 's': case 'S'://Key Down
                if (asteriskPosY != boardColumn - 1)
                {
                    asteriskPosY++;
                }
                break;

            case 75: case 'a': case 'A': //Key Left
                if (asteriskPosX != 0)
                {
                    asteriskPosX--;
                }
                break;

            case 77: case 'd': case 'D': //Key Right
                if (asteriskPosX != boardRow - 1)
                {
                    asteriskPosX++;
                }
                break;

            default:
                break;
            }

            inputPassword[moves] = board[asteriskPosY][asteriskPosX];
        }
        //std::cout << "Password: ";

        if (password == inputPassword)
        {
            break;
        }

        passwordAttempts++;
        //reset input
        asteriskPosX = 0;
        asteriskPosY = 0;
        //reset input
        for (int i = 0; i < passwordLength; i++)
        {
            inputPassword[i] = 0;
        }
    } while (passwordAttempts < maxPasswordAttempts && password != inputPassword);

    system("cls");
    if
        (passwordAttempts >= maxPasswordAttempts)
    {
        std::cout << "You are out of attempts! Please exit the program\n";
        _getch();
        exit(0);
    }
    else if(password == inputPassword)
    {
        std::cout << "Correct password!\n";
    }
}

void Task1()
{
    system("cls");
    const int timesToRoll{2000};
    int numbersRolled[6]{ 0,0,0,0,0,0 };

    for(int i = 0; i < timesToRoll; i++)
    {
        int roll;
        roll = rand() % 6 + 1;
        numbersRolled[roll - 1]++;

        switch (i)
        {
        case 200:
            std::cout << "After 200 rolls:\n";
            for(int j = 1; j <= 6; j++)
            {
                std::cout << j << ". " << numbersRolled[j - 1] << std::endl;
            }
            break;
        case 500:
            std::cout << "\nAfter 500 rolls:\n";
            for (int j = 1; j <= 6; j++)
            {
                std::cout << j << ". " << numbersRolled[j - 1] << std::endl;
            }
            break;
        case 1000:
            std::cout << "\nAfter 1000 rolls:\n";
            for (int j = 1; j <= 6; j++)
            {
                std::cout << j << ". " << numbersRolled[j - 1] << std::endl;
            }
            break;
        case 1500:
            std::cout << "\nAfter 1500 rolls:\n";
            for (int j = 1; j <= 6; j++)
            {
                std::cout << j << ". " << numbersRolled[j - 1] << std::endl;
            }
            break;
        case 2000:
            std::cout << "\nAfter 2000 rolls:\n";
            for (int j = 1; j <= 6; j++)
            {
                std::cout << j << ". " << numbersRolled[j - 1] << std::endl;
            }
            break;
        default:
            break;
        }
    }
    _getch();
}

void Task2()
{
    system("cls");
    std::vector<int> no;
    std::vector<char> name;
    std::vector<int> value;
    char c;

    //Print the unsorted variables
    std::cout << "UNSORTED:\nNo\tName\tValue\tHealth Bar\n";
    std::cout << "-----------------------------------------\n";
    for(int i = 0; i < 20; i++)
    {
        c = i + 65;
        no.push_back(i);
        name.push_back(c);
        int randomValue = rand() % 20 + 1;
        value.push_back(randomValue);
        std::cout << no.at(i) << "\t" << name.at(i) << "\t" << value.at(i) << "\t";
        for (int j = 0; j < value.at(i); j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    //Print the Sorted variables
    std::cout << "\nSORTED:\nNo\tName\tValue\tHealth Bar\n";
    std::cout << "-----------------------------------------\n";
    //Yes, this is indeed one of the worse methods of sorting systems out there, tried testing with the sort() system in the 
    //algorithm library, but I couldn't get it to work the way I wanted, so I did it this way instead to spare me some time
    for(int k = 0; k < 20; k++)
    {
        for (int i = 0; i < 19; i++)
        {
            int valueTemp1 = value.at(i);
            int valueTemp2 = value.at(i + 1);
            int noTemp1 = no.at(i);
            int noTemp2 = no.at(i + 1);
            char nameTemp1 = name.at(i);
            char nameTemp2 = name.at(i + 1);

            if (value.at(i) > value.at(i + 1))
            {
                value.at(i) = valueTemp2;
                value.at(i + 1) = valueTemp1;
                no.at(i) = noTemp2;
                no.at(i + 1) = noTemp1;
                name.at(i) = nameTemp2;
                name.at(i + 1) = nameTemp1;
            }
        }
    }
    

    for (int i = 0; i < 20; i++)
    {
        std::cout << no.at(i) << "\t" << name.at(i) << "\t" << value.at(i) << "\t";
        for (int j = 0; j < value.at(i); j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    _getch();
}

int Task3()
{
    int packmanPosY{1};
    int packmanPosX{1};
    bool stopPlaying{false};

    char grid[10][10] = {
        {'+','#','#','#','#','#','#','#','#','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ','#',' ','#','#',' ','#',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|','#',' ','#','#','#','#',' ','#','|'},
        {'|',' ',' ',' ','#','#',' ',' ',' ','|'},
        {'|',' ','#',' ',' ',' ',' ','#',' ','|'},
        {'|',' ','#','#',' ',' ','#','#',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|','#','#','#','#','#','#','#','#','|'},
    };

    do
    {
        system("cls");
        //Print Grid
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (packmanPosY == i && packmanPosX == j)
                {
                    std::cout << "E ";
                }
                else
                {
                    std::cout << grid[i][j] << " ";
                }
            }
            std::cout << "\n";
        }

        char userInput;
        std::cout << "(Use WASD or the arrow keys to navigate, or press 'G' to exit)\n";
        std::cout << "input: ";
        //Move the player
        switch (userInput = _getch())
        {
        case 72: case 'w': case 'W': //Key Up
            if (grid[packmanPosY - 1][packmanPosX] != '#' && grid[packmanPosY - 1][packmanPosX] != '|')
            {
                packmanPosY--;
            }
            break;

        case 80: case 's': case 'S'://Key Down
            if (grid[packmanPosY + 1][packmanPosX] != '#' && grid[packmanPosY + 1][packmanPosX] != '|')
            {
                packmanPosY++;
            }
            break;

        case 75: case 'a': case 'A': //Key Left
            if (grid[packmanPosY][packmanPosX - 1] != '#' && grid[packmanPosY][packmanPosX - 1] != '|')
            {
                packmanPosX--;
            }
            break;

        case 77: case 'd': case 'D': //Key Right
            if (grid[packmanPosY][packmanPosX + 1] != '#' && grid[packmanPosY][packmanPosX + 1] != '|')
            {
                packmanPosX++;
            }
            break;

        case 'g': case 'G':
            return (0);

        default:
            break;
        }

    } while (stopPlaying == false);

    _getch();
}

void Task4()
{

    int enemyPosY{ 8 };
    int enemyPosX{ 1 };
    int aiDirection{ 1 };
    int packmanPosY{ 1 };
    int packmanPosX{ 1 };

    const int dotsToSpawn{ 15 };
    char DOT = '-';
    int score{ 0 };
    bool gameEnded{ false };

    char grid[10][10] = {
        {'+','#','#','#','#','#','#','#','#','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|',' ','#',' ','#','#',' ','#',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|','#',' ','#','#','#','#',' ','#','|'},
        {'|',' ',' ',' ','#','#',' ',' ',' ','|'},
        {'|',' ','#',' ',' ',' ',' ','#',' ','|'},
        {'|',' ','#','#',' ',' ','#','#',' ','|'},
        {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
        {'|','#','#','#','#','#','#','#','#','|'},
    };

    //Creates dots around the grid
    for(int i = 0; i < dotsToSpawn; i++)
    {
        int randPosY;
        int randPosX;
        do
        {
            randPosY = rand() % 10;
            randPosX = rand() % 10;
        } while (grid[randPosY][randPosX] != ' ');

        grid[randPosY][randPosX] = DOT;
    }

    //Game loop
    do
    {
        system("cls");
        //Print Board
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (packmanPosY == i && packmanPosX == j)
                {
                    std::cout << "E ";
                }
                else if(enemyPosY == i && enemyPosX == j)
                {
                    std::cout << "W ";
                }
                else
                {
                    std::cout << grid[i][j] << " ";
                }
            }
            if (i == 1)
            {
                std::cout << "   Score: " << score;
            }

            std::cout << "\n";
        }

        char userInput;
        std::cout << "(Use WASD or the arrow keys to navigate)\n";
        std::cout << "input: ";

        //Player Movement
        switch (userInput = _getch())
        {
        case 72: case 'w': case 'W': //Key Up
            if (grid[packmanPosY - 1][packmanPosX] != '#' && grid[packmanPosY - 1][packmanPosX] != '|')
            {
                if(grid[packmanPosY - 1][packmanPosX] == DOT)
                {
                    grid[packmanPosY - 1][packmanPosX] = ' ';
                    score++;
                }
                packmanPosY--;
            }
            break;

        case 80: case 's': case 'S'://Key Down
            if (grid[packmanPosY + 1][packmanPosX] != '#' && grid[packmanPosY + 1][packmanPosX] != '|')
            {
                if (grid[packmanPosY + 1][packmanPosX] == DOT)
                {
                    grid[packmanPosY + 1][packmanPosX] = ' ';
                    score++;
                }
                packmanPosY++;
            }
            break;

        case 75: case 'a': case 'A': //Key Left
            if (grid[packmanPosY][packmanPosX - 1] != '#' && grid[packmanPosY][packmanPosX - 1] != '|')
            {
                if (grid[packmanPosY][packmanPosX - 1] == DOT)
                {
                    grid[packmanPosY][packmanPosX - 1] = ' ';
                    score++;
                }
                packmanPosX--;
            }
            break;

        case 77: case 'd': case 'D': //Key Right
            if (grid[packmanPosY][packmanPosX + 1] != '#' && grid[packmanPosY][packmanPosX + 1] != '|')
            {
                if (grid[packmanPosY][packmanPosX + 1] == DOT)
                {
                    grid[packmanPosY][packmanPosX + 1] = ' ';
                    score++;
                }
                packmanPosX++;
            }
            break;

        default:
            break;
        }

        //AI
        //1 = up, 2 = right, 3 = down, 4 = left
        bool aiTurnFinished{ false };


        do
        {
            aiTurnFinished = false;
            switch (aiDirection)
            {
            case 1:
                if (grid[enemyPosY - 1][enemyPosX] != '#' && grid[enemyPosY - 1][enemyPosX] != '|')
                {
                    if (enemyPosY - 1 == packmanPosY && enemyPosX == packmanPosX)
                    {
                        gameEnded = true;
                    }
                    enemyPosY--;
                    aiTurnFinished = true;
                }
                else { aiDirection = rand() % 4 + 1; }
                break;
            case 2:
                if (grid[enemyPosY][enemyPosX + 1] != '#' && grid[enemyPosY][enemyPosX + 1] != '|')
                {
                    if (enemyPosY == packmanPosY && enemyPosX + 1 == packmanPosX)
                    {
                        gameEnded = true;
                    }
                    enemyPosX++;
                    aiTurnFinished = true;
                }
                else { aiDirection = rand() % 4 + 1; }
                break;
            case 3:
                if (grid[enemyPosY + 1][enemyPosX] != '#' && grid[enemyPosY + 1][enemyPosX] != '|')
                {
                    if (enemyPosY + 1 == packmanPosY && enemyPosX == packmanPosX)
                    {
                        gameEnded = true;
                    }
                    enemyPosY++;
                    aiTurnFinished = true;
                }
                else { aiDirection = rand() % 4 + 1; }
                break;
            case 4:
                if (grid[enemyPosY][enemyPosX - 1] != '#' && grid[enemyPosY][enemyPosX - 1] != '|')
                {
                    if (enemyPosY == packmanPosY && enemyPosX - 1 == packmanPosX)
                    {
                        gameEnded = true;
                    }
                    enemyPosX--;
                    aiTurnFinished = true;
                }
                else { aiDirection = rand() % 4 + 1; }
                break;
            default:
                break;
            }
        } while (aiTurnFinished == false);
    } while (gameEnded == false && score < dotsToSpawn);

    system("cls");
    if(gameEnded == true)
    {
        std::cout << "\nYou got killed! Game over!\n";
    }
    else if(score == dotsToSpawn)
    {
        std::cout << "\nYou won! Congratulations!\n";
    }
    _getch();
}

void Menu()
{
    int input{ 0 };
    do
    {
        system("cls");
        std::cout << "1. Task 1\n2. Task 2\n3. Task 3\n4. Task 4\n5. Quit the program\n\n";
        std::cout << "Type the number of which task you would like to see: ";
        std::cin >> input;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

            std::cout << "Type the number of which task you would like to see: ";
            std::cin >> input;
        }

        switch (input)
        {
        case 1:
            Task1();
            break;

        case 2:
            Task2();
            break;

        case 3:
            Task3();
            break;

        case 4:
            Task4();
            break;

        case 5:
            exit(0);
            break;

        default:
            system("cls");
        }
    } while (true);

}


int main()
{
    srand(time(NULL));
    //Password = 2569
    logInPage();
    system("cls");
    Menu();
    return(0);
}