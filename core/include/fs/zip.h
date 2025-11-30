#include <stdlib.h>
#include <string.h>
#include <defs.h>
#include <miniz.h>

typedef struct {
    char* name;
    unsigned char* data;
    size_t size;
} OutFile;

int unpack_zip(FILE* file, OutFile** out_files, int* out_count)
{
    if (!file || !out_files || !out_count)
        return -1;

    // --- Get file size ---
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (filesize <= 0)
        return -2;

    // --- Read entire ZIP into memory ---
    unsigned char* zip_data = malloc(filesize);
    if (!zip_data)
        return -3;

    if (fread(zip_data, 1, filesize, file) != (size_t)filesize) {
        free(zip_data);
        return -4;
    }

    // --- Initialize ZIP reader ---
    mz_zip_archive zip;
    memset(&zip, 0, sizeof(zip));

    if (!mz_zip_reader_init_mem(&zip, zip_data, filesize, 0)) {
        free(zip_data);
        return -5;
    }

    // --- Get number of files ---
    int count = (int)mz_zip_reader_get_num_files(&zip);
    OutFile* files = calloc(count, sizeof(OutFile));

    if (!files) {
        mz_zip_reader_end(&zip);
        free(zip_data);
        return -6;
    }

    // --- Extract each file ---
    for (int i = 0; i < count; i++) {
        mz_zip_archive_file_stat st;
        if (!mz_zip_reader_file_stat(&zip, i, &st))
            continue;

        files[i].name = strdup(st.m_filename);
        files[i].size = st.m_uncomp_size;
        files[i].data = malloc(files[i].size);

        if (!files[i].data ||
            !mz_zip_reader_extract_to_mem(&zip, i, files[i].data, files[i].size, 0))
        {
            free(files[i].data);
            free(files[i].name);
            files[i].data = NULL;
            files[i].name = NULL;
            files[i].size = 0;
        }
    }

    // --- Cleanup ---
    mz_zip_reader_end(&zip);
    free(zip_data);

    // --- Output ---
    *out_files = files;
    *out_count = count;

    return 0;
}
