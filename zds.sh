#!/bin/sh
echo
echo "Zlodeeva Daria Sergeevna"
echo "Nazvanie"
echo "Opisanie"
echo

while :
do
    repolist="yum repolist all"
    eval $repolist
    echo
    echo "Enter repository:"
    read repo
    FILE=/etc/yum.repos.d/${repo}.repo
    while read LINE; do
       stroka=$LINE
       name=$(echo $stroka | awk -F'=' '{print $1}')
        if test $name = "name"; then
	    namerepo=$(echo $stroka | awk -F' - ' '{print $2}')
        fi
        if test $stroka = "enabled=1"; then
            yum-config-manager --disable $namerepo
      	    yum clean all
	    yum makecache
        elif test $stroka = "enabled=0"; then
	    yum-config-manager --enable $namerepo
	    yum clean all
	    yum makecache
        fi
     done < $FILE
    while :
        do
        echo
        echo "Continue? (y/n)"
        read cont
        if test $cont = "y"; then
	    echo
	    break
        elif test $cont = "n"; then
	    echo "Closed"
	    exit
        else:
	    echo "Error"
        fi
    done
done
