#!/bin/sh
echo
echo "Zlodeeva Darya Sergeevna"
echo "Manager packetov yum"
echo "Rabota s repolist"
echo
while :
do
    yum repolist all
    echo
    echo "Enter repository:"
    read repo
	
	yum repoinfo $repo
	echo "1 - off 2 - on"
	read stroka
        if test $stroka = "1"; then
            yum-config-manager --disable $repo
      	    yum clean all
	    yum makecache
        elif test $stroka = "2"; then
	    yum-config-manager --enable $repo
	    yum clean all
	    yum makecache
	else
	   echo "Error"
        fi
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
