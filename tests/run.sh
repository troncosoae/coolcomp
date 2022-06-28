for dir in ./*
do
    if [ -d "$dir" ];
    then 
        cd $dir
        ./run.sh
        cd ..
    fi
    echo $dir
done
