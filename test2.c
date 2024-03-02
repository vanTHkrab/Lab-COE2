# include <stdio.h>
# include <string.h>

int main() {

    int mode, size, t, ans, amount, choice;
    char name[100], coupon_code[100];
    float discount, price;
    while (1){
    printf("**********************************\n");
    printf("Welcome to the laundry program!\n");
    printf("Please select a mode:\n");
    printf("1. Use the washing machine\n");
    printf("2. Use the dryer machine\n");
    printf("3. Use the coin exchange machine\n");
    printf("4. Use detergent vending machine\n");
    printf("5. Use Fabric softener vending machinen\n");
    printf("6. Exit the program\n");
    printf("\n-> ");
    scanf("%d", &mode);
    switch (mode)
    {
        case 1:
            printf("Washing machine\n");
            printf("Enter your name: ");
            scanf("%s", name);
            do
            {
                printf("\nPlease select the size of the load:\n");
                printf("1.Size 7kg 20Baht\n");
                printf("2.Size 10kg 30Baht\n");
                printf("3.Size 13kg 40Baht\n");
                printf("4.Size 17kg 50Baht\n");
                printf("5.Size 20kg 60Baht\n");
                printf("6.Size 25kg 80Baht\n");
                printf("7.Back to menu\n");
                printf("\nEnter the size of the load: ");
                scanf("%d", &size);
                switch (size)
                {
                    case 1:
                        price = 20;
                        break;
                    case 2:
                        price = 30;
                        break;
                    case 3:
                        price = 40;
                        break;
                    case 4:
                        price = 50;
                        break;
                    case 5:
                        price = 60;
                        break;
                    case 6:
                        price = 80;
                        break;
                    case 7:
                        break;
                    default:
                        printf("Invalid size\n");
                        break;
                }
            } while (size < 1 || size > 7);

            if (size != 7) {
                printf("\nDo you have a coupon? (1 for yes, 0 for no): ");
                scanf("%d", &ans);
                if (ans == 1) {
                    do {
                        printf("Enter coupon code (if not have enter 0): ");
                        scanf("%s", coupon_code);
                        if (strcmp(coupon_code, "0") == 0) {
                            discount = 0;
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT10") == 0) {
                            discount = 10.0 / 100.0; //10% discount
                            break;
                        } 
                        else if(strcmp(coupon_code, "DISCOUNT20") == 0) {
                            discount = 20.0 / 100.0; //20% discount
                            break;
                        } 
                        else if(strcmp(coupon_code, "DISCOUNT30") == 0) {
                            discount = 30.0 / 100.0; //30% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT40") == 0) {
                            discount = 40.0 / 100.0; //40% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT50") == 0) {
                            discount = 50.0 / 100.0; //50% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT60") == 0) {
                            discount = 60.0 / 100.0; //60% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT70") == 0) {
                            discount = 70.0 / 100.0; //70% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT80") == 0) {
                            discount = 80.0 / 100.0; //80% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT90") == 0) {
                            discount = 90.0 / 100.0; //90% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT100") == 0) {
                            discount = 100.0 / 100.0; //100% discount
                            break;
                        }
                        else {
                            printf("Invalid coupon code\n");
                        }
                    } while (1);
                    printf("Discount %.2f %%\n", discount);
                }
                float total_price_washing_machine = (price) * (1 - discount);
                printf("\nThe total price is %.2f.\n", total_price_washing_machine);
                printf("\n");
            }
            break;
// ----------------------------------------------------------------------------------------------------------------
        case 2:
            printf("Use the dryer machine\n");
            printf("Enter your name: ");
            scanf("%s", name);
            do {
                printf("\nPlease select the size of the cabinet:\n");
                printf("1.Size 15kg 40Baht\n");
                printf("2.Size 30kg 60Baht\n");
                printf("3.Back to menu\n");
                printf("Enter the size of the cabinet: ");
                scanf("%d", &size);
                switch (size)
                {
                    case 1:
                        price = 40;
                        break;
                    case 2:
                        price = 60;
                        break;
                    case 3:
                        break;
                    default:
                        printf("Invalid size\n");
                        break;
                }
            } while (size < 1 || size > 3);
            if (size != 3) {
                printf("\nDo you have a coupon? (1 for yes, 0 for no): ");
                scanf("%d", &ans);
                if (ans == 1) {
                    do {
                        printf("Enter coupon code (if not have enter 0): ");
                        scanf("%s", coupon_code);
                        if (strcmp(coupon_code, "0") == 0) {
                            discount = 0;
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT10") == 0) {
                            discount = 10 / 100; //10% discount
                            break;
                        } 
                        else if(strcmp(coupon_code, "DISCOUNT20") == 0) {
                            discount = 20 / 100; //20% discount
                            break;
                        } 
                        else if(strcmp(coupon_code, "DISCOUNT30") == 0) {
                            discount = 30 / 100; //30% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT40") == 0) {
                            discount = 40 / 100; //40% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT50") == 0) {
                            discount = 50 / 100; //50% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT60") == 0) {
                            discount = 60 / 100; //60% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT70") == 0) {
                            discount = 70 / 100; //70% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT80") == 0) {
                            discount = 80 / 100; //80% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT90") == 0) {
                            discount = 90 / 100; //90% discount
                            break;
                        }
                        else if(strcmp(coupon_code, "DISCOUNT100") == 0) {
                            discount = 100 / 100;
                            break;
                        }
                        else {
                            printf("Invalid coupon code\n");
                        }
                    } while (1);
                    printf("Discount %.2f %%\n", discount);
                }
                float total_price_dryer_machine = (price) * (1 - discount);
                printf("\nThe total price is %.2f.\n", total_price_dryer_machine);
                printf("\n");
            }
            break;
// ----------------------------------------------------------------------------------------------------------------
        case 3:
            printf("Enter money to exchange (50 OR 100): ");
            scanf("%d", &amount);
            int coins, tokens;
            if (amount == 50) {
                coins = 4;
                tokens = 1;
            } else if (amount == 100) {
                coins = 8;
                tokens = 2;
            } else {
                printf("Invalid amount. Please enter either 50 or 100.\n");
            }
            printf("You get %d coins and %d tokens.\n", coins, tokens);
            printf("\n");
            break;
// ----------------------------------------------------------------------------------------------------------------
        case 4:
            do {
                printf("Welcome to the detergent Vending Machine!\n");
                printf("Please select a detergent:\n");
                printf("1. Brand A - $10\n");
                printf("2. Brand B - $12\n");
                printf("3. Brand C - $14\n");
                printf("4. Brand D - $18\n");
                printf("5. Back to menu\n");
                printf("->");
                scanf("%d", &choice);
                switch(choice) {
                    case 1:
                        price = 10;
                        break;
                    case 2:
                        price = 12;
                        break;
                    case 3:
                        price = 14;
                        break;
                    case 4:
                        price = 18;
                        break;
                    case 5:
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                }
            } while (choice < 1 || choice > 5);

            if (choice != 5) {
                printf("You have selected Brand %c. The price is $%.2f.\n", 'A' + choice - 1, price);
                printf("Thank you for using our vending machine!\n");
                printf("\n");
            }
            break;
// ----------------------------------------------------------------------------------------------------------------    
        case 5:
            do {
                printf("Welcome to the Fabric Softener Vending Machine!\n");
                printf("Please select a fabric softener:\n");

                printf("1. Brand A - $10\n");
                printf("2. Brand B - $12\n");
                printf("3. Brand C - $14\n");
                printf("4. Brand D - $18\n");
                printf("5. Back to menu\n");
                printf("\n->");
                scanf("%d", &choice);
                switch(choice) {
                    case 1:
                        price = 10;
                        break;
                    case 2:
                        price = 12;
                        break;
                    case 3:
                        price = 14;
                        break;
                    case 4:
                        price = 18;
                        break;
                    case 5:
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                }
            } while (choice < 1 || choice > 5);
            if (choice != 5) {
                printf("You have selected Brand %c. The price is $%.2f.\n", 'A' + choice - 1, price);
                printf("Thank you for using our vending machine!\n");
                printf("\n");
            }
            break;
// ----------------------------------------------------------------------------------------------------------------
        case 6:
            printf("Thank you for using our program!\n");
            return 0;

        default:
            printf("Invalid mode\n");
        }
    }
}