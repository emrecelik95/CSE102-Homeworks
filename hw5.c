/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW05_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw5.c                                                                    */
/* ---------                                                                */
/* Created on 05/04/2016 by Emre_Çelik                                      */
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
/* satranç tahtasının içeriğinin oluşturulduğu fonksiyon                    */
void initBoard(char *board);
/* satranç tahtasını ekrana yazdıran fonksiyon                              */
void printBoard(char *board);
/* hamlenin geçerli olmasını kontrol eden fonksiyon                         */
int isPieceMovable(char *board);
/*  sütun ve satır inputlarını alan fonksiyon                               */
void getPosition(char *col,int *row);
/* girilen hücrenin tahta içerisinde olup olmadığını kontrol eden fonksiyon */
int isValidCell(char col, int row);
/* piyon hareketini kontrol eden fonksion                                   */
int isPawnMovable
(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
/* at hareketini kontrol eden fonksion                                   */
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
/* kale hareketini kontrol eden fonksion                                   */
int isRookMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* şah hareketini kontrol eden fonksion                                   */
int isKingMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* fil hareketini kontrol eden fonksion                                   */
int isBishopMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* vezir hareketini kontrol eden fonksion                                   */
int isQueenMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
void emptyBuffer()
{
	while ( getchar() != '\n' );
}
int main()
{
	char board [64];
	int initComplete = 0;
	char empty;
    
	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board); 
				initComplete = 1; 
				printf("OK\n");
				break;
			case 2: 
				/*Read space character after comma  nd number*/
				scanf("%c", &empty);
               
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{  
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3: 
				if (initComplete)
					printBoard(board);
				else  
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;

		}	
		
		scanf("%d", &command);
	
	}
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
int isPieceMovable(char *board)
{
/*   (sourceCol/Row)=bulunduğumuz konumun satır ve sütunu                   */ 
/*   (targetCol/Row)=hedefin satır ve sütunu , indexSource=bulunulan indis  */     
    char sourceCol,targetCol,empty;
    int sourceRow,targetRow,indexSource;
/*  bulunulan yerin ve hedefin koorninatlarını almak için 2 kere çağırılır  */    
    getPosition(&sourceCol,&sourceRow);
    scanf("%c",&empty);
    getPosition(&targetCol,&targetRow);   
/*girilen inputlardan herhangi birinin tahatanın dışında olma durumu return0*/    
    if( !isValidCell(sourceCol,sourceRow) || !isValidCell(targetCol,targetRow))    
        return 0;
/*  bulunulan konumu dizide indisini hesaplama                              */        
    indexSource=(8-sourceRow)*8 + ((int)sourceCol - 'a');
/*  taşın türüne göre taşın fonksiyonunu return etme işlemi                 */     
    if(board[indexSource]=='p' || board[indexSource]=='P')
        return isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='n' || board[indexSource]=='N')
        return isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='r' || board[indexSource]=='R')
        return isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='k' || board[indexSource]=='K')
        return isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='b' || board[indexSource]=='B')
        return isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='q' || board[indexSource]=='Q') 
        return isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow);  
    
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
(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
/*  bulunulan konumun indisi(iSour),hedefin indisi(iTar)                    */
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');    
/*  üst kısımdaki oyuncunun piyonuysa  'p'                                  */    
    if(board[iSour]=='p')
    {    
/* (hedefin boş olma ve sağ sol ve ileri yapma durumu) veya (hedefte rakip  */
 /*           varsa ve çaprazındaysa)                                       */    
        if((board[iTar]==' ' && (iTar==iSour+1 || iTar==iSour-1 || iTar==iSour+8
)) || 
     ((board[iTar]>='A' && board[iTar]<='Z')&&(iTar==iSour+9 || iTar==iSour+7)))
            return 1;
    }
/*  alt kısımdaki oyuncunun piyonuysa,aynı işlemler kontrol edilsin         */    
    else if(board[iSour]=='P')
    {
        if((board[iTar]==' ' && (iTar==iSour+1 || iTar==iSour-1 || iTar==iSour-8
)) || 
     ((board[iTar]>='a' && board[iTar]<='z')&&(iTar==iSour-9 || iTar==iSour-7)))
        return 1;
    }
       
    return 0;
}   
/* at hareketini kontrol eden fonksion                                      */
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
    if(board[iSour]=='n')
    {
        if((board[iTar]==' ' || (board[iTar]>='A' && board[iTar]<='Z')) &&
        (iTar==iSour+10 || iTar==iSour+6 || iTar==iSour+15 || iTar==iSour+17 ||
         iTar==iSour-10 || iTar==iSour-6 || iTar==iSour-15 || iTar==iSour-17 ) )
            return 1; 
    }
    else if(board[iSour]=='N')
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
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar,i;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
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
    if(sourceCol==targetCol)
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
    else if(sourceRow==targetRow)
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
    return 1;
}
/* şah hareketini kontrol eden fonksion                                   */
int isKingMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
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
    if(iTar==iSour+8 || iTar==iSour+7 || iTar==iSour+9 || iTar==iSour-8 ||
       iTar==iSour-7 || iTar==iSour-9 || iTar==iSour+1 || iTar==iSour-1  )
        return 1;
    return 0;
}
/* fil hareketini kontrol eden fonksion                                   */
int isBishopMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar,i;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
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
    if((iTar-iSour)%7==0)
    {
        if(iTar>iSour)
        {
            for(i=iSour+7;i<iTar;i+=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-7;i>iTar;i-=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }    
        }
    }       
    else if((iTar-iSour)%9==0)
    {
        if(iTar>iSour)
        {
            for(i=iSour+9;i<iTar;i+=9)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-9;i>iTar;i-=9)
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
/* vezir hareketini kontrol eden fonksion                                   */
int isQueenMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
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
    if(isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow))
        return 1;
