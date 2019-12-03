#!/bin/sh
echo $(date '+%d/%d/%Y %H:%M:%S') >> /var/log/update_script.log
sudo apt-get update -y >> /var/log/update_script.log
sudo apt-get upgrade -y >> /var/log/update_script.log
printf "\n\n\n" >> /var/log/update_script.log
