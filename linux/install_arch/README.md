-------
Author: Nurfitr
-------

# Download Arch Linux
1. Arch linux iso file can be donwload from the official website.
2. I lived in Malaysia so I used the mirror that are closes to me, which is in singapore.
3. After downloaded, you can check the file signature and create a bootable drive to install it.

# Checking Signatures
# Creating Bootable drive

# Installing Arch.
ways I install arch is basically just follows their official documentation on their website.
but with a little bit of tweak. 

1. Connect to internet.
	- Following official docs, if you are connected to internet through ethernet, you are basically up and running.
	- to check if your network interface is up is by using ` ip link` command.
	- to check if you are actually having itnet connection ` ping archlinux.org`
	- to connect to wifi with no authentication
	- to connect to wifi with WEP authentication
	- to connect to wifi with WPA authentication

2. Update the system clock.
	- on official docs, you just set the ntp (network time protocol) to true using `timedatectl set-ntp true`
	- this commands will sync your arch timedate with local network timedate.
	- you can check it using `timedatectl status`
	- if somehow the status result is showing incorrect result, you can manually set you timezone using
		`timedatectl set-timezone` command.
		- you can find your time zone using `timedatectl list-timezone`.
		- in my case, i used : `timedatectl set-timezone Asia/Kuala_Lumpur`

3. Partition the disks.
	- find your disk partition information using `fdisk -l` or `lsblk` or `cat /proc/partitions`
	- information of a your hardisk can also be viewed in `/sys/block/$yourblock_name`
		- as example, I have 3 hardisk on my computer, the first is a SSD mapped as sda, and hardisks on sdb and sdc.
		- to view size of the ssd `cat /sys/block/sda/size`
			- this will return result in a 512-byte block.
			- so my 500GB ssd will return a 937721856 - bytes. so the actual size is 937721856 * 512 = 480113590272 bytes which is around 447.14 GB
		- loking inside `/sys/block/sda/` folder we notice there 5 partition in this drives which is `sda1,sda2,sda3,sda4,sda5`.
		- to look at information like size of the first partition we can `cat /sys/block/sda/sda1/size`
		- to look at the device models `cat /sys/block/sda/device/model`
	
	- So back to making a new parition.
	- using `fdisk -l` will show you the necessary information such as `Units: sectors of 1*512 = 512 bytes`
		- like I mention earlier, let say u have a 10.76GIB hardisk, it has 11552833536 bytes / 512 bytes = 22564128 sectors.
	- from the fdisk result you also know the `dislabel type : gpt`
		- GPT stand for `GUI (Globally Unique Identifier) Partition Table` 
		- a partition table is what define the partition area of your hardisk.
		- a kernel represent each partition as block device, to know where to look, they need to refer to a partition table.
		- partition table is what manage the parition inside you hardisk mapping a partition.
		- other than `GPT` there is also partition table called `MBR` stand for `Master Boot Record`.


