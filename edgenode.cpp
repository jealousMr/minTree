#include "edgenode.h"

EdgeNode::EdgeNode()
{

}
bool EdgeNode::operator <(const EdgeNode x)
{
    return weight<x.weight;
}
bool EdgeNode::operator <=(const EdgeNode x)
{
    return weight<=x.weight;
}
bool EdgeNode::operator >(const EdgeNode x)
{
    return weight>x.weight;
}
bool EdgeNode::operator >=(const EdgeNode x)
{
    return weight>=x.weight;
}
