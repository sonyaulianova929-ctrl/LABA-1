#include <stdio.h>
int main(void) {
    int duration;      /*Длительность
     разговора в минутах */
    int start hour;    /*Час начала
     разговора  (0-23)*/
    int day_of_week;   /*День недели
     (1-7, 1- понедельник)*/
    int is_regular;    /*Постоянный
     клиент (1-да, 0-нет)*/
    double rate;       /*Тариф руб/
     мин */
    double base_cost;  /*Базовая
     стоимость*/
    double discount_duration;/*Скидка за
     длительность*/
    double cost_after_dur; /* Стоимость
     после скидки за длительность*/
    double discount_regular; /*Скидка
     постоянному клиенту*/
    double total_no_vat;     /*Итого без
     НДС*/
    double vat;              /*НДС*/
    double final_total;      /*Итоговая
     сумма*/

    printf("Введите данные звонка:\n");

    printf("Длительность  (мин):");
    if (scanf("%d", &duration) != 1) {
       printf("Ошибка: некорректный ввод
         длительности.\n");
       return 1;
    }
    printf("Час начала (0-23): ");
    if (scanf("%d", &start_hour) !=1) {
        printf("Ошибка; некорректный ввод
             часа.\n");
        return 1;
    }
    printf("День недели (1-7, 1-пн):");
    if (scanf("%d", &day_of_week) !=1) {
        printf("Ошибка: некоректный ввод
             дня недели.\n");
        return 1;
    }
    printf("Постоянный клиент (1-да/0-нет):");
    if (scanf("%d", &is_regular) !=1) {
        printf("Ошибка: некорректный ввод
             статуса клиента.\n");
        return 1;
    }
    /* ---Проверка корректности введенных
     данных---*/
    if (duration < 0 \\ start_hour < 0 
        \\ start_hour > 23
    day_of_week < 1 \\ day_of_week > 7
    (is regular !=0 && is_regular !=1)) {
        printf("Ошибка: введены
             некорректные данные.\n");
        return 1;
    }
    printf("\n=== РАСЧЕТ СТОИМОСТИ ===\n");
    /* --- Определение тарифа (вложенные
     ветвления) --- */
    if (day_of_week ==6 \\ day_of_week ==
         7) {
        /* Выходные: фиксированная ставка 2
         рубля/мин*/
        rate = 2.00;
        printf("Тариф: выходной (2.00 руб)/
            мин)\n");
    } else {
        /*Будни: проверяем время суток*/
        if(start_hour >=8 && start_hour < 22) {
            rate=5.00;
        printf("Тариф: будни-день (5.00
             руб/мин)\n");
        } else {
            rate = 3.00;
            printf ("Тариф: будни-ночь (3.00
                 руб/ мин)\n");
        }
    } 
    /* --- Расчет базовой стоимости --- */
    base_cost = duration * rate;
    printf("Базовая стомость: %.2f руб/n", 
        base_cost);

    /* --- Расчет скидок --- */
    printf("Скидки:\n");

    /*Скидка за длительность (60 минут и
     более)*/
    if (duration >=60) {
        discount_duration = base_cost *
         0.10;
        printf("- За длительность: %.2f 
            руб\n", discount_duration);
    } else {
        discount_duration = 0.0;
        printf(" - За длительность: 0.00
             руб (менее 60 мин)\n");
    }
/*Стоимость после скидки за 
длительность*/
cost_after_dur = base_cost -
 discount_duration;
/*Скидка постоянному клиенту (+5% от
 суммы после первой скидки)*/
if (is_regular == 1) {
    discount_regular = cost_after_dur * 
    0.05;
    printf(" - Постоянный клиент: %.2f
         руб\n",discount_regular);
} else {
    discount_regular = 0.00;
    printf(" - Постоянный клиент: 0.00
         руб\n");
}
/* Итоговая сумма без НДС */
total_no_vat = cost_after_dur - 
discount_regular;
printf("Итого без НДС: %.2f руб\n", 
    total_no_vat);

/* --- Расчет НДС --- */
vat = total_no_vat * 0.20;
printf("НДС 20%%: %.2f руб\n" , vat);

/* --- Итоговая сумма ---*/
final_total = total_no_vat + vat;
printf("К ОПЛАТЕ: %.2f руб\n", 
    final_total);
return 0;
}









