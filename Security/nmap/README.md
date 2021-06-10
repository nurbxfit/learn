# nmap

- a tools to get more information about the victim.
- scan for open port, or hosts in the network.

# scanning type

## Ping Scan.

- ping is a simple ICMP (Internet Control Message Protocol) scan that send icmp packets to host,
- it send ICM echo packets then waiting for ICMP echo reply from the host.
- if there is no reply packets from the host, the host maybe block any ICMP/ping request.
- it is advisable in any recon, to first send ICMP/ping request usgin `ping` command before perfom nmap scan.
- it's just to know if the host actually alive or not blocking request.
- ping also usefull to get IP address from a hostname.

## Basic nmap scanning

- using generic `nmap scanme.nmap.org` will perfom a ping scan, dns reslution, to find the IP address and Stealth SYN scan to find open port.
- to get more verbose information about the scan, we can use `-v` argument.

example output:

```
Nmap scan report for scanme.nmap.org (45.33.32.156)
Host is up (0.24s latency).
Other addresses for scanme.nmap.org (not scanned): 2600:3c01::f03c:91ff:fe18:bb2f
Not shown: 996 closed ports
PORT      STATE SERVICE
22/tcp    open  ssh
80/tcp    open  http
9929/tcp  open  nping-echo
31337/tcp open  Elite

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 15.57 seconds

```

- here we can see the output, PORT number, STATE and SERVICE
- port number is common port number for services, we can view list of port and service mapping by viewing the file in `/etc/services`.
- here we found the ip address of scanme.nmap.org (45.33.32.156).
- let say, if we want to scan a hostname, that are only resolvable by a private dns-server, we can specify the dns server to nmap using `--dns-servers <dns-ips> <target-hostname>` argument.
  - if we want to use multiple dns-server, simply seperate the ip using commas.
  - example `nmap --dns-servers 1.1.1.1, 8.8.8.8 victim.local.net`
  - if we don't want to perform DNS resolution we can use the `-n` options.
  - let say `www.victim.org` can be resolve into multiple address, we can use `--resolve-all` options, to perform port scanning on all resolved address.
- common nmap protocol tags (this tell nmap, we want to use these protocols to probe).

```
-sP #ping scan
-sS #TCP SYN
-sT #TCP connect
-sU #UDP scan
-sY #SCTP INIT scan
-sZ #SCTP cookie echo
-sN #TCP NULL
-sA #TCP ACK
-sW #TCP ACK with window size
```

## Specifying port.

- to specify the port use the small `-p` following with the port number
  - example: `nmap -p 22 scanme.nmap.org`
  - to specify a range, use it like this `nmap -p 22-444 scanme.nmap.org`

## Versioning

- to get specific version of services, we use the `-sV` tags, for scan Version.
  - example: `nmap -sV scanme.nmap.org`
  - during this phase, we probably get a glance of out target operating system based on the service version.
  - example output

```
PORT      STATE    SERVICE    VERSION
22/tcp    open     ssh        OpenSSH 6.6.1p1 Ubuntu 2ubuntu2.13 (Ubuntu Linux; protocol 2.0)
80/tcp    filtered http
9929/tcp  open     nping-echo Nping echo
31337/tcp open     tcpwrapped
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```

- aggressive scanning: we can increase our probe intensity using `--version-intensity`, 9 is the max
  - example: `nmap -sV --version-intensity 9 scanme.nmap.org`
- using the `-A` tag is a shorter version for `-sC -sV -O` to find, (-sV) version, (-O) OS and (-sC) network enumeration script scanning.
- using `-O` requires us to be a root.
- to specify our network interface use the `-e`

## NSE (Nmap Scripting Engine).

