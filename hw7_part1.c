/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW07_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw7_part1.c                                                              */
/* ---------                                                                */
/* Created on 15/04/2016 by Emre_Çelik                                      */

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h> 
/* abs fonksiyonu için                                                      */
#include <stdlib.h>                
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
int isPalindrome(char *str);
/* recursion check islemlerinin yapıldığı fonksiyon                         */
int checkString(char *str,int right);
int main(void)
{
    char str[]="anc";
    printf("%d\n",isPalindrome(str));
    return 0;
}

int isPalindrome(char *str)
{
    int right,count=0;
/* str nin son indisini bulma ve aynı zamanda icindeki harf sayısını bulma  */    
    for(right=0;str[right]!='\0';right++)
    {
        if( (str[right]>='a' && str[right]<='z') || 
            (str[right]>='A' && str[right]<='Z')   )
            count++;
    }
    right--;
/*  null degilse veya icinde harf varsa kontrol ettigin fonksionu dondur    */    
    if(str!=NULL && count!=0)
        return checkString(str,right);        
/*  degilse zaten return 0 olur                                             */            
    return 0;   
}

int checkString(char *str,int right)
{
/* son elemana kadar git ve sagdaki elemanın indisi en az 1 olsun           */
    if(str[0]!='\0' && right>0)
    {   
/* soldaki eleman harf olmalı                                               */    
        if((str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))
        {
/* sagdaki eleman da harf olmalı                                            */        
            if((str[right]>='a' && str[right]<='z') || 
                                (str[right]>='A' && str[right]<='Z')   )
            {
/*  iki harf birbirine esit veya ascii farkları a - A (32) ise devam et     */            
                if(str[0]==str[right] || abs(str[0]-str[right])=='a'-'A')
                {
/* soldaki elamanın bi sagındakinden itibaren cagır ve sag indis 2 azalt    */
                    return checkString(&str[1],right-2);
                }
/* iki harf eslesmezse direk return 0                                       */                
                else
                    return 0;
            }
/* sagdaki eleman harf degilse diziyi soldan sabit tutup sag indisi 1 azalt */            
            return checkString(&str[0],right-1);
        }
/* soldaki eleman harf degilse soldan ve sagdan 1 daralt                    */        
        return checkString(&str[1],right-1);
    }
/* hic return 0 yapmamıssa buraya gelir ve 1 dondurur                       */    
    return 1;    
}
/*--------------------------------------------------------------------------*/
/*                           END OF HW7_PART1.C                             */
/*--------------------------------------------------------------------------*/
