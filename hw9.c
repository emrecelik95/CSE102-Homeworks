/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW09_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw9.c                                                                    */
/* ---------                                                                */
/* Created on 29/04/2016 by Emre_Çelik                                      */
/*                                                                          */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                              Includes                                    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h> /* strcmp icin                                          */               
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*                        Function Prototypes                               */
/*--------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/
/*  ulke icin struct tanimlamasi                                            */
typedef struct{
    char name[25];
    int population;
    int area;
    int numOfSoldiers;
    char neighbours[10][25];
}country_t;
/* girilen ulkenin dizide kacinci indiste oldugunu bulma fonksiyonu         */
int findIndex(country_t *countries,char *current);
/* ulke ekleme fonksiyonu                                                   */
void addCountry(country_t *country);
/* en guclu ulke yazdirma fonksiyonu                                        */
void printMostPowerful(country_t *countries);
/* en genis ulkeyi yazdirma fonksiyonu                                      */
void printLargest(country_t *countries);
/* bir ulkeden digerine ulasimin mumkunlugunu kontrol eden fonksiyon        */
void isAccessible(country_t *countries);
/* baslangıc ulkesinin komsuluk baglarının hepsini bulup kiyas yapan fonksiyon*/
int sourceNeighs(country_t *countries,int c1Ind,int c2Ind,int *find);
/* gitmek istenen ulkenin tum kosuluklarina ulasan ve karsilastiran fonksiyon*/
int targetNeighs(country_t *countries,int c1Ind,int c2Ind,int *find);

