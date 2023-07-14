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
    printf("\n--------------------------------------------------------\n");
    printf ("\tОберіть функцію:\n");
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

void katalog_output(struct prod_info products[10])
{

}

void filter_choose(struct prod_info products[10])
{

}


void seach_prod(struct prod_info products[10])
{

}

int add_prod (struct prod_info products[10], int cart[10], int kilk_cart)
{

}

void cart_output(struct prod_info products[10], int cart[10], int kilk_cart)
{

}

void order_process(struct prod_info products[10], int cart[10], int kilk_cart)
{

}

int main()
{
    SetConsoleOutputCP(1251);
    int user_action;

    struct prod_info products[10];
    katalog (products);

    int cart[10], kilk_cart=0;

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
                printf("Вихід\n");
                break;
            }
        default:
            {
                printf("--------------------------------------------------------\n");
                printf ("\nНемає такої опції\n\n");
                printf("--------------------------------------------------------\n");
                continue;
            }
        }
    }
    katalog();

    return 0;
}

void katalog(struct prod_info products[10])
{

}

void our_project()
{

}
