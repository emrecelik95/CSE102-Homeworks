/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW06_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw6_part2.c                                                                    */
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
/* needle ı  haystack ta arayan fonksiyon                                   */
char *matcher (char *haystack,char *needle);
int main(void)
{
    char *ptr=matcher("lorem ipsum dolor amet","lerom");
    printf("\n");
    printf("%s\n",ptr);
    
    return 0;
}

char *matcher (char *haystack,char *needle)
{
/* döngü degiskenleri(i,j),çift indisli harflerinin eşleştiği miktar(count)*/ 
    int i,j=0,count;
/* needle haystack tan daha uzun ise veya ikisinden biri NULL ise return NULL*/    
    if(strlen(needle)>strlen(haystack) || needle==NULL || haystack==NULL)
        return NULL;
/*  haystackın tüm karakterlere bakacak kadar dönsün                       */        
    for(i=0;haystack[i]!='\0';i++)
    {
/*eğer haystack i. indisteki karakter needle ın ilk karakteriyle eşleştiyse*/
           if(haystack[i]==needle[0])
           {
/* her seferinde sayac sıfırlanacak                                        */           
                count=0;
/* needle ın uzunluğu kadar dönsün                                         */                
                for(j=0;j<strlen(needle);j+=2)
                {
/*haystack i. indisten itibaren çift indisleri karsılartır ve count artır */              
                    if(haystack[i+j]==needle[j])
                    {    
                        count++;                        
                    }
                }
/* sayac j nin yarısıysa(çifter gittiği için) i.indisten itibaren return et */                
                if(count==j/2)
                    return &haystack[i];
           }
    }                                   
    return NULL;            
}
/*                      End of hw6_part2.c                                        */
/*##########################################################################*/
/*  yorumsuz
#include <stdio.h>
#include <string.h>
char *matcher (char *haystack,char *needle);

char *matcher (char *haystack,char *needle)
{
    int i,j=0,count;
    if(strlen(needle)>strlen(haystack))
        return NULL;
    for(i=0;haystack[i]!='\0';i++)
    {
           if(haystack[i]==needle[0])
           {
                count=0;
                for(j=0;j<strlen(needle);j+=2)
                {
                    if(haystack[i+j]==needle[j])
                    {    
                        count++;                        
                    }
                }
                if(count==j/2)
                    return &haystack[i];
           }
           printf(" ");
    }
  return NULL;            
}
*/
