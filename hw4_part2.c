/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW04_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw4.c                                                                    */
/* ---------                                                                */
/* Created on 22/03/2016 by Emre_Çelik                                      */
/
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h> /* pow kullanmak icin                                     */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*kullanicidan sayi,tablo kalinligi ve yazdirma karakteri alma fonksiyonu   */
void getInputs(int *num ,int *borderWidth,char *borderChar);
/*  sayiyi yazdirma islemini yapan fonksiyon                                */
int printNumber(int num ,int borderWidth,char borderChar);
/*--------------------------------------------------------------------------*/
/*                      Function Implementations                            */
/*--------------------------------------------------------------------------*/
int main(void)
{
    int num=0,bWidth=0;
    char bChar;
    while(num>=0 && num<=99999)
        {
        getInputs(&num,&bWidth,&bChar);
        printNumber(num,bWidth,bChar);
        }
    return 0;    
}

/*       input alma fonksiyonu                                              */
void getInputs(int *num ,int *borderWidth,char *borderChar)
{
    *num=0;;
    *borderWidth=0;
    *borderChar=0;
    scanf("%d %d %c",num,borderWidth,borderChar);
}

/*  yazdirma fonksiyonu                                                     */
int printNumber(int num ,int borderWidth,char borderChar)
{
/* kontrol degiskenleri,basamak sayisi(digit),gecici degiskenler            */
    int i=0,j,k,l=0,digit=0,temp,tempDigit=0;
/* sayiyi kaybetmemek için kullanilan gecici degisken                       */
    temp=num;
/*  return 1 etme durumu                                                    */
    if(num<=99999 && num>=0)
    {
/* sayinin basamak sayisini bulma dongusu                                   */
    do
    {
        temp/=10;
        digit++;
    }while(temp!=0);
/*  ust kalinlik cizme donguleri(icice)                                     */ 
    for(k=0;k<borderWidth;k++)
    {
        for(l=1;l<=7*digit+borderWidth*2;l++)
        {
                printf("%c",borderChar);
        }
        printf("\n");
    }
/*  tum sayilarin tanimlanip borderla birlikte cizildiği donguler(icice)    */
/*  satir cizimleri icin (7 satir)                                          */
    for(i=1;i<=7;i++)
    {
/*  sol kalinlik cizimi                                                     */
        for(l=0;l<borderWidth;l++)
            {printf("%c",borderChar);}
/*  her basamak icin ayrı dongu ve her biri icin 7 karakterlik yatay alan   */
        for(k=0;k<digit;k++)
                {
/* sayiyi basamaklarına her bir dongu icin ayırıp gecici degiskene atama    */
                 if(tempDigit==0)
                tempDigit=digit;
                temp = ( num % (int)(pow(10,tempDigit)) - num % 
                (int)(pow(10,tempDigit-1))) / (int)pow(10,tempDigit-1);
                tempDigit--;
/* yazdirma islemi,ortak noktaya sahip sayilar birlikte tanimlanmistir      */
                for(j=1;j<=7;j++)
                {
/*  1 rakami icin tanimlama,koordinat duzlemi gibi noktalar belirtilmistir  */
                   if(temp==1)
                   {
                        if( j==4 && (i==2 || i==3 || i==4 || i==5 || i==6 ) )
                            printf("%c",borderChar);
                        else if( (i==3 && j==3 ) || (i==6 && (j==3 || j==5) ) )
                            printf("%c",borderChar);
                            else
                                printf(" ");  
                   }
/*  2 , 5 , 6 , 8 , 9 sayilarinin ortak noktalarinin ve kendilerinin tanimi */
                   else if(temp==2 || temp==5 || temp==6 || temp==8 || temp==9)
                   {
                       if( (i==2 || i==4 || i==6) && (j==3 || j==4 || j==5 ) )
                           printf("%c",borderChar);   
                       else if(temp==2)
                       {
                          if((i==3 && j==5) || (i==5 && j==3))
                                 printf("%c",borderChar);
                           else
                                 printf(" "); 
                       }
                       else if(temp==5 || 6 || 8 || 9)
                       {
                           if((i==3 && j==3) || (i==5 && j==5))
                                 printf("%c",borderChar);
                           else if(temp==6 && i==5 && j==3)
                                 printf("%c",borderChar);
                           else if( (temp==8 || temp==9) && 
                           (i==3 && j==5)){
                                 printf("%c",borderChar);}   
                           else if(temp==8 && i==5 && j==3)
                                 printf("%c",borderChar);         
                           else
                                 printf(" ");       
                       }     
                   }
/*  3 , 7 , 0  sayilarinin ortak noktalarinin ve kendilerinin tanimi        */
                  else if(temp==3 || temp==7 || temp==0)
                       if( i==2 && (j==3 || j==4 || j==5) )
                           printf("%c",borderChar);
                       else if((i==2 || i==3 || i==4 || i==5 || i==6) && j==5)
                           printf("%c",borderChar);
                       else if(i==6 &&(j==3||j==4||j==5)&&(temp==0 || temp==3)){
                           printf("%c",borderChar);}
                       else if((i==3 || i==4 || i==5)&& j==3 && temp==0)
                           printf("%c",borderChar);
                       else if( i==4 && (j==4 || j==5) && temp==3 )
                           printf("%c",borderChar); 
                       else 
                           printf(" "); 
/*          4 rakami icin tanimlama                                         */                  
                   else if( temp==4)
                            {
                                if( (i==2 || i==3) && j==3)
                                    printf("%c",borderChar);
                                else if(i==4 && (j==3 || j==4))
                                    printf("%c",borderChar);
                                else if((i==2 || i==3 || i==4 || i==5 || i==6 ) 
                                && j==5){
                                    printf("%c",borderChar);} 
                                else
                                    printf(" ");
                            }                        
                   else
                        printf(" ");            
                } 
              }
/*    sag kalinlik cizimi                                                   */
        for(l=0;l<borderWidth;l++)
            {printf("%c",borderChar);}
        printf("\n");
    }
/*    alt kalinlik cizimi                                                   */
    for(k=0;k<borderWidth;k++)
    {
        for(l=1;l<=7*digit+borderWidth*2;l++)
        {
                printf("%c",borderChar);
        }
        printf("\n");
    }
/*  basarili olma veya olmama durumunda deger dondurma islemi               */
    return 1;
    }
    else
    return 0;
}
/*--------------------------------------------------------------------------*/
/*                            End of hw4.c                                  */
/*--------------------------------------------------------------------------*/
