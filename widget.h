#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPixmap>
#include<QPaintEvent>
#include<QVector>
#include<QStack>
#include"edgenode.h"
#include"titlebar.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *);
    void draw_vertex();//设置顶点位置
   void draw_line(int x1,int y1,int x2,int y2);//连接顶点的边,在此设置图的矩阵
   void draw_line2(int x1, int y1, int x2, int y2);//擦除边
    void getXY(int &x,int &y,int num);//获得顶点num的坐标

    //生成树操作
    bool Exist(int i,int j);
    bool MinTree(QVector<EdgeNode>& vc);
    void draw_TreeLine(int x1,int y1,int x2,int y2);

    //重新绘制图结构
    void deleteVertex();//擦出顶点和边

protected:
      void mousePressEvent(QMouseEvent *);
      void mouseReleaseEvent(QMouseEvent *);
      void mouseMoveEvent(QMouseEvent *);
private slots:
    void on_vertexBtn_clicked();

    void on_gBtn_clicked();

    void on_getMinBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_released();

    void on_valueBtn_clicked();

    void on_dBtn_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    QPixmap Pix;
    int Vertex;
    int graph[11][11];
    QStack<EdgeNode> S;//动态获取树时用来存放边
    bool clickTree=false,isMin=false;
    int sum=0;//最小生成树权值和


      bool isPress;
      QPoint windowPos;
      QPoint mousePos;
      TitleBar *titleBar;
};

#endif // WIDGET_H
