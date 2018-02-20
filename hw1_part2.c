/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW01_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw1_part2.c                                                              */
/* ---------
*/
/* Created on 22/02/2016 by Emre_Çelik                                      */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*      The hw1_part2.c contains the implementations of the second part of  */
/*		homework I, which are used for calculating how many days the user   */
/*  	has lived and if the user lived in another planet,how old the user  */
/*      would be.                                                           */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*--------------------------------------------------------------------------*/

int main(void)
{
/*  types of variables                                                      */	
	int currentYear,currentMonth,currentDay;
	int birthYear,birthMonth,birthDay,totalDays;
	int planetHours,planetDays,planetMonths;
	int newTotalDays,newYear,newMonth,newDay;
/*  current date and user's birthdate inputs from user						*/
	printf("Please enter the current date.\n");
	
	printf("Year: ");
	scanf("%d",&currentYear);
	printf("Month: ");
	scanf("%d",&currentMonth);
	printf("Day: ");
	scanf("%d",&currentDay);
	printf("Please enter your birthdate.\n");
	printf("Year: ");
	scanf("%d",&birthYear);
	printf("Month: ");
	scanf("%d",&birthMonth);
	printf("Day: ");
	scanf("%d",&birthDay);

/*  the calculation of total days that the user has lived					*/
	totalDays=(currentYear-birthYear)*365+(currentMonth-birthMonth)*30
	+(currentDay-birthDay);
/*	the output of total days 												*/
	printf("You have lived %d days. \n",totalDays);

/*  inputs about time informations of another planet from user				*/ 
	printf("Please enter about the time of another planet: \n");
	
	printf("How many hours is a day? ");
	scanf("%d",&planetHours);
	printf("How many days is a month? ");
	scanf("%d",&planetDays);
	printf("How many months is a year? ");
	scanf("%d",&planetMonths);

/*  the calculation of total days in another planet    					    */
	newTotalDays=(totalDays*24)/(planetHours);
/*  the calculation of total year in another planet  						*/
	newYear=newTotalDays/(planetDays*planetMonths);
/*  the calculation of month after year in another planet  					*/
	newMonth=(newTotalDays%(planetDays*planetMonths))/planetDays;
/*  the calculation of days after years and months in another planet  		*/
	newDay=(newTotalDays%(planetDays*planetMonths))%planetMonths;
/*	the output of time informations about how old the user would be         */
	printf("If you lived in a planet where a day is %d hours, ",planetHours);
	printf("a month is %d days and a year  is",planetDays);
	printf(" %d months: you were %d years,",planetMonths,newYear);
	printf(" %d months and %d days old. \n",newMonth,newDay);
/*the function prints the output in itself,there is no value to be returned */ 
	return 0;
}
/*---------------------------------------------------------------------------*/
/*                            End of hw1_part2.c                             */
/*---------------------------------------------------------------------------*/
