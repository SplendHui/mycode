#!/bin/bash
mpis="mpich intel"
maths="atlas mkl open goto"
base_path="/home/node1/hpl-2.2/bin"
for mpi in $mpis
do
    for math in $maths
    do
        #outfile="${mpi}_${math}.txt"
        if [ "$mpi" == "intel" -a "$math" == "mkl" ];then
            continue
        fi
        cd "${base_path}/ubuntu_${math}_${mpi}"
        #echo "${base_path}/ubuntu_${math}_${mpi}"
        for((j=1000;j <= 31000; j += 1000))
        do
            filename="rs${j}.txt"
            sed -i "s/^SIZE_VALUE/${j}/" HPL.dat
            if [ "$mpi" == "intel" ];then
                mpirun -n 4 ./xhpl >${filename}
            else
                /usr/local/mpich/bin/mpirun -n 4 ./xhpl >${filename}
            fi
            sed -i "s/^${j}/SIZE_VALUE/" HPL.dat
        done
    done
done
exit 1