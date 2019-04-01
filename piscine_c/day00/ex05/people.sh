ldapsearch -x -LL "(uid=z*)" cn | grep '^cn:' | sed 's/^....//' | sort -r -f
