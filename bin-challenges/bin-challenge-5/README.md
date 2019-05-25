<h1>Challenge 5</h1>
<h2>Request</h2>
Connect to bin.it port 22 via SSH as user <em>username</em>. 
You will find the files in /home/<em>username</em>/mission5. 
Your goal is to read the file flag with the privileges of the group 
that owns the vulnerable binary.

<h2>Solution</h2>
Even though it is possible to see the code into this folder, while I 
was doing the challenge it was not available and so it has been necessary 
to find an alternative way to understand what <em>mission.c</em> was doing.<br>
In order to get it, it is necessary to enter into debug mode and disassemble 
the main function via commands written into <em>disassemble_code.sh</em>. 
The assembly code will give some informations such as the buffer dimension and
the addess associated to a push.<br>

Once the required info have been obtained the flag will be retrieved just by
writing the following command:<br>
<code>python -c "print('x60\xa0\x04\x08'* buffer dimension) | ./mission5</code>.
