#include "widget.h"
#include "ui_widget.h"
#include<QPixmap>
#include<QPainter>
#include<QDebug>
#include<QMessageBox>
#include<QPen>
#include"edgenode.h"
#include"minheap.h"
#include"un.h"
#include<QVector>
#include<QListWidgetItem>
#include<QIcon>
#include<QIntValidator>
#include<QMouseEvent>
#include<QMainWindow>




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString qss = "color:#BECEC6;background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #1B3152,stop:1 #255C80);";
    this->setStyleSheet(qss);
    ui->widget1->setText("顶点");
    ui->widget1->setImage(":/image/tree1.png");

    ui->widget2->setText("设置图");
    ui->widget2->setImage(":/image/tree2.png");


    ui->widget3->setText("下一步");
    ui->widget3->setImage(":/image/tree3.png");

    ui->widget4->setText("获得权值");
    ui->widget4->setImage(":/image/tree4.png");
    ui->widget4->update();

    Pix=QPixmap(this->width(),this->height()-220);
    Pix.fill(Qt::transparent);

    QIcon ic(":/image/sum3.png");
    ui->valueBtn->setIcon(ic);

    //输入权值只能为数字
    QIntValidator  *va=new QIntValidator;
    va->setRange(0,999999);
    ui->weightEdit->setValidator(va);

    ui->vertexBtn->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->getMinBtn->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->pushButton->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->gBtn->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->dBtn->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->pushButton_2->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->valueBtn->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");
    ui->pushButton_3->setStyleSheet("QPushButton:hover{background-color:rgb(199, 207, 255);color: rgb(255, 85, 127);}");

    QIcon ccc(":/image/re.png");
    ui->pushButton_3->setIcon(ccc);

    //关闭按钮样式
    titleBar=new TitleBar();
    isPress=false;
    setWindowFlags(Qt::FramelessWindowHint);
    titleBar->setParent(this);
    titleBar->move(620,0);
    titleBar->setStyleSheet("#CloseButton {"
                            "border-image: url(':/image/dark/window_close_normal.png');"
                        "}");

    connect(titleBar, &TitleBar::MinimizeButtonClicked, this, &Widget::showMinimized);
    connect(titleBar, &TitleBar::CloseButtonClicked, this, &Widget::close);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,240,width(),height()-240,Pix);
}
void Widget::draw_vertex()
{
    QPainter Painter(&Pix);
    qDebug()<<Vertex;
    if(Vertex==1)
    {
        QPixmap pix;
        Painter.translate(0,0);
        pix.load(":/image/1_008.png");
        Painter.drawPixmap(300,180,40,40,pix);//第一个点的坐标
    }else if(Vertex==2)
    {
        QPixmap pix1,pix2;
        Painter.translate(0,0);
        pix1.load(":/image/1_008.png");
        pix2.load(":/image/2_008.png");
        Painter.drawPixmap(300,180,40,40,pix1);
        Painter.drawPixmap(420,220,40,40,pix2);//第二点坐标
    }else if(Vertex==3)
    {
        QPixmap pix1,pix2,pix3;
        Painter.translate(0,0);
        pix1.load(":/image/1_008.png");
        pix2.load(":/image/2_008.png");
        pix3.load(":/image/3_008.png");
        Painter.drawPixmap(300,180,40,40,pix1);
        Painter.drawPixmap(420,220,40,40,pix2);
        Painter.drawPixmap(180,220,40,40,pix3);//第三点坐标
    }
    else if(Vertex==4)
        {
            QPixmap pix1,pix2,pix3,pix4;
            Painter.translate(0,0);
            pix1.load(":/image/1_008.png");
            pix2.load(":/image/2_008.png");
            pix3.load(":/image/3_008.png");
            pix4.load(":/image/4_008.png");
            Painter.drawPixmap(300,180,40,40,pix1);
            Painter.drawPixmap(420,220,40,40,pix2);
            Painter.drawPixmap(180,220,40,40,pix3);
            Painter.drawPixmap(500,320,40,40,pix4);//第四点坐标
        }
    else if(Vertex==5)
        {
            QPixmap pix1,pix2,pix3,pix4,pix5;
            Painter.translate(0,0);
            pix1.load(":/image/1_008.png");
            pix2.load(":/image/2_008.png");
            pix3.load(":/image/3_008.png");
            pix4.load(":/image/4_008.png");
            pix5.load(":/image/5_008.png");
            Painter.drawPixmap(300,180,40,40,pix1);
            Painter.drawPixmap(420,220,40,40,pix2);
            Painter.drawPixmap(180,220,40,40,pix3);
            Painter.drawPixmap(500,320,40,40,pix4);
            Painter.drawPixmap(100,320,40,40,pix5);//第5点坐标
        }
    else if(Vertex==6)
        {
            QPixmap pix1,pix2,pix3,pix4,pix5,pix6;
            Painter.translate(0,0);
            pix1.load(":/image/1_008.png");
            pix2.load(":/image/2_008.png");
            pix3.load(":/image/3_008.png");
            pix4.load(":/image/4_008.png");
            pix5.load(":/image/5_008.png");
            pix6.load(":/image/6_008.png");
            Painter.drawPixmap(300,180,40,40,pix1);
            Painter.drawPixmap(420,220,40,40,pix2);
            Painter.drawPixmap(180,220,40,40,pix3);
            Painter.drawPixmap(500,320,40,40,pix4);
            Painter.drawPixmap(100,320,40,40,pix5);
             Painter.drawPixmap(500,420,40,40,pix6);//第6点坐标
        }
    else if(Vertex==7)
        {
            QPixmap pix1,pix2,pix3,pix4,pix5,pix6,pix7;
            Painter.translate(0,0);
            pix1.load(":/image/1_008.png");
            pix2.load(":/image/2_008.png");
            pix3.load(":/image/3_008.png");
            pix4.load(":/image/4_008.png");
            pix5.load(":/image/5_008.png");
            pix6.load(":/image/6_008.png");
             pix7.load(":/image/7_008.png");
            Painter.drawPixmap(300,180,40,40,pix1);
            Painter.drawPixmap(420,220,40,40,pix2);
            Painter.drawPixmap(180,220,40,40,pix3);
            Painter.drawPixmap(500,320,40,40,pix4);
            Painter.drawPixmap(100,320,40,40,pix5);
            Painter.drawPixmap(500,420,40,40,pix6);
            Painter.drawPixmap(100,420,40,40,pix7);//第7点坐标
        }
    else if(Vertex==8)
        {
            QPixmap pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8;
            Painter.translate(0,0);
            pix1.load(":/image/1_008.png");
            pix2.load(":/image/2_008.png");
            pix3.load(":/image/3_008.png");
            pix4.load(":/image/4_008.png");
            pix5.load(":/image/5_008.png");
            pix6.load(":/image/6_008.png");
             pix7.load(":/image/7_008.png");
              pix8.load(":/image/8_008.png");
            Painter.drawPixmap(300,180,40,40,pix1);
            Painter.drawPixmap(420,220,40,40,pix2);
            Painter.drawPixmap(180,220,40,40,pix3);
            Painter.drawPixmap(500,320,40,40,pix4);
            Painter.drawPixmap(100,320,40,40,pix5);
            Painter.drawPixmap(500,420,40,40,pix6);
            Painter.drawPixmap(100,420,40,40,pix7);
             Painter.drawPixmap(420,520,40,40,pix8);//第8点坐标
        }
    else if(Vertex==9)
        {
            QPixmap pix1,pix2,pix3,pix4,pix5,pix6,pix7,pix8,pix9;
            Painter.translate(0,0);
            pix1.load(":/image/1_008.png");
            pix2.load(":/image/2_008.png");
            pix3.load(":/image/3_008.png");
            pix4.load(":/image/4_008.png");
            pix5.load(":/image/5_008.png");
            pix6.load(":/image/6_008.png");
             pix7.load(":/image/7_008.png");
              pix8.load(":/image/8_008.png");
               pix9.load(":/image/9_008.png");
            Painter.drawPixmap(300,180,40,40,pix1);
            Painter.drawPixmap(420,220,40,40,pix2);
            Painter.drawPixmap(180,220,40,40,pix3);
            Painter.drawPixmap(500,320,40,40,pix4);
            Painter.drawPixmap(100,320,40,40,pix5);
            Painter.drawPixmap(500,420,40,40,pix6);
            Painter.drawPixmap(100,420,40,40,pix7);
             Painter.drawPixmap(420,520,40,40,pix8);
              Painter.drawPixmap(180,520,40,40,pix9);//第9点坐标
        }


    update();
}


