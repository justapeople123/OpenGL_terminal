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

