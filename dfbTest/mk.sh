#########################################################################
# File Name: mk.sh
# Author: 徐进
# mail: xujinchn@163.com
# Created Time: Sat 25 Aug 2018 09:37:41 PM CST
#########################################################################
#!/bin/bash
gcc test.c -o tes -I /usr/local/include -I /usr/local/include/directfb \
	-I /usr/local/include/directfb-internal -L/usr/local/lib -ldirectfb -lpthread -ldl -lz 
