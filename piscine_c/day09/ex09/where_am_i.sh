#!/bin/bash

MY_IPS=`ifconfig -a | grep 'inet ' | cut -d' ' -f2`
if [[ -n $MY_IPS ]]
then
	ifconfig -a | grep 'inet ' | cut -d' ' -f2
else
	echo "I am lost!\n"
fi