                                                             MINI TORRENT
 
PART1
.............................CREATING MTORRENT.....................................

1..Creating mtorrent ...It will automatically be created while sharing a file in Part3.

FORMAT of mtorrent:-
TRACKER URL1
TRACKER URL2
FILENAME
FILESIZE
SHA

2.Access any mtorrent as <file_name>.mtorrent


PART2
................................TRACKER...............................................
1.Start Tracker as..
./server_2018201001 10.42.0.394:4444 10.42.0.666:5555  seeders.txt  mylog.log

Note:- It is always running.......

PART3
................................Client................................................
This part utilizes both PART1 and PART2.There are several commands that are implemented in this and the way to access those commands are as follows:-

1.SHARE
.............
If client want to make itself seader of some file than it can be done by uploading its file in seader list by using this command.

COMMMAND: share <file_name> <file_name>.mtorrent

2.GET/DOWNLOAD
..............
In order to download a file from remote server client can use this command.
It must also noted that after download client automatically become seader of that file that it has currently downloaded.

NOTE:-> It is assumed that mtorrent is already with the client.

COMMAND: get <file_name>.mtorrent destination_path

At the end of downloads it also update the seeders list.

3.REMOVE
................
If client want to remove any file it was previously sharing can use this command.

COMMAND: remove <file_name>.mtorrent

4.CLOSE
................
If client want to close its connection it can use this command.
It must also be noted that when client rejoin the network all ots mtorrent are again loaded in seeder list.

COMMAND: close


5.SHOW_DOWNLOADS
..................
In order to see the list all files that are downloaded till now client can use this command.

COMMAND: show_downloads


ASSUMPTION::::
1.It is done only with single tracker.
2.It is communicating with multiple seeders but taking file only from one.
.................................................xxxxxxxxxxxxxxxxxxxxxxxxxxxxx............................................................

