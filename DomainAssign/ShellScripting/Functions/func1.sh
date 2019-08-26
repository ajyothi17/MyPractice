sampleFunc()
{
	echo "inside function"
	ls -l;
	ps;
}

echo "before function call"
sampleFunc
echo "after function call"