void Widget::on_vertexBtn_clicked()
{
    Vertex=ui->numV->currentIndex()+1;
    for(int i=0;i<11;i++)
        for(int j=0;j<11;j++)
            graph[i][j]=0;


    draw_vertex();
}
void Widget::draw_line(int x1, int y1, int x2, int y2)
{
      QPainter Painter(&Pix);
      Painter.setPen(QPen(Qt::yellow,4));
      Painter.drawLine(x1,y1,x2,y2);
      update();
}
void Widget::on_gBtn_clicked()
{
    int begin=ui->beginVertex->currentIndex()+1;
    int end=ui->endVertex->currentIndex()+1;
    int w=ui->weightEdit->text().toInt();
   // qDebug()<<w<<","<<begin<<","<<end;

    if(begin>Vertex ||end>Vertex || begin==end)
        QMessageBox::about(NULL,"error","起始/终止顶点输入有误");
    else if(w==0||w<0)
    {
         QMessageBox::about(NULL,"error","输入边的权值有误");
    }
    else
    {  //设置图矩阵(无向图)
        graph[begin][end]=w;
        graph[end][begin]=w;
        int x1,x2,y1,y2;
        getXY(x1,y1,begin);
        getXY(x2,y2,end);
        draw_line(x1,y1,x2,y2);

        //设置文字显示图结构listView
        QIcon icon=QIcon(":/image/lefe.png");
        QListWidgetItem * IconItem = new QListWidgetItem(icon,QString("%1--->%2---权值：%3").arg(begin).arg(end).arg(w),ui->listWidget);
        ui->listWidget->addItem(IconItem);
    }
}
void Widget::getXY(int &x, int &y, int num)
{
    int r=20,d=20;
    switch (num) {
    case 1:
    {
        x=300+r;
        y=180+d;
        break;
    }
    case 2:
    {
        x=420+r;
        y=220+d;
        break;
    }
    case 3:
    {
        x=180+r;
        y=220+d;
        break;
    }case 4:
    {
        x=500+r;
        y=320+d;
        break;
    }case 5:
    {
        x=100+r;
        y=320+d;
        break;
    }case 6:
    {
        x=500+r;
        y=420+d;
        break;
    }case 7:
    {
       x=100+r;
       y=420+d;
       break;
    }
    case 8:
    {
        x=420+r;
        y=520+d;
        break;
    }
    case 9:
    {
        x=180+r;
        y=520+d;
        break;
    }
    }
}

