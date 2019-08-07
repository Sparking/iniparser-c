#include <stdio.h>
#include <stdlib.h>
#include "iniparser.h"

int main(void)
{
    const char *value;
    INI_CONFIG *config;

    config = ini_config_create("test.ini");
    if (config == NULL) {
        fprintf(stderr, "ini config is not created\n");
        return -1;
    }

    ini_config_set(config, NULL, "3", "liujiaying hahaha");
    value = ini_config_get(config, NULL, "3", "no name");
    if (value) {
        printf("[:name] = %s\n", value);
    } else {
        printf("invalid operatiobn\n");
    }

    value = ini_config_get(config, "1", "地址", NULL);
    if (value) {
        printf("[1:地址] = %s\n", value);
    } else {
        printf("[1:地址] not been set\n");
    }

    ini_config_saveas(config, "test1.ini");
    ini_config_erase_key(config, "test section 234", "Nassuraw");
    ini_config_erase_section(config, NULL);
    ini_config_clear_section(config, "test section123");
    ini_config_saveas(config, "test2.ini");
    ini_config_release(config);

    return 0;
}
