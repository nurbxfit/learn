# Enumerating DNS using nmap.

- we can perform dns brute force attack to find common, subdomains of a host.
- nmap got a script for that called `dns-brute`
- to use it, simply `nmap --script dns-brute nmap.org -p 80`

# scanning protocol.

- instead of scanning thru port numbers, we can scan thru IP protocol supported by the host such as `ICMP`,`TCP`,`UDP`,`IGMP`.
- to do this, we use `-sO` tag in nmap.
- example: `nmap -sO scanme.nmap.org`
- this will show state of protocol that are filtered or not by firewall.

```
PROTOCOL STATE         SERVICE
1        open          icmp
2        open|filtered igmp
4        open|filtered ipv4
6        open          tcp
17       open          udp
29       open|filtered iso-tp4
41       open|filtered ipv6
50       open|filtered esp
51       open|filtered ah
78       open|filtered wb-mon
104      open|filtered aris
185      open|filtered unknown
206      open|filtered unknown
```

# PORT state recognized by Nmap

```

open
An application is actively accepting TCP connections, UDP datagrams or SCTP associations on this port. Finding these is often the primary goal of port scanning. Security-minded people know that each open port is an avenue for attack. Attackers and pen-testers want to exploit the open ports, while administrators try to close or protect them with firewalls without thwarting legitimate users. Open ports are also interesting for non-security scans because they show services available for use on the network.

closed
A closed port is accessible (it receives and responds to Nmap probe packets), but there is no application listening on it. They can be helpful in showing that a host is up on an IP address (host discovery, or ping scanning), and as part of OS detection. Because closed ports are reachable, it may be worth scanning later in case some open up. Administrators may want to consider blocking such ports with a firewall. Then they would appear in the filtered state, discussed next.

filtered
Nmap cannot determine whether the port is open because packet filtering prevents its probes from reaching the port. The filtering could be from a dedicated firewall device, router rules, or host-based firewall software. These ports frustrate attackers because they provide so little information. Sometimes they respond with ICMP error messages such as type 3 code 13 (destination unreachable: communication administratively prohibited), but filters that simply drop probes without responding are far more common. This forces Nmap to retry several times just in case the probe was dropped due to network congestion rather than filtering. This slows down the scan dramatically.

unfiltered
The unfiltered state means that a port is accessible, but Nmap is unable to determine whether it is open or closed. Only the ACK scan, which is used to map firewall rulesets, classifies ports into this state. Scanning unfiltered ports with other scan types such as Window scan, SYN scan, or FIN scan, may help resolve whether the port is open.

open|filtered
Nmap places ports in this state when it is unable to determine whether a port is open or filtered. This occurs for scan types in which open ports give no response. The lack of response could also mean that a packet filter dropped the probe or any response it elicited. So Nmap does not know for sure whether the port is open or being filtered. The UDP, IP protocol, FIN, NULL, and Xmas scans classify ports this way.

closed|filtered
This state is used when Nmap is unable to determine whether a port is closed or filtered. It is only used for the IP ID idle scan.
```

# check for Firewall

- let say we perform a simple TCP ACK scan using `-sA`
- running `nmap -sA 10.0.2.16`
- for a firewalled machine, we will get something like this.

```
Nmap scan report for 10.0.2.16
Host is up (0.00027s latency).
All 1000 scanned ports on 10.0.2.16 are filtered
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

Nmap done: 1 IP address (1 host up) scanned in 22.51 seconds

```

- if we get unfiltered like this

```
Nmap scan report for 10.0.2.16
Host is up (0.00059s latency).
All 1000 scanned ports on 10.0.2.16 are unfiltered
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

Nmap done: 1 IP address (1 host up) scanned in 2.30 seconds

```

- our nmap scan might be having problems to determine if it is filtered or not
- to make it more percise, we can try specify port in that scan.
- running `nmap -p 80 -sA 10.0.2.16`
- in case of no firewall we can see

