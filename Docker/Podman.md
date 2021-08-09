# Podman.
- podman is an alternative to Docker runtime.
- it is available for RHEL and fedora but also available for other distro.
- most of Docker command can be directly translated to podman.

# installing podman on Fedora
```bash
$sudo dnf install podman
```
- [alternate distro guide](https://podman.io/getting-started/installation)

# Podman Example
## Installing SQL server on podman.
1. Pulling MySQL image.
```bash
$podman pull mysql-server
```
2. see logs
```bash
$podman logs
```
3. Finding generated mysql password
```bash
$podman logs mysql 2>&1 | grep GENERATED
```
let say the password is `testpassword`
4. start server instance and set enviroment variable of our root password with the generated password we found earlier. 
```bash
$podman -d --name=mysqldb -e MYSQL_ROOT_PASSWORD=testpassword mysql/mysql-Server
```
- the `-d` tag, run our mysql/mysql-Server in background.
- the `-e` tag, set the enviroment variable.
- the `--name` specify the name of our container/pod.
## Accessing our pod CLI.
- like in docker, we can use the `exec` command to overide command.
- example `podman exec -it <podname> <overide command>`
```bash
$podman exec -it mysqldb bash
```
- to run mysql cli, we just specify the mysql command
```bash
$podman exec -it mysqldb mysql -u root -p
```

# Stoping our pod/container
```bash
$podman stop mysqldb
```

# Deleting pod
```bash
$podman rm mysql
```