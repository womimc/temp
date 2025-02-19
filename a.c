#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
void send_packet(const char *url) {
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_perform(curl);
}

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-a") != 0) {
        fprintf(stderr, "Użycie: %s -a url\n", argv[0]);
        return 1;
    }
    char *url = argv[2];
    char *http_prefix = "http://";
    char *https_prefix = "https://";
    if (strstr(url, http_prefix)) {
        url = strstr(url, http_prefix) + strlen(http_prefix);
        char new_url[1024];
        snprintf(new_url, sizeof(new_url), "%s%s", https_prefix, url);
        url = new_url;
    }
    else if (!strstr(url, https_prefix)) {
        char new_url[1024];
        snprintf(new_url, sizeof(new_url), "%s%s", https_prefix, url);
        url = new_url;
    }
    while (1) {
        send_packet(url);
    }
    return 0;
}