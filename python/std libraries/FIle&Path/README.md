# Python Path library.

- this lib, create filesystem path object.
- usefull for manipulating filesystem, without actually accessing the OS.
- [reference]('https://docs.python.org/3/library/pathlib.html)

## Basic.

- create a path

```py
from pathlib import Path

home = Path('/home/jun') #my home directory path
download = home / 'Downloads/' # create new path for Downloads folder

print(download) # path is /home/jun/Downloads
```

- basic path methods

```py
#checking if path exists
print (download.exists()) # True

#check if path is file or directory
print(download.is_file()) # False
print(download.is_dir())  # True

# get path parent
print(download.parent) # /home/jun

# get file with specific name
textfile = download.with_name('file.txt')

#check if it is a file
if textfile.is_file:
    # print name
    print(textfile.name) # return path name (file.txt)
    print(textfile.stem) # return path name without extension (file)
    print(textfile.suffix) # return path name extension. (.txt)

# Get the absolute path (full path)
print(textfile.absolute())
```

- manipulating folders and directories.

```py
from pathlib import Path

path = Path() #by default it is current directory.
print(path.absolute()) # print absolute path.

# CRUD directory
testFolder = path / 'testDir' # create new path ./testDir
testFolder.mkdir() # make path into directory
# testFolder.rename("testFolder") # rename directory

# Deleting using rmdir or unlink
# testFolder = path / "testFolder"
# testFolder.rmdir() # remove it

testFolder.unlink()

# list files using iterdir
dirList = [ p for p in path.iterdir()] # shothands for p in path.iterdir(): return p
print(dirList)

# get file with specific patterns
pyFile = [p for p in path.glob("*.py")]
print(pyFile) # result: [PosixPath('main2.py'), PosixPath('main.py')]

# get file with specific patterns recursively
pyFile = [ p for p in path.rglob("*.py")]
print(pyFile)
```

- Getting File Information.

```py
from pathlib import Path
from time import ctime

path = Path()
file1 = path.with_name('main.py')
print(file1.stat())
```