bool Widget::Exist(int i, int j)
{
    if (i<1 || i>Vertex || j<1 || j>Vertex)
        return false;
    if (graph[i][j] != 0)
        return true;
  return false;
}
bool Widget::MinTree(QVector<EdgeNode> &vc)
{
   QVector<EdgeNode> E;
   for(int i=1;i<=Vertex;i++)
       for(int r=1;r<=Vertex;r++)
           if(Exist(i,r))
           {
               int c=graph[i][r];
               EdgeNode temp;
               temp.weight=c;
               temp.u=r;
               temp.v=i;
               E.append(temp);
           }
   MinHeap H(E.size());
   for(int i=0;i<E.size();i++)
       H.Insert(E[i]);
   UN un(Vertex);
   int k=0,e=E.size();
   while (e&& k<Vertex - 1)
       {
           EdgeNode x;
           H.Delete(x);
           e--;
           int a = un.Find(x.u);
           int b = un.Find(x.v);

           if (a != b)
           {
               k++;
               vc.push_back(x);
               un.Unite(a, b);
           }
       }
   for(int i=0;i<vc.size();i++)
       S.push(vc[i]);
   return k == Vertex - 1;
}

void Widget::draw_TreeLine(int x1, int y1, int x2, int y2)
{
    QPainter Painter(&Pix);
    Painter.setPen(QPen(Qt::red,4));
    Painter.drawLine(x1,y1,x2,y2);
    update();
}
void Widget::on_getMinBtn_clicked()
{
    QVector<EdgeNode> vc;
    if(MinTree(vc))
    {
    for(int i=0;i<vc.size();i++)
    {
        int a=vc[i].u;
        int b=vc[i].v;
        sum+=vc[i].weight;
        int x1,y1,x2,y2;
        getXY(x1,y1,a);
        getXY(x2,y2,b);
        draw_TreeLine(x1,y1,x2,y2);
    }
   }else
    {
         QMessageBox::about(NULL,"message","不存在最小生成树");
    }
}

