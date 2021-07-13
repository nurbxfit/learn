# GNS3 in Fedora.
- things you need are:
    - vpcs 
    - dynamips
    - gns3-server
    - gns3-gui
    - ubridge

## Enable RPMFusion Repo
```bash
  $sudo dnf install https://mirrors.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm https://mirrors.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm && sudo dnf copr enable tgerov/vpcs
```
- we enable this for dynamips and vpcs.
- if u want to compile it yourself check the github repo.
- install cmake to compile dynamips.
- [dynamips](https://github.com/GNS3/dynamips)
- [vpcs](https://github.com/GNS3/vpcs)

## Install the dependencies.
```bash
$sudo dnf install gns3-gui gns3-server dynamips vpcs ubridge
```

## Install qemu-kvm
- this is a VM, and optional if you are using something else like GNS3 VM on VMWare or Virtualbox
```bash
$sudo dnf install libvirt qemu-kvm
$sudo gpasswd -a $(id -un) libvirt
```

## Source of Reference
[Gerov: how-to-install-gns3-on-fedora](https://gerov.eu/posts/how-to-install-gns3-on-fedora/)