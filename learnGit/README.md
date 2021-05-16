# Basic Command.

- `git pull`
- `git push`
- `git commit`
- `git branch`
- `git add`
- `git stash`
- `git status`

# Creating and Initialize Git repo.

- simply create a project folder
- initialize folder using `git init` command.

```
mkdir myProject && cd myProject && git init
```

# Git worksflow.

- Git workflow consist of 3 stages, or states.

  1. working directory.
  2. Staging area
  3. Repository (.git folder).
  4. Remote Repository (Github /Gitlab)

- working directory is the folder we are working, we make change in it.
  - we write and make changes here.
  - we initialize our working directory using `git init`
- Staging area holds the information of our current commit and our next commit.

  - we enter here when we use the `git add` command.
  - this is a stage where we decided what to commit before we actually commit.
  - here we can decided, let say we want to make other changes and don't want to commit it yet, but we want to keep it somewhere so it will not interfeer with our changes. to stash away our changes we can use `git stash` command.
  - Using `git stash` we can create a clean tree for our new changes.
  - we can latter re-apply our previously stashed changes using `git stash apply` or `git stash pop`.

- Local Repository (.git).

  - our changes information are stored here when we commit it using `git commit`

- Remote Repository.
  - when we use `git push` our local repo get sync with our remote repo.
  - we can also specify which origin we want to push to `git push <name>`
  - or we can also specify the branch `git push <name> <branch>`
  - we specify our remote repo by using `git remote add <name> <url>`.
    - this will create an entry in our `.git/config` file.
  - to view our remote repo information we can use `git remote -v`
  - or we can also use `git remote show <name>`
  - we can remove our upstream origin using `git remote rm <name>`
    - this will delete the remote repo, and we'll not use it to `git push` to remote.
    - if we simply want to rename it we can use `git remote rename <oldname> <newname>`

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

  - to view changes u've made, you can use `git status`.
  - git status will tell you information such as our current branch
  - our commit, changes and untracked files.
  - changes files is the files that we recently make changes and not yet add it to stages for commit.
  - untracked files is new file we added, and git have no previous knowledge of it.
  - to add file to stages we use `git add` command to add the changes to the git indexs.
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

## Basic Staging.

### Removing from stages

- let say we modified a file README.md,
- in it we write "Hello World" and perform the first commit.
- then we edit it adding new line "This is first line"
  and use `git add` to move our changes to stages before we commit it.
- let say before we commit it, we changed our mind, and decided to not commit it.
  - we can `remove` it from stage using`git reset HEAD`
  - `git reset HEAD` will only remove our changes from staging.
  - if we use `git status` we will see it as changes not staged.
  - our working file, still have that changes.
  - if we view the content of the README.md file we will see
  ```
  Hello World
  This is first line
  ```
  - if we want to remove the changes from our working file and revert our code to the previous state before we edit and put to stages (means we want to be same as our previous/current commit).
  - we can use `git checkout -- README.md` or `git reset --hard HEAD`.
  - then if we view our file we only see
  ```
  Hello World
  ```
  - because it is the content of our current commit HEAD.

## Basic Commit and checkout.

- few ways to create a commit.

  - `git commit -am "Our commit message"`
    - this `-a` will add all our working files to stages and perform a quick commit specifying our message using `-m`.
    - this will work for modified files, if we have new unracked file, we need to `git add` it manually to stages.
  - `git commit`
    - this will open up our default text editor to write a commit message
  - `git commit -m "Our Commit message"`
    - this will commit our current stages file and specify message using `-m`

- we can view our commit history using `git log` command

  - this will show information such as our commit id (SHA1), Author, date and commit message.

  ```
  commit f2cfd8c9b4d4b1077d5b1c67d0ed6286c0b9af64
  Author: nurbxfit <myemmail@gmail.com>
  Date:   Sun May 9 03:17:42 2021 +0800
  ```

- checkout

  - let say we write our code project, and perform multiple commit.
  - then we decided, we want to revert back to previous commit that we made.
  - we can do this using `git checkout <commit SHA1 id>`
  - this will checkout our working directory to that particular commit history.
  - let say, we create `README.md`, write "Hello World" and commit it.
  - then we edit it and write "First line" and commit it.
  - then we edit it some more and write "Second line" and commit it.
  - then we write something in it, and decided, we want to start over when we write "Hello World".
  - to revert back we can use `git log` to view our commit history.
  - there we can see our first commit for our "Hello World", using it SHA1 ID.
  - we can checkout to it using `git checkout <SHA1ID>`. this will checkout to a branch of that particular commit.
  - then when we open our README.md, we only see "Hello World" and no other lines.
  - this new branch it called a detached HEAD, it is detached from out main tree.
  - we can view the content of this particular commit, and we can create it as a new branch in our main tree using `git switch -c <new-name>`.
  - if we want to undo our changes, we can use `git switch -`
  - if we exidentally commit and not making new branch (means we let it dangling)
  - we can find it back using `git fsck --lost-found` command.
  - it will output SHA1 of dangling commits we done,
  - then we can create new branch using `git branch <new-name> <SHA1>`

- reset.

  - unlike checkout using `git reset --hard`, we will not checkout into new branch, but instead will remove file from staging, reset current working directory.
  - like checout, to reset our working code to particular point, we can use `git reset`
  - `git reset HEAD` will reset our code to our HEAD (our current commit) incase we make changes in working directory and stage it, but we want to fully revert it.
  - `git reset HEAD^`, append `^` symbol will going back 1 commit before HEAD.
  - `git reset HEAD~2`, will go back 2 commit before HEAD, change 2 with other number.
  - `git reset HEAD@{1}` will undone our reset / mean reset to one HEAD front instead of one HEAD before.

## Basic Git Logs.

- we use git logs to see the history of our commit.
- this command show usefull information for each commit such as the author, date, commit message and SHA1 of our commits.
- we can also perform various output filter to show different style of information.
- `git log --graph --decorate`, will create a graph view of our commit
- `git log --oneline`, will show commit info in one line, without extra info.
- `git log --all`, show commit for all branches.
- we can combine these filter toger such that `git log --graph --decorate --oneline --all`
