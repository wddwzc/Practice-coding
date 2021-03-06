

秋招以来在牛客也混了很久了，攒了一些经验，就来分享一波。今年算法岗求职难度大幅提升，资本渐凉，需求变少，找算法岗的毕业生却越来越多，很多人迫不得已都转去开发岗。机器学习、推荐、NLP、推荐等等方向也都是大热的方向，自从玩了一段时间深度学习之后，我还是选择退出这个深坑，一方面是变化太快、而且小改小动灌水变多、并不会有大的变革，单纯的调参很快就能被替代，没有核心竞争力；另一方面深度学习目前的应用场景还是局限在语音、视觉，短时间内看不到突破性的应用场景，理论解释也没有得到突破，我可以直接拿成熟研究好的模型而并不想去搞模型内部的细枝末节。

说回自己吧，本科十所TOP3之一机械工程，啥都学那种通识教育（机械设计制造、控制、材料、热流体固体力学无所不及），一直对机器人感兴趣，硕士就读于海外某不知名理工学院机械工程机器人方向，做了差不多两年的机器人相关项目，主要围绕SLAM、立体视觉展开。从8月以来到12月陆续投了不少简历，有消息（面试）的包括华为、海康、大华、360、商汤、旷视、地平线、博世。留学生这边消息毕竟延迟一点，错过了一些机会，大家也是尽可能早一点准备，不过留学生还有一些春招机会可以把握，比如大疆留学生专场。

总结一下SLAM方向公司：
阿里ailab：很难进，岗位没了直接挂了
大疆：感知算法，slam技术算是最好的了
华为：车BU需求量比较大，起步阶段也是技术积累阶段，前景应该不错
海康、大华：围绕安防展开机器人相关、相机相关领域研究，
美团、京东、阿里菜鸟、顺丰：配送相关
滴滴、地平线、百度、阿里：自动驾驶
商汤、旷视：AR\VR，自动驾驶，机器人业务都有覆盖
360等：扫地机器人
oppo：AR/VR
博世、安波福、大陆、戴姆勒、一汽上汽：汽车tier1，OEM
图森、pony.ai等：初创自动驾驶

几大块准备：
1. 项目准备，尽可能在学习期间进入实验室做slam相关的项目，针对项目准备细节问题
2. SLAM基础问题准备，前端视觉、立体视觉匹配、后端优化、滤波等等各方面都要扎实
3. c++数据结构基础问题准备
4. 剑指offer leetcode刷题

技术面试问题可参考大佬帖子https://www.nowcoder.com/discuss/294308

面试经验总结：
8月
商汤：
面了三个一面(50min)，两个是SLAM，一个是自动驾驶
1. 第一次啥也不懂，先聊项目，聊得感觉很开心，后面问了些SLAM基本问题，然后C++数据结构基本问题，那时候没准备很多简单的东西也没答上来就挂了
2. 第二次换了个部门，同上，挂了
3. 做控制的，聊MPC（model predictive control），不是slam相关，挂

9月
旷视：
一面（1.5h）：一个半小时都是挖简历项目，挖细节问细节，问到打不出来为止，举个例子，如何对齐groundtruth轨迹（用手眼标定），手眼标定的方程是什么样的，如何得出这个方程，如何求解这个方程，最少几个点对能求解，如何提高精度。旷视的面试官水平非常高，面试感觉自己啥也不会的那种，酣畅淋漓。最后也成功领取一面挂。

地平线：
一面(45min)：弱版旷视，问项目问细节，问几个slam基本问题。感觉答得还行，最后还是一面挂，可能是不够自信吧。

10月
博世：认知算法工程师
HR面(25min)：聊聊人生。面完过了，第二天简历复筛挂了，大概是博世只要博士吧。

11月
360：牛客留学生专场
一面(45min)：技术面试，聊项目，问细节，做题，二叉树相关。
二面(45min)：大佬面试，聊项目
三面HR面：聊人生
360面试体验非常好，三面一起整个接近3个小时完成，感觉面试官很大佬，技术也不错。面完没消息。

大华：牛客留学生专场
一面(25min)：技术面试，聊项目，很简单，20多分钟
二面(25min)：技术面试，聊项目，依然很简单，20多分钟
三面HR面：基本问题，感觉大华hr比较传统
大华整体感觉一般，面试也都是提前10分钟短信提示，没有提前预约，体验不是特别好，水平也不算太好。

华为：8月投递简历，11月开始约，车bu技术研究
一面(50min)：元老级员工，不过应该是其他方向的，对slam不大懂，聊项目也泛泛而谈，体验不是很好。上来先一道手撕代码，不能理解都是远程视频面试了还要拿纸笔写代码这种操作，虽说是第一年开始手撕代码环节也不用这么传统吧。
二面(60min)：技术面，聊项目，问一些细节。最后是一套试题，SLAM相关，还是比较对口。
三面(50min)：部门主管面，还是聊聊项目，聊聊自动驾驶想法
大概半个月就收到了邮件offer。整体体验一般，感觉华为目前技术一般，但是花大力气在做自动驾驶这件事，前景还是不错的。

12月
海康：留学生专场
一面(60min):聊项目问细节，比较轻松。
二面(20min):HR面，自我评价，项目介绍。
三面(50min):技术面，项目简单介绍，基本问题，公司介绍。


祝大家都能拿到好offer！
