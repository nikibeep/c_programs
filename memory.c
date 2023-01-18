#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   char job[100];
   char *skill=NULL;

   strcpy(job, "bug bounty");

   skill = malloc( 30 * sizeof(char) );
  
   if( skill == NULL ) {
      fprintf(stdout, "Error - cannot allocate memory\n");
   } else {
      strcpy( skill, "has command over bash");
   }
   skill = realloc( skill, 100 * sizeof(char) );
  
   if( skill == NULL ) {
      fprintf(stdout, "Error - cannot allocate required memory\n");
   } else {
      strcat( skill, "makes good reports and has really good name in the hacker1 community, has a good Knowledge in perl,ruby and has expertise in visual basics , usually designs own set of tools");
   }
   printf("job : %s\n", job );
   printf("skill: %s\n", skill );
   free(skill);
}