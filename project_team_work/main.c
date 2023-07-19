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

void show_catalog_data (int id_product, struct prod_info products[id_product])
{
    printf("Продукт №%d:\n", id_product + 1);
    printf("\tНазва: %s\n", products[id_product].name);
    printf("\tКод: %d\n", products[id_product].code);
    printf("\tГендер: %s\n", products[id_product].gender);
    printf("\tРозмір: %s\n", products[id_product].size);
    printf("\tЦіна: %.2f\n", products[id_product].cost);
}

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
    printf ("\t7. Історія замовлень\n");
    printf ("\t8. Про нас\n");
    printf ("\t9. Вихід\n");
    printf("--------------------------------------------------------\n");
    printf ("Опція: ");
    scanf ("%d", &user_action);
    printf("--------------------------------------------------------\n");

    return user_action;
}

void show_init_catalog_data_output(int total_products, struct prod_info products[total_products])
{
    printf("\tКаталог одягу:\n");
    for (int i = 0; i < total_products; i++)
    {
        printf("----------------------------\n");
        show_catalog_data (i, products);
    }
    printf ("\n");
}

void filter_choose(int total_products, struct prod_info products[total_products])
{
    char fil_gender[10], fil_size[5];
    int user_action_filter, user_action_filter_next, i, count_fil=0;
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

    for (i=0; i<total_products; i++)
    {
        if ((strcmp(fil_gender, products[i].gender)==0) || (strcmp(fil_gender, "Усі")==0))
        {
            if ((strcmp(fil_size, products[i].size)==0) || (strcmp(fil_size, "Усі")==0))
            {
                if ((products[i].cost<=max_cost)&&(products[i].cost>=min_cost))
                {
                    printf("----------------------------\n");
                    show_catalog_data (i, products);
                    count_fil=count_fil+1;
                }
            }
        }
    }
    if (count_fil==0)
    {
        printf("--------------------------------------------------------\n");
        printf ("Немає продуктів за заданим фільтром\n");
    }
}

void search_prod(int total_products, struct prod_info products[total_products])
{
    int user_code, i , absent=0;
    printf ("Введіть код продукту: ");
    scanf("%d", &user_code);
    printf("----------------------------\n");
    for (i=0;i<total_products;i++)
    {
        if (products[i].code==user_code)
        {
            show_catalog_data (i, products);
            absent=1;
            break;
        }
    }
    if (absent==0)
        {
            printf("Продукту з таким кодом немає\n");
        }
}

