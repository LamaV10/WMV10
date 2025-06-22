# Installation and Setup of dwm

In order to launch dwm with startx you need following dependencies:
```
sudo pacman -S xorg-server xorg-xinit libx11 libxft webkit2gtk
```
After that you can go into the dwm-6.5 folder and enter:
```
sudo make clean install
```
For the status you need follwing package:
```
sudo pacman -S xorg-xsetroot
```
For displaying wallpapers with xwallpaper:
```
sudo pacman -S xwallpaper
```
Picom installation:
```
sudo pacman -S picom
```
The config file that you can replace with my one is located in /etc/xdg/picom.conf

In order to identify your display output you need xrandr:
```
sudo pacman -S xorg-xrandr
```
To launch dwm directly after login you need to add following line in your .bash_profile at the bottom:
```
startx
```

Don't forget to copy the .xinitrc file into your home directory
