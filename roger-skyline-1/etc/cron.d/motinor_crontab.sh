#!/bin/bash
h1=$(cat /etc/cron.d/crontab.hash)
h2=$(md5sum /etc/crontab | cut -d' ' -f1)
if [ "$h1" != "$h2" ]
then
	echo "$h1" >> /etc/cron.d/crontab.hash;
	echo "/etc/crontab has been modified" | mail -s "crontab monitoring: crontab modified! 11" "root@localhost"
fi
