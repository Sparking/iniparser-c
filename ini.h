#pragma once

#include "list.h"

struct ini_tag {
    char *key;
    char *value;
    struct list_head tag_node;
};

struct ini_section {
    char *section;
    struct list_head section_node;
    struct list_head tag_node;
};

struct ini_config {
    struct list_head section_node;
    char *config_file;
};
typedef struct ini_config INI_CONFIG;

extern INI_CONFIG *ini_config_create(const char *const file);
extern const char *ini_config_get(INI_CONFIG *config, const char *section,
    const char *key, const char *default_value);
extern int ini_config_set(INI_CONFIG *config, const char *section,
    const char *key, const char *value);
extern int ini_config_save2filestream(INI_CONFIG *config, FILE *fp);
extern int ini_config_saveas(INI_CONFIG *config, const char *file);
static inline int ini_config_save(INI_CONFIG *config) {
    return ini_config_saveas(config, config->config_file);
}
extern void ini_config_release(INI_CONFIG *config);

extern struct ini_section *ini_config_add_section(INI_CONFIG *config,
    const char *name);
extern struct ini_tag *ini_config_add_tag(struct ini_section *section,
    const char *key, const char *value);

extern void ini_show(INI_CONFIG *config);
