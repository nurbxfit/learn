import os
import argparse
import re
import click
from pathlib import Path

parser = argparse.ArgumentParser(
    description="Rename files by searching a keyword, and replace it"
)

parser.add_argument('-p','--path', type=str, metavar="", help="directory path containing file to be rename")
parser.add_argument('-k','--keyword',type=str,metavar="",help="keyword to be rename")
parser.add_argument('-r','--replace',type=str,metavar="",help="string to replace the keywords")
parser.add_argument('-t','--type',type=str,metavar="",help="type of object to rename, wether a file or (dir)ectory or (all) for both")
# parser.add_argument('-x','--regex', type=str,help="/regex/")
args = parser.parse_args()


def main():
    path = Path(args.path)
    try:
        #check if path exist
        if not path.exists():
            raise Exception('path','not exist!')
        #check if a directory
        elif not path.is_dir():
            raise Exception('path','not a directory')
        else:
            rename(path)
    except Exception as ex:
        print(ex)
        raise SystemExit()
    

def listFiles(path):
    for file in os.listdir(path):
        if args.type == "file":
            if os.path.isfile(os.path.join(path,file)): yield file 
                
        elif args.type == "dir":
            if os.path.isdir(os.path.join(path,file)): yield file 
            

def rename(path):
    for file in listFiles(path):
        key = args.keyword
        newname = file.replace(key,args.replace).strip()
        if key in file:
            print(f"\nold: {file}\nnew: {newname}\nkey: {key}")
            if click.confirm("Rename this?",default=False):
                # print ("Rename")
                os.rename(os.path.join(path,file),os.path.join(path,newname))
            else:
                print ("Not Rename")



if __name__ =='__main__':
    print(f"path:{args.path}\nkeyword:{args.keyword}\nreplace with:{args.replace}")
    main()