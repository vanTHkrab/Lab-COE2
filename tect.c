#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    int mode;
    int cabinet_size, dryer_size;
    float cabinet_price, dryer_price;
    char coupon_code[20];
    float discount = 0;
    int amount = 0;
    char name[20];
    int time_of_use;
    int estimated_time;

    printf("Welcome to the laundry program!\n");
    printf("Please select a mode:\n");
    printf("1. Use the washing machine\n");
    printf("2. View the status of the washing machine\n");
    printf("3. Use the dryer machine\n");
    printf("4. View the status of the dryer machine\n");
    printf("5. Use the coin exchange machine\n");
    printf("6. Use detergent vending machine\n");
    printf("7. Use Fabric softener vending machinen\n");
    printf("8. Exit the program\n");

    printf("\n");

    scanf("%d", &mode);

    printf("\n");

    switch(mode) {
        case 1:
            printf("Enter your name: ");
            scanf("%s", name);

            printf("Enter the size of the cabinet (7kg, 10kg, 13kg, 17kg or 25kg): ");
            scanf("%d", &cabinet_size);

            switch(cabinet_size) {
                case 7:
                    cabinet_price = 20;
                    break;
                case 10:
                    cabinet_price = 30;
                    break;
                case 13:
                    cabinet_price = 40;
                    break;
                case 17:
                    cabinet_price = 60;
                    break;
                case 25:
                    cabinet_price = 80;
                    break;
                default:
                    printf("Invalid input.\n");
                    return 0;
            }

            printf("Enter coupon code (if any): ");
            scanf("%s", coupon_code);

            printf("\n");

            if(strcmp(coupon_code, "DISCOUNT10") == 0) {
                discount = 10.0 / 100.0; //10% discount
            } 
              else if(strcmp(coupon_code, "DISCOUNT20") == 0) {
                discount = 20.0 / 100.0; //20% discount
            } 
              else if(strcmp(coupon_code, "DISCOUNT30") == 0) {
                discount = 30.0 / 100.0; //30% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT40") == 0) {
                discount = 40.0 / 100.0; //40% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT50") == 0) {
                discount = 50.0 / 100.0; //50% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT60") == 0) {
                discount = 60.0 / 100.0; //60% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT70") == 0) {
                discount = 70.0 / 100.0; //70% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT80") == 0) {
                discount = 80.0 / 100.0; //80% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT90") == 0) {
                discount = 90.0 / 100.0; //90% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT100") == 0) {
                discount = 100.0 / 100.0; //100% discount
            }

            float total_price_washing_machine = (cabinet_price) * (1 - discount);

            printf("The total price is %.2f.\n", total_price_washing_machine);

            printf("\n");

            time_t rawtime;

            struct tm * timeinfo;

            time (&rawtime);

            timeinfo = localtime (&rawtime);

            time_of_use = timeinfo->tm_hour * 60 + timeinfo->tm_min;

            estimated_time = time_of_use + cabinet_size;

            FILE *file_pointer;

            file_pointer = fopen("washing_machine_users.txt", "a");

            fprintf(file_pointer, "%s %d %d %d\n", name, time_of_use, estimated_time, cabinet_size);

            fclose(file_pointer);

            break;

        case 2:

        {
            FILE *file_pointer;

            file_pointer = fopen("washing_machine_users.txt", "r");

            if(file_pointer == NULL) {
                printf("Error opening file.\n");
                return -1;
            }

            char user_name[20];
            int user_time_of_use;
            int user_estimated_time;
            int user_cabinet_size;

            time_t rawtime;

            struct tm * timeinfo;

            time (&rawtime);

            timeinfo = localtime (&rawtime);

            int current_time = timeinfo->tm_hour * 60 + timeinfo->tm_min;

            while(fscanf(file_pointer, "%s %d %d %d\n", user_name, &user_time_of_use, &user_estimated_time, &user_cabinet_size) != EOF) {
                if(current_time >= user_time_of_use && current_time <= user_estimated_time) {
                    printf("%s's washing machine (%dkg) is busy.\n", user_name, user_cabinet_size);
                } else {
                    printf("%s's washing machine (%dkg) is empty.\n", user_name, user_cabinet_size);
                }
            }

            printf("\n");

            fclose(file_pointer);
        }
            break;
            

        case 3:
        {
            printf("Enter your name: ");
            scanf("%s", name);

            printf("Enter the size of the cabinet (15kg or 30kg): ");
            scanf("%d", &cabinet_size);

            switch(cabinet_size) {
                case 15:
                    cabinet_price = 40;
                    break;
                case 30:
                    cabinet_price = 60;
                    break;
                default:
                    printf("Invalid input.\n");
                    return 0;
            }

            printf("Enter coupon code (if any): ");
            scanf("%s", coupon_code);

            printf("\n");

            if(strcmp(coupon_code, "DISCOUNT10") == 0) {
                discount = 10.0 / 100.0; //10% discount
            } 
              else if(strcmp(coupon_code, "DISCOUNT20") == 0) {
                discount = 20.0 / 100.0; //20% discount
            } 
              else if(strcmp(coupon_code, "DISCOUNT30") == 0) {
                discount = 30.0 / 100.0; //30% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT40") == 0) {
                discount = 40.0 / 100.0; //40% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT50") == 0) {
                discount = 50.0 / 100.0; //50% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT60") == 0) {
                discount = 60.0 / 100.0; //60% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT70") == 0) {
                discount = 70.0 / 100.0; //70% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT80") == 0) {
                discount = 80.0 / 100.0; //80% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT90") == 0) {
                discount = 90.0 / 100.0; //90% discount
            }
              else if(strcmp(coupon_code, "DISCOUNT100") == 0) {
                discount = 100.0 / 100.0; //100% discount
            }

            float total_price_dryer_machine = (cabinet_price) * (1 - discount);

            printf("The total price is %.2f.\n", total_price_dryer_machine);

            printf("\n");

            time_t rawtime;
            struct tm * timeinfo;

            time (&rawtime);
            timeinfo = localtime (&rawtime);

            time_of_use = timeinfo->tm_hour * 60 + timeinfo->tm_min;

            estimated_time = time_of_use + cabinet_size;

            FILE *file_pointer;

            file_pointer = fopen("dryer_machine_users.txt", "a");

            fprintf(file_pointer, "%s %d %d %d\n", name, time_of_use, estimated_time, cabinet_size);

            fclose(file_pointer);
        }
            break;
        
        case 4:
        {
            FILE *file_pointer;

            file_pointer = fopen("dryer_machine_users.txt", "r");

            if(file_pointer == NULL) {
                printf("Error opening file.\n");
                return -1;
            }

            char user_name[20];
            int user_time_of_use;
            int user_estimated_time;
            int user_cabinet_size;

            time_t rawtime;

            struct tm * timeinfo;

            time (&rawtime);

            timeinfo = localtime (&rawtime);

            int current_time = timeinfo->tm_hour * 60 + timeinfo->tm_min;

            while(fscanf(file_pointer, "%s %d %d %d\n", user_name, &user_time_of_use, &user_estimated_time, &user_cabinet_size) != EOF) {
                if(current_time >= user_time_of_use && current_time <= user_estimated_time) {
                    printf("%s's dryer machine (%dkg) is busy.\n", user_name, user_cabinet_size);
                } else {
                    printf("%s's dryer machine (%dkg) is empty.\n", user_name, user_cabinet_size);
                }
            }

            printf("\n");
            fclose(file_pointer);
        }
            break;

        case 5:

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


        case 6:
        {
            int choice;
            float price;

            printf("Welcome to the detergent Vending Machine!\n");
            printf("Please select a detergent:\n");
            printf("1. Brand A - $10\n");

            printf("2. Brand B - $12\n");

            printf("3. Brand C - $14\n");

            printf("4. Brand D - $18\n");

            printf("\n");
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

                default:
                    printf("Invalid choice.\n");
                    break;
           }
            printf("\n");

            printf("You have selected detergent %d for $%.2f\n", choice, price);
            printf("Thank you for using our vending machine!\n");

            printf("\n");
            }
            break;
        
        case 7:
        {
            int choice;
            float price;

            printf("Welcome to the Fabric Softener Vending Machine!\n");
            printf("Please select a fabric softener:\n");
            printf("1. Brand A - $10\n");

            printf("2. Brand B - $12\n");

            printf("3. Brand C - $14\n");

            printf("4. Brand D - $18\n");

            printf("\n");
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

                default:
                    printf("Invalid choice.\n");
                    break;
           }
            printf("\n");

            printf("You have selected fabric softener %d for $%.2f\n", choice, price);
            printf("Thank you for using our vending machine!\n");

            printf("\n");
            }
            break;

        case 8:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid input.\n");
            return 0;
    }

    return 0;
}