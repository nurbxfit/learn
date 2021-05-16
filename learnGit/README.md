# Basic Understanding.

- git is a version control tools, it is a timeline of our works to a file.
- basically it tracks our works as a milestone every time we commit it.
- let say we want to write a book, we wrote few chapters 1 - 3 then we commit it. git will create index information about what we've done.
- then we decided to change the name of our main character From Bob to Harry.
- we make a change save it and commit it. git will also keep track of this changes.
- then later in future we want to revert back changing our character name from Harry to Bob.
- we can easily refer to our previous commit, and revert back the changes.
- basically git keep tracks of modification that we made to our projects, whether we write a text documents, a code or simply indexing file changes or in an out of a folder.

### Git work flow.

- Git workflow consist of 3 or 4 stages/states.

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

## Commits.

- commiting is like giving a tags, or pin a point to a particular changes in our development timeline.
- this particular point will be index by the git system.

## Branching.

- our main timeline is called the master or main repository.
- branching is like diverging from the main stream or main timeline.
- this will create a copy with history of our main timeline and we can future create new features from here.
- when we create a branch, the main timeline diverge into the branch of it.
- the branch can move on creating their own timeline but still have a the origin point connected to the main timeline.
- the main timeline can also continue future making it timeline.
- these branches can latter merge back into the main timeline.

## Forking.

- forking is making the copy of a repository.

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

# Basic Branching and Merger.

## Branching.

- we can list our branches using `git branch` or `git branch -a`.
- this will usually list the branches and highly current branch in green with asterik `*`.
- to create new branch we can use `git branch <branch name>`
- alternatively we can create using `git checkout -b <branch name>`
  - this will create our new branch and automatically checkout to that branch.
- to delete a branch we can use `git branch -d <branch name>`.
- to switch branch we can use `git checkout <branch name>`

## Merging.

- after we made a edit or update a features in our branch, we can merge it our the main branch.
- to merge to master, we fisrt change our branch to the master using `git checkout master`.
- then from master, we merge using `git merge <branch name>`.
- if there's no conflict with the changes made, those changes will be applied automatically to the main branch.
  - this usually happen in `fast foward merge` where, master have no commits ahead of the branch.
  - where the branch is ahead of master.
  - it simply takes the commits made by the branches and applied as the commits in master.
  - the result is merged commits in both branch and master will have same SHA1 commit ids.
- problem can happen when there's conflicts.

  - let say in new branch we edit in line 20 and commit it.
  - in other branch we also edit it line 20 and commit it.
  - then we want to merge these two branch together, and conflict will occured because git have no idea which changes we want to kept or remove.
  - example output of `git log --oneline --all`

  ```
  jun@null:~/Developer/LearnGit/test$ git log --oneline --all

  3b16cc5 (HEAD -> new-detach-v2) Conflic update
  e4f38ee (newBrach) Bad Commit
  1630ba0 resolve conflict
  330d596 (prev-detached) new line in detached branch
  157de9a (new-detach, new) Second line new branch
  99c7935 New line new branch
  e85642a (master) Fourth Commit
  fa3a2e7 Third Commit
  4482d66 second commit
  86bdb69 First Commit

  ```

  - `newBranch` diverge from `new-detach-v2` branch.
  - `newBranch` made a `Bad commit`.
  - so in git log timeline, newBranch `Bad Commit` is ahead of it's master which is `new-detach-v2`.
  - then in `new-detach-v2` we also create a new commit called `Conflic update` making changes as the same line.
  - so `new-detach-v2` is now one commit ahead of `newBranch`.
  - when merging these two branches, a error called `Merge conflicts` will occured.
  - and we have to manually fix the conflicts to merge it.
  - we can view more information about the conflict using `git status`.
  - if we want to abort the merge we can use `git merge --abort`
  - after a succesfull merger, we can see in `git log`, that our branches are pointing to the same commit id.

  ```
  jun@null:~/Developer/LearnGit/test$ git log --oneline

  6e89149 (HEAD -> new-detach-v2, newBrach) resolve conflict
  3b16cc5 Conflic update
  e4f38ee Bad Commit
  1630ba0 resolve conflict
  330d596 (prev-detached) new line in detached branch
  157de9a (new-detach, new) Second line new branch
  99c7935 New line new branch
  e85642a (master) Fourth Commit
  fa3a2e7 Third Commit
  4482d66 second commit
  86bdb69 First Commit

  ```

# Merge Conflicts cases.

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

# Basic Staging.

## Removing from stages

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
  - we can use `git checkout -- <FILENAME>` or `git reset --hard HEAD`.
  - then if we view our file we only see
  ```
  Hello World
  ```
  - because it is the content of our current commit HEAD.

