for case in {1..2}
do
    MIN=1
    MAX=$(($case == 1 ? 2 : 5))
    for (( type=$MIN; type<=$MAX ; type++ ))
    do
        echo "Case $case - Type $type:"
        for ((i=200; i<=4000; i+=200))  
        do  
            python3 graphGenerator.py "$i";
            bash time.sh "$case" "$type" "$i"
            rm -r "../input/graph$i.txt";
        done 
    done
done