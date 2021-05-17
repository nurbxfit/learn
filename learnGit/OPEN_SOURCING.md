# Contributing to a Project.

- when getting start in contributing to an open source project, it is necessary how to:
  - using fork to create a copy of project.
  - make changes and create pull request.
  - reviewing changes and accept the request.
  - create an issues.

## Forking,

- forking is making a copy of other people repository.
- it is important to fork the project instead of commiting directly to the original repository.
- we can fork a repository by simply use the fork button in Github.
- after forking, we use the URL of our copy of that repository to clone to our development machine.

## Pull Request.

- we use pull request to let the owner know of changes we made in our copy of that repository.
- we can do this by clicking on the `compare & pull request` button or a `Pull request` hyperlink in Github.
- making a pull request is like asking permission to create a commit to the original repository.
- it will make a request to merge our copy repository to the original repository,
- Github page will show us a form to write a message for us to tell the original developer/maintainer what we've done, what changes we made.
- after we clicked `create pull request` button. the original developer will be notified with our request.
- the developer then will decide whether to approve or reject our request.
- after making a pull request, and we then update more of the files and push it to our copy repository.
- all our recent commits will also been updated and shown in the pull request.

## Syncing our local Repository with Original Remote Repository.

- the local repository for development that we use is the copy repository on our github.
- when we use `git fetch` or `git pull` in the terminal on our development machine, we are actually fetching from our own copy repository.
- we can view the remote origin using `git remote -v` command.
- so to get the latest update from the original repository we can add a new origin url pointing to the original repository when we want to fetch in our local repository.
- we can do this by using `git remote add <newOriginName> <theurl>`, let say we named it original
- then we can fetch or pull it using `git pull original master`.
- make sure to push to our copy repository not the original.
- we will have no permission to write to that original repository.
- we can only commit the code directly if we are a collaborators or the owner.

# Issues

- when we found bugs, we can create an issue, to tell the developer that there's a problem with the repository.
- we can also use issues to request add new features to the repository.
- to create issues, go to the repository, then find the `issues` button or hyperlink.
- there we can click `New Issue` button to create new issues.
- usually when we create new pull request, an issues automatically created on github to keep track of the request.
- we can use `labels` to assign tags to our issues to categorise or indicating the type of the issues.
- common labels such as `bug`,`duplicate`,`question` etc ...
- we can create, edit or delete labels.

## Using Commit with Issues.

- let say we had an issues created, saying please fix some bugs.
- we can fix that bugs commit it and then go to issue page and close the issue.
- alternatively we can associate our commits with specific issues we trying to solve.
- we can do this my specifying the issue number in our commit message.
- issue number is the number after the hashtag # symbol at our issue name.
- let we created an issue labeled bugs with issue number #1.
- then when working for the commit locally we commit the changes using
  - `git commit -am "Fixed bugs, added semicolon, close #1`
  - noticed that our commit message contains a coma, a `close` statement and a issue number `#1`
- after we push our commit, we can see at our github page that the issue is now closed, with a commit id associate with it.
- alternatively, we can go to our our github page, and the commit section.
- comment to our commit and add `Associating with #1 with this commit`
