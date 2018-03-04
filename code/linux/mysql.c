#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
int main()
{

    MYSQL my_connection;
    MYSQL_RES *mysql_result;
    MYSQL_ROW mysql_row;
    int res = 0;
    mysql_init(&my_connection);
    if (mysql_real_connect(&my_connection, "localhost", "splend", "splend", "myjdbc", 0, NULL, 0))
    {
        printf("Connection success\n");
        //res = mysql_query(&my_connection, "insert into customer values(2,'rick','rick')");
        res = mysql_query(&my_connection, "select * from customer");
        if (!res)
        {
            int row, col;
            int i, j;
            mysql_result = mysql_store_result(&my_connection);
            row = mysql_num_rows(mysql_result);
            col = mysql_num_fields(mysql_result);

            printf("----------------------------------------------\n");
            for (i = 0; i < row; i++)
            {
                mysql_row = mysql_fetch_row(mysql_result);
                for (j = 0; j < col; j++)
                    printf("|%-10s", mysql_row[j]);
                printf("\n");
            }
            printf("----------------------------------------------\n");
            //printf("Insert %lu rows\n", (unsigned long)mysql_affected_rows(&my_connection));
        }
        else
        {
            fprintf(stderr, "insert error %d: %s \n", mysql_errno(&my_connection), mysql_error(&my_connection));
        }
    }
    else
    {
        printf("error \n");
    }

    return 0;
}