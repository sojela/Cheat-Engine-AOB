# Cheat Engine AOB

A simple program that calculates an array of bytes (AOB) that matches all of the AOB in a file.

## Build

Install a C++11 compiler and make, then run make.

## Usage

Run without arguments to show help.

```powershell
./aob.exe
Usage: ./aob.exe PATH_TO_FILE
Lines begining with a "#" are ignored
```

If aob.txt is in the current folder and contains the following text.

```
a1 7f ?3 78 e0
# This line is ignored
a1 66 23 78 f0
```

Then using aob.txt outputs:

```powershell
./aob.exe aob.txt
a1 ?? ?3 78 ?0
```