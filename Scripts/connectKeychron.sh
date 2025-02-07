timer=10

while [[ $timer > 0 ]]; do
  echo $timer
  sleep 1
  timer=$((timer - 1))
done

# connect keychron k3p
bluetoothctl connect 6C:93:08:68:91:A1
