echo "Enter your link here: "
read link
yt-dlp -x --audio-format mp3 $link
