# Setup project

mkdir build
cd build
cmake ..
cmake --build .
clear
./proj2 --help 

# Testing each case with graph 10

echo ""
echo "Case 1.1"
./proj2 1 1 graph10.txt 1 10

echo ""
echo "Case 1.2"
./proj2 1 2 graph10.txt 3 10

echo ""
echo "Case 2.1"
./proj2 2 1 graph10.txt 1 10 6

echo ""
echo "Case 2.2"
echo "Initial capacity and paths:"
cat "../input/input10.txt"
echo ""
echo "New capacity: 9"
./proj2 2 2 graph10.txt 1 10 9