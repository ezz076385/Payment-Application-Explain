#ifndef CAED_H
#define CARD_H

typedef unsigned char uint8_t;
typedef unsigned char EN_cardError_t;
typedef unsigned char ST_cardData_t;
typedef unsigned char cardData;
typedef unsigned char cardHolderName;

typedef struct st_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t prinaryAccountNumber[20];
    uint8_t cardExpirationData[6];
} st_cardData_t;

typedef enum En_cardError_t
{
    card_ok,
    WRONG_NAME,
    WRONG_EXP_DATE,
    WRONG_PAN
} En_cardError_t;

EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);
#endif