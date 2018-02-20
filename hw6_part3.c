/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW06_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw6_part3.c                                                              */
/* ---------                                                                */
/* Created on 08/04/2016 by Emre_Çelik                                      */

/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>              
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/* substr nin str nin içindeki tekrar sayısını bulma fonksiyonu             */
int count (char *str,char *substr);

int main(void)
{
    printf("%d\n",count(" ecemecenecetr ece","ece"));
    
    return 0;
}

int count (char *str,char *substr)
{
/* döngü degiskenleri(i,j),çift indisli harflerinin eşleştiği miktar(count)*/
/* substr nin kaç kez tekrar ettiğini tutan degisken(resCount)             */
    int i,j=0,count,resCount=0;
/* needle haystack tan daha uzun ise veya ikisinden biri NULL ise return 0 */        
    if(strlen(substr)>strlen(str) || str==NULL || substr==NULL)
        return 0;
/*  str nin tüm karakterlere bakacak kadar dönsün                          */        
    for(i=0;str[i]!='\0';i++)
    {
/*eğer strnin  i. indisteki karakter substr nin ilk karakteriyle eşleştiyse*/    
           if(str[i]==substr[0])
           {
/* her seferinde sayac sıfırlanacak                                        */                      
                count=0;
/* substr ın uzunluğu kadar dönsün                                         */                                
                for(j=0;j<strlen(substr);j+=2)
                {
/* str i. indisten itibaren çift indisleri karsılartır ve count artır      */                              
                    if(str[i+j]==substr[j])
                    {    
                        count++;                        
                    }
                }
/* sayac j nin yarısıysa(çifter gittiği için) döndürülecek sayacı arttır   */                                
                if(count==j/2)
                    resCount++;
           }
    }       
/*  resCount u döndür                                                      */                                
    return resCount;            
}
/*                      End of hw6_part3.c                                  */
/*############################################################################*/
/* yorumsuz
#include <stdio.h>
#include <string.h>
int count (char *str,char *substr);

int count (char *str,char *substr)
{
    int i,j=0,count,resCount=0;
    if(strlen(substr)>strlen(str))
        return 0;
    for(i=0;str[i]!='\0';i++)
    {
           if(str[i]==substr[0])
           {
                count=0;
                for(j=0;j<strlen(substr);j+=2)
                {
                    if(str[i+j]==substr[j])
                    {    
                        count++;                        
                    }
                }
                if(count==j/2)
                    resCount++;
           }
    }                                   
    return resCount;            
}
*/
