# URL Encoding.

- also known as percent encoding.
- web url sometimes can contains weird character to be pass to back-end server.
- browser cannot understand it because it can only understand ASCII characters.
- ASCII only allow alphanumeric characters and certain special characters.
- so all weird characters that are not in ASCII table, need to be encoded using chracters inside of ASCII table.
- these encoded character are denoted with the percentage `%` symbol.
- common examples
  - spaces usually get encoded into `%20`.
  - double quote encoded into `%22`.
  - [see more](https://www.w3schools.com/tags/ref_urlencode.ASP).
  - sometimes instead of encoding spaces with `%20`, it often replaced with plus `+` symbol

# Base64 Encoding.
