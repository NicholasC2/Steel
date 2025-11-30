#include <json.h>
#include <defs.h>
#include <miniz.h>

int load_theme(FILE* file) {
    return 0;
}

int get_theme_info(char* text) {
    struct json_value_s *json = json_parse(text, strlen(text));
    if(json) {
        struct json_object_s* object = (struct json_object_s*)json->payload;
        printf(object->start->name->string);
        return 0;
    } else {
        return 1;
    }
}