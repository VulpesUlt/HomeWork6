// HomeWork6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>


const int RANG = 4;

void printArr (int *arrPtr, int arrLength) // Функция для задания 1
{
    if (arrPtr != nullptr)
    {
        for (int i = 0; i < arrLength; i++)
            std::cout << arrPtr[i] << "  ";
        std::cout << "\n Array was successfully printed! \n";
    }
    else
        std::cout << "An error has ocured.";
}

void printArr(int** arrPtr, int arrLength, int ArrHight) // Функция для задания 2
{
    if (arrPtr != nullptr)
    {
        for (int i = 0; i < arrLength; i++)
        {
            for (int j = 0; j < ArrHight; j++)
                std::cout << arrPtr[i][j] << "  ";
            std::cout << std::endl;
        }
        std::cout << "\n Array was successfully printed! \n";
    }
    else
        std::cout << "An error has ocured.";

}

int** initArr(int arrLength, int arrayHight) // Функция для заданий 1 и 2
{
    if (arrLength != 0)
    {
        if (arrayHight == 0)
        {
            int* arrPtr = new int[arrLength];
            for (int i = 0; i < arrLength; i++)
                arrPtr[i] = pow(2, i + 1);
            return &arrPtr;
        }
        else
        {
            int** arrPtr = new int*[arrLength];
            for (int i = 0; i < arrLength; i++)
            {
                arrPtr[i] = new int[arrayHight];
                for (int j = 0; j < arrayHight; j++)
                    arrPtr[i][j] = rand() % 100;
            }
            return arrPtr;
        }
    
    
    }
    else
    {
        std::cout << "An error has ocured.";
        return nullptr;
    } 
}

bool deleteArr(int* arr, int arrLength) // Функция для задания 1
{
    if (arr != nullptr)
    {
        delete[] arr;
        std::cout << "Array was deleted. \n";
        return true;
    }
    else 
    {
        std::cout << "Array was not deleted. \n";
        return false;
    }

}

bool deleteArr(int** arr, int arrLength) // Функция для задания 2
{
    if (arr != nullptr)
    {
        for (int i = 0; i < arrLength; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        std::cout << "Array was deleted. \n";
        return true;
    }
    else
    {
        std::cout << "Array was not deleted. \n";
        return false;
    }

}

void createFile() // Функция для задания 3
{
    const int LENGTH = 10;
    std::cout << "Enter your first file name:";
    std::string name;
    std::cin >> name;
    std::ofstream fileOne( name + ".txt" );
    int* arrPtrOne = *initArr(LENGTH, 0);
    for (int i = 0; i < LENGTH; i++)
        fileOne << "2^" << i + 1 << " = " << arrPtrOne[i] << std::endl;
    deleteArr(arrPtrOne, LENGTH);
    fileOne.close();
    
    std::cout << "Enter your second file name:";
    std::cin >> name;
    std::ofstream fileTwo ( name + ".txt" );
    int** arrPtrTwo = initArr(LENGTH, LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
            fileTwo << arrPtrTwo[i][j] << "\t";
        fileTwo << std::endl;
    }
    deleteArr(arrPtrTwo, LENGTH);
    fileTwo.close();
}

void addFile() // Функция для задания 4
{
    std::string nameOne;
    std::string nameTwo;
    std::string nameThree;
    std::string buf;
    std::cout << "Enter your first file name:";
    std::cin >> nameOne;
    std::cout << "Enter your second file name:";
    std::cin >> nameTwo;
    std::cout << "Enter the name of resulting file:";
    std::cin >> nameThree;
    std::ofstream fileThree(nameThree + ".txt");
    std::ifstream fileOne(nameOne + ".txt");
    while (!fileOne.eof())
    {
        getline(fileOne, buf);
        fileThree << buf << std::endl;
    }
    fileOne.close();
    std::ifstream fileTwo(nameTwo + ".txt");
    while (!fileTwo.eof())
    {
        getline(fileTwo, buf);
        fileThree << buf << std::endl;
    }
    fileTwo.close();
    fileThree.close();
    std::cout << "file " << nameThree << " was created." << std::endl;
}

bool searchFor(std::string word, std::string filename) // Функция для задания 5
{
    std::string buf;
    std::ifstream fin(filename);
    if (fin.is_open())
    {
        while(getline(fin, buf))
        {
            
            if(buf.find(word) != std::string::npos)
            {
                fin.close();
                return true;
            }
        }
        fin.close();
        return false;
    }
    else
    {
        std::cout << filename << " was not found or an error occured." << std::endl;
        return false;
    }
}

int main()
{
    // Task 1
    int length{ 0 };
    int newVarCount{ 0 };
    do
    {
        std::cout << "Enter array length: ";
        std::cin >> length;
    } 
    while (length == 0);
    int* arrPtrOne = *initArr(length, 0);
    newVarCount++;
    printArr(arrPtrOne, length);
    if (deleteArr(arrPtrOne, length))
        newVarCount--;
    std::cout << std::endl;
    
    // Task 2
    int** arrPtrTwo = initArr(RANG, RANG);
    printArr(arrPtrTwo, RANG, RANG);
    newVarCount++;
    if (deleteArr(arrPtrTwo, RANG))
        newVarCount--;
    std::cout << std::endl;

    // Task 3
    createFile();

    // Task 4
    addFile();
    
    // Task 5
    
    std::string name;
    std::string word;
    std::cout << "What word we are loking for? \n";
    std::cin >> word;
    std::cout << "Where we are looking for? \n";
    std::cin >> name;
    if(searchFor(word, name))
        std::cout << "We have found the word " << word << " in " << name << std::endl;
    else    
        std::cout << "There is no word " << word << " in " << name << std::endl;
    
    std::cout << "Hello World!\n";
}
