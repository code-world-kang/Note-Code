# Code-Note-WeiKang
[toc]
## git and github Code
### Git 初体验及其常用命令介绍

在 Git 中，所有的命令都是以git开头

* `git config --global user.name "Your Name"`:
* `git config --global user.email "youxiang"`:
* `git init`:作用就是初始一个 Git 仓库;
* `git status`:查看仓库的状态：
	* Untracked fies提示，它表示demo仓库中有文件没有被追踪，并提示了具体没有被追踪的文件为abs.txt，还提示了我们可以使用git add命令操作这个文件，
* ` git add abs.txt` :将txt文件添加到 Git 仓库：
	* 需要声明一点，那就是：git add命令并没有把文件提交到 Git 仓库，而是把文件添加到了「临时缓冲区」，这个命令有效防止了我们错误提交的可能性
* `git commit -m "text commit"`:将txt文件提交到 Git 仓库：
	* 如上图所示，我们成功将文件hit.txt提交到了 Git 仓库，其中commit表示提交，-m表示提交信息，提交信息写在双引号""内
* `git log`:打印 Git 仓库提交日志：
* `git branch`:查看 Git 仓库的分支情况：
	* 显示了仓库demo中的分支情况，现在仅有一个master分支，其中master分支前的*号表示“当前所在的分支”，例如* master就意味着我们所在的位置为demo仓库的主分支
* `git branch a`:	创建了一个名为a的分支，并且当前的位置仍然为主分支。
* `git checkout a`:切换到a分支：
* `git checkout -b b`:git checkout -b b
* `git merge a`:切换到master分支，然后输入git merge a命令，将a分支合并到master分支：
* `git branch -d a`:删除a分支：不过有的时候，通过git branch -d命令可以出现删除不了现象。例如分支a的代码没有合并到主分支等，这时如果我们一定要删除该分支，那么我们可以通过命令`git branch -D`进行强制删除
* `git tag v1.0`:为当前分支添加标签,`git tag` 查看当前分支标签：
 ### 利用 SSH 完成 Git 与 GitHub 的绑定
* `ssh` :查看本机是否安装 SSH.
* `ssh-keygen -t rsa`命令，表示我们指定 RSA 算法生成密钥，然后敲三次回车键，期间不需要输入密码，之后就就会生成两个文件，分别为id_rsa和id_rsa.pub，即密钥`id_rsa`和公钥`id_rsa.pub`. 对于这两个文件，其都为隐藏文件，默认生成在以下目录：
 ```
 Linux 系统：~/.ssh
 Mac 系统：~/.ssh
 Windows 系统：C:\Documents and Settings\username\\.ssh
 Windows 10 ThinkPad：C:\Users\think\.ssh
 ```
* 进入我们的 GitHub 主页，先点击右上角所示的倒三角▽图标，然后再点击Settins，进行设置页面；点击我们的头像亦可直接进入设置页面
* 进入Settings页面后，再点击SSH and GPG Keys进入此子界面，然后点击New SSH key按钮：
* 只需要将公钥id_rsa.pub的内容粘贴到Key处的位置（Titles的内容不填写也没事），然后点击Add SSH key 即可。
* ` ssh -T git@github.com`:进行测试,验证绑定是否成功
### 通过 Git 将代码提交到 GitHub
#### 提交代码
对于向远处仓库（GitHub）提交代码，我们可以细分为两种情况：
* 第一种：本地没有 Git 仓库，这时我们就可以直接将远程仓库clone到本地。通过clone命令创建的本地仓库，其本身就是一个 Git 仓库了，不用我们再进行init初始化操作啦，而且自动关联远程仓库。我们只需要在这个仓库进行修改或者添加等操作，然后commit即可。
1. 首先，进入 GitHub 个人主页：
2. 点击 mybatis-tutorial 项目
3. 点击Clone or download，复制地址链接
4. 进入准备存储 Git 仓库的目录(gitbash)
   输入```
   git clone https://github.com/guobinhit/mybatis-tutorial.git ```
