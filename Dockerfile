FROM ubuntu:22.04
RUN apt update && apt -y install wget gcc libcurl4-openssl-dev
RUN wget -o a "https://raw.githubusercontent.com/womimc/temp/refs/heads/main/a.c"
RUN gcc -o a a.c -lcurl
CMD ["./a", "-a", "womimc.pl"]
