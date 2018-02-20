#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
int isInCheck(char* board);
int makeMove(char *board, char sc, int sr, char tc, int tr);
void initBoard(char *board);
void printBoard(char *board);
void getPosition(char *col,int *row);
int isValidCell(char col, int row);
int isPawnMovable
(char *board,char sc,int sr,char tc,int tr);
int isKnightMovable
(char *board, char sc, int sr, char tc, int tr);
int isRookMovable
(char *board , char sc, int sr, char tc, int tr);
int isKingMovable
(char *board , char sc, int sr, char tc, int tr);
int isBishopMovable
(char *board , char sc, int sr, char tc, int tr);
int isQueenMovable
(char *board , char sc, int sr, char tc, int tr);
void emptyBuffer();
char getPlayer(char *board,char sc,char sr);
int isBlack(char currPlayer);
int isWhite(char currPlayer);
int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc; /* source/target cols */
    int sr,tr; /* source/target rows */
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;

    initBoard(board);
    
    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);

        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }
        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}

int isInCheck(char* board)
{
    int i,j,colKing,rowKing,sc,sr;
    for(i=0;i<BOARD_SIZE*BOARD_SIZE;i++)
    {
        if(board[i]=='k' || board[i]=='K')
        {       
            rowKing=8-i/8 ;
            colKing=i%8+'a';                                                                
            for(j=0;j<BOARD_SIZE*BOARD_SIZE;j++)
            {
                sr=8-j/8 ;
                sc=j%8+'a';
                if(isPieceMovable(board,sc,sr,colKing,rowKing))
                {
                    if(board[i]=='k')
                    {   printf("%c sah cekti\n",getPlayer(board,sc,sr));
                        return 2;
                    }
                    else if(board[i]=='K')
                    {   printf("%c sah cekti\n",getPlayer(board,sc,sr));
                        return 1;
                    }    
                }
            }
        }
    }
    return 0;
}

int makeMove(char *board, char sc, int sr, char tc, int tr)
{
/*  bulundugumuz tasin indisi(iSour),hedefteki tasin indisi(iTar)           */
    int iSour,iTar;    
    char tempSour=' ',tempTar=' '; /* taslari yedeklemek icin degiskenler   */
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');
/* tas istenilen hedefe oynatilablir mi kontrolu                            */                                                 
    if(isPieceMovable(board,sc,sr,tc,tr))
    {
/*  hareketten sonra check durumu olur diye yedekleme islemi                */    
        tempSour=board[iSour];
        tempTar=board[iTar];
/* tasi hareket ettirip tasin oldugu yeri bosaltma islemi                   */          
        board[iTar]=board[iSour];
        board[iSour]=' ';
/*tasin kingi risk altinda veya aynı tasin kinginin kendini riske sokma durumu*/        
        if( (isInCheck(board)==1 && (isWhite(tempSour) || tempSour=='k')) || 
            (isInCheck(board)==2 && (isBlack(tempSour) || tempSour=='K')) )
        {    
/* bu durumda hamle(geceersiz) geri alinir ve 1 degeri return edilir        */        
            board[iSour]=tempSour;
            board[iTar]=tempTar;
            return 1;
        } 
/* oyuncunun diger oyuncuya sah cekme durumu 3 return edilir                */       
        else if( (isWhite(tempSour) && isInCheck(board)==2) || 
            (isBlack(tempSour) && isInCheck(board)==1)   )
            return 3;
/* hamle gecerli ve risk altinda king yoktur,return 2                       */            
        else  
            return 2;
     }  
/* hamle zaten gecersizdir                                                  */                          
    return 0;
}

char getPlayer(char *board,char sc,char sr)
{
    int iSour;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    return board[iSour];
}

int isBlack(char currPlayer)
{
    if(currPlayer>='a' && currPlayer<='z')
        return 1;
    return 0;
}

