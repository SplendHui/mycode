#!bin/bash

getNumber(){

    if [ "$1" == "1" ]
    then
        return 0
    else
        return 1
    fi
}

    if getNumber "2" && [ "1" == "1" ]
    then
        echo "0 is true"
    fi

    path=$(pwd)
    echo "$path"
    cd ..
    path=$(pwd)
    echo "$path"

exit 0
