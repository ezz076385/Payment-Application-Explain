#include "card.h"

char temp[25];
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Enter Your Name : ");
	fgets(temp, sizeof(temp), stdin);
	temp[strcspn(temp, "\n")] = "\0";

	if (strlen(temp)== NULL || strlen(temp)<20 || strlen(temp)>20)
	{
		printf("Your Name is Wrong , Please Try Again.");
		cardData->cardHolderName[0] = '\0';
		return WRONG_NAME;
	}
	else
	{
		printf("Your Name Card Ok ♥");
		strcpy((char *)&cardData->cardHolderName, temp);
		return CARD_OK;
	}
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	char date = 0[6]; 
	int month, year;

	printf("\n Enter Your Card Expiry Date (MM/YY): ");
	//scanf("%5s", date); //(5 cahr + Null)
	fgets(temp, sizeof(temp), stdin);
	

	if (date == NULL || strlen(date) !=5)

	{
		printf("Wrong Expriaton Date , Please Try Again \n");
		cardData->cardExpirationDate[0] = '\0';
		return WRONG_EXP_DATE;
	}
	else
	{
		printf("Your Card Expriation Ok ♥");
		strcpy((char*)&cardData->cardExpirationDate, temp);
		return CARD_OK;
	}
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Enter The Card Primary Account Number (PAN): ");
	fgets(temp, sizeof(temp), stdin);

	if (temp == NULL || strlen(temp) < 16 ||strlen(temp) >19 )
	{
		printf("Wrong PAN Number , Please Try Again");
		cardData->primaryAccountNumber[0] = '\0';
		return WRONG_PAN;
	}
	else
	{
		strcpy((char*)&cardData->primaryAccountNumber, temp);
		return CARD_OK;
	}
}