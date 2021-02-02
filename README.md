# Web-Path-BruteForcer-cURL
#### A simple Web Path Bruteforcer using C++ Request: [cURL](https://github.com/whoshuu/cpr) for People wrapper built on top of [libcurl](https://curl.se/libcurl/). 

##### The CLI interface accepts these from the user:

• Webapp urls(can be multiple, space seperated)<br>
• A file containing a list of webapp paths that need to be brute forced against the specified<br>
• List of success status code according to user<br>

##### Sample Input:<br>

Webapp urls: https://www.github.com<br>
Webapp paths: (sample 5 lines out of the input file wordlist.txt)<br>

• admin<br>
• info<br>
• .git/config<br>
• .htaccess<br>
• backup.zip<br>

Success status codes(needs to be space seperated): 200 302<br>

##### Sample Output:

A list of URLs that responded with any of the success status codes as provided in
the input by the user.<br>

• https://www.github.com/info [Status code 302]<br>
• https://www.github.com/.htaccess [Status code 200]<br>

## Usage:

1) Clone repo to local machine.
2) Go to '[release](Release/)' folder.
- By default there is '[wordlist.txt](Release/wordlist.txt)' file containing wordlist which can be replaced with another text file having same name.
3) Run BruteForce.exe.

## Screenshot

<img src="images/bruteforce.png">
