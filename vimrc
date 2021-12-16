" Vimrc for daily use

" basic options
set cb=unnamedplus,unnamed
set ts=4 " tabstop=4
set sw=4 " shiftwidth=4
set ls=2 " laststatus=2
set cul " cursorline
set ai " autoindent
set is " incsearch
filetype plugin indent on
set hls " hlsearch
set rnu " relativenumber
syntax enable
" colo ???

" Plugins
call plug#begin('~/.vim/plugged')

Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'yuttie/comfortable-motion.vim'
Plug 'itchyny/lightline.vim'
Plug 'godlygeek/tabular'
Plug 'plasticboy/vim-markdown'
Plug 'lervag/vimtex'
Plug 'preservim/nerdtree'
Plug 'morhetz/gruvbox'
Plug 'tomasr/molokai'
Plug 'fmoralesc/molokayo'
Plug 'rlue/vim-barbaric'

call plug#end()

" additional options
colo molokayo
set nocompatible
set showcmd
set mouse=n
set t_Co=256
set wrap
set autochdir
set noerrorbells
set autoread
set ttimeoutlen=0

" keymaps
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 % -o %:r -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined -fsanitize=address <CR>
autocmd filetype cpp nnoremap <F10> :!./%:r <CR>
autocmd filetype cpp nnoremap <C-C> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

" latex keymaps
autocmd filetype tex nnoremap <F9> :w <bar> :!xelatex % <CR>
autocmd filetype tex nnoremap <F10> :!okular %:r.pdf <CR>

" vim markdown settings
let g:vim_markdown_math = 1
 
" enhanced highlight issue
let c_no_curly_error = 1

" Set true color
let &t_8f="\<Esc>[38;2;%lu;%lu;%lum"
let &t_8b="\<Esc>[48;2;%lu;%lu;%lum"
set termguicolors

" NERDTree settings
" F5 to toggle and put the cursor back in the othe window.
nnoremap <F5> :NERDTreeToggle \| wincmd p<CR>
" Start NERDTree and put the cursor back in the other window.
autocmd VimEnter * NERDTree | wincmd p
" Exit Vim if NERDTree is the only window remaining in the only tab.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
" Close the tab if NERDTree is the only window remaining in it.
autocmd BufEnter * if winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
let g:NERDTreeWinSize=20

" Refresh defaut code
autocmd filetype cpp command New execute "%d|r ~/Programming/template/default.cpp|1d|41"

" encoding
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
