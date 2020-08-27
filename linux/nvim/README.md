# Vim and NeoVim, 
vim or neovim is actually a great text editor when you actually learned to use it.
My command line texteditor of choice was `nano` because it was simple and straightfoward to use as a begineer,
but I rarely used it, and I often choosed GUI texteditor such as `vscode` and `atom` when I am coding. 
`vscode` is great, beutiful and easy to use, can install lot of plugin to enhance my coding experience.
Then one day while playing around learning about my linux machine, i decided to start to learn vim. 
I started with simple `vimtutor` command and online tutorial, then I get hooked to it. 

# My daily vim variant is neovim.
1. to install neovim in arch: `pacman -Sy neovim`
2. to configure neovim create a file in your home directory called `~/.configure/nvim/init.vim`

# Install vue Plug to add plugins to your vim.
1. install vue Plug on with neovim you can follow the official docs of [vim-plug](https://github.com/junegunn/vim-plug) 
  or just using this command: 
```
sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
```
2. then insite our `init.vim` file, we can start adding our plugins.


