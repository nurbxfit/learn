# Regex (regular expression) Basic.
- in javascript regex can be used with `.match`,  `.split` or `.replace`, function of a string object.
- you can declare a regex by placing it in between two `/`.
- example.
  ```js
  const myRegex = /hello/g
  ```
  - `myRegex` is the variable name, and `/hello/g` is our experession.
  - `g` at the end of `/` is an expression flags.
  - there are other expression flags such as.
    - `/g` : globally.
    - `/m` : multiline.
    - `/s` : single line (dotall).
    - `/u` : unicide.
    - `/y` : sticky.
    - `/i` : case insensitive.

# Understanding Flags.
- flags is use at the end of `/`, to describe the pattern search.
- as example the `/i` flag, is use to search for a pattern, but `ignore case sensitivity`.
- let say we want to search for every occurance of pattern contains the words `API` ignore the case.
  - the regex will be: `/api/gi`, this will match for : `Api`,`API`, `api`, api in `berapi` and so on.. u get the point...
- `/g` flag is used to find globally, means that, it will not stop on single ocurance of the matched pattern.
  - disabling the `/g` will only match a single occurance of the pattern.
  - so a line like this: `there is api in berapi, but doesn't means it's a pi or API`.
  - will result in: `api`, ber`api`, and `API` to match.

  ... not finish yet.

# Patterns.
- if you want only `API` not `berapi` while ignoring the case.
  - the regex will be: `/\b(api)/gi`, this add `\s` a space into the pattern.
  - so a line like this, `there is API in berapian`, will only match `API` and not include the api in ber`api`an.

