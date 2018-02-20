/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW03_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw3.c                                                                    */
/* ---------                                                                */
/* Created on 08/03/2016 by Emre_Çelik                                      */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*      The hw3.c contains the implementations of the homework 3 which are  */
/*		used for checking if the given number is an odd , a factorial       */
/*  	or a narcissistic number.                                           */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h> /* includes math functions like pow                       */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/* this function checks if the number is odd or not                         */ 
void oddFunction(int number);
/*this function checks if the number is factorial or not                    */
void factorialFunction(int number);
/*this function checks if the number is narcissistic or not                 */
void narcFunction(int number);
/*--------------------------------------------------------------------------*/
/*                      Function Implementations                            */
/*--------------------------------------------------------------------------*/
void oddFunction(int number)
{
/*  if the remainder is 1,then the number is odd                            */
    if (number % 2 == 1) 
        {printf ("%d is an odd number !\n",number);} /* print the output    */
    else
        {printf ("%d is not an odd number !\n",number);} /*print the output */
}

void factorialFunction(int number)
{
/*  define variables that are used in loop                                  */
	int i=2;
/* this variable is copy of number(original)                                */
	double temp=number;
/* the process of dividing the number by numbers starting 2                 */
	while(temp>1) /* it works till temp > 1                                 */
	{
        temp/=i;
        i++;
	}
/* this condition means that it is divisible without remainder by 2.3.4.5...*/
	if(temp==1) 
	    {printf("%d is a factorial number ! \n",number);} /*print the output*/
	else
	    {printf("%d is not a factorial number ! \n",number);}
}

void narcFunction(int number)
{
/* define variables for digit count(digit),loop variable(i),total(sum)      */
/* for copy of original number(temp,temp2)                                  */
	int digit,i,temp=number,temp2=number,sum;
/*  calculates digit count of the number by dividing number by 10           */
	for(digit=1;temp>=10;digit++)               /* till temp > = 10         */
	{
		temp/=10; 
	}
/* calculates each digit to the power of digit count then adds all of them  */
	for(i=1;i<=digit;i++) 
	{	
		sum += pow((temp2%10),digit);
		temp2/=10; 	
	}
/* the condition of being narcissistic number,then print the output         */
	if(sum==number) 
	    {printf("%d is narcissistic number ! \n",number);}	
	else
	    {printf("%d is not narcissistic number ! \n",number);}
}

int main(void)
{
/* define variables,to get original number(num),process to be done(property)*/
	int num,property;   
/* to ask to continue (choice)                                              */                
	char choice='y';
/*  the message of entry partition                                          */
	printf("*****************************************************\n");
	printf("*                   WELCOME !                       *\n");
	printf("*  This Program checks whether the given number     *\n");
	printf("* is an odd, a factorial or a narcissistic number   *\n");
	printf("*****************************************************\n");
/*  this loop works as long as user enters 'y' and ends by entering 'n'     */ 	
	while(choice=='y' || choice=='Y')
	{
/*      get the number from user                                            */
	    printf("Please enter a positive integer : ");
/*      assign to a variable called num                                     */
	    scanf("%d",&num); 
/*      the condition of negativity                                         */
	    if(num<=0) 
		    {
			    printf("The entered number is not positive.\n");
		    }
	    else
          	{
/*           ask user to check property,then do what to do                  */ 
           	    printf("Which property would you like to check?\n");
	       	    printf("1)Odd number\n"); 
	       	    printf("2)Factorial number\n"); 
	       	    printf("3)Narcissistic number\n"); 
	            printf("Please enter(1/2/3): ");
/*      assign choice of user to a variable called property                 */
        	    scanf(" %d",&property);
/*      check the property then do what to do                               */ 
        	    switch (property) 
	        	    {
	        	        case 1: 
/*                      call the oddFunciton                                */
	        	            oddFunction(num);
	        	            break;
	        	        case 2:
/*                      call the factorialFunciton                          */
	        	        	factorialFunction(num);
	        	        	break; 
	        	        case 3:
/*                      call the narcFunciton                               */
	        	        	narcFunction(num);
	        	        	break;
	        	        default: 
	        	            /* do nothing */ 
	        	            break;
     
	          	    }
	       	}    
/*          ask user to continue                                            */ 
	        printf("Do you want to continue (y/n)? ");
		    scanf(" %c",&choice);
/*          the condition of  wrong choice                                  */ 		    
		    if(choice!='y' && choice!='n' && choice!='Y' && choice!='N')
	        {
/*          warning message                                                 */
	            printf("Please enter (y or n)! \n");				        
		    }	  	
    }
    printf("Good Bye !\n");  
    return 0;
}
/*--------------------------------------------------------------------------*/
/*                            End of hw3.c                                  */
/*--------------------------------------------------------------------------*/