//动态获得树
void Widget::on_pushButton_clicked()
{
    if(clickTree)
    {
        if(isMin)
        {
            if(!S.empty())
            {
                int a=S.top().u;
                int b=S.top().v;
                sum+=S.top().weight;
                int x1,y1,x2,y2;
                getXY(x1,y1,a);
                getXY(x2,y2,b);
                draw_TreeLine(x1,y1,x2,y2);
                S.pop();
            }else
                QMessageBox::about(NULL,"message","演示完成");
        }else
        {
            QMessageBox::about(NULL,"message","不存在最小生成树");
            clickTree=false;
        }

    }else
    {
        clickTree=true;
        QVector<EdgeNode> vc;
        isMin=MinTree(vc);
    }
}


void Widget::on_pushButton_released()
{

}

void Widget::on_valueBtn_clicked()
{
    QString str=QString::number(sum);
     QMessageBox::about(NULL,"message","min value:"+str);
     sum=0;
}

//取消边的权值设置
void Widget::on_dBtn_clicked()
{
    int begin=ui->beginVertex->currentIndex()+1;
    int end=ui->endVertex->currentIndex()+1;
    graph[begin][end]=0;
    graph[end][begin]=0;
    int x1,x2,y1,y2;
    getXY(x1,y1,begin);
    getXY(x2,y2,end);
    draw_line2(x1,y1,x2,y2);
    QIcon icon=QIcon(":/image/lefe.png");
    QListWidgetItem * IconItem = new QListWidgetItem(icon,QString("%1--->%2---权值：0").arg(begin).arg(end),ui->listWidget);
    ui->listWidget->addItem(IconItem);

}
void Widget::draw_line2(int x1, int y1, int x2, int y2)
{
    QPainter painter(&Pix);
    QPen pen;
    pen.setWidth(4);
    painter.setCompositionMode(QPainter::CompositionMode_Clear);
    painter.setPen(pen);
    painter.drawLine(x1,y1,x2,y2);
    update();
}
void Widget::deleteVertex()
{
     QPainter painter(&Pix);
     painter.setCompositionMode(QPainter::CompositionMode_Clear);
     painter.fillRect(100,180,460,400,Qt::SolidPattern );
     update();
}

void Widget::on_pushButton_3_clicked()
{
    //重置图
    deleteVertex();
    //重置矩阵
    for(int i=0;i<11;i++)
        for(int j=0;j<11;j++)
            graph[i][j]=0;
    //清空文字图结构
    int s=ui->listWidget->count();
    for(int index=0;index<s;index++)
    {
        QListWidgetItem *item=ui->listWidget->takeItem(0);
        delete item;
    }
    //调整动态演示标志
    this->isMin=false;
    this->clickTree=false;
    //重置权值
    this->sum=0;
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        windowPos = this->pos();
        mousePos = e->globalPos();

        isPress = true;
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        isPress = false;
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if (isPress)
        move(windowPos + (e->globalPos() - mousePos));
}
