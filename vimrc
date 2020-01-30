""/*
"" * Author        : OFShare@outlook.com
"" * Created Time  : 2020-01-30 21:20:53 PM
"" * File Name     : /home/ofshare/.vimrc
"" */

"自动语法高亮
syntax on

"utf-8是针对Unicode的一种可变长度字符编码. 它可以用来表示Unicode标准中的任何字符
"编码设定Encoding
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936 
set termencoding=utf-8　　
set encoding=utf-8

"突出显示当前行
set cursorline 

"用C语言的缩进格式来处理程序的缩进结构
set cindent
"新增加的行和前一行使用相同的缩进形式
set autoindent

function! ClosePair(char)
  if getline('.')[col('.') - 1] == a:char
    return "\<Right>"
  else
    return a:char
  endif
endfunction

"为C/C++程序提供自动缩进
set smartindent
"自动补全
inoremap ( ()<ESC>i
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap { {<CR>}<ESC>O
inoremap } <c-r>=ClosePair('}')<CR>
inoremap [ []<ESC>i
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap " ""<ESC>i
inoremap " <c-r>=ClosePair('"')<CR>
inoremap ' ''<ESC>i
inoremap ' <c-r>=ClosePair('\'')<CR>

"允许使用鼠标
set mouse=a
"鼠标复制内容到剪切板
set mouse=v

"调试好了以后<Ctrl-A>复制代码到粘贴板, 提交
map <C-A> ggVG"+y

"<Ctrl-W>, 会自动跳回终端编译并运行, Ctrl-C中断运行并跳回vim
map <C-W> :call Run()<CR>
func! Run()
  exec "w"
  exec "!g++ -Wall -std=c++11 % -o %<"
  exec "!./%<"
endfunc

"显示行号
set nu

"背景设置为黑色
set background=dark

"设定tab所等同的空格长度
set tabstop=2

"设置空格字符代替tab键
set expandtab

"把以前使用的tab键也用space字符代替
%retab!

"程序中自动缩进所使用的空白长度指示
set shiftwidth=2

map <C-D> :call SetTitle()<CR>
func SetTitle()
  let l = 0
  let l = l + 1 | call setline(l, '/*')
  let l = l + 1 | call setline(l, ' * Author        : OFShare@outlook.com')
  let l = l + 1 | call setline(l, ' * Created Time  : '.strftime('%F %T %p'))
  let l = l + 1 | call setline(l, ' * File Name     : '.expand('%'))
  let l = l + 1 | call setline(l, ' */')
  let l = l + 1 | call setline(l, '')
endfunc