```

Nmap scan report for 10.0.2.16
Host is up (0.00034s latency).

PORT   STATE      SERVICE
80/tcp unfiltered http
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

Nmap done: 1 IP address (1 host up) scanned in 0.42 seconds

```

- we can reach the service, but there is no reply from server, thus, nmap do not know if it is open or closed.
- for a filtered/firewalled result we can see

```

Nmap scan report for 10.0.2.16
Host is up (0.00026s latency).

PORT   STATE    SERVICE
80/tcp filtered http
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

Nmap done: 1 IP address (1 host up) scanned in 0.54 seconds

```

- if `TCP ACK` doesn't yield much usefull information about the state of the port.
- we can perfom other TCP scan such as `TCP CONNECT` using `-sT`
- example `nmap -p- -sT 10.0.2.16`
- the `-p-` means to use all possible port number.
- for a non firewalled result we might see something like this

```
map scan report for 10.0.2.16
Host is up, received arp-response (0.00029s latency).
Scanned at 2021-06-10 04:49:51 EDT for 84s
Not shown: 65524 closed ports
Reason: 65524 conn-refused
PORT      STATE SERVICE      REASON
22/tcp    open  ssh          syn-ack
135/tcp   open  msrpc        syn-ack
139/tcp   open  netbios-ssn  syn-ack
445/tcp   open  microsoft-ds syn-ack
5357/tcp  open  wsdapi       syn-ack
49152/tcp open  unknown      syn-ack
49153/tcp open  unknown      syn-ack
49154/tcp open  unknown      syn-ack
49155/tcp open  unknown      syn-ack
49156/tcp open  unknown      syn-ack
49162/tcp open  unknown      syn-ack
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

```

- we can see from the output, our TCP connect, receive a TCP syn-ack from the target host.

- for a firewalled result of the same machine we might see something like this

```
Nmap scan report for 10.0.2.16
Host is up, received arp-response (0.0029s latency).
Scanned at 2021-06-10 04:53:57 EDT for 111s
Not shown: 65534 filtered ports
Reason: 65534 no-responses
PORT   STATE SERVICE REASON
22/tcp open  ssh     syn-ack
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

```

- at the end, it's all depend on the firewall rules configuration
- we can perfom other type of scan such as TCP SYN `-sS` or TCP NULL`-sN` to check for different result.

# check for OS.

- perfoming an OS scan, we can use the `-O` tag
- example `nmap -O 10.0.2.16`
- result will show something like this.

```
Nmap scan report for 10.0.2.16
Host is up (0.00054s latency).
Not shown: 999 filtered ports
PORT   STATE SERVICE
22/tcp open  ssh
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Microsoft Windows Vista|2008 (91%)
OS CPE: cpe:/o:microsoft:windows_vista::sp2 cpe:/o:microsoft:windows_server_2008::beta3 cpe:/o:microsoft:windows_server_2008
Aggressive OS guesses: Microsoft Windows Vista SP2 (91%), Microsoft Windows Server 2008 or 2008 Beta 3 (90%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 1 hop
```

or

```
Nmap scan report for 10.0.2.4
Host is up (0.00047s latency).
Not shown: 997 closed ports
PORT    STATE SERVICE
135/tcp open  msrpc
139/tcp open  netbios-ssn
445/tcp open  microsoft-ds
MAC Address: 08:00:27:8F:81:AA (Oracle VirtualBox virtual NIC)
Device type: general purpose
Running: Microsoft Windows XP|2003
OS CPE: cpe:/o:microsoft:windows_xp cpe:/o:microsoft:windows_server_2003
OS details: Microsoft Windows XP SP2 or SP3, or Windows Server 2003
Network Distance: 1 hop

```

# Identifying vulnerabilities

- to identify vulnerabilities, we can run `vulners` scripts
- to run it `nmap --script vulners -sV 10.0.2.16`
- example output is

