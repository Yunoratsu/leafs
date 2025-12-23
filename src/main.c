/************************************************
 * JUST A SIMPLE TREE TOOL: VERSION - 0.1       *
 * **********************************************
 * Newbie: Yunoratsu - Date: 12/04/2025           *
************************************************/

#include "headers.h"

/* As sugested by its name, it simply traverse directories */

/*
void traverseDir(const char *path, int depth) {
    DIR* dir;
    struct dirent *entry;
    struct stat path_stat;
    int i;

    dir = opendir(path);
    if (dir == NULL) {
        die("Unable to open dir");
    }

    while ((entry=readdir(dir)) != NULL) {
        //stat(entry->d_name, &path_stat);
        if (!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name)) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        for (i = 0; i < depth; i++) {
            printf("\t└──");
        }
        if (stat(full_path, &path_stat) == 0) {
            if (S_ISDIR(path_stat.st_mode)) {
                printf("[dir] %s\n", entry->d_name);
                traverseDir(full_path, depth+1);
            } else if (S_ISREG(path_stat.st_mode)) {
                printf("%s\n", entry->d_name);
            }
        }
    }
    closedir(dir);
} */

int main(int argc, char **argv) {

    if (argc != 2) {
        traverseDir(".", 0, true);
    } else {
        traverseDir(argv[1], 0, true);
    }

    return EXIT_SUCCESS;
}

