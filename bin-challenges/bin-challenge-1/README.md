<h1>Challenge 1</h1>
<h2>Request</h2>
Connect to bin.it port 22 via SSH as user <em>username</em>. You will find the files in /home/<em>username</em>/mission1. Your goal is to read the file flag with the privileges of the group that owns the vulnerable binary.
The executable program is compiled with the commanda into compile.sh file.

<h2>Solution</h2>
By doing <em>ls</em> command it is possible to see that into mission1 folder 
there are the following files:
<ul>
  <li> <strong>flag</strong> --> the file that must be read in order to reach the goal. <br> 
  NB. It is not possible to modify the user privileges via <em>chmod</em> neither via <em>chown</em>.</li>
  <li> mission1 file </li>
  <li> <strong>mission1.c</strong> --> file containing the vulnerable code that can be exploited in order to obtain the permissions to     read flag.</li>
  <li> <strong>writabale</strong> --> folder in which it is possible to save useful code to exploit the challenge</li>
</ul>

The mission.c vulnerability is given by the fact that the buffer's dimension is known and the presence of fread function which doesn't give any protection against <strong>buffer overflow attacks</strong>.

In order to write a valid expoit look at the README.md file of <em>Challenge 0</em>, in fact this challenge is really similar to it and it can be solved by applying the same procedure. Anyway I have added also the program.c and shell.c file in order to let you better understand this specific case.

<h3>Some notes</h3>
<ul>
  <li>If it goes in Segmentation Fault, modify a little the buffer address. The buffer address is \xnn\xn<strong>N</strong>\xnn\xnn, it   can be modified by adding 2 or 4 to the bold char. </li>
  <li>A difference from <em>Challenge 0</em> is given by the fact that there is no check on the argc so it is not necessary to care about     it. </li>
</ul>