int add_prod (int total_products, struct prod_info products[total_products], int total_cart,  int cart[total_cart], int count_cart)
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
            for (i=0;i<total_products;i++)
            {
                if (products[i].code==user_code)
                {
                    cart[count_cart]=products[i].code;
                    count_cart = count_cart+1;
                    printf("--------------------------------------------------------\n");
                    printf ("Було додано продукт %d до кошика\n", cart[count_cart-1]);
                    absent=1;
                    break;
                }
            }
            if (absent==0)
            {
                printf("--------------------------------------------------------\n");
                printf("Продукту з таким кодом немає\n");
            }
            break;
        }
    case 2:
        {
            printf("--------------------------------------------------------\n");
            printf ("Введіть код бажаного продукту: ");
            scanf ("%d", &user_code);
            for (j=0;j<count_cart;j++)
            {
                if (cart[j]==user_code)
                {
                    cart[j]=cart[count_cart];
                    cart[count_cart]=0;
                    count_cart = count_cart-1;
                    printf("--------------------------------------------------------\n");
                    printf ("Було видалено продукт %d з кошика\n", user_code);
                    absent=1;
                    break;
                }
            }
            if (absent==0)
            {
                printf("--------------------------------------------------------\n");
                printf("Продукту з таким кодом немає\n");
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
    return count_cart;
}

void show_cart(int total_products, struct prod_info products[total_products],int total_cart, int cart[total_cart], int count_cart)
{
    int i, j;
    if (count_cart==0)
    {
        printf ("В кошику немає товарів\n");
    }
    else
    {
        for (j=0;j<=count_cart;j++)
        {
            for (i=0;i<total_products;i++)
            {
                if (cart[j]==products[i].code)
                {
                    show_catalog_data (i, products);
                    printf("----------------------------\n");
                }
            }
        }
    }
}

float order_process(int total_products, struct prod_info products[total_products],int total_cart, int cart[total_cart], int count_cart, int count_order, float total_order)
{
    FILE *order_history;
    order_history = fopen("order_history", "a");
    int i, j;
    float total=0.00;

    if (count_cart==0)
    {
        printf ("В кошику немає продуктів\n");
    }
    else
    {
       printf ("В вашому кошику є:\n");
       printf("----------------------------\n");
       fprintf (order_history, "Замовлення %d:\n", count_order);
        for (j=0; j<=count_cart; j++)
        {
            for (i=0; i<total_products; i++)
            {
                if (cart[j]==products[i].code)
                {
                    printf ("\t%d. %s, %s, розмір %s, ціна %0.2f\n", j+1, products[i].name, products[i].gender, products[i].size, products[i].cost);
                    fprintf (order_history,"\t%d. %s, %s, розмір %s, ціна %0.2f\n", j+1, products[i].name, products[i].gender, products[i].size, products[i].cost);
                    total=total+products[i].cost;
                    cart[j]=0;
                }
            }
        }
        printf("--------------------------------------------------------\n");
        fprintf(order_history, "--------------------------------------------------------\n");
        printf ("Загальна сума: %0.2f\n", total);
        fprintf (order_history, "Загальна сума: %0.2f\n--------------------------------------------------------\n", total);
    }

    total_order=total_order+total;
    fclose(order_history);
    return total_order;
}

void show_all_order(int count_order, float total_order)
{
    FILE *order_history;
    order_history = fopen("order_history", "r");

    if (count_order == 0)
    {
        printf("--------------------------------------------------------\n");
        printf("Історія замовлень порожня\n");
    }
    else
    {
        printf("Історія замовлень:\n");
        printf("----------------------------\n");
        char file_info[256];
        while (fgets(file_info, sizeof(file_info), order_history) != NULL)
        {
            printf("%s", file_info);
        }
    }
    printf ("Загальна сума всіх замовлень: %0.2f\n", total_order);

    fclose(order_history);
}

int main()
{
    SetConsoleOutputCP(1251);
    int user_action, total_products=19, total_cart=1000;
    char* text = "...";
    int delay = 1000000;

    struct prod_info products[total_products];
    init_catalog_data (total_products , products);

    int cart[total_cart];
    float count_cart=0;

    int count_order = 0;
    float total_order = 0;

    FILE *order_history;
    order_history = fopen("order_history", "w+");
    fclose(order_history);

    while (user_action!=9)
    {
        user_action = menu(user_action);
        switch (user_action)
        {
        case 1:
            {
                show_init_catalog_data(total_products, products);
                continue;
            }
        case 2:
            {
                filter_choose(total_products, products);
                continue;
            }
        case 3:
            {
                search_prod(total_products, products);
                continue;
            }
        case 4:
            {
                count_cart = add_prod(total_products, products,total_cart, cart, count_cart);
                continue;
            }
        case 5:
            {
                show_cart(total_products, products, total_cart, cart, count_cart);
                continue;
            }
        case 6:
            {
                count_order = count_order+1;
                total_order = order_process(total_products, products, total_cart,  cart, count_cart, count_order, total_order);
                count_cart = 0;
                continue;
            }
        case 7:
            {
                show_all_order(count_order, total_order);
                continue;
            }

        case 8:
            {
                show_project_info();
                continue;
            }

        case 9:
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
    return 0;
}

void init_catalog_data(int total_products, struct prod_info products[total_products])
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

void show_project_info()
{
    printf ("Тема нашої командної роботи Інтернет-магазин одягу\n");
    printf ("В програмі реалізовані головні вимоги інтернет магазину, а саме:\n");
    printf ("\t1. Перегляд каталогу\n");
    printf ("\t2. Можливість знаходити товар по коду\n");
    printf ("\t3. Фільтр товарів відповідно до розміру, ціни та гендеру\n");
    printf ("\t4. Додавання та видалення товару з кошику\n");
    printf ("\t5. Перегляд товарів в кошику\n");
    printf ("\t6. Оформлення замовлення та загальна ціна\n");
    printf("--------------------------------------------------------\n");
    printf ("Проєкт виконали студентки групи ІПЗ-22007б\n");
    printf ("\tМалинка Тетяна\n\tСтрішенець Ангеліна\n\tПилипенко Наталія\n\tДацюк Неля\n");
}
