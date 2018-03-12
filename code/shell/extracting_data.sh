#!/bin/bash

mpis="intel mpich"
maths="atlas mkl open goto"
base_path="/home/node1/hpl-2.2/bin"
for mpi in $mpis
do
    for math in $maths
    do
        outfile="${mpi}_${math}.txt"
        cd "${base_path}/ubuntu_${math}_${mpi}"
        for((i=10000;i <= 30000; i += 1000))
        do
            #deal data > $outfile
            echo $PWD
            filename="rs${i}.txt"
            grep "WR" rs${i}.txt | head -n 1 | awk '{print $2,$NF}' >> "../$outfile"
        done
        #
    done
done
exit 1

