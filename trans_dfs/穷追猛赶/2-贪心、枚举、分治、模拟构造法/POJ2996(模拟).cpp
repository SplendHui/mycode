/*
Description
Your task is to read a picture of a chessboard position and print it in the chess notation.
Input
The input consists of an ASCII-art picture of a chessboard with chess pieces on positions described by the input. The pieces of the white player are shown in upper-case letters, while the black player's pieces are lower-case letters. The letters are one of "K" (King), "Q" (Queen), "R" (Rook), "B" (Bishop), "N" (Knight), or "P" (Pawn). The chessboard outline is made of plus ("+"), minus ("-"), and pipe ("|") characters. The black fields are filled with colons (":"), white fields with dots (".").
Output
The output consists of two lines. The first line consists of the string "White: ", followed by the description of positions of the pieces of the white player. The second line consists of the string "Black: ", followed by the description of positions of the pieces of the black player. 

The description of the position of the pieces is a comma-separated list of terms describing the pieces of the appropriate player. The description of a piece consists of a single upper-case letter that denotes the type of the piece (except for pawns, for that this identifier is omitted). This letter is immediatelly followed by the position of the piece in the standard chess notation -- a lower-case letter between "a" and "h" that determines the column ("a" is the leftmost column in the input) and a single digit between 1 and 8 that determines the row (8 is the first row in the input). 

The pieces in the description must appear in the following order: King("K"), Queens ("Q"), Rooks ("R"), Bishops ("B"), Knights ("N"), and pawns. Note that the numbers of pieces may differ from the initial position because of capturing the pieces and the promotions of pawns. In case two pieces of the same type appear in the input, the piece with the smaller row number must be described before the other one if the pieces are white, and the one with the larger row number must be described first if the pieces are black. If two pieces of the same type appear in the same row, the one with the smaller column letter must appear first.
Sample Input
+---+---+---+---+---+---+---+---+
|.r.|:::|.b.|:q:|.k.|:::|.n.|:r:|
+---+---+---+---+---+---+---+---+
|:p:|.p.|:p:|.p.|:p:|.p.|:::|.p.|
+---+---+---+---+---+---+---+---+
|...|:::|.n.|:::|...|:::|...|:p:|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|.P.|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:P:|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|.P.|:::|.P.|:P:|...|:P:|.P.|:P:|
+---+---+---+---+---+---+---+---+
|:R:|.N.|:B:|.Q.|:K:|.B.|:::|.R.|
+---+---+---+---+---+---+---+---+
Sample Output
White: Ke1,Qd1,Ra1,Rh1,Bc1,Bf1,Nb1,a2,c2,d2,f2,g2,h2,a3,e4
Black: Ke8,Qd8,Ra8,Rh8,Bc8,Ng8,Nc6,a7,b7,c7,d7,e7,f7,h7,h6
 
题意：给出 棋盘 情况 输出 白棋 和 黑棋在 棋盘上的坐标
            白棋为大写字母 黑棋为小写字母
棋盘 左下点为原点(1,a)
输出 是 按照KQRBNP的顺序
白棋 输出 行小的 行相同按列小的 先输出
黑棋 行大的先输出
思路： 模拟就行，没什么算法好说、、
s开小了 贡献一个WA、、、
*/
#include <iostream>  
#include <algorithm>  
using namespace std;  
struct Pieces  
{  
    int x,y,p;  
    char b;  
}w[65],b[65];  
int power(char p)  
{  
    if(p=='K' || p=='k') return 1;  
    if(p=='Q' || p=='q') return 2;  
    if(p=='R' || p=='r') return 3;  
    if(p=='B' || p=='b') return 4;  
    if(p=='N' || p=='n') return 5;  
    if(p=='P' || p=='p') return 6;  
}  
bool cmp_w(Pieces a, Pieces b)  
{  
    if(a.p!=b.p) return a.p<b.p;  
    if(a.x!=b.x) return a.x<b.x;  
    return a.y<b.y;  
}  
bool cmp_b(Pieces a, Pieces b)  
{  
    if(a.p!=b.p) return a.p<b.p;  
    if(a.x!=b.x) return a.x>b.x;  
    return a.y<b.y;  
}  
int main()  
{  
    int i,j;  
    int sum_b=0,sum_w=0;  
    char a,d,c,s[100];  
    for(i=8; i>=1; i--)  
    {  
        gets(s);  
        for(j=0; j<8; j++)  
        {  
            getchar();   
            scanf("%c%c%c", &a, &d, &c);  
            if(d=='.' || d==':') continue;  
            if(d>='a' && d<='z')   
            {  
                b[sum_b].x = i;  
                b[sum_b].y = j;  
                b[sum_b].b = d-32;  
                b[sum_b++].p = power(d);  
            }  
            else  
            {  
                w[sum_w].x = i;  
                w[sum_w].y = j;  
                w[sum_w].b = d;  
                w[sum_w++].p = power(d);  
            }  
        }  
        getchar();getchar();  
    }  
    sort(b, b+sum_b, cmp_b);  
    sort(w, w+sum_w, cmp_w);  
    gets(s);  
    printf("White: ");  
    for(i=0; i<sum_w; i++)  
    {  
        if(w[i].b!='P') printf("%c", w[i].b);  
        printf("%c%d%c",w[i].y+'a', w[i].x, (i==sum_w-1)?'\n':',');  
    }  
    printf("Black: ");  
    for(i=0; i<sum_b; i++)  
    {  
        if(b[i].b!='P') printf("%c",b[i].b);  
        printf("%c%d%c",b[i].y+'a', b[i].x, (i==sum_b-1)?'\n':',');  
    }  
    return 0;  
} 