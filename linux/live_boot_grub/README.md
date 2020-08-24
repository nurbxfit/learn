-------
Author: Nurfitri
-------
# Boot a Live ISO image using grub.
- having already installed arch based linux system on my pc.
- without using live usb, we can also boot the `.ISO` file through grub.
- we first need to download the iso file, and then configure our grub menu.
- open grub custom configure file `/etc/grub.d/40_custom` using text editor.

	```
		$ sudo vim /etc/grub.d/40_custom
	```

- then add the following entry at the bottom:

	```
	menuentry "Title of my ISO file" --class someclassname{ # change someclassname with other name
  	set root='(hd2,4)' #change with the main partition of your current OS
  	set isofile="/home/jun/Downloads/archlinux.iso" #change with the iso file u want to boot
		set dri="free"
 		search --no-floppy -f --set=root $isofile
 		probe -u $root --set=abc
 		set pqr="/dev/disk/by-uuid/$abc"
 		loopback loop $isofile
 		linux  (loop)/arch/boot/x86_64/vmlinuz-linux img_dev=$pqr img_loop=$isofile driver=$dri quiet splash vt.global_cursor_default=0 loglevel=2 rd.systemd.show_status=false rd.udev.log-priority=3 sysrq_always_enabled=1 cow_spacesize=2G
  	initrd  (loop)/arch/boot/intel-ucode.img (loop)/arch/boot/amd-ucode.img (loop)/arch/boot/x86_64/archiso.img
 	} 

	```
- note to replace `isofile` path to the path of your downloaded iso file.
- and replace the `Title of my ISO file` with anything you want to show in grub menu.
- then save the file (if using vim press the `<ESC>` button and then press the `:` button and write `wq` and press enter).
- then reload and update the `grub.cfg`

	```
	# on Arch based distro
	$ sudo grub-mkconfig -o /boot/grub/grub.cfg

	# on ubuntu based distro
	$ sudo update-grub
	```

