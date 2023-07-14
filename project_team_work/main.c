
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct prod_info
{
    char name[50];
    int code;
    char gender[20];
    char size[10];
    float cost;
};

int menu (int user_action)
{
    printf("--------------------------------------------------------\n");
    printf ("\t\tОберіть функцію:\n");
    printf("--------------------------------------------------------\n");
    printf ("\t1. Переглянути каталог\n");
    printf ("\t2. Фільтри\n");
    printf ("\t3. Знайти товар по коду\n");
    printf ("\t4. Додати(видалити) продукт до кошику за кодом\n");
    printf ("\t5. Перегляд кошику\n");
    printf ("\t6. Оформлення замовлення\n");
    printf ("\t7. Про проєкт\n");
    printf ("\t8. Вихід\n");
    printf("--------------------------------------------------------\n");
    printf ("Опція: ");
    scanf ("%d", &user_action);
    printf("--------------------------------------------------------\n");

    return user_action;
}

void katalog_output(struct prod_info products[19])
{
    printf("\tКаталог одягу:\n");
    for (int i = 0; i < 19; i++)
    {
        printf("----------------------------");
        printf("\nПродукт №%d:\n", i + 1);
        printf("\tНазва: %s\n", products[i].name);
        printf("\tКод: %d\n", products[i].code);
        printf("\tГендер: %s\n", products[i].gender);
        printf("\tРазмір: %s\n", products[i].size);
        printf("\tЦіна: %.2f\n", products[i].cost);

    }
    printf ("\n");
}

void filter_choose(struct prod_info products[19])
{
    char fil_gender[10], fil_size[5];
    int user_action_filter, user_action_filter_next, i, kilk_fil=0;
    float max_cost=100000, min_cost=0;

    strcpy(fil_gender, "Усі");
    strcpy(fil_size, "Усі");

    while (user_action_filter!=4)
    {
        printf ("Фільтр:\n");
        printf ("\tГендер: %s\n", fil_gender);
        printf ("\tРозмір: %s\n", fil_size);
        printf ("\tМінімальна та максимальна ціна: %0.2f - %0.2f\n", min_cost, max_cost);
        printf("--------------------------------------------------------\n");
        printf ("Змінити:\n");
        printf ("\t1. Гендер\n");
        printf ("\t2. Розмір\n");
        printf ("\t3. Мінімальна та максимальна ціна\n");
        printf ("\t4. Закінчити вибір фільтрів\n");
        printf("--------------------------------------------------------\n");

        scanf ("%d", &user_action_filter);

        switch (user_action_filter)
        {
        case 1:
            {
                printf("--------------------------------------------------------\n");
                printf ("Гендер:\n");
                printf ("\t1. Чоловічий\n");
                printf ("\t2. Жіночий\n");
                printf ("\t3. Унісекс\n");
                printf ("\t4. Усі\n");
                printf("--------------------------------------------------------\n");
                scanf ("%d", &user_action_filter_next);
                switch (user_action_filter_next)
                {
                    case 1:
                    {
                        strcpy(fil_gender, "Чоловічий");
                        continue;
                    }
                    case 2:
                    {
                        strcpy(fil_gender, "Жіночий");
                        continue;
                    }
                    case 3:
                    {
                        strcpy(fil_gender, "Унісекс");
                        continue;
                    }
                    case 4:
                    {
                        strcpy(fil_gender, "Усі");
                        continue;
                    }
                    default:
                    {
                        printf ("Немає такої опції\n");
                    }
                }
                continue;
            }
        case 2:
            {
                printf("----------------------------\n");
                printf ("Розмір:\n");
                printf ("\t1. S\n");
                printf ("\t2. M\n");
                printf ("\t3. L\n");
                printf ("\t4. XL\n");
                printf ("\t5. Всі\n");
                printf("----------------------------\n");
                scanf ("%d", &user_action_filter_next);
                switch (user_action_filter_next)
                {
                case 1:
                    {
                        strcpy(fil_size, "S");
                        continue;
                    }
                case 2:
                    {
                        strcpy(fil_size, "M");
                        continue;
                    }
                case 3:
                    {
                        strcpy(fil_size, "L");
                        continue;
                    }
                case 4:
                    {
                        strcpy(fil_size, "XL");
                        continue;
                    }
                case 5:
                    {
                        strcpy(fil_size, "Усі");
                        continue;
                    }
                default:
                    {
                        printf ("Немає такої опції\n");
                    }
                }
                continue;
            }
        case 3:
            {
                printf("--------------------------------------------------------\n");
                printf ("Введіть мінімальну та максимальну ціну - ");
                scanf ("%f %f", &min_cost, &max_cost);
                printf("--------------------------------------------------------\n");
                continue;
            }
        case 4:
            {
                printf("----------------------------\n");
                printf ("Фільтри обрано\n");
                break;
            }
        default:
            {
                printf ("Немає такої опції\n");
                continue;
            }
        }
    }

    for (i=0; i<19; i++)
    {
        if ((strcmp(fil_gender, products[i].gender)==0) || (strcmp(fil_gender, "Усі")==0))
        {
            if ((strcmp(fil_size, products[i].size)==0) || (strcmp(fil_size, "Усі")==0))
            {
                if ((products[i].cost<=max_cost)&&(products[i].cost>=min_cost))
                {
                    printf("----------------------------\n");
                    printf("Продукт №%d:\n", i + 1);
                    printf("\tНазва: %s\n", products[i].name);
                    printf("\tКод: %d\n", products[i].code);
                    printf("\tГендер: %s\n", products[i].gender);
                    printf("\tРазмір: %s\n", products[i].size);
                    printf("\tЦіна: %.2f\n", products[i].cost);
                    kilk_fil=kilk_fil+1;
                }
            }
        }
    }
    if (kilk_fil==0)
    {
        printf("--------------------------------------------------------\n");
        printf ("Немає продуктів за заданим фільтром\n");
    }
}

