# Installing PHP in Fedora
check if community repo contains latest php version.
```bash
$sudo dnf info php-cli
```
then install php-cli, phpunit, composer and php-mysqli
```bash
$sudo dnf update && sudo dnf install php-cli phpunit composer php-mysqli
```
else, we use remi repository.
1. install Remi repo
```bash
$sudo dnf install http://rpms.remirepo.net/fedora/remi-release-34.rpm 
```
2. enable remi repo 
```bash
$sudo dnf config-manager --set-enabled remi
```
3. reset and install specific version of php
```bash
$sudo dnf module reset php && sudo dnf module install php:remi-7.4 
```
4. Verify installed PHP version
```bash
$php -v
```

5. result example
```
[jun@fedora PHP]$ php -v
PHP 7.4.22 (cli) (built: Jul 27 2021 18:08:31) ( NTS )
Copyright (c) The PHP Group
Zend Engine v3.4.0, Copyright (c) Zend Technologies 
```
# Start a Local Development Server
```bash
$sudo php --server localhost:8080 --docroot  .
```
# Installing MySQL in Fedora
check if community repo contains MySQL
```bash
$sudo dnf info community-mysql-server
```
if the version provided is what you want, you can skip to step 2.
else use the MySQL Repo on step 1.

1. Adding MySQL Repo
```bash
$sudo dnf install https://repo.mysql.com//mysql80-community-release-fc31-1.noarch.rpm
```

2. Installing MySQL
```bash
$sudo dnf install mysql-community-server
```

3. Enable and start MySQL
```bash
$sudo systemctl enable mysqld
$sudo systemctl start mysqld
```
4. Finding Default Password
```bash
$sudo grep 'temporary password' /var/log/mysqld.log
```
5. Configure SQL the first time.
```bash
$sudo mysql_secure_installation
```

6. Login to MySQL via CLI.
```bash
$sudo mysql -u root -p
```

# Uninstalling MySQL
```bash
$sudo rpm -e --nodeps mysql-community-libs mysql-community-common mysql-community-server
```