/*  çapraz gidebilme durumu(fildeki gibi)                                  */
    else if(isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow))
        return 1;
/* ikisi de gerçekleşmezse zaten hamle geçersizdir                         */        
    return 0;
}

/*--------------------------------------------------------------------------*/
/*                                                                          */
/* HW05_141044024_Emre_Çelik                                                */
/*                                                                          */
/* hw5.c                                                                    */
/* ---------                                                                */
/* Created on 05/04/2016 by Emre_Çelik                                      */
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
/* satranç tahtasının içeriğinin oluşturulduğu fonksiyon                    */
void initBoard(char *board);
/* satranç tahtasını ekrana yazdıran fonksiyon                              */
void printBoard(char *board);
/* hamlenin geçerli olmasını kontrol eden fonksiyon                         */
int isPieceMovable(char *board);
/*  sütun ve satır inputlarını alan fonksiyon                               */
void getPosition(char *col,int *row);
/* girilen hücrenin tahta içerisinde olup olmadığını kontrol eden fonksiyon */
int isValidCell(char col, int row);
/* piyon hareketini kontrol eden fonksion                                   */
int isPawnMovable
(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow);
/* at hareketini kontrol eden fonksion                                   */
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow);
/* kale hareketini kontrol eden fonksion                                   */
int isRookMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* şah hareketini kontrol eden fonksion                                   */
int isKingMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* fil hareketini kontrol eden fonksion                                   */
int isBishopMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* vezir hareketini kontrol eden fonksion                                  */
int isQueenMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow);
/* input girilene kadar beklemeye yarayan fonksiyon                       */
void emptyBuffer()
{
	while ( getchar() != '\n' );
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
int isPieceMovable(char *board)
{
/*   (sourceCol/Row)=bulunduğumuz konumun satır ve sütunu                   */ 
/*   (targetCol/Row)=hedefin satır ve sütunu , indexSource=bulunulan indis  */     
    char sourceCol,targetCol,empty;
    int sourceRow,targetRow,indexSource;
/*  bulunulan yerin ve hedefin koorninatlarını almak için 2 kere çağırılır  */    
    getPosition(&sourceCol,&sourceRow);
    scanf("%c",&empty);
    getPosition(&targetCol,&targetRow);   
/*girilen inputlardan herhangi birinin tahtanın dışında olma durumu return0*/    
    if( !isValidCell(sourceCol,sourceRow) || !isValidCell(targetCol,targetRow))    
        return 0;
/*  bulunulan konumun dizideki indisini hesaplama                           */        
    indexSource=(8-sourceRow)*8 + ((int)sourceCol - 'a');
/*  taşın türüne göre taşın fonksiyonunu return etme işlemi                 */     
    if(board[indexSource]=='p' || board[indexSource]=='P')
        return isPawnMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='n' || board[indexSource]=='N')
        return isKnightMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='r' || board[indexSource]=='R')
        return isRookMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='k' || board[indexSource]=='K')
        return isKingMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='b' || board[indexSource]=='B')
        return isBishopMovable(board,sourceCol,sourceRow,targetCol,targetRow);
    else if(board[indexSource]=='q' || board[indexSource]=='Q') 
        return isQueenMovable(board,sourceCol,sourceRow,targetCol,targetRow);  
    
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
(char *board,char sourceCol,int sourceRow,char targetCol,int targetRow)
{
/*  bulunulan konumun indisi(iSour),hedefin indisi(iTar)                    */
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');    
/*  üst kısımdaki oyuncunun piyonuysa  'p'                                  */    
    if(board[iSour]=='p')
    {    
/* (hedefin boş olma ve sağ sol ve ileri yapma durumu) veya (hedefte rakip  */
 /*           varsa ve çaprazındaysa)                                       */    
        if((board[iTar]==' ' && (iTar==iSour+1 || iTar==iSour-1 || iTar==iSour+8
)) || 
     ((board[iTar]>='A' && board[iTar]<='Z')&&(iTar==iSour+9 || iTar==iSour+7)))
            return 1;
    }
/*  alt kısımdaki oyuncunun piyonuysa,aynı işlemler kontrol edilsin         */    
    else
    {
        if((board[iTar]==' ' && (iTar==iSour+1 || iTar==iSour-1 || iTar==iSour-8
)) || 
     ((board[iTar]>='a' && board[iTar]<='z')&&(iTar==iSour-9 || iTar==iSour-7)))
        return 1;
    }
       
    return 0;
}   
/* at hareketini kontrol eden fonksion                                      */
int isKnightMovable
(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
    if(board[iSour]=='n')
    {
/* hedefin boş olma veya hedefte rakip olma) && l şeklinde gittiği için     */
/*koordinat verme(8 +2 -2   veya 16 +1 -1  veya bunların negatifi(ters yön))*/
        if((board[iTar]==' ' || (board[iTar]>='A' && board[iTar]<='Z')) &&
        (iTar==iSour+10 || iTar==iSour+6 || iTar==iSour+15 || iTar==iSour+17 ||
         iTar==iSour-10 || iTar==iSour-6 || iTar==iSour-15 || iTar==iSour-17 ) )
            return 1; 
    }
    else
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
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar,i;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                        */    
    if(board[iSour]=='r')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/* kale dikey veya yatay gitmeli bu yüzden satır veya sütun eşit olmalı    */
/* dikey veya yatay ilerlemek için + - 8 yapılır                           */    
    if(sourceCol==targetCol)
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
    else if(sourceRow==targetRow)
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
    return 1;
}
/* şah hareketini kontrol eden fonksion                                   */
int isKingMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                       */        
    if(board[iSour]=='k')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/* her yöne sadece 1 birim gidebilir                                      */    
    if(iTar==iSour+8 || iTar==iSour+7 || iTar==iSour+9 || iTar==iSour-8 ||
       iTar==iSour-7 || iTar==iSour-9 || iTar==iSour+1 || iTar==iSour-1  )
        return 1;
    return 0;
}
/* fil hareketini kontrol eden fonksion                                   */
int isBishopMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar,i;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                       */            
    if(board[iSour]=='b')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/* filin  çaprazındaki hücreler indis olarak hedef - kaynak ın            */
