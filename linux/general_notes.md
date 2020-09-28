# Arch General Notes:

# 1. Pacman
- install: `pacman -S package-name`
- search: `pacman -Ss package-name`
- uninstall: `pacman -R package-name`
- uninstall: `pacman -Rs package-name` ; this will also any unused dependencies.
- show installed: `pacman -Qe` 

# 2. Display output
- display all available display output: `xrandr`
- output on a display : `xrandr --output HDMI-0 --auto --left-of DVI-D-1`

# 3. Audio Manager.
- install pulseaudio driver.
- GUI (Qt based) control using: `pavucontrol-qt`

# 4. Window manager
- i3 window manager.
- i3status for i3 bar status.
- configuration file for i3 :` ~./config/i3/config`
- configuration file for i3status:` ~./config/i3status/config`

# 5. File Manager:
- vim base file manager using: ranger.
- ranger config: `ranger --copy-config=all`
- default config path:` ~./config/ranger/`
- `rc.conf` : startup and key binding.
- `commands.py` : command launched using `:`.
- `rifle.conf` : default apps to use when open a file extension. (like open with).
- delete file (move to trash) : `DD` just like in vim. (must edit tthe rc.conf key binding).
- example in `rc.conf`: `map DD shell mv %s /home/$(USER)/.local/share/Trash/files/`.
- view trash using: `:gio list trash://`.

# 6. General Partition mounting.
- list block devices : ` sudo lsblk -o name,fstype,mountpoint,label,partlabel,size,uuid`
- manual mount using: `mount -t ntfs /dev/sdc3 /run/media/jun/Data -o umask=0022,gid=OwnerGroupID,uid=ownerID`
  - gid and uid we can get using: `id` command.
  - umask value using : `umask` command. 
- auto mount on boot: edit `/etc/fstab` adding: `UUID=C826B95A26B949E8   /run/media/jun/Data     ntfs    defaults        0 2`
- other auto mount util: `udiskctl` 

