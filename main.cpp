//Assignment 1
//https://www.learncpp.com/cpp-tutorial/chars/
//Data Sctructures & Algorithms


#include "GenStack.cpp"
#include <fstream> //Needed to work with files
#include <string>

using namespace std;

int main(int argc, char **argv)

{

    //   _    __                                   __   ____  __      _           __      
    //  | |  / /___ ___________   ____ _____  ____/ /  / __ \/ /_    (_)__  _____/ /______
    //  | | / / __ `/ ___/ ___/  / __ `/ __ \/ __  /  / / / / __ \  / / _ \/ ___/ __/ ___/
    //  | |/ / /_/ / /  (__  )  / /_/ / / / / /_/ /  / /_/ / /_/ / / /  __/ /__/ /_(__  ) 
    //  |___/\__,_/_/  /____/   \__,_/_/ /_/\__,_/   \____/_.___/_/ /\___/\___/\__/____/  
    //                                                         /___/                  

    string userInput = "";
    ifstream inputFile; //takes file form command line
    GenStack<char> charStack(128);
    GenStack<int> intStack(128); 

    char currentChar = ' ';
    char lastChar = ' '; //used for checking for comments
    char secondFromLastChar = ' '; //used for checking for comments
    unsigned int lineNumber = 1;
    bool isLineComment = false;
    bool isInQuote = false;
    bool isInChar = false;
    bool isInMultilineComment = false;

    //     ____                   _                _______ __   
    //    / __ \____  ___  ____  (_)___  ____ _   / ____(_) /__ 
    //   / / / / __ \/ _ \/ __ \/ / __ \/ __ `/  / /_  / / / _ \
    //  / /_/ / /_/ /  __/ / / / / / / / /_/ /  / __/ / / /  __/
    //  \____/ .___/\___/_/ /_/_/_/ /_/\__, /  /_/   /_/_/\___/ 
    //      /_/                       /____/                    
    

    //a la Assignment 1
    while (!(userInput == "stop" || userInput == "s" || userInput == "exit" || userInput == "no" || userInput == "Don't make me hit ctrl c"))
    {

        if (userInput == "")
        {
            inputFile.open(argv[1]);
        } else
        {
            inputFile.open(userInput);
        }

    //     ________              __      ____                  __        __      
    //    / ____/ /_  ___  _____/ /__   / __ )_________ ______/ /_____  / /______
    //   / /   / __ \/ _ \/ ___/ //_/  / __  / ___/ __ `/ ___/ //_/ _ \/ __/ ___/
    //  / /___/ / / /  __/ /__/ ,<    / /_/ / /  / /_/ / /__/ ,< /  __/ /_(__  ) 
    //  \____/_/ /_/\___/\___/_/|_|  /_____/_/   \__,_/\___/_/|_|\___/\__/____/  
    //   


        while (inputFile.get(currentChar)) // loop getting single characters
        {
            //     ____              ___    __  ___               __       __    _____               
            //    /  _/__ _  _____ _/ (_)__/ / / _ )_______ _____/ /_____ / /_  / ___/__ ____ ___ ___
            //   _/ // _ \ |/ / _ `/ / / _  / / _  / __/ _ `/ __/  '_/ -_) __/ / /__/ _ `(_-</ -_|_-<
            //  /___/_//_/___/\_,_/_/_/\_,_/ /____/_/  \_,_/\__/_/\_\\__/\__/  \___/\_,_/___/\__/___/
            //

            //Line comment                                                             
            if (currentChar == '/' && lastChar == '/' && !isInChar && !isInQuote && !isInMultilineComment)
                {isLineComment = true;}

            //In quote
            if (currentChar == '\"' && !isInChar && !isLineComment && !isInMultilineComment)
            {
                if (isInQuote)
                    isInQuote = false;
                else 
                    isInQuote = true;
            }

            //In char
            if (currentChar == '\'' && !isInQuote && (lastChar != '\\' || secondFromLastChar == '\\') && !isLineComment && !isInMultilineComment)
            {
                if (isInChar)
                    isInChar = false;
                else 
                    isInChar = true;
            }

            //Multiline Quote
            if (lastChar == '/' && currentChar == '*' && !isLineComment && !isInQuote)
                {isInMultilineComment = true;}

            if (lastChar == '*' && currentChar == '/' && !isLineComment)
                {isInMultilineComment = false;}

            secondFromLastChar = lastChar;
            lastChar = currentChar;
            //    _______           __    _             ___               __       __    
            //   / ___/ /  ___ ____/ /__ (_)__  ___ _  / _ )_______ _____/ /_____ / /____
            //  / /__/ _ \/ -_) __/  '_// / _ \/ _ `/ / _  / __/ _ `/ __/  '_/ -_) __(_-<
            //  \___/_//_/\__/\__/_/\_\/_/_//_/\_, / /____/_/  \_,_/\__/_/\_\\__/\__/___/
            //                                /___/                                      
            if (!(isLineComment || isInQuote || isInChar || isInMultilineComment))  //Makes sure it's a valid bracket
            {
                if (currentChar == '(' || currentChar == '{' || currentChar == '[')
                    {
                        charStack.push(currentChar);
                        intStack.push(lineNumber);
                    }
                else if (currentChar == ')' || currentChar == '}' || currentChar == ']')
                {
                    if(charStack.isEmpty())
                    {
                        cout << "Error: " << currentChar << " at line " << lineNumber << " doesn't have starting bracket." << endl;
                        return 1;
                    }
                    if
                    (  (charStack.peek() == '(' && currentChar == ')' ) 
                    || (charStack.peek() == '{' && currentChar == '}' ) 
                    || (charStack.peek() == '[' && currentChar == ']' ))
                        {
                            charStack.pop();
                            intStack.pop();
                        }
                    else
                        {
                            cout << "Error: " << charStack.peek() << " from line "<< intStack.peek() << " not completed before " << currentChar << " at line " << lineNumber <<endl;
                            return 1;
                        }
                }
            }

            //     ____    __    __  __       _  __        __    __   _         
            //    / __/__ / /_  / / / /__    / |/ /____ __/ /_  / /  (_)__  ___ 
            //   _\ \/ -_) __/ / /_/ / _ \  /    / -_) \ / __/ / /__/ / _ \/ -_)
            //  /___/\__/\__/  \____/ .__/ /_/|_/\__/_\_\\__/ /____/_/_//_/\__/ 
            //                     /_/                                          
            if (currentChar == '\n')
                {
                    lineNumber++;
                    isLineComment = false;
                    isInQuote = false;
                    isInChar = false;
                }
        }                                         

            //    _______           __         __         _             __                __       __    
            //   / ___/ /  ___ ____/ /__  ____/ /__  ___ (_)__  ___ _  / /  _______ _____/ /_____ / /____
            //  / /__/ _ \/ -_) __/  '_/ / __/ / _ \(_-</ / _ \/ _ `/ / _ \/ __/ _ `/ __/  '_/ -_) __(_-<
            //  \___/_//_/\__/\__/_/\_\  \__/_/\___/___/_/_//_/\_, / /_.__/_/  \_,_/\__/_/\_\\__/\__/___/
            //                                                /___/                                      
        if (!(charStack.isEmpty()))
            {
                cout << "Error: unclosed " << charStack.pop() << " bracket at line number "<< lineNumber << endl;
                return 1;
            }

            //     _  __       ____                       ____                  __
            //    / |/ /__    / __/__________  _______   / __/__  __ _____  ___/ /
            //   /    / _ \  / _// __/ __/ _ \/ __(_-<  / _// _ \/ // / _ \/ _  / 
            //  /_/|_/\___/ /___/_/ /_/  \___/_/ /___/ /_/  \___/\_,_/_//_/\_,_/  
            //                                                                    

            cout << "No bracket syntax errors detected." << endl;
            
            inputFile.close();

            cout << endl << "That was a pretty cool syntax check, right?" << endl << "If you want to take it for another wirl, just enter the name of a file" << endl << "...Or enter \"exit\" to stop the program" << endl;

            cin >> userInput;

    }

}