int main(void)
{
    int i=0;
    char choice=' ';  
/* boyutu 100 olan struct dizi tanimlamasi                                  */                                                              
    country_t countries[100];                                                   
/* donguyu bitirme kosulu (klavyeden e alininca)                             */                                                               
    while(choice!='e')
    {   
/* inputa gore yapilacak islemleri iceren fonksiyonlari cagir               */    
        printf("Make Your Choice:\n");
        scanf(" %c",&choice);
        switch (choice)
        {
            case 'a':
                    addCountry(&countries[i]);/*her seferinde sonraki eleman*/
                    i++;
                    break;
            case 'b':
                    printMostPowerful(countries);
                    break;
            case 'c':
                    printLargest(countries); 
                    break; 
            case 'd':
                    isAccessible(countries);
                    break;             
            default:break;
        }
    }
    printf("Good Bye\n");
    return 0;
}
/* ulke ekleme fonksiyonu                                                   */
void addCountry(country_t *country)
{
   int i;
    printf("Enter the informations about country:\n");
/* ulke bilgilerini kullanicidan al                                         */    
    scanf("%s %d %d %d",country->name,&country->population,
                        &country->area,&country->numOfSoldiers);              
/* komsulari al eger -1 girerse orada kes \0                                */                          
    for(i=0;i>=0;i++)
    {
        scanf("%s",country->neighbours[i]);                                     
        if(country->neighbours[i][0]=='-' && country->neighbours[i][1]=='1')
        {   
            country->neighbours[i][0]='\0';
            i=-2;
        }    
    }                                                      

}
/* girilen ulkenin dizide kacinci indiste oldugunu bulma fonksiyonu         */
int findIndex(country_t *countries,char *current){
    int i=0;
    for(i=0;strcmp(countries[i].name,current)!=0 &&
                   countries[i].name[0]!='\0';i++);
    return i;               
}
/* en guclu ulke yazdirma fonksiyonu                                        */
void printMostPowerful(country_t *countries)
{
    int i,j,k,l,m,max=0,indexMax=0;
    char entry[25];
    scanf("%s",entry);
/* ulkeyi al indisine bak ve eger ulke girdisi yanlıs ise hata mesajı ver   */    
    i=findIndex(countries,entry);
    if(strcmp(countries[i].name,entry)!=0) 
        printf("Country is Invalid\n");
    else
    {
/* ilk deger max olsun                                                      */    
        max=countries[i].numOfSoldiers;
        indexMax=i;
/* komsularini bul ve max ile karsilastir                                   */        
        for(j=0;countries[i].neighbours[j][0]!='\0';j++)
        {                                                                       
            k=findIndex(countries,countries[i].neighbours[j]);                  
            if(countries[k].numOfSoldiers>max)   
            {
                max=countries[k].numOfSoldiers;
                indexMax=k;
            }     
/* komsularinin komsularinin bul ve max ile karsilastir                     */                 
            for(l=0;countries[k].neighbours[l][0]!='\0';l++)
            {                                                                   
                m=findIndex(countries,countries[k].neighbours[l]); 
                                                                                
                if(countries[m].numOfSoldiers>max)
                {
                    max=countries[m].numOfSoldiers; 
                    indexMax=m;
                }                                                                    
                
            }
        }                                                                       
    }                                                                           
    printf("Most Powerful Country:%s\n",countries[indexMax].name);                                                                             
}
/* en genis ulkeyi yazdirma fonksiyonu                                      */
void printLargest(country_t *countries)
{
    int i,j,k,l,m,max=0,indexMax=0;
    char entry[25];
    scanf("%s",entry);
/* ulkeyi al indisine bak ve eger ulke girdisi yanlıs ise hata mesajı ver   */        
    i=findIndex(countries,entry);
    if(countries[i].name[0]=='\0') 
        printf("Country is Invalid\n");
    else
    {
/* ilk deger max olsun                                                      */        
        max=countries[i].area;
        indexMax=i;
/* komsularini bul ve max ile karsilastir                                   */                
        for(j=0;countries[i].neighbours[j][0]!='\0';j++)
        {                                                                       
            k=findIndex(countries,countries[i].neighbours[j]);                   
            if(countries[k].area>max)   
            {
                max=countries[k].area;
                indexMax=k;
            }     
/* komsularinin komsularinin bul ve max ile karsilastir                     */                                  
            for(l=0;countries[k].neighbours[l][0]!='\0';l++)
            {                                                                   
                m=findIndex(countries,countries[k].neighbours[l]);               
                if(countries[m].area>max)
                {
                    max=countries[m].area; 
                    indexMax=m;
                }                                                                    
            
            }       
        }                                                                       
    }
    printf("Largest Country:%s\n",countries[indexMax].name);                                                                                
}
/* bir ulkeden digerine ulasimin mumkunlugunu kontrol eden fonksiyon        */
void isAccessible(country_t *countries)
{
    char source[25],target[25];
    int i1=0,i2=0,find=0;
    scanf("%s %s",source,target);
/* kaynak ve hedef okundu ve indisleri bulundu                              */    
    i1=findIndex(countries,source);
    i2=findIndex(countries,target);                                             
/* herhangi biri dizide yoksa                                               */                                                                               
    if(countries[i1].name[0]=='\0' || countries[i2].name[0]=='\0'){
        printf("INACCESSIBLE\n");
    } 
/* herhangi biri ada ise yani komsusu yok ise                               */    
    else if(countries[i1].neighbours[0][0]=='\0' || 
            countries[i2].neighbours[0][0]=='\0'){
        printf("INACCESSIBLE(source or target is an island country!)\n");
    }       
    else{                                                                     
/* ulkeleri ve find in adresini gonder,sonra find 1 ise accessible dir      */               
        sourceNeighs(countries,i1,i2,&find);
        if(find==1)
            printf("ACCESSIBLE\n");
        else
            printf("INACCESSIBLE\n");    
    }                                            
                                                                                
}
/* baslangıc ulkesinin komsuluk baglarının hepsini bulup kiyas yapan fonksiyon*/
int sourceNeighs(country_t *countries,int c1Ind,int c2Ind,int *find)
{
    int i=0,j=0; 
/* bir onceki cagirmada bulduysa bir daha arama yapmasin                    */      
    if(*find==1)
        return 0;
/* eldeki ulkenin komsulari icin ve her calismada onlarin komsulari icin bak*/        
    for(i=0;countries[c1Ind].neighbours[i][0]!='\0';i++)
    {                                                                           
       j=findIndex(countries,countries[c1Ind].neighbours[i]);
/* ulkenin dizide bulunmama durumu kontrolu                                 */       
       if(countries[j].name[0]!='\0'){
/* hedefin tum komsuluklarina bakmak icin asil islem o fonksiyonda gerceklesir*/       
           targetNeighs(countries,j,c2Ind,find);
        }    
/* ortak komsu bulunmadigi surece kendini cagir                             */                         
       if(*find==0)
           sourceNeighs(countries,j,c2Ind,find);   
    }
    return 0;
}
/* gitmek istenen ulkenin tum kosuluklarina ulasan ve karsilastiran fonksiyon*/
int targetNeighs(country_t *countries,int c1Ind,int c2Ind,int *find)
{
    int i=0,j=0;  
/* bir onceki cagirmada bulduysa bir daha arama yapmasin                    */            
    if(*find==1)
        return 0;
/* eldeki ulkenin komsulari icin ve her calismada onlarin komsulari icin bak*/                
    for(i=0;countries[c2Ind].neighbours[i][0]!='\0';i++)
    {                                                                           
        j=findIndex(countries,countries[c2Ind].neighbours[i]);
/* ulkenin dizide bulunmama durumu kontrolu                                 */               
        if(countries[j].name[0]!='\0'){
/* hedef ulkenin bakilan komsuluklarindan biri kaynak ulkenin komsuluklarindan
   herhangi birine esitse ortak yol vardir accessible dir(*find=1)          */        
            if(strcmp(countries[j].name,countries[c1Ind].name)==0)
            {
                printf("buldu %s\n",countries[j].name);
                *find = 1;
            }   
/* ortak komsu bulunmadigi surece kendini cagir                             */            
            if(*find==0)
                targetNeighs(countries,c1Ind,j,find);                   
        }
    }
     
    return 0;
}