* 第二种：本地有 Git 仓库，并且我们已经进行了多次commit操作。
1. 首先，建立一个本地仓库，命名为springmvc-tutorial
2. 进入该仓库，进入init初始化操作
3.  `git remote add Note-Code https://github.com/code-world-kang/Note-Code.git`：
命令，关联远程仓库（在此，默认大家都知道如何获取远程仓库的地址），其中origin为远程仓库的名字：
4. 输入git pull origin master命令，同步远程仓库和本地仓库：
5. 接下来，在本地仓库新建一个名为test.txt的测试文件：
6. 输入git add和git commit命令，将文件test.txt添加并提交到springmvc-tutorial仓库：
7. 再输入git pull Note-Code master
命令，将本地仓库修改（或者添加）的内容提交到远程仓库：
8. 接下来，在本地仓库新建一个名为test.txt的测试文件：
9. 输入git add和git commit命令，将文件test.txt添加并提交到springmvc-tutorial仓库：
10. 再输入git push origin master命令，将本地仓库修改（或者添加）的内容提交到远程仓库：
11. 已经将本地仓库的内容同步到了远程仓库。下面，我们进入远程springmvc-tutorial仓库的页面，看看我们的提交结果：
## Root Code

### 部分代码示例
##### 利用ROOT实现自动寻峰以及多高斯拟合
$\color{red}{一维高精度自动寻峰函数SearchHighRes()}$
**说明：**
这个函数用于原始谱中搜索峰值。它基于反卷积方法解谱寻git峰。首先去除背景(如果需要)，然后计算马尔可夫平滑谱(如果需要)，然后根据给定的sigma生成响应函数并进行反卷积。峰值的顺序是根据背景消除后它们在光谱中的高度来排列的。最高的山峰是名单上的第一个。如果成功，它将返回找到的**峰值数量**。
```
//参数说明
Int_t TSpectrum::SearchHighRes	(Double_t * source,//源谱，一直数据作为输入，是一个向量
Double_t *destVector,//反卷积得到的数据，也是一个向量
Int_t 	ssize,//源谱的长度,即向量的长度，十一个int类型的数据
Double_t 	sigma,//峰的标准差，是一个double类型的
Double_t 	threshold,//峰阈值，峰高于这个阈值才认为是一个峰
bool 	backgroundRemove, //是否去除本底，逻辑变量，如果需要在反褶积之前去除背景，则设置，bool类型的数据
Int_t 	deconIterations,// 反褶积运算中的迭代次数,int类型
bool 	markov,是否用马尔可夫链法计算的能谱，bool型，逻辑变量
Int_t 	averWindow //搜索峰值的平均窗口，仅仅适用于马尔可夫方法，int型
)	
```
需要用到`TSpectrum`这个类，然后通过这个类定义类指针，然后定义类函数SearchHighRes()。
$\color{red}{如何在root中实现多高斯拟合}$
```
//code example
Int_t npeaks 4; //定义峰的数目，可以通过自动寻峰获得
Double_t fpeaks(Double_t *x,Double *par)  //定义多高斯拟合函数，第一参数为x，第二个为高斯函数的参数，如峰值，峰位，sigma
//一个高斯有三个参数，四个高斯，12个参数，加上par[0]和par[1],共计14个参数，
{
    Double result = par[0]+par[1]*x[0];   
    for(Int_t p=0;p<npeaks;p++){
        Double_t norm=par[3*p+2];
        Double_t mean=par[3*p+3];
        Double_t sigma=par[3*p+4];
        result +=norm*TMath::Gaus(x[0],mean,sigma);//不断循环后的一个累加
    }
    return result;//返回值为多个高斯的总贡献，root对高斯函数的参数进行调整，就得到了能谱
}
```
$\color{red}{寻峰+拟合}$
头文件中包含`TSpectrum.h`{自动寻峰}，`TPolyMarker,h`{峰标记，倒三角}


