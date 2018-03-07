#########################################################################
# File Name: exp.sh
# Author: splend
# mail: 752406912@qq.com
# Created Time: Wed 07 Mar 2018 16:09:10 CST
#########################################################################
#!/bin/bash


for((i=1;i <= 4;i++))
do
    expect -c "
        spawn ssh node${i}@node${i}
        expect {
            \"yes/no\" {send \"yes\r\";exp_continue}
            \"password\" {send \"admin123\r\"}
        }
        expect \"$\" { send \"cd /mirror && touch node${i}.c \r\" }
        expect \"$\" { send \"exit\r\" }
        expect eof
    "
done
exit 1
