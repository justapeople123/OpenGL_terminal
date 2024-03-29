# 座標系統及運算相關表示方法

* 座標(Coordinates)  
    * 用來定義系統中的任一個位置，是構成座標空間的基本要素。
    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Coordinates.png" alt="Coordinates" width = "200" >
    </div>
    <br/>

* 維度(Dimension)
    * 維度代表在空間中定義一個點最少所需要的座標數量。

    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Dimension.png" alt="Dimension"  width = "400">
    </div>
    <br/>

* 點及位置(Point)
    * 點代表空間中的一個特定位置，並不具備體積、面積或長度，維度為0。  
    * 點的位置可被空間中的對應的一組向量(vector)做座標定義。
    

    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Point.png" alt="Point"  width = "300">
    </div>
    <br/>

* 向量(Vector)
    * 向量(Vector)代表一組距有順序排序的一串數組，數組中的數字可用整數定位(向量中的第n個數)。
    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Vector.png" alt="Vector"  width = "300">
    </div>  
    <br/>

* 方向(Direction)
    * 方向代表空間中兩個點的相對位置信息，不具有起點、終點、與長度的信息，並注重空間中的相對性。
    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Direction.png" alt="Direction"  width = "300">
    </div>    
    <br/>
    
* 矩陣(Matrix)
    * 矩陣是一個由二為數組組成的數學系統。  
    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Matrix.png" alt="Matrix"  width = "150">
    </div>    
    <br/>

* 座標系統(Coordinate System)
    * 座標系統(Coordinate System)是在一個n維度的座標空間(coordinate space)。  
    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Coordinate System.png" alt="Coordinate System"  width = "150">
    </div>    
    <br/>

---
    
# 基本數學與空間運算

* 數學記號與常用變數  
    * 用來定義系統中的任一個位置，是構成座標空間的基本要素。  
    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Math.png" alt="Math" >
    </div>    
    <br/>

    <div style="display: flex; justify-content: space-around;">
       <img src="./img/Name.png" alt="Name" >
    </div>    
    <br/>  

* 向量相關數學運算  

   向量在空間中可視為一個點，或是兩點之間的距離，這樣的特性使的向量能夠幫助計算空間中的問題。  
   <br/>  

   * 向量間的疊加(Addition)  
     * 向量的疊加可視為移動量的疊加

   * 向量與純量之間的乘除法(Multiplication)  
     * 向量具有長度的性質，與純量做成除法的運算，可改變長度的大小並保留其方向的特性。  

   * 向量間的內積(Dot product)
     * 向量在空間中的內積具有許多特質可幫助求得向量間的角度關係與分量大小。  
     * 其向量之間的內積定義是將兩邊向量的對應項次之乘積累加。  

   * 向量間的叉積(Cross product)
     * 叉積(Cross product)，或稱向量積(Cross product)，是用來求得與兩向量垂直的向量方向。

* 矩陣相關數學運算  

   矩陣是一個由二維數組組成的數學系統，其許多的數學特性使其用於解線性方程組或是計算線性變換上時常用到。  

   * 基本性質與基本運算  
     * 矩陣中的元素數量有 m X n 個，且每個元素能夠被標註其位置。  

   * 矩陣加法運算(Addition)  
     * 兩個**大小相同**的兩個矩陣之間可以相加。  

   * 矩陣與純量乘法運算(Multiplication)  
     * 矩陣可以與純量相乘。  

   * 矩陣轉置運算(Matrix transpose)  
     * 矩陣本身可以做轉置運算，其大小從 m X n -> n X m。  

   * 矩陣運算性質  
     * 矩陣的加法運算滿足交換率(Commutative property)   
       * A + B = B + A  
     * 矩陣的轉置和純量乘法運算對加法滿足分配律(Distributive property)  
       * (A + B)<sup>T</sup> = A<sup>T</sup> + B<sup>T</sup>  
       * n(A + B) = nA + nB  
     * 純量乘法與轉置的順具可以互換
       * n(A<sup>T</sup>) = (nA)<sup>T</sup>  

   * 矩陣間的乘法(Multiplication)  
     * 兩個矩陣的乘法僅當地一個矩陣A的行數和另一個矩陣B的列數**相等**時，才能定義。  
       * A<sub>mxn</sub> . B<sub>nxp</sub> = C<sub>mxp</sub>  
     * 矩陣的乘法滿足結合律和對矩陣加法的分配律(Distributive property)  
       * (AB)C = A(BC)  
       * (A+B)C = AC + BC  
       * C(A+B) = CA + CB  
     * 矩陣的乘法與純量乘法運算和轉置也滿足以下轉換  
       * c(AB) = (cA)B = A(cB)
       * (AB)<sup>T</sup> = B<sup>T</sup>A<sup>T</sup>  
     * **矩陣乘法不滿足交換律**  
       * **AB ≠ BA**  

   * 方正矩陣與逆矩陣(Square matrix & Inverse matrix)  
     * 當一個矩陣的行數與列數相等，可將該矩陣稱為方正矩陣(Square matrix)。  
     * 一個 n X n 的方正矩陣A，若存在另一格方陣矩陣B使得 AB = l<sub>n</sub> = BA，則A為**可逆矩陣(Invertible matrix)**，而B為A的反矩陣(Inversion matrix)，且可將B記為A<sup>-1</sup>。  
     * 逆矩陣(Inverse matrix)再用於解線性方程式或是用於反轉換運算等數學領域都有用途。  
       * ex :   
        Ax = b  
        A<sup>-1</sup>Ax = A<sup>-1</sup>b  
        l<sub>n</sub>x = A<sup>-1</sup>b  
        x = A<sup>-1</sup>b  
     * 當物體透過變化矩陣(Transformation matrix) **A** 從 P -> P<sup>'</sup>，該物體也可透過 **A** 的反矩陣(Inversion matrix) 從 P<sup>'</sup> -> P。  

   <br/>  
   <div style="display: flex; justify-content: space-around;">
       <img src="./img/Opengl matrix.png" alt="Opengl matrix" >
   </div>    
   <br/>  

