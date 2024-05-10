name=$(echo $* | tr ' ' '-' | tr -d '.')
number=$(echo $name | cut -d '-' -f1)
dir=$(echo "($number + 199) / 200 * 200" | bc)
if [ ! -e $dir ]; then mkdir $dir; fi
cd $dir
mkdir $name