void seach_prod(struct prod_info products[19])
{
    int user_code, i , absent=0;
    printf ("Введіть код продукту: ");
    scanf("%d", &user_code);
    printf("----------------------------\n");
    for (i=0;i<19;i++)
    {
        if (products[i].code==user_code)
        {
            printf("Продукт #%d:\n", i + 1);
            printf("\tНазва: %s\n", products[i].name);
            printf("\tКод: %d\n", products[i].code);
            printf("\tГендер: %s\n", products[i].gender);
            printf("\tРазмір: %s\n", products[i].size);
            printf("\tЦіна: %.2f\n", products[i].cost);
            absent=1;
            break;
        }
    }
    if (absent==0)
        {
            printf("Продукту з таким кодом немає\n");
        }
}

int add_prod (struct prod_info products[19], int cart[100], int kilk_cart)
{
    int user_code, absent=0, i, user_action_prod, j;
    printf ("\t1. Додати продукт\n");
    printf ("\t2. Видалити продукт\n");
    printf ("\t3. Відмінити дію\n");
    printf("----------------------------\n");
    printf ("Опція: ");
    scanf ("%d", &user_action_prod);

    switch (user_action_prod)
    {
    case 1:
        {
            printf("--------------------------------------------------------\n");
            printf ("Введіть код бажаного продукту: ");
            scanf ("%d", &user_code);
            for (i=0;i<19;i++)
            {
                if (products[i].code==user_code)
                {
                    cart[kilk_cart]=products[i].code;
                    kilk_cart = kilk_cart+1;
                    printf("----------------------------\n");
                    printf ("Було додано продукт %d до кошика\n", cart[kilk_cart-1]);
                    absent=1;
                    break;
                }
            }
            if (absent==0)
            {
                printf("Продукту з таким кодом немає\n");
            }
            break;
        }
    case 2:
        {
            printf("--------------------------------------------------------\n");
            printf ("Введіть код бажаного продукту: ");
            scanf ("%d", &user_code);
            for (j=0;j<kilk_cart;j++)
            {
                if (cart[j]==user_code)
                {
                    cart[j]=cart[kilk_cart];
                    cart[kilk_cart]=0;
                    kilk_cart = kilk_cart-1;
                    printf("----------------------------\n");
                    printf ("Було видалено продукт %d з кошика\n", user_code);
                    absent=1;
                    break;
                }
            }
            if (absent==0)
            {
                printf("--------------------------------------------------------\n");
                printf("Продукту з таким кодом немає\n");
                printf("--------------------------------------------------------\n");
            }
            break;
        }
    case 3:
        {
            printf("----------------------------\n");
            printf("Дія відмінена\n");
            break;
        }
    default:
        {
            printf("--------------------------------------------------------\n");
            printf ("Немає такої опції\n");
            printf("--------------------------------------------------------\n");
        }
    }
    return kilk_cart;
}