---
    
# 座標系統和轉換

在鏡頭投影系統中，世界空間、相機和物體到螢幕都有屬於自己的座標空間，要正確地將物體投影回螢幕就必須經過座標系統的轉換，才能將物體渲染在螢幕上正確的位置。

<div style="display: flex; justify-content: space-around;">
       <img src="./img/Coordinate1.png" alt="Coordinate1" >
</div>    
在空間中，相同的位置在不同的座標系統下，標示的方式也不同。  
  
<br/>  

<div style="display: flex; justify-content: ">
       <img src="./img/Coordinate2.png" alt="Coordinate2" width = "400">
</div> 
在空間中相同的位置在不同的座標系統下標示的結果也不同。  
  
<br/> 

在三維空間中，要將位置轉換至不同的座標空間內，需要進行座標轉換的運算，而在轉換前會將物體的座標轉變為三維齊次座標(3D homogeneous coordinate)表示。

<div style="display: flex; justify-content: ">
       <img src="./img/Coordinate3.png" alt="Coordinate3" width = "400">
</div> 
三維的齊次座標用(x, y, z, h)四元素向量表示在直角坐標空間中( x/h, y/h, z/h)的位置。  

當h為零時，表示物體在(x, y, z)方向中無限遠的位置。

  
<br/> 

<div style="display: flex; justify-content: space-around;">
       <img src="./img/Opengl matrix.png" alt="Opengl matrix" >
</div> 
在齊次座標空間中，物體的座標轉換可透過變化矩陣(Transformation matrix)運算達成。

<br/>  

* 位移轉換(Translation Transformation)  

  當需要把再三維空間中的物體，從現在的座標系統表示轉換到另一個相對空間位移的座標系表示，或是需要將物體在空間中移動時，需要進行位移轉換。

  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Translation Transformation.png" alt="Translation Transformation" >
  </div> 

  <br/>  

* 旋轉轉換(Rotation Transformation)  

  當需要把再三維空間中的物體從現在的座標系統表是轉換到另一個相對旋轉的座標系表示，或是需要將物體在空間中繞著座標軸時，需要進行旋轉轉換。

  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Rotation1.png" alt="Rotation1" >
  </div> 
  沿著 x 軸旋轉θ<sup>。</sup>到新位置

  <br/>  

  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Rotation2.png" alt="Rotation2" >
  </div> 
  沿著 y 軸旋轉θ<sup>。</sup>到新位置

  <br/>  

  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Rotation3.png" alt="Rotation3" >
  </div> 
  沿著 z 軸旋轉θ<sup>。</sup>到新位置

  <br/>  

  **因其運算並不具有交換律的性質，所以三個軸向的旋轉順序不同會導致旋轉結果不同。**  

* 縮放轉換(Scaling Transformation)  

  當需要把再三維空間中的物體從現在的座標系統表示轉換到另一個相對縮放的座標系表示，或是需要將物體在空間中沿著座標軸縮放與原典的距離時，就需要進行縮放轉換。

   <div style="display: flex; justify-content: space-around;">
       <img src="./img/Scaling1.png" alt="Scaling1" >
  </div>  
  <br/>  

  當縮放的參數為負值時，會產生翻轉的效果，稱為反射轉換(Reflection transform)、鏡射轉換(Mirror transform)和翻轉轉換(Flip transform)。  

   <div style="display: flex; justify-content: space-around;">
       <img src="./img/Reflection.png" alt="Reflection" >
  </div> 
  <br/>  

  
  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Reflection_x.png" alt="Reflection_x" >
  </div>  

  點(x, y, z)對X座標軸反射到新位置  

  <br/>   
  
  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Reflection_x_z.png" alt="Reflection_x_z" >
  </div>  

  點(x, y, z)對X與Z座標軸反射到新位置  

  <br/>  