/*7 veya 9 un katı olmalıdır,yani her satır 8 olduğu için 7 veya 9 gitmeli*/
    if((iTar-iSour)%7==0)
    {
        if(iTar>iSour)
        {
            for(i=iSour+7;i<iTar;i+=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-7;i>iTar;i-=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }    
        }
    }       
    else if((iTar-iSour)%9==0)
    {
        if(iTar>iSour)
        {
            for(i=iSour+9;i<iTar;i+=9)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-9;i>iTar;i-=9)
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
/* vezir hareketini kontrol eden fonksion                                   */
int isQueenMovable
(char *board , char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int iSour,iTar,i;
    iSour=(8-sourceRow)*8 + ((int)sourceCol - 'a');
    iTar=(8-targetRow)*8 + ((int)targetCol - 'a');
/*  hedef hücre boş olmalı veya rakip oyuncu olmalı                       */                
    if(board[iSour]=='q')
    {
        if(board[iTar]!=' ' && board[iTar]>='a' && board[iTar]<='z')
            return 0;
    }
    else
    {
        if(board[iTar]!=' ' && board[iTar]>='A' && board[iTar]<='Z')
            return 0;
    }
/*   yatay veya dikey gidebilme durumu (kaledeki gibi)                   */    
    if(sourceCol==targetCol)
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
    else if(sourceRow==targetRow)
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
/*  çapraz gidebilme durumu(fildeki gibi)                               */    
    else if((iTar-iSour)%7==0)
    {
        if(iTar>iSour)
        {
            for(i=iSour+7;i<iTar;i+=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-7;i>iTar;i-=7)
            {   
                if(board[i]!=' ')
                    return 0;
            }    
        }
    }       
    else if((iTar-iSour)%9==0)
    {
        if(iTar>iSour)
        {
            for(i=iSour+9;i<iTar;i+=9)
            {   
                if(board[i]!=' ')
                    return 0;
            }
        }
        else if(iTar<iSour)
        {
            for(i=iSour-9;i>iTar;i-=9)
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
