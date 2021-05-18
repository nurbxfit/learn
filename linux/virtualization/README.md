## KVM install Basic.

- KVM stand for Kernel Virtual Machine.
- it's a hypervisor (virtual machine manager)
- it consist of loadable kernerl module `kvm.ko` and CPU specific module such as `kvm-intel.ko` or `kvm-amd.ko` that provide core virtualization functionality to linux.

### Checking for support.

- check if our CPU support Virtualization Technology such as VT-x (for Intel).
- simply google our CPU model and check the specification.
- make sure to enable virtualization in Bios.
  - go to bios advance setting.
  - CPU setting, and find options for Virtualization and enable it.
- check our os support vmx
  - run in terminal `egrep -c '(vmx|svm)' /proc/cpuinfo`
  - or run `sudo kvm-ok`.
- install qemu and other dependencies

```
sudo apt install -y qemu qemu-kvm libvirt-daemon libvirt-clients bridge-utils virt-manager
```

- check if our kvm kernel module are loaded using `lsmod | grep kvm`

## Network Virtualization using Libvirt.

- enable us creating virtual network that we can use together with KVM virtualization.
- we install using `sudo apt install -y libvirt-daemon libvirt-clients`
- `/etc/libvirt/qemu/networks`
- view our network interface using `ip a`
- this usually will output our network interface such as
  - `lo` for local loopback.
  - `enp3s0` or `eth0` for our ethernet interface
  - `wlp3s0` or `wlan0` for our wireless interface.
- if we do not see any interface such as `virbr0` (virtual bridge), our libvirtd service might not be up and runnning.
- we can check this using `sudo systemctl status libvirtd`
- if it's not yet start, we can run `sudo systemctl start libvirtd` to start it.
- then we can see we now have our virtual interface up in `ip a` result

## brctl (bridge control).

- we can use `brtctl` to create and manage a bridge network.
- to list our bridge network we use `brctl show`
- to create one we can use `brctl addbr <name>`
  - eg: `brctl addbr br0`.
- we can enable STP (Spanning Tree Protocol)
  - we do this thru `brctl stp <name> on`
  - eg: `brctl stp br0 on`
  - to disable it, simply use `off` instead of `on`
- to remove a bridge we can use `brctl delbr <name>`

## Virsh (Virtualization interactive terminal).

- make sure to run as `root` previlege for better experience
- Virsh is a command line tools to manage virtual machine.
- we can run it by simply type `virsh` to get into an interactive shell.
- to list our virtual machine we can run `virsh list` or simply `list` in virsh shell.
  - this will list all active virtual machine.
- we can also list virtual network using `virsh net-list`

  - we can list all inactive network using `virsh net-list --inactive`
  - we can create new virtual network using `virst net-define <config.xml>`
  - we can view default `.xml` in `/etc/libvirt/qemu/networks/default.xml`

  ```xml
  <!--example content of default.xml-->

  <network>
    <name>default</name> <!--name of our network in virsh-->
    <uuid>890557f9-4a3c-4957-aa23-efff790abd11</uuid>
    <forward mode='nat'/>
    <bridge name='virbr0' stp='on' delay='0'/> <!--our network name-->
    <mac address='52:54:00:81:73:97'/>
    <ip address='192.168.122.1' netmask='255.255.255.0'>
        <dhcp>
            <range start='192.168.122.2' end='192.168.122.254'/>
        </dhcp>
    </ip>
  </network>
  ```

  - we can start our network using `virst net-start <name>`
  - to edit we use `virst net-edit <name>`
    - this will open an xml document that we can edit.
    - after edit we need to restart our network using
      - `virsh net-destroy <name>`
      - `virsh net-start <name>`
    - to view our network info such as ip addr we can use `ip addr show virbr0`
    - to view list of bridge network we use `brctl show`
  - we can remove network we using `virsh net-undefine <name>`

- using virst to connect to qemu kvm.
  - `sudo virsh -c qemu:///system`
- we can use virst to connect to a remote system.

  - connect via ssh `virsh -c qemu+ssh://root@<address>/system`.

- there are more options we can use such as configure the storage.
  - storage location is in `/var/lib/libvirt/images`
- find our more command using `virsh help`.

## virt-manager.

- or virtual machine manager, is a GUI alternative to virsh.
- we can start is using `sudo virt-manager`

## Enabling remote autoinstall.

- we can boot our installation media from remote server via tftp.
- we can use [PXE](https://www.manageengine.com/products/os-deployer/pxe-preboot-execution-environment.html) to use that remote vsftp server to store our boot media.
- our virtual machine upon booting will fetch the remote media and boot it via network.
- for a RHEL base distro we can use a `kickstart file` usually end with `.ks` to create an auto install configuration that will be use to auto install our operating system via network.
- for ubuntu we can [refer here](https://askubuntu.com/questions/1235723/automated-20-04-server-installation-using-pxe-and-live-server-image).
- [debian reference](https://lathama.net/PXE_boot_with_Libvirt)