* 切變轉換(Shearing Transformation)  

  切變(Shearing)，是指將座標系統中座標軸之間的關係根據空間平面中指定的方向而改變，當在空間的點與指定方向(經原點)的距離越遠時，改變的程度就越大。  

  當需要把在三維空間中的物體從現在的座標系統表示轉換到另一個相對切變(Shearing)的座標系表示，或是需要將物體在空間中隨著指定平面方向扭曲時就需要進行切變轉換。

  在三維空間中，進行切變轉換(Shearing transformation)時需要的平面方向會從二維空間需要的一個增加為三個(x-y plane, x-z plane, y-z plane)。

  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Shearing.png" alt="Shearing" width = "300">
  </div>  
  
  <br/>  

* 透視轉換(Perspective Transformation)

  當鏡頭產生的視錐區域對應到二維平面時，較遠的物體被壓縮，透過透視轉換(Perspective Transformation)運算可以計算此笑我，將處在三維空間中離座標原點的越遠的位置縮放的越小。  

  <div style="display: flex; justify-content: space-around;">
       <img src="./img/Perspective.png" alt="Perspective" >
  </div>  
  當點(x, y, z)位置的物體對(X, Y, Z)進行透視轉換到新位置時。  

  <br/>  

* 綜合轉換(Combination Transformation)

  旋轉、縮放與位移，這三個運算會影響物體所處的座標軸，若是轉換順序不一樣，得到的結果也會不相同，建議先將物體轉回座標原點再進行旋轉與縮放的運算。

---
    
# 座標系統和轉換

在OpenGL中有透視投影(Perspective projection)與正交投影(Orthographic projection)兩種鏡頭設定。 

<div style="display: flex; justify-content: space-around;">
      <img src="./img/projection.png" alt="Perprojectionspective" >
</div>  
<br/>  

透視投影(Perspective projection)透過設定鏡頭的廣角與投影面長寬比投影出類似於第一人稱視角的畫面。  
正交投影(Orthographic projection)透過設定投影的方向與平面，投影出模擬從遠方觀察的畫面，

* 透視投影(Perspective projection)  

  透視投影(Perspective projection)的成像結果較接近用相機拍攝環境的效果，比較能察覺環境的深度。

  <div style="display: flex; justify-content: space-around;">
        <img src="./img/Perspective_c1.png" alt="Perspective_c1" >
  </div>  
  <br/>  

  <div style="display: flex; justify-content: space-around;">
        <img src="./img/Perspective_c2.png" alt="Perspective_c2" >
  </div>  
  <br/>  

  經過轉換後，無論原位置的深度Z為何值，其運算的結果皆會使新位置的深度為d，使的空間中的物體都壓縮對應到 (z=d) 的二維平面上。  

* 正交投影(Orthographic projection)

  正交投影(Orthographic projection)的成像結果常用在鳥瞰視野或是截面圖上，對單一平面上的觀察較為精確。

  <div style="display: flex; justify-content: space-around;">
        <img src="./img/Orthographic_c1.png" alt="Orthographic_c1" >
  </div>  
  <br/>  

  <div style="display: flex; justify-content: space-around;">
        <img src="./img/Orthographic_c2.png" alt="Orthographic_c2" >
  </div>  
  <br/>  

  經過轉換後，無論原位置的深度Z為何值，其運算的結果皆會使新位置的深度為0，使的空間中的物體都壓縮對應到 (z=0) 的二維平面上。  

---
    
# 渲染相關座標系統

在OpenGL中，將三維空間中的點投影到二維空間的螢幕上，需經過