## Geant Code

## 软件安装教程

## Azure

Azure是微软基于云计算的操作系统，相当于一个大型的云操作系统，既提供基础设施服务如虚拟机，硬盘，又提供托管服务。类似于我们的个人电脑，可以在上面安装软件，存储东西。
Azure 虚拟桌面，和存储有免费版本以及收费版本，虚拟机仅仅提供收费版本。
[网页连接](https://www.azure.cn/)

## Markdown语法

[Markdown官方简单教程](https://markdown.com.cn/basic-syntax/links.html)
常用的总结：
前面带#+空格表示标题
两个空格+enter表示换行  
间隔一行表示换行
强调前后两个**，快捷方式ctrl+B，斜体前后一个_，斜体强调三个***
要创建块引用，请在段落前添加一个` > `符号，不知道引用有什么用
**列表的显示**
Markdown语法 | 预览效果 |
---------|----------|---------
 `1. First item`  | B1 | 1. First item
加*,-,+都会表示出不同的效果，例如

```markdown
1. Third item
    - Indented item
* Indented item
- Fourth item
```

**代码**
如果你要表示为代码的单词或短语中包含一个或多个反引号，则可以通过将单词或短语包裹在双反引号(``)中，若但是代码块可以放在六个反引号（``````）中，或将代码块的每一行缩进至少四个空格或一个制表符

```markdown
<html>
      <head>
      </head>
    </html>
```

要创建分隔线，请在单独一行上使用三个或多个星号 (***)、破折号 (---) 或下划线 (___) ，并且不能包含其他内容。

**添加连接**
链接文本放在中括号内，链接地址放在后面的括号中，链接title可选
超链接Markdown语法代码：`[超链接显示名](超链接地址 "超链接title")`

```markdown
这是一个链接 [Markdown语法](https://markdown.com.cn "最好的代码教程  ")
<https://markdown.com.cn>
<fake@example.com>
[1]: https://en.wikipedia.org/wiki/Hobbit#Lifestyle
[1]: https://en.wikipedia.org/wiki/Hobbit#Lifestyle "Hobbit lifestyles"
```

这是一个链接 [Markdown语法](https://markdown.com.cn "最好的代码教程  ")
<https://markdown.com.cn>
<fake@example.com>
[1]: <https://en.wikipedia.org/wiki/Hobbit#Lifestyle>
[1]: <https://en.wikipedia.org/wiki/Hobbit#Lifestyle> "Hobbit lifestyles"

**插入图片**
插入图片Markdown语法代码：`![图片alt](图片链接 "图片title")`。
对应的HTML代码：`<img src="图片链接" alt="图片alt" title="图片title">`

```markdown
![这是图片](路径/garden.jpg "Magic Gardens")
[![沙漠中的岩石图片](/assets/img/shiprock.jpg "Shiprock")](https://markdown.com.cn)
```

**转义字符**
要显示原本用于格式化 Markdown 文档的字符，请在字符前面添加反斜杠字符 (\\),例如

```markdown
\* Without the backslash
\{},\[],\&,\<,\....
```

\* Without the backslash  
\{},\[],\&,\<,\....

**内嵌HTML标签**
对于 Markdown 涵盖范围之外的标签，都可以直接在文件里面用 HTML 本身。如需使用 HTML，不需要额外标注这是 HTML 或是 Markdown，只需 HTML 标签添加到 Markdown 文本中即可。

**表格语法**
请使用三个或多个连字符（---）创建每列的标题，并使用管道（|）分隔每列；
通过在标题行中的连字符的左侧，右侧或两侧添加冒号（:），将列中的文本对齐到左侧，右侧或中心。

```markdown

| :---        |    :----:   |          ---: |
```

**脚注**
要创建脚注参考，请在方括号（[^1]）内添加插入符号和标识符。标识符可以是数字或单词，但不能包含空格或制表符。标识符仅将脚注参考与脚注本身相关联-在输出中，脚注按顺序编号。

**任务列表语法**
列表语法

```markdown
- [x] Write the press release
- [ ] Update the website
- [ ] Contact the media
```

- [x] Write the press release
- [ ] Update the website
- [ ] Contact the media

**文本颜色**
$\color{green}{green}$
$\color{red}{green}$
$\color{blue}{green}$
$\color{grey}{green}$
$\color{black}{green}$

## Linux Shell code
### 终端美化
$\color{red}{\bf zsh的安装}$
$\color{blue}{非root用户安装zsh，并配置}$
1. 安装zsh
* 新建zsh文件夹
```
  cd && mkdir  zsh && cd zsh
 ```
* 下载最新版本的zsh，需要手动添加版本号
 ```
  wget https://sourceforge.net/projects/zsh/files/latest/download/zsh-XXX.tar.xz (xxx换成最新的版本号)
 ```
* 解压下载后文件
 ```
  xz -d zsh-xxx.tar.xz
  tar -xvf zsh-xxx.tar
  cd zsh-xxx
  (xxx换成最新的版本号)
```
* 编译文件
 ```
  ./configure --prefix=$HOME/zsh #表示安装到家目录中的zsh文件夹下，可以自己设置想要的路径
  make && make install
 ```
* 若没有遇到问题则跳过此步
  问题一：`./configure`出现问题，提示缺少`ncurses`
```
configure: error: "No terminal handling library was found on your system.
This is probably a library called 'curses' or 'ncurses'.  You may
need to install a package called 'curses-devel' or 'ncurses-devel' on your system."
See `config.log' for more details
```
* 解决：
先配置相应的环境变量，除了第三行可以修改（也可以不修改），其他不用修改
```
export CXXFLAGS="-fPIC"
export CFLAGS="-fPIC"
export NCURSES_HOME=$HOME/ncurses  # 这里表示家目录的ncurses目录，可以自己设置一个想要的路径
export PATH=$NCURSES_HOME/bin:$PATH
export LD_LIBRARY_PATH=$NCURSES_HOME/lib:$LD_LIBRARY_PATH
export CPPFLAGS="-I$NCURSES_HOME/include" LDFLAGS="-L$NCURSES_HOME/lib"
```
配置好环境变量后，安装`ncurses`, 找到最新版本`ncurses`下载安装
```
cd ../../ && mkdir ncurses && cd ncurses  # 切换到上级目录新建ncurses文件夹

wget http://ftp.gnu.org/pub/gnu/ncurses/ncurses-XXX.tar.gz  # 下载最新版本ncurses
tar -xzvf ncurses-XXX.tar.gz  # 解压
cd ncurses-XXX
# XXX需要改成最新的版本号

./configure --prefix=$HOME/ncurses --with-shared --without-debug --enable-widec  
# 指定路径configure,可以自己修改想要安装的路径，这里我装到了家目录的ncurses下面了
make && make install  # 安装
```
安装完`ncurses`后，回到zsh路径，重新进行第四步就行了。

问题二：`make && make install` 时出现问题
```
make: *** No targets specified and no makefile found.  Stop.
```
这里的问题应该也是问题一，可能是你没有看到而忽略了。按照问题一的解决办法修改就行了。

2. 安装on my zsh
* 更新PATH
  安装` oh-my-zsh `前先将安装好的` zsh `所在的路径添加到系统环境变量 `PATH` 中
```
export PATH=$HOME/zsh/bin:$PATH
# 这里需要修改成你安装的路径
```
但是我们会发现重新登录之后，默认的shell还是bash，这里我们通过修改`.bash_profile`来自动切换到`zsh`，将一下命令加到`~/.bash_profile`
```
[ -f $HOME/zsh/bin/zsh ] && exec $HOME/zsh/bin/zsh -l
# 路径还是要修改成你安装的路径
注意zsh与scp不兼容，所以不要把该命令写到.bashrc中。因为当我们使用scp命令从本地连接该Linux服务器时，系统会自动执行.bashrc（而不会执行.bash_profile），如果.bashrc中有切换到zsh的命令，则系统的shell会被切换到zsh, 从而与scp产生兼容的问题。

.bash_profile只有当交互式登录shell时（如系统启动、远程登录）才会被读取并执行，而.bashrc在交互式登录与非交互登录（如使用scp从本地连接到该Linux服务器）时都会被读取且执行。
```
*  安装onmyzsh
```
# 方法一：wget方式自动化安装oh my zsh：
$ wget https://github.com/robbyrussell/oh-my-zsh/raw/master/tools/install.sh -O - | sh

# 方法二：
$ curl -L https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh | sh 

# 官网上的另外一种写法
$ sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
$ sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"

# 方法三：手动安装
$ git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh 
注: 1. 克隆后将templates目录下的zsh配置文件拷贝至~/.zshrc即可
    2. .oh-my-zsh一定要在$HOME下( ~ 下)
```
以上选一种即可

*  切换到zsh，安装完之后应该是会自动切换到zsh
```
exec $HOME/zsh/bin/zsh  # 你的zsh路径
```

$\color{blue}{root用户安装zsh，并配置}$
*  安装
```
sudo apt install zsh
```
* 将 zsh 设置为默认 shell
```
chsh -s /bin/zsh
```
*  检查
```
echo $SHELL
```
  返回 /usr/bin/zsh 即表示成功；若没成功，重启试试看
* 安装Oh My Zsh
```
% 通过 curl
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

% 或者 通过 wget
sh -c "$(wget -O- https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

$\color{blue}{zsh配置on my zsh}$
* 修改默认主题
```
vim ~/.zshrc
```
用vim打开文件后，按下/键，可以直接搜索`ZSH_THEME`的位置，按esc即可退出。将其修改成
```
ZSH_THEME="ys"  //修改风格
```
* 插件

**语法高亮插件 zsh-syntax-highlighting**
```
git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh}/plugins/zsh-syntax-highlighting
```
**自动提示插件 zsh-autosuggestions**
```
git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh}/plugins/zsh-autosuggestions
```
**快速打开 GitHub 仓库 git-open**
```
git clone https://github.com/paulirish/git-open.git $ZSH_CUSTOM/plugins/git-open`
```
下载之后还需要修改`.zshrc`使其生效，修改`plugins`的值，将`zsh-syntax-highlighting` `zsh-autosuggestions` `git-open`添加进去
```
plugins=(
    git 
    zsh-syntax-highlighting 
    zsh-autosuggestions
    git-open
    )
```
**incr.zsh 补全插件 在zsh 模式下全自动补全指令或目录**
下载软件：官网: `http://mimosa-pudica.net/zsh-incremental.html`
放置：`.oh-my-zsh/plugins/`
在`.zshrc`中加入`source ~/.oh-my-zsh/plugins/incr/incr*.zsh`
incr文件内容：
```
# Incremental completion for zsh
# by y.fujii <y-fujii at mimosa-pudica.net>, public domain

autoload -U compinit
zle -N self-insert self-insert-incr
zle -N vi-cmd-mode-incr
zle -N vi-backward-delete-char-incr
zle -N backward-delete-char-incr
zle -N expand-or-complete-prefix-incr
compinit

bindkey -M viins '^[' vi-cmd-mode-incr
bindkey -M viins '^h' vi-backward-delete-char-incr
bindkey -M viins '^?' vi-backward-delete-char-incr
bindkey -M viins '^i' expand-or-complete-prefix-incr
bindkey -M emacs '^h' backward-delete-char-incr
bindkey -M emacs '^?' backward-delete-char-incr
bindkey -M emacs '^i' expand-or-complete-prefix-incr

unsetopt automenu
compdef -d scp
compdef -d tar
compdef -d make
compdef -d java
compdef -d svn
compdef -d cvs

# TODO:
#     cp dir/

now_predict=0

function limit-completion
{
	if ((compstate[nmatches] <= 1)); then
		zle -M ""
	elif ((compstate[list_lines] > 6)); then
		compstate[list]=""
		zle -M "too many matches."
	fi
}

function correct-prediction
{
	if ((now_predict == 1)); then
		if [[ "$BUFFER" != "$buffer_prd" ]] || ((CURSOR != cursor_org)); then
			now_predict=0
		fi
	fi
}

function remove-prediction
{
	if ((now_predict == 1)); then
		BUFFER="$buffer_org"
		now_predict=0
	fi
}

function show-prediction
{
	# assert(now_predict == 0)
	if
		((PENDING == 0)) &&
		((CURSOR > 1)) &&
		[[ "$PREBUFFER" == "" ]] &&
		[[ "$BUFFER[CURSOR]" != " " ]]
	then
		cursor_org="$CURSOR"
		buffer_org="$BUFFER"
		comppostfuncs=(limit-completion)
		zle complete-word
		cursor_prd="$CURSOR"
		buffer_prd="$BUFFER"
		if [[ "$buffer_org[1,cursor_org]" == "$buffer_prd[1,cursor_org]" ]]; then
			CURSOR="$cursor_org"
			if [[ "$buffer_org" != "$buffer_prd" ]] || ((cursor_org != cursor_prd)); then
				now_predict=1
			fi
		else
			BUFFER="$buffer_org"
			CURSOR="$cursor_org"
		fi
		echo -n "\e[32m"
	else
		zle -M ""
	fi
}

function preexec
{
	echo -n "\e[39m"
}

function vi-cmd-mode-incr
{
	correct-prediction
	remove-prediction
	zle vi-cmd-mode
}

function self-insert-incr
{
	correct-prediction
	remove-prediction
	if zle .self-insert; then
		show-prediction
	fi
}

function vi-backward-delete-char-incr
{
	correct-prediction
	remove-prediction
	if zle vi-backward-delete-char; then
		show-prediction
	fi
}

function backward-delete-char-incr
{
	correct-prediction
	remove-prediction
	if zle backward-delete-char; then
		show-prediction
	fi
}

function expand-or-complete-prefix-incr
{
	correct-prediction
	if ((now_predict == 1)); then
		CURSOR="$cursor_prd"
		now_predict=0
		comppostfuncs=(limit-completion)
		zle list-choices
	else
		remove-prediction
		zle expand-or-complete-prefix
	fi
}

```




然后`source`
```
source ~/.zshrc
```

### 常用命令
1. alias 命令别名
```
alias cls='clear'
alias ga='git add'
alias gc='git commit -m'
alias gp='git push'
alias go='git-open'
alias update='sudo apt update'
alias upgrade='sudo apt upgrade'
alias install='sudo apt install'
alias aremove='sudo apt autoremove'
alias remove='sudo apt remove'
alias aclean='sudo apt autoclean'
alias clean='sudo apt clean'
```
2. 相对路径与绝对路径
绝对路径：`/home/kang/work`
相对路径：`~/work`
`../` 上一级目录单个点‘.’ 表示当前目录, 两个点“. .”表示上一层目录
1. 统计文档的行数
`wc -l a.txt`
1. 统计文档中的words
`wc -w a.txt`
1. 查找文件中包含某个单词的文件，s表示忽略文件不存在或无法读取等错误信息，r表示在文件夹中递归查找，n表示打印出字符串出现的行号。
`grep -srn "Fit_Landau" /home/kang/mywork`
1. 即用find命令在当前目录寻找(递归)所有的cpp文件，找到后执行sed命令，其中-name和-exec是find命令的参数，分别表示按文件名寻找和执行指令。sed指令在文件中寻找(s)字符串“yang_int”，替换为“yang_float”。
`find . -name "*.cpp" -exec sed -i 's/yang_int/yang_float/g' {} \;`


