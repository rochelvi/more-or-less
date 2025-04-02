#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для определиния числа
int make_secret_number() {
    int number;

    srand(time(0));
    number = rand() % 100 + 1;
    
    return number;
}

// Функция для проверки
int check_guess(int guess, int secret) {
    // Угадал?
    if (guess == secret) {  
        return 0;
    }

    // Меньше?
    if (guess < secret) {  
        return -1;
    }

    // Больше?
    if (guess > secret) {  
        return 1;
    }

    return 0;
}

// Функция для вывода подсказки
void show_hint(int result) {
    if (result == -1) {
        printf("Твоё число меньше! Попробуй ещё раз.\n");
    }

    if (result == 1) {
        printf("Твоё число больше! Попробуй ещё раз.\n");
    }

    if (result == 0) {
        printf("Ты угадал! Поздравляю!\n");
    }
}

// Главная функция
void play_game() {
    int secret_number;
    int player_guess;
    int tries = 0;
    int check_result;

    // Секретное число
    secret_number = make_secret_number();
    
    // Выводим инструкцию
    printf("Я загадал число от 1 до 100. Угадай его!\n");
    
    // Играем - пока не угадает
    while (1) {

        printf("Введи своё число: ");
        
        if (scanf("%d", &player_guess) != 1){
            printf("ERROR!\n");
            return;
        }
        tries = tries + 1;
        
        // Проверяем: угадал?
        check_result = check_guess(player_guess, secret_number);
        show_hint(check_result);  // показываем подсказку
        
        // Угадал? - выходим
        if (check_result == 0) {
            printf("Ты угадал за %d попыток!\n", tries);
            
            break;
        }
    }
}

// Старт программы
int main() {
    printf("Привет! Давай играть в 'Угадай число'!\n");
    play_game();
    
    return 0;
}