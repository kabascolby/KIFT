#include "server.h"

int main(int argc, char **argv)
{
    char str[BUFSIZE];
    t_config config;
    char *cmd1 = "hello my Genius";

    if (argc < 2)
    {
        fprintf(stderr, "Error: Port number has to be specified\n");
        return (1);
    }

    if (create_server(&config, atoi(argv[1])))
    {
        fprintf(stderr, "Error Serveur configuration\n");
        return (1);
    }

    while (1)
    {
        bzero(str, BUFSIZE);

        if (config.status && read(config.status, str, BUFSIZE))
        {
            fprintf(stdout, "\033[1;34mClient ->\033[m %s", str);
            write(config.status, str, strlen(str) + 1);
            send(config.status, cmd1, strlen(cmd1) + 1, 0);
        }
    }
    return (0);
}