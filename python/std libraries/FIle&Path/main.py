from pathlib import Path

home = Path('/home/jun') #my home directory path
download = home / 'Downloads/' # create new path for Downloads folder


print(download) # path is /home/jun/Downloads

#checking if path exists
print (download.exists())

#check if path is file or directory
print(download.is_file())
print(download.is_dir())


# get path parent
print(download.parent) # /home/jun

# get file with specific name
textfile = download.with_suffix('file.txt') # there is file called file.txt in my Download Folder

#check if it is a file
if textfile.is_file:
    # print name
    print(textfile.name) # return path name (file.txt)
    print(textfile.stem) # return path name without extension (file)
    print(textfile.suffix) # return path name extension. (.txt)

    # Get the absolute path (full path)
    print(textfile.absolute())