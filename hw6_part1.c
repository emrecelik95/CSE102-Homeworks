/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW06_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw6_part1.c                                                                    */
/* ---------                                                                */
/* Created on 08/04/2016 by Emre_Çelik                                      */

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
/* girilen stringin içinde hangi karakterden ne kadar var bulmaya yarar     */
void freq(char *str,int *fr);

int main(void)
{
    int fr[37],i;
    char str[]="..?aaAzZ9012";
    freq(str,fr);
    for(i=0;i<37;i++)
        printf("%d,",fr[i]);
    printf("\n");
    return 0;
}
void freq(char *str,int *fr)
{
/*  stringin tüm karakterlerini okuyabilmek için döngüdeki degisken          */
    int i;
/*  fr dizisinin içeriğinin doldurulması (0) yani default olarak             */   
    for(i=0;i<37;i++)
        fr[i]=0;   
/*  döngü str nin tüm karakterleri için dönecek                              */        
    for(i=0;str[i]!='\0';i++)
    {
/*küçük harf ise bundan 'a' nın ascıı degerini çıkardığı indisi artırır      */     
        if(str[i]>='a' && str[i]<='z')
            fr[str[i]-'a']++;
/*büyük harf ise bundan 'A' nın ascıı degerini çıkardığı indisi artırır      */                 
        else if(str[i]>='A' && str[i]<='Z')
            fr[str[i]-'A']++;
/*eğer rakam ise o rakamın ascıı değerinden '0' ın kini çıkardığı indisi artır*/   
/*  ve 26 ekleyerek indisi bul(ilk 26 eleman harf olduğu için)                */         
        else if(str[i]>='0' && str[i]<='9')
           fr[str[i] -'0' + 26]++;   
/*  bunların dısında bir karakter girilmiş ise 36.indisin değerini arttır     */                                 
        else 
            fr[36]++;
    }
}
/*--------------------------------------------------------------------------*/
/*                      End of hw6_part1.c                                        */
