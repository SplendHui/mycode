
/*
Descriptioa
ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ������������������õ���ͳ�Ʊ����г����п��ܽ��蹫·����������·�ĳɱ����������д���򣬼����ȫʡ��ͨ��Ҫ����ͳɱ���
 

Iaput
��������������ɲ���������ÿ�����������ĵ�1�и��������ĵ�·���� a����ׯ��ĿM ( < 100 )������ a
�ж�Ӧ��ׯ���·�ĳɱ���ÿ�и���һ�����������ֱ���������ׯ�ı�ţ��Լ�������ׯ���·�ĳɱ���Ҳ������������Ϊ���������ׯ��1��M��š���aΪ0ʱ��ȫ�������������Ӧ�Ľ����Ҫ�����
 

Output
��ÿ��������������1�������ȫʡ��ͨ��Ҫ����ͳɱ�����ͳ�����ݲ����Ա�֤��ͨ���������?����
 

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