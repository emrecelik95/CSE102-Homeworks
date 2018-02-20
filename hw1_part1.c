/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW01_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw1_part1.c                                                              */
/* ---------
*/
/* Created on 22/02/2016 by Emre_Çelik                                      */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*      The hw1_part1.c contains the implementations of the first part of   */
/*		the homework I, which are used for calculating final grade of a 	*/
/*  	student.                                                            */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*--------------------------------------------------------------------------*/

int main(void)
{
/*  types of variables                                                      */
	float mid1Weight,mid2Weight,mid3Weight,hw1Weight,hw2Weight,finalExamWeight;
	float midGrade1,midGrade2,midGrade3,hw1,hw2,finalExam,finalGrade;
/*  weight and grade inputs from user for each exam                         */
	printf("Please enter the 1. midterm weight: ");
	scanf("%f",&mid1Weight);
	printf("Please enter the 2. midterm weight: ");
	scanf("%f",&mid2Weight);
	printf("Please enter the 3. midterm weight: ");
	scanf("%f",&mid3Weight);
	printf("Please enter the 1. homework weight: ");
	scanf("%f",&hw1Weight);
	printf("Please enter the 2. homework weight: ");
	scanf("%f",&hw2Weight);
	printf("Please enter the final exam weight: ");
	scanf("%f",&finalExamWeight);
	printf("Please enter the 1. midterm grade: ");
	scanf("%f",&midGrade1);
	printf("Please enter the 2. midterm grade: ");
	scanf("%f",&midGrade2);
	printf("Please enter the 3. midterm grade: ");
	scanf("%f",&midGrade3);
	printf("Please enter the 1. homework grade: ");
	scanf("%f",&hw1);
	printf("Please enter the 2. homework grade: ");
	scanf("%f",&hw2);
	printf("Please enter the final exam grade: ");
	scanf("%f",&finalExam);
/*  calculation of final grade                                               */
	finalGrade=(mid1Weight*midGrade1+mid2Weight*midGrade2+mid3Weight*midGrade3+
	hw1Weight*hw1+hw2Weight*hw2+finalExamWeight*finalExam)/100;
/*  output of final grade                                					 */
	printf("Your final grade is: %.2f \n",finalGrade);
/*	the function prints the output in itself,there is no value to be returned*/ 
	return 0;
}
/*---------------------------------------------------------------------------*/
/*                            End of hw1_part1.c                             */
/*---------------------------------------------------------------------------*/
