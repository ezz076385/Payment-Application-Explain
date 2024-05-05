#include <stdio.h>
#include <string.h>
#include "card.h"

// typedef unsigned char cardData;
int main()
{
    char temp[25];
    EN_cardError_t getCardHolderName(ST_cardData_t * cardData) //..................................
    {
        printf("Please Enter Your Name : ");
        gets(temp);
        if(temp == NULL || strlen(temp) < 20 || strlen(temp) > 24)
        {
            cardData->cardHolderName[0] = '\0';
            printf("you Entered Wrong Name, pleas try again");
            return WRONG_NAME;
        }else
        {
            strcpy((char *)cardData->cardHolderName, temp);
            printf("Your Name Card Ok ♥");
            return card_ok;
        }
    }

    EN_cardError_t getCardExpiryDate(ST_cardData_t * cardData) //..................................
    {
        char date[6];
        int month, year;
        printf("\n Enter Your Card Expiry Date (MM/YY): ");
        scanf("%5s", date);//(5 char + null)
        if (date == NULL || strlen(date) !=5)
        {
            cardData->cardHolderName[0] = '\0';
            printf("Wrong Expriation Date Please try Again\n");
            return WRONG_EXP_DATE;
        }
        if (sscanf(date,"%2d/%2d",&month,&year) !=2)
        {
            cardData->cardHolderName[0] = '\0';
            printf("Wrong Expriation Date Please try Again\n");
            return WRONG_EXP_DATE;
        }
        if (month < 1 || month > 12 || year < 0 || year > 99)
        {
            cardData->cardHolderName[0] = '\0';
            printf("Wrong Expriation Date Please try Again\n");
            return WRONG_EXP_DATE;
        }else
        {
            strcpy((char *)cardData->cardHolderName, temp);
            printf("Your Card Expriation Ok ♥");
            return card_ok;
        }
    }
    EN_cardError_t getCardPAN(ST_cardData_t * cardData) //..................................
    {
        printf("Enter The Card Primary Account Number (PAN): ");
        gets(temp);
        if (temp == NULL || strlen(temp) < 16 || strlen(temp) > 19)
        {
            cardData->cardHolderName[0] = '\0';
            printf("Wrong PAN Number , Please Try Again");
            return WRONG_PAN;
        }else
        {
            strcpy((char *)cardData->cardHolderName, temp);
            printf("Your Card PAN Ok ♥");
            return card_ok;
        }
    }

    return 0;
}