1. [模型座標空間(Object space)](#Object_space)
2. [世界座標空間(World space)](#World_space)
3. [鏡頭座標空間(Camera space)](#Camera_space)
4. [正則座標空間(Canonical space)](#Canonical_space)
5. [螢幕座標空間(Screen space)](#Screen_space)

空間中的點每經過一層座標轉換，其在空間中的幾何意義也會跟著改變。

* 模型座標空間(Object Space) <a name="Object_space"></a>  

  在OpenGL架構中，物體擁有一個模型座標空間，以座標原點(物體中心)為基準，將三維模型(3D model)的點儲存在座標空間中，只要三維模型(3D model)不發生形變(Deformation)，OpenGL就不需要消耗運算資源去更新三維模型(3D model)的點資訊。 

  透過用模型座標空間儲存點(Point)資訊，可以省去更新點(Point)資料的運算資源。   

* 世界座標空間(World space) <a name="World_space"></a>  

  建立世界的基準點，提供空間中的物體參照，當空間中有三維模型移動時，只需更新該三維模型在世界座標的資訊即可，省下記憶體用量。

  在OpengGL架構中，每一個三維模型都有一個對應世界座標的塑模座標矩陣(Model matrix)，處在模型座標空間的資訊，可透過三維模型的塑模座標矩陣(Model matrix)相乘進行模型轉換(Modeling transformation)進入世界座標空間。

* 鏡頭座標空間(Camera space) <a name="Camera_space"></a>  

  鏡頭在世界座標空間中觀察空間中的物體，然而對鏡頭而言，一個物體是否被看到取決於該物體與鏡頭在空間中的相對關係。

  在OpenGL架構中，有一個鏡頭位置與世界座標(World coordinate)對應的鏡頭矩陣，世界座標(World coordinate)中的物體可透過該矩陣進行鏡頭轉換到鏡頭座標(Camera coordinate)的空間中。

  在OpenGL架構中，鏡頭透過位置(Position)、方向(Direction)與上方(Lookup)來設定鏡頭的參數。

  假設世界座標空間中設置的鏡頭位置在**P**，對著**F**的方向並以**U**為上方，透過**U**與**F**的叉積(Corss product)**U X F**取得鏡頭的左方向**L**，即可得到鏡頭矩陣(View matrix)。

  <div style="display: flex; justify-content: space-around;">
        <img src="./img/Model_view_matrix.png" alt="Model_view_matrix" >
  </div>  
  <br/>  

* 正則座標空間(Canonical space) <a name="Canonical_space"></a>  

  相機經過設定後會產生三維的成像視錐區域(Canonical view volume)，當物體經過投影轉換(Projection transformation)從鏡頭座標空間(Camera space)轉到正則座標空間(Canoical space)的過程中，成像視錐區域(Canonical view volume)會被壓縮在(-1, -1, -1)到(1, 1, 1)的區域內。

  此時空間中的位置可透過簡單的邏輯計算(**|P|**>1)快速檢查該位置是否被鏡頭觀察到。

  而後，被觀察到的點會投射到該區域的成像區域平面，轉到二維的空間維度。

* 螢幕座標空間(Screen space) <a name="Screen_space"></a>  

  當物體經過投影轉換(Projection transformation)到二維空間時，其平面大小為1到-1之間。

  在OpenGL中鏡頭所看到的畫面不一定符合螢幕中可顯示的大小與比例，因此需要經過視角轉換(Viewport transformation)轉到合適的空間已符合螢幕。

* 整體轉換及GL上的轉換狀態

  一個三維模型物體的點資料，經過上述的轉換後到實際顯示的視窗畫面成像。

  在OpenGL架構中，這五種類型的座標空間被分為：  

  1. 視覽座標矩陣(Model-view matrix, GL_MODELVIEW)  
     負責處理物體在三為空間中縮放(Scaling)和位移(Translation)等轉換的運算。  

  2. 投影矩陣(Projection matrix, GL_PROJECTION)  
     負責鏡頭投影(Projection)的轉換運算。

  OpenGL架構中，物體可直接與上述兩類矩陣直接運算從三維空間投影到二維的畫面上。

  <div style="display: flex; justify-content: space-around;">
        <img src="./img/GL_trans.png" alt="GL_trans" >
  </div>  
  <br/>  


  ```cpp
  # GL_MODELVIEW Example

  glMatrixMode(GL_MODELVIEW); 
  // 將目前轉換模式改為視覽座標矩陣模式
  glLoadIdentity();  
  // 將目前的視覽座標矩陣重設為單位矩陣(Identity matrix)
  glTranslatef(0.0, 0.0, -5.0);  
  // 位移轉換(z軸方向移動-5單位)
  glRotatef(-45.0, 0.0, 1.0, 0.0);  
  // 旋轉轉換(y軸方向旋轉45度)
  glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
  // 將目前計算的視覽座標矩陣輸出給modelview變數

  ```

  ```cpp
  # GL_PROJECTION Example

  aspect = width * 1.0f / height;
  // 設定畫面長寬比例變數 aspect
  glMatrixMode(GL_PROJECTION); 
  // 將目前轉換模式改為投影矩陣模式
  glLoadIdentity();  
  // 將目前的投影矩陣重設為單位矩陣(Identity matrix)
  glViewport(0, 0, width, height); 
  // 設定畫面基準點與大小
  gluPerspective(60.0f, aspect, 0.1f, 10.0f);  
  // 將鏡頭視角設定為透視投影(Perspective projection)，並附加相關參數(廣角、長寬比例、近平面與遠平面)
  glGetDoublev(GL_PROJECTION, projection);
  // 將目前計算的投影矩陣輸出給projection變數

  ```










  










