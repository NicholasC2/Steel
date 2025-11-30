#pragma once
#include <nds.h>
#include <fat.h>
#include <stdio.h>
#include <string.h>
#include <defs.h>

#include "ini.h"

typedef struct {
    char* theme;
} Config;

/*
 * Create default config file if missing.
 * Returns:
 *   0 = config exists
 *   1 = config created
 *  -1 = FAT error or failure
 */
static inline int initConfig(const char* path) {
    if (!fatInitDefault()) return -1;

    FILE* f = fopen(path, "rb");
    if (f) {
        fclose(f);
        return 0;
    }

    // Create new config
    f = fopen(path, "w");
    if (!f) return -1;

    fprintf(f, DEFAULT_CONFIG);
    fclose(f);
    return 1;
}

static int config_handler(void* user, const char* section, const char* name, const char* value)
{
    Config* cfg = (Config*)user;

    if (strcmp(section, "general") == 0) {
        if (strcmp(name, "theme") == 0) {
            strncpy(cfg->theme, value, sizeof(cfg->theme));
        }
    }

    return 0;
}

/*
 * Parse config INI file.
 * Returns:
 *   0 = success
 *  <0 = parse error
 */
static inline int loadConfig(const char* path, Config* cfg)
{
    int result = ini_parse(path, config_handler, cfg);

    return result;
}
