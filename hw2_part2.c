/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW02_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw2_part2.c                                                              */
/* ---------
*/
/* Created on 29/02/2016 by Emre_Çelik                                      */
/*                                                                          */
/* Description                                                              */
/* -----------                                                              */
/*      The hw1_part2.c contains the implementations of the second part of  */
/*		the homework 2, which are used for calculating area and perimeter  	*/
/*  	of certain geometric shapes.                                        */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#define pi 3.14

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
int areaofRectangle(int width,int height);
int perimeterofRectangle(int width,int height);
int areaofSquare(int edgeLengt);
int perimeterofSquare(int edgeLengt);
double areaofCircle(int radius);
double perimeterofCircle(int radius);

/*---------------------------------------------------------------------------*/
/*                      Function Implementations                             */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/* calculate area of rectangle by using its width and height,return result   */
int areaofRectangle(int width,int height)
{
	return (width * height);
}
/*---------------------------------------------------------------------------*/

/* calculate perimeter of rectangle by using its width and height then return*/
int perimeterofRectangle(int width,int height)
{
	return (2 * (width + height));
}
/*---------------------------------------------------------------------------*/

/* calculate area of square by using its edgeLengt then return the result    */
int areaofSquare(int edgeLengt)
{
	return (edgeLengt * edgeLengt);
}
/*---------------------------------------------------------------------------*/

/*calculate perimeter of square by using its edgeLengt then return the result*/
int perimeterofSquare(int edgeLengt)
{
	return (edgeLengt * 4);
}
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/*calculate area of circle by using its radius and pi,then return the result */
double areaofCircle(int radius)
{
	return (pi * radius * radius);
}
/*---------------------------------------------------------------------------*/

/*calculate perimeter of circle by using its radius and pi,then return result*/
double perimeterofCircle(int radius)
{
	return (2 * pi * radius);
}
/*---------------------------------------------------------------------------*/

int main(void)
{
	int widthofRectangle,heightofRectangle,area,perimeter;
	int widthofSquare,radius;

	printf("Please enter the width of the rectangle:");
	scanf("%d",&widthofRectangle);
	printf("Please enter the height of the rectangle:");
	scanf("%d",&heightofRectangle);

	area = areaofRectangle(widthofRectangle,heightofRectangle);
	perimeter=perimeterofRectangle(widthofRectangle,heightofRectangle);

	printf("The area of the rectangle is: %d\n",area);
	printf("The perimeter of the rectangle is: %d\n",perimeter);

	printf("Please enter the width of the square:");
	scanf("%d",&widthofSquare);

	area=areaofSquare(widthofSquare);
	perimeter=perimeterofSquare(widthofSquare);

	printf("The area of the square is: %d\n",area);
	printf("The perimeter of the square is: %d\n",perimeter);

	printf("Please enter the radius of the circle:");
	scanf("%d",&radius);

	printf("The area of the circle is: %.2f\n",areaofCircle(radius));
	printf("The perimeter of the circle is: %.2f\n",perimeterofCircle(radius));
	
	return 0;
}
/*---------------------------------------------------------------------------*/
/*                            End of hw2_part2.c                             */
/*---------------------------------------------------------------------------*/
