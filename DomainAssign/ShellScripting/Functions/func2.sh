diskusage()
{
	echo "disk usage space" df echo "\ndisk usage space in human readable"
	df -h;
	echo "\nfile usage space"
	du -sch;
}

diskusage
