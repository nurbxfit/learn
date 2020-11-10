# CRON
- cron for me is a super handy schelduling program in linux.
- it's enable us to scheldule programs to run periodically.
- example usage is to run backup scripts or cleaning scripts on a given scheldule.
- In pass project i used cron to run web crawler every weekend of every third week of the month.
- It is very handy as system admin I don't have to run the scripts everytime manually.

# understanding CRON.
- cron is linux deamon,
- in cron, a program running in it, is called a `cron job`. 
- a file that holds the  `cron jobs` is called `crontab`.
- to create a new crontab for current user. use the command `crontab -e`.
- this will open up your default texteditor for you to write your jobs.
- cron jobs are written using cron syntax that are something like this.
  ```
  * * * * * user_name command_to_execute
  ```
  - the 5 asterik ( * ) symbols indicates period or time.
    - it's defines the period when the command need to run.
    - the left most asterik is the indication for minutes, can also be presented by number (0-59).
    - the second column indicate the hour (0-23).
    - the third column is for day of month (1-31).
    - the fourth column is for the month of the year (1-12) or jan,feb,mar,apr ....
    - the last colum is the day of week (0-6). that start with sunday=0, and ends with sat=6.
  - `user_name` is the user for that cronjob. 
    - username are for the system reserved crontab, means crontab defined by the system.
    - for user defined crontab, if you are login as a user eg name: bob,
    - when you run the command `crontab -e` the, program automatically detect your username.
    - so you don't have to specify your username when writting a jobs.
    - you syntax should be justt `* * * * * command_to_execute`
  - `command_to_execute` is just any command that you want to run with cron, such as a bash script, python scripts or a nodejs script.

# understanding the period ( * ).
- 
