# cap_readfile
This is simple demonstration of Linux capability cap_dac_read_search. The program reads the given file and prints the file content.


# 1. compile
```c++code
g++ readfile.cpp -o readfile
```

# 2. setup - YOU MUST RUN WITH ROOT USER
```c++code
./setup.sh
```
Note: The script will setup the test environment. It creates below directory and files with shown permissions
```
 drwxr-xr-x   root:root   /readall/all.txt
 drwxr-x---   root:root   /restricted/r.txt
```

# 3. check for capabilities - output shall be empty
```c++code
getcap readfile
```

# 4. Run without any capabilities - YOU MUST RUN AS NON-ROOT USER
```c++code
./readfile /readall/all.txt 	- shall show contents of hello.txt
./readfile /restricted/r.txt 	- fails with permission denied error
```

# 5. set file capabilities for readfile - YOU NEED TO RUN THIS AS ROOT USER
```c++code
setcap 'cap_dac_read_search+ep' readfile
```
Note: The capability, CAP_DAC_READ_SEARCH, bypass file read permission checks and directory read and execute permission checks;

#6. check the file capabilities - the output shall include cap_dac_read_search=ep
```c++code
getcap readfile
```
#7. run again with NON-ROOT user - both commands shall succeed
```c++code
./readfile /readall/all.txt
./readfile /restricted/r.txt
```

#8. now cleanup - YOU MUST RUN AS ROOT USE
```c++code
./cleanup.sh
```

#CONCLUSION
If the service is reading privileged directory/files, then the service can be
still run as non-root with only cap_dac_read_search. This capability bypasses
file read permission checks and directory read and execute permission checks.
