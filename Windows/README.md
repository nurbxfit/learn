# Basic Windows Server Usage.

- check for pc name in cmd: `hostname`
- shutdown pc in cmd : `shutdown`
    - this will shutdown pc in `60 seconds` countdown
    - to shutdown instantly use `/t 0` options.
    - to restart use `/r` options.
    - to view more option use `/?` options.

# Windows powershell.
- powershell commands are called cmdlets.
- these are shell command built into windows.
- these are like a Setter and Getters for us to use to request for Windows API.
- to search for command related to any specific functions, we can use `Get-Help` cmdlets
- example trying to search for cmdlets related to Computer
    - `Get-Help Computer`
    - this will return list of cmdlets commands that are related to the words Computer.


## Basic command (mostly like unix system).
- `cd` change directory
- `mv` move directory
- `cls` clear console (this is in cmd in poweshell we can use both cls and `clear`)

## Getting Network info
- `Get-NetIPAddress` : get local ip address information.
- to specify which ip version we want, we can use `-AddressFamily` options
- example: `Get-NetIPAddress -AddressFamily IPv4`

