osascript -e 'tell application "iTerm2"
    set newWindow to (create window with default profile)
    tell current session of newWindow
		set rows to 10
		set columns to 45
		write text "cd \"$(ls -R | grep \"/hohow/srcs\" | sed \"s/://\")\""
		write text "echo -n -e \"\\033]0;НУ И КАК ТАМ В ЕГИПТЕ?\\007\""
		write text "afplay Uncle.mp3 &"
		write text "imgcat 1.jpg 2.jpg 3.jpg 4.jpg 5.jpg"
		write text "sleep 2"
		write text "exit -f"
    end tell
end tell'