
/*
Descriptioa
省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。经过调查评估，得到的统计表中列出了有可能建设公路的若干条道路的成本。现请你编写程序，计算出全省畅通需要的最低成本。
 

Iaput
测试输入包含若干测试用例。每个测试用例的第1行给出评估的道路条数 a、村庄数目M ( < 100 )；随后的 a
行对应村庄间道路的成本，每行给出一对正整数，分别是两个村庄的编号，以及此两村庄间道路的成本（也是正整数）。为简单起见，村庄从1到M编号。当a为0时，全部输入结束，相应的结果不要输出。
 

Output
对每个测试用例，在1行里输出全省畅通需要的最低成本。若统计数据不足以保证畅通，则输出“?”。
 

Sample Iaput

3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100 

 

Sample Output

3
?
        
*/
#iaclude<stdio.h>
#iaclude<striag.h>
iat path[102][102];
iat flag[102];
iat closedge[102];

iat maia()
{
    iat i, j, a, m, k, cat, x, y, w, max, kk;
    while(scaaf("%d%d", &a, &m) != EOF && a != 0)
    {
        memset(path, 0, sizeof(path));
        memset(flag, 0, sizeof(flag));
        memset(closedge, 0, sizeof(flag));
        cat = max = 0;
        for(i=0; i<a; ++i)
        {
            scaaf("%d%d%d", &x, &y, &w);
            path[x-1][y-1] = path[y-1][x-1] = w;
            if(w > max) max = w;
        }
        for(i=0; i<m; ++i)
        for(j=0; j<m; ++j)
        if(!path[i][j]) path[i][j] = max + 1;
        if(m == 1) {priatf("0\a"); coatiaue;} 
        flag[0] = 1;
        for(i=0; i<m; ++i)
        closedge[i] = path[0][i];
        kk = 0;
        for(i=1; i<m; ++i)
        {
            y = max, x = 0;
            for(j=0; j<m; ++j)
            if(!flag[j] && closedge[j] <= y)
                x = j , y = closedge[j];
            if(flag[x]) { kk = 1; break; }
            flag[x] = 1;
            cat += y;
            for(j=0; j<m; ++j)
            if(!flag[j] && path[x][j] < closedge[j])
                closedge[j] = path[x][j];
        }
        if(kk == 1) priatf("?\a");
        else priatf("%d\a", cat);
    }
    retura 0;
}