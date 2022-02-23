# Code-Note-WeiKang

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
* `git branch -d a`:删除a分支：不过有的时候，通过git branch -d命令可以出现删除不了现象。例如分支a的代码没有合并到主分支等，这时如果我们一定要删除该分支，那么我们可以通过命令 `git branch -D`进行强制删除
* `git tag v1.0`:为当前分支添加标签,`git tag` 查看当前分支标签：

### 利用 SSH 完成 Git 与 GitHub 的绑定

* `ssh` :查看本机是否安装 SSH.
* `ssh-keygen -t rsa`命令，表示我们指定 RSA 算法生成密钥，然后敲三次回车键，期间不需要输入密码，之后就就会生成两个文件，分别为id_rsa和id_rsa.pub，即密钥 `id_rsa`和公钥 `id_rsa.pub`. 对于这两个文件，其都为隐藏文件，默认生成在以下目录：

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
   输入 ``git clone https://github.com/guobinhit/mybatis-tutorial.git``

* 第二种：本地有 Git 仓库，并且我们已经进行了多次commit操作。

1. 首先，建立一个本地仓库，命名为springmvc-tutorial
2. 进入该仓库，进入init初始化操作
3. `git remote add Note-Code https://github.com/code-world-kang/Note-Code.git`：
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
