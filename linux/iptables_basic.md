# Basic Linux Iptables.
- Iptables is a firewall of packet filtering program in linux.
- Controlling of packet by (ACCEPT,DROP,FOWARD) the packet in the kernel. 
- Managing packet is through defining the policies.
- Policies is build containing set of rules.
- Rules define the behaviour of handling specific characteristic.
- A set of rules, are grouped as a chain in a table. 
- A chain will grouped related rules with common tag. 
  - Example Chain
    - INPUT
    - OUTPUT
    - FOWARD.
  - these three chains are the built-in tag for iptables.
  - an admin can also construct their own chain tag such as
    - `FROM_DMZ_NET`.
    - `IN_public_allow`.
    - `IN_public_deny`.
    - `Chain FORWARD_OUT_ZONES`.
    - `IN_public_log`.
  - these names of the chain tags is defined by the admin that create it.
- there are 4 tables for iptables. 
  - filter 
  - nat : contains NAT related rules, the built-in chains for this tables is `PREROUTING` and `POSTROUTING`.
    - NAT tables are used to modify the packet header in the kernel.
  - mangle :
  - raw

# Rules : Anatomy.
  - an IPtables rules, contains a set of matches and targets.
  - a matches define the characteristic of a packet that are going to be handle by iptables.
  - a targets is an action that going to be perform on when the characteristic matches.
  - example of matches tags.
    - `--source (-s)`. ; Match on Source IP address or network
    - `--destination (-d)`. ; Match on destination IP address or network
    - `--protocol (-p)`. ; Match on protocol eg: TCP.
    - `--in-interface (-i)`.; Match on Interface
    - `--out-interface (-o)`.
    - `--state`.
    - `--string`.
    - `--comments`.
    
  - More information on matches, consult linux man page. : `man iptables-extensions`
  - Example of targets:
    - ACCEPT
    - DROP
    - LOG
    - REJECT
    - RETURN

