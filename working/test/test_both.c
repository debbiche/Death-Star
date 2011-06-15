/*!
 *  @file test_both.c
 *
 *  @brief file to test server and client at the same time
 *
 *  @author Michal Musialik,Eugene Groshev
 *  @date 2011-05-18
 */
#include <stdlib.h>

int main(void) {
  int pid = fork();
  if (pid == 0) {
    system("./clienttest.a");
  }
  else {
    system("./servertest.a");
    sleep(3);
  }
}
