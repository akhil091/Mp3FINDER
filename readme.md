**Mp3 Finder**

About
_____

This repo contains code for mp3finder that uses a recursive approach for finding the mp3 files in directory and its sub-directory.

Operating system
________________

The program runs on unix-like OS.

Compiling and running
_____________________

The code for the mp3 file finder can be compiled using the GNU compiler like:-

g++ -o output "src_file_name.cpp"
-----------------------
And can be run using:-

./output
-------

Using the program
_________________

The user is prompted to enter the directory from which to start finding the mp3 files. Absolute or relative path should be entered. If failed to open the directory, it shows an error.

If successful it shows the names and paths of the files that it found in following format:-

"abc.mp3"    "path_of_abc.mp3"
"pqr.mp3"    "path_of_pqr.mp3"
"xyz.mp3"    "path_of_xyz.mp3"
.
.
.
.
and so so.

License
_______

It contains MIT license, for details see the License.txt

