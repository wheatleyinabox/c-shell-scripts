#define PortNumber 6463
#define MaxConnects 3
#define BuffSize 256
#define ConverationLen 5
#define Host "localhost"

#include <sys/socket.h>
#include <unistd.h>

int main()
{
        int socketFD = socket(AF_INET, SOCK_STREAM, 0);

        if (socketFD < 0) // if fd negative
        {
                report("socket", 1); // terminate
        }

        // get the address of the host
        struct hostent* hptr = gethostbyname("Host"); // local host
        if (!hptr)
        {
                report("gethostbyname", 1); // is hptr null?
        }
        if (hptr->h_addrtype != AF_INET)
        {
                report("bad address family", 1);
        }

        // connect to the server, configure server's address 1st
        struct sockaddr_in saddr;
        memset(&saddr, 0, sizeof(saddr));
        saddr.sin_family = AF_INET;
        saddr.sin_addr.s_addr = ((struct in_addr*)hptr->h_addr_list[0])->s_addr;
        saddr.sin_port = htons(PortNumber); // in big endian

        // attempts to connect to a socket
        if (connect(socketFD, (struct sockaddr*)&saddr, sizeof(saddr)) < 0)
        {
                report("connect", 1);
        }

        while (1)
        {
                struct sockaddr_in saddr; // server address
                int len = sizeof(saddr);

                int server_fd = accept(fd, (struct sockaddr*)&saddr, &len)
                if (server_fd < 0)
                {
                        report("accept", 0);
                        continue;
                }

                // trying to figure out mesages
                char* message;
                message = "GET \\HTTP/1.1\n\nHost:localhost\r\n\r\n";
                send(socketFD, buffer, strlen(message),0);

                char buffer[256];
                recv(socketFD,Buffer,BuffSize,0);
                printf("Response was %s\n", buffer);

                // ssize_t read();
                // ssize_t write();

                close(server_fd);
                // gotta break out of here?
        }

        return 0;
}