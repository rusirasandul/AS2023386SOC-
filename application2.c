/* application2.c - functionality that can be merged into application.c */

#include <stdio.h>

/* Prints the module status when called from application.c. */
void application2_run(void)
{
	puts("Application 2 is running.");
}
