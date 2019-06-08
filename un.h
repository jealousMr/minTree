#ifndef UN_H
#define UN_H

//并查集，判断是否回路
class UN
{
public:
    UN(int num);
    ~UN();
    int Find(int element);
    void Unite(int& rootA,int& rootB);
private:
    int* parent;
};

#endif // UN_H
