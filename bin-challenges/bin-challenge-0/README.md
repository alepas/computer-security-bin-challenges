<h1>Challenge 0</h1>
<h2>Request</h2>
Connect to bin.it port 22 via SSH as user username. You will 
find the files in /home/username/mission0. 
Your goal is to <strong>read the file flag</strong> with the privileges 
of the group that owns the vulnerable binary.<br>
The executable program is compiled with the command in compile.sh.

<h2>Solution</h2>
By doing <em>ls</em> command it is possible to see that into mission0 folder 
there are the following files:
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
dimension is known and the presence of strcpy function which doesn't give any 
protection against <strong>buffer overflow attacks</strong>.

In order to write a valid exploit it is necessary to:
<ul>
  <li>know the exact address of the buffer. A good solution to retrieve 
  it is to write a new file equal to program.c by doing the commands 
  in obtain-buffer-addr.sh.</li>
  <li>know the exact dimension for which the buffer generates a Segmentation
  Fault. To do it applay the following command:<br>
  ./mission0 print('A'*number<=856) ""<br>
  NB. the "" into the command are necessary because of the first check into
  the main function.</li> 
  <li>find a shell code such as the following:<br>
  \x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb\x16\x5b\x31\xc0\x88\x43\x07\
  x89\x5b\x08\x89\x43\x0c\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd\x80\xe8\xe5\
  xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68</li>
</ul>

Once all the elements have been found, write and execute the code into shell.c.<br>
It retrieves the secret code written into the flag file.


</ul>

