#include <stdio.h>
#include "constants.h" //Include required headers


void app_main(void)
{
    if (init_sd_card() == ESP_OK)
    {
        printf("SD card mounted successfully!\n");
    }
    else
    {
        printf("Failed to mount SD card!\n");
    }
    

    // write to file

    FILE *f = fopen("/sdcard/test.txt", "w");

if (f == NULL)
{
    printf("Failed to create file\n");
}
else
{
    fprintf(f, "Hello Phil!\n");
    fclose(f);

    printf("File written successfully\n");
}

// read the file back

char line[64];

f = fopen("/sdcard/test.txt", "r");

if (f == NULL)
{
    printf("Failed to open file\n");
}
else
{
    fgets(line, sizeof(line), f);

    printf("Read from file: %s", line);

    fclose(f);
}
}
