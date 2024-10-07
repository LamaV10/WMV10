In order to launch dwm with startx you need following dependencies:

sudo pacman -S xorg-server xorg-xinit libx11 libxft webkit2gtk

For the status you need follwing:
sudo pacman -S xorg-xsetroot

For displaying wallpapers i use:
sudo pacman -S xwallpaper

Picom:
sudo pacman -S picom

The config file that you can replace with my one is located in /etc/xdg/picom.conf

In order to identify displays you need xrandr:
sudo pacman -S xorg-xrandr

To launch dwm directly after login you need to add following line in your .bash_profile at the bottom:
startx
