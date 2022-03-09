" Vimrc for contest
set nocp
set cb^=unnamedplus,unnamed
set ts=4
set sw=4
set ls=2
set cul
set ai
set is
filetype plugin indent on
set hls
set rnu
set showcmd
syntax enable
colo pablo

autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 % -o %:r -Wall -Wconversion -Wextra -Wshadow -fsanitize=undefined -fsanitize=address<CR>
autocmd filetype cpp nnoremap <F10> :!./%:r<CR>

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}
