from pathlib import Path
from time import ctime

path = Path()
print(path.absolute())

myobj = path.with_name('main.py')
print (myobj)

# return all file in dir, get their stats->creation time, pass to ctime function 
mylist = [ctime(p.stat().st_ctime) for p in path.glob("*.py")]
print(mylist)
