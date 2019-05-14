<h1>Challenge 3</h1>
<h2>Request</h2>
Connect to bin.it port 22 via SSH as user <em>username</em>. 
You will find the files in /home/<em>username</em>/mission3. Your goal 
is to read the file flag with the privileges of the group that owns the 
vulnerable binary.

<h2>Solution</h2>
The code into mission3.c is equal to mission1.c, but this doesn't mean that
it can be solved in the same way. Actually, what is different, is the compile command:
it doesn't contain the <em>-z execstack</em> element which is the one that, in Challenge 1, 
has allowed to modify the stack. Because of the different compile.sh the technique used to 
solve Challenge 1 can't be used here.

The vulnerability is, of course, the same into Challenge 1 but, in order to expolit it,
are required the system address, the exit address and the address of a global variable
which contain lots of spaces and "cat flag" command.<br>
In order to the get the first two addresses it is necessary to enter into the debugger
mode and follow the command into system-exit-addresses.sh file.<br>
Then, once the first two elements have been found, follow the command into egg.sh file. <br>

The last step, in order to get the flag's secret, is into the final-exploit.sh.