- the most powefull features of nmap is their NSE, which user can write and share our own scripts.
- NSE are written in [Lua](http://www.lua.org/manual/5.3/)
- user can write various script from, Network discovery, version detection, vulnerability detection, backdoor detection, to vulnerability exoloitation.
- we can use NSE using the `-sC` or `--script` followed by our script name or category.
  - syntax : `nmap --script <name-or-category> scname.nmap.org`
  - example: `nmap -sC discovery scanme.nmap.org` or `nmap --script discovery scname.nmap.org`
  - above example will run all script in discovery category.
- location of nmap scripts are usually stored in `/usr/share/nmap/scripts`

## Scripts categories.

- read more about [NSE](https://nmap.org/book/nse-usage.html)
- nmap scripts are devided into few categories which we can use by simply specify the categories name
  - `safe` - this scripts peform action that won't effect the target.
  - `intrusive` - this scripts is the opposite of safe.
  - `vuln` - this scripts categories scan for known vulnerabilities.
  - `exploit` - attempt to exploit the target vulnerabilities.
  - `auth` - perform bruteforce attack on target services.
  - `discovery` - perform service query to get future info.
  - `brodcast` - perform discovery by sending broadcast in local network.
  - `dos` - perform denial of service.

## Searching for NSE script.

few ways to search for a script.

0.  simple open file manager and direct to `/usr/share/nmap/scripts` and you will see lot of file with extension `.nse`

- you can use `ls` and basic wildcard to search for script.

  - example: `ls /usr/share/nmap/scripts/*ftp*`

1. using `/usr/share/nmap/scripts/script.db`.
   - we can open the file, and simply search for keyword.
   - the file is just an indexing for files in `/usr/share/nmap/scripts`.
   - here are the example file content, containing the filename and categories of the script.
   ```
   Entry { filename = "acarsd-info.nse", categories = { "discovery", "safe", } }
   Entry { filename = "address-info.nse", categories = { "default", "safe", } }
   Entry { filename = "afp-brute.nse", categories = { "brute", "intrusive", } }
   ```
   - alternatively we can `grep <keyword> /usr/share/nmap/scripts/script.db `
   - some mistake I made was using cat pipe to grep, where you can just grep without piping.

## Using the scripts

- when you found your desired script or script category you can just use like this

  - by name : `nmap --script smb-enum-users scanme.nmap.org` ; smb-enum-users is the script name
    - let say we want to use multiple script : `nmap --script smb-enum-users,smb-enum-shares scanme.nmap.org` ;
    - we just seperate the script name by commas.
  - by category: `nmap --script vuln scanme.nmap.org`
    - or `nmap --script vuln,safe scname.nmap.org`

- Passing arguments to our script using `--script-args`
- read more on [script argument](https://nmap.org/book/nse-usage.html#nse-args).
- script arguments follows the key='value' pair format.
  - the value is enclosed in single quotes.
  - example:
    - `nmap --script <scriptname> --script-args <key>='<value>' <target>`
  - multiple argument can be seperate with commas.
  - example:
    - `nmap --script <scriptname> --script-args <key1>='<value>',<key2>='<value>' <target>`

### How do we know which argument to pass ?

- to know what argument to use, one of the ways is simply read the scripts.
- most script will have a commented section, telling people how to use it.
- let say as example, we want to use `xmpp-brute` script.
- simple read it via `less /usr/share/nmap/scripts/xmpp-brute.nse`

```lua
local brute = require "brute"
local coroutine = require "coroutine"
local creds = require "creds"
local shortport = require "shortport"
local stdnse = require "stdnse"
local xmpp = require "xmpp"

description = [[
Performs brute force password auditing against XMPP (Jabber) instant messaging servers.
]]

---
-- @usage
-- nmap -p 5222 --script xmpp-brute <host>
--
-- @output
-- PORT     STATE SERVICE
-- 5222/tcp open  xmpp-client
-- | xmpp-brute:
-- |   Accounts
-- |     CampbellJ:arthur321 - Valid credentials
-- |     CampbellA:joan123 - Valid credentials
-- |     WalkerA:auggie123 - Valid credentials
-- |   Statistics
-- |_    Performed 6237 guesses in 5 seconds, average tps: 1247
--
-- @args xmpp-brute.auth authentication mechanism to use LOGIN, PLAIN, CRAM-MD5
--                       or DIGEST-MD5
-- @args xmpp-brute.servername needed when host name cannot be automatically
--                             determined (eg. when running against an IP,
--                             instead of hostname)
--

-- Version 0.1
-- Created 07/21/2011 - v0.1 - created by Patrik Karlsson <patrik@cqure.net>


author = "Patrik Karlsson"
license = "Same as Nmap--See https://nmap.org/book/man-legal.html"
categories = {"brute", "intrusive"}

```

- here in the script tell us in the @args section, which argument to use.
- we can see the argument for this script is `xmpp.brute.servername`, `xmpp-brute.auth`
- these arguments are the script specific arguments.
- there are others argument we can specify.
- for `bruteforce` category scripts, common arguments we can use is
  - `userdb` ; file contains username db;
    - default: `/usr/share/nmap/nselib/data/username.lst`
  - `passdb` ; file contains password db;
    - default: `/usr/share/nmap/nselib/data/passwords.lst`
- example usage

```
nmap -p 5222 --script xmpp-brute --script-args userdb='~/Desktop/username.lst',passdb='~/Desktop/pass.lst',xmpp-brute.auth='LOGIN' target.com
```

- reading directly on the script can be quite challenging for someone who don't understand `Lua`.
- most simpler way to know about the script is simply goolge the name
- read official [nmap docs](https://nmap.org/nsedoc/scripts/xmpp-brute.html) about the script.

## Installing scripts.

- let say you want to sync your scripts with official nmap script, we can simply run `apt update && apt install nmap`.
- to download or add your own script, simply move it to `/urs/share/nmap/scripts` directory and then run `nmap --script-updatedb`.
- this will update the `script.db` we viewed earlier.

## Saving scan result.

- while perfoming scanning, we might want to safe our result as reference, we can save the output of our scan using the small o `-o` tag.
- there are few formats we can save our output.
- Normal Format (-oN)

  - `nmap -T4 -A scanme.nmap.org -oN <path-to-outputfile> `
  - example output look like this

  ```nmap
  # Nmap 7.91 scan initiated Wed Jun  9 01:16:58 2021 as: nmap -T4 -A -oN nmap_out/normal scanme.nmap.org
  Nmap scan report for scanme.nmap.org (45.33.32.156)
  Host is up (0.24s latency).
  Other addresses for scanme.nmap.org (not scanned): 2600:3c01::f03c:91ff:fe18:bb2f
  Not shown: 996 closed ports
  PORT      STATE SERVICE    VERSION
  22/tcp    open  ssh        OpenSSH 6.6.1p1 Ubuntu 2ubuntu2.13 (Ubuntu Linux; protocol 2.0)
  | ssh-hostkey:
  |   1024 ac:00:a0:1a:82:ff:cc:55:99:dc:67:2b:34:97:6b:75 (DSA)
  |   2048 20:3d:2d:44:62:2a:b0:5a:9d:b5:b3:05:14:c2:a6:b2 (RSA)
  |   256 96:02:bb:5e:57:54:1c:4e:45:2f:56:4c:4a:24:b2:57 (ECDSA)
  |_  256 33:fa:91:0f:e0:e1:7b:1f:6d:05:a2:b0:f1:54:41:56 (ED25519)
  80/tcp    open  http       Apache httpd 2.4.7 ((Ubuntu))
  |_http-favicon: Nmap Project
  |_http-server-header: Apache/2.4.7 (Ubuntu)
  |_http-title: Go ahead and ScanMe!
  9929/tcp  open  nping-echo Nping echo
  31337/tcp open  tcpwrapped
  Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

  Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
  # Nmap done at Wed Jun  9 01:17:32 2021 -- 1 IP address (1 host up) scanned in 33.65 seconds

  ```

- XML format (-oX).
  - this stored the output in a xmal format, that can be easily parsed by other tools or scripts.
  - `nmap -T4 -A scanme.nmap.org -oX ~/Desktop/nmapout.xml`
  - the output can be overwhelme, but here's a snippit of the output.
  ```xml
  <verbose level="0"/>
  <debugging level="0"/>
  <hosthint><status state="up" reason="unknown-response" reason_ttl="0"/>
  <address addr="45.33.32.156" addrtype="ipv4"/>
  <hostnames>
  <hostname name="scanme.nmap.org" type="user"/>
  </hostnames>
  </hosthint>
  <host starttime="1623216170" endtime="1623216199"><status state="up" reason="syn-ack" reason_ttl="0"/>
  <address addr="45.33.32.156" addrtype="ipv4"/>
  <hostnames>
  <hostname name="scanme.nmap.org" type="user"/>
  <hostname name="scanme.nmap.org" type="PTR"/>
  </hostnames>
  <ports><extraports state="closed" count="962">
  <extrareasons reason="conn-refused" count="962"/>
  </extraports>
  <extraports state="filtered" count="35">
  <extrareasons reason="no-responses" count="35"/>
  </extraports>
  ```
- $crIpT kIddI3 format (-oS).

  - as you can see from the name, its a joke, printing letters in weird mix of inconsistent capitalization.
  - `nmap -T4 -A scanme.nmap.org -oS <path-to-outputfile> `
  - here are the example output

  ```nmap
  start1ng Nmap 7.91 ( httpz://Nmap.0rg ) at 2021-06-09 01:25 eDT
  Nmap scan r3p0Rt fOr $cANM3.nmap.0rg (45.33.32.156)
  h0st iz Up (0.23z latENcY).
  OTh3r aDdr3s$3z f0r scanm3.nmap.0rg (n0t ScAnned): 2600:3c01::f03c:91ff:f318:bb2F
  N0T sh0wn: 986 Cl0S3d p0rts
  PORT      ST4TE    SERVice       V3RS|oN
  22/tcp    OPEN     $$H           OpENSSH 6.6.1p1 UbuNtu 2ubuNTu2.13 (Ubuntu L1nux; prOt0c0l 2.0)
  | $$h-ho$tk3Y:
  |   1024 ac:00:a0:1a:82:Ff:cc:55:99:Dc:67:2b:34:97:6b:75 (DS4)
  |   2048 20:3D:2d:44:62:2a:b0:5a:9d:b5:B3:05:14:c2:a6:b2 (R$A)
  |   256 96:02:bb:5E:57:54:1C:4e:45:2f:56:4c:4a:24:b2:57 (eCD$4)
  |_  256 33:fa:91:0f:30:31:7b:1f:6d:05:a2:b0:f1:54:41:56 (3D25519)
  80/tcp    0peN     http          apAche Httpd 2.4.7 ((Ubuntu))
  |_Http-favicon: NmaP PR0ject
  |_hTtp-$3rveR-hEader: 4pache/2.4.7 (uBuntU)
  |_httP-t1tle: G0 aH3Ad and ScaNM3!
  406/tcp   filt3r3D im$p
  1043/tcp  f!LT3red B0Inc
  1064/tcP  fILteREd J$tel
  1183/tcp  fIlTer3D Ll$urfuP-hTtp
  1311/tcp  filtEr3d rxm0n
  1718/tCp  filtErEd H323gat3D|$C
  2967/tCp  fiLtered $ymaNtec-av
  5001/tcp  F|lterEd COMmpLEX-liNk
  8008/tCp  f1ltEred http
  9929/tcp  0p3n     nPiNg-ecH0    Np|ng 3Ch0
  31337/tcp 0p3n     TcpwRaPp3d
  52673/tcp f|lT3R3d uNkN0wn
  $3Rvic3 inf0: Os: L|nux; cPE: cp3:/0:Linux:l|nuX_kern3l

  ServiC3 d3tect!0N perfoRmEd. PleA$e R3p0rt any iNcoRrEct r3$Ultz At hTtps://nmaP.0rg/$Ubmit/ .
  NmAp dOn3: 1 iP addr3$z (1 hOst up) scann3d !n 37.91 $eCoNdz

  ```

- Grep format (-oG)
  - this format yield output that are grepable, means we can easily use it with grep.
  - `nmap -T4 -A scanme.nmap.org -oN <path-to-outputfile> `
  - here are the example outputs, short and simple seperate by commas.
  ```gnmap
  # Nmap 7.91 scan initiated Wed Jun  9 01:35:45 2021 as: nmap -T4 -A -oG nmap_out/grepformat scanme.nmap.org
  Host: 45.33.32.156 (scanme.nmap.org)    Status: Up
  Host: 45.33.32.156 (scanme.nmap.org)    Ports: 22/open/tcp//ssh//OpenSSH 6.6.1p1 Ubuntu 2ubuntu2.13 (Ubuntu Linux; protocol 2.0)/, 80/open/tcp//http//Apache httpd 2.4.7 ((Ubuntu))/, 9929/open/tcp//nping-echo//Nping echo/, 31337/open/tcp//tcpwrapped///     Ignored State: closed (996)
  # Nmap done at Wed Jun  9 01:36:15 2021 -- 1 IP address (1 host up) scanned in 29.62 seconds
  ```
- major format, AKA All format (-oA)
  - this will create output of 3 major format (normal, grep and XML) each as seperate file.
  - `nmap -T4 -A scanme.nmap.org -oA nmap_out/combined`
  - this will produce 3 files `combined.gnmap`, `combined.nmap`, `combined.xml`
- in this example, notice that we use `-T` tag, with a number.
- this tag is the level of timing, with highest level is the faster timing but noisier.
- what is does is making our scan run faster, but can prone to error because of the noise created can be detected IDS or firewall.
