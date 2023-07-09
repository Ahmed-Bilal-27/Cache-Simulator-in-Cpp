# Cache-Simulator-in-Cpp
This was my semester project for course Operating Systems. It was implemented in C++ and executed on Ubuntu Operating System.

1. Implemented cache using structure ‘cacheTable’ with following 4 block placement strategies:

    1.1. Direct Map with 3rd command line argument of ‘1’.
    1.2. 2-Way Set Associative with 3rd command line argument of ‘2’.
    1.3. 4-Way Set Associative with 3rd command line argument of ‘4’.
    1.4. 8-Way Set Associative with 3rd command line argument of ‘8’.

3. Block/Memory addresses/references were read from ‘samples.txt’ text file. To access the values in sample file the 'samples.txt' must be present in the same directory in which the cpp file resides or you should put the required path in the code.

4. The File Stream ‘fstream’ library was used to read from file.

5. The lines read from the file are stored in a number which is converted into binary which is then used to separate ‘tag’ and ‘index’ bits and convert them back into decimal accordingly. These values were used for block identification.

6. All Block Placement strategies are working correctly with number of hits increasing with increase in associativity and
                                  miss + hits = Total No. of entries in the text file
