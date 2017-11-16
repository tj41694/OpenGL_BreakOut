# OpenGL_BreakOut #

***
####关于：####
> 这个 小游戏——基于OpenGL 是我个人学习C++和OpengGL的一个小示例，在此非常感谢 [Joey de Vries](https://joeydevries.com/#home)提供的[OpengGL学习教程](https://learnopengl.com/)。

##文件目录##
* 依赖的库目录在[这里](https://github.com/tj41694/OpenGL/tree/master/MyLib)，是我学习OpenGL的源码和Demo仓库里。
* ./Release 文件夹是我编译好的游戏以及所有资源文件，可以直接下载下来运行，当然你的显卡可能必须要支持OpenGL3.3及以上。
* ./BreakOut 是游戏的源码文件夹
* 
##环境##
* 此示例是在*Visual Studio 2017*下编译完成。
* 依赖库*GLFW*、*GLAD*、*GLM*、*irrKlang*、*freetype*、*stb_image*。它们都保存在[这儿](https://github.com/tj41694/OpenGL/tree/master/MyLib)，当然如果某库不能在你系统上正常链接可以到原[教程](https://learnopengl.com/)里找到相应的库源码，Cmake后编译后食用。
* 当然此示例是使用OpenGL的**CORE_PROFILE**，即完全是通过shader，可编程管线完成的。所以你的显卡可能至少需要支持OpenGL3.3。

##概要##
* 游戏示例将先前OpenGL基础以及高级教程里大量零散的OpengGL细节实现抽象成如***render spirit***类，让我们专注于游戏逻辑。
* 我们自己实现了一个基于渲染帧*frame*、AABB的碰撞检测，即单帧轴对齐边界盒子碰撞检测（stands for axis-aligned bounding box collisions）。当然我们自己完成的此碰撞检测算法还不完善在测试过程中有很多bug。如移动速度过快导致Ball渗透(penetrated)进入其他物体导致多次碰撞，甚至单帧时间内穿越物体，并没导致碰撞发生。
* 手动完成了一个漂亮的粒子系统。
* 利用帧缓存以及核技术（在fragmentshader中的图像卷积算法（边缘检测））实现漂亮的后期效果。如屏幕震动，反色，chaos等。
* 完善的游戏符文buff机制。
* 利用跨平台*irrKlang*库让我们能听见游戏声音了。
* 利用*freetype*库，通过预渲染字形的RED纹理至TextureBuffer，将RED纹理在fragmentshader中视着ALPHA纹理，让我们的游戏实现了文字（ASSIC码）渲染。当然，通过与渲染的方式，挺适合ASSIC码的，但对于有上万字符的中文，来说好不好实现我还没有试验（估计没戏）。
