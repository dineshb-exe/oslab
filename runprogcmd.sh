namer=$1

i=1
j=0
exefile=${namer%.*}
mainpicture=$exefile
for var in "$@"
do
	if [ $j -ge $i ] 
	then
		mainpicture+=" "
		mainpicture+=$var
	fi
	j=$(($j+1))
done
gcc -o $exefile $namer
./$mainpicture
