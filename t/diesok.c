/* test 2: dies_ok and lives_ok macros  */

#include "../tap.h"

int main () {
    plan(5);
    
    ok(1, "sanity");
    dies_ok({int x = 0/0;}, "can't divide by zero");
    lives_ok({int x = 3/7;}, "this is a perfectly fine statement");
    dies_ok({abort();}, "abort kills the program");
    dies_ok(
        {printf("stdout\n"); fprintf(stderr, "stderr\n"); abort();},
        "supress output");

    return exit_status();
}
