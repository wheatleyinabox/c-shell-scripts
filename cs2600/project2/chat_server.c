#define PortNumber 6463
#define MaxConnects 3
#define BuffSize 256
#define ConverationLen 3
#define Host "localhost"

#include <sys/socket.h>
#include <unistd.h>

int main()
{
        // Variables to define...
        //      PortNumber [there was 2 I picked one-]

        int fd = socket(AF_INET, SOCK_STREAM, 0);

        if (fd < 0) // if fd negative...
        {
                report("socket", 1); // terminate
        }

        // bind the server's local address in memory
        struct sockaddr_in saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_addr.s_addr = htonl(INADDR_ANY);
        saddr.sin_port = htons(PortNumber);

        // binds the socket to a memory address
        if (bind(fd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0)
        {
                report("bind", 1); // terminate
        }

        // Listen for socket connections & limit queue for incoming connections
        if (listen(fd, MaxConnects) < 0)
        {
                report("listen", 1);
        }
        fprintf(stderr, "Listening on port %i for clients...\n", PortNumber);

        // accept a new connections to the socket
        while (1)
        {
                struct sockaddr_in caddr; // client address
                int len = sizeof(caddr);

                int client_fd = accept(fd, (struct sockaddr*)&caddr, &len);
                if (client_fd < 0)
                {
                        report("accept", 0);
                        continue;
                }

                // ssize_t read();
                // ssize_t write();

                close(client_fd);
        }

        return 0;
}