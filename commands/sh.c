/****************************************
 * DOS Coreutils sh Command Source File *
 ****************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char *command_line;
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(SH_DOS_COREUTILS_SHELL);
      puts("  sh");
      puts("  sh --help|--version\r\n");
      puts(NOTE);
      puts(IN_DOS_COREUTILS_SHELL_GIVE_COMMAND_EXIT_TO_EXIT_SHELL);
      return 0;
   }
#endif

#ifdef VERSION
   else if(!strcmp(argv[1], "--version"))
   {
      version();
      return 0;
   }
#endif

   command_line = (char *) malloc(MAX_COMMAND_LINE_LENGTH);

   loop:

   printf("\r\n#");
   fgets(command_line, MAX_COMMAND_LINE_LENGTH, stdin);

   if(!strcmp(command_line, "exit\n"))
   {
      exit(0);
   }
   else if(strcmp(command_line, "\n"))
   {
      system(command_line);
   }

   goto loop;

   return 0;
}
