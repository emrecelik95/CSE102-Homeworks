/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW02_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw2_part1.c                                                              */
/* ---------
*/
/* Created on 29/02/2016 by Emre_Çelik                                      */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*      The hw1_part1.c contains the implementations of the first part of   */
/*		the homework 2, which are used for calculating last grade of a 	    */
/*  	student.                                                            */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
void calculateLastGrade();

/*--------------------------------------------------------------------------*/
/*                      Function Implementations                            */
/*--------------------------------------------------------------------------*/
/* this function contains weight and grade  inputs and calculates the final */
/* grade,then prints the result in itself                                   */
void caltulateLastGrade()
{
/*  define the variables and their data types                               */
    float midtermWeight,homeworkWeight,finalExamWeight;
    float midtermGrade,homeworkGrade,finalExamGrade;
    float finalGrade;
/*  get weight and grade inputs from user by assigning them to variables    */
    printf("Please enter the 1. midterm weight:");
    scanf("%f",&midtermWeight);
    printf("Please enter the 1. homework weight:");
    scanf("%f",&homeworkWeight);
    printf("Please enter the 1. final weight:");
    scanf("%f",&finalExamWeight);
    
    printf("Please enter the 1. midterm grade:");
    scanf("%f",&midtermGrade);
    printf("Please enter the 1. homework grade:");
    scanf("%f",&homeworkGrade);
    printf("Please enter the 1. final grade:");
    scanf("%f",&finalExamGrade);
/*  calculate the final grade of the student by using grades of the student */
    finalGrade=( (midtermWeight*midtermGrade) + (homeworkWeight*homeworkGrade)
    + (finalExamWeight*finalExamGrade) ) / 100 ; 
/*  print the result                                                        */
    printf("Your final grade is: %f\n",finalGrade);
}


int main(void)
{
/*  call the function                                                       */
    caltulateLastGrade();
    return 0;
}
/*---------------------------------------------------------------------------*/
/*                            End of hw2_part1.c                             */
/*---------------------------------------------------------------------------*/
