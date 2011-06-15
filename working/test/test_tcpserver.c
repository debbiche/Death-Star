/*!
 *  @file test_tcpserver.c
 *
 *  @brief file to test server 
 *
 *  @author Michal Musialik,Eugene Groshev,Ali Issa
 *  @date 2011-05-18
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "../src/conn_tcpserver.c"
#include "../src/conn_ui_mask.c"


/*!
 @brief Test 1: creating a socket
 */
void test1_create(void) {
    CU_ASSERT(socket_create() == 0);	
}

/*!
 @brief Test 2: reusing a socket 
 */
void test2_reuse(void) {
  CU_ASSERT(socket_reusing() == 0);
}

/*!
 @brief Test 3: socket keep alive
 */
void test3_keepalive(void) {
  CU_ASSERT(socket_keep_alive() == 0);
}

/*!
 @brief Test 4: binding address to a socket
 */
void test4_bind(void) {
     CU_ASSERT(socket_binding() == 0);
}

/*!
    @brief Test 5: listening for incomming connection
*/
void test5_listen(void) {
    CU_ASSERT(socket_listening() == 0);	
}

/*!
    @brief Test 6: accepting a connection
*/
void test6_accept(void) {
  CU_ASSERT(socket_accept() == 0);
}


int main() {
    /**************************************************************************/
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    /**************************************************************************/
    /* add socket tests */

    CU_pSuite Bind = CU_add_suite("tcp_server.c: Create and connect to a socket", NULL, NULL);
    
    CU_add_test(Bind, "Creating a socket", test1_create);    
    CU_add_test(Bind, "Reusing a socket", test2_reuse);
    //CU_add_test(Bind, "", test3_keepalive);
    CU_add_test(Bind, "Binding address to a socket", test4_bind);
    CU_add_test(Bind, "Listening for connection", test5_listen); 
    CU_add_test(Bind, "Accepting a connection", test6_accept);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
