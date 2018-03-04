#########################################################################
# File Name: while.sh
# Author: splend
# mail: 752406912@qq.com
# Created Time: 2017年12月10日 星期日 09时55分09秒
#########################################################################
#!/bin/bash

i=1
    while false 
    do

        if [ $i -eq "9" ]
        then
            break
        fi
        if [ $(($i%3)) -eq "0" ]
        then
            i=$(expr $i + 1)
            continue
        fi
        echo "$i"
        i=$(expr $i + 1)

    done


    if [ -n "11" ]
    then
        echo "empty"
    fi
exit 0