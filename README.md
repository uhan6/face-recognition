# 人脸识别

[![license](https://img.shields.io/github/license/go88/face-recognition.svg?style=for-the-badge)](https://choosealicense.com/licenses/mit/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=for-the-badge)](https://github.com/go88/face-recognition/pulls)
[![GitHub (pre-)release](https://img.shields.io/github/release/go88/face-recognition/all.svg?style=for-the-badge)](https://github.com/go88/face-recognition/releases)

项目环境：

1. opencv库（编译过extra modules）

    在 OpenCVwithModules.props 里更改路径及配置

    ```
    默认目录: D:\Program Files\opencv_with_modules
                                                 \bin
                                                 \include
                                                 \x64
    ```

---

目录介绍：
```
头文件\
      lib\
          go88_lib.h    // 自己写的工具函数
          tinyxml2.h    // tniyxml 函数库，用于序列化读写 xml
      proj_com.h        // 程序的公共环境变量和程序数据，Com 类进行序列化与反序列化
源文件\
      face_recognition\
                       fr_main  // 在 main() 中被调用
                       fr_create_face   // 记录人脸并训练模型
                                        // 只训练模型：可以输入已存在的 name，然后直接 q 退出拍照，就可以只训练模型
                       fr_check_face    // 检测人脸，用到了多线程

      just_test\    // 测试摄像头等等
      lib\          // lib 的具体实现
      proj_com.cpp  // com 类的实现
      
      main.cpp      // 程序入口
```

---

提示：

    程序第一次运行时会在"D:\opencv_faces\"目录下生成 common.xml ，这个文件是项目的Com公共变量以及项目的设置，在这里修改参数。
    如果没有盘符"D:\"，在代码proj_com.cpp:11行修改配置并运行。