/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW04_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw4.c                                                                    */
/* ---------                                                                */
/* Created on 24/03/2016 by Emre_Çelik                                      */
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
/* üs alma fonksiyonu                                                       */
double power(double number1,int number2);
/*  faktöriyel fonksiyonu                                                   */
int fact(int number);
/*  cosinus hesaplama fonksiyonu                                            */
double cosine(int degree,int n);
/* sinus hesaplama fonksiyonu                                               */
double sine(int degree,int n);
/* kullanıcıdan inputlar alma fonksiyonu                                    */
void  getInputs(int *degree,int *n,int *exit);
/*--------------------------------------------------------------------------*/
/*                      Function Implementations                            */
/*--------------------------------------------------------------------------*/
int main(void)
{
    int d=0,n=0,e=0;
    while(e==0)
    {
    getInputs(&d,&n,&e);
    printf("sin(%d) where n is %d = %.4f\n",d,n,sine(d,n));
    printf("cos(%d) where n is %d = %.4f\n",d,n,cosine(d,n)); 
    }    
    return 0;
}
/* üs alma fonksiyonu                                                       */
double power(double number1,int number2)
{
    int i;
    double result=1;
    if(number2==0)
    {
        result = 1;
    }
    else
    {
         for(i=1;i<=number2;i++)
        {
            result *= number1;
        }
    }
   
    return result;
}
/*  faktöriyel fonksiyonu                                                   */
int fact(int number)
{
    int i,result=1;
    if(number==0)
    {
        result = 1;
    }
    else
    {
        for(i=1;i<=number;i++)
        {
            result *= i;
        }
    }
    return result;
}
/* derece ve n inputlarini alma fonksiyonu                                  */
void  getInputs(int *degree,int *n,int *exit)
{
/*  e(exit)' yi okumak için gerekli degişken tanımlaması                    */
    char temp;
    *degree=0;
    *n=0;
    *exit=0;    
/*ilk okunan değer integer degilse karakter olarak oku ve eger e ise exit=1 */    
    if(scanf("%d",degree)!=1)
    {  
        scanf("%c",&temp);
        if(temp=='E' || temp=='e')
        {
            *exit=1;   
        }    
    }
/* degilse ikinci degeri oku                                                */
    else
    {   
        scanf("%d",n);  
    }         
}
/*  cosinus hesaplama fonksiyonu                                            */
double cosine(int degree,int n)
{
/* dongunun kontrol degiskeni                                               */
    int i=0; 
/*  cosinus toplam degiskeni,radyan degiskeni                               */
    double cosx=0,rad;
/*  derece 360 dan buyuk olmasi durumunda mod alma                          */    
    if(degree>360)
    {
        degree=(degree%360);
    }
/*  dereceyi radyana cevirme                                                */        
    rad = (degree * pi)/180;
/*  seri toplam formulu ile islemin dongu icinde yapilmasi                  */
    for(i=0;i<n;i++)
    {
        cosx += ( (power((-1),i)) * (power(rad,2*i)) ) / ( fact(2*i) );
    }
/*  toplamin sonucunun dondurulmesi                                         */
    return cosx;
}
/* sinus hesaplama fonksiyonu                                               */
double sine(int degree,int n)
{
/* dongunun kontrol degiskeni                                               */
    int i=0;
/*  sinus toplam degiskeni,radyan degiskeni                                 */    
    double sinx=0,rad;
/*  derece 360 dan buyuk olmasi durumunda mod alma                          */    
    if(degree>360)
    {
        degree=(degree%360);
    }
/*  dereceyi radyana cevirme                                                */        
    rad = (degree * pi)/180;
/*  seri toplam formulu ile islemin dongu icinde yapilmasi                  */
    for(i=0;i<n;i++)
    {
        sinx += ( (power((-1),i)) * (power(rad,2*i+1)) ) / ( fact(2*i+1) );
    }
/*  toplamin sonucunun dondurulmesi                                         */
    return sinx;
}
/*--------------------------------------------------------------------------*/
/*                            End of hw4.c                                  */
/*--------------------------------------------------------------------------*/


/*
#include <stdio.h>
#define pi 3.14
double power(double number1,int number2);
int fact(int number);
double cosine(int degree,int n);
double sine(int degree,int n);
void  getInputs(int *degree,int *n,int *exit);


double power(double number1,int number2)
{
    int i;
    double result=1;
    if(number2==0)
    {
        result = 1;
    }
    else
    {
         for(i=1;i<=number2;i++)
        {
            result *= number1;
        }
    }
   
    return result;
}

int fact(int number)
{
    int i,result=1;
    if(number==0)
    {
        result = 1;
    }
    else
    {
        for(i=1;i<=number;i++)
        {
            result *= i;
        }
    }
    return result;
}

void  getInputs(int *degree,int *n,int *exit)
{
    char temp;
    *degree=0;
    *n=0;
    *exit=0;    
    if(scanf("%d",degree)!=1)
    {  
        scanf("%c",&temp);
        if(temp=='E' || temp=='e')
        {
            *exit=1;   
        }    
    }
    else
    {   
        scanf("%d",n);  
    }         
}

double cosine(int degree,int n)
{
   int i=0;
    double cosx=0,rad,temp=degree;
    if(degree>180)
        degree=(degree%180);
    rad = (degree * pi)/180;
    for(i=0;i<n;i++)
    {
        cosx += ( (power((-1),i)) * (power(rad,2*i)) ) / ( fact(2*i) );
    }
    if(temp>180 && temp<=360)
        cosx*=-1;
    return cosx;
}

double sine(int degree,int n)
{
    int i=0,temp=degree;
    double sinx=0,rad;
    if(degree>180)
        degree=(degree%180);
    rad = (degree * pi)/180 ;
    for(i=0;i<n;i++)
    {
        sinx += ( (power((-1),i)) * (power(rad,2*i+1)) ) / ( fact(2*i+1) );
    }
    if(temp>=180 && temp<=360)
        sinx*=-1;
    return sinx;
   
}

*/