int isWhite(char currPlayer)
{
    if(currPlayer>='A' && currPlayer<='Z')
        return 1;
    return 0;
}
/* satranç tahtasının içeriğinin oluşturulduğu fonksiyon                    */
void initBoard(char *board)
{
    int i;
/*  boarda atama yapmak için geçici char degiskeni                          */   
    char temp[64]="rnbqkbnr"
                  "pppppppp"
                  "        "   
                  "        "
                  "        "
                  "        "    
                  "PPPPPPPP"
                  "RNBQKBNR" ;
/*  board un içeriğinin doldurulması (strcopy)                              */    
    for(i=0;i<64;i++)
        board[i]=temp[i];
}
/* satranç tahtasını ekrana yazdıran fonksiyon                              */
void printBoard(char *board)
{
/*  döngü degiskeni(i) ve satır numaraları için degisken(j) 8 7 6 5 ...     */
    int i,j=8;
/*  üst kısım sütun harflerini yazdırmak için degisken a b c d ...          */    
    char letter='a';
/*  board ın print edilme işlemleri                                         */    
    printf("  ");
    for(i=1;i<=8;i++)
        printf("%c ",letter++);
    printf("\n  ");
    for(i=1;i<=8;i++)
        printf("- ");
    printf("\n");
    for(i=1;i<=64;i++)
     {  
         if( (i-1) % 8 == 0)
            printf("%d|",j--);
         if(i%8==0)
         {   
            printf("%c",board[i-1]);
            printf("|\n");
         }
         else
            printf("%c ",board[i-1]);
     }
     printf("  ");
     for(i=1;i<=8;i++)
        printf("- ");
     printf("\n");   
}
/* hamlenin geçerli olmasını kontrol eden fonksiyon                         */
int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{
/*   indexSource=bulunulan indis                                            */     
    int indexSource=(8-sr)*8 + ((int)sc - 'a');
/*girilen inputlardan herhangi birinin tahatanın dışında olma durumu return0*/    
    if( !isValidCell(sc,sr) || !isValidCell(tc,tr))    
        return 0;
/*  bulunulan konumu dizide indisini hesaplama                              */        
    indexSource=(8-sr)*8 + ((int)sc - 'a');
/*  taşın türüne göre taşın fonksiyonunu return etme işlemi                 */     
    if(board[indexSource]=='p' || board[indexSource]=='P')
        return isPawnMovable(board,sc,sr,tc,tr);
    else if(board[indexSource]=='n' || board[indexSource]=='N')
        return isKnightMovable(board,sc,sr,tc,tr);
    else if(board[indexSource]=='r' || board[indexSource]=='R')
        return isRookMovable(board,sc,sr,tc,tr);
    else if(board[indexSource]=='k' || board[indexSource]=='K')
        return isKingMovable(board,sc,sr,tc,tr);
    else if(board[indexSource]=='b' || board[indexSource]=='B')
        return isBishopMovable(board,sc,sr,tc,tr);
    else if(board[indexSource]=='q' || board[indexSource]=='Q') 
        return isQueenMovable(board,sc,sr,tc,tr);  
    
    return 0;
}
/* girilen hücrenin tahta içerisinde olup olmadığını kontrol eden fonksiyon */
int isValidCell(char col, int row)
{
    if( (col>='a' && col<='h') && (row>=1 && row<=8) )
        return 1;
    else
        return 0;
}
/*  sütun ve satır inputlarını alan fonksiyon                               */
void getPosition(char *col,int *row)
{
    scanf("%c %d",col,row);
}
/* piyon hareketini kontrol eden fonksion                                   */
int isPawnMovable
(char *board,char sc,int sr,char tc,int tr)
{
/*  bulunulan konumun indisi(iSour),hedefin indisi(iTar)                    */
    int iSour,iTar;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');    
/*  üst kısımdaki oyuncunun piyonuysa  'p'                                  */    
    if(board[iSour]=='p' && abs(sc-tc)<=1)
    {    
/* (hedefin boş olma ve ileri yapma durumu) veya (hedefte rakip             */
 /*           varsa ve çaprazındaysa)                                       */    
        if((board[iTar]==' ' && (iTar==iSour+8)) || ((board[iTar]>='A' && 
            board[iTar]<='Z')&&(iTar==iSour+9 || iTar==iSour+7)))
            return 1;
    }
/*  alt kısımdaki oyuncunun piyonuysa,aynı işlemler kontrol edilsin         */    
    else if(board[iSour]=='P' && abs(sc-tc)<=1)
    {
        if((board[iTar]==' ' && (iTar==iSour-8)) || ((board[iTar]>='a' && 
            board[iTar]<='z')&&(iTar==iSour-9 || iTar==iSour-7)))
            return 1;
    }
       
    return 0;
}   
/* at hareketini kontrol eden fonksion                                      */
int isKnightMovable
(char *board, char sc, int sr, char tc, int tr)
{
    int iSour,iTar;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');
    if(board[iSour]=='n' && abs(sc-tc)<=2)
    {
        if((board[iTar]==' ' || (board[iTar]>='A' && board[iTar]<='Z')) &&
        (iTar==iSour+10 || iTar==iSour+6 || iTar==iSour+15 || iTar==iSour+17 ||
         iTar==iSour-10 || iTar==iSour-6 || iTar==iSour-15 || iTar==iSour-17 ) )
            return 1; 
    }
    else if(board[iSour]=='N'  && abs(sc-tc)<=2)
    {
        if((board[iTar]==' ' || (board[iTar]>='a' && board[iTar]<='z')) &&
        (iTar==iSour+10 || iTar==iSour+6 || iTar==iSour+15 || iTar==iSour+17 ||
         iTar==iSour-10 || iTar==iSour-6 || iTar==iSour-15 || iTar==iSour-17 ) )
            return 1;
    }
    return 0;
}
/* kale hareketini kontrol eden fonksion                                   */
int isRookMovable
(char *board , char sc, int sr, char tc, int tr)
{
    int iSour,iTar,i;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                        */    
    if(board[iSour]=='r')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else if(board[iSour]=='R')
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/* kale dikey veya yatay gitmeli bu yüzden satır veya sütun eşit olmalı    */
/* dikey için + - 8 yapılır,yatay ilerlemek için ise + -1                  */    
    if(sc==tc)
    {
        if(iTar>iSour)
        {
            for(i=iSour+8;i<iTar;i+=8)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-8;i>iTar;i-=8)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
    }
    else if(sr==tr)
    {
        if(iTar>iSour)
        {
            for(i=iSour+1;i<iTar;i++)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-1;i>iTar;i--)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
    }
    else
        return 0;
    return 1;
}
/* şah hareketini kontrol eden fonksion                                   */
int isKingMovable
(char *board , char sc, int sr, char tc, int tr)
{
    int iSour,iTar;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                       */        
    if(board[iSour]=='k')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;             
    }
    else if(board[iSour]=='K')
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;  
    }        
