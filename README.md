# 人脸识别

---

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

提示：

    程序第一次运行时会在"D:\opencv_faces\"目录下生成 common.xml ，这个文件是项目的Com公共变量以及项目的设置，在这里修改参数。
    如果没有盘符"D:\"，在代码proj_com.cpp:11行修改配置并运行。