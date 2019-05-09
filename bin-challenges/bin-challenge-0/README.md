<h1>Challenge 0</h1>
<h2>Request</h2>
Connect to bin.it port 22 via SSH as user username. You will 
find the files in /home/username/mission0. 
Your goal is to <strong>read the file flag</strong> with the privileges 
of the group that owns the vulnerable binary.<br>
The executable program is compiled with the command in compile.sh.

<h2>Solution</h2>
By doing ls command it is possible to see that into mission0 folder 
there are the followinf files:
<ul>
  <li> <strong>flag</strong> --> the file that must be read in order to reach 
  the goal. <br> NB. It is not possible to modify the user privileges via 
  <em>chmod</em> neither via <em>chown</em>.</li>
  <li> mission0 file </li>
  <li> <strong>mission0.c</strong> --> file containing the vulnerable code 
  that can be exploited in order to obtain the permissions to read flag.</li>
  <li> <strong>writabale</strong> --> folder in which it is possible to save 
  useful code to exploit the challenge</li>
</ul>

The mission.c vulnerability is given by the fact that the buffer's
dimension is known and the presence of strcpy function which doesn't give any protection
against <strong>buffer overflow attacks</strong>.

In order to write a valid shellcode it is necessary to know the exact
address of the buffer. A good solution to retrieve it is to write a new file
equal to program.c.
