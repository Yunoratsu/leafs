/************************************************
 * JUST A SIMPLE TREE TOOL: VERSION - 0.1       *
 * **********************************************
 * Newbie: Yunoratsu - Date: 12/04/2025           *
************************************************/

#include "headers.h"

int main(int argc, char **argv) {

    if (argc != 2) {
        traverseDir(".", 0, true);
    } else {
        traverseDir(argv[1], 0, true);
    }

    return EXIT_SUCCESS;
}

