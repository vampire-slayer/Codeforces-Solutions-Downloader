# Codeforces Solutions Downloader
It is a tool built using Shell script and C to download any user's non-Gym accepted solutions on Codeforces. It has been built primarily for Linux.
## Running the tool
Place 'run.sh', 'parse.c' and 'fix.c' in the directory where you intend to keep the downloaded solutions.
### Run the following commands:
`chmod +x run.sh` (Makes the script executable)

`./run.sh username` (Runs the script, replace 'username' with the user's handle whose solutions you intend to download)


*The downloaded solutions get saved in a directory called 'Codes' inside the directory from where the script was executed.*

*The solutions get saved in the format 'ContestId_ProblemID.extension'. For example, 776_D.cpp is a possible filename.*


In order to use it with proxy, add `export http_proxy="http://username:password@host:port"` to the beginning of 'run.sh'.