# Basic Commit and checkout.

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

  - there are 3 type of reset
    - `git reset --soft <SHA1/TAG>` ; change where the head point to.
    - `git reset <SHA1/TAG>` ; this default to mixed.
    - `git reset --hard <SHA1/TAG>` ; this discard our staged file and clean our working directory to be same as that particular commit location.
  - unlike checkout using `git reset --hard`, we will not checkout into new branch, but instead will remove file from staging and reset current working directory.
  - like checkout, to reset our working code to particular point, we can use `git reset`
  - `git reset HEAD` will reset our code to our HEAD (our current commit) incase we make changes in working directory and stage it, but we want to fully revert it.
  - `git reset HEAD^`, append `^` symbol will going back 1 commit before HEAD.
  - `git reset HEAD~2`, will go back 2 commit before HEAD, change 2 with other number.
  - `git reset HEAD@{1}` will undone our reset / mean reset to one HEAD front instead of one HEAD before.
  - `git reset <SHA1>` will reset to that particular commit id.

  - when performing `git reset` we can see the log of our actions using `git reflog` command.
  - this will list all our actions such as `commit`,`checkout`, and `reset`.
  - this is usefull when we exidently perform a hard reset and wiped out or stages or working direcotry.
  - when performing `git reset --hard HEAD~2`, our head will point to that below 2 commit, and the top most commit we made be gone from out `git log`.
  - we can use `<SHA1>` id for our actions from `reflog` to get to the point before we perform reset.

# Basic Git Logs.

- we use git logs to see the history of our commit.
- this command show usefull information for each commit such as the author, date, commit message and SHA1 of our commits.
- we can also perform various output filter to show different style of information.
- `git log --graph --decorate`, will create a graph view of our commit
- `git log --oneline`, will show commit info in one line, without extra info.
- `git log --all`, show commit for all branches.
- we can combine these filter toger such that `git log --graph --decorate --oneline --all`

# Diff

- to show different between commits point or branches.
- we use `git diff <SHA1> <SHA1>` or `git diff <branch1> <branch2>`.
- let say we want to see the different between our HEAD (current commit) and previous commit.
  - `git log` to list our commit history.
  - select a commit we want to compare.
  - then simply run `git diff <SHA1> HEAD`
  - newly added content will be highlight in green with plus `+` sign while delete will be highlight in red with minus `-` sign.
  - scroll thru it using keypad down button.

# Git TAGS

- git tags simply gives a name or label to any commits point.
- you might noticed the `HEAD` label in our current commit.
- `HEAD` is just a tags indicating we are currently in this commit.
- we can list tags using `git tag --list`.
- there are two types of tags,
  - `lightweight tags`: simply tags with no information associated.
  - `annotated tags` : tags with extra information.
- we can create new lightweight tags using `git tag <tagname>`

  - this simply create new tag in current commit what we are in.
  - example we create tag named `myLightTag` using `git tag myLightTag`.
  - we can see it when we use `git log` command.

  ```
  jun@null:~/Developer/LearnGit/test$ git log --oneline

  6e89149 (HEAD -> new-detach-v2, tag: myLightTag, newBrach) resolve conflict
  3b16cc5 Conflic update
  e4f38ee Bad Commit
  1630ba0 resolve conflict

  ```

- to delete tag we use, `git tag -d <tagname>`
- to create new annotated tag, we use the `-a` options.

  - `git tag -a <tagname> -m <message about tag information>`
  - let say we want to create a version tag.
  - `git tag -a v0.1 -m "Version 0.1 development"`.
  - then we can see information about that specific tags version using `git show <tagname>`

  ```
  jun@null:~/Developer/LearnGit/test$ git show v0.1

  tag v0.1
  Tagger: nurbxfit <myemail@gmail.com>
  Date:   Sun May 16 22:50:21 2021 +0800

  Version 0.1 development

  commit 6e89149c730429d9765884cc7d826720d3f96211 (HEAD -> new-detach-v2, tag: v0.1, newBrach)
  Merge: 3b16cc5 e4f38ee
  Author: nurbxfit <myemail@gmail.com>
  Date:   Sun May 16 22:12:51 2021 +0800

      resolve conflict

  diff --cc README.md
  index 48f510b,971633d..0842b72
  --- a/README.md
  +++ b/README.md
  @@@ -7,4 -7,4 +7,8 @@@ Second Line in new Branc

    Detached line in new branch

  -Bad commit
  ++
  +Conflicting update
  ++
  ++
  ++

  ```

# Git Stash

- let say we made changes to a file.
- then change our mind and wanting re-edit it, but we don't want to remove what we already done.
- we can temporary save our changes using `git stash` command.
- `git stash` will save our working directory and index the state WIP (Work in Progress) on that particular changes.
- it's like boxing our changes, and put it somewhere for next time use.
- we can list our stash using `git stash list`.
- after saving into our stash, we will get a clean working tree (like a clean desk).
- here we can make changes again, and commit our changes.
- next time when we need to get back our stash, we can use `git stash pop` or `git stash apply`.
- `git stash pop`, will pop our top most stashes in our stashes list, and add it to our working directory.

  - it's like take our most recent stash and put it on table.
  - this will remove the stash from the stash list.

- example cases.
  - let say we are editing a code in a file `app.js`.
  - we now have app.js set to modified, Changes to be committed.
  - we not yet commit this file, because there is lot of work need to do.
  - then suddenly our manager call and ask us to make change to file `.config` ASAP.
  - if we make changes to .config and commit it now, we will also be commiting our `app.js` and we don't want that.
  - so we can use `git stash` to stash our `app.js`, and then only commit the `.config` file.
    - what we do is we first perform a `git stash`.
    - then we edit our `.config` file.
    - then we commit `git commit -am 'edit config: update db url'`
    - then we can get back our stash files using `git stash pop`
