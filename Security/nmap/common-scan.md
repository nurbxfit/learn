# Common port Scanning Technique

## Concept of Three-way-handshake

- tcp connection, perfom 3 way handshake to establish connection.
- for `Alice` to initiate connection with `Bob` on let say port 22.
- `Alice` first send `TCP SYN` to `Bob` to port 80.
- if `Bob` have a server listening on port 22, it will reply to `Alice` with `TCP SYN/ACK`, saying ok "I got service running here".
- `Alice` then acknowledge that `Bob` know it want to make connection, then `Alice` send the `TCP ACK` to `Bob`.
- then if we want to terminate connection we either send `TCP Fin` or `TCP RST` connection.

![tcp example](https://nmap.org/book/images/ereet/Ereet_Packet_Trace_Connect_Open.png)

- nmap have dozen of port scan technique.
- only one method may be used at a time.
- except for
  - UDP scan (-sU)
  - SCTP scan (-sY,-sZ)
- these exception can be combined with one of TCP scan type.

## TCP scan types.

- TCP Connect scan (-sT)

  - this is a default scanning options.
  - it perform 3 way handshake with our target to get information on open port.
  - after send the `ACK` it will send `RST` packet to kill connection.
  - example usage: `nmap -sT 10.0.2.16`
  - output

  ```
  Starting Nmap 7.91 ( https://nmap.org ) at 2021-06-10 10:59 EDT
    Nmap scan report for 10.0.2.16
    Host is up (0.00066s latency).
    Not shown: 999 filtered ports
    PORT   STATE SERVICE
    22/tcp open  ssh
    MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

    Nmap done: 1 IP address (1 host up) scanned in 4.53 seconds
  ```

- TCP SYN scan (-sS)

  - just like Connect scan, but shorter
  - example usage: `nmap -sS 10.0.2.16`
  - output

  ```
    Nmap scan report for 10.0.2.16
    Host is up (0.00049s latency).

    PORT   STATE SERVICE
    22/tcp open  ssh
    MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

    Nmap done: 1 IP address (1 host up) scanned in 0.49 seconds

  ```

  - what it does is
  - nmap try to establish connection by sending `TCP SYN` packet
  - our target then will reply with `SYN/ACK` if there is a open port.
  - then instead of initiating connection with `TCP ACK`, nmap send `RST` packet, to skip making connection.
  - because we skip `TCP ACK` stage, our scanning become slightly faster and consume less bandwidth when perform on multiple open ports.
    ![tcp sync](https://nmap.org/book/images/ereet/Ereet_Packet_Trace_Syn_Open.png)

- TCP ACK scan (-sA)

  - unlike Connect and SYN,
  - ACK scan simply sent only the ACK packet to the target.
  - a confused target then either send `TCP RST` back to use, no sending any response or sending us with an ICMP error.
  - if the target send back a `TCP RST` packet, it means we are able to reach the port, but we have no ideas if the port is open or not.
  - if there is no response or we got ICMP error, then the port is filtered because either the firewall just drop our ACK packet, thus we haven't receive anything.
  - because all host must send back something to client trying to connect to their service. so if they doesn't sent us anything, there must be firewall involved.
  - other reasons is maybe host is suddently down, (but unlikely, else nmap will tell us).
  - nmap will perform ping scan and host resolution first, to check if host is online then they perform TCP ACK scan.
  - we can see this when we use `-vv` tags for verbose information.
  - example `nmap -sA -p22 scanme.nmap.org --vv`

  ```
  Warning: Hostname scanme.nmap.org resolves to 2 IPs. Using 45.33.32.156.
    Initiating Ping Scan at 12:24
    Scanning scanme.nmap.org (45.33.32.156) [4 ports]
    Completed Ping Scan at 12:24, 0.06s elapsed (1 total hosts)
    Initiating Parallel DNS resolution of 1 host. at 12:24
    Completed Parallel DNS resolution of 1 host. at 12:24, 0.00s elapsed
    Initiating ACK Scan at 12:24
    Scanning scanme.nmap.org (45.33.32.156) [1 port]
    Completed ACK Scan at 12:24, 0.03s elapsed (1 total ports)
    Nmap scan report for scanme.nmap.org (45.33.32.156)
    Host is up, received reset ttl 255 (0.00020s latency).
    Other addresses for scanme.nmap.org (not scanned): 2600:3c01::f03c:91ff:fe18:bb2f
    Scanned at 2021-06-10 12:24:47 EDT for 0s

    PORT   STATE      SERVICE REASON
    22/tcp unfiltered ssh     reset ttl 255

    Read data files from: /usr/bin/../share/nmap
    Nmap done: 1 IP address (1 host up) scanned in 1.13 seconds
            Raw packets sent: 5 (192B) | Rcvd: 2 (80B)

  ```

- TCP Window scan (-sW)
- TCP Maimon scan (-sM)
- TCP Xmas scan (-sX)

## No Port Scan -sn

- also known as Ping scan
- it functions like netdiscover, usefull to discover alive host
- it will not perform port scan, only discover the host
- we provide ip range and it simply return host in it.
- example `nmap -sn 10.0.2.1/24`
- result:

```
Nmap scan report for 10.0.2.1
Host is up (0.00081s latency).
Nmap scan report for 10.0.2.2
Host is up (0.00073s latency).
Nmap scan report for 10.0.2.4
Host is up (0.00059s latency).
Nmap scan report for 10.0.2.5
Host is up (0.00030s latency).
Nmap scan report for 10.0.2.15
Host is up (0.00033s latency).
Nmap done: 256 IP addresses (5 hosts up) scanned in 3.26 seconds
```

<!-- ```
- -sS
- -sT
- -sA
- -sU
- -sY
- -sN
- -sF
- -sX
- -sW
- -sM
- -sZ
- -sI
- -sO
- -sV
- -sC
``` -->

# P for ping
