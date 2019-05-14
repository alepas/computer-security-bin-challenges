<h1>Challenge 7</h1>
<h2>Request</h2>
Connect to bin.it port 22 via SSH as user <em>username</em>. 
You will find the files in /home/<em>username</em>/mission7. Your goal is to 
read the file flag with the privileges of the group that owns the vulnerable binary.

<h2>Solution</h2>
In order to exploit the code of this challenge it is interesting to notice 
that it is not necessary to know, as in all other cases, some addresses or the buffer dimension
and it is also not necessary to use some shellcode.<br>

Everything is based on the Switch-case which is formed by 4 steps associated to 4 different functions.
The interesting stuff is given by the fact that both the set_format and the set_time_zone() functions 
uses the <em>free()</em>. It is known that, although the free deallocates the memory previously allocated by a call to
malloc, it doesn't change the address. <br>
By analyzing the functions it is possible to see that:
<ul>
  <li><strong>set_format()</strong> function contains some restrictions which to
  not allow to put some chars that are contain into the <em>"cat flag"</em> command;</li>
  <li><strong>set_time_zone()</strong> function doesn't contain any restriction so it
  can be the best input to put the exploit;</li>
  <li> is it necessary to pass trhough all the Switch-Case stages in order to 
  obtain a valid end situation.</li>
</ul>

To retrieve the secret follow the commands into the exploit.sh file.