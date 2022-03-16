# Basics of UDP
# Code from this: https://www.geeksforgeeks.org/udp-server-client-implementation-c/

### Steps

1. create sockets for client and server sides.
2. bind those sockets 
3. For server side, listen in using the `recvfrom` function from `<sys/socket.h>` lib. Send a confirm message using `sendto`
4. For client side, send message using `sendto` function from `<sys/socket.h>` lib. Receive a confirm message using `recvfrom`


### Purpose

Just trying to freshen up on the basics of UDP and TCP


### Next steps

Implement a LAN chat room using UDP
