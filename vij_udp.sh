cc vij_udps.c -o s -w
cc vij_udpc.c -o c -w

./s &
./c


output()
{
 sh vij_udp.sh 
This is Client------------
This is server----------
Enter the IP address:127.0.0.1
Enter the text to be sent:asdfasdf
Succesfully sent
Received packet from 127.0.0.1:50884
Data: asdfasdf
Received packet: asdfasdf

}