void cart_output(struct prod_info products[19], int cart[100], int kilk_cart)
{
    int i, j;
    if (kilk_cart==0)
    {
        printf ("В кошику немає товарів\n");
    }
    else
    {
        for (j=0;j<=kilk_cart;j++)
        {
            for (i=0;i<19;i++)
            {
                if (cart[j]==products[i].code)
                {
                    printf("Продукт #%d:\n", i + 1);
                    printf("\tНазва: %s\n", products[i].name);
                    printf("\tКод: %d\n", products[i].code);
                    printf("\tГендер: %s\n", products[i].gender);
                    printf("\tРазмір: %s\n", products[i].size);
                    printf("\tЦіна: %.2f\n", products[i].cost);
                    printf("----------------------------\n");
                }
            }
        }
    }
}

void order_process(struct prod_info products[19], int cart[100], int kilk_cart)
{
    int i, j;
    float total=0.00;

    if (kilk_cart==0)
    {
        printf ("В кошику немає продуктів\n");
    }
    else
    {
       printf ("В вашому кошику є:\n");
        for (j=0; j<=kilk_cart; j++)
        {
            for (i=0; i<19; i++)
            {
                if (cart[j]==products[i].code)
                {
                    printf ("\t%d. %s, %s, розмір %s, ціна %0.2f\n", j+1, products[i].name, products[i].gender, products[i].size, products[i].cost);
                    total=total+products[i].cost;
                }
            }
        }
        printf("--------------------------------------------------------\n");
        printf ("Загальна сума %0.2f\n", total);
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    int user_action;
    char* text = "...";
    int delay = 1000000;

    struct prod_info products[19];
    katalog (products);

    int cart[100], kilk_cart=0;

    while (user_action!=8)
    {
        user_action = menu(user_action);
        switch (user_action)
        {
        case 1:
            {
                katalog_output(products);
                continue;
            }
        case 2:
            {
                filter_choose(products);
                continue;
            }
        case 3:
            {
                seach_prod(products);
                continue;
            }
        case 4:
            {
                kilk_cart = add_prod(products, cart, kilk_cart);
                continue;
            }
        case 5:
            {
                cart_output(products, cart, kilk_cart);
                continue;
            }
        case 6:
            {
                order_process(products, cart, kilk_cart);
                continue;
            }
        case 7:
            {
                our_project();
                continue;
            }
        case 8:
            {
                printf("Вихід");
                for (int i = 0; text[i] != '\0'; i++)
                {
                    printf("%c", text[i]);
                    fflush(stdout);
                    usleep(delay);
                }
                break;
            }
        default:
            {
                printf ("Немає такої опції\n");
                continue;
            }
        }
    }
    katalog();

    return 0;
}

void katalog(struct prod_info products[19])
{
    strcpy(products[0].name, "Футболка");
    products[0].code = 7643;
    strcpy(products[0].gender, "Чоловічий");
    strcpy(products[0].size, "M");
    products[0].cost = 19.99;

    strcpy(products[1].name, "Джинси");
    products[1].code = 7632;
    strcpy(products[1].gender, "Жіночий");
    strcpy(products[1].size, "S");
    products[1].cost = 49.99;

    strcpy(products[2].name, "Шапка");
    products[2].code = 4532;
    strcpy(products[2].gender, "Унісекс");
    strcpy(products[2].size, "L");
    products[2].cost = 79.99;

    strcpy(products[3].name, "Штани");
    products[3].code = 2354;
    strcpy(products[3].gender, "Жіночий");
    strcpy(products[3].size, "M");
    products[3].cost = 400.99;

    strcpy(products[4].name, "Худі");
    products[4].code = 9364;
    strcpy(products[4].gender, "Унісекс");
    strcpy(products[4].size, "XL");
    products[4].cost = 670.87;

    strcpy(products[5].name, "Худі");
    products[5].code = 5678;
    strcpy(products[5].gender, "Чоловічий");
    strcpy(products[5].size, "L");
    products[5].cost = 348.55;

    strcpy(products[6].name, "Кепка");
    products[6].code = 8874;
    strcpy(products[6].gender, "Унісекс");
    strcpy(products[6].size, "S");
    products[6].cost = 120.34;

    strcpy(products[7].name, "Шорти");
    products[7].code = 4453;
    strcpy(products[7].gender, "Чоловічий");
    strcpy(products[7].size, "S");
    products[7].cost = 250.50;

    strcpy(products[8].name, "Спідниця");
    products[8].code = 6541;
    strcpy(products[8].gender, "Жіночий");
    strcpy(products[8].size, "XL");
    products[8].cost = 330.00;

    strcpy(products[9].name, "Шкарпетки");
    products[9].code = 2634;
    strcpy(products[9].gender, "Чоловічий");
    strcpy(products[9].size, "M");
    products[9].cost = 67.50;

    strcpy(products[10].name, "Сукня");
    products[10].code = 7122;
    strcpy(products[10].gender, "Жіночий");
    strcpy(products[10].size, "M");
    products[10].cost = 489.79;

    strcpy(products[11].name, "Футболка");
    products[11].code = 9864;
    strcpy(products[11].gender, "Жіночий");
    strcpy(products[11].size, "L");
    products[11].cost = 210.4;

    strcpy(products[12].name, "Топ");
    products[12].code = 3742;
    strcpy(products[12].gender, "Жіночий");
    strcpy(products[12].size, "S");
    products[12].cost = 125.3;

    strcpy(products[13].name, "Піджак");
    products[13].code = 3384;
    strcpy(products[13].gender, "Чоловічий");
    strcpy(products[13].size, "M");
    products[13].cost = 342.5;

    strcpy(products[14].name, "Камуфляжний костюм");
    products[14].code = 2022;
    strcpy(products[14].gender, "Чоловічий");
    strcpy(products[14].size, "M");
    products[14].cost = 457.99;

    strcpy(products[15].name, "Ремінь");
    products[15].code = 2112;
    strcpy(products[15].gender, "Чоловічий");
    strcpy(products[15].size, "M");
    products[15].cost = 249.99;

    strcpy(products[16].name, "Сорочка");
    products[16].code = 8843;
    strcpy(products[16].gender, "Чоловічий");
    strcpy(products[16].size, "S");
    products[16].cost = 328.45;

    strcpy(products[17].name, "Світшот");
    products[17].code = 3212;
    strcpy(products[17].gender, "Чоловічий");
    strcpy(products[17].size, "S");
    products[17].cost = 423.4;

    strcpy(products[18].name, "Боді");
    products[18].code = 5467;
    strcpy(products[18].gender, "Жіночий");
    strcpy(products[18].size, "M");
    products[18].cost = 268.99;

}

void our_project()
{
    printf ("Тема нашої командної роботи Інтернет-магазин одягу\n");
    printf ("В програмі реалізовані головні вимоги інтернет магазину, а саме:\n");
    printf ("\t1. Перегляд каталогу\n");
    printf ("\t2. Можливість знаходити товар по коду\n");
    printf ("\t3. Фільтр товарів відповідно до розміру, ціни та гендеру\n");
    printf ("\t4. Додавання та видалення товару з кошику\n");
    printf ("\t5. Перегляд товарів в кошику\n");
    printf ("\t6. Оформлення замовлення та загальна ціна\n");
    printf ("Проєкт виконали студентки групи ІПЗ-22007б\n");
    printf ("\tМалинка Тетяна\n\tСтрішенець Ангеліна\n\tПилипенко Наталія\n\tДацюк Неля\n");
}
