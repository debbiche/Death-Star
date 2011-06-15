#################################################################################
## Description:
## Makefile for socket tests.
##
##Author: Michal Musialik,Eugene Groshev
##  Date: 2011-05-18
################################################################################
default:
	@echo "test_clinet"
	@echo "test_server"
	@echo "test_both"

test_client: test_tcpclient.c
	gcc test_tcpclient.c -o clienttest.a -lcunit && ./clienttest.a

test_server: test_tcpserver.c
	gcc test_tcpserver.c -o servertest.a -lcunit && ./servertest.a

test_both: test_both.c
	gcc test_both.c -o test_both.a -lcunit && ./test_both.a