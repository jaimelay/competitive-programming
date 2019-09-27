syntax on
colors evening
filetype on
filetype indent on
autocmd BufNewFile *.cpp :0r ~/.vim/cpp
autocmd BufNewFile *.cpp :w!
map <F5> :!g++ -g % && time ./a.out <CR>
set number
set et ts=4 sw=0 sts=-1 ai nu hls cindent
nnoremap ; :
vnoremap ; :
noremap <c-j> 15gj
noremap <c-k> 15gk
nnoremap <s-k> i<CR><ESC>
inoremap ,. <esc>
vnoremap ,. <esc>
nnoremap ,. <esc>
inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O
