#Monitor Setup
xrandr --output DisplayPort-0 --off --output DisplayPort-1 --off --output DisplayPort-2 --mode 2560x1440 --pos 0x614 --rotate normal --output HDMI-A-0 --mode 2560x1440 --pos 2560x0 --rotate left

#Background
xwallpaper --output DisplayPort-2 --stretch /home/marcel/Pictures/Wallpaper/Horizontal/Porsche911Sunset.jpg
xwallpaper --output HDMI-A-0 --stretch /home/marcel/Pictures/Wallpaper/Vertical/CadOld.jpg

#time
while true; do
	xsetroot -name "Vol:$(pamixer --get-volume)% | Date:$(date +"%F %R")"
	#follwing for laptops
#	xsetroot -name "Bat:$(cat /sys/class/power_supply/BAT1/capacity)% | Vol:$(pamixer --get-volume)% | Brightness:$(brightnessctl g) | Date:$(date +"%F %R")"
done &

#st transparency
picom &

exec dwm