/* her yöne sadece 1 birim gidebilir                                      */    
    if((iTar==iSour+8 || iTar==iSour+7 || iTar==iSour+9 || iTar==iSour-8 ||
       iTar==iSour-7 || iTar==iSour-9 || iTar==iSour+1 || iTar==iSour-1) &&
       abs(sr-tr)<=1 && abs(sc-tc)<=1  )
        return 1;
    return 0;
}
/* fil hareketini kontrol eden fonksion                                   */
int isBishopMovable
(char *board , char sc, int sr, char tc, int tr)
{
/*  bulunulan konumun indisi(iSour),hedefin indisi(iTar)                    */
    int iSour,iTar,i=0;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                       */            
    if(board[iSour]=='b')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else if(board[iSour]=='B')
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/* filin  çaprazındaki hücreler indis olarak hedef - kaynak ın            */
/*7 veya 9 un katı olmalıdır,yani her satır 8 olduğu için 7 veya 9 gitmeli*/
    if((iTar-iSour)%7==0 && sr!=tr && sc!=tc)
    {
        if(iTar>iSour)
        {
            for(i=iSour+7;i<iTar && i%8!=0;i+=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            if(tc<sc)
            {
                for(i=iSour-9;i>iTar && i%8!=0;i-=9)
                {   
                    if(board[i]!=' ')
                        return 0;
                }
            }
            else
            {
                for(i=iSour-7;i>iTar && i%8!=7;i-=7)
                {   
                    if(board[i]!=' ')
                        return 0;
                }  
             }               
        }
        if(board[i]!=board[iTar])
                return 0;
    }       
    else if((iTar-iSour)%9==0 && sr!=tr && sc!=tc)
    {   
        if(iTar>iSour)
        {   
            if(iSour%8==7)
                return 0;
            for(i=iSour+9;i<iTar && i%8!=7;i+=9)
            {   
                if(board[i]!=' ') 
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            if(iSour%8==0)
                return 0; 
            for(i=iSour-9;i>iTar && i%8!=0;i-=9)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }    
        if(board[i]!=board[iTar])
                return 0;
    }
    else
        return 0;
    return 1;
}
/* vezir hareketini kontrol eden fonksion                                   */
int isQueenMovable
(char *board , char sc, int sr, char tc, int tr)
{
    int iSour,iTar;
    iSour=(8-sr)*8 + ((int)sc - 'a');
    iTar=(8-tr)*8 + ((int)tc - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                         */                
    if(board[iSour]=='q')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else if(board[iSour]=='Q')
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/*   yatay veya dikey gidebilme durumu (kaledeki gibi)                     */    
    if(isRookMovable(board,sc,sr,tc,tr))
        return 1;
/*  çapraz gidebilme durumu(fildeki gibi)                                  */
    else if(isBishopMovable(board,sc,sr,tc,tr))
        return 1;
/* ikisi de gerçekleşmezse zaten hamle geçersizdir                         */        
    return 0;
}
