
dir1=$PWD 

echo $dir1

dir2=/home/r/plan10/

cd $dir2

echo $PWD

javac seq1.java
java seq1 $dir1/schedule16.txt

cd $dir1
pdflatex schedule16.tex
