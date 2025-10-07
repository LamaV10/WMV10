clear
echo "Hotspot"
hostname=T460

echo "Current hostname: $hostname"
printf "\nChoose an option:\n"
printf "1: Start Hotspot\n2: Stop Hotspot\n3: Change Hostname\n"
printf "4: Show connections\n5: Delete connection\n\n"
read option

if [ $option -eq 1 ]; then
    nmcli device disconnect wlan0
    # check if this connection already exists
    if ! nmcli connection show | grep -q $hostname; then
	echo "Make connection..."
	sudo nmcli connection add type wifi ifname wlan0 con-name $hostname ssid $hostname
	sudo nmcli connection modify $hostname 802-11-wireless.mode ap 802-11-wireless.band bg ipv4.method manual ipv4.addresses 10.42.0.1/24 wifi-sec.key-mgmt wpa-psk wifi-sec.psk sudoFortnite
    else
	echo "Connection already exists!"
    fi
    sudo nmcli connection up $hostname
    echo "Start DHCP..."
    sudo dnsmasq --interface=wlan0 --bind-interfaces --dhcp-range=10.42.0.10,10.42.0.100,12h
    echo "Network Ready!"

elif [ $option -eq 2 ]; then
    echo "Shutting down connection..."
    sudo nmcli connection down $hostname
    sudo pkill dnsmasq
    echo "Done!"

elif [ $option -eq 3 ]; then
    echo "Your desired Hostname: "
    read hostname
    sed -i "3s/.*/hostname=$hostname/" hotspot.sh

elif [ $option -eq 4 ]; then
    nmcli connection show

elif [ $option -eq 5 ]; then
    echo "Name of connection you want to delete: "
    read name
    sudo nmcli connection delete $name
fi

