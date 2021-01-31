This is a demo for how to create a custom icon for your c program
Here, I have used MinGW to compile my program
* * *
### STEPS
* * *
1. Write the code. --> "custom_icon.c"
2. write the resource file (.rc) --> "resources.rc"
3. make object with `windres` program in windows
```
windres resources.rc -o resources.o
```
4. compile the code with the object file
```
gcc custom_icon.c resources.o -o helloworld
```
