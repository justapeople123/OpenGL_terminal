# Window應用程式介面(API)及3D繪圖

設計者想設計應用程式，並在程式的視窗內進行3D繪圖，需要兩種應用程式介面(API)。  

1. 視窗程式的應用程式介面(API)  

   視窗程式，即是圖形使用者介面(Graphical User Interface, GUI)的應用程式單位，設計者能在視窗程式中，獲得使用者與應用程式互動的資訊，以此進行渲染，將程式的內部資料視覺化於使用者前。

2. 繪圖程式的應用程式介面(API)  

   亦稱繪圖函式庫(Graphics Library)，藉由函式庫便能利用電腦產生圖像，也就是電腦繪圖(Computer Graphics, CG)技術。

設計者適當的呼叫這兩種應用程式介面的指令後，便能將想畫出的圖像，通過程式編寫，在應用程式的視窗上進行渲染，將資訊呈現於螢幕上。

**而GLUT則同時實作了兩種應用程式介面。**


* Window API   
  
  由於各種作業系統下所提供的視窗應用程式介面不同，設計者所撰寫出的程式，往往在不同的作業系統下便無法正確的運行，**GLUT是跨平台的API**，提供在不同的作業系統下，仍然能正確的運營。  

* 3D繪圖  

  OpenGL核心庫(GL)為OpenGL提供的最基本函式庫，GLU經由GL實作了一些常用功能的函式，GLUT則多提供了立體圖形的繪製函式，並且也提供了其他功能。

  <div style="display: flex; justify-content: space-around;">
      <img src="./img/diagram.png" alt="diagram" width = "200" >
  </div>
  <br/>

---
    
# GLUT簡介  

GLUT的功能包刮：定意視窗、視窗控制、接受鍵盤滑鼠的輸入、渲染程式到螢幕上、繪製幾何行元體...等。

由於GLUT本身並非開源軟體，現今所用的函式庫幾乎都是freeglut，是由其他程式設計師所重新製作的開源的OpenGL應用程式介面(API)。

* 環境建置

  我參考了  
  https://www.youtube.com/watch?v=A1LqGsyl3C4&ab_channel=TechLearners  
  建立了本地的環境，可以參考自己的電腦配置來找出適合自己的環境建立。  
  <br/>

---  

# GLUT介面程式實作

現在進行程式的撰寫，將測試並視覺化GLUT的功能，總共四個過程：  
1. **視窗建立**  

   視窗建立是使用GLUT的第一步驟，由於GLUT預設必須要有渲染的函式，否則無法正確運行，因此，此節先會先將渲染功能註冊後，讓程式進行更新，並且清除畫面。

    ``` cpp
    // windowCreate.cpp  

    // 初始化GLUT函式庫
    glutInit(&argc, argv);  
    // 初始化渲染模式，並指定緩存器類型 (for windows)
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 
    // 初始化視窗位置，(0, 0)為屏幕的左上角
    glutInitWindowPosition(100, 100);
    // 初始化視窗長寬
    glutInitWindowSize(600, 600);  
    // 創立一個標題為'glut'的視窗
    glutCreateWindow("glut");
    // 設定清除畫面為指定顏色
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    // 註冊設計者的繪圖函式進入GLUT
    glutDisplayFunc(My_Display);

    // 迴圈指令，讓GLUT創建出的視窗不斷運行
    glutMainLoop();
    ```  

    ``` cpp
    // windowCreate.cpp

    // 註冊繪圖函式
    void My_Display()
    {
        // 清除畫面儲存的顏色緩存器，以及深度緩存器
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
        // 將畫面清除為設定的顏色
      glClearColor(0.2f, 0.2f, 0.2f, 1.0f);  
        // 交替被現在使用的緩存器及後緩存器，可避免螢幕閃爍
      glutSwapBuffers();
    }
    ```  

    <div style="display: flex; ">
        <img src="./img/windowCreate.png" alt="windowCreate" width = "300" >
    </div>
    <br/>


2. 利用**渲染功能繪製茶壺**  
   * teapotRender.cpp  

3. 利用**計時功能使茶壺旋轉**、**按鍵功能進行位移**、**選單功能進行茶壺大小選擇**  
    * transform.cpp  

3. **滑鼠事件調變背景顏色**  
    * mouseEvent.cpp

* GLUT指令介紹





