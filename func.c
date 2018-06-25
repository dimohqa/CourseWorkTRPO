#include <stdio.h>
#include "void_print.h"
	//7 easy 5 hard
	void print_hang (int err, int step) //виселица
	{		
		if (err == 7) {
			switch (step)
			{
				case 7: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ / \\  (A)  "); break;
				case 6: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ /    (A)  "); break;
				case 5: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_      (A)  "); break;
				case 4: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|   (A)\n_||_      (A)  "); break;
				case 3: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||   |   (A)\n_||_      (A)  "); break;
				case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||       (A)\n_||_      (A)  "); break;
				case 1: printf("  ____    (A)\n ||/      (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;
				//case 1: printf("          (A)\n ||       (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;
				//case 1: printf("         (A)\n          (A)\n         (A)\n         (A)\n___      (A)  "); break;
				//case 0: printf("         (A)\n         (A)\n         (A)\n         (A)\n         (A)  "); break;
     
			}
        }
        if (err == 5) {
			switch (step)
			{
				case 5: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ / \\  (A)  "); break;
				case 4: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_ /    (A)  "); break;
				case 3: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|\\  (A)\n_||_      (A)  "); break;
				case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||  /|   (A)\n_||_      (A)  "); break;
				case 1: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||   |   (A)\n_||_      (A)  "); break;
				//case 2: printf("  ____    (A)\n ||/  |   (A)\n ||   o   (A)\n ||       (A)\n_||_      (A)  "); break;
				//case 1: printf("  ____    (A)\n ||/      (A)\n ||       (A)\n ||       (A)\n_||_      (A)  "); break;      
            }
		}
}
