﻿#include <iostream>
#include <stdio.h>
#include <locale.h>
#include "permutationsWithFixedPoints.h"

int factorial(int n)
{
    if (n < 0)  //Если число отрицательное, факториала не существует - выдать ошибку (вернуть -1)
        return -1;
    else
    {
        //Вычислить факториал по формуле n!=1*2*...*n
        int factorial_n = 1;

        for (int i = 1; i <= n; i++)
        {
            factorial_n *= (i);
        }
        return factorial_n;
    }  
}

int permutationsWithFixedPoints(int n, int k)
{
    if ((n < 0) or (k < 0) or (k > n)) //Если n<k, n<0 или k<0, перестановок не существует - выдать ошибку (вернуть -1)
        return -1;
    else
    {
        int P = 0; //кол-во перестановок

        //Если кол-во неподижных точек равно нулю - выычислить только кол-во беспорядков размера n
        if (k == 0)
            P = derangement(n);
        else
            //Иначе вычислить кол-во сочетаний из n по k и умножить на кол-во беспорядков размера n-k
            P = combinationWithoutRepeat(n, k) * derangement(n - k);

        return P;
    }
}

int combinationWithoutRepeat(int n, int k)
{
    if ((n < 0) or (k < 0) or (k > n)) //Если n<k, n<0 или k<0 - выдать ошибку (вернуть -1)
        return -1;
    else
    {
        //Вычислить кол-во сочетаний по формуле C=n!/(k!*(n-k)!)
        int numberCombination = 0;

        numberCombination = factorial(n) / factorial(n - k) / factorial(k);

        return numberCombination;
    }
  
}

int derangement(int n)
{
    if (n < 0) //Если число n отрицательное, беспорядков не существует - выдать ошибку (вернуть -1)
        return -1;
    else
    {
        //Вычислить кол-во беспорядков по формуле P=(-1)^i * n!/i!, где i=(1,2...n)
        int numberDerangement = 0;

        for (int i = 0; i < n + 1; i++)
            numberDerangement += pow(-1, i) * factorial(n) / factorial(i);

        return numberDerangement;
    }

}

int main(int argc, char* argv[])
{
    char* locale = setlocale(LC_ALL, ""); //для вывода сообщений русскими буквами


     // буфер для считавания данных из файла в формате строки
    char buffer[256] = "";

    // чтение из файлов
    FILE* inputfile = fopen(argv[1], "r");
    FILE* outputfile = fopen(argv[2], "w+");

    //Если файлы не читаются - вывести сообщение об ошибке 
    if (inputfile == NULL)
        printf("Неверно указан файл с входными данными. Возможно, файл не существует.\n");
    else if (outputfile == NULL)
        printf("Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись.\n");
    else
    {
        fgets(buffer, 10, inputfile); //Копирование данных из файла в буфер в формате строки

        //Нахождение кол-ва перестановок с неподвижными точками
        int result;
        

        //Запись ответа в выходной файл
        char str[10];
        _itoa(result, str, 10);
        fputs(str, outputfile);

        //Закрыть файлы
        fclose(outputfile);
        fclose(inputfile);
        
    }
}