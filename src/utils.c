#include "headers.h"

void    die(const char *msg) {
    if (errno) {
        perror(msg);
    } else {
        fprintf(stderr, RED"[ERROR]: %s\n"RST, msg);
    }

    exit(EXIT_FAILURE);
}

void    printEntry(char *name, int depth, int isLast[], bool islastEntry) {
    for (int i = 0; i < depth; i++) {
        if (isLast[i]) {
            printf("   ");
        } else {
            printf("|   ");
        }
    }

    if (islastEntry) {
        printf("└── ");
    } else {
        printf("├── ");
    }

    printf("%s\n", name);
} 

void 	traverseDir(const char *path, int depth, bool firstTime) {
    DIR* dir;
    struct dirent *entry;
    struct stat path_stat;
    int i, is_last, count = 0;
    int *entries = malloc(sizeof(int) * MAX_SIZE);
    int *isLast = malloc(sizeof(int) * MAX_SIZE);

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

        for (i = 0; i < count; i++) {
            is_last = (i == count - 1);
            isLast[depth] = is_last;
        }

        printEntry(entry->d_name, depth, isLast, is_last);

        if (stat(full_path, &path_stat) == 0) {
            if (S_ISDIR(path_stat.st_mode)) {
                if (firstTime == true) 
                    count++;
                    
                    entries[depth]++;
                traverseDir(full_path, depth+1, firstTime);
            } else if (S_ISREG(path_stat.st_mode)) {
                if (firstTime == true)
                    count++;
                    
                    entries = realloc(entries, sizeof(entries) + sizeof(int) * count);
                    entries[depth]++;
            }
        }
    }
}