```
Nmap scan report for 10.0.2.16
Host is up (0.00044s latency).
Not shown: 999 filtered ports
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 6.7 (protocol 2.0)
| vulners:
|   cpe:/a:openbsd:openssh:6.7:
|       EDB-ID:21018    10.0    https://vulners.com/exploitdb/EDB-ID:21018      *EXPLOIT*
|       CVE-2001-0554   10.0    https://vulners.com/cve/CVE-2001-0554
|       CVE-2015-5600   8.5     https://vulners.com/cve/CVE-2015-5600
|       EDB-ID:40888    7.8     https://vulners.com/exploitdb/EDB-ID:40888      *EXPLOIT*
|       CVE-2020-16088  7.5     https://vulners.com/cve/CVE-2020-16088
|       EDB-ID:41173    7.2     https://vulners.com/exploitdb/EDB-ID:41173      *EXPLOIT*
|       CVE-2015-6564   6.9     https://vulners.com/cve/CVE-2015-6564
|       CVE-2018-15919  5.0     https://vulners.com/cve/CVE-2018-15919
|       CVE-2017-15906  5.0     https://vulners.com/cve/CVE-2017-15906
|       SSV:90447       4.6     https://vulners.com/seebug/SSV:90447    *EXPLOIT*
|       EDB-ID:45233    4.6     https://vulners.com/exploitdb/EDB-ID:45233      *EXPLOIT*
|       EDB-ID:45210    4.6     https://vulners.com/exploitdb/EDB-ID:45210      *EXPLOIT*
|       EDB-ID:45001    4.6     https://vulners.com/exploitdb/EDB-ID:45001      *EXPLOIT*
|       EDB-ID:45000    4.6     https://vulners.com/exploitdb/EDB-ID:45000      *EXPLOIT*
|       EDB-ID:40963    4.6     https://vulners.com/exploitdb/EDB-ID:40963      *EXPLOIT*
|       EDB-ID:40962    4.6     https://vulners.com/exploitdb/EDB-ID:40962      *EXPLOIT*
|       CVE-2016-0778   4.6     https://vulners.com/cve/CVE-2016-0778
|       CVE-2020-14145  4.3     https://vulners.com/cve/CVE-2020-14145
|       CVE-2015-5352   4.3     https://vulners.com/cve/CVE-2015-5352
|       CVE-2007-2768   4.3     https://vulners.com/cve/CVE-2007-2768
|       CVE-2016-0777   4.0     https://vulners.com/cve/CVE-2016-0777
|_      CVE-2015-6563   1.9     https://vulners.com/cve/CVE-2015-6563
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

```

- here we get various CVE for Openssh, we can copy it and perfom a google search to find out more about the vulnerabilities.
- we can also make use of metasploit to attack known vulnerabilities.

# (stealth) Finding zombies machine for proxying.

- in nmap, we can proxy our ip address for scanning, by using zombies host.
- first we need to find the zombies using the script `ipidseq`
- to do this run `nmap --script ipidseq 10.0.2.0/24`
- `10.0.2.0/24` is our network address range we want to scan.
- to perfom zombies proxy, we need to find host with `ipidseq : Incremental!`
- example output from my scan, we found two host that support ip id sequence increment

