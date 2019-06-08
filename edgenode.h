#ifndef EDGENODE_H
#define EDGENODE_H


class EdgeNode
{
public:
    EdgeNode();
    operator int()const;
    bool operator <(const EdgeNode x);
    bool operator <=(const EdgeNode x);
    bool operator >(const EdgeNode x);
    bool operator >=(const EdgeNode x);

public:
    int weight;
    int u,v;
};

#endif // EDGENODE_H
