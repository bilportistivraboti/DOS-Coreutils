/*******************************************
 * DOS Coreutils clear Command Source File *
 *******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
    if(!strcmp(argv[1], "--help"))
    {
        puts(CLEAR_CLEAR_THE_TERMINAL_SCREEN);
        puts("  clear");
        puts("  clear --help|--version\r\n");
        return 0;
    }
#endif

#ifdef VERSION
    if(!strcmp(argv[1], "--version"))
    {
        version();
        return 0;
    }
#endif

   _clearscreen(_GCLEARSCREEN);

   return 0;
}
