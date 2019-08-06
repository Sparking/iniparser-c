#include <stdio.h>
#include <stdlib.h>
#include "ini.h"

int main(void)
{
    const char *value;
    INI_CONFIG *config;

    config = ini_config_create("test.ini");
    if (config == NULL) {
        fprintf(stderr, "ini config is not created\n");
        return -1;
    }

    ini_config_set(config, "2", "3", "liujiaying hahaha");
    value = ini_config_get(config, "2", "3", "no name");
    if (value) {
        printf("[1:name] = %s\n", value);
    } else {
        printf("invalid operatiobn\n");
    }

    ini_config_saveas(config, "test1.ini");
    ini_config_release(config);

    return 0;
}