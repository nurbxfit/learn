# Basic Command.
- `git pull` 
- `git push`
- `git commit`
- `git branch`
- `git add`
- `git stash`
- `git status`

# common usecase.
- when you collabs with a remote repositories, u first need to copy/clone that remote repo into your local repo.
- to do that, you need to clone that from the remote repository.
- take this repo as example:.
    - the commands is `git clone` and append the url of the repo.
    - `git clone https://github.com/nurbxfit/learn.git`
    - this will clone that remote repo into your local.
    - you can now start making changes to the file.
    - to sync with the remote server, instead of re-cloning the repo, you just need to pull changes made to the repo using `git pull` command.
    - let say you want to sync with the master branch of the repo:
        - `git pull origin master`
        - if you want to use other brach, simply replace master with the name of that branch.
        - `git pull origin deployment`, this example sync with the deployment branch.
- After u made a changes to a file, you must add that changes to your local repo,
    - to do that you use `git add` command to add the changes to the git indexs.
    - `git add` is in a staging state where it add your files to the index of changes u made before you commit it to local repo. 
    - let say u want to add all file into the local repo, u can append `.` at the end to indicate all file inside current directory.
    - `git add .`, 
    - or if you want to add specific file that u made changes named `index.js`, u can add it like this `git add index.js`
    - then after add you changes to the index, you need to commit your changes into the local git repo in your system.
    - the command used is `git commit -m "myCommit Message"`, without using `-m` argument, you will be prompt to add a commit message before you can continue commit to local repo.
    - alternatly u can use `git commit -am "My Commit Message"` to combine both the `git add` and `git commit` operation into single operation.

- After commited your changes into your local repo, you can sync your changes with the remote repo by pushing your local repo into the remote repo.
- the command is `git push origin master`
- to push into a branch simple change the `master` branch with other branch name.

# Merge Conflic use case.
- let say you are in collaboration with other developer.
- you currently editing a file, the other developer also did the same with the same file, 
- then the other developer make changes and push it into the remote repo.
- now your repo is currently not in a `clean state` because u r not sync with the latest changes of the remote repo. 
- if u are not yet commit ur changes, but u try to sync with the remote repo using `git pull`, u will probably encounter with an error asking you to first commit your changes into your local git or stash them (remove your changes) and revert to the clean state.
- to overcome this, u first need to commit your changes into your local git using `git commit -am "your commmit message"`
- then try to sync again using `git pull origin master`
- incase you don't want to commit your changes and want to rever to the `clean state` you can use `git reset --hard` command to reset your files. 

- sometimes when you perform a pull request, you will get a `Merge Conflict` error, asking you to fix the conflicst.
- it will usually tell you the problem is on which files. 
- to resolve the conflict, open that file, and you will see something like this...
```
<<<<<< HEAD
Your code in local repo
======
Your partner code from remote repo
>>>>>> somerandomlongnumberandletters_indicating_the commit id
``` 

- to resolve this conflic, you can just remove the metadata ( the arrow, the equal sign, the HEAD and the random string ), then remove the part of the code that don't want, and kept the code that you want, let say your partner code is better. you simply delete the rest and kept your partner part.

```
Your partner code from remote repo
```
- noticed that, all the metadata and your code is missing from the file.
- then perform a commit `git commit -am "conflic resolved"`
- then push it to the remote repo : `git push origin master`