```
Nmap scan report for 10.0.2.1
Host is up (0.000073s latency).
Not shown: 999 closed ports
PORT   STATE SERVICE VERSION
53/tcp open  domain  (generic dns response: SERVFAIL)
| fingerprint-strings:
|   DNSVersionBindReqTCP:
|     version
|_    bind
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port53-TCP:V=7.91%I=7%D=6/10%Time=60C1EAB1%P=x86_64-pc-linux-gnu%r(DNSV
SF:ersionBindReqTCP,20,"\0\x1e\0\x06\x81\x82\0\x01\0\0\0\0\0\0\x07version\
SF:x04bind\0\0\x10\0\x03");
MAC Address: 52:54:00:12:35:00 (QEMU virtual NIC)

Host script results:
|_ipidseq: Incremental!

Nmap scan report for 10.0.2.2
Host is up (0.00015s latency).
Not shown: 998 closed ports
PORT     STATE SERVICE VERSION
631/tcp  open  ipp     CUPS 2.3
|_http-server-header: CUPS/2.3 IPP/2.1
5989/tcp open  vnc     VNC (protocol 3.8)
MAC Address: 52:54:00:12:35:00 (QEMU virtual NIC)

Host script results:
|_ipidseq: Unknown

Nmap scan report for 10.0.2.3
Host is up (0.000060s latency).
All 1000 scanned ports on 10.0.2.3 are filtered
MAC Address: 08:00:27:78:39:A6 (Oracle VirtualBox virtual NIC)

Nmap scan report for 10.0.2.4
Host is up (0.00038s latency).
Not shown: 997 closed ports
PORT    STATE SERVICE      VERSION
135/tcp open  msrpc        Microsoft Windows RPC
139/tcp open  netbios-ssn  Microsoft Windows netbios-ssn
445/tcp open  microsoft-ds Microsoft Windows XP microsoft-ds
MAC Address: 08:00:27:8F:81:AA (Oracle VirtualBox virtual NIC)
Service Info: OSs: Windows, Windows XP; CPE: cpe:/o:microsoft:windows, cpe:/o:microsoft:windows_xp

Host script results:
|_ipidseq: Incremental!

Nmap scan report for 10.0.2.16
Host is up (0.00051s latency).
Not shown: 999 filtered ports
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 6.7 (protocol 2.0)
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)

Host script results:
|_ipidseq: Incremental!

Nmap scan report for 10.0.2.5
Host is up (0.0000020s latency).
All 1000 scanned ports on 10.0.2.5 are closed

Host script results:
|_ipidseq: All zeros

Nmap scan report for 10.0.2.15
Host is up (0.0000030s latency).
All 1000 scanned ports on 10.0.2.15 are closed

Host script results:
|_ipidseq: All zeros

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 256 IP addresses (7 hosts up) scanned in 24.19 seconds

```

- the addresses we can use as zombie are `10.0.2.16`, `10.0.2.4` and `10.0.2.1`.
- to use those ip for scanning we specify the `-sI` tag followed by the ip address.
-
- example we perform os scan using zombie address of `10.0.2.4` and target address of `10.0.2.16`
  - `nmap -O -sI 10.0.2.4 10.0.2.16`
- thing to note is, make sure our zombies are not behind firewall, unless we will not receive any result.
- example output if our zombie is behind firewall (our zombie is 10.0.2.16)

```
Idle scan zombie 10.0.2.16 (10.0.2.16) port 443 cannot be used because it has not returned any of our probes -- perhaps it is down or firewalled.
QUITTING!

```

- example output if our zombie are not behind firewall (our zombie is 10.0.2.4)

```
Idle scan using zombie 10.0.2.4 (10.0.2.4:443); Class: Incremental
Nmap scan report for 10.0.2.16
Host is up (0.0052s latency).
Not shown: 999 closed|filtered ports
PORT   STATE SERVICE
22/tcp open  ssh
MAC Address: 08:00:27:10:B8:D0 (Oracle VirtualBox virtual NIC)
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Microsoft Windows 2008|Vista (92%), FreeBSD 6.X (85%)
OS CPE: cpe:/o:microsoft:windows_server_2008::beta3 cpe:/o:microsoft:windows_server_2008 cpe:/o:microsoft:windows_vista::sp2 cpe:/o:freebsd:freebsd:6.2
Aggressive OS guesses: Microsoft Windows Server 2008 or 2008 Beta 3 (92%), Microsoft Windows Vista SP2 (91%), FreeBSD 6.2-RELEASE (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 1 hop

```
