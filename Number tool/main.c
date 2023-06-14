#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInputNum(void)
{
    int a;
    char buf[1024]; // use 1KiB just to be sure

    do
    {
        //printf("enter a number: ");
        if (!fgets(buf, 1024, stdin))
        {
            // reading input failed, give up:
            return 1;
        }

        // have some input, convert it to integer:
        a = atoi(buf);
        if (a ==0)
        {
            printf("invalid choice!\n");
        }
    } while (a == 0); // repeat until we got a valid number

    return a;
}

int tempConvert()
{
    int tempChoice;
    float tempInput;
    float tempOutput;
    char buf[1024];
    printf("\n1) celsius  to fahrenheit   2) celsius to kelvin    3) fahrenheit to celsius");
    printf("\n4)fahrenheit to kelvin      5) kelvin to celsius    6) kelvin to fahrenheit");
    printf("\n\nenter a choice: ");
    tempChoice = getInputNum();

    switch(tempChoice)
    {
    case 1:
        printf("enter temperature in celsius: ");
        tempInput = getInputNum();
        tempOutput = (tempInput*9/5) + 32;
        printf("the result is: %.1f", tempOutput);
        break;
    case 2:
        printf("enter temperature in celsius: ");
        tempInput = getInputNum();
        tempOutput = tempInput + 273.15;
        printf("the result is: %.2f", tempOutput);
        break;
    case 3:
        printf("enter temperature in fahrenheit: ");
        tempInput = getInputNum();
        tempOutput = (tempInput-32) * 5/9;
        printf("the result is: %.2f", tempOutput);
        break;
    case 4:
        printf("enter temperature in fahrenheit: ");
        tempInput = getInputNum();
        tempOutput = (tempInput-32)*5/9+273.15;
        printf("the result is: %.3f", tempOutput);
        break;
    case 5:
        printf("enter temperature in kelvin: ");
        tempInput = getInputNum();
        tempOutput = tempInput-273.15;
        printf("the result is: %.2f", tempOutput);
        break;
    case 6:
        printf("enter temperature in kelvin: ");
        tempInput = getInputNum();
        tempOutput = (tempInput-273.15)*9/5+32;
        printf("the result is: %.2f", tempOutput);
        break;

    }

}

void choiceChooser(int choosed)
{
    switch(choosed)
     {
     case 1:
        tempConvert();
        break;
     default:
        printf("\ninvalid choice\n\n");
        main();
     }
}

int main()
{
    int choice;

    printf("1) temperature converter\n\n");

    while(choice >= 2)
    {
        printf("enter a choice: ");
        choice = getInputNum();
        if (choice >= 2)
        {
            printf("invalid choice!\n");
        }
    }



    choiceChooser(choice);

}


