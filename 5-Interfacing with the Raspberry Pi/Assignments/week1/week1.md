# In your own words, write a short paragraph describing the differences between the TCP and IP protocols. Then, in your own words, describe the different roles between the TCP and IP protocols in Internet communication.


**The Main Difference Between TCP/IP and IP Protocols is**

TCP is responsible for the data delivery of a packet and IP is responsible for the logical addressing.

Means, the IP obtains the address and TCP guarantees delivery of data to that address.

TCP = Transmission Control protocol, a connection oriented and reliable protocol that is present in the transport layer.

IP = Internet Protocol a connection less network layer protocol and is responsible for sending the packets to devices in the network.

TCP transfers Segments to internet layer, whereas IP transfers Datagrams to physical level.

TCP carries with its own flow control, but there is no flow control in IP.
Format of TCP

TCP segments have a 20 byte header with >= 0 bytes of data

Format of IP

IP datagrams contain a message, or one fragment of a message, that may be up to 65,535 bytes (octets) in length
