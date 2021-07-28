## USAGE
- example getting help.
```bash
python changeName.py -h
```
- example changing file that have the words `[by:jeff]` in its name to `[by:Jun]`.
- example file
```
Acapelalela - [by:jeff].mp3
....
```
```bash
python changeName.py -p "/home/jun/Documents" -k "[by:jeff]" -r "[by:Jun]" -t file
```
- will change name to
```
Acapelalela - [by:Jun].mp3
```