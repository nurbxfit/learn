from pathlib import Path

path = Path() #by default it is current directory.
print(path.absolute()) # print absolute path.

# CRUD directory
testFolder = path / 'testDir' # create new path ./testDir
testFolder.mkdir() # make path into directory
testFolder.rename("testFolder") # rename directory

# Deleting using rmdir or unlink
# testFolder = path / "testFolder"
# testFolder.rmdir() # remove it
# testFolder.unlink()

# list files using iterdir
dirList = [ p for p in path.iterdir()] # shothands for p in path.iterdir(): return p
print(dirList)

# get file with specific patterns
pyFile = [p for p in path.glob("*.py")]
print(pyFile) # result: [PosixPath('main2.py'), PosixPath('main.py')]

# get file with specific patterns recursively
pyFile = [ p for p in path.rglob("*.py")]
print(pyFile)