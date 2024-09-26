// Tic tac toe in the console.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void printField(char field[3][3])
{
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция для проверки победителя
char checkWinner(char field[3][3])
{
    // Проверка победителя по строкам
    for (int i = 0; i < 3; i++)
    {
        if (field[i][0] == field[i][1] && field[i][1] == field[i][2])
        {
            return field[i][0];
        }
    }

    // Проверка победителя по столбцам
    for (int j = 0; j < 3; j++)
    {
        if (field[0][j] == field[1][j] && field[1][j] == field[2][j])
        {
            return field[0][j];
        }
    }

    // Проверка победителя по диагоналям
    if (field[0][0] == field[1][1] && field[1][1] == field[2][2])
    {
        return field[0][0];
    }
    if (field[0][2] == field[1][1] && field[1][1] == field[2][0])
    {
        return field[0][2];
    }

    // Если нет победителя, то возвращаем пробел
    return ' ';
}

int main()
{
    setlocale(LC_ALL, "Rus");
    for (; ; )
    {
        // Создание игрового поля
        char field[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        // Переменная для хранения текущего хода
        char turn = 'X';

        // Переменная для хранения победителя
        char winner = ' ';

        // Цикл для прохождения ходов
        while (true)
        {
            // Вывод игрового поля
            printField(field);

            // Ход игрока
            int x, y;
            cout << "Ходит игрок " << turn << endl;
            cout << "Введите координаты ячейки (x, y): ";
            cin >> x >> y;
            cout << endl;

            // Проверка на корректность введенных координат
            if (x < 1 || x > 3 || y < 1 || y > 3 || field[x - 1][y - 1] != ' ')
            {
                cout << "Некорректные координаты. Попробуйте еще раз." << endl;
                cout << endl;
                continue;
            }

            // Запись хода на игровое поле
            field[x - 1][y - 1] = turn;

            // Проверка на победителя
            winner = checkWinner(field);

            // Если есть победитель, то завершаем игру
            if (winner != ' ')
            {
                break;
            }

            // Передача хода другому игроку
            if (turn == 'X')
            {
                turn = 'O';
            }
            else
            {
                turn = 'X';
            }
        }

        // Вывод победителя или сообщение о ничьей
        if (winner == 'X')
        {
            printField(field);
            cout << "Победил игрок X!" << endl;
            cout << endl;
        }
        else if (winner == 'O')
        {
            printField(field);
            cout << "Победил игрок O!" << endl;
            cout << endl;
        }
        else
        {
            printField(field);
            cout << "Ничья!" << endl;
            cout << endl;
        }
    }
    system("pause");
    return 0;
}