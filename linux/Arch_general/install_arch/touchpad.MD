## Enabling Laptop Touchpad in Arch Linux.
1. Install touchpad driver using `pacman -Sy xf86-input-synaptics` 
2. In arch linux website, it is advised to use libinput instead of xf86-input-synaptics, 

## Enable two finger touch for right click,
1. you can either configure it with the file in `/etc/X11/xorg.conf.d/70-synaptics.conf`
example:
```
Section "InputClass"
    Identifier "touchpad"
    Driver "synaptics"
    MatchIsTouchpad "on"
        Option "TapButton1" "1"
        Option "TapButton2" "3"
        Option "TapButton3" "2"
        Option "VertEdgeScroll" "on"
        Option "VertTwoFingerScroll" "on"
        Option "HorizEdgeScroll" "on"
        Option "HorizTwoFingerScroll" "on"
        Option "CircularScrolling" "on"
        Option "CircScrollTrigger" "2"
        Option "EmulateTwoFingerMinZ" "40"
        Option "EmulateTwoFingerMinW" "8"
        Option "CoastingSpeed" "0"
        Option "FingerLow" "30"
        Option "FingerHigh" "50"
        Option "MaxTapTime" "125"
        ...
EndSection

```
2. second methods is by using `synclient`, 
 - using `synclient -l` to list our touchpad options.
 - to enable douple tap for rightclick `synclient TabButton2=3`
 - to enable single tab for leftclick `synclient TabButton1=